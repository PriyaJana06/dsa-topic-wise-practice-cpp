#include<iostream>
#include<string>
using namespace std;

// Classes & Objects
class Student { 
    // Properties
    float cgpa;  // By default, its Private.
public:
    string name;

    //Methods
    void getPercentage(){
        cout << (cgpa * 10) << "% \n";
    }

// Indirect Access for Private Properties
    // Setters -> Sets value for Properties
    void setCgpa(float cgpaVal){   // Creating Setter() for private properties
        cgpa = cgpaVal;
    }

    // Getters -> gets value of Properties
    float getCgpa(){
        return cgpa;
    }
};

// Practice Que: Instagram Users Account 
class User {
private:
    int id;
    string password;

public:
    string username;

    User(int id){
        this->id = id;
    }

    void deactivate(){
        cout << "Deactivating Account\n";
    }

    // Setter
    void setPassword(string password){
        this->password = password;
    }

    // Getter
    string getPassword(){
        return password;
    }
 };

// Car Class
class Car {
    string name;
    string color;

public:
    Car() {  // Custom Non-Parameterized Constructor
        cout << "Constructor without Parameters is invoked.\n";
    }

    Car(string name, string color) {  // Custom Constructor
        cout << "Constructor with Parameters is invoked.\n";
        this->name = name;   // *(this).prop OR this->prop
        this->color = color;   // object prop = parameter name
    }

    void start(){
        cout << "Car Started...\n"; 
    }

    void stop(){
        cout << "Car Stoped...\n";
    }

    // Getters  
    string getName(){
        return name;
    }

    string getColor(){
        return color;
    }
};

// Copy Constructor/ Shallow Copy & Deep Copy
class Car2 {
    public:
        string name;
        string color;

    // Parameterized Constructor
    Car2(string name, string color){
        this->name = name;
        this->color = color;
    }

    // Custom Copy Constructor
    Car2(Car2 &original){
        cout << "copying original to new...\n";
        name = original.name;
        color = original.color;
    }
};

int main(){
/*
    Student s1;  // object
    // cout << sizeof(s1) << endl;  // size of obj is 28

    s1.name = "Priyanka";  // Direct Access for Public Properties
    cout << s1.name << endl; 

    s1.setCgpa(9.2);   // Indirect Access for Private Properties
    cout << s1.getCgpa() << endl;
*/

/* 4Pillars of OOPs: 
    // Encapsulation
    // Inheritance
    // Abstraction
    // Polymorphism */
    
/*
    // Constructor
    Car c;   // Invokes constructor without parameter.
    Car c1("MG Hector", "Dual Color");   // constructor invoked automatically, when obj is created
    Car c2("Fortuner", "White");

    c1.start();
    cout << "Car Name: " << c1.getName() << endl;
    cout << "Car Color: " << c1.getColor() << endl;
    c1.stop();
*/

/*
    // Practice Que:
    User user1(101);
    user1.username = "_priyanka_j";
    user1.setPassword("priyaroy");

    cout << "Username: " << user1.username << endl;
    cout << "Password: " << user1.getPassword() << endl;
*/

/*
    // Copy Constructor
    Car2 c1("Maruti 800", "White");
    
    Car2 c2(c1);   // Custom Copy Constructor
    cout << c2.name << endl;
    cout << c2.color << endl;
*/


    // Shallow Copy & Deep Copy





    return 0;
}