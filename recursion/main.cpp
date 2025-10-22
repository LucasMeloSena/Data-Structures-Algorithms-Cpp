#include <iostream>
using namespace std;

int factorial(int value) {
  if (value == 1)
    return 1;
  return value * factorial(value - 1);
}

int main() {
  int res = factorial(4);
  cout << "Factorial Result: " << res << endl;
}