#include<iostream>
#include<cstring>
#include<string>
#include<cctype>   // Required for isalnum()
using namespace std;

// Practice Que:
// to UpperCase & LowerCase
void toUpperCase(char word[], int n){
    for(int i=0; i<n; i++){   // loop through each char
        char ch = word[i];  // store each char of char array in ch
        if(ch >= 'A' && ch <= 'Z'){    // (65 <= ch <=90)
            continue;     // already in uppercase
        } else {    // in lowercase
            word[i] = ch - 'a' + 'A';  // to convert char into UpperCase
        }
    }
    cout << word << endl;
}

void toLowerCase(char word[], int n){
    for(int i=0; i<n; i++){
        char ch = word[i];
        if(ch >= 'a' && ch <= 'z'){
            continue;
        } else {
            word[i] = ch - 'A' + 'a';    // to convert char into LowerCase
        } 
    }
    cout << word << endl;
}


// Reverse a char Array:
void reverseArray(char word[], int n){
    int start = 0, end = n-1;
    while(start<=end){
        swap(word[start++], word[end--]);
    }
    cout << "Reverse: " << word << endl;
}




int main() {
    // char ch1 = 'f';
    // char ch2 = 'A';
    // char ch3 = '$';
    // char ch4 = '5';
    // char ch5 = '\n';  // nextline character -> \n (single character)
    
    
    // to find position/idx of alphabet:

    // int pos = ch1 - 'a';
    // cout << (int)ch1 << endl;
    // cout << pos << endl;
    

    /*
    // C-Strings:

    char str[5] = {'a', 'b', 'c', 'd', 'e'};  // char array
    char str2[6] = {'h', 'e', 'l', 'l', 'o', '\0'};   // string
    
    cout << str[0] << str[1] << str[2] << str[3] << str[4] << endl;

    cout << str << endl;  // returns whole character array with extra trailing char.
    cout << str2 << endl;  // returns only string, as array contains null char. 
    */

    /*
    //Creation & Output:

    char work[] = "code";
    cout << work << endl;

    char work1[5] = "code";
    cout << work1 << endl;
    cout << strlen(work1) << endl;   // strlen(variable) gives length of string

    char str[] = {'h', 'e', 'l', 'l', 'o', '\0'};
    cout << str << endl;

    char str2[60] = {'h', 'e', 'l', 'l', 'o', '\0'};
    cout << str2 << endl;
    cout << strlen(str2) << endl;  // gives length of string

    // char str3[60] = {'h', 'e', 'l', 'l', 'o'};
    // cout << str3 << endl;   // stores garbage value 
    */


    // Input Char Arrays:

    // char word[10];
    // cout << "Enter string: ";
    // cin does not check the size of the array. It keeps writing characters in memory beyond the array boundary.
    // This is undefined behavior. Sometimes it works, sometimes it crashes, sometimes it corrupts memory.
    // cin >> word;    // stops at the first whitespace.


    // char sentence[20];
    // cout << "Enter string: ";
    // // cin.getline(sentence, 10);
    // cin.getline(sentence, 20, '*');
    // cout << "Your sentence was: " << sentence << endl;
    // cout << "Your letter was: " << sentence[0] << endl;
    // cout << "length: " << strlen(sentence) << endl;


    // Que: Convert to UpperCase & LowerCase
    // char word[] = "pRiYanKa";  // char array should be without whitespaces
    // toUpperCase(word, strlen(word));

    // char word1[] = "pRiYanKa";  // char array should be without whitespaces
    // toLowerCase(word1, strlen(word1));


    // Reverse an Array
    // char word[] = "code";
    // reverseArray(word, strlen(word));
    


    // CStrings Functions:
    // char str1[100] = "priyanka";
    // char str2[100] = "hello world";
    // str1 = "apna college";
    // copies string literals into char array
    // strcpy(str1, "apna college");  // copy string from src to destination(dst)
    // cout << str1 << endl; 

    // i) syntax: strcpy(dest, src)
    // strcpy(str1, str2);
    // cout << str1 << endl;


    //ii) strcat(str1, str2) -> concatenate 2 strings and store in dest
    // strcat(str1, str2);
    // cout << str1 << endl;

    //iii) strcmp(str1, str2) -> compares 2 strings based on values(-ve , 0, +ve)
    // char word1[50] = "strawberry";
    // char word2[50] = "abc";
    // cout << strcmp(word1, word2) << endl;


    // C++ strings:
    // string str = "hello";
    // cout << str << endl;
    // str = "priyanka";
    // cout << str << endl;

    // Input String:
    // string str1;
    // // cin >> str1;   // stops at whitespace
    // getline(cin, str1);   //can input with whitespaces
    // cout << str1 << endl;

    // string str2 = "Priyanka";
    // cout << str2[0] << endl;  // can also access elements at particular idx 



    // forEach loop:
    // string str = "apna college!";
    // for(int i=0; i<str.length(); i++){   // obj.length() -> dot operator
    //     cout << str[i] << " ";
    // } cout << endl;
    
    // //forEach loop
    // for(char ch : str){
    //     cout << ch << " ";
    // }


/*
    // String Member Functions:
    string str = "Priyanka";
    cout << str.length() << endl;   // lenght of str

    //ii) syntax: str.at(idx)
    cout << str.at(3) << endl;   // element at idx passed in parenthesis

    //iii) syntax: str.substr(startIdx, size of substring)
    cout << str.substr(1, 4) << endl;   // returns continuous part of a string(substring)

    //iv) syntax: str.find(word)  -> return unsigned value
    string str1 = "I love C++ & Java but I like to code in C++";
    cout << str1.length() << endl;  // 43
    cout << str1.find("C++") << endl;   // returns idx of first occurence
    
    int idx = str.find("Python");
    cout << idx << endl;    // returns garbage value i.e(-1), if word not found in str.

    // checks for second occurence after a certain starting idx is passed
    cout << str1.find("C++", 15) << endl;   // second occurence of C++ is at idx 40
*/


    return 0;
}