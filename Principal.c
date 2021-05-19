#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
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

// Função de cadastro de usuário
void cadastroUsuarios(); 
																				// INÍCIO FUNÇÃO MAIN

int main(){
	
	setlocale(LC_ALL, "PORTUGUESE");
	int opc = 1;
	
	while (opc != 0) {
		menuLogin(opc);		
	}

	
}
																				// FIM FUNÇÃO MAIN
void menu(){
	// Desenvolver menu aqui

}

void menuLogin(int opc){
	
	char nomeCompleto[100];
	char nomeUsuario[100];
	char email[100];
	char senha[100];
	
	FILE *file;
	file = fopen("menu_de_boas_vindas.txt", "r");
	
	if(file == NULL) {
		printf("Não foi possível abrir o arquivo...\n");
		getchar();
		exit(0);
	}
	
	char mostrarMenu[150];
	
	while(fgets(mostrarMenu,150,file) != NULL) {
		printf("%s", mostrarMenu);
	}
	
	fclose(file);
	scanf("%d",&opc);
	
	Usuario *u = (Usuario*)malloc(sizeof(Usuario));
	
	switch(opc){
		case 1:
			// Login
			break;
			
		case 2:
			// Cadastrar Usuário
			
			system("cls");
			
			file = fopen("menu_cadastrar.txt", "r");
	
			if(file == NULL) {
				printf("Não foi possível abrir o arquivo...\n");
				getchar();
				exit(0);
			}
			
			char mostrarMenu[150];
			
			while(fgets(mostrarMenu,150,file) != NULL) {
				printf("%s", mostrarMenu);
			}
			
			fclose(file);
			
			printf("\n\n");
			
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
  			
  			printf("\nCadastrando usuário...\n");
  			sleep(1);
  			
			cadastrar(u);
			sleep(1);
			system("cls");
			
			break;
			
		case 0:
			system("cls");
			printf("\nObrigado por usar nosso programa!\n\nPrograma fechando...");
			sleep(1);
			exit(0);
	}
}
