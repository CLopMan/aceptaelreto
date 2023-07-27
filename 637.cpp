/*https://aceptaelreto.com/problem/statement.php?id=637&potw=1#ftn.2*/

#include <iostream> 
#define A_ascii 65
#define space 5
#define letter_gap 3

int const durations[] = {5, 9, 11, 7, 1, 9, 9,
                   7, 3, 13, 9, 9, 7,
                   5, 11, 11, 13, 7, 5, 
                   3, 7, 9, 9, 11, 13, 11};

/*int tratar_caso() {
    char c; 
    int duration = 0; 
    bool first = true; 
    c = getchar_unlocked(); 
    while (c != '\n') {
        if (c == ' ') {
            duration += space;
            first = true;
        } else{
            if (!first) duration += letter_gap;
            if (c == '!') {
                duration += 19;
            }else if (c == '?') {
                duration += 15;  
            } else {
                duration += durations[(int)c - A_ascii];
            }
            first = false;
        }
        c = getchar_unlocked(); 
    }
    return duration;
}*/

int tratar_caso() {
    char c;
    int duration = 0; 
    int letters = 0, spaces = 0;
    c = getchar_unlocked();
    while (c != '\n') {
        switch (c)
        {
        case ' ':
            spaces++;
            duration += space;
            break;
        
        case '!':
            letters++;
            duration += 19;
            break;
        
        case '?':
            letters++;
            duration += 15;
            break;
        
        default:
            letters++;
            duration += durations[c - A_ascii];
            break;
        }
        c = getchar_unlocked();
    }
    return duration + ((letters - 1) - spaces)*letter_gap;
}

int main() {
    int casos; 
    std::cin >> casos; 
    char dummy = getc(stdin);
    for (int i = 0; i < casos; ++i) {
        std::cout << tratar_caso() << "\n";
    }
    return 0; 
}