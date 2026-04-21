#include<iostream>
#include<cmath>
using namespace std;

int main(){
    // int n;
    // cout << "Enter a number: ";
    // cin >> n;

/*
    // for(int i=1; i<=n; i++){
    //     cout << i << " ";
    // }

    // Sum of N natural numbers
    int sum = 0;
    for(int i=1; i<=n; i++){
        sum += i;
    }
    cout << "Sum of "<< n << " natural number is: " << sum << endl;
    cout << "Sum of "<< n << " natural number is: " << n*(n+1)/2<< endl;

    int i = 1;
    int sum2 = 0;
    while(i<=n){
        sum2 += i;
        i++;
    } cout << "Sum is: " << sum2;
*/


    // Que: print square pattern using loop
/*
    // for(int i=1; i<=4; i++){
    //     cout << "****" << endl;
    // } 

    // for(int i=0; i<n; i++){
    //     for(int j=0; j<n; j++){
    //         cout << "*";
    //     } cout << endl;
    // }
*/


/*
    // Que: print numbers from n to 1
    for(int i=n; i>0; i--){
        cout << i << " ";
    } cout << endl;
*/


/*
    // Que: print sum of digits of a number 
         // initialisation
    int dpnum = n;
    int sum = 0;
    while(n > 0){
        int lastdigit = n % 10;
        sum += lastdigit;
        n /= 10;    // updation
    }
    cout << "Sum of digits of a number "<<dpnum<<" is "<<sum<<"."<< endl;
*/


/*
    // Que: print sum of odd digits of a number
      // initialisation
    int dpnum = n;
    int sum = 0;
    while(n > 0){
        int lastdigit = n % 10;
        if(lastdigit % 2 != 0){   // sum of odd digits
            sum += lastdigit;
        }
        n /= 10;    // updation
    } cout << "Sum of odd digits of a number is " << sum << endl;
*/


/*
    // Que: print digits of given reverse 
    while(n>0){
        int lastDigit = n%10;
        cout << lastDigit;
        n/=10;
    } cout << endl;

    // OR

    int reverse = 0;
    while(n>0){
        int lastDigit = n%10;
        reverse = reverse*10 + lastDigit;   // 0*10 + 9 = 9 and so on.
        n/=10;
    } cout << "Reverse No : "<< reverse;
*/

/*
    //do - while loop
    int val = 1;
    do{
        cout << "Priyanka Roy in do-while loop";     // will execute atleast once even if condition is false
    } while(val > 5);

    while(val > 5){
        cout << "Priyanka Roy in while loop";
    }
*/


/*
    // break statement:

    int i = 1;
    while(i<=10){
        cout << "i = " << i << endl;
        i++;            // updation
        if(i==5){
            break;     // exit the loop if condition is true
        }
    } cout << "out of loop" << endl;
    cout << i << endl;    // i=5

    int j = 1;
    while(j<=10){
        cout << "j = " << j << endl;
        if(j==5){
            break;     // exit the loop if condition is true
        }
        j++;           // updation
    } cout << "out of loop" << endl;
    cout << j;      // j=5
*/


/*
    // Que: user can keep entering numbers till they enter multiple of 10
    int val;
    do{
        cout << "Enter any value: ";
        cin >> val;
        if(val%10==0){
            cout << "Sorry! You entered multiple of 10."<< endl;
            break;
        }
        cout << "Your entered " << val << endl;
    } while(true);
*/


/*
    // continue statement:
    for(int i=1; i<=10; i++){
        if(i==3){
            continue;   // to skip an iteration
        }
        cout << i << endl;
    }

    //Que: show numbers entered by user except multiples of 10
    int val;
    do{
        cout << "Enter any number: ";
        cin>>val;
        if(val%10==0){
            cout << "Oops! Your number skipped."<< endl;
            continue;        // creates an infinite loop here.
        }
        cout << "You entered " << val << endl;
    }while(true);
*/


/*
// Prime number or NOT:
int num;
cout << "Enter a number: ";
cin>>num;

bool isPrime = true;
for(int i=2; i<=num-1; i++){
    if(num % i == 0){    // i is a factor of n; i completely divides n; n is non-prime
        isPrime = false;
        break;               // one check of factor is enough to find Prime no.
    }
}

if(isPrime){   // isPrime == true  OR isPrime  
    cout << "Number is PRIME";
} else {
    cout << "Number is NOT PRIME";
}
*/

/*
// OPTIMIZED:   O(sqrt(n))
int num;
cout << "Enter a number: ";
cin>>num;

bool isPrime = true;
for(int i=2; i<=sqrt(num); i++){
    if(num % i == 0){    // i is a factor of n; i completely divides n; n is non-prime
        isPrime = false;
        break;               // one check of factor is enough to find Prime no.
    }
}

if(isPrime){   // isPrime == true  OR isPrime  
    cout << "Number is PRIME";
} else {
    cout << "Number is NOT PRIME";
}
*/



// Assignment Ques:
/*
    // Que: find factorial of a number 
    int fact = 1;
    for(int i=1; i<=n; i++){
            fact*=i;
    } cout <<"Factorial of "<<n<<" is: "<<fact<<endl;
*/


/*
    //Que: print multiplication table of a number
    cout << "Multiplication table of number "<<n<< " is"<< endl;
    for(int i=1; i<=10; i++){
        int ans = n * i;
        cout << n << " * " << i <<" = " << ans << endl;
    }
*/


/*
    // Que: check whether a number is Armstrong no. or not
    int sumOfCubes = 0;
    int dupNO = n;
    while(n>0){
        int lastDigit = n%10;
        sumOfCubes += lastDigit*lastDigit*lastDigit;
        n/=10;
    }

    if(dupNO == sumOfCubes){
        cout << "It is AN Armstrong number";
    } else {
        cout << "It is NOT an Armstrong number";
    }
*/


/*
    //Que: prints all the prime numbers from 2 to N
    int N;
    cout << "Enter N: ";
    cin >> N;

    for(int i=2; i<=N; i++){
        bool isPrime = true;
        for(int j=2; j<i; j++){
            if(i%j==0){
                isPrime = false;
                break;
            }
        }
        if(isPrime){
            cout << i << " ";
        }
    }
*/



    // Que: nth Fibonacci number
    int n; cout << "Enter nth number: "; cin>>n;

    int first = 0;
    int second = 1;

    if(n == 0) {
        cout << first;
    } else {
        for(int i=2; i<=n; i++){
            int curr = first + second;
            first = second;
            second = curr;
        } 
        cout << "nth fibonacci number is " << second << " ";
    } 
    cout << "\n";


    //Que: print n fibonacci numbers   (has some errors)

    int p1 = 0;
    int p2 = 1;
    
    if(n == 0){
        cout << p1 << " ";
    } else {
        cout << p1 << " " << p2 << " ";
    }

    for(int i=2; i<=n; i++){
        int curr = p1 + p2;
        cout << curr << " ";
        p1 = p2;
        p2 = curr;
    }
        // cout << "nth fibonacci number is " << second << " ";
    cout << "\n";



    return 0;
}