#include<iostream>
// #define PI 3.14
using namespace std;

int main(){

    // Type Conversion: Implicit
    // cout << (10/3) << endl;   // 3
    // cout << (10/3.0) << endl;  // 3.3333

    // cout << ('$' + 1) << endl;   //37
    // cout << ('$' - 0) << endl;   //36
    // cout << ('A' + 1) << endl;   //66


    // Type Conversion:  Explicit:
    // cout << (int)('$') << endl;   //36
    // float PI = 3.14;
    // cout << (int)PI << endl;    //3
    // cout << (int)(10/3.0) << endl;   // 3
    // cout << ((float)10/3) << endl;   //3.333
    // cout << (char)('A'+1) << endl;  //B
    // cout << (bool)3+2 << endl;   //1 + 2 = 3
    // cout << (23.5 + 2 + 'A') << endl;


    // Unary Operator:
    //Increment: ++
    // int a = 3;
    // a++;
    // cout << a << endl;
    // ++a;
    // cout << a << endl;

    /*
    int b = a++;  // use & then update. 
    cout << "a = " << a << endl;  //4
    cout << "b = " << b << endl;  //3
    int c = ++a;   // update & then use.
    cout << "c = " << c << endl;  //5
    int d = c++; 
    cout << "d = " << d << endl;  //5
    */

    // Unary Operator: Decrement --
    /*
    int x = 6;
    // x--;
    // cout << "x = " << x << endl;  //5
    // --x;
    // cout << "x = " << x << endl;  //4
    
    int y = x--;
    cout << "y = " << y << endl;  //6
    int z = --x;
    cout << "z = " << z << endl;  //4
    */




    /*
    // Que: Print area of square.
    int side;
    cout << "Enter a number(side) in cm: ";
    cin >> side;

    int area = side*side;
    cout << "Area of Square is "<< area <<" sqcm."<< endl;
    */

    /*
    // Que: Find total cost of items.
    float pencil;
    float pen;
    float eraser;
    cout << "Enter Price of your items: ";
    cin>> pencil >> pen >> eraser;

    float total = pencil + pen + eraser;
    cout << "Total Cost is " << total << endl;
    cout << "Your Bill is " << total + (total*0.18) << " Rs. with GST."<< endl;
    */

    /*
    //Que: Simple Interest Calculator
    float P;
    float R;
    float T;

    cout << "Enter your Principle(P) amount: ";
    cin>> P;
    cout << "Enter rate(R) of Interest: ";
    cin>> R;
    cout << "Enter Time(T): ";
    cin>> T;
 
    float SimpleInterest = (P*R*T)/100;
    cout << "Total Simple Interest is " << SimpleInterest << endl;
    */

    /*
    //Que: Area of circle
    float radius;
    cout << "Enter radius in cm: ";
    cin>> radius;

    float area_Circle = PI*radius*radius;
    cout << "Area of Circle is " << area_Circle << endl;
    */


    // Que1: 
    /*
    int x = 2, y = 5;
    int exp1 = (x*y/x);  // 5*2 = 10/2 => 5
    int exp2 = (x* (y/x));  // 4
    cout << exp1 << ", ";
    cout << exp2 << "\n";
    */

    // Que2:
    /*
    int x = 10, y=5;
    int exp1 = (y*(x/y + x/y));  //20
    int exp2 = (y*x/y + y*x/y);  //20
    cout << exp1 << " ";
    cout << exp2 << "\n";
    */

    // Que3:
    /*
    int x = 200, y=50, z=100;
    if(x>y && y>z){
        cout << "Hello\n";
    } 
    if(z>y && z<x){
        cout << "C++\n";
    }
    if((y+20)< x && (y+150)<z){
        cout << "Hello C++\n";
    }
    */


    //Que: Print the largest of 2 numbers
    /*
    int A, B;
    cout << "Enter a value for A: ";
    cin>> A;
    cout << "Enter a value for B: ";
    cin>> B;

    if(A > B){
        cout << "Greatest number is "<< A << endl;
    } else if (A == B) {
        cout << "Value A and Value B are equal." << endl;
    } else {
        cout << "Greatest number is " << B << endl;
    }
    */


    // Que: Print if a number is Odd OR Even.
    /*
    int num;
    cout << "Enter a number: ";
    cin>> num;

    if(num % 2 == 0){
        cout << "Number is Even." << endl;
    } else {
        cout << "Number is Odd." << endl;
    }
    */


    //Que: Income Tax Calculator
    /*
    float income;
    float tax;
    const int LAKH = 100000;
    cout << "Enter income (in Lakhs): ";
    cin>> income;

    if(income <= 5){
        // 0%
        tax = 0;
    } else if (income <= 10){
        //20%
        tax = 0.2 * (income-5);
    } else {
        //30%
        tax = (0.2 * 5) + 0.3 * (income-10);
    }
    cout << "Tax = " << (tax * LAKH) << " rupees" << endl;
    */

    //Que: Print largest of 3 numbers
/*
    int A, B, C;
    cout << "Enter a value A: ";
    cin>> A;
    cout << "Enter a value B: ";
    cin>> B;
    cout << "Enter a value C: ";
    cin>> C;

    if((A >= B) && (A >= C)) {
        cout << "Greatest number is A = " << A << endl;
    } else if((B >= A) && (B >= C)){
        cout << "Greatest number is B = " << B << endl;
    } else {
        cout << "Greatest number is C = " << C << endl;
    }
*/


    // int age;
    // bool isAdult;
    // cout <<"Enter your age: ";
    // cin>>age;

    // Ternary operator:
    // isAdult = (age>=18)? true : false;
    // cout << isAdult << endl;


    // // Largest of 2 numbers
    // int a, b;
    // cout << "Enter two number A and B: ";
    // cin>> a >> b;

    // int largest = (a>=b)? a : b;
    // cout << "Largest number is: " << largest << endl;


    // Odd or Even 
    // int num;
    // cout << "Enter a number: ";
    // cin >> num;

    // bool odd_Even = (num % 2 == 0)? true : false;
    // cout << odd_Even << endl;


    // Switch Statement:
    /*
    int day;
    cout << "Enter a number (1 to 7): ";
    cin >> day;

    switch (day)
    {
    case 1: cout << "Monday" << endl;
        break;
    case 2: cout << "Tuesday" << endl;
        break;
    case 3: cout << "Wednesday" << endl;
        break;
    case 4: cout << "Thursday" << endl;
        break;
    case 5: cout << "Friday" << endl;
        break;
    case 6: cout << "Saturday" << endl;
        break;
    case 7: cout << "Sunday" << endl;
        break;
    default: cout << "Invalid Input!" << endl;
        break;
    }
    */

    // Que: Arithmetic Calculator
    // int a, b;
    // char op;
    // cout << "Enter two numbers: ";
    // cin >> a >> b;
    // cout << "Enter arithmetic operation: ";
    // cin>> op;

    /*
    if(op == '+'){
        cout << "Addition is " << a+b << endl;
    } else if(op == '-'){
        cout <<"Subtraction is " << a-b << endl;
    } else if(op == '*'){
        cout << "Multiplication is " << a*b << endl;
    } else if(op == '/'){
        cout << "Quotient is " << a/b << endl;
    } else {
        cout << "Invalid Operator!" << endl;
    }
    */

    /*
    // Using Switch Case:
    switch(op){
        case '+': cout << "Addition is " << a+b << endl;
            break;
        case '-': cout << "Subtraction is " << a-b << endl;
            break;
        case '*': cout << "Multiplication is " << a*b << endl;
            break;
        case '/': cout << "Division is " << (float)a/b << endl;
            break;
        default: cout << "Invalid Operator" << endl;
            break;
    }
    */


    // Que:
    /*
    int number;
    cout << "Enter a number: ";
    cin >> number;
    
    if(number < 0){
        cout << "Number is Negative" << endl;
    } else if (number==0){
        cout << "Number is ZERO" << endl;
    } else {
        cout << "Number is Positive" << endl;
    }
    */


    //Que: Leap year or not
    
    int year;
    cout << "Enter year: ";
    cin>> year;

    if((year%4 == 0) || (year%400==0)){
        cout << year << " is a leap year." << endl;
    } else if(year % 100 == 0){
        cout << year << " is NOT a leap year." << endl;
    } else {
        cout << year << " is NOT a leap year." << endl;
    }
    



    //Que: 
    int a = 63, b = 36;
    bool x = (a<b)? true : false;
    int y = (a>b)? a : b;
    cout << x << ", " << y << endl;   // 0, 63


    int c = 5;
    if(++c*5 <= 25){
        cout << "Hello\n";
    } else {
        cout << "Bye\n";
    }

    return 0;
}