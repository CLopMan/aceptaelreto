#include <iostream>
#include <stdio.h>
#include <algorithm>

int cte_Kaprekar(int n) {
    int out = 0;
    while (n != 6174) {
        // get the numbers
        /*int d0, d1, d2, d3;
        d0 = n % 10;
        n /= 10;
        d1 = n % 10;
        n /= 10;
        d2 = n % 10;
        n /= 10; 
        d3 = n % 10;*/
        int arr[4];// = {d0, d1, d2, d3};

        for (int i = 0; i < 4; ++i) {
            arr[i] = n % 10;
            n /= 10;
        }
        std::sort(arr, arr + 4);
        int greater = arr[3]*1000 + arr[2]*100 + arr[1]*10 + arr[0];
        int lower = arr[3] + arr[2]*10 + arr[1]*100 + arr[0]*1000;

        n = greater - lower; 
        if (n <= 0) {
            return 8;
        }
        ++out;
    }
    return out;


}

int main() {
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    int casos;
    int n;
    std::cin >> casos;

    for (int i = 0; i < casos; ++i) {
        std::cin >> n;
        std::cout << cte_Kaprekar(n) << "\n";
    }
}