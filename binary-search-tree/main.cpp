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

  void invert(Node *currentNode) {
    if (currentNode) {
      Node *left = currentNode->left;
      currentNode->left = currentNode->right;
      currentNode->right = left;
      invert(currentNode->left);
      invert(currentNode->right);
    }
  }
};

int main()
{
  BinarySearchTree *bst = new BinarySearchTree(7);
  bst->insert(12);
  bst->insert(27);
  bst->insert(3);

  cout << "Contains 27? " << bst->contains(27) << endl;
  cout << "Contains 17? " << bst->contains(17) << endl;
}