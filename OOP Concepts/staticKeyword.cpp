#include<iostream>
#include<string>
using namespace std;

//static in class
class Example {
    public:
        static int x;  // declaration
};

int Example::x = 0;  // initialisation
 
// static in functions
void counter(){
    static int count = 0;  // static in function
    count++;
    cout << "Count: " << count << endl;
}


// static objects
class Example2 {
    public:
        Example2() {
            cout << "Constructor...\n";
        }

        ~Example2() {
            cout << "Destructor...\n";
        }
};


// Friend Class & Function:
class A {
    string secret = "A very suspicious data...\n";
    friend class B;
    friend void revealSecret(A &obj);
};

// Friend Class
class B {    // becomes friend class of A
public:
    void showSecret(A &obj){
        cout << obj.secret << endl;
    }
};

// Friend Function
void revealSecret(A &obj){
    cout << obj.secret << endl;
}


// Practice Que1:
class A1 {
public:
    A1() { 
        cout << "Constructor A" << endl;
    }

    ~A1() { 
        cout << "Destructor A" << endl;
    }
};

class B1 : public A1 {
public:
    B1() { 
        cout << "Constructor B" << endl;
    }

    ~B1() { 
        cout << "Destructor B" << endl;
    }
};

// Practice Que2:
class Base {
public:
    virtual void print(){
        cout << "Base" << endl;
    }
};

class Derived : public Base {
public:
    void print() override {
        cout << "Derived" << endl;
    }
};

int main(){
    // static in functions
    // counter();
    // counter();
    // counter();
  
    
    // Static in Class
    // Example eg1;
    // Example eg2;
    // Example eg3;

    // cout << eg1.x++ << endl;
    // cout << eg2.x++ << endl;
    // cout << eg3.x++ << endl;
    

    // static objects
    // int a = 0;
    // if(a == 0){
    //     static Example2 eg1;
    // }

    // cout << "code ending...\n";


    // Friend Class & function
    // A a1;
    // B b1;

    // b1.showSecret(a1);  // copy constructor
    // revealSecret(a1);


    // Practice Que1:
    // B1 obj;

    // Practice Que2:
    Base* b = new Base();
    b->print();
    delete b;

    return 0;
}