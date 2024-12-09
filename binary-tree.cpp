#include <iostream>
#include <random>
#include "binary-tree.hpp"
using namespace std;

bool isEmpty(Node *root)
{
    return (root == nullptr);
}

void printLevel(Node *root, int level)
{
    if (root == nullptr)
        return;

    if (level == 1)
    {
        cout << root->value << "-";
    }
    else if (level > 1)
    {
        printLevel(root->left, level - 1);
        printLevel(root->right, level - 1);
    }
}

void visit(Node *root)
{
    cout << root->value << " ";
}

void symmetricalOrder(Node *root)
{
    if (root->left != nullptr)
        symmetricalOrder(root->left);
    visit(root);
    if (root->right != nullptr)
        symmetricalOrder(root->right);
}

void preOrder(Node *root)
{
    visit(root);
    if (root->left != nullptr)
        preOrder(root->left);
    if (root->right != nullptr)
        preOrder(root->right);
}

void postOrder(Node *root)
{
    if (root->left != nullptr)
        postOrder(root->left);
    if (root->right != nullptr)
        postOrder(root->right);
    visit(root);
}

int treeHeight(Node *root)
{
    if (root == nullptr)
        return 0;

    int leftHeight = treeHeight(root->left);
    int rightHeight = treeHeight(root->right);

    return max(leftHeight, rightHeight) + 1;
}

void queueTree(Node *root)
{
    int height = treeHeight(root);

    for (int i = 1; i <= height; i++)
    {
        printLevel(root, i);
    }
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

void printTree(Node *root, int level)
{
    if (root != nullptr)
    {
        for (int i = 0; i < level; i++)
        {
            cout << "-";
        }
        cout << root->value << endl;
        printTree(root->left, level + 1);
        printTree(root->right, level + 1);
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

int getAllSheets(Node *root)
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

Node *searchMin(Node *root)
{
    if (root == nullptr)
        return nullptr;

    if (root->left == nullptr)
        return root;

    return searchMin(root->left);
}

Node *searchMax(Node *root)
{
    if (root == nullptr)
        return nullptr;

    if (root->right == nullptr)
        return root;

    return searchMax(root->right);
}

Node *remove(int value, Node *root)
{
    if (root == nullptr)
    {
        cout << "Value not found in the tree.\n";
        return nullptr;
    }

    if (value < root->value)
    {
        root->left = remove(value, root->left);
    }
    else if (value > root->value)
    {
        root->right = remove(value, root->right);
    }
    else
    {
        if (root->left == nullptr && root->right == nullptr)
        {
            delete root;
            return nullptr;
        }

        else if (root->left == nullptr)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        else
        {
            Node *minNode = searchMin(root->right);
            root->value = minNode->value;
            root->right = remove(minNode->value, root->right);
        }
    }
    return root;
}
