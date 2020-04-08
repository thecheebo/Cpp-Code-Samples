#include <iostream>

int main() {
  int x=53;
  int* xPtr = &x;
  std::cout << xPtr << "\n";
  std::cout << &xPtr << "\n";
  std::cout << *xPtr << "\n";
  std::cout << *&xPtr << "\n";
  std::cout << &*&xPtr << "\n";
  std::cout << **&*&xPtr << "\n";
  std::cout << x << "\n";
  std::cout << &x << "\n";
}
