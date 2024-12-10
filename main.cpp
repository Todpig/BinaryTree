#include "binary-tree.hpp"
#include <random>

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
        cout << "14. Travessia em nivel\n";
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
        case 14:
            cout << "Travessia em nível: ";
            levelOrder(root);
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