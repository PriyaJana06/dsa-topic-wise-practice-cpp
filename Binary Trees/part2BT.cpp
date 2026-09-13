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

// Build Tree:
static int idx = -1;
Node* buildTree(vector<int> nodes){
    idx++;
    if(nodes[idx] == -1){
        return nullptr;
    }

    Node* currNode = new Node(nodes[idx]);
    currNode->left = buildTree(nodes);
    currNode->right = buildTree(nodes);

    return currNode;
}

// Height of a Tree:
int heightOfTree(Node* root){
    if(root == nullptr) return 0;

    int leftHt = heightOfTree(root->left);
    int rightHt = heightOfTree(root->right);

    int currHt = max(leftHt, rightHt) + 1;
    
    return currHt;
}

// Que: Diameter of a Tree:
int diam1(Node* root){
    if(root == nullptr) return 0;

    int currDiam = heightOfTree(root->left) + heightOfTree(root->right) + 1;
    int leftDiam = diam1(root->left);
    int rightDiam = diam1(root->right);

    return max(currDiam, max(leftDiam, rightDiam));
}

int main(){
    // Que: Diameter of a Tree:
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    Node* root = buildTree(nodes);

    cout << "Diameter of Tree: " << diam1(root) << endl;

    return 0;
}