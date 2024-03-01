#include <iostream>
#include <vector>
#include <string>

bool compare (std::string & a, std::string b) {
    if (a.length() != b.length()) return false;
    std::string aux = b;
    for (int i = 0; i < a.length(); ++i) {
        if (toupper(a[i]) != toupper(b[i])) {
            return false;
        } else {
            aux[i] = std::min(a[i], b[i]);
        }
    }
    a = aux;
    return true;
}


int main() {
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);
    int casos; 
    int curr_word = 0;
    std::vector<std::string> palabras (1000); 
    std::vector<int> index(1000);

    while(std::cin >> casos) {
        palabras.clear();
        index.clear();
        curr_word = 0;
        std::string palabra; 
        for (int i = 0; i < casos; ++i) {
            std::cin >> palabra; 
            if (index.size() == 0) {
                palabras.push_back(palabra);
                
            }
            for (int j = 0; j < palabras.size(); ++j) {
                if (compare(palabras[j], palabra)) {    
                    index.push_back(j);   
                    break; 
                } else {
                    if (j == palabras.size() - 1) {
                        palabras.push_back(palabra);
                        ++curr_word;
                    }
                }
            }

        }
        
        for (auto i : index) {
            std::cout << palabras[i] << "\n";
        }
        std::cout <<"---\n";
    }

    return 0; 
}