#include "Pieza.h"
Pieza::Pieza(){}
Pieza::Pieza(std:: vector <Coordenadas> extremos)
{
    abc = 1 + rand()%6;
    pivote = new Coordenadas[4];
    pivote->setX(5);
    pivote->setY(1);
    for(int i = 1; i < 4; i++)
    {
        pivote[i] = extremos[i-1];
    }
}
Pieza::~Pieza()
{
    delete[] pivote;
}
Coordenadas* Pieza::return_pivote()
{
    return pivote;
}
Coordenadas Pieza::posicion(int n)
{
    Coordenadas temp(pivote->getX(), pivote->getY());
    if(n != 0)
    {
        temp.aumentarX(pivote[n].getX());
        temp.aumentarY(pivote[n].getY());
    }
    return temp;
}

void Pieza::set_pivote(int a,int b)
{
    pivote->setX(a);
    pivote->setY(b);
}
int Pieza::getColor()
{
    return abc;
}
 void Pieza::mover_abajo()
{
    pivote->aumentarY(1);
}
void Pieza::mover_derecha()
{
    pivote->aumentarX(1);
}
void Pieza::mover_izquierda()
{
    pivote->aumentarX(-1);
}
void Pieza::rotar_derecha()
{
    for(int i = 1; i < 4; i++){
            int n = pivote[i].getX();
            int m = pivote[i].getY();
            pivote[i].setX(-m);
            pivote[i].setY(n);
        }
}

void Pieza::pieza_inicio(std::vector <Coordenadas> extremos) // papu
{
    pivote = new Coordenadas[4];
    pivote->setX(13);
    pivote->setY(2);
    abc = 1 + rand()%6;
    for(int i = 1; i < 4; i++)
    {
        pivote[i] = extremos[i-1];
    }
}
