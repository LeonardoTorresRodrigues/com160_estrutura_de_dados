#include <cstddef> // Para NULL.
#include <new>     // Para bad_alloc.
#include "queue.h"
#include <iostream>
using namespace std;

/* Inicializando os ponteiros como NULL no construtor */
Queue::Queue()
{
    front = NULL;
    rear = NULL;
}

Queue::~Queue()
{
    NodeType *tempPtr;
    while (front != NULL)
    {
        tempPtr = front;     // tempPtr aponta para o front antes do elemento ser apagado.
        front = front->next; // front aponta para o próximo elemento enquanto tempPtr fica como referência para a memória que será desalocada.
        delete tempPtr;      // a memória é desalocada usando o tempPtr como o ponteiro "atual".
    }
    rear = NULL;
}

/* Verificando se existe espaço livre em memória para alocar um novo elemento */
bool Queue::isFull() const
{
    NodeType *location;
    try
    {
        location = new NodeType;
        delete location;
        return false;
    }
    catch (std::bad_alloc exception)
    {
        return true;
    }
}

bool Queue::isEmpty() const
{
    return (front == NULL);
}

void Queue::enqueue(ItemType newItem)
{
    if (!isFull())
    {
        NodeType *newNode;
        newNode = new NodeType;
        newNode->info = newItem;
        newNode->next = NULL; // O último nó da fila sempre aponta para Nulo.
        if (rear == NULL)
            front = newNode;
        else
            rear->next = newNode; // O ponteiro do rear sempre vai apontar para o último nó.
        rear = newNode;
    }
    else
    {
        throw "Queue is already full!";
    }
}

/* Antes de desalocar, o front já deve estar no próximo nó, por isso é usado o tempPtr para "marcar" o nó atual. */
ItemType Queue::dequeue()
{
    if (!isEmpty())
    {
        NodeType *tempPtr;
        tempPtr = front;
        ItemType item = front->info;
        front = front->next;
        if (front == NULL)
            rear = NULL;
        delete tempPtr;
        return item;
    }
    else
    {
        throw "Queue is empty!";
    }
}

/* Imprimindo a lista na saída padrão. */
void Queue::print() const
{
    NodeType *tempPtr = front;
    while (tempPtr != NULL)
    {
        cout << tempPtr->info;
        tempPtr = tempPtr->next;
    }
    cout << endl;
}
