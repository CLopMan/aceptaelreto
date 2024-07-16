#include <iostream>

int heightCount () {
    int node, child;
    std::cin >> node;
    if (node == 0) return 1;

    int maxH = 0, aux;
    for (int i = 0; i < node; ++i) {
        aux = heightCount();
        if (aux > maxH) maxH = aux;

    }
    return 1 + maxH;

}
int main () {
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    int casos;
    std::cin >> casos;

    for (int i = 0; i < casos; ++i) {
        std::cout << heightCount() << "\n";
    }

    return 0;
}
