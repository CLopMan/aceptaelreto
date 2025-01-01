#include <iostream>

int gcd (int a, int b) {
  int temp;
  while (b != 0) {
    temp = a % b;
    a = b;
    b = temp;
  }
  return(a);
}

int main() {
    int casos;
    std::cin >> casos;

    for (int i = 0; i < casos; ++i) {
        int a, b;
        std::cin >> a >> b;
        int d = gcd(a, b);
        a = a/d;
        b = b/d;
        std::cout << a + b - 1 << "\n";
    }

    return 0;
}
