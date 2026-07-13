#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Jugador { 
    string nombre; 
    char sim; 
    int vic; 
};

int main() {
    int op;
    do {
        cout << "\n--- TIC TAC TOE ---\n";
        cout << "1. 1vs1 (Mejor de 3)\n";
        cout << "2. Ultimate TTT\n";
        cout << "3. vs PC (Facil)\n";
        cout << "4. Historial\n";
        cout << "5. Salir\n";
        cout << "Opcion: ";
        cin >> op;
    } while(op != 5);
    
    return 0;
}
