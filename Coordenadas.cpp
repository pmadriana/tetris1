#include "Coordenadas.h"
Coordenadas::Coordenadas()
{
    x=0;
    y=0;
}
Coordenadas::Coordenadas(int a, int b)
{
    x=a;
    y=b;
}
Coordenadas::~Coordenadas(){}
int Coordenadas::getX()
{
    return x;
}
int Coordenadas::getY()
{
    return y;
}
void Coordenadas::setX(int a)
{
    x = a;
}
void Coordenadas::setY(int b)
{
    y = b;
}
void Coordenadas::aumentarY(int n)
{
    y += n;
}
void Coordenadas::aumentarX(int n)
{
    x += n;
}
