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
		users = (Usuario*)realloc(users,(usuCadastrados+1)*sizeof(Usuario));
		users[usuCadastrados] = *user;
		free(user);
		usuCadastrados++;
	}
	
	fclose(banco);
}

void lerUsers(){
	int i;
	for(i=0;i<usuCadastrados;i++){
		printf("%s\n",users[i].nomeCompleto);
		fflush(stdin);
	}
}
