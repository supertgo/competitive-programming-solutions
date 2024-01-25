#include <iostream>

int main (int argc, char *argv[]) {

  int t, a, b, x, y;

  std::cin >> t;

  while(t--) {
    std::cin >> a >> b >> x >> y; 
    int newX, newY;
    
    if (x == 0) {
      newX = a;
    } else {
      newX = a - x - 1; 
    }
    
    if (y == 0) {
      newY = y;
    } else {
      newY = b - y - 1; 
    }

    std::cout << a * newY << std::endl;
  }
  
  return 0;
}

