//
// Created by HP on 28/11/2018.
//

#ifndef SUDO_F_SUDOKU_2_H
#define SUDO_F_SUDOKU_2_H

#include <time.h>
#include <cstdlib>
#include <iostream>
using namespace std;
class sudoku_2 {
public:
    int* matriz[6] ;
    bool SudoOver = false;

    sudoku_2();

    bool IsOver();
    void ImprimirSudoku();

    void generar_sudoku();
    void generar_sudokuPredeterminado();
    void IngresarDato();

    bool ValorValido(int valor, int x,int y);

    void Iniciar();

};


#endif //SUDO_F_SUDOKU_2_H
