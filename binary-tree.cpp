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

int getSize(Node *root)
{
    if (root == nullptr)
    {
        return 0;
    }

    int leftSize = getSize(root->left);
    int rightSize = getSize(root->right);

    return leftSize + rightSize + 1;
}

int getAllSheets (Node *root)
{
    if (root == nullptr)
    {
        return 0;
    }

    if (root->left == nullptr && root->right == nullptr)
    {
        return 1;
    }

    int leftSheets = getAllSheets(root->left);
    int rightSheets = getAllSheets(root->right);

    return leftSheets + rightSheets;
}

Node *createRoot()
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
        cout << "Enter a value for the node" << i + 1 << " : ";
        cin >> value;
        push(value, root);
    }

    cout << "Tree in-order traversal: ";
    printTree(root);
    cout << endl;

    return root;
}

int main()
{
    Node *root = createRoot();
    int size = getSize(root);
    int sheets = getAllSheets(root);
    cout << "Size of the tree: " << size << endl;
    cout << "Number of sheets: " << sheets << endl;
    return 0;
}
