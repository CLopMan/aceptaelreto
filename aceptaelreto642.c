#include <stdio.h>

/*typedef struct Node {
    int visited;
    int node;
    int bf;
} Node;

Node newNode(int n, int bf) {
    Node node;
    node.node = n;
    node.bf = bf;
    node.visited = 0;
    return node;
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        Node nodes[n];
        int i = 0;
        int out = 0;
        int current;
        for (i; i < n; ++i) {
            scanf("%d", &current);
            nodes[i] = newNode(i + 1, current);
        }
        i = 0;
        for (i; i < n; ++i) {
            if (nodes[nodes[i].bf - 1].visited){
                if(nodes[i].visited) {
                    ++out;
                }
            } else {
                nodes[nodes[i].bf - 1].visited = 1;
            }
            nodes[i].visited = 1;
        }
        
        printf("%d\n", out);
    }
    return 0; 
}*/
