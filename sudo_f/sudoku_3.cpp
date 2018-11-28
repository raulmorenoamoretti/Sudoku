//
// Created by HP on 28/11/2018.
//

#include "sudoku_3.h"
sudoku_3::sudoku_3(){

    for(int i=0;i<9;i++){

        matriz[i]= new int[9];

    }

    for(int i=0;i<9;i++){

        for(int j=0;j<9;j++){

            matriz[i][j]= 0;

        }

    }



    //algunos valore
}
void sudoku_3::ImprimirSudoku(){
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << " + ---";
        }
        cout << " +";
        cout << '\n';
        for (int j = 0; j < 9; j++) {
            cout << " |  " << matriz[i][j] << " ";
        }
        cout << " |";
        cout << '\n';
    }

    for (int j = 0; j < 9; j++) {
        cout << " + ---";
    }

    cout  << "\n";
}

void sudoku_3::generar_sudoku(){
    int valor;
    srand(time(NULL));
    for (int i=0;i<9;i++){
        for(int j=0;j<9;j++){

            valor = 1 + rand()%9;
            if (ValorValido(valor,i,j)){
                matriz[i][j] = valor;
            }
        }
    }

}

void sudoku_3::generar_sudokuPredeterminado(){

    matriz[0][0] = 5;
    matriz[0][1] = 3;
    matriz[0][4] = 7;
    matriz[1][0] = 6;
    matriz[1][3] = 1;
    matriz[1][4] = 9;
    matriz[1][5] = 5;
    matriz[2][1] = 9;
    matriz[2][2] = 8;
    matriz[2][7] = 6;
    matriz[3][0] = 8;
    matriz[3][4] = 6;
    matriz[3][8] = 3;
    matriz[4][0] = 4;
    matriz[4][3] = 8;
    matriz[4][5] = 3;
    matriz[4][8] = 1;
    matriz[5][0] = 7;
    matriz[5][4] = 2;
    matriz[5][8] = 6;
    matriz[6][1] = 6;
    matriz[6][6] = 2;
    matriz[6][7] = 8;
    matriz[7][3] = 4;
    matriz[7][4] = 1;
    matriz[7][5] = 9;
    matriz[7][8] = 5;
    matriz[8][4] = 8;
    matriz[8][7] = 7;
    matriz[8][8] = 9;





}


bool sudoku_3::IsOver() {

    bool NotOver = false ;

    for (int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(matriz[i][j]==0){
                NotOver = true;
            }
        }
    }
    SudoOver = !NotOver;


    return SudoOver;
}

void sudoku_3::IngresarDato(){
    int i,j,valor;
    std::cout << "\ningresa fila : " ;
    std::cin >> i ; std::cout << "\n";
    std::cout << "ingresa columna : " ;
    std::cin >> j;  std::cout << "\n";

    std::cout << "ingresa valor : " ;
    std::cin >> valor;  std::cout << "\n";
    if (ValorValido(valor,i-1,j-1)){
        matriz[i-1][j-1] = valor;
        ImprimirSudoku();
    } else{
        ImprimirSudoku();
        cout << "valor no valido\n";
    }



}

bool sudoku_3::ValorValido(int valor, int x,int y){

    bool valido = true;
    for (int i=0;i<9;i++ ){
        if (valor == matriz[x][i] and i!=y){
            valido =  false;
        }
    }

    for (int i=0;i<9;i++ ){
        if (valor == matriz[i][y] and i!=x){
            valido = false;
        }
    }

    int a = x/3 ;
    int b = y/3 ;

    for (int i=3*a ; i<3*(a+1);i++ ){
        for (int j=3*b ; j<3*(b+1);j++ )
        {
            if (matriz [i][j] == valor and (i!=x or j!=y) ){
                valido = false;
            }
        }
    }

    if (valor < 0 or valor >9){
        valido = false;
    }


    return valido;

}

void sudoku_3::Iniciar(){
    generar_sudokuPredeterminado();
    ImprimirSudoku();
    while (!IsOver()){
        IngresarDato();
    }

    cout << "juego terminado";

}