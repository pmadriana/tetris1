#include "miniwin.h"
#include <time.h>
#include <sstream>
#include <vector>
#include <cstdlib>
#include "Coordenadas.h"
#include "Pieza.h"
using namespace std;
using namespace miniwin;
typedef const int Tipo;
Tipo TAM = 25;
Tipo FILAS = 20;
Tipo COLUMNAS = 10;
Tipo puntos_nivel[10] = {5,20,30,40,50,60,70,80,90,100};
Tipo rapidez[10] = {33,25,20,15,12,9,7,5,2,1};
typedef int Tablero[COLUMNAS][FILAS];
void cuadrado(int x, int y){
    rectangulo_lleno(20+ 1 + x * TAM,
                     20+ 1 + y * TAM, //LE SUMAMOS 20 PARA ACOMODAR
                     20+ x * TAM + TAM,
                     20+ y * TAM + TAM);
}
void pintar(Pieza &P)
{
        color(P.getColor());
        for(int i = 0; i < 4; i++){
            Coordenadas c = P.posicion(i);
            cuadrado(c.getX(), c.getY());
    }
}
Coordenadas extremos[7][3] = {
    {{1,0}  , {0,1}  , {1,1}  },
    {{1,0}  , {-1,1} , {0,1}  },
    {{0,1}  , {1,1}  , {-1,0} },
    {{0,1}  , {0,-1} , {1,1}  },
    {{0,1}  , {0,-1} , {-1,1} },
    {{0,1}  , {0,-1} , {0,2}  },
    {{-1,0} , {1,0}  , {0,1}  }
};
std::vector <Coordenadas> pieza_aleatoria(){
    std::vector <Coordenadas> temp;
    int aleatorio = rand() % 7;
    for(int i = 0; i < 3; i++){
        temp.push_back(extremos[aleatorio][i]);
    }
    return temp;
}

void tablero_vacio(Tablero &T){
    for(int i=0; i < COLUMNAS; i++){
        for(int j=0; j < FILAS; j++){
            T[i][j] = NEGRO; //Casilla vacia
        }
    }
}

void tablero_lleno(const Tablero &T){ //tablero pinta
    for(int i=0; i < COLUMNAS; i++){
        for(int j=0; j < FILAS; j++){
            color(T[i][j]); //Casilla vacia
            cuadrado(i, j);
        }
    }
}

void tablero_fijar(Tablero &T, Pieza &P){
    for(int i = 0; i < 4; i++){
        Coordenadas c = P.posicion(i);
        T[c.getX()][c.getY()] = P.getColor();
    }
}
bool tablero_conflicto(const Tablero &T, Pieza &P){
    for(int i = 0; i < 4; i++){
        Coordenadas c = P.posicion(i);
        if(c.getX() < 0 || c.getX() >= COLUMNAS){
            return true;}
        if(c.getY() < 0 || c.getY() >= FILAS){
            return true;}
        if(T[c.getX()][c.getY()] != NEGRO){
            return true;}
    }
    return false;
}
bool tablero_filallena(Tablero &T, int fila){ //pa q
        for(int i = 0; i < COLUMNAS; i++){
            if(T[i][fila] == NEGRO)
                return false;
        }
}
void tablero_colapsa(Tablero &T, int fila){
    for(int j = fila; j > 0; j--){
        for(int i = 0; i < COLUMNAS; i++){
            T[i][j] = T[i][j-1];
        }
    }
    for(int i = 0; i < COLUMNAS; i++){
        T[i][0] = NEGRO;
    }
}
int tablero_cuentalineas(Tablero &T){
    int fila = FILAS-1;
    int cont = 0;
    while(fila>=0){
        if(tablero_filallena(T, fila)){
            tablero_colapsa(T, fila);
            cont++;
        }
        else
            fila--;
    }
    return cont;
}
string convertir(int a)
{
    stringstream sout;
    sout << a;
    return sout.str();
}
void repinta(const Tablero &T, Pieza &P, Pieza &sig, int puntos, int nivel)
{
    const int ancho = TAM*COLUMNAS;
    const int alto = TAM*FILAS;
    borra();
    tablero_lleno(T);
    color(BLANCO);
    linea(20,20,20, 20+alto);
    linea(20, 20+alto, 20+ancho, 20+alto);
    linea(20+ancho, 20+alto, 20+ancho, 20);
    texto(60 + ancho, 20, "Pieza Siguiente");
    texto(60 + ancho, 170, "Nivel");
    texto(60 + ancho, 320, "Puntaje");
    texto(60 + ancho, 370, convertir(puntos));
    texto(60 + ancho, 220, convertir(nivel+1));
    pintar(P);
    pintar(sig);
    refresca();
}
void gameover(int &nivel){
    color(BLANCO);
    texto(120,240,"GAME OVER");
    refresca();
    if(nivel<=5){
        color(BLANCO);
        texto(100,260,"Puedes hacerlo mejor");
        refresca();
    }
    if(nivel>5 && nivel!=11){
        color(BLANCO);
        texto(120,260,"BIEN HECHO");
        refresca();
    }
    espera(3000);
    vcierra();
}

void ganaste(){
    color(BLANCO);
    texto(140,240,"FELICITACIONES");
    texto(90,260,"PASASTE TODOS LOS NIVELES");
    refresca();
    espera(3000);
    vcierra();
}


int main()
{
    vredimensiona(TAM * COLUMNAS + 220, TAM * FILAS + 100);
    srand(time(NULL)); //inizializar los numeros al azar

    int ticks=0, puntos=0, nivel =0;

    Tablero T;
    tablero_vacio(T);
    //T[0][19]=VERDE;
    tablero_lleno(T);
    Pieza sig(pieza_aleatoria());
    Pieza z(pieza_aleatoria());
    z.set_pivote(5,2);
    sig.set_pivote(13,2);
    pintar(z);
    repinta(T,z, sig, puntos, nivel);
    int t = tecla();
    while(t != ESCAPE){
        int x=z.return_pivote()->getX();
        int y= z.return_pivote()->getY();
        if(t == NINGUNA && ticks > rapidez[nivel]){
            ticks=0;
            t = ABAJO;
        }
        if(t == ABAJO){
            z.mover_abajo();
        }
        if(t == IZQUIERDA){
            z.mover_izquierda();
        }
        if(t == DERECHA){
            z.mover_derecha();
        }
        if(t== ARRIBA)
        {
            z.rotar_derecha();
        }
        if(t == 'N')
            nivel++;

        if(tablero_conflicto(T,z)){
            z.set_pivote(x, y);
            if(t == ABAJO){
                tablero_fijar(T, z);
                int cont = tablero_cuentalineas(T);
                puntos += cont;
                if(puntos > puntos_nivel[nivel])
                    nivel++;

                z = sig;
                sig.pieza_inicio(pieza_aleatoria());
                z.set_pivote(5,2);

                if(nivel==10)
                    ganaste();
                if(tablero_conflicto(T,z)){
                    gameover(nivel);}


            }
        }

        if(t != NINGUNA){
            repinta(T,z, sig, puntos, nivel);
        }
        espera(30);
        ticks++;
        t = tecla();
    }
    vcierra();
    return 0;
}
