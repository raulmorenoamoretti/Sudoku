//
// Created by HP on 28/11/2018.
//

#include "sudoku_2.h"


sudoku_2::sudoku_2(){

    for(int i=0;i<4;i++){

        matriz[i]= new int[4];

    }

    for(int i=0;i<4;i++){

        for(int j=0;j<4;j++){

            matriz[i][j]= 0;

        }

    }



    //algunos valore
}

void sudoku_2::generar_sudokuPredeterminado(){

    matriz[1][2] = 1;
    matriz[2][0] = 4;
    matriz[3][1] = 2;
    matriz[3][3] = 3;





}
void sudoku_2::ImprimirSudoku(){
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout << " + ---";
        }
        cout << " +";
        cout << '\n';
        for (int j = 0; j < 4; j++) {
            cout << " |  " << matriz[i][j] << " ";
        }
        cout << " |";
        cout << '\n';
    }

    for (int j = 0; j < 4; j++) {
        cout << " + ---";
    }

    cout  << "\n";
}

void sudoku_2::generar_sudoku(){
    int valor;
    srand(time(NULL));
    for (int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            valor = 1 + rand()%4;
            if (ValorValido(valor,i,j)){
                matriz[i][j] = valor;
            }
        }
    }

}

void sudoku_2::IngresarDato(){
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

bool sudoku_2::ValorValido(int valor, int x,int y){

    bool valido = true;
    for (int i=0;i<4;i++ ){
        if (valor == matriz[x][i] and i!=y){
            valido =  false;
        }
    }

    for (int i=0;i<4;i++ ){
        if (valor == matriz[i][y] and i!=x){
            valido = false;
        }
    }

    int a = x/2 ;
    int b = y/2 ;

    for (int i=2*a ; i<2*(a+1);i++ ){
        for (int j=2*b ; j<2*(b+1);j++ )
        {
            if (matriz [i][j] == valor and (i!=x or j!=y) ){
                valido = false;
            }
        }
    }

    if (valor < 0 or valor >4){
        valido = false;
    }


    return valido;

}

bool sudoku_2::IsOver() {

    bool NotOver = false ;

    for (int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(matriz[i][j]==0){
                NotOver = true;
            }
        }
    }
    SudoOver = !NotOver;


    return SudoOver;
}

void sudoku_2::Iniciar(){
    generar_sudokuPredeterminado();
    ImprimirSudoku();
    while (!IsOver()){
        IngresarDato();
    }

    cout << "juego terminado";

}