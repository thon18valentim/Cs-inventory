#include <stdio.h>
#include <stdlib.h>

// Desenvolva aqui todas as funções referentes ao login

typedef struct {
	char nomeCompleto[100];
	char nomeUsuario[100];
	char email[100];
	char senha[100];
} Usuario;

Usuario *users;
int tamanho=0;

void cadastrar(Usuario *usuario){
	users = (Usuario*)realloc(users,(tamanho+1)*sizeof(Usuario));
	users[tamanho] = *usuario;
	tamanho++;
	printf("\nCadastrado...");
}
