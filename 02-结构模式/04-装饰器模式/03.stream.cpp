/*************************************************************************
> File Name: 03.stream.cpp
> Author: 
> Mail: 
> Created Time: 2022年08月14日 星期日 09时59分31秒
 ************************************************************************/

#include<iostream>
using namespace std;
class Stream {
  public:
    virtual char handleBuffer()  =0;
};

class MemoryStream:public Stream {
  public:
    char handleBuffer() override {
      return 'z';
    }
} ;

class FileStream:public Stream {
  public:
    char handleBuffer() override {
      return 'z';
    }
} ;

class StreamDecorator :public Stream {
  public:
    ~StreamDecorator() {
      delete stream;
    }
  public:
    char handleBuffer() override {
      return  stream->handleBuffer();
    }
  protected:
    Stream *stream;
};

class ASCII:public StreamDecorator {
  public:
    ASCII(Stream* stream) {
      this->stream = stream;
    }
  public:
    char handleBuffer() override {
      char c = StreamDecorator::handleBuffer();

      printf("%d\n",c);

      return 0;
    }
};

class Hex:public StreamDecorator {
  public:
    Hex(Stream* stream) {
      this->stream = stream;
    }
  public:
    char handleBuffer() override {
      char c = StreamDecorator::handleBuffer();

      printf("%x\n",c);

      return 0;
    }
};

void worker(Stream* stream) {
  stream->handleBuffer();

  delete stream;

}

int main(){

  worker(new Hex(new MemoryStream()));
  worker(new ASCII(new MemoryStream()));


  cout << endl;

  worker(new Hex(new FileStream()));
  worker(new ASCII(new FileStream()));
  return 0;
}
