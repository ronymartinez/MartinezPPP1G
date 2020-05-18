#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int id;
    char procesador[20];
    char marca[20];
    float precio;
} eNotebook;

#define TAM 5

int ordenar(eNotebook vec[], int tam);
float aplicarDescuento(float producto);
int contarCarateres(char cadena[], char letra);
int main()
{
    float precio;
    float descuento;
    char nombre [20];
    char letra;
    int contador = 0;


    eNotebook notebook[TAM] = {{1000, "INTEL", "Apple", 125},
                             {2000, "ZEN", "Lenovo",435},
                             {3000, "INTEL", "Sony", 224},
                             {4000, "AMD", "Toshiba", 734},
                             {4000, "ZEN", "Sony", 564},
                            };



    printf("*** FUNCION CONTAR CARACTER REPETIDO***");
    printf("\n\nIngrese una nombre: ");
    scanf("%s", &nombre);
    __fpurge(stdin);

    printf("\nIngrese una letra: ");
    scanf("%c", &letra);
    __fpurge(stdin);

    contador = contarCarateres(nombre, letra);
    printf("\nIngresó la cadena '%s' y la letra '%c' se menciona %d veces\n\n", nombre, letra, contador);


    printf("*** FUNCION APLICAR DESCUENTO ***\n\n");

    printf("Ingrese precio: ");
    scanf("%f", &precio);

    descuento = aplicarDescuento(precio);

    printf("\nEl precio ingresado es %.2f y con el descuento es %.2f\n\n", precio, descuento);


    printf("*** FUNCION ORDENAR NOTEBOOKS***");

    ordenar(notebook, TAM);

    printf(" ID    PROCESADOR     MARCA    PRECIO \n\n");
    for(int i = 0; i < TAM; i++)
    {
        printf("%d   %10s   %10s    %6.f2\n", notebook[i].id, notebook[i].procesador, notebook[i].marca, notebook[i].precio);
    }

    return 0;
}

float aplicarDescuento(float producto)
{
    float descuento = 0;

    descuento = producto - (producto * 0.05);

    return descuento;
}

int contarCarateres(char cadena[], char letra)
{
    int contadorLetra = 0;

    for (int i = 0; cadena[i] != '\0'; i++)
    {
        if (cadena[i] == letra)
        {
            contadorLetra++;
        }
    }
    return contadorLetra;
}

int ordenar(eNotebook vec[], int tam)
{
    eNotebook aux1;
    eNotebook aux2;

    for (int i = 0; i < tam - 1; i ++)
    {
        for (int j = i +1; j < tam; j++)
        {
            if (strcmp(vec[i].marca, vec[j + 1].marca) > 0)
            {
                aux1 =  vec[i];
                vec[i] = vec[j];
                vec[j] = aux1;
            }
            if(strcmp(vec[i].marca, vec[i].marca) == 0 && vec[i].precio < vec[j].precio)
            {
                aux2 = vec[i];
                vec[i] = vec[j];
                vec[j] = aux2;
            }
        }
    }

    return 0;
}




