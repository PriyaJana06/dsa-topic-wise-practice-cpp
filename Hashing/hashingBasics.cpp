#include<iostream>
#include<vector>
#include<string>
using namespace std;

// Implementing Hash Table from scratch
class Node {
public:
    string key;
    int value;
    Node* next;

    Node(string key, int val){
        this->key = key;
        this->value = value;
        next = nullptr;
    }
};

class HashTable {
    int totSize;
    int currSize;  // for rehashing
    Node** table;

public:
    HashTable(int size){
        totSize = size;
        currSize = 0;
        table = new Node*[totSize];

        // Initializing each element as nullptr
        for(int i=0; i<totSize; i++){
            table[i] = nullptr;
        }
    }

    // Operations:
    void insert(string key, int val){

    }

    void erase(string key){

    }

    void search(string key){

    }
};

int main(){
    HashTable ht(6);


    return 0;
}