#include<iostream>
#include<string>
using namespace std;

// Single Inheritance
// Parent Class
class Animal {
public:
    string color;

    void eat(){
        cout << "Eats...\n";
    }

    void breathe(){
        cout << "Breathes...\n";
    }
};

// Child Class
class Fish : public Animal {
public:
    int fins;
    
    void swim(){
        // eat();   // Protected Inheritance
        // breathe();
        cout << "Fish Swims...\n";
    }

};


// Multilevel Inheritance
// Parent Class
class Animal2 {
public:
    void eat(){
        cout << "Eats...\n";
    }

    void breathe(){
        cout << "Breathes ...\n";
    }
};

// Child Class1
class Mammal : public Animal2 {
public:
    string bloodType;

    Mammal(){   //Default Constructor
        bloodType = "Warm";
    }
};

// Child Class2
class Dog : public Mammal {
public: 
    void tailWag(){
        cout << "A Dog wags its tail\n";
    }

    void bark(){
        cout << "Dog Barks...\n";
    }
};


// Multiple Inheritance
// Parent Class
class Teacher {
public:
    int salary;
    string subject;
};

// Parent Class
class Student {
public:
    int rollno;
    float cgpa;
};

// Child Class
class TA : public Teacher, public Student {
public:
    string name;
};


// Hierarchical Inheritance
// Parent Class
class Animal3 {
public:
    void eat(){
        cout << "Can Eat...\n";
    }

    void breathe(){
        cout << "Can Breathe...\n";
    }
};

// Child Class1
class Bird : public Animal3 {
public:
    void fly(){
        cout << "Can Fly...\n";
    }
};

// Child Class2
class Fish2 : public Animal3 {
public: 
    void swim(){
        cout << "Swim, Swim...\n";
    }
};

int main(){

    // Single Inheritance
    // Fish f1;
    // f1.fins = 3;
    // cout << "Number of fins: " << f1.fins << endl;
    // f1.swim();
    // f1.breathe();
    // f1.eat();

    // Not possible by protected mode of inheritance
    // f1.eat();
    // f1.breathe();


    // Multilevel Inheritance
    // Dog d1;
    // d1.eat();
    // d1.bark();
    // d1.breathe();
    // d1.tailWag();
    // cout << d1.bloodType << endl;


    // Multiple Inheritance
    // TA ta1;
    // ta1.name = "Priyanka Jana";
    // ta1.subject = "Economics";
    // ta1.cgpa = 9.2;
    // ta1.salary = 4500;

    // cout << ta1.name << endl;
    // cout << ta1.salary << endl;
    // cout << ta1.subject << endl;
    // cout << ta1.cgpa << endl;


    // Hierarchical Inheritance
    // Fish2 f1;
    // f1.breathe();
    // f1.eat();
    // f1.swim();

    // Bird b1;
    // b1.breathe();
    // b1.eat();
    // b1.fly();


    return 0;
}