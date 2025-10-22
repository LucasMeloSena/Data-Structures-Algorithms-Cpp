#include <iostream>
#include <queue>

using namespace std;

class Node
{
public:
  int value;
  Node *left;
  Node *right;

  Node(int value)
  {
    this->value = value;
    this->left = nullptr;
    this->right = nullptr;
  }
};

class BinarySearchTree
{
private:
  Node *root;

public:
  BinarySearchTree()
  {
    root = nullptr;
  }

  BinarySearchTree(int value)
  {
    Node *newNode = new Node(value);
    root = newNode;
  }

  bool insert(int value)
  {
    Node *newNode = new Node(value);
    if (root == nullptr)
    {
      root = newNode;
      return true;
    }
    Node *temp = root;
    while (true)
    {
      if (newNode->value == temp->value)
        return false;

      if (newNode->value < temp->value)
      {
        if (!temp->left)
        {
          temp->left = newNode;
          return true;
        }
        temp = temp->left;
      }
      else
      {
        if (!temp->right)
        {
          temp->right = newNode;
          return true;
        }
        temp = temp->right;
      }
    }
  }

  bool contains(int value)
  {
    Node *temp = root;
    while (temp)
    {
      if (value < temp->value)
      {
        temp = temp->left;
      }
      else if (value > temp->value)
      {
        temp = temp->right;
      }
      else
      {
        return true;
      }
    }
    return false;
  }

  void BFS()
  {
    queue<Node *> myQueue;
    myQueue.push(root);

    while (myQueue.size() > 0)
    {
      Node *currentNode = myQueue.front();
      myQueue.pop();
      cout << currentNode->value << " ";
      if (currentNode->left)
      {
        myQueue.push(currentNode->left);
      }
      if (currentNode->right)
      {
        myQueue.push(currentNode->right);
      }
    }
  }

  void DFSPreOrder(Node *currentNode)
  {
    cout << currentNode->value << " ";
    if (currentNode->left)
    {
      DFSPreOrder(currentNode->left);
    }
    if (currentNode->right)
    {
      DFSPreOrder(currentNode->right);
    }
  }

  void DFSPreOrder() { DFSPreOrder(root); }

  void DFSPostOrder(Node *currentNode)
  {
    if (currentNode->left)
    {
      DFSPostOrder(currentNode->left);
    }
    if (currentNode->right)
    {
      DFSPostOrder(currentNode->right);
    }
    cout << currentNode->value << " ";
  }

  void DFSPostOrder() { DFSPostOrder(root); }

  void DFSInOrder(Node *currentNode) {
    if (currentNode->left)
    {
      DFSInOrder(currentNode->left);
    }
    cout << currentNode->value << " ";
    if (currentNode->right)
    {
      DFSInOrder(currentNode->right);
    }
  }

  void DFSInOrder() { DFSInOrder(root); }
};

int main()
{
  BinarySearchTree *bst = new BinarySearchTree(47);
  bst->insert(21);
  bst->insert(76);
  bst->insert(18);
  bst->insert(27);
  bst->insert(52);
  bst->insert(82);

  cout << "BFS: ";
  bst->BFS();
  cout << "\n";
  cout << "DFS PreOrder: ";
  bst->DFSPreOrder();
  cout << "\n";
  cout << "DFS PostOrder: ";
  bst->DFSPostOrder();
  cout << "\n";
  cout << "DFS InOrder: ";
  bst->DFSInOrder();
  cout << "\n";
}