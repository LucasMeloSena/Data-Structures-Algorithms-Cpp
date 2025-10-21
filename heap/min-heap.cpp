#include <iostream>
using namespace std;

class MinHeap
{
private:
  vector<int> heap;

  int leftChild(int index)
  {
    return 2 * index + 1;
  }

  int rightChild(int index)
  {
    return 2 * index + 2;
  }

  int parent(int index)
  {
    return (index - 1) / 2;
  }

  void swap(int index1, int index2)
  {
    int temp = heap[index1];
    heap[index1] = heap[index2];
    heap[index2] = temp;
  }

  void sinkDown(int index)
  {
    int minIndex = index;
    while (true)
    {
      int leftIndex = leftChild(index);
      int rightIndex = rightChild(index);

      if (leftIndex < heap.size() && heap[leftIndex] < heap[rightIndex])
      {
        minIndex = leftIndex;
      }
      else if (rightIndex < heap.size() && heap[rightIndex] < heap[leftIndex])
      {
        minIndex = rightIndex;
      }

      if (index != minIndex)
      {
        swap(index, minIndex);
        index = minIndex;
      }
      else
      {
        return;
      }
    }
  }

public:
  void print()
  {
    cout << "[";
    for (size_t i = 0; i < heap.size(); i++)
    {
      cout << heap[i];
      if (i < heap.size() - 1)
      {
        cout << ",";
      }
    }
    cout << "]" << endl;
  }

  void insert(int value)
  {
    heap.push_back(value);
    int currIdx = heap.size() - 1;
    while (currIdx > 0 && heap[currIdx] < heap[parent(currIdx)])
    {
      int parentIdx = parent(currIdx);
      swap(currIdx, parentIdx);
      currIdx = parentIdx;
    }
  }

  int remove()
  {
    if (heap.empty())
    {
      return INT_MIN;
    }
    int minValue = heap.front();
    if (heap.size() == 1)
    {
      heap.pop_back();
    }
    else
    {
      heap[0] = heap.back();
      heap.pop_back();
      sinkDown(0);
    }

    return minValue;
  }
};

int main()
{
  MinHeap *myMinHeap = new MinHeap();
  myMinHeap->insert(95);
  myMinHeap->insert(75);
  myMinHeap->insert(80);
  myMinHeap->insert(55);
  myMinHeap->insert(60);
  myMinHeap->insert(50);
  myMinHeap->insert(65);
  myMinHeap->insert(30);

  cout << "Print before remove: " << endl;
  myMinHeap->print();

  cout << "Print after remove: " << endl;
  myMinHeap->remove();
  myMinHeap->print();
}