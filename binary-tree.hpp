#ifndef BINARY_TREE_HPP
#define BINARY_TREE_HPP

#include <iostream>
using namespace std;

struct Node
{
    int value;
    Node *left;
    Node *right;
};

bool isEmpty(Node *root);
void printLevel(Node *root, int level);
void visit(Node *root);
void symmetricalOrder(Node *root);
void preOrder(Node *root);
void postOrder(Node *root);
int treeHeight(Node *root);
void queueTree(Node *root);
Node *search(int value, Node *root);
void push(int value, Node *&root);
void printTree(Node *root, int level = 0);
int getSize(Node *root);
int getAllSheets(Node *root);
Node *searchMin(Node *root);
Node *searchMax(Node *root);
Node *remove(int value, Node *root);

#endif
