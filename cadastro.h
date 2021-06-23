#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char tipo[30];
	char condicao[30];
	char nome[30];
	char valor[8];
	char raridade[30];
}Item;

Item *itens;
int itensCadastrados = 0;

// Desenvolver aqui funções referentes a add e remover itens do cadastro

void inserir(Item *item){
	// Função inserir novo item
	itens = (Item*)realloc(itens,(itensCadastrados+1)*sizeof(Item));
	itens[itensCadastrados] = *item;
	itensCadastrados++;
	printf("\nItem Cadastrado com sucesso!\n");
}

void lerBancoItens(){
	
	char linha[124];
	char *mat;
	Item *item;
	char val[20];
	
	FILE *bancoItem;
	
	bancoItem = fopen("banco_de_itens.txt","r");
	
	while(fgets(linha,124,bancoItem) != NULL) {
		mat = strtok(linha, ";"); // Separando strings a partir do ;
		item = (Item*) malloc(sizeof(Item));
		strcpy(item->condicao,mat);
		strcpy(item->nome,mat);
		strcpy(item->raridade,mat);
		strcpy(item->valor,mat);
		strcpy(item->tipo,mat);
		item->tipo[strcspn(item->tipo,"\n")] = 0;
		itens = (Item*)realloc(itens,(itensCadastrados+1)*sizeof(Item));
		itens[itensCadastrados] = *item;
		free(item);
		itensCadastrados++;
	}
	
	fclose(bancoItem);
}

void lerItens(){
	int i;
	
	printf("==========================\n");
	for(i=0;i<itensCadastrados;i++){
		
		printf("||\tItem: %d\t||\n",i+1);
		printf("\tNome: %s\t\n",itens[i].nome);
		printf("\tTipo: %s\t\n",itens[i].tipo);
		printf("||\t\t\t||\n");
		printf("==========================\n");
		fflush(stdin);
	}
}

void remover(){
	// Função remover item
}
