#include <stdio.h>
#include <iostream> 

int main() {
    int casos;
    std::cin >> casos;
    for (int i=0; i < casos; ++i) {
        int major;
        int minor;
        int patch;
        int major2;
        int minor2;
        int patch2;
        int yes = 0;
        scanf("%i.%i.%i", &major, &minor, &patch);
        scanf("%i.%i.%i", &major2, &minor2, &patch2);
        if (major == major2){
            if (minor == minor2){
                if(patch2 - patch == 1) {
                    printf("SI\n");
                    yes = 1;
                    
                }
            } else if (minor2 - minor == 1 && patch2 == 0) {
                printf("SI\n");
                yes = 1;
                
            }
        } else if (major2 - major == 1 && minor2 == 0 && patch2 == 0) {
            printf("SI\n");
            yes = 1;
            
        }
        if (!yes) {
            printf("NO\n");
        }
    }
    return 0;
}
