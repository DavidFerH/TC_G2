#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Definiciones
#define a 10
#define b 4

// Prototipos de las funciones
void notaFinal(float notas[a][b]);
void maxMinMedia(float notas[a][b]);

// Funcion main
void main() {
    // Declaracion de las variables
    float aNotas[a][b];
    int seleccion;

    // Insercion de las notas
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 4; j++) {
            printf("Introduzca la nota %d del alumno %d: ", j + 1, i + 1);
            scanf("%f", &aNotas[i][j]);
        }
    }

    // Muestra por pantalla de las distintas opciones
    printf("\n--- MENU DE SELECCION ---\n1- Nota final por alumno\n2- Notas maxima, minima y media por prueba\n3- Listado de pruebas y notas\n4- Modificacion de ponderacion de notas\n");
    scanf("%d", &seleccion);

    // Switch de seleccion de las diferentes opciones
    switch(seleccion) {
    case 1:
        notaFinal(aNotas);
        break;
    
    case 2:
        maxMinMedia(aNotas);
        break;

    default:
        printf("La opcion seleccionada no es valida");
        break;
    }

    return;
}

void notaFinal(float notas[a][b]) {
    float suma = 0;

    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 4; j++) {
            suma = suma + notas[i][j];
        }
        printf("\nLa media del alunno %d es: %.1f", i + 1, (suma / b));
        suma = 0;
    }

    return;
}

void maxMinMedia(float notas[a][b]) {
    float max = 0, min = 0, suma = 0;

    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 10; j++) {
            suma = suma + notas[j][i];

            if(notas[j][i] > max) {
                max = notas[j][i];
            }

            if(notas[j][i] < min) {
                min = notas[j][i];
            }
        }
        printf("\nLa media de la asignatura %d es: %.1f", i + 1, (suma / a));
        printf("\nLa nota maxima de la asignatura %d es: %.1f", i + 1, max);
        printf("\nLa nota minima de la asignatura %d es: %.1f", i + 1, min);

        max = 0;
        min = 0;
        suma = 0;
    }

    return;
}
