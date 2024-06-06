#include <iostream> 
#include <string> 

int main() {
    int casos; 
    std::string frst, snd, third;
    std::cin >> casos; 

    for (int i = 0; i < casos; i++) {
        std::cin >> frst >> snd >> third; 

        bool found = false; 
        std::string l,r;
        
        l = frst + snd[0];
        r = snd[1] + third;

        if (l == r) found = true; 


        l = frst + third[0];
        r = third[1] + snd;

        if (l == r) found = true; 

        l = snd + frst[0];
        r = frst[1] + third;

        if (l == r) found = true; 

        l = snd + third[0];
        r = third[1] + frst;

        if (l == r) found = true; 

        l = third + snd[0];
        r = snd[1] + frst;

        if (l == r) found = true; 

        l = third + frst[0];
        r = frst[1] + snd;

        if (l == r) found = true; 

        if (found) std::cout << "DIVERTIDOS\n";
        else std::cout << "INSULSOS\n";

    }
    

    return 0;
}