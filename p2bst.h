#include <cstddef>

template <typename T>
struct Node {
    T data;         // Data held at this node in tree
    Node<T>* left;  // Pointer to left child
    Node<T>* right; // Pointer to right child
};

template <typename T>
struct Tree {
    Node<T>* root; // Pointer to topmost (root) node
};

template <typename T>
void initialize(Tree<T>& t)
{
    t.root = NULL;
}

// This is the recursive destroy function, accepting a Node* argument.
template <typename T>
void destroy(Node<T>* n)
{
    if (n == NULL)
        return;

    destroy(n->left);  // Recursively destroy left subtree
    destroy(n->right); // Recursively destroy right subtree
    delete n;          // Delete this node
}

// This is the function called by the user, to destroy a Tree.
// It will call the recursive function, beginning with the root node.
template <typename T>
void destroy(Tree<T>& t)
{
    destroy(t.root);
    t.root = NULL;
}

template <typename T>
void insert(Tree<T>& t, T value)
{
    // Create new node to add to the tree
    Node<T>* newNode = new Node<T>;
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    if (t.root == NULL) { // empty tree
        t.root = newNode;
        return;
    }

    Node<T>* walker = t.root;
    while (true)
    {
        if (value < walker->data)
        {
            if (walker->left == NULL)
            {
                walker->left = newNode;
                return;
            }
            else
                walker = walker->left;
        }
        else // value >= walker->data
        {
            if (walker->right == NULL)
            {
                walker->right = newNode;
                return;
            }
            else
                walker = walker->right;
        }
    }
}

// Return depth (level) at which value appears
//    or 0 if value is not in tree
template <typename T>
int contains(Tree<T>& t, T value)
{
    Node<T>* walker = t.root;
    int depth = 1;
    while (walker != NULL)
    {
        if (walker->data == value)
            return depth;
        else if (value < walker->data)
            walker = walker->left;
        else // value >= walker->data
            walker = walker->right;
        depth++;
    }
    return 0;
}

// implement these functions
template <typename T>
int  countNodes(Node<T>*&n) {

    if (n == NULL)
        return 0;

    return 1 + countNodes(n->left) + countNodes(n->right);
}
template <typename T>
int  countNodes(Tree<T>& t) {

    if (t.root == NULL) 
        return 0;

    return countNodes(t.root);
}
template <typename T>
int  height(Node<T>*&n) {

    if (n == NULL)
        return 0;

    else if (height(n->left) > height(n->right)) 
        return 1 + height(n->left);
    else
        return 1 + height(n->right);
}
template <typename T>
int  height(Tree<T>& t) {

    if (t.root == NULL)
        return 0;

    return height(t.root);
}
template <typename T>
int  countLeaf(Node<T>* n) {

    if (n == NULL)
        return 0;
    else if (n->left == NULL && n->right == NULL)
        return 1;
    else
        return countLeaf(n->left) + countLeaf(n->right);
}
template <typename T>
int  countLeaf(Tree<T> t) {

    if (t.root == NULL) 
        return 0;
    
    return countLeaf(t.root);
}
template <typename T>
int  countDouble(Node<T>* n) {

    if (n == NULL)
        return 0;
    else if (n->left != NULL && n->right != NULL)
        return 1 + countDouble(n->left) + countDouble(n->right);
    else
        return countDouble(n->left) + countDouble(n->right);
}
template <typename T>
int  countDouble(Tree<T> t) {

    if (t.root == NULL)
        return 0;

    return countDouble(t.root);
}
template <typename T>
T    kthValue(Node<T>* n, int k) {

    if (k == (countNodes(n->left) + 1))
        return n->data;
    else if (k > (countNodes(n->left) + 1))
        return kthValue(n->right, k - (countNodes(n->left) + 1));
    else
        return kthValue(n->left, k);
}
template <typename T>
T    kthValue(Tree<T> t, int k) {

    return kthValue(t.root, k);
}
