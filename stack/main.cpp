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

class Stack
{
private:
  Node *top;
  int height;

public:
  Stack(int value)
  {
    Node *newNode = new Node(value);
    top = newNode;
    height = 1;
  }

  void getTop()
  {
    cout << "Top: " << this->top->value << endl;
  }

  void getHeight()
  {
    cout << "Height: " << this->height << endl;
  }

  void printStack()
  {
    Node *current = top;
    while (current)
    {
      cout << current->value << endl;
      cout << "↓" << endl;
      current = current->next;
    }
  }

  void push(int value)
  {
    Node *newNode = new Node(value);
    newNode->next = top;
    top = newNode;
    height += 1;
  }

  int pop() {
    if (height == 0) {
      return INT_MIN;
    }
    Node *removedNode = top;
    int poppedValue = removedNode->value;
    top = top->next;
    delete removedNode;
    height -= 1;
    return poppedValue;
  }
};

int main()
{
  Stack *myStack = new Stack(10);
  myStack->getTop();
  myStack->getHeight();

  myStack->push(12);
  cout << endl
       << "Stack:" << endl;
  myStack->printStack();

  cout << "After Pop:" << endl;
  myStack->pop();
  myStack->printStack();
}