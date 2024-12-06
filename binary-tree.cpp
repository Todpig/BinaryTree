#include <iostream>
#include <random>
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

void printTree(Node *root, int level = 0)
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

void menu(Node *&root)
{
    int choice;
    do
    {
        cout << "\nMenu de opções:\n";
        cout << "1. Inserir um valor\n";
        cout << "2. Imprimir a árvore\n";
        cout << "3. Tamanho da árvore\n";
        cout << "4. Número de folhas\n";
        cout << "5. Buscar valor mínimo\n";
        cout << "6. Buscar valor máximo\n";
        cout << "7. Remover um valor\n";
        cout << "8. Gerar árvore com valores aleatórios\n";
        cout << "9. Enfileirar árvore\n";
        cout << "10. Altura da árvore\n";
        cout << "11. Travessia em ordem simétrica\n";
        cout << "12. Travessia em pré-ordem\n";
        cout << "13. Travessia em pós-ordem\n";
        cout << "0. Sair\n";
        cout << "Escolha uma opção: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            int value;
            cout << "Digite um valor para inserir: ";
            cin >> value;
            push(value, root);
            break;
        case 2:
            cout << "Árvore:\n";
            printTree(root);
            break;
        case 3:
            cout << "Tamanho da árvore: " << getSize(root) << endl;
            break;
        case 4:
            cout << "Número de folhas: " << getAllSheets(root) << endl;
            break;
        case 5:
            if (root != nullptr)
                cout << "Valor mínimo: " << searchMin(root)->value << endl;
            else
                cout << "Árvore vazia.\n";
            break;
        case 6:
            if (root != nullptr)
                cout << "Valor máximo: " << searchMax(root)->value << endl;
            else
                cout << "Árvore vazia.\n";
            break;
        case 7:
            cout << "Digite o valor para remover: ";
            cin >> value;
            root = remove(value, root);
            break;
        case 8:
        {
            random_device rd;
            mt19937 gen(rd());
            uniform_int_distribution<> sizeDist(5, 15);
            uniform_int_distribution<> valueDist(1, 100);

            int treeSize = sizeDist(gen);
            cout << "Gerando uma árvore com " << treeSize << " valores aleatórios...\n";

            for (int i = 0; i < treeSize; i++)
            {
                int randomValue = valueDist(gen);
                push(randomValue, root);
            }

            break;
        }
        case 9:
            cout << "Árvore: ";
            queueTree(root);
            break;
        case 10:
            cout << "Altura da árvore: " << treeHeight(root) << endl;
            break;
        case 11:
            cout << "Travessia em ordem simétrica: ";
            symmetricalOrder(root);
            cout << endl;
            break;
        case 12:
            cout << "Travessia em pré-ordem: ";
            preOrder(root);
            cout << endl;
            break;
        case 13:
            cout << "Travessia em pós-ordem: ";
            postOrder(root);
            cout << endl;
            break;
        case 0:
            cout << "Saindo...\n";
            break;
        default:
            cout << "Opção inválida. Tente novamente.\n";
            break;
        }
    } while (choice != 0);
}

int main()
{
    Node *root = nullptr;
    menu(root);
    return 0;
}
