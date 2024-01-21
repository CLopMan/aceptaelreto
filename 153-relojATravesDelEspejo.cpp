/*https://aceptaelreto.com/problem/statement.php?id=153&potw=1*/

#include <iostream> 
#include <string>

void tratar_caso(int h, int m) {
    std::string output; 
    int o_horas, o_minutos; 
    o_horas = abs(12 - h);

    o_minutos = abs(60 - m) %  60; 
    if (m > 0) o_horas -= 1;

    o_horas = (o_horas <= 0) ? o_horas + 12 : o_horas; 
    if (o_horas < 10) output = "0";
    output += std::to_string(o_horas) + ":"; 

    if (o_minutos < 10) output += "0";
    output += std::to_string(o_minutos) + "\n";

    std::cout << output;

}

int main() {
        std::cin.tie(NULL);
        std::ios_base::sync_with_stdio(false);
        int casos;
        int horas, minutos;
        char colon;
        std::cin >> casos; 
        for ( int i = 0; i < casos; ++i ) {

            std::cin >> horas >> colon >> minutos; 
            tratar_caso(horas, minutos);
        }
    
    
    return 0;
}