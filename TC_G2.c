#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Definiciones macro
#define a 10
#define b 4

// Prototipos de las funciones.
void notaFinal(float notas[a][b],int aPonderacion[b]);
void maxMinMedia(float notas[a][b]);
void listPruebasNotas(float notas[a][b]);
void cambiarPonderacion(int arrayPonderaciones[b]);

// Funcion main
void main() {
    // Declaracion de las variables.
    float aNotas[a][b];
    int seleccion;
    int aPonderacion[b] = {25, 25, 25, 25};



    // Insercion de las notas
    /*
    Ejecutaremos este bucle que recorre las 4 notas de los 10 alumnos siempre que el dato isntertado por el usuario
    sea mayor o igual que 0 o menor o igual que 10. Si esta condicion no se cumple, se pedira de nuevo la calificacion
    del alumno que se ha introducido equivocamente.
    */
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

    // Peticion de seleccion de la opcion al usuario
    /*
    Ejecutaremos este bucle mientras el valor de la seleccion introducida por el usuario sea distinta de 5. Si el valor introducido no comprende entre los valores 1 y 4,
    se mostrara por pantalla un mensaje de error.
    */

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

// Funcion notaFinal

/*
Esta funcion nos mostrara por pantalla la nota final de cada alumno teniendo en cuenta las ponderaciones de cada prueba.
*/

void notaFinal(float notas[a][b], int aPonderacion[b]) {
    // Declaracion de la variable
    float suma = 0;

    /*
    Bucle que recorre el array alumno por alumno (j) y añade a la variable suma (variable que arrastra las sumas de las 4 pruebas)
    el valor de la prueba multiplicado por el porcentaje correspondiente a la ponderacion de la misma.
    Al finalizar el calculo de la nota de cada alumno se muestra por pantalla el resultado.
    */
    for(int i = 0; i < a; i++) {
        for(int j = 0; j < b; j++) {
            suma = suma + notas[i][j] * aPonderacion[j] / 100;
        }
        printf("\nLa media del alumno %d es: %.2f", i + 1, (suma));
        suma = 0;
    }
}

// funcion MaxMinMedia
/*
Esta funcion nos muestra la nota maxima, minima y la media por asigntura.
*/

void maxMinMedia(float notas[a][b]) {
    // Declaracion de las variables
    float max = 0, min = 0, suma = 0;

    // Bucle que recorre el array asignatura por asignatura (i) y haya el valor maximo y minimo, asi como la media aritmetica de las calificaciones de dicha asignatura.
    for(int i = 0; i < b; i++) {
        /* 
        Seteo de las variables max y min. Inicializamos la nota minima como el primer elemento de la asignatura ya que si lo 
        hiciesemos en 0, no podriamos haya una nota con un valor minimo que 0. Inicializamos la nota maxima a 0 para que pueda
        encontrar un valor valido.
        Una vez recorrida la asignatura, se muestran por pantalla las diferentes notas.
        */
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

// Funcion listaPruebaNotas
/*
Esta funcion lista las notas de cada prueba, asi como el numero de aprobados y suspensos de la misma.
*/

void listPruebasNotas(float notas[a][b]) {
    // Declaracion de la variable
    int aprobados = 0;

    /*
    Bucle que recorre el array asignaturas asignatura por asignatura (i) e imprime las notas de cada asignatura.
    La condicion if evalua si la nota leida del array es mayor o igual a 5, si es asi, suma 1 a la variable aprobados.
    Una vez finalizada la asignatura, imprime por pantalla el valor de la variable aprobados, y calcula la de suspensos como a(10) - aprobados.
    Resete la variable aprobados a 0.
    */
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


//Funcion cambiarPonderacion
/*
Esta funcion nos permite cambiar las ponderaciones de cada prueba.
*/
void cambiarPonderacion(int arrayPonderaciones[]) {
    /*
    Bucle que se ejecuta siempre y cuanto alguna de las nuevas ponderaciones introducidas sea inferior a 10 o mayor que 60, o
    que la suma total de las ponderaciones no sea igual a 100
    */
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