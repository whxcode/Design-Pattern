#include <iostream>
#include <list>

using namespace std;

class Component {
  public:
    virtual void add(Component* com) {

    }
    virtual void remove(Component* com) {

    }

    virtual void display() {
      cout<< name << endl;
    }
  protected:
    string name;
};


class Composite :public Component {
  public:
  Composite(string name) {
    l.clear();
    this->name = name;
  }

  ~Composite() {
      for(auto it : l)  {
        delete it;
      }
  }
  public:
    void add(Component *com) override {
      l.push_back(com);
    }

    void remove(Component *com) override {
      l.remove(com);
    }
    void display() override {
      Component::display();

      for(auto it : l)  {
        it->display();
      }

      cout << "----" << endl;
    }
  private:
    list<Component*> l;
};

class Leaf :public Component {
  public:
  Leaf(string name) {
    this->name = name;
  }
};

int main() {
  Composite* university = new Composite("大学");
  Component* infoCollege = new Composite("信息工程系");
  Component* dynamicCollege = new Composite("动漫系");

  infoCollege->add(new Leaf("java"));
  infoCollege->add(new Leaf("c"));
  infoCollege->add(new Leaf("c++"));

  dynamicCollege->add(new Leaf("3d"));
  dynamicCollege->add(new Leaf("maya"));
  dynamicCollege->add(new Leaf("c5d"));

  university->add(infoCollege);
  university->add(dynamicCollege);

  university->display();

  cout <<  endl;
  cout <<  endl;

  infoCollege->display();

  delete university;

  return 0;
}
