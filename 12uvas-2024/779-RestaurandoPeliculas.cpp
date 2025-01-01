#include <stdio.h>
#include <iostream>
#include <list>

typedef struct {
    int begin;
    int end;
} interval;

void myinsert(std::vector &fotogramas, fa, fb) {
    if (fotogramas.size() == 0) {fotogramas.emplace_back({fa, fb}); return ;}

    for (int i = 0; i < fotogramas.size(); ++i) {
        if (fb < fotogramas[i].end) 
        if (fa < fotogramas[i].begin && fb < fotogramas[i].end ) fotogramas[i].begin = fa;
        else if (fa > fotogramas[i].begin && fb > fotogramas[i].end ) fotogramas[i].end = fb;
        else if (fa < fotogramas[i].begin && fb > 
    }


}

int main() {
    while (true) {
        std::list<interval> fotogramas;
        int N, copias;
        std::cin >> N >> copias;

        if (N == 0) return 0;

        for (int i = 0; i < copias; ++i) {
            int sec, fa, fb;
            std::cin >> sec;
            for (int j = 0; j < sec; ++j) {
                scanf("%i,%i", &fa, &fb); 
                myinsert(fotogramas, a, b);
            }
        }
         

    } 

    return 0;
}
