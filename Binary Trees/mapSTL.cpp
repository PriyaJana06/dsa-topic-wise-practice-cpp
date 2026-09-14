#include<iostream>
#include<map>
#include<string>
using namespace std;

int main() {
    map<int, string> m;

    m[101] = "Rahul";
    m[110] = "Neha";
    m[131] = "Rahul";
    m[101] = "Rajat";

    cout << m[101] << endl;
    cout << m.count(101) << endl;  // check if key is present or not
    cout << m.count(120) << endl;

    // loop on map:
    for(auto itr : m){
        cout << itr.first << " : " << itr.second << endl;
    } cout << endl;

    // manipulation on key:value pair:
    for(auto itr : m){
        cout << "Double: " << itr.first * 2 << endl;
    }

    return 0;
}