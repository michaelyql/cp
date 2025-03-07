#include <iostream>
#include <string>

using namespace std;

struct my_pair {
  int first;
  int second;
  void setValues(int x, int y) {
    first = x;
    second = y;
  }
};

// operator overloading
my_pair operator>(const my_pair& p1, const my_pair& p2) 
{
  return p1.first > p2.first ? p1 : p2;
}

// abstract base class
class Animal {
  friend class AnimalHandler;
private:
  virtual void eatFood() =0; 
public:
  string breed;
  Animal() : breed("") {};
  Animal(string s) : breed(s) {};
  // pure virtual function
  virtual string make_sound() =0;
};

// inheritance 
class Dog : public Animal {
private:
  void eatFood() {
    cout << "dog eating food" << endl;    
  }
public: 
  Dog() : Animal("dog") {};
  string make_sound() {
    return "woof";
  }
};

class AnimalHandler {
public:
  // friend class
  static void handleAnimal(Animal& a1, Animal& a2) {
    a1.eatFood();
    a2.eatFood();
  }; 
};

int main() 
{
  my_pair p1, p2;
  p1.setValues(2, 1);
  p2.setValues(1, 2);
  int val = (p1 > p2).first;
  cout << "val: " << val << endl;

  Animal * a1;
  Dog dog1; 
  a1 = &dog1; 
  cout << a1->make_sound() << endl;

  AnimalHandler::handleAnimal(dog1, dog1);

  cout << "test" << endl;
}
