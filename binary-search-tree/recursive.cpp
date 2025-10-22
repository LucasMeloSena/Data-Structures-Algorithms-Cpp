#include <iostream>
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

  Node *insert(Node *currentNode, int value)
  {
    if (currentNode == nullptr)
    {
      return new Node(value);
    }

    if (value < currentNode->value)
    {
      currentNode->left = insert(currentNode->left, value);
    }
    else if (value > currentNode->value)
    {
      currentNode->right = insert(currentNode->right, value);
    }
    return currentNode;
  }

  void insert(int value)
  {
    root = insert(root, value);
  }

  bool contains(Node *current, int value)
  {
    if (!current)
      return false;
    if (current->value == value)
      return true;
    if (value < current->value)
    {
      return contains(current->left, value);
    }
    else
    {
      return contains(current->right, value);
    }
  }

  bool contains(int value)
  {
    Node *temp = root;
    return contains(temp, value);
  }

  int minValue(Node *currentNode)
  {
    if (currentNode->left == nullptr)
    {
      return currentNode->value;
    }
    return minValue(currentNode->left);
  }

  int minValue()
  {
    return minValue(root);
  }

  Node *deleteNode(Node *currentNode, int value)
  {
    if (currentNode == nullptr)
      return nullptr;

    if (value < currentNode->value)
    {
      currentNode->left = deleteNode(currentNode->left, value);
    }
    else if (value > currentNode->value)
    {
      currentNode->right = deleteNode(currentNode->right, value);
    }
    else
    {
      if (!currentNode->left && !currentNode->right)
      {
        delete (currentNode);
        return nullptr;
      }
      else if (!currentNode->left)
      {
        Node *temp = currentNode->right;
        delete (currentNode);
        return temp;
      }
      else if (!currentNode->right)
      {
        Node *temp = currentNode->left;
        delete (currentNode);
        return temp;
      }
      else
      {
        int subTreeMin = minValue(currentNode->right);
        currentNode->value = subTreeMin;
        currentNode->right = deleteNode(currentNode->right, subTreeMin);
      }
    }
    return currentNode;
  }

  void deleteNode(int value)
  {
    root = deleteNode(root, value);
  }

  Node *getRoot() {
    return root;
  }
};

int main()
{
  BinarySearchTree *bst = new BinarySearchTree(2);
  bst->insert(1);
  bst->insert(3);

  cout << "Contains 27? " << bst->contains(27) << endl;
  cout << "Contains 17? " << bst->contains(17) << endl;
  cout << "Min value: " << bst->minValue() << endl;

  /* 
       2
      /  \
     1    3
  */
  cout << "Before Deleting (2) Node: " << endl;
  cout << "-----------------" << endl;
  cout << "Root: " << bst->getRoot()->value << endl;
  cout << "Root->Left: " << bst->getRoot()->left->value << endl;
  cout << "Root->Right: " << bst->getRoot()->right->value << endl;

  bst->deleteNode(2);
  cout << "Aftr Deleting (2) Node: " << endl;
  cout << "-----------------" << endl;
  cout << "Root: " << bst->getRoot()->value << endl;
  cout << "Root->Left: " << bst->getRoot()->left->value << endl;
  cout << "Root->Right: " << bst->getRoot()->right << endl;
}