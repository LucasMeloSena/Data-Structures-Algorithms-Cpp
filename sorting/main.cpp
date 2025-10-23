#include <iostream>
using namespace std;

void bubbleSort(int array[], int size)
{
  for (int i = size - 1; i > 0; i--)
  {
    for (int j = 0; j < i; j++)
    {
      if (array[j] > array[j + 1])
      {
        int temp = array[j];
        array[j] = array[j + 1];
        array[j + 1] = temp;
      }
    }
  }
}

void selectionSort(int array[], int size)
{
  for (int i = 0; i < size; i++)
  {
    int minIndex = i;
    for (int j = i + 1; j < size; j++)
    {
      if (array[j] < array[minIndex])
      {
        minIndex = j;
      }
    }
    if (i != minIndex)
    {
      int temp = array[i];
      array[i] = array[minIndex];
      array[minIndex] = temp;
    }
  }
}

void insertionSort(int array[], int size)
{
  for (int i = 1; i < size; i++)
  {
    int temp = array[i];
    int j = i - 1;
    while (j > -1 && temp < array[j])
    {
      array[j + 1] = array[j];
      array[j] = temp;
      j--;
    }
  }
}

void merge(int array[], int leftIndex, int midIndex, int rightIndex)
{
  int leftArrSize = midIndex - leftIndex + 1;
  int rightArrSize = rightIndex - midIndex;

  int leftArray[leftArrSize];
  int rightArray[rightArrSize];

  for (int i = 0; i < leftArrSize; i++)
  {
    leftArray[i] = array[leftIndex + i];
  }
  for (int j = 0; j < rightArrSize; j++)
  {
    rightArray[j] = array[midIndex + 1 + j];
  }

  int index = leftIndex;
  int i = 0;
  int j = 0;

  while (i < leftArrSize && j < rightArrSize)
  {
    if (leftArray[i] < rightArray[j])
    {
      array[index] = leftArray[i];
      index++;
      i++;
    }
    else if (rightArray[j] < leftArray[i])
    {
      array[index] = rightArray[j];
      index++;
      j++;
    }
  }

  while (i < leftArrSize) {
    array[index] = leftArray[i];
    index++;
    i++;
  }
  while (j < rightArrSize) {
    array[index] = rightArray[j];
    index++;
    j++;
  }
}

void mergeSort(int array[], int leftIndex, int rightIndex) {
  if (leftIndex >= rightIndex)
    return;
  int midIndex = leftIndex + (rightIndex - leftIndex) / 2;
  mergeSort(array, leftIndex, midIndex);
  mergeSort(array, midIndex+1 , rightIndex);

  merge(array, leftIndex, midIndex, rightIndex);
}

void swap(int array[], int firstIndex, int secondIndex) {
  int temp = array[firstIndex];
  array[firstIndex] = array[secondIndex];
  array[secondIndex] = temp;
}

int pivot(int array[], int pivotIndex, int endIndex) {
  int swapIndex = pivotIndex;
  for (int i = pivotIndex + 1; i <= endIndex; i++) {
    if (array[i] < array[pivotIndex]) {
      swapIndex++;
      swap(array, swapIndex, i);
    }
  }
  swap(array, pivotIndex, swapIndex);
  return swapIndex;
}

void quickSort(int array[], int leftIndex, int rightIndex) {
  if (leftIndex >= rightIndex)
    return;

  int pivotIndex = pivot(array, leftIndex, rightIndex);
  quickSort(array, leftIndex, pivotIndex - 1);
  quickSort(array, pivotIndex + 1, rightIndex);
}

int main()
{
  int myArr[] = {1,3,7,8,2,4,5,6};
  int size = sizeof(myArr) / sizeof(myArr[0]);
  int leftIndex = 0;
  int rightIndex = size - 1;
  int midIndex = (size / 2) - 1;

  // bubbleSort(myArr, size);
  // selectionSort(myArr, size);
  // insertionSort(myArr, size);
  // mergeSort(myArr, leftIndex, rightIndex);
  quickSort(myArr, leftIndex, rightIndex);

  for (auto num : myArr)
  {
    cout << num << " ";
  }
}