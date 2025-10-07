#include <iostream>
#include <unordered_set>

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

class LinkedList
{
private:
  Node *head;
  Node *tail;
  int length;

public:
  LinkedList(int value)
  {
    Node *newNode = new Node(value);
    head = newNode;
    tail = newNode;
    length = 1;
  }

  ~LinkedList()
  {
    Node *temp = head;
    while (head != nullptr)
    {
      head = head->next;
      delete temp;
      temp = head;
    }
  }

  void printList()
  {
    Node *temp = head;
    while (temp != nullptr)
    {
      cout << temp->value << " -> ";
      temp = temp->next;
    }
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
      tail = newNode;
    }
    length++;
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
      head = newNode;
    }
    length++;
  }

  void deleteLastNode()
  {
    if (length == 0)
    {
      return;
    }
    else if (length == 1)
    {
      head = nullptr;
      tail = nullptr;
      length = 0;
    }
    else
    {
      Node *temp = head;
      while (temp->next != tail)
      {
        temp = temp->next;
      }
      delete tail;
      tail = temp;
      tail->next = nullptr;
      length--;
    }
  }

  void deleteFirst()
  {
    if (length == 0)
    {
      return;
    }
    else if (length == 1)
    {
      head = nullptr;
      tail = nullptr;
    }
    else
    {
      head = head->next;
    }
    length--;
  }

  Node *get(int index)
  {
    if (length == 0 || index < 0 || index >= length)
    {
      return nullptr;
    }

    Node *temp = head;
    for (int i = 0; i < index; i++)
    {
      temp = temp->next;
    }
    return temp;
  }

  bool set(int index, int value)
  {
    Node *temp = get(index);
    if (temp == nullptr)
    {
      return false;
    }
    else
    {
      temp->value = value;
      return true;
    }
  }

  bool insert(int index, int value)
  {
    if (index < 0 || index > length)
    {
      return false;
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

    Node *temp = get(index - 1);
    Node *newNode = new Node(value);
    newNode->next = temp->next;
    temp->next = newNode;
    length++;
    return true;
  }

  void deleteAtIndex(int index)
  {
    if (index < 0 || index >= length)
    {
      return;
    }
    if (index == 0)
    {
      return deleteFirst();
    }
    if (index == length - 1)
    {
      return deleteLastNode();
    }

    Node *previous = get(index - 1);
    Node *temp = previous->next;
    previous->next = temp->next;
    delete temp;
    length--;
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

  void reverse()
  {
    // invert head and tail position
    Node *temp = head;
    head = tail;
    tail = temp;

    Node *after = temp->next;
    Node *before = nullptr;

    for (int i = 0; i < length; i++)
    {
      after = temp->next;
      temp->next = before;
      before = temp;
      temp = after;
    }
  }

  Node *middle()
  {
    Node *fast = head;
    Node *slow = head;

    while (fast != nullptr && fast->next != nullptr)
    {
      fast = fast->next->next;
      slow = slow->next;
    }

    return slow;
  }

  bool hasLoop()
  {
    Node *fast = head;
    Node *slow = head;

    while (fast != nullptr && fast->next != nullptr)
    {
      fast = fast->next->next;
      slow = slow->next;

      if (fast != nullptr && fast->value == slow->value)
      {
        return true;
      }
    }
    return false;
  }

  Node *findKthFromEnd(int k)
  {
    Node *fast = head;
    Node *slow = head;

    for (int i = 0; i < k; i++)
    {
      if (fast == nullptr)
      {
        return nullptr;
      }
      fast = fast->next;
    }

    while (fast != nullptr)
    {
      slow = slow->next;
      fast = fast->next;
    }

    return slow;
  }

  void removeDuplicates()
  {
    if (!head)
      return;

    unordered_set<int> seen;
    Node *current = head;
    Node *prev = nullptr;

    while (current)
    {
      if (seen.count(current->value))
      {
        prev->next = current->next;
        delete current;
      }
      else
      {
        seen.insert(current->value);
        prev = current;
      }
      current = prev->next;
    }

    length--;
  }

  int binaryToDecimal()
  {
    Node *temp = head;
    int decimal = 0;

    while (temp)
    {
      if (temp->value)
      {
        decimal += 1;
      }
      if (temp->next)
      {
        decimal = decimal * 2;
      }
      temp = temp->next;
    }
    cout << "Binary To Decimal: " << decimal << endl;
    return decimal;
  }

  void partitionList(int x)
  {
    Node *current = head;

    if (current == nullptr)
    {
      return;
    }

    LinkedList *beforeHead = new LinkedList(0);
    LinkedList *afterHead = new LinkedList(0);
    Node *before = beforeHead->head;
    Node *after = afterHead->head;

    while (current)
    {
      if (current->value < x)
      {
        before->next = current;
        before = before->next;
      }
      else
      {
        after->next = current;
        after = after->next;
      }
      current = current->next;
    }

    before->next = afterHead->head->next;
    after->next = nullptr;
    head = beforeHead->head->next;
  }

  void reverseBetween(int m, int n) {
    if (head == nullptr)
      return;

    Node *dummy = new Node(0);
    dummy->next = head;

    Node *prev = dummy;
    for (int i = 0; i < m; i++) {
      prev = prev->next;
    }

    Node *current = prev->next;
    Node *after = current->next;

    for (int i = 0; i < n - m; i++) {
      current->next = after->next;
      after->next = prev->next;
      prev->next = after;
      after = current->next; 
    }

    head = dummy->next;
  }

  void swapPairs() {
    Node *dummy = new Node(0);
    dummy->next = head;

    Node *prev = dummy;
    Node *first = head;
    Node *second = nullptr;

    while (first)
    {
      second = first->next;
      if (second == nullptr) {
        break;
      }

      prev->next = second;
      first->next = second->next;
      second->next = first;

      prev = first;
      first = first->next;
    }

    head = dummy->next;
  }
};

int main()
{
  LinkedList *myLinkedList = new LinkedList(9);
  myLinkedList->append(10);
  myLinkedList->append(12);
  myLinkedList->prepend(7);

  myLinkedList->deleteLastNode();
  myLinkedList->append(15);
  myLinkedList->deleteFirst();

  myLinkedList->printList();
  myLinkedList->getHead();
  myLinkedList->getTail();
  myLinkedList->getLength();

  cout << "Node at index 0: " << myLinkedList->get(0)->value << endl;

  myLinkedList->set(2, 49);
  myLinkedList->printList();

  cout << endl;

  myLinkedList->insert(3, 40);
  myLinkedList->printList();

  cout << endl;

  myLinkedList->deleteAtIndex(2);
  myLinkedList->printList();

  cout << endl;

  myLinkedList->append(20);
  myLinkedList->append(25);
  myLinkedList->append(32);
  myLinkedList->append(9);
  myLinkedList->reverse();
  myLinkedList->removeDuplicates();
  myLinkedList->partitionList(10);
  cout << "List after reversing, removing duplicates and partition: ";
  myLinkedList->printList();

  cout << endl << "Reverse Between: ";
  myLinkedList->reverseBetween(1, 3);
  myLinkedList->printList();

  cout << endl << "Swap Pairs: ";
  myLinkedList->swapPairs();
  myLinkedList->printList();

  cout << endl;

  Node *middleNode = myLinkedList->middle();
  cout << "Middle Node: " << middleNode->value << endl;

  cout << "Has loop: " << myLinkedList->hasLoop() << endl;

  cout << "Kth From End: " << myLinkedList->findKthFromEnd(1)->value << endl;

  LinkedList *binaryLinkedList = new LinkedList(1);
  binaryLinkedList->append(1);
  binaryLinkedList->append(1);
  binaryLinkedList->append(1);
  binaryLinkedList->binaryToDecimal();

  return 0;
}