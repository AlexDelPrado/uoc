/* Ejercicio AA2/a de Fundamentos de Programacion
por Alex Del Prado - DAM abril 18 */

#include <stdio.h>

typedef enum {false, true} bool;

int main(){

    //Declaramos las variables
    int n;
    int t, t_max, t_min;
    float i, i_suma, i_next, i_min, i_max;
    float media;
    bool inco;

    scanf("%d", &t); // iniciamos lectura de segundos
    scanf("%f", &i); // iniciamos lectura de metros

    // Inicializamos las varibles
    n = 1; // iniciamos en uno el indice
    t_max = t;
    t_min = t;
    i_suma = i;
    i_next = i;
    i_min = i;
    i_max = i;
    inco = false;

    // iniciamos bucle
    while (t != -1) { // -1 es la marca que indica final de secuencia
        scanf("%d", &t); // volvemos a leer los segundos
        if ( t != -1){ // si t no es igual a -1 leemos los metros
            scanf("%f", &i);
            if (i > i_max){
                i_max = i;
                t_max = t;
            }
            if (i < i_min){
                i_min = i;
                t_min = t;
            }
            i_suma+=i;
            ++n;
            if ((i_next / i) < 0.80 || (i_next / i) > 1.25){
                inco = true;
            }
            i_next = i;
        }
    }
    if (inco){
        printf("%d %.1f %d %.1f", t_max, i_max, t_min, i_min);
    } else {
        media = i_suma / n;
        printf("%.5f", media);
    }
}
