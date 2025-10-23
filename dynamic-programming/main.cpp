#include <iostream>
using namespace std;

vector<int> memo(100, -1);
static int counterTopDown = 0;
static int counterBottomUp = 0;

int fibonacciTopDown(int n)
{
  counterTopDown++;
  if (n == 0 || n == 1)
  {
    return n;
  }
  if (memo[n] != -1)
  {
    return memo[n];
  }
  memo[n] = fibonacciTopDown(n - 1) + fibonacciTopDown(n - 2);
  return memo[n];
}

int fibonacciBottomUp(int n) {
  vector<int> fibList;
  fibList.push_back(0);
  fibList.push_back(1);
  for (int i = 2; i <= n; i++) {
    counterBottomUp++;
    fibList.push_back(fibList[i - 1] + fibList[i - 2]);
  }
  return fibList[n];
}

int main()
{
  int input = 41;
  int topDown = fibonacciTopDown(input);
  int bottomUp = fibonacciBottomUp(input);

  cout << "Counter Top Down: " << counterTopDown << endl;
  cout << "Fibonacci " << input << " (Top Down): " << topDown << endl;
  cout << "Counter Bottom Up: " << counterBottomUp << endl;
  cout << "Fibonacci " << input << " (Bottom Up): " << bottomUp << endl;
}