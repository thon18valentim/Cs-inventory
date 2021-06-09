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

int loginReconhecido = 0;

// Função de menu principal
void menu();

// Função de menu login
int menuLogin();

// Função de cadastro de usuário
void cadastroUsuarios(Usuario* u); 

int loginUsuarios(int loginReconhecido);

void menuPrincipal();
																				// INÍCIO FUNÇÃO MAIN

int main(){
	
	lerBanco();
	
	setlocale(LC_ALL, "PORTUGUESE");
	int opc = 1;

	while (1) {
		if (loginReconhecido == 2) {
			break;
		}
		loginReconhecido = menuLogin(opc, loginReconhecido);		
	}
	
	menuPrincipal();
}
																				// FIM FUNÇÃO MAIN
void menu(){
	// Desenvolver menu aqui

}

int menuLogin(int opc, int loginReconhecido){
	
	char nomeCompleto[100];
	char nomeUsuario[100];
	char email[100];
	char senha[100];
	
	FILE *file;
	file = fopen("menu_de_boas_vindas.txt", "r");
	printf("...");
	
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
			if(usuCadastrados == 0) {
				printf("\n\t\t\t\t\tAinda não há usuários cadastrados aqui...\n");
				sleep(2);
				system("cls");
				break;
			}
			else {
				loginUsuarios(loginReconhecido);
			}
			break;
			
		case 2:
			// Cadastrar Usuário
			
			system("cls");
			
			Usuario *u;
			
			FILE *file;
			
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
		
			u = (Usuario* ) malloc(sizeof(Usuario));
			
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
			
			cadastroUsuarios(u);	
			break;
		
		case 3:
			system("cls");
			
			lerUsers();
			printf("\n\n");
			system("pause");
			
			system("cls");
			break;
			
		case 0:
			system("cls");
			printf("\nObrigado por usar nosso programa!\n\nPrograma fechando...");
			sleep(1);
			exit(0);
	}
}

void cadastroUsuarios(Usuario *u) {
	
	FILE *enviaBDD;
	enviaBDD = fopen("banco_de_usuarios.txt", "a");
	fputs(strncat(u->nomeCompleto,";",1),enviaBDD);
	fputs(strncat(u->nomeUsuario,";",1),enviaBDD);
	fputs(strncat(u->email,";",1),enviaBDD);
	fputs(strncat(u->senha,"\n",1),enviaBDD);
	fclose(enviaBDD);
	
	printf("\nCadastrando usuário...\n");
	sleep(1);
	
	cadastrar(u);
	sleep(1);
	system("cls");
}

int loginUsuarios(int loginReconhecido) {
	
	system("cls");
	
	FILE *file;
	
	char nomeU [20];
	char senhaU [20];
	
	file = fopen("menu_login.txt", "r");

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
	
	printf("\t\tEntre com o seu nome: ");
	scanf("\n");
	scanf("%[^\n]%*c", nomeU);
	printf("\n\t\tEntre com a sua senha: ");
	scanf("\n");
	scanf("%[^\n]%*c", senhaU);
	
	loginReconhecido = existeLogin(nomeU,senhaU, loginReconhecido);
	
	return loginReconhecido;
	
	//system("pause");
	
	//system("cls");
}

void menuPrincipal() {
	system("cls");
	
	FILE *file;
	
	char nomeU [20];
	char senhaU [20];
	
	file = fopen("gif_menu_principal.txt", "r");

	if(file == NULL) {
		printf("Não foi possível abrir o arquivo...\n");
		getchar();
		exit(0);
	}
	
	char mostrarMenu[150];
	
	while(fgets(mostrarMenu,150,file) != NULL) {
		sleep(1);
		printf("%s", mostrarMenu);
	}
	
	fclose(file);
	
	system("pause");
}
