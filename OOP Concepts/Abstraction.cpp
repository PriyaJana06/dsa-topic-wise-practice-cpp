#include<iostream>
#include<string>
using namespace std;

// Abstract Class
class Shape {
public:
    virtual void draw() = 0;   // Pure Virtual Function (Abstract Function)
};

class Circle : public Shape {
public:
    void draw(){
        cout << "Draws Circle...\n";
    }
};

class Square : public Shape {
public: 
    void draw(){
        cout << "Draws Square...\n";
    }
}; 

int main(){

    Circle c1;
    c1.draw();

    Square sq1;
    sq1.draw();
    
    return 0;
}