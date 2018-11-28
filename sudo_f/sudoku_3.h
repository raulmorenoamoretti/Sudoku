//
// Created by HP on 28/11/2018.
//

#ifndef SUDO_F_SUDOKU_3_H
#define SUDO_F_SUDOKU_3_H


#include <time.h>
#include <cstdlib>
#include <iostream>
using namespace std;

class sudoku_3 {


public:
    int* matriz[9] ;
    bool SudoOver = false;

    sudoku_3();
    void ImprimirSudoku();

    void generar_sudoku();

    void IngresarDato();

    bool ValorValido(int valor, int x,int y);

    void generar_sudokuPredeterminado();

    void Iniciar();

    bool IsOver();
};




#endif //SUDO_F_SUDOKU_3_H
