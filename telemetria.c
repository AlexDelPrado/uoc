#include <stdio.h>

int main(){
    
    //Declaramos las variables
    int t, n;
    float i, suma_i, media;

    scanf("%d", &t); // iniciamos lectura de segundos
    scanf("%f", &i); // iniciamos lectura de metros

    n = 1; // iniciamos en uno el indice
    suma_i = i; // le damos a suma_i el primer valor indicado en el scanf

    // iniciamos bucle
    while (t != -1){ // -1 es la marca que indica final de secuencia
        scanf("%d", &t); // volvemos a leer los segundos
        if ( t != -1){ // si t no es igual a -1 leemos los metros
            scanf("%f", &i);
            suma_i = suma_i + i;
            n = n + 1; 
        } 
    }
    media = suma_i / n;
    printf("Fin secuencia. La media es %f", media);
}
