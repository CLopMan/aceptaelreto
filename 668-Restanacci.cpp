#include <stdio.h>
#include <iostream> 

int restanacci(int a, int b, int n) {
    if (n == 0) {
        return a;
    } else if (n == 1) {
        return b;
    } 
    int out;
    for (int i = 2; i <= n; ++i) {
        out = b - a;
        a = b;
        b = out; 
    }
    return out;
}

int restanacci_better(int a, int b, int n) {
    n = n%6;
    if (n == 0) {
        return a;
    } else if (n == 1) {
        return b;
    } else if (n == 2) {
        return b - a;
    } else if (n == 3) {
        return -a;
    } else if (n == 4) {
        return -b;
    } else if (n == 5) {
        return a - b;
    }
}

int main() {
    int a, b, n;
    std::cin >> a >> b >> n;
    while (!(a == 0 && b == 0 && n == 0)) {
        std::cout << restanacci_better(a, b, n) << "\n";
        std::cin >> a >> b >> n;
    }
}
