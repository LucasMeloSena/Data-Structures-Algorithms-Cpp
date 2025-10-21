#include <iostream>
using namespace std;

class Heap {
  private:
    vector<int> heap;

  int leftChild(int index) {
    return 2 * index + 1;
  }

  int rightChild(int index) {
    return 2 * index + 2;
  }

  int parent(int index) {
    return (index - 1) / 2;
  }

  void swap(int index1, int index2) {
    int temp = heap[index1];
    heap[index1] = heap[index2];
    heap[index2] = temp;
  }

  void sinkDown(int index) {
    int maxIndex = index;
    while (true) {
      int leftIndex = leftChild(index);
      int rightIndex = rightChild(index);

      if (leftIndex < heap.size() && heap[leftIndex] > heap[rightIndex]) {
        maxIndex = leftIndex;
      } else if (rightIndex < heap.size() && heap[rightIndex] > heap[leftIndex]) {
        maxIndex = rightIndex;
      }

      if (index != maxIndex) {
        swap(index, maxIndex);
        index = maxIndex;
      } else {
        return;
      }
    }
  }

  public:
  void print() {
    cout << "[";
    for (size_t i = 0; i < heap.size(); i++) {
      cout << heap[i];
      if (i < heap.size() - 1) {
        cout << ",";
      }
    }
    cout << "]" << endl;
  }

  void insert(int value) {
    heap.push_back(value);
    int currIdx = heap.size() - 1;
    while (currIdx > 0 && heap[currIdx] > heap[parent(currIdx)]) {
      int parentIdx = parent(currIdx);
      swap(currIdx, parentIdx);
      currIdx = parentIdx;
    }
  }

  int remove() {
    if (heap.empty()) {
      return INT_MIN;
    }
    int maxValue = heap.front();
    if (heap.size() == 1) {
      heap.pop_back();
    } else {
      heap[0] = heap.back();
      heap.pop_back();
      sinkDown(0);
    }

    return maxValue;
  }
};

int main() {
  Heap *myHeap = new Heap();
  myHeap->insert(95);
  myHeap->insert(75);
  myHeap->insert(80);
  myHeap->insert(55);
  myHeap->insert(60);
  myHeap->insert(50);
  myHeap->insert(65);

  cout << "Print before remove: " << endl;
  myHeap->print();

  cout << "Print after remove: " << endl;
  myHeap->remove();
  myHeap->print();
}