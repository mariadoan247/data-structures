#include <iostream>
using namespace std;

// In this project, implement an AVL tree with one function
// -- AVL_Insert: insert a new node into AVL tree 
//
// In the main function, we will insert 10 nodes into AVL 
// Then, we will enumarate these nodes based on in-order traverse 
// The enumeration function has been implemented for you
// 
// Some functions are provided. You don't have to use them. 

class Node {

public:

    int SID = 0;

    Node* left = NULL;

    Node* right = NULL;

    Node* parent = NULL;

    int balanceFactor = 0;

    int height = -1;

};


class AVL {

public:

    Node* GetRoot(); // return root node pointer; not really used in testing 

    void AVL_Enumerate(); // enumerate nodes based on in-order traverse 

    void AVL_Insert(Node* x); // insert a new node x into AVL tree 

private:

    Node* root = NULL;
};


int depth(Node* ptr) { // measure depth of a node 

    int counter = 0;

    while (ptr->parent != NULL) {

        ptr = ptr->parent;

        counter++;
    }

    return counter;
}


void enumerate(Node* ptr) { // in-order traverse 

    if (ptr->left != NULL) {

        enumerate(ptr->left);

    }
    cout << ptr->SID << ' ';

    if (ptr->right != NULL) {

        enumerate(ptr->right);
    }
}


int isRoot(Node* ptr) { // check if node is root or not

    if (ptr->parent == NULL) {

        return 1;
    }
    else {

        return 0;
    }
}


int isLeaf(Node* ptr) { // check if node is leaf or not

    if (ptr->left == NULL && ptr->right == NULL) {

        return 1;
    }
    else {

        return 0;
    }
}


int height(Node* x) // Will find the height for the given Node x
{
    if (x == NULL) // If x is NULL then the height is 0
    {
        return 0;
    }

    if (isLeaf(x) == 1) // If x is a leaf then the height is 1
    {
        return 1;
    }
    else // else we will go through the height method recursively to find the 
    {    // height of the Node x
        int left = height(x->left);
        int right = height(x->right);
        if (left >= right)
        {
            return left + 1;
        }
        else
        {
            return right + 1;
        }
    }
}


Node* insert(Node* root, Node* x) { // insert a node to a tree with root

    if (root == NULL) {

        root = x;
    }
    else {

        if (x->SID <= root->SID) {

            root->left = insert(root->left, x);
            root->left->parent = root;
        }
        else {

            root->right = insert(root->right, x);
            root->right->parent = root;
        }
    }

    return root;
}


int findmax(Node* root) { // find max node from a tree with root 

    if (root->right == NULL) {

        return root->SID;
    }
    else {

        return findmax(root->right);
    }
}


Node* rotation_counterclock(Node* root) { // rotate tree at given root counter clockwise 

    Node* temp = root->right;

    if (root->right->left != NULL) {

        root->right = root->right->left;
    }

    temp->left = root;
    // Will change temp's parent to the parent of its parent if its parent equals its
    // left node's parent
    if (temp->parent == temp->left) temp->parent = temp->parent->parent;
    // Change temp's left node's parent to temp
    temp->left->parent = temp;
    // To prevent a looping tree this will be done to make sure the leaf node does not 
    // point back to its parent
    if (temp->left->right == temp) temp->left->right = NULL;

    root = temp;

    // These conditions will be done to insert the rebalanced subtree into the tree
    if (root->parent != NULL and root->SID < root->parent->SID) root->parent->left = root;
    else if (root->parent != NULL and root->SID > root->parent->SID) root->parent->right = root;

    return root;
}

Node* rotation_clock(Node* root) { // rotate tree at given root clockwise 

    Node* temp = root->left;

    if (root->left->right != NULL) {

        root->left = root->left->right;
    }

    temp->right = root;
    // Will change temp's parent to the parent of its parent if its parent equals its
    // right node's parent
    if (temp->parent == temp->right) temp->parent = temp->parent->parent;
    // Change temp's right node's parent to temp
    temp->right->parent = temp;
    // To prevent a looping tree this will be done to make sure the leaf node does not 
    // point back to its parent
    if (temp->right->left == temp) temp->right->left = NULL;

    root = temp;

    // These conditions will be done to insert the rebalanced subtree into the tree
    if (root->parent != NULL and root->SID < root->parent->SID) root->parent->left = root;
    else if (root->parent != NULL and root->SID > root->parent->SID) root->parent->right = root;

    return root;
}



// Gets the balance factor of the given Node x
int getBalance(Node* x) 
{
    if (x == NULL)
    {
        return 0;
    }
    return height(x->left) - height(x->right);
}

Node* AVL::GetRoot() // returns the root
{
    return root;
}


// Inserts the Node x into the tree according to AVL rules
void AVL::AVL_Insert(Node* x) 
{
    // We first start the AVL_Insert by doing a BST insert
    root = insert(root, x);

    // temp will be assigned to x, so x won't be directly altered.
    Node* temp = x;
    int balance = getBalance(temp);

    // This while loop will provide us with the lowest unbalanced node if 
    // it exists
    while (temp->parent != NULL and balance > -2 and balance < 2)
    {
        temp = temp->parent;
        balance = getBalance(temp);
    }

    // Left Left Case
    if (balance > 1 and x->SID < temp->left->SID)
    {
        temp = rotation_clock(temp);
    }

    // Right Right Case
    else if (balance < -1 and x->SID > temp->right->SID)
    {
        temp = rotation_counterclock(temp);
    }

    // Left Right Case
    else if (balance > 1 and x->SID > temp->left->SID)
    {
        temp->left = rotation_counterclock(temp->left);
        temp = rotation_clock(temp);
    }

    // Right Left Case
    else if (balance < -1 and x->SID < temp->right->SID)
    {
        temp->right = rotation_clock(temp->right);
        temp = rotation_counterclock(temp);
    }

    // If temp's parent is null then the root will be assigned to temp
    if (temp->parent == NULL) root = temp;
}

void AVL::AVL_Enumerate() {

    enumerate(root);
}


int main()
{
    Node tmp[10];

    for (int i = 0; i < 10; i++) {

        cin >> tmp[i].SID;
    }

    AVL x;

    for (int i = 0; i < 10; i++) {

        x.AVL_Insert(&tmp[i]);
    }

    int operationChoice;

    cin >> operationChoice;

    if (operationChoice == 1) { // enumerate key 

        x.AVL_Enumerate();
    }
    else {

        cout << "Enter a valid choice";
    }

    return 0;
}
