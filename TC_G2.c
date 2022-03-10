#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Definiciones
#define a 10
#define b 4

// Prototipos de las funciones
void notaFinal(float notas[a][b]);
void maxMinMedia(float notas[a][b]);
void listPruebasNotas(float notas[a][b]);
void cambiarPonderacion(float notas[a][b]);

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

    case 3:
        listPruebasNotas(aNotas);
        break;

    case 4:
        cambiarPonderacion(aNotas);
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
        printf("\nLa media del alunno %d es: %.2f", i + 1, (suma / b));
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
        printf("\nLa media de la asignatura %d es: %.2f", i + 1, (suma / a));
        printf("\nLa nota maxima de la asignatura %d es: %.2f", i + 1, max);
        printf("\nLa nota minima de la asignatura %d es: %.2f", i + 1, min);

        max = 0;
        min = 0;
        suma = 0;
    }

    return;
}

void listPruebasNotas(float notas[a][b]) {
    int aprobados = 0;

    for(int i = 0; i < 4; i++) {
        printf("Listado de notas de la prueba %d", i + 1);
        for(int j = 0; j < 10; j++) {
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

// Esta parte no funciona

void cambiarPonderacion(float notas[a][b]) {
    int arrayPonderaciones[4] = {25, 25, 25, 25}, suma[4];

    do {
        printf("Introduzca las nuevas ponderacion (entre 10 y 60)");
        scanf("%d %d %d %d", &arrayPonderaciones[0], &arrayPonderaciones[1], &arrayPonderaciones[2], &arrayPonderaciones[3]);

        if(
            arrayPonderaciones[0] < 10 || arrayPonderaciones[0] > 60 ||
            arrayPonderaciones[1] < 10 || arrayPonderaciones[1] > 60 ||
            arrayPonderaciones[2] < 10 || arrayPonderaciones[2] > 60 ||
            arrayPonderaciones[3] < 10 || arrayPonderaciones[3] > 60
        ) {
            printf("La ponderacion introducida no es valida");
        }

    } while (
        arrayPonderaciones[0] >= 10 || arrayPonderaciones[0] <= 60 ||
        arrayPonderaciones[1] >= 10 || arrayPonderaciones[1] <= 60 ||
        arrayPonderaciones[2] >= 10 || arrayPonderaciones[2] <= 60 ||
        arrayPonderaciones[3] >= 10 || arrayPonderaciones[3] <= 60
    );
    


    if(arrayPonderaciones[0] + arrayPonderaciones[1] + arrayPonderaciones[2] + arrayPonderaciones[3] != 100) {
        printf("La suma de las ponderaciones no es valida");
    } else {
        for(int i = 0; i < 10; i++) {
            for(int j = 0; j < 4; j++) {
                suma[j] = notas[i][j];
            }
        printf("\nLa media del alumno %d es: %.2f", i + 1, (suma[0] * (arrayPonderaciones[0] / 100)) + (suma[1] * (arrayPonderaciones[1] / 100)) + (suma[2] * (arrayPonderaciones[2] / 100)) + (suma[3] * (arrayPonderaciones[3] / 100)));
    }
    }
}