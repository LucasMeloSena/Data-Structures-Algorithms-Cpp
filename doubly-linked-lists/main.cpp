#include <iostream>

using namespace std;

class Node
{
public:
  int value;
  Node *next;
  Node *prev;

  Node(int value)
  {
    this->value = value;
    this->next = nullptr;
    this->prev = nullptr;
  }
};

class DoublyLinkedList
{
private:
  Node *head;
  Node *tail;
  int length;

public:
  DoublyLinkedList() {
    this->head = nullptr;
    length = 0;
  }

  DoublyLinkedList(int value)
  {
    Node *newNode = new Node(value);
    this->head = newNode;
    this->tail = newNode;
    this->length = 1;
  }

  void printList()
  {
    Node *temp = head;
    while (temp != nullptr)
    {
      if (temp->next)
      {
        cout << temp->value << " <-> ";
      }
      else
      {
        cout << temp->value << " -> " << endl;
      }
      temp = temp->next;
    }
  }

  void getHead()
  {
    cout << "\nHead: " << head->value << endl;
  }

  void getTail()
  {
    cout << "Tail: " << tail->value << endl;
  }

  void getLength()
  {
    cout << "Length: " << length << endl;
  }

  void append(int value)
  {
    Node *newNode = new Node(value);
    if (length == 0)
    {
      head = newNode;
      tail = newNode;
    }
    else
    {
      tail->next = newNode;
      newNode->prev = tail;
      tail = newNode;
    }
    length += 1;
  }

  void deleteLast()
  {
    if (length == 0)
      return;
    Node *temp = tail;
    if (length == 1)
    {
      head = nullptr;
      tail = nullptr;
    }
    else
    {
      tail = tail->prev;
      tail->next = nullptr;
    }
    delete temp;
    length -= 1;
  }

  void prepend(int value)
  {
    Node *newNode = new Node(value);
    if (length == 0)
    {
      head = newNode;
      tail = newNode;
    }
    else
    {
      newNode->next = head;
      head->prev = newNode;
      head = newNode;
    }
    length += 1;
  }

  void deleteFirst()
  {
    Node *temp = head;
    if (length == 0)
      return;
    if (length == 1)
    {
      head = nullptr;
      tail = nullptr;
    }
    else
    {
      head = head->next;
      head->prev = nullptr;
    }
    delete temp;
    length -= 1;
  }

  Node *get(int index)
  {
    if (index < 0 || index >= length)
    {
      return nullptr;
    }

    Node *temp = head;
    if (index < length / 2)
    {
      for (int i = 0; i < index; i++)
      {
        temp = temp->next;
      }
    }
    else
    {
      temp = tail;
      for (int i = length - 1; i > index; i--)
      {
        temp = temp->prev;
      }
    }
    return temp;
  }

  bool set(int index, int value)
  {
    Node *node = get(index);
    if (node)
    {
      node->value = value;
      return true;
    }
    return false;
  }

  bool insert(int index, int value)
  {
    if (index < 0 || index > length)
      return false;
    Node *newNode = new Node(value);
    if (length == 0)
    {
      head = newNode;
      tail = newNode;
      length += 1;
      return true;
    }
    if (index == 0)
    {
      prepend(value);
      return true;
    }
    if (index == length)
    {
      append(value);
      return true;
    }
    Node *before = get(index - 1);
    Node *after = before->next;
    if (before)
    {
      before->next = newNode;
      newNode->prev = before;
      newNode->next = after;
      after->prev = newNode;
      length += 1;
      return true;
    }
    return false;
  }

  void deleteNode(int index)
  {
    Node *node = get(index);
    if (index == 0)
    {
      deleteFirst();
      return;
    }
    if (index == length - 1)
    {
      deleteLast();
      return;
    }

    if (node)
    {
      node->prev->next = node->next;
      node->next->prev = node->prev;

      delete node;
      length -= 1;
      return;
    }
    return;
  }

  bool checkPalindrome()
  {
    Node *forward = head;
    Node *backward = tail;

    if (length == 1) {
      return true;
    }

    for (int i = 0; i < length / 2; i++)
    {
      if (forward->value == backward->value)
      {
        forward = forward->next;
        backward = backward->prev;
        continue;
      }
      else
      {
        return false;
      }
    }

    return true;
  }

  void reverse() {
    if (head == nullptr || length <= 1) {
      return;
    }

    Node *dummy = head;
    Node *current = head;
    Node *temp = nullptr;

    while (current) {
      current->prev = current->next;
      current->next = temp;
      temp = current;
      current = current->prev;
    }

    head = temp;
    tail = dummy;
  }

  void partitionList(int val) {
    DoublyLinkedList *d1 = new DoublyLinkedList();
    DoublyLinkedList *d2 = new DoublyLinkedList();
    Node *curr = head;

    while (curr) {
      if (curr->value < val) {
        d1->append(curr->value);
      }
      else
      {
        d2->append(curr->value);
      }
      curr = curr->next;
    }

    if (d1->head && d2->head) {
      d1->tail->next = d2->head;
      d2->head->prev = d1->tail;
      head = d1->head;
      tail = d2->tail;
    }
    else if (d1->head)
    {
      head = d1->head;
      tail = d2->tail;
    }
    else if (d2->head)
    {
      head = d2->head;
      tail = d2->tail;
    } else {
      head = nullptr;
      tail = nullptr;
    }
  }

  void reverseBetween(int startIndex, int endIndex) {
    Node *dummy = head;
    Node *first = get(startIndex);
    Node *last = get(endIndex);
    Node *prev = first->prev;
    Node *next = last->next;

    prev->next = first->next;
    first->next = first;
    first->next = next;
  }
};

int main()
{
  DoublyLinkedList *myDll = new DoublyLinkedList(0);
  myDll->append(7);
  myDll->prepend(-1);

  cout << "Initial state: ";
  myDll->printList();

  cout << "After delete last: ";
  myDll->deleteLast();
  myDll->printList();

  cout << "After delete first: ";
  myDll->deleteFirst();
  myDll->printList();

  myDll->set(0, 10);
  cout << "Get at index 0: " << myDll->get(0)->value << endl;

  cout << "After inserts: ";
  myDll->insert(1, 12);
  myDll->insert(1, 24);
  myDll->printList();

  cout << "After delete node at index 2: ";
  myDll->deleteNode(2);
  myDll->printList();

  DoublyLinkedList *myPalindromeDll = new DoublyLinkedList(0);
  myPalindromeDll->append(1);
  myPalindromeDll->append(1);
  myPalindromeDll->append(0);
  bool isPalindrome = myPalindromeDll->checkPalindrome();
  if (isPalindrome)
    cout << "Is Palindrome!!" << endl;
  else
    cout << "Isn't Palindrome!!" << endl;

  cout << "Reversed Doubly Linked List: ";
  myDll->reverse();
  myDll->printList();

  myDll->append(9);
  cout << "Partition List: ";
  myDll->partitionList(12);
  myDll->printList();
}