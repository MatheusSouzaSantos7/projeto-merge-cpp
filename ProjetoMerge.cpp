#include <iostream>
#include <locale.h>
using namespace std;

// Estrutura para um nó da lista encadeada
struct Node {
    int valor;
    Node* proximo;
};

// Estrutura para a pilha implementada como lista encadeada
struct PilhaLista {
    Node* topo;
    int qtde;
    int capacidade;

    PilhaLista(int capacidade) {
        topo = nullptr;
        qtde = 0;
        this->capacidade = capacidade;
    }
};

// Função para inicializar a pilha implementada como lista encadeada
PilhaLista* initLista(int capacidade) {
    PilhaLista* p = new PilhaLista(capacidade);
    return p;
}

// Função para verificar se a pilha implementada como lista encadeada está vazia
bool isEmptyLista(PilhaLista* p) {
    return (p->topo == nullptr);
}

// Função para contar o número de elementos na pilha implementada como lista encadeada
int countLista(PilhaLista* p) {
    return (p->qtde);
}

// Função para liberar a memória alocada para a pilha implementada como lista encadeada
void freePilhaLista(PilhaLista* p) {
    while (!isEmptyLista(p)) {
        Node* temp = p->topo;
        p->topo = p->topo->proximo;
        delete temp;
    }
    delete p;
}

// Função para empilhar um valor na pilha implementada como lista encadeada
void pushLista(PilhaLista* p, int v) {
    if (p->qtde < p->capacidade) {
        Node* novo = new Node;
        novo->valor = v;
        novo->proximo = p->topo;
        p->topo = novo;
        p->qtde++;
    } else {
        cout << "A pilha atingiu a capacidade máxima!" << endl;
    }
}

// Função para desempilhar um valor da pilha implementada como lista encadeada
int popLista(PilhaLista* p) {
    if (isEmptyLista(p))
        return -1;

    Node* temp = p->topo;
    int v = temp->valor;
    p->topo = p->topo->proximo;
    delete temp;
    p->qtde--;
    return v;
}

// Função para verificar se o valor a ser inserido na pilha é maior que o valor no topo
bool eMaiorLista(PilhaLista* p, int v) {
    if (isEmptyLista(p))
        return true;

    return p->topo->valor < v;
}

// Função para imprimir os elementos da pilha implementada como lista encadeada
void printLista(PilhaLista* p) {
    cout << "Qtde de elementos: " << countLista(p) << endl;
    Node* temp = p->topo;
    while (temp != nullptr) {
        cout << temp->valor << endl;
        temp = temp->proximo;
    }
    cout << "--------------------" << endl;
}

int main() {
    setlocale(LC_ALL, "");
    int capacidadeMaxima = 10;
    PilhaLista* pilhaPar = initLista(capacidadeMaxima);
    PilhaLista* pilhaImpar = initLista(capacidadeMaxima);

    int valor;
    int contPar = 0, contImpar = 0;

    while (contPar + contImpar < capacidadeMaxima) {
        cout << "Digite um valor: ";
        cin >> valor;

        if ((valor % 2 == 0 && eMaiorLista(pilhaPar, valor)) ||
            (valor % 2 != 0 && eMaiorLista(pilhaImpar, valor))) {
            if (valor % 2 == 0) {
                pushLista(pilhaPar, valor);
                contPar++;
            } else {
                pushLista(pilhaImpar, valor);
                contImpar++;
            }
        } else {
            cout << "O valor deve ser maior que o anterior!" << endl;
        }
    }

    cout << "Pilha de números pares:" << endl;
    printLista(pilhaPar);

    cout << "Pilha de números ímpares:" << endl;
    printLista(pilhaImpar);

    freePilhaLista(pilhaPar);
    freePilhaLista(pilhaImpar);

    return 0;
}