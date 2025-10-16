#include <iostream>
using namespace std;

class Node
{
public:
  int value;
  Node *next;

  Node(int value)
  {
    this->value = value;
    this->next = nullptr;
  }
};

class Queue
{
private:
  Node *first;
  Node *last;
  int length;

public:
  Queue(int value)
  {
    Node *newNode = new Node(value);
    first = newNode;
    last = newNode;
    length = 1;
  }

  void print()
  {
    Node *current = first;
    while (current)
    {
      cout << current->value << " -> ";
      current = current->next;
    }
  }

  void enqueue(int value)
  {
    Node *newNode = new Node(value);
    if (length == 0)
    {
      first = newNode;
      last = newNode;
    }
    else
    {
      last->next = newNode;
      last = newNode;
    }
    length += 1;
  }

  int dequeue()
  {
    if (length == 0)
    {
      return INT_MIN;
    }
    Node *poppedNode = first;
    int poppedValue = poppedNode->value;
    if (length == 1)
    {
      first = nullptr;
      last = nullptr;
    }
    else
    {
      first = first->next;
    }
    delete poppedNode;
    length -= 1;
    return poppedValue;
  }
};

int main()
{
  Queue *myQueue = new Queue(24);
  
  cout << "Enqueue executed: ";
  myQueue->enqueue(12);
  myQueue->enqueue(6);
  myQueue->print();

  cout << endl << "Dequeue executed: ";
  myQueue->dequeue();
  myQueue->print();
}