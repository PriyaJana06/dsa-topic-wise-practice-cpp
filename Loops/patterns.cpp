#include<iostream>
using namespace std;
 
void basicPatternBox(int n){
    int i;
    for(i=1; i<=n; i++){
        for(int j=1; j<=n+1; j++){
            cout << i << " ";
        } cout << "\n";
    }
    cout << i << endl;  
}

void starPattern(int n){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            cout << "* ";
        } cout << "\n";
    }
}

void invertedStar(int n){
    for(int i=1; i<=n; i++){
        for(int j=n; j>=i; j--){
            cout << "* ";
        }
        cout << "\n";
    }
}

void halfPyramid(int n){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            cout << j;
        } cout << "\n";
    }
}

void halfPyramid2(int n){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            cout << i;
        } cout << "\n";
    }
}

void characterPyramid(int n){
    char ch = 'A';    // written outside loop because we don't have to reinitialise ch
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            cout << ch++;
        } cout << "\n";
    }
}

void characterPyramid2(int n){
    for(int i=1; i<=n; i++){
        char ch = 'A';         // written inside loop because we have to reinitialise ch
        for(int j=1; j<=i; j++){
            cout << ch++;
        } cout << "\n";
    }
}

void hollowRect(int n){
    for(int i=1; i<=n; i++){
        cout << "*";   // first star (compulsory)
        for(int j=1; j<=n-1; j++){
            if(i==1 || i==n) cout << "*";
            else cout << " ";
        } cout << "*" << endl;  // last star (compulsory)
    }
}

void invertedRotatedHalfPyramid(int n){
    for(int i=1; i<=n; i++){
        // spaces
        for(int j=1; j<=n-i; j++){
            cout << " ";
        } // stars
        for(int j=1; j<=i; j++){
            cout << "*";
        }
        cout << "\n";
    }
}

void floydsTriangle(int n){
    int num = 1;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            cout << num++ << " ";
        }
        cout << "\n";
    }
}

void diamondPattern(int n){
    // 1st half
    for(int i=1; i<=n; i++){
        // spaces -> 1 to n-i
        for(int j=1; j<=n-i; j++){
            cout << " ";
        } // stars -> 1 to 2*i-1
        for(int j=1; j<=2*i-1; j++){
            cout << "*";
        } cout << endl;
    }
    // 2nd half
    for(int i=n; i>0; i--){  // reverse loop
        // spaces   -> 1 to n-i
        for(int j=1; j<=n-i; j++){
            cout << " ";
        }
        // stars -> 1 to 2*i-1
        for(int j=1; j<=2*i-1; j++){
            cout << "*";
        } cout << endl;
    }
}

void butterflyPattern(int n){
    // 1st half 
    for(int i=1; i<=n; i++){
        // stars -> 1 to i
        for(int j=1; j<=i; j++){
            cout << "*";
        }
        // spaces -> 1 to 2*(n-i)
        for(int j=1; j<=2*(n-i); j++){
            cout << " ";
        }
        // stars -> 1 to i
        for(int j=1; j<=i; j++){
            cout << "*";
        } cout << endl;
    }
    // 2nd half
    for(int i=n; i>0; i--){
        // stars
        for(int j=1; j<=i; j++){
            cout << "*";
        }
        // spaces
        for(int j=1; j<=2*(n-i); j++){
            cout << " ";
        }
        // spaces
        for(int j=1; j<=i; j++){
            cout << "*";
        } cout << endl;
    }
}

void hollowDiamond(int n){   // not in course
//top:
    for(int i=0; i<n; i++) {
        for(int j=0; j<n-i-1; j++) {
            cout << " ";   //spaces
        }
        cout << "*";
    
        if(i != 0) {   
            for(int j=0; j<2*i-1; j++) {
                cout << " ";    //spaces
            }
            cout << "*";
        }
        cout << endl;
    }

//bottom
    for(int i=0; i<n-1; i++) {
        //spaces
        for(int j=0; j<i+1; j++) {
            cout << " ";
        }
        cout << "*";

        if(i != n-2) {
            for(int j=0; j<2*(n-i)-5; j++){
                cout<< " ";
            }
            cout << "*";
        }
        cout << endl;
    }
}

void squarePattern(int n){    // not in course
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cout << j;
        } cout << endl;
    }
}

void reverseTriangle(int n){   // not in course
    for(int i=0; i<n; i++){
        for(int j=i+1; j>0; j--){
            cout << j << " "; 
        } cout << endl;
    }
}

void pyramid(int n){     // not in course
    for(int i=0; i<n; i++){
        for(int j=1; j<n-i; j++){
            cout << " ";
        }
        for(int j=1; j<=i+1; j++){
            cout << j;
        }
        for(int j=i; j>0; j--){
            cout << j;
        } cout << endl;
    }
}

// Assignment Que's:

void zeroOneTriPatternODD(int n){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            if((i+j) % 2 != 0){   // 2+1 = 3 != 0 -> true 
                cout << 0;
            } else{
                cout << 1;
            }
        } cout << endl;
    }
}

void zeroOneTriPatternEVEN(int n){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            if((i+j) % 2 == 0){   // 2+1 = 3 != 0 -> true 
                cout << 0;
            } else{
                cout << 1;
            }
        } cout << endl;
    }
}

void rhombusPattern(int n){
    for(int i=1; i<=n; i++){
        // spaces
        for(int j=1; j<=n-i; j++){
            cout << " ";
        }
        // stars
        for(int j=1; j<=n; j++){
            cout << "*";
        } cout << "\n";
    }
}

void palindromicPattern(int n){
    for(int i=1; i<=n; i++){
        // spaces
        for(int j=1; j<=n-i; j++){
            cout << " ";
        }
        // numbers backward
        for(int j=i; j>0; j--){
            cout << j;
        } 
        // numbers forward
        for(int j=2; j<=i; j++){
        cout << j;
    } cout << endl;
    }
    
}

int main(){
    int n;
    cout << "Enter n: ";
    cin >> n;

    // basicPatternBox(n);
    // starPattern(n);
    // invertedStar(n);
    // halfPyramid(n);
    // halfPyramid2(n);
    // characterPyramid(n);
    // characterPyramid2(n);
    // hollowRect(n);
    // invertedRotatedHalfPyramid(n);
    // floydsTriangle(n);
    // diamondPattern(n);
    // butterflyPattern(n);
    // hollowDiamond(n);
    // squarePattern(n);
    // reverseTriangle(n);
    pyramid(n);

    // Assignment Que's:

    // zeroOneTriPatternODD(n);
    // zeroOneTriPatternEVEN(n);
    // rhombusPattern(n);
    // palindromicPattern(n);



    return 0;
}