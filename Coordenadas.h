#ifndef COORDENADAS_H
#define COORDENADAS_H
class Coordenadas
{
    int x, y;
public:
    Coordenadas();
    Coordenadas(int a, int b);
    ~Coordenadas();
    int getX();
    int getY();
    void setX(int a);
    void setY(int b);
    void aumentarY(int n);
    void aumentarX(int n);
};
#endif // COORDENADAS_H
