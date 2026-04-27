#include<iostream>
using namespace std;

// Runtime Polymorphism
class Parent {
public:
    void show(){
        cout << "Parent Class show...\n";
    }

    virtual void hello(){   // Virtual Function
        cout << "Parent Hello...\n";
    }
};

class Child: public Parent{
public:
    void show(){   // Overrides
        cout << "Child Class show...\n";
    }

    void hello(){
        cout << "Child Hello...\n";
    }
};

int main(){

    Parent parent1;
    Child child1;

    cout << "pptr points to Parent obj\n";
    Parent *pptr;       // parent ptr points to parent obj
    pptr = &parent1;
    pptr->hello();
    pptr->show();   // Non-Virtual Function
    
    cout << "\npptr points to Child obj\n";
    pptr = &child1;   // parent ptr points to Child class obj (Runtime Binding)
    pptr->hello();   // Virtual Function -> calls child virtual function
    pptr->show();   // Non-Virtual Function 

    cout << "\n";

    Child *cptr;
    cptr = &child1;
    cptr->show();
    cptr->hello();

    return 0;
}