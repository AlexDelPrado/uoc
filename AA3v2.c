#include <stdio.h>

/*Declaracion de constantes*/
#define NUMVOCALES 5
#define FINSEC '.'

/*Declaracion de tipos*/
typedef enum {false, true} bool; /*Declaracion tipo booleano*/
typedef struct{
    char vocal;
    int numVeces;
}tFrecUnaVocal;

typedef struct{
    tFrecUnaVocal frecuencias[NUMVOCALES];
    int nVocales;
}tFrecVocales;

/*Predeclaracion de funciones*/
void inicilizarFrecuencias(tFrecVocales *frecVocales);
void procesarCaracter(char c, tFrecVocales *frecVocales);
bool esVocal(char c);
void mostrarResultado(tFrecVocales frecVocales);
int cuentaVocales(tFrecVocales frecVocales);

/*En el canal estandar de entrada hay una secuencia de caracteres
terminada por un '.' */
int main(){

    tFrecVocales frecVocales;
    char car;

    inicilizarFrecuencias(&frecVocales);
    scanf(" %c", &car);
    while (car != FINSEC){
        procesarCaracter(car, &frecVocales);
        scanf(" %c", &car);
    }
    mostrarResultado(frecVocales);
    return 0;
}

void inicilizarFrecuencias(tFrecVocales *frecVocales){
    frecVocales->nVocales=0;
}

void procesarCaracter(char c, tFrecVocales *frecVocales){
    int i;
    bool encontrado;

    if (esVocal(c)){
        encontrado = false;
        i = 0;
        while ((i < frecVocales->nVocales) && !encontrado){
            encontrado = c == frecVocales->frecuencias[i].vocal;
            if (!encontrado){
                i++;
            }
        }
        if (!encontrado){
            frecVocales->frecuencias[frecVocales->nVocales].vocal = c;
            frecVocales->frecuencias[frecVocales->nVocales].numVeces = 1;
            frecVocales->nVocales = frecVocales->nVocales + 1;
        }else{
            frecVocales->frecuencias[i].numVeces = frecVocales->frecuencias[i].numVeces + 1;
        }
    }
}

bool esVocal(char c){
    return ( c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

void mostrarResultado(const tFrecVocales frecVocales){
    int i, totalVocales;

    totalVocales = cuentaVocales(frecVocales);
    printf("Total de vocales introducidas: %d\n", totalVocales);
    for(i=0;i<frecVocales.nVocales;i++){
        if (totalVocales != 0){
            printf("El %% de aparicion de la %c es del %d", frecVocales.frecuencias[i].vocal, (frecVocales.frecuencias[i].numVeces * 100)/totalVocales);
        }else{
            printf("%d", 0);
        }
        printf("%c\n", '%');
    }
}

int cuentaVocales(tFrecVocales frecVocales){
    int total, i;

    total = 0;
    for(i=0;i<frecVocales.nVocales;i++){
        total = total + frecVocales.frecuencias[i].numVeces;
    }
    return total;
}
