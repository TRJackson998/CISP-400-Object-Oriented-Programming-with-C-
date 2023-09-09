#include "../std_lib_facilities.h"

int main() {
  char operation;
  double num1, num2;

  cin >> operation >> num1 >> num2;

  if(operation == '+') {
    cout << "= " << num1 + num2 << endl;
  }
  else if(operation == '-') {
    cout << "= " << num1 - num2 << endl;
  }
  else if(operation == '*') {
    cout << "= " << num1 * num2 << endl;
  }
  else if(operation == '/') {
    while (num2 < 0.001 && num2 > -.001) {
      cin >> num2;
    }
    cout << "= " << num1 / num2 << endl;
  }



  return 0;
}
