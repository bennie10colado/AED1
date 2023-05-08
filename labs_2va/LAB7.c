//Aluno: Joao Guilherme Benjamin

#include <stdio.h>
#include <stdbool.h>

typedef struct 
{
    int id;  
    int idade;    
    float altura; 
} estudante;

int bubblesort(estudante *e){
    int retorno = 0;
    int i,j;
    
    for(i=0; i<10-1;i++){
        for(j=0;j<10-i-1;j++){
            if(e[j].altura < e[j+1].altura){
                retorno = 1;
            }
            else{
                retorno = 0;
            }
        }
    }
    return retorno;
}

void swap(estudante *min, estudante *i)
{
    estudante temp = *min;
    *min = *i;
    *i = temp;
    
}


int selectionSort(estudante *e, int n)
{
    int i,j, indice_minimo_valor;
    
    if(bubblesort(e)){
        printf("nenhuma troca eh necessaria.\n");
        return 1;
    }
    for(i=0; i < n-1;i++){
        indice_minimo_valor = i;
        for(j=i+1;j < n;j++){
            
            if(e[j].altura < e[indice_minimo_valor].altura){
                indice_minimo_valor = j;
            }
            if(indice_minimo_valor != i){
                swap(&e[indice_minimo_valor],&e[i]);
            }
            
        }
    }
    return 0;
}


void printArray(estudante *e, int tam)
{
    int i;
    for (i=0; i < tam; i++)
        printf("%f ", e[i].altura);
    printf("\n");
}

int main()
{   
    int tam = 10;
    estudante turma[10];
    estudante Joao;
    
    Joao.idade = 15;
    Joao.id = 60.5;
    Joao.altura = 1.75;
    
    turma[0].id = 1;
    turma[0].idade = 10;
    turma[0].altura = 1.20;
    
    turma[1].id = 1;
    turma[1].idade = 10;
    turma[1].altura = 1.10;
    
    turma[2].id = 1;
    turma[2].idade = 10;
    turma[2].altura = 1.30;
    
    turma[3].id = 1;
    turma[3].idade = 10;
    turma[3].altura = 1.40;
    
    turma[4].id = 1;
    turma[4].idade = 10;
    turma[4].altura = 1.75;
    
    turma[5].id = 1;
    turma[5].idade = 10;
    turma[5].altura = 1.80;  
    
    turma[6].id = 1;
    turma[6].idade = 10;
    turma[6].altura = 1;  
    
    turma[7].id = 8;
    turma[7].idade = 2;
    turma[7].altura = 0.5; 
    
    turma[8].id = 8;
    turma[8].idade = 20;
    turma[8].altura = 1.90;  
    
    turma[9].id = 8;
    turma[9].idade = 1;
    turma[9].altura = 0.2;     
    
    selectionSort(turma, tam);
    printf("array de estudantes com suas alturas: \n\n");
    printArray(turma, tam);
    
    return 0;
    
}