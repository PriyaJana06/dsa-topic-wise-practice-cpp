#include<iostream>
using namespace std;

// Basic structure of creating LL:
class Node {
    int data;
    Node* next;

public:
    Node(int val){
        data = val;
        next = nullptr;
    }
};

class List {
    Node* head;
    Node* tail;

public:
    List(){
        head = nullptr;
        tail = nullptr;
    }
};

int main(){
    

    return 0;
}