#include <iostream>
#include <conio.h> // Biblioteca para capturar teclas pressionadas

int main() {
    char tecla;

    do {
        tecla = getch(); // Captura a tecla pressionada
        if (tecla == 72) { // C�digo ASCII da seta para cima
            std::cout << "Seta para cima pressionada" << std::endl;
        } else if (tecla == 80) { // C�digo ASCII da seta para baixo
            std::cout << "Seta para baixo pressionada" << std::endl;
        }
    } while (tecla != 13); // Encerra o loop quando a tecla ESC � pressionada

    return 0;
}






