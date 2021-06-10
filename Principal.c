#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "cadastroUsuario.h";

int loginReconhecido = 0;

// Função de menu principal
void menu();

// Função de menu login
int menuLogin();

// Função de cadastro de usuário
void cadastroUsuarios(Usuario* u); 

int loginUsuarios(int loginReconhecido);

void entrando_main_menu();

void cadastrandoItem();

void menuPrincipal();

int removerItens();
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
	
	lerBancoItens();
	//entrando_main_menu();
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

void entrando_main_menu() {
	
	system("cls");
	
	FILE *file;
	
	file = fopen("gif_bem-vindo.txt", "r");

	if(file == NULL) {
		printf("Não foi possível abrir o arquivo...\n");
		getchar();
		exit(0);
	}
	
	char mostrarMenu[150];
	
	while(fgets(mostrarMenu,150,file) != NULL) {
		printf("%s", mostrarMenu);
		sleep(1);
	}
	
	sleep(2);
	fclose(file);
}

void menuPrincipal() {
	system("cls");
	
	FILE *file;
	
	char nomeU [20];
	char senhaU [20];
	int opc;
	
	char tipo[30];
	char condicao[30];
	char nome[30];
	char valor[8];
	char raridade[30];
	
	file = fopen("menu_principal.txt", "r");

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
	
	scanf("%d", &opc);
	
	switch(opc){
		
		case 1:
			system("cls");
			
			Item *i;
			
			i = (Item* ) malloc(sizeof(Item));
			
			printf("\nEntre com o tipo do item:");
			scanf("\n");
			scanf("%[^\n]%*c", tipo);
			printf("\nEntre com o nome:");
			scanf("\n");
			scanf("%[^\n]%*c", nome);
			printf("\nEntre com a condicao:");
			scanf("\n");
			scanf("%[^\n]%*c", condicao);
			printf("\nEnte com o valor:");
			scanf("\n");
			scanf("%[^\n]%*c", valor);
			printf("\nEntre com a raridade:");
			scanf("\n");
			scanf("%[^\n]%*c", raridade);
			
			strcpy(i->tipo,tipo);
			strcpy(i->nome,nome);
			strcpy(i->condicao,condicao);
			strcpy(i->valor,valor);
			strcpy(i->raridade,raridade);
			
			cadastrandoItem(i);	
			break;
			
		case 2:
			system("cls");
			
			lerItens();
			printf("\n\n");
			system("pause");
			
			system("cls");
			break;
		
		case 3:
			system("cls");
			
			removerItens();
			printf("\n\n");
			system("pause");
			
			system("cls");
			break;
		
		case 0:
			break;
	}
	
	system("pause");
}

void cadastrandoItem(Item *i){
	
	FILE *enviaItem;
	
	enviaItem = fopen("banco_de_itens.txt","a");
	
	fputs(strncat(i->condicao,";",1),enviaItem);
	fputs(strncat(i->nome,";",1),enviaItem);
	fputs(strncat(i->raridade,";",1),enviaItem);
	fputs(strncat(i->tipo,";",1),enviaItem);
	fputs(strncat(i->valor,";",1),enviaItem);
	
	fclose(enviaItem);
	
	printf("\nCadastrando item...\n");
	sleep(1);
	
	inserir(i);
	sleep(1);
	system("cls");
}

int removerItens() {
	
	FILE *file;
	
	file = fopen("removendo_itens.txt", "r");

	if(file == NULL) {
		printf("Não foi possível abrir o arquivo...\n");
		getchar();
		exit(0);
	}
	
	char mostrarTela[150];
	
	while(fgets(mostrarTela,150,file) != NULL) {
		printf("%s", mostrarTela);
	}
	
	fclose(file);
	
}
