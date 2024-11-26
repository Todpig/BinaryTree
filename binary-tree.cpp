#include <iostream>
using namespace std;

struct Node
{
    int value;
    Node *left;
    Node *right;
};

bool isEmpty(Node *root)
{
    return (root == nullptr);
}

Node *search(int value, Node *root)
{
    Node *current = root;
    Node *parent = nullptr;

    while (current != nullptr)
    {
        parent = current;

        if (value == current->value)
        {
            cout << "Value " << value << " already exists in the tree.\n";
            return nullptr;
        }

        if (value > current->value)
        {
            current = current->right;
        }
        else
        {
            current = current->left;
        }
    }

    return parent;
}

void push(int value, Node *&root)
{
    if (isEmpty(root))
    {
        root = new Node();
        root->value = value;
        root->left = nullptr;
        root->right = nullptr;
        return;
    }

    Node *parentNode = search(value, root);

    if (parentNode != nullptr)
    {
        Node *newNode = new Node();
        newNode->value = value;
        newNode->left = nullptr;
        newNode->right = nullptr;

        if (value > parentNode->value)
        {
            parentNode->right = newNode;
        }
        else
        {
            parentNode->left = newNode;
        }
    }
}

void printTree(Node *root)
{
    if (root != nullptr)
    {
        printTree(root->right);
        cout << root->value << " ";
        printTree(root->left);
    }
}

void createRoot()
{
    Node *root = nullptr;
    int rootValue, count;

    cout << "Enter the value for the root node: ";
    cin >> rootValue;
    push(rootValue, root);

    cout << "Enter the number of nodes to add: ";
    cin >> count;

    for (int i = 0; i < count; i++)
    {
        int value;
        cout << "Enter a value for the node: ";
        cin >> value;
        push(value, root);
    }

    cout << "Tree in-order traversal: ";
    printTree(root);
    cout << endl;
}

int main()
{
    createRoot();
    return 0;
}
