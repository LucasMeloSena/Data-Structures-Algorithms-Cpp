#include <iostream>
using namespace std;

class Node
{
public:
  int value;
  Node *next;
  string key;

  Node(string key, int value)
  {
    this->value = value;
    this->key = key;
    this->next = nullptr;
  }
};

class HashTable
{
private:
  static const int SIZE = 7;
  Node *dataMap[SIZE];

public:
  void printTable()
  {
    for (int i = 0; i < SIZE; i++)
    {
      cout << i << ":" << endl;
      if (dataMap[i])
      {
        Node *temp = dataMap[i];
        while (temp)
        {
          cout << "   {" << temp->key << ", " << temp->value << "}" << endl;
          temp = temp->next;
        }
      }
    }
  }

  int hash(string key)
  {
    int hash = 0;
    for (int i = 0; i < key.length(); i++)
    {
      int asciiValue = int(key[i]);
      hash = (hash + asciiValue * 23) % SIZE;
    }
    return hash;
  }

  void set(string key, int value)
  {
    int index = hash(key);
    Node *newNode = new Node(key, value);
    if (!dataMap[index])
    {
      dataMap[index] = newNode;
    }
    else
    {
      Node *temp = dataMap[index];
      while (temp->next)
      {
        temp = temp->next;
      }
      temp->next = newNode;
    }
  }

  int get(string key)
  {
    int index = hash(key);
    Node *temp = dataMap[index];
    while (temp)
    {
      if (temp->key == key)
      {
        return temp->value;
      }
      temp = temp->next;
    }
    return 0;
  }

  vector<string> keys()
  {
    vector<string> allKeys;
    for (int i = 0; i < SIZE; i++)
    {
      Node *temp = dataMap[i];
      while (temp)
      {
        allKeys.push_back(temp->key);
        temp = temp->next;
      }
    }
    return allKeys;
  }
};

int main()
{
  HashTable *myHashTable = new HashTable();

  myHashTable->set("nails", 12);
  myHashTable->set("tile", 7);
  myHashTable->set("lumber", 4);
  myHashTable->set("truck", 23);
  myHashTable->set("moto", 21);
  myHashTable->set("guitar", 32);
  myHashTable->set("keyboard", 15);

  myHashTable->printTable();
  cout << "Get Lumber Key value: " << myHashTable->get("lumber") << endl;

  vector<string> myKeys = myHashTable->keys();
  for (auto key : myKeys) {
    cout << key << " ";
  }

  unordered_map<int, bool> myMap;
  myMap.find(0);
};