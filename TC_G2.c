#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Definiciones
#define a 10
#define b 4

// Prototipos de las funciones
void notaFinal(float notas[a][b],int aPonderacion[b]);
void maxMinMedia(float notas[a][b]);
void listPruebasNotas(float notas[a][b]);
void cambiarPonderacion(int arrayPonderaciones[b]);

// Funcion main
void main() {
    // Declaracion de las variables
    float aNotas[a][b];
    int seleccion;
    int aPonderacion[b] = {25, 25, 25, 25};



    // Insercion de las notas
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            do {
                printf("Introduzca la nota %d del alumno %d: ", j + 1, i + 1);
                scanf("%f", &aNotas[i][j]);

                if (aNotas[i][j] < 0 ||aNotas[i][j] > 10) {
                    printf("El valor de la nota debe estar entre 0 y 10\n");
                }
                
            } while(aNotas[i][j] < 0 || aNotas[i][j] > 10);
        }
    }

    do {
        // Muestra por pantalla de las distintas opciones
        printf("\n--- MENU DE SELECCION ---\n1- Nota final por alumno\n2- Notas maxima, minima y media por prueba\n3- Listado de pruebas y notas\n4- Modificacion de ponderacion de notas\n5- Salir del programa\n");
        scanf("%d", &seleccion);

        // Switch de seleccion de las diferentes opciones
        switch(seleccion) {
        case 1:
            notaFinal(aNotas, aPonderacion);
            break;
        
        case 2:
            maxMinMedia(aNotas);
            break;

        case 3:
            listPruebasNotas(aNotas);
            break;

        case 4:
            cambiarPonderacion(aPonderacion);
            break;
        case 5:
            break;
        default:
            printf("La opcion seleccionada no es valida");
            break;
        }
    } while(seleccion != 5);
}

void notaFinal(float notas[a][b], int aPonderacion[b]) {
    float suma = 0;

    for(int i = 0; i < a; i++) {
        for(int j = 0; j < b; j++) {
            suma = suma + (notas[i][j] * (aPonderacion[j] / 100));
        }
        printf("\nLa media del alumno %d es: %.2f", i + 1, (suma));
        suma = 0;
    }
}

void maxMinMedia(float notas[a][b]) {
    float max = 0, min = 0, suma = 0;

    for(int i = 0; i < b; i++) {
        min = notas[0][i];
        max = 0;
        for(int j = 0; j < a; j++) {
            suma = suma + notas[j][i];

            if(notas[j][i] > max) {
                max = notas[j][i];
            }

            if(notas[j][i] < min) {
                min = notas[j][i];
            }
        }
        printf("\nLa media de la asignatura %d es: %.2f", i + 1, (suma / a));
        printf("\nLa nota maxima de la asignatura %d es: %.2f", i + 1, max);
        printf("\nLa nota minima de la asignatura %d es: %.2f", i + 1, min);

        max = 0;
        min = 0;
        suma = 0;
    }
}

void listPruebasNotas(float notas[a][b]) {
    int aprobados = 0;

    for(int i = 0; i < b; i++) {
        printf("Listado de notas de la prueba %d", i + 1);
        for(int j = 0; j < a; j++) {
            printf("\nAlumno %d: %.2f", j + 1, notas[j][i]);
            if(notas[j][i] >= 5) {
                aprobados++;
            }
        }
        printf("\nEl numero de aprobados en la prueba %d es de %d", i + 1, aprobados);
        printf("\nEl numero de suspensos en la prueba %d es de %d", i + 1, a - aprobados);
        printf("\n");

        aprobados = 0;
    }
}


//Metodo para cambiar la ponderacion con los valores introducidos por el usuario
void cambiarPonderacion(int arrayPonderaciones[]) {

    do {
        printf("Introduzca las nuevas ponderacion (entre 10 y 60)\n");
        scanf("%d %d %d %d", &arrayPonderaciones[0], &arrayPonderaciones[1], &arrayPonderaciones[2], &arrayPonderaciones[3]);

        if ( //comprobacion de valor entre 10 y 60
            arrayPonderaciones[0] < 10 || arrayPonderaciones[0] > 60 ||
            arrayPonderaciones[1] < 10 || arrayPonderaciones[1] > 60 ||
            arrayPonderaciones[2] < 10 || arrayPonderaciones[2] > 60 ||
            arrayPonderaciones[3] < 10 || arrayPonderaciones[3] > 60
        ) {
            printf("La ponderacion introducida no es valida\n");
        } else if (arrayPonderaciones[0] + arrayPonderaciones[1] + arrayPonderaciones[2] + arrayPonderaciones[3] != 100) { //comprobar que la suma de ponderaciones sea 100
            printf("La suma de las ponderaciones no es valida\n");
        }

    } while (//bucle para comprobar que el valor de ponderaciones esta entre 10 y 60 y su suma da 100
        arrayPonderaciones[0] < 10 || arrayPonderaciones[0] > 60 ||
        arrayPonderaciones[1] < 10 || arrayPonderaciones[1] > 60 ||
        arrayPonderaciones[2] < 10 || arrayPonderaciones[2] > 60 ||
        arrayPonderaciones[3] < 10 || arrayPonderaciones[3] > 60 ||
        (arrayPonderaciones[0] + arrayPonderaciones[1] + arrayPonderaciones[2] + arrayPonderaciones[3] != 100)
    );
    
}