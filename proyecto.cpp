#include <iostream>
#include <vector>
using namespace std;

int main(){
    int i, j;
    int turno = 1;
    void ganarX();
    void ganarO();
    void empate();
    vector<vector<char>> matriz(3, vector<char>(3,'-')); // MATRIZ ****NO MOVER****
    
    cout<< R"(  
       _____ ____  _____ ____    _____ _   _   ____      _ __   __ _     
      |_   _|  _ \| ____/ ___|  | ____| \ | | |  _ \    / \\ \ / // \    
        | | | |_) |  _| \___ \  |  _| |  \| | | |_) |  / _ \\ V // _ \   
        | | |  _ <| |___ ___) | | |___| |\  | |  _ <  / ___ \| |/ ___ \  
        |_| |_| \_\_____|____/  |_____|_| \_| |_| \_\/_/   \_\_/_/   \_\ 
      )" << endl;              
    cout<< "Las columnas van del 0-2"<<endl;
    cout<< "Las filas van del 0-2"<< endl;
    cout<< "Los '-' implican un espacio vacio"<< endl;
    cout<< "!BUENA SUERTE!"<<endl;
    cout<< "!QUE GANE EL MEJOR!"<<endl;  


    cout<< "          " << matriz[0][0]<<"          |          "<< matriz[0][1]<< "          |          "<< matriz[0][2]<<endl; // ║ ╬ ═
    cout<< "---------------------|---------------------|---------------------\n";
    cout<< "          " << matriz[1][0]<<"          |          "<< matriz[1][1]<< "          |          "<< matriz[1][2]<<endl;
    cout<< "---------------------|---------------------|---------------------\n";
    cout<< "          " << matriz[2][0]<<"          |          "<< matriz[2][1]<< "          |          "<< matriz[2][2]<<endl; 
    cout<< " " << endl;
    cout<< "Turno 1" << endl; 
    cout<< " " << endl;

    do{
        if (turno%2 == 0)
        {
            cout << "JUEGA O ----------\n";
            cout<< "Ingrese su fila: \n";
            cin >> i;
            cout << "Ingrese su columna: \n";
            cin >> j;
            turno++; // AUMENTA EL TURNO PARA SABER QUIEN JUEGA
            if (i < 0 || i > 2 || j < 0 || j > 2 || matriz[i][j] != '-')
            {
                cout << "Movimiento no valido, intente de nuevo\n";
                turno--; 
                continue;
            }
            matriz [i][j] = 'O';
        }
        else
        {
            cout << "JUEGA X ----------\n";
            cout<< "Ingrese su fila: \n";
            cin >> i;
            cout << "Ingrese su columna: \n";
            cin >> j;
            if (i < 0 || i > 2 || j < 0 || j > 2 || matriz[i][j] != '-')
            {
                cout << "Movimiento no valido, intente de nuevo\n";
                continue;
            }
            matriz [i][j] = 'X';
            turno++; // AUMENTA EL TURNO PARA SABER QUIEN JUEGA
        } // SI EL TURNO ES PAR JUEGA O SINO JUEGA X

        cout<< "          " << matriz[0][0]<<"          |          "<< matriz[0][1]<< "          |          "<< matriz[0][2]<<endl; // ║ ╬ ═
        cout<< "---------------------|---------------------|---------------------\n";
        cout<< "          " << matriz[1][0]<<"          |          "<< matriz[1][1]<< "          |          "<< matriz[1][2]<<endl;
        cout<< "---------------------|---------------------|---------------------\n";
        cout<< "          " << matriz[2][0]<<"          |          "<< matriz[2][1]<< "          |          "<< matriz[2][2]<<endl;
        cout << endl;
        cout << "Turno: " << turno << endl;
        cout<< " " << endl;
        
        if (turno == 10)
        {
            break;
        }
        
    }while(!((matriz[0][0] == matriz [0][1] && matriz[0][1] == matriz[0][2] && matriz[0][0] != '-') || // PRIMERA FILA
        (matriz[1][0] == matriz [1][1] && matriz[1][1] == matriz[1][2] && matriz[1][0] != '-') || // SEGUNDA FILA
        (matriz[2][0] == matriz [2][1] && matriz[2][1] == matriz[2][2] && matriz[2][0] != '-') || // TERCERA FILA
        (matriz[0][0] == matriz [1][0] && matriz[1][0] == matriz[2][0] && matriz[0][0] != '-') || // PRIMERA COLUMNA
        (matriz[0][1] == matriz [1][1] && matriz[1][1] == matriz[2][1] && matriz[0][1] != '-') || // SEGUNDA COLUMNA
        (matriz[0][2] == matriz [1][2] && matriz[1][2] == matriz[2][2] && matriz[0][2] != '-') || // TERCERA COLUMNA
        (matriz[0][0] == matriz [1][1] && matriz[1][1] == matriz[2][2] && matriz[0][0] != '-') ||// DIAGONAL PRINCIPAL
        (matriz[0][2] == matriz [1][1] && matriz[1][1] == matriz[2][0] && matriz[0][2] != '-')));// DIAGONAL SECUNDARIA

    if (turno < 10)
    { 
        if (turno%2 != 0) 
        {
            ganarO();
        }
        else if (turno%2 == 0) {
            ganarX();
        }
    }
    else if (turno == 10){
        if ((matriz[0][0] == matriz [0][1] && matriz[0][1] == matriz[0][2] && matriz[0][0] != '-') || // PRIMERA FILA
        (matriz[1][0] == matriz [1][1] && matriz[1][1] == matriz[1][2] && matriz[1][0] != '-') || // SEGUNDA FILA
        (matriz[2][0] == matriz [2][1] && matriz[2][1] == matriz[2][2] && matriz[2][0] != '-') || // TERCERA FILA
        (matriz[0][0] == matriz [1][0] && matriz[1][0] == matriz[2][0] && matriz[0][0] != '-') || // PRIMERA COLUMNA
        (matriz[0][1] == matriz [1][1] && matriz[1][1] == matriz[2][1] && matriz[0][1] != '-') || // SEGUNDA COLUMNA
        (matriz[0][2] == matriz [1][2] && matriz[1][2] == matriz[2][2] && matriz[0][2] != '-') || // TERCERA COLUMNA
        (matriz[0][0] == matriz [1][1] && matriz[1][1] == matriz[2][2] && matriz[0][0] != '-') ||// DIAGONAL PRINCIPAL
        (matriz[0][2] == matriz [1][1] && matriz[1][1] == matriz[2][0] && matriz[0][2] != '-'))
        {
            if (turno%2 != 0) 
            {
                ganarO();
            }
            else if (turno%2 == 0) {
                ganarX();
            }
        }
        else
        {
            empate();
        }
    }
    cout<<"ESTE JUEGO FUE PROGRAMADO POR: "<<endl;
    cout<<"-Federico Proanho"<<endl;
    cout<<"-Francis Alcarraz"<<endl;
    cout<<"-Josthin Moreira"<<endl;
    cout<<"-Jorge Shuguli" <<endl;
    return 0;    
}

void ganarX(){
    cout<< R"(
        ____    _    _   _    _      __  __ 
       / ___|  / \  | \ | |  / \     \ \/ / 
      | |  _  / _ \ |  \| | / _ \     \  /
      | |_| |/ ___ \| |\  |/ ___ \    /  \  
       \____/_/   \_\_| \_/_/   \_\  /_/\_\ 
    )" << endl;                            
}

void ganarO(){
    cout<< R"( 
        ____    _    _   _    _        ___   
       / ___|  / \  | \ | |  / \      / _ \  
      | |  _  / _ \ |  \| | / _ \    | | | | 
      | |_| |/ ___ \| |\  |/ ___ \   | |_| | 
       \____/_/   \_\_| \_/_/   \_\   \___/ 
    )" << endl;                                         
}    

void empate(){
 cout << R"(  
       _____ __  __ ____   _  _____ _____  
      | ____|  \/  |  _ \ / \|_   _| ____| 
      |  _| | |\/| | |_) / _ \ | | |  _|   
      | |___| |  | |  __/ ___ \| | | |___  
      |_____|_|  |_|_| /_/   \_\_| |_____| 
    )" << endl;                            
}

/*
                              __
                            .d$$b
                          .' TO$;\
                         /  : TP._;
                        / _.;  :Tb|
                       /   /   ;j$j
                   _.-"       d$$$$
                 .' ..       d$$$$;
                /  /P'      d$$$$P. |\
               /   "      .d$$$P' |\^"l
             .'           `T$P^"""""  :
         ._.'      _.'                ;
      `-.-".-'-' ._.       _.-"    .-"
    `.-" _____  ._              .-"
   -(.g$$$$$$$b.              .'
     ""^^T$$$P^)            .(:
       _/  -"  /.'         /:/;
    ._.'-'`-'  ")/         /;/;
 `-.-"..--""   " /         /  ;
.-" ..--""        -'          :
..--""--.-"         (\      .-(\
  ..--""              `-\(\/;`
    _.                      :
                            ;`-
                           :\  
                           | `-.
                           ;    XD*/