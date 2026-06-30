#include<iostream>
#include<vector>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data = data;
        left = right = nullptr; 
    }
};

Node* buildTree(vector<int> nodes){

}

int main() {
    // Preorder sequence:
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};

    return 0;
}