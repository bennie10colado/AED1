//Aluno: Joao Guilherme Benjamin Alves de Rezende

#include <stdio.h>
#include <stdbool.h>
 
void swap(int *valor1, int *valor2)
{
    int temp = *valor1;
    
    *valor1 = *valor2;
    *valor2 = temp;
}
 
void bubbleSort(int array[], int tam)
{
   int i, j;
   bool trocou;
   
   for (i = 0; i < tam-1; i++)
   {
     trocou = false;
     for (j = 0; j < tam-i-1; j++)
     {
        if (array[j] > array[j+1]) //se o primeiro numero for maior do que o segundo, ocorre o swap
        {
           swap(&array[j], &array[j+1]);
           trocou = true;
        }
     }
 
     if (trocou == false) //se nao houve troca, eh encerrado
        break;
   }
}
 
void imprimirArray(int arr[], int tam)
{
    int i;
    
    for (i=0; i < tam; i++)
        printf("%d ", arr[i]);
    printf("\nok\n");
}
 
int main()
{
    int lista[] = {64, 34, 25, 12, 22, 11, 90, 12, 50, 49, -1};
    int lista2[] = {0,1,2,3,4,5,6,7,8,9}; //lista ordenada
    
    int tam = sizeof(lista)/sizeof(lista[0]);
    int tam2 = sizeof(lista2)/sizeof(lista2[0]);

    bubbleSort(lista, tam);
    bubbleSort(lista2, tam2);
    
    printf("Array desordenado sorteado apos o bubblesort: \n");
    
    imprimirArray(lista, tam); //devera printar 11 12 12 22 25 34 49 50 64 90

    printf("Array ordenado sorteado apos o bubblesort: \n");
    
    imprimirArray(lista2, tam2);
    return 0;
}
