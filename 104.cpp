/*https://aceptaelreto.com/problem/statement.php?id=104&potw=1*/

#include <iostream>
#include <cinttypes>

uint_fast16_t is_balance (uint_fast16_t Pa, uint_fast16_t a, uint_fast16_t Pb, uint_fast16_t b) {
    // if is balance returns weight, else return -1
    //std::cout << Pa << " " << a << " " << Pb << " " << b << "\n";
    uint_fast16_t Pa_2, a_2, Pb_2, b_2;
    if (Pa != 0 && Pb != 0) {
        if (Pa * a == Pb * b) return Pa + Pb;
        else return -1;
    } else if (Pa != 0 && Pb == 0) {
        std::cin >> Pa_2 >> a_2 >> Pb_2 >> b_2;
        uint_fast16_t sub_b = is_balance(Pa_2, a_2, Pb_2, b_2);
        if (sub_b == -1) return -1;
        if (Pa * a == sub_b*b) return Pa + sub_b;
        else return -1;
    } else if (Pa == 0 && Pb != 0) {
        std::cin >> Pa_2 >> a_2 >> Pb_2 >> b_2;
        uint_fast16_t sub_a = is_balance(Pa_2, a_2, Pb_2, b_2);
        if (sub_a == -1) return -1;
        if (Pb * b == sub_a*a) return Pb + sub_a;
    } else {
        std::cin >> Pa_2 >> a_2 >> Pb_2 >> b_2;
        uint_fast16_t sub_a = is_balance(Pa_2, a_2, Pb_2, b_2);
        std::cin >> Pa_2 >> a_2 >> Pb_2 >> b_2;
        uint_fast16_t sub_b = is_balance(Pa_2, a_2, Pb_2, b_2);
        if (sub_a == -1 || sub_b == -1)  return -1;
        if (sub_a*a == sub_b*b) return sub_a + sub_b;
    }
    return 0;
}

int main() {
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);
    uint_fast16_t Pa, a, Pb, b;
    std::cin >> Pa >> a >> Pb >> b;
    while (Pa != 0 || Pb != 0 || a != 0 || b != 0) {
        if (is_balance(Pa, a, Pb, b) > 0) std::cout << "SI\n";
        else std::cout << "NO\n";
        std::cin >> Pa >> a >> Pb >> b;
    }
    return 0; 
}