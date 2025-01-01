#include <iostream>
#include <vector>


int maxSum(std::vector<int> &v, int k) {
    int acum[v.size()]; 
    for (int i = 0; i < v.size(); ++i) {
        acum[i] = v[i] + ((i - 1 < 0) ? 0 : acum[i - 1]) - ((i - k < 0) ? 0 : v[i - k]);
    }

    std::vector<int> dinamic(v.size());
    for (int i = k - 1; i < v.size(); ++i) {
        dinamic[i] = std::max((acum[i] + (i - k < 0 ? 0: dinamic[i - k])), dinamic[i - 1]);
    }
    return dinamic[v.size() - 1];
}

int maxSumBad(std::vector<int> &v, int k, int s, int e) {
    if (e - s < k - 1) return 0;
    if (e - s == k - 1) {
        int out = 0;
        for (int x = s; x <= e; ++x) {
            out += v[x]; 
        }
        return out;
    }
    int acum[e - s + 1]; 
    int max = 0;
    int maxI = 0;
    int maxJ = 0;
    for (int i = s; i <= e; ++i) {
        acum[i] = v[i] + ((i - 1 < 0) ? 0 : acum[i - 1]) - ((i - k < 0) ? 0 : v[i - k]);
        if (max < acum[i]) {
            max = acum[i];
            maxI = i - k + 1;
            maxJ = i;
        }
    }

    return max + maxSumBad(v, k, s, maxI - 1)
               + maxSumBad(v, k, maxJ + 1, e);
}

int main() {
    while (true) {
        int n, k;
        std::vector<int> v;
        std::cin >> n >> k;
        if (n == 0) return 0;

        int a; 
        for (int i = 0; i < n; ++i) {
            std::cin >> a;
            v.push_back(a);
        }

        std::cout << maxSum(v, k) - maxSumBad(v, k, 0, v.size() - 1) << "\n";

    }
    return 0;
}
