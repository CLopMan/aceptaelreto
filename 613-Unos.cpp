#include <iostream>

int unos(int base) {
	int unos = 0;
	int resto = 0;
	int dividendo = 1;

	do {
		++unos;
		resto = dividendo % base;
		dividendo = resto * 10 + 1;
	} while(resto != 0); 
	
	return unos;
}

int main() {
	std::cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);
	int input;
	while(std::cin >> input) {
		std::cout << unos(input) << '\n';
	}
}