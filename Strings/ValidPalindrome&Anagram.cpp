#include<iostream>
#include<cstring>
#include<string>
using namespace std;

// Valid Palindrome:  for lowercase only
bool validPalindrome(char str[], int n){   // TC => O(N)
    int start = 0, end = n-1;

    while(start < end){
        if(str[start] != str[end]){
            cout << "Not Valid Palindrome\n";
            return false;
        }
        start++; end--;
    }
    cout << "Valid Palindrome\n";
    return true;
}
 
// Valid Anagram:
bool isAnagram(string s, string t) {
        if(s.length() != t.length()) {   // length of both strings should be equal
            cout << "NOT VALID Anagram" << endl;
            return false;
        }

        int count[26] = {0};
        for(int i=0; i<s.length(); i++){   // traverse 1st string
            count[s[i] - 'a']++;    // count[idx]++
        }

        for(int i=0; i<t.length(); i++){   // traverse 2nd string
            if(count[t[i] - 'a'] == 0){  // not valid anagram
                cout << "NOT VALID Anagram" << endl;
                return false;    
            }
            count[t[i] - 'a']--;    // count[idx]--
        }
        cout << "VALID Anagram" << endl;
        return true;
    }

int main(){

    // Valid Palindrome
    char palindrome[] = "racecar";
    validPalindrome(palindrome, strlen(palindrome));


    // Valid Anagram :
    string str1 = "anagram";
    string str2 = "nagaram";
    isAnagram(str1, str2);

    return 0;
}