#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cadastroUsuario.h";

typedef struct {	
	char nome[30];
	char tipo[30];
	float condicao;
	char raridade[15];
	float valor; 
} Item;

// Função de menu principal
void menu();
// Função de menu login
void menuLogin();

int main(){
	menuLogin();
}

void menu(){
	// Desenvolver menu aqui

}

void menuLogin(){
	int opc;
	
	char nomeCompleto[100];
	char nomeUsuario[100];
	char email[100];
	char senha[100];
	
	printf("Bem vindo - (1)Login (2)Cadastrar (0)Sair\n");
	scanf("%d",&opc);
	
	Usuario *u = (Usuario*)malloc(sizeof(Usuario));
	
	switch(opc){
		case 1:
			// Login
			break;
		case 2:
			// Cadastrar Usuario
			printf("\nEntre com o seu nome completo: ");
			scanf("\n");
  			scanf("%[^\n]%*c", nomeCompleto);
			printf("\nEntre com o nome do seu usuario: ");
			scanf("\n");
  			scanf("%[^\n]%*c", nomeUsuario);
			printf("\nEntre com o seu email: ");
			scanf("\n");
  			scanf("%[^\n]%*c", email);
			printf("\nEntre com a sua senha: ");
			// Verificar funcao de senha posteriormente
			scanf("\n");
  			scanf("%[^\n]%*c", senha);
  			
  			strcpy(u->nomeCompleto,nomeCompleto);
  			strcpy(u->nomeUsuario,nomeUsuario);
  			strcpy(u->email,email);
  			strcpy(u->senha,senha);
  			
			cadastrar(u);
			break;
		default:
			// Sair
			break;
	}
}
