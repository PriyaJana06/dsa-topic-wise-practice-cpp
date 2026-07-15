#include<iostream>
#include<vector>
#include<queue>
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

// Build Tree from Preorder:
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

// Preorder traversal:  TC = O(n)
void preorder(Node* root){
    if(root == nullptr) return;

    cout << root->data << " ";   // root
    preorder(root->left);    // left subtree
    preorder(root->right);   // right subtree
}

// Inorder traversal:  TC = O(n)
void inorder(Node* root){
    if(root == nullptr) return;

    inorder(root->left); // left subtree
    cout << root->data << " ";   // root
    inorder(root->right);  // right subtree
}

// Postorder traversal:  TC = O(n)
void postorder(Node* root){
    if(root == nullptr) return;

    postorder(root->left); // left subtree
    postorder(root->right);  // right subtree
    cout << root->data << " ";   // root
}

// Level Order traversal:  TC = O(n)  SC = O(n)
void levelOrder(Node* root){
    if(root == nullptr) return; 

    queue<Node*> Q;
    Q.push(root);

    while(!Q.empty()){
        Node* currNode = Q.front();
        Q.pop();
        cout << currNode->data << " ";
         
        if(currNode->left != nullptr){
            Q.push(currNode->left);
        }

        if(currNode->right != nullptr){
            Q.push(currNode->right);
        }
    }
}

// Variation:  TC = O(N)
void levelOrderPrint(Node* root){
    if(root == nullptr) return; 

    queue<Node*> Q;
    Q.push(root);
    Q.push(nullptr);

    while(!Q.empty()){
        Node* currNode = Q.front();
        Q.pop();

        if(currNode == nullptr){
            cout << "\n";
            if(Q.empty()) break;
            Q.push(nullptr);   // to track nextline
        } else {
            cout << currNode->data << " ";
            
            if(currNode->left != nullptr){
                Q.push(currNode->left);
            }

            if(currNode->right != nullptr){
                Q.push(currNode->right);
            }
        }
    }
}

// Height of a Tree:
int heightOfTree(Node* root){
    if(root == nullptr) return 0;

    int leftHt = heightOfTree(root->left);
    int rightHt = heightOfTree(root->right);

    int currHt = max(leftHt, rightHt) + 1;
    
    return currHt;
}

// Count of Nodes: 
int countNodes(Node* root){
    if(root == nullptr) return 0;

    int leftCount = countNodes(root->left);
    int rightCount = countNodes(root->right);

    return leftCount + rightCount + 1;
}

// Sum of Nodes in a Tree:
int sumOfNodes(Node* root){
    if(root == nullptr) return 0;

    int leftSum = sumOfNodes(root->left);
    int rightSum = sumOfNodes(root->right);

    int currSum = leftSum + rightSum + root->data;
    cout << "Sum: " << currSum << "\n"; 

    return currSum;
}

int main() {
    // Preorder sequence:
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};

    Node* root = buildTree(nodes);
    cout << "root = " << root->data << endl;


    // Preorder traversal:
    cout << "Preorder traversal: ";
    preorder(root); cout << endl;

    // Inorder Traversal:
    cout << "Inorder traversal: "; 
    inorder(root); cout << endl;

    // Postorder traversal:
    cout << "Preorder traversal: ";
    postorder(root); cout << endl;

    // Level Order traversal:
    cout << "LevelOrder traversal: ";
    levelOrder(root); cout << endl;
    // Variation:
    levelOrderPrint(root); 

    // Height of A tree:
    cout << "Height of tree: " << heightOfTree(root) << endl;

    // Count of Nodes:
    cout << "No. of nodes in Tree: " << countNodes(root) << endl;

    Node* root2 = new Node(5);
    root2->left = new Node(3);
    root2->right = new Node(4);
    cout << "No. of nodes in Tree: " << countNodes(root2) << endl;

    // Sum of Nodes in a Tree:
    cout << "Sum of Nodes of Tree: " << sumOfNodes(root) << endl;

    return 0;
}