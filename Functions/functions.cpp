#include<iostream>
using namespace std;

void myName();    // function Declaration

void sayHello(){     // function Definition
    cout << "Hello :) \n";
}

void assistant(){
    sayHello();
    cout << "Work done! \n";
}


// Function Overloading:
int sum(int a, int b){
    cout << (a+b) << endl;
    return a+b;
}

int sum(int a, int b, int c){
    cout << (a+b+c) << endl;
    return a+b+c;
}

double sum(double a, double b){
    cout << (a+b) << endl;
    return a+b;
}


// Que's:

int product(int a, int b){
    int product = a*b;
    return product;
}

bool isEven(int a){
    if(a % 2 == 0){
        return true;
    } else {
        return false;
    }
}

int factorial(int n){
    int factorial = 1;
    // if(n == 0) return 1;       // 0! -> // (1 never <= 0) -> 1
    if(n<0) {
        cout << "Negative Not Allowed" << endl;
        return -1;
    }
    for(int i=1; i<=n; i++){   
        factorial *= i;
    } 
    return factorial;
}

bool isPrime(int n){
    if(n==1) return false;
    if(n==0) return false;
    for(int i=2; i<=n-1; i++){
        if(n%i == 0) {
            return false;
        }
    } return true;
}

bool isPrime2(int n){
    if(n==1) return false;
    if(n==0) return false;
    for(int i=2; i*i<=n; i++){
        if(n%i == 0){
            return false;   // n is Non-Prime
        }
    } return true;   // n is Prime
}

int binomialCoeff(int n, int r){
    int val1 = factorial(n);
    int val2 = factorial(r);
    int val3 = factorial(n-r);

    int result = val1 / (val2*val3);
    return result;
}

void allPrimes(int n){
    for(int i=2; i<=n; i++){
        if(isPrime2(i)){  // true
            cout << i << " ";
        }
    }
    cout << endl;
}

// Assignment Que's:

void checkPalindrome(int num){
    int dupNum = num;
    int reverse = 0;
    while(num > 0){
        int lastdigit = num%10;
        reverse = (reverse*10) + lastdigit;
        num/=10;
    } 

    if(dupNum == reverse){
        cout << dupNum << " is Palindrome number."<< endl;
    } else {
        cout << dupNum << " is NOT Palindrome number." << endl;
    }
}

int sumOfDigits(int num){
    int sum = 0;
    while(num > 0){
        int lastDigit = num%10;
        sum += lastDigit;
        num/=10;
    }
    return sum;
}

int abSquare(int a, int b){
    return a*a + b*b + 2*a*b;
}

void largestOf3No(int a, int b, int c){
    if((a >= b) && (a >= c)){
        cout << a << " is Largest Number.";
    } else if ((b >= a) && (b >= c)){
        cout << b << " is Largest Number.";
    } else {
        cout << c << " is Largest Number.";
    }
}

char getNextChar(char ch){
    if(ch == 'z')
        return 'a';
    return ch+1;
}

int main(){
    // assistant();   // function call
    // sayHello();
    // myName();


    // Que's:
    // int n; cout << "Enter a number: "; cin >> n;
    
    // cout << "Product is: " << product(34, 4) << endl;
    // cout << isEven(n) << endl;
    // cout << "Factorial of " << n << "! is " << factorial(n) << endl;
    // cout << isPrime(n) << endl;
    // cout << isPrime2(n) << endl;

    // int r; cout << "Enter r: "; cin >> r;
    // cout << binomialCoeff(n, r) << endl;
    // allPrimes(n);

    // Function Overloading:
    // sum(2, 4);
    // sum(34, 4, 56);
    // sum(45.3, 33.21);


    // Assignment Que's:
    
    // checkPalindrome(n);
    // cout <<"Sum of digits of a number " << n << " is " << sumOfDigits(n) << endl;
    // int a, b; cout << "Enter value for a & b: "; cin >> a >> b;
    // cout << "Value of " << "(" << a << "+" << b << ")^2 is " << abSquare(a, b) << endl;

    // int a, b, c; cout << "Enter three numbers: "; cin>>a>>b>>c;
    // largestOf3No(a, b, c);


    cout << "Value = " << getNextChar('z');



    // MCQ Test:
    int meal = 5;
    int tip = 2;
    int total = meal + (meal > 6? ++tip: --tip);
    cout << total;   // 6

    if(1+1+1+1+1 == 5){
        cout << "True\n";
    } else {
        cout << "False\n";
    }

    return 0;
}


void myName(){    // Forward Declaration
    cout << "Hi! I am Priyanka. \n";
}