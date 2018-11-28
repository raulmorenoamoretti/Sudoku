
#include <iostream>
#include "sudoku_3.h"
#include "sudoku_2.h"
using namespace std;

int num;

int main() {

    sudoku_2 sudo2;

    sudoku_3 sudo3;

    cout<<"Elige un numero:\n 1. Dibuja Soduko 3x3,"
          "\n 2.Dibuja Soduko 2X2"
          "\n 3. Jugar sudoku 3X3"
          "\n 4. Jugar sudoku 2x2" << endl;
    cin>>num;

    if (num==1)
    {   sudo3.generar_sudoku();
        sudo3.ImprimirSudoku();
    }
    if (num==2)
    {   sudo2.generar_sudoku();
        sudo2.ImprimirSudoku();}
    if (num==3)
    {
        sudo3.Iniciar();
    }
    if (num==4)
    {
        sudo2.Iniciar();
    }
    return 0;}
