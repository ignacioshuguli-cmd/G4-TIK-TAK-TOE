#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Jugador { string nombre; char sim; int vic; };

void verificarGanador(const vector<vector<char>>& b, char p, int &gano) {
    gano = 0; 
    for(int i=0; i<3; i++) {
        if(b[i][0]==p && b[i][1]==p && b[i][2]==p) gano = 1; 
        if(b[0][i]==p && b[1][i]==p && b[2][i]==p) gano = 1;
    }
    if(b[0][0]==p && b[1][1]==p && b[2][2]==p) gano = 1; 
    if(b[0][2]==p && b[1][1]==p && b[2][0]==p) gano = 1; 
}

void imprimirTablero(const vector<vector<char>>& b) {
    cout << "\n";
    for(int i=0; i<3; i++) {
        cout << "          " << b[i][0] << " | " << b[i][1] << " | " << b[i][2] << "\n";
        if(i < 2) cout << "         ---|---|---\n";
    }
    cout << "\n";
}

int main() {
    int op;
    do {
        cout << "\n--- TIC TAC TOE ---\n";
        cout << "1. 1vs1 (Mejor de 3)\n";
        cout << "5. Salir\n";
        cout << "Opcion: ";
        cin >> op;
        if(op == 1) cout << "Iniciando logica del tablero...\n";
    } while(op != 5);
    return 0;
}
