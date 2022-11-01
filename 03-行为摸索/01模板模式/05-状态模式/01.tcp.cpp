/*************************************************************************
> File Name: 01.tcp.cpp
> Author: 
> Mail: 
> Created Time: 2022年11月01日 星期二 22时46分25秒
 ************************************************************************/

#include<iostream>
using namespace std;
class TCPOctestStream ;
class TCPConnection;

class TCPState {
  public:
    virtual void open(TCPConnection* t)  {

    }
    virtual void closed(TCPConnection* t) {

    }
    virtual void acknowledge(TCPConnection* t) {

    }
  public:
    void changeState( TCPConnection*t,TCPState *s);

};

class TCPEstablished :public TCPState {
  public:
    static TCPEstablished* getInstace()  {
      return  TCPEstablished::instance;
    }

  private:
    static TCPEstablished *instance;
  public:
    void closed(TCPConnection*t) override;
      void acknowledge(TCPConnection*t) override {
      cout << "acknowledge TCPEstablished"<< endl;
    }
};

TCPEstablished* TCPEstablished::instance = new TCPEstablished;

class TCPClosed :public TCPState {
  public:
    static TCPClosed* getInstace()  {
      return  TCPClosed::instance;
    }

  private:
    static TCPClosed *instance;
  public:
    void open(TCPConnection*t ) override {
      TCPState::changeState(t,TCPEstablished::getInstace());
    }
    void closed(TCPConnection*t) override {
    }
    void acknowledge(TCPConnection*t) override {
      cout << "acknowledge TCPClosed"<< endl;
    }
};

void TCPEstablished::closed(TCPConnection *t)  {
      cout << "closed TCPEstablished"<< endl;
      TCPState::changeState(t,TCPClosed::getInstace());
}




TCPClosed* TCPClosed::instance = new TCPClosed;

class TCPConnection {
  private:
    TCPState* state;

  public:
    TCPConnection() {
      state = TCPClosed::getInstace();
    }

    void open() {

      state->open(this);
    }

    void closed() {
      state->closed(this);
    }

    void acknowledge() {
      state->acknowledge(this);
    }

    void changeState(TCPState *state) {
      this->state = state;
    }

};


void TCPState::changeState(TCPConnection *t, TCPState *s){
  t->changeState(s);
}

int main(){

    TCPConnection *t = new TCPConnection;
    t->acknowledge();
    t->open();
    t->acknowledge();
    t->closed();
    t->acknowledge();

    return 0;
}
