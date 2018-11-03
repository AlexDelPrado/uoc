/* Ejercicio AA2/b de Fundamentos de Programacion
por Alex Del Prado - DAM abril 18 */

#include <stdio.h>


//Definicion de tipo
typedef enum {false, true} bool;

//Predeclaracion de funciones
void buscapareja1 (int n, int *a, int *b);
void buscapareja2 (int n, int a, int *b);
bool pitagoricos (int h, int c1, int c2);


int main(){

    int hipo, cmenor, cmayor;

    scanf("%d", &hipo); // Escaneamos entero

    //inicamos bucle
    while (hipo != 0){ // La marca es 0
        buscapareja1(hipo,&cmenor,&cmayor);
        if (pitagoricos(hipo,cmenor,cmayor)){
            printf("%d ", hipo);
            printf("%d ", cmayor);
            printf("%d\n", cmenor);
        }
        scanf("%d", &hipo);
    }
    return 0;
}
void buscapareja1 (int n, int *a, int *b){
    bool encontrado;
    *a=1;
    *b=1;
    encontrado = false;
    while (*a<n && !encontrado){
        buscapareja2(n,*a,b);
        encontrado=pitagoricos(n,*a,*b);
        if (!encontrado){
            ++*a;
        }
    }
}
void buscapareja2 (int n, int a, int *b){
    bool encontrado;
    *b=1;
    encontrado = false;
    while (*b<n && !encontrado){
        encontrado=pitagoricos(n,a,*b);
        if (!encontrado){
            ++*b;
        }
    }
}
bool pitagoricos (int h, int c1, int c2){
    return h*h==c1*c1+c2*c2;
}
