#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;


struct Jugador { 
    string nombre; 
    char sim; 
    int vic; 
};

void guardarHistorial(string modo, Jugador j1, Jugador j2) {
    ofstream f("historial.txt", ios::app);
    if(f.is_open()) {
        f << modo << " | " << j1.nombre << "(" << j1.vic << ") vs " << j2.nombre << "(" << j2.vic << ")\n";
        f.close();
        cout << "-> Resultado guardado en historial.txt\n";
    }
}

void verHistorial() {
    ifstream f("historial.txt"); 
    string l;
    cout << "\n--- HISTORIAL ---\n";
    if (!f.is_open()) {
        cout << "No hay partidas registradas aun.\n";
    } else {
        while (getline(f, l)) {
            cout << l << "\n";
        }
        f.close();
    }
}

void verificarGanador(const vector<vector<char>>& b, char p, int &gano) {
    gano = 0; 
    for(int i=0; i<3; i++) {
        if(b[i][0]==p && b[i][1]==p && b[i][2]==p) gano = 1; 
        if(b[0][i]==p && b[1][i]==p && b[2][i]==p) gano = 1;
    }
    if(b[0][0]==p && b[1][1]==p && b[2][2]==p) gano = 1; 
    if(b[0][2]==p && b[1][1]==p && b[2][0]==p) gano = 1; 
}

void verificarLleno(const vector<vector<char>>& b, int &estaLleno) {
    estaLleno = 1; 
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            if(b[i][j] == '-') {
                estaLleno = 0; 
            }
        }
    }
}

void imprimirTablero(const vector<vector<char>>& b) {
    cout << "\n";
    for(int i=0; i<3; i++) {
        cout << "          " << b[i][0] << " | " << b[i][1] << " | " << b[i][2] << "\n";
        if(i < 2) cout << "         ---|---|---\n";
    }
    cout << "\n";
}

void mostrarArte(char s) {
    if(s == 'X') {
        cout << R"(
        ____    _    _   _    _      __  __ 
       / ___|  / \  | \ | |  / \     \ \/ / 
      | |  _  / _ \ |  \| | / _ \     \  /
      | |_| |/ ___ \| |\  |/ ___ \    /  \  
       \____/_/   \_\_| \_/_/   \_\  /_/\_\ 
    )" << endl;
    } else if(s == 'O') {
        cout << R"( 
        ____    _    _   _    _        ___   
       / ___|  / \  | \ | |  / \      / _ \  
      | |  _  / _ \ |  \| | / _ \    | | | | 
      | |_| |/ ___ \| |\  |/ ___ \   | |_| | 
       \____/_/   \_\_| \_/_/   \_\   \___/ 
    )" << endl;
    } else {
        cout << R"(  
       _____ __  __ ____   _  _____ _____  
      | ____|  \/  |  _ \ / \|_   _| ____| 
      |  _| | |\/| | |_) / _ \ | | |  _|   
      | |___| |  | |  __/ ___ \| | | |___  
      |_____|_|  |_|_| /_/   \_\_| |_____| 
    )" << endl;
    }
}


void jugarRonda(Jugador& j1, Jugador& j2, int turnoInicial, int vsPC, int &ganadorRonda) {
    vector<vector<char>> b(3, vector<char>(3, '-')); 
    int turno = turnoInicial; 
    int gano = 0;
    int lleno = 0;
    
    while(gano == 0 && lleno == 0) {
        imprimirTablero(b);
        Jugador act;
        if (turno % 2 != 0) act = j1;
        else act = j2;

        int f, c;

        if(turno % 2 == 0 && vsPC == 1) {
            do { 
                f = rand()%3; 
                c = rand()%3; 
            } while(b[f][c] != '-');
            cout << "PC juega en fila " << f << " y columna " << c << "\n";
        } else {
            cout << act.nombre << " (" << act.sim << "), ingresa fila y columna (0-2): ";
            cin >> f >> c;
            if(f<0 || f>2 || c<0 || c>2 || b[f][c] != '-') { 
                cout << "Movimiento no valido, intente de nuevo\n"; 
                continue; 
            }
        }

        b[f][c] = act.sim;
        
        
        verificarGanador(b, act.sim, gano);
        if(gano == 1) { 
            imprimirTablero(b); 
            cout << "¡Gana " << act.nombre << "!\n"; 
            if (turno % 2 != 0) ganadorRonda = 1;
            else ganadorRonda = 2;
            return;
        }
        
        verificarLleno(b, lleno);
        if(lleno == 1) { 
            imprimirTablero(b); 
            cout << "¡Empate!\n"; 
            ganadorRonda = 0; 
            return;
        }
        
        turno++;
    }
}

void modoNormal(int vsPC) {
    Jugador j1 = {"", 'X', 0};
    Jugador j2 = {"", 'O', 0};
    
    if (vsPC == 1) j2.nombre = "PC";
    
    cout << "Ingrese nombre P1: "; cin >> j1.nombre;
    if(vsPC == 0) { 
        cout << "Ingrese nombre P2: "; 
        cin >> j2.nombre; 
    }
    
    
    int turnoInicial = (rand() % 2 == 0) ? 1 : 2; 
    int maxRondas = (vsPC == 1) ? 1 : 2; 

    while(j1.vic < maxRondas && j2.vic < maxRondas) {
        cout << "\nMarcador: " << j1.vic << " - " << j2.vic << "\n";
        int ganadorRonda = 0;
        
        jugarRonda(j1, j2, turnoInicial, vsPC, ganadorRonda);
        
        if(ganadorRonda == 1) j1.vic++; 
        else if(ganadorRonda == 2) j2.vic++;
        
        turnoInicial++;
        if (vsPC == 1) break;
    }
    
    if (j1.vic > j2.vic) mostrarArte('X');
    else if (j2.vic > j1.vic) mostrarArte('O');
    else mostrarArte('-');
    
    if (vsPC == 1) guardarHistorial("VsPC", j1, j2);
    else guardarHistorial("1vs1", j1, j2);
}

void modoUltimate() {
    Jugador j1 = {"P1", 'X', 0};
    Jugador j2 = {"P2", 'O', 0};
    vector<vector<char>> G(3, vector<char>(3, '-')); 
    vector<vector<char>> L[3][3];                    
    
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            L[i][j] = vector<vector<char>>(3, vector<char>(3, '-'));
        }
    }

    int tActF = -1, tActC = -1; 
    int turno = 1;
    int juegoTerminado = 0;

    while(juegoTerminado == 0) {
        cout << "\n";
        for(int r=0; r<9; r++) {
            for(int c=0; c<9; c++) {
                int gF = r/3, gC = c/3, lF = r%3, lC = c%3;
                if (G[gF][gC] != '-') cout << " " << G[gF][gC] << " ";
                else cout << " " << L[gF][gC][lF][lC] << " ";
                if (c%3==2) cout << "|";
            }
            if (r%3==2 && r<8) cout << "\n----------------------------\n";
            else cout << "\n";
        }

        Jugador act;
        if (turno % 2 != 0) act = j1; else act = j2;
        
        int gF = tActF, gC = tActC, lF, lC;

        if(tActF == -1) {
            cout << act.nombre << " (" << act.sim << "), elige macro-tablero libre (fila col 0-2): "; 
            cin >> gF >> gC;
            if(gF<0 || gF>2 || gC<0 || gC>2 || G[gF][gC] != '-') { 
                cout << "Invalido.\n"; 
                continue; 
            }
        }

        cout << act.nombre << " juega en macro-tablero (" << gF << "," << gC << "). Casilla local (fila col 0-2): "; 
        cin >> lF >> lC;
        if(lF<0 || lF>2 || lC<0 || lC>2 || L[gF][gC][lF][lC] != '-') { 
            cout << "Invalido.\n"; 
            continue; 
        }

        L[gF][gC][lF][lC] = act.sim;
        
        int ganoLocal = 0;
        verificarGanador(L[gF][gC], act.sim, ganoLocal);
        
        if(ganoLocal == 1) {
            G[gF][gC] = act.sim;
            cout << "¡" << act.nombre << " conquista el tablero (" << gF << "," << gC << ")!\n";
            
            int ganoGlobal = 0;
            verificarGanador(G, act.sim, ganoGlobal);
            
            if(ganoGlobal == 1) {
                mostrarArte(act.sim); 
                act.vic++;
                guardarHistorial("Ultimate", j1, j2); 
                juegoTerminado = 1;
                continue;
            }
        }
        
        int estaLleno = 0;
        verificarLleno(L[lF][lC], estaLleno);
        
        if(G[lF][lC] != '-' || estaLleno == 1) { 
            tActF = -1; 
            tActC = -1; 
        } else { 
            tActF = lF; 
            tActC = lC; 
        }
        
        turno++;
    }
}


int main() {
    srand(time(0));
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
        
        if(op == 1) modoNormal(0);      // 0 significa que NO es vs PC
        else if(op == 2) modoUltimate();
        else if(op == 3) modoNormal(1); // 1 significa que SI es vs PC
        else if(op == 4) verHistorial();
        
    } while(op != 5);
    
    return 0;
}
