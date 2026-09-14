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

// Que: Approach_1: Diameter of a Tree: TC = O(N^2)
int diam1(Node* root){
    if(root == nullptr) return 0;

    int currDiam = heightOfTree(root->left) + heightOfTree(root->right) + 1;  // O(N)
    int leftDiam = diam1(root->left);
    int rightDiam = diam1(root->right);

    return max(currDiam, max(leftDiam, rightDiam));
}

// Approach_2:
pair<int, int> diam2(Node* root){   // N nodes * O(1) = O(N)
    if(root == nullptr) return make_pair(0, 0);

    // pair(diameter, height)
    pair<int, int> leftInfo = diam2(root->left);  // LeftSubtreeDiam, LeftHeight
    pair<int, int> rightInfo = diam2(root->right);  // RightSubtreeDiam, RightHeight

    int currDiam = leftInfo.second + rightInfo.second + 1;
    int finalDiam = max(currDiam, max(leftInfo.first, rightInfo.first));
    int finalHt = max(leftInfo.second, rightInfo.second) + 1;

    return make_pair(finalDiam, finalHt);
}

// Que: Subtree of another Tree: TC = O(N * M)
bool isIdentical(Node* root1, Node* root2){
    // Base Case
    if(root1 == nullptr && root2 == nullptr){
        return true;
    } else if(root1 == nullptr || root2 == nullptr){
        return false;
    }

    if(root1->data != root2->data){
        return false;
    }

    return isIdentical(root1->left, root2->left) && 
            isIdentical(root1->right, root2->right);
}

bool isSubtree(Node* root, Node* subRoot){
    // Base Case
    if(root == nullptr && subRoot == nullptr){
        return true;
    }
    else if(root == nullptr || subRoot == nullptr){
        return false;
    }

    if(root->data == subRoot->data){
        // identical or not
        if(isIdentical(root, subRoot)){   // Edge Case
            return true;
        }
    }

    bool isLeftSubtree = isSubtree(root->left, subRoot);

    // if not found in leftSubtree, then search in rightSubtree.
    if(!isLeftSubtree){
        return isSubtree(root->right, subRoot);
    }

    return true;
}


int main(){
    // Que: Diameter of a Tree:
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    Node* root = buildTree(nodes);

    cout << "Diameter_1 of Tree: " << diam1(root) << endl;
    cout << "Diameter_2 of Tree: " << diam2(root).first << endl;

    // Que: Subtree of Another Tree:
    Node* subRoot = new Node(2);
    subRoot->left = new Node(4);
    subRoot->right = new Node(5);

    if(isSubtree(root, subRoot)){
        cout << "subRoot is a subtree of root." << endl;
    } else {
        cout << "subRoot is NOT a subtree of root." << endl;
    }

    return 0;
}