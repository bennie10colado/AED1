//Aluno: Joao Guilherme Benjamin
//por algum motivo, os outros labs da 1VA foram corrompidos e nao consegui os recuperar da plataforma o qual foram entregues, somente este.

#include <stdio.h>
#include <stdlib.h>

//MATRIZ
float **criaMatriz(int linhas, int colunas){//alocar espaco nos sistema (qual seria a diferenca entre calloc)	
	int i=0;
    float **mat;

    mat = (float **)malloc(linhas * (sizeof(float *))); //retorna ponteiro de ponteiros

    for (i = 0; i < linhas; i++){
        mat[i] = (float *)malloc(colunas * (sizeof(float *)));//aloca a qtd de colunas de cada linha (o vetor)
    }
    return mat;
}

void preencheMatriz(int linhas, int colunas, float **mat){
	int i=0,j=0;

	for(i=0;i<linhas;i++){
		printf("\ndigite os valores para a linha %d: \n", i);
		for(j=0;j<colunas;j++){
			scanf("%f", &mat[i][j]);
		}
	}
	printf("\nmatriz preenchida com sucesso!\n");
}

void visualizaMatriz(int linhas, int colunas, float **mat){ //por algum motivo estar "float **visualizaMatriz" o codigo continuou funcionando
	int i=0,j=0;

	for(i=0;i<linhas;i++){
		printf("\n\n");
		for(j=0;j<colunas;j++){
			printf(" %.1f ", mat[i][j]);
		}
	}
}

float **somaMatrizes(int linhas, int colunas, float **mat1, float **mat2){ //considerando ambas as matrizes com numeros iguais de linhas e colunas
	int i=0,j=0;

	if(linhas == colunas)
	{
		float **matriz_subject;

		matriz_subject = criaMatriz(linhas,colunas); //alocar espaco
		
		for(i=0;i<linhas;i++){
			for(j=0;j<colunas;j++){
				matriz_subject[i][j] = mat1[i][j] + mat2[i][j];
			}
		}
	return matriz_subject;
	}
	
	else
	{
	printf("impossivel realizar operacao, pois o numero entre linhas e colunas eh diferente.\n");
	return -1;
	}
}

void visualizarSomaMatrizes(int l, int c, float **mat){
	int i=0,j=0;
	printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=/\n\n");
	printf("\n\nMATRIZ SOMA: \n");
	for(i=0;i<l;i++){
		printf("\n\n");
		for(j=0;j<c;j++){
			printf(" %.1f ", mat[i][j]);
		}
	}
}

//VETOR
float *criaVet(int linhas, int colunas)
{
    float *vet;
    vet = (float *)malloc(linhas*colunas*(sizeof(float)));//declaracao por alocacao dinamica
    return vet;
}

void preencheVet(int linhas, int colunas, float *vetMatriz){
	int i=0;

	printf("Digite os valores para o preenchimento do vetor: \n");
	for (i=0;i<(linhas*colunas);i++){
		scanf("%f",&vetMatriz[i]);
	}

	printf("Vetor preenchido com sucesso.\n");
}

void visualizaVet(int linhas, int colunas, float *vetMatriz){
	if(vetMatriz != NULL){
		int i=0;

		for(i=0; i<(linhas*colunas);i++){
			printf("%1.f ", vetMatriz[i]);
		}
	}
	else{
		printf("\nVetor vazio, nao preenchido previamente...\n");
	}
}

int main()
{
	float **matriz1;
	float **matriz2;
	float **matrizSoma;
	float *vetDeMatriz;
	int linhas=0,colunas=0,linhas2=0,colunas2=0;
	int opcao = 0;

	printf("________MATRIZES/VETORES_______ \n\n");
    printf("[1]-   Criar Matriz A.\n");
    printf("[2]-   Criar Matriz B.\n");
    printf("[3]-   Preencher Matriz A.\n");
    printf("[4]-   Preencher Matriz B.\n");
    printf("[5]-   Visualizar Matriz A.\n");
    printf("[6]-   Visualizar Matriz B.\n");
	printf("[7]-   Efetuar Soma de Matrizes.\n");
    printf("[8]-   Visualizar Soma de Matrizes.\n");
    printf("[9]-   Transformar Matriz em Vetor.\n");
    printf("[10]-  Visualizar Vetor.\n");
	printf("[11+]-  Sair.");

	
	do{	
		printf("\n----------------------------------\n");
		printf("\nEscolha uma nova opcao:\n");
        printf("----------------------------------\n");
        scanf("%d", &opcao);

		if(opcao == 1){
			printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=/\n");
			printf("obs: para que seja efetuada a soma de matrizes,consideraremos    /\n");
			printf("o numero de linhas e colunas iguais para todo o codigo           /\n");
			printf("                                                                 /\n");
			printf("                                                                 /\n");
			printf("digite a qtd de linhas das suas matrizes:                        /\n");
			scanf("%d", &linhas);
			printf("digite a qtd de colunas das suas matrizes:                       /\n");
			scanf("%d", &colunas);
			matriz1 = criaMatriz(linhas,colunas);
			printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=/\n\n");

		}

		if(opcao == 2){
			printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
			printf("obs: para que seja efetuada a soma de matrizes,consideraremos    /\n");
			printf("o numero de linhas e colunas iguais para todo o codigo           /\n");
			printf("                                                                 /\n");
			printf("                                                                 /\n");
			printf("digite a qtd de linhas das suas matrizes:                        /\n");
			scanf("%d", &linhas2);
			printf("digite a qtd de colunas das suas matrizes:                       /\n");
			scanf("%d", &colunas2);
			matriz2 = criaMatriz(linhas2,colunas2);
			printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=/\n\n");

		}

		if(opcao == 3){
			printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
			printf("                                                                 /\n");
			printf(" Preencha a matriz A:                                            /\n");
			printf("                                                                 /\n");
			printf("                                                                 /\n");
			printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=/\n\n");

			preencheMatriz(linhas,colunas,matriz1);
			
		}
		if(opcao == 4){
			printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
			printf("                                                                 /\n");
			printf(" Preencha a matriz B:                                            /\n");
			printf("                                                                 /\n");
			printf("                                                                 /\n");
			printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=/\n\n");
			
			preencheMatriz(linhas2,colunas2,matriz2); 

		}
		if(opcao == 5){
			printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
			printf("                                                                 /\n");
			printf(" Carregando Visualizacao da matriz A...                          /\n");
			visualizaMatriz(linhas,colunas,matriz1);
			printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=/\n\n");
					

		}
		if(opcao == 6){
			printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
			printf("                                                                 /\n");
			printf(" Carregando Visualizacao da matriz B...                          /\n");
			visualizaMatriz(linhas2,colunas2,matriz2);		
			printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=/\n\n");
			
		}

		if(opcao == 7){
			printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
			printf("                                                                 /\n");
			printf(" A soma entre a matriz A e B foi concluida.                      /\n");
			printf(" (obs: opcao 8 visualiza a matriz SOMA)                          /\n");
			printf("                                                                 /\n");
			printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=/\n\n");
			matrizSoma = somaMatrizes(linhas,colunas,matriz1,matriz2);
			printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=/\n\n");
		}
		if(opcao == 8){
			printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
			printf("obs: o numero de linhas e colunas usadas aqui serão usadas       /\n");
			printf("as da primeira matriz, se ambos forem iguais efetuará.           /\n");
			printf("                                                                 /\n");
			printf(" Carregando Visualizacao...                                      /\n\n");
			visualizarSomaMatrizes(linhas,colunas,matrizSoma);		
			printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=/\n\n");


		}
		if(opcao == 9){
			printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
			printf("                                                                 /\n");
			printf(" O vetor da matriz acaba de ser criado...                        /\n");
			printf(" Por favor digite seus algarismos:                               /\n");
			printf("                                                                 /\n");
			printf("                                                                 /\n");
			vetDeMatriz = criaMatriz(linhas,colunas);
			preencheVet(linhas,colunas, vetDeMatriz);
			printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=/\n\n");


		}
		if(opcao == 10){
			printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
			printf("                                                                 /\n");
			printf(" Carregando visualizacao do vetor...                             /\n");
			printf("                                                                 /\n");
			visualizaVet(linhas2,colunas2,vetDeMatriz);		
			printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=/\n\n");

		}
		

	}while (opcao < 11);

	printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=/\n");
	printf("\nCodigo desenvolvido por: Joao Guilherme Benjamin Alves de Rezende\n");
	printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=/\n\n");

	return 0;
}