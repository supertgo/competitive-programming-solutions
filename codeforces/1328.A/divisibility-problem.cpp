#include <iostream>

int main(int argc, char *argv[]) {
  int number_of_tests, a, b;

  std::cin >> number_of_tests;

  while (number_of_tests--) {

    std::cin >> a >> b;

    int remaining = a % b;
    int result = a / b;

    if (remaining == 0) {
      std::cout << remaining << std::endl;
      continue;
    }

    if (remaining == a) {
      std::cout << b - a << std::endl;
      continue;
    }

    std::cout << (result + 1) * b - a << std::endl;
  }

  return 0;
}
