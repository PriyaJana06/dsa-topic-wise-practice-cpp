#include<iostream>
#include<string>
using namespace std;

//// Compile Time Polymorphism
// Function Overloading
class Print{
public:
    void show(int x){
        cout << "Int: "<< x << endl;
    }

    void show(string str){
        cout << "String: " << str << endl;
    }
};

//// Operator Overloading
// Binary Operator Overloading
class Complex {
    float real, img;

public:
    Complex(float r, float i){   // Constructor
        real = r;
        img = i;
    }

    void showNum() {
        cout << real << " + " << img << "i \n";
    }

    // Operator Functions 
    Complex operator +(Complex &c2){
        float resReal = this->real + c2.real;
        float resImg = this->img + c2.img;

        Complex c3(resReal, resImg);
        cout << "Result: ";
        return c3;
    }

    Complex operator -(Complex &c2){
        float resReal = this->real - c2.real;
        float resImg = this->img - c2.img;

        Complex c4(resReal, resImg);
        cout << "Result: ";
        return c4;
    }
};


// Unary Operator Overloading
class Demo {
    int x;

public:
    void getdata() {
        cout << "Enter value of x : ";
        cin >> x;
    }

    void displaydata() {
        cout << "x : " << x;
    }

    // Operator Function
    void operator ++() {
        x = x + 1;
    }
};


int main(){

    //// Compile Time Polymorphism
    // Function Overloading
    // Print obj1;
    // obj1.show(25);
    // obj1.show("Priyanka");


    // Binary Operator Overloading
    Complex c1(1, 3);
    Complex c2(3, 4);

    cout << "c1: ";
    c1.showNum();
    cout << "c2: ";
    c2.showNum();

    Complex c3 = c1 + c2;
    c3.showNum();

    Complex c4 = c3 - c2;
    c4.showNum();


    // Unary Operator Overloading
    Demo obj;
    obj.getdata();

    cout << "Orignal value of ";
    obj.displaydata();

    ++obj;
    
    cout << "\nValue after increment of ";
    obj.displaydata();
    
    return 0;
}