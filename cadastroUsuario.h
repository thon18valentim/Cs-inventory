#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Desenvolva aqui todas as funções referentes ao login

typedef struct {
	char nomeCompleto[50];
	char nomeUsuario[20];
	char email[30];
	char senha[20];
} Usuario;

Usuario *users;
int usuCadastrados=0;

void cadastrar(Usuario *usuario){
	users = (Usuario*)realloc(users,(usuCadastrados+1)*sizeof(Usuario));
	users[usuCadastrados] = *usuario;
	usuCadastrados++;
	printf("\nCadastrado com sucesso!\n");
}

void lerBanco(){
	
	char linha[124];
	char *mat;
	Usuario *user;
	
	FILE *banco;
	
	banco = fopen("banco_de_usuarios.txt","r");
	
	while(fgets(linha,124,banco) != NULL) {
		mat = strtok(linha, ";"); // Separando strings a partir do ;
		user = (Usuario*) malloc(sizeof(Usuario));
		strcpy(user->nomeCompleto,mat);
		strcpy(user->nomeUsuario,strtok(NULL,";"));
		strcpy(user->email,strtok(NULL,";"));
		strcpy(user->senha,strtok(NULL,";"));
		user->senha[strcspn(user->senha,"\n")] = 0;
		users = (Usuario*)realloc(users,(usuCadastrados+1)*sizeof(Usuario));
		users[usuCadastrados] = *user;
		free(user);
		usuCadastrados++;
	}
	
	fclose(banco);
}

void lerUsers(){
	int i;
	
	printf("==========================\n");
	for(i=0;i<usuCadastrados;i++){
		
		printf("||\tUsuário: %d\t||\n",i);
		printf("\tNome.: %s\t\n",users[i].nomeCompleto);
		printf("\tSenha: %s\t\n",users[i].senha);
		printf("||\t\t\t||\n");
		printf("==========================\n");
		fflush(stdin);
	}
}

void existeLogin(char *nome, char *senha){
	
	int i;
	
	for(i=0; i<usuCadastrados; i++){
		if(strcmp(users[i].nomeUsuario,nome) == 0){
			printf("\nAchou nome");
			if(strcmp(users[i].senha,senha) == 0){
				printf("\nAchou senha");
			}
		}
	}
	
}
