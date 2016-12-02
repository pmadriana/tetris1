#ifndef PIEZA_H
#define PIEZA_H
#include "Coordenadas.h"
#include <vector>
#include <cstdlib>
class Pieza
{
    int abc;
    Coordenadas *pivote;
public:
    Pieza();
    Pieza(std:: vector <Coordenadas> extremos);
    ~Pieza();
    Coordenadas *return_pivote();
    Coordenadas posicion(int n) ;
    void pieza_inicio(std:: vector <Coordenadas> extremos);
    void set_pivote(int a,int b);
    int getColor();
    void mover_abajo();
    void mover_derecha();
    void mover_izquierda();
    void rotar_derecha();
};





#endif // PIEZA_H

