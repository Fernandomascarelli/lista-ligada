#include <stdio.h>
#include <stdlib.h>

typedef struct no No;
typedef struct lista Lista;

Lista *criar_lista();

void destruir_lista(Lista **ptr_ptr_lista);

void inserir_no_inicio(Lista *lista, int num);

void inserir_no_final(Lista *lista, int num);

int remover_no_inicio(Lista *lista);

int remover_no_final(Lista *lista);

int buscar_inicio(Lista *lista);

int buscar_final(Lista *lista);

void imprimir_lista_inicio(Lista *lista);

void imprimir_lista_fim(Lista *lista);

void limpar_lista(Lista *lista);
