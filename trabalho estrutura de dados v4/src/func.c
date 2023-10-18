#include <stdio.h>
#include <stdlib.h>
#include "func.h"


struct no{
    int dado;
    struct no *no_anterior;
    struct no *no_proximo;
};

struct lista{
    No *inicio;
    No *fim;
    int tamanho;
};


Lista *criar_lista(){
    Lista *ptr_lista = (Lista*)malloc(sizeof(Lista));
    ptr_lista->tamanho = 0;
    ptr_lista->inicio = NULL;
    ptr_lista->fim = NULL;
    return ptr_lista;
}

void destruir_lista(Lista **ptr_ptr_lista){

    Lista *ptr_lista = (*ptr_ptr_lista);

    if(ptr_lista != NULL){
        No *ptr_no_atual = ptr_lista->inicio;
        No *ptr_aux;

        while(ptr_no_atual != NULL){
            
            ptr_aux = ptr_no_atual;
            ptr_no_atual = ptr_no_atual->no_proximo;

            free(ptr_aux);
        }
        free(ptr_no_atual);
        free(ptr_lista);
        *ptr_ptr_lista = NULL;
    }
}

void inserir_no_inicio(Lista *lista, int num){
    No *no_novo = (No*) malloc(sizeof(No));

    no_novo->dado = num;
    no_novo->no_anterior = NULL;
    no_novo->no_proximo = NULL;
    
    if(lista->inicio == NULL){
        lista->inicio = no_novo;
        lista->fim = no_novo;
    }else{

        no_novo->no_proximo = lista->inicio;
        lista->inicio->no_anterior = no_novo;
        lista->inicio = no_novo;
        
    }

    if(lista->inicio == NULL){
        printf("A lista nao contem itens !!!\n");
    }else{
        No *no_aux = lista->inicio;

        while(no_aux != NULL){
            printf("| %d | ", no_aux->dado);
            no_aux = no_aux->no_proximo;
        }
        printf("\n\n");
   }

    lista->tamanho = lista->tamanho + 1;
}


void inserir_no_final(Lista *lista, int num){

    No *no_novo = (No*) malloc(sizeof(No));

    no_novo->dado = num;
    no_novo->no_proximo = NULL;
    no_novo->no_anterior = NULL;

    if(lista->inicio == NULL){
        lista->inicio = no_novo;
        lista->fim = no_novo;
    }else{
        no_novo->no_anterior = lista->fim;
        lista->fim->no_proximo = no_novo;
        lista->fim = no_novo;
    }

    if(lista->inicio == NULL){
        printf("A lista nao contem itens !!!\n");
   }else{
        No *no_aux = lista->inicio;

        while(no_aux != NULL){
            printf("| %d | ", no_aux->dado);
            no_aux = no_aux->no_proximo;
        }
        printf("\n\n");
   }

    lista->tamanho = lista->tamanho + 1;

}

int remover_no_inicio(Lista *lista){
    No *no_remover = lista->inicio;

    if(lista->inicio == NULL){
        printf("Nao contem itens\n");
        return -1;
    }

    if(lista->inicio->no_proximo == NULL){
        lista->inicio = NULL;
        return 1;
    }else{
        lista->inicio = lista->inicio->no_proximo;
        lista->inicio->no_anterior = NULL;
        free(no_remover);
        return 1;
    }

   
}

int remover_no_final(Lista *lista){
    No *no_remover = lista->fim;


    if(lista->inicio == NULL){
        printf("Nao contem itens\n");
        return -1;
    }

    if(lista->inicio->no_proximo == NULL){
        lista->inicio = NULL;
        return 1;
    }else{
        lista->fim = lista->fim->no_anterior;
        lista->fim->no_proximo = NULL;
        free(no_remover);
        return 1;
    }


    


}

int buscar_inicio(Lista *lista){
    return lista->inicio->dado;
}

int buscar_final(Lista *lista){
    return lista->fim->dado;
}

void imprimir_lista_inicio(Lista *lista){

   if(lista->inicio == NULL){
        printf("A lista nao contem itens !!!\n");
   }else{
        No *no_aux = lista->inicio;

        while(no_aux != NULL){
            printf("| %d | ", no_aux->dado);
            no_aux = no_aux->no_proximo;
        }
        printf("\n\n");
   }
}

void imprimir_lista_fim(Lista *lista){

    if(lista->inicio == NULL){
        printf("A lista nao contem itens !!!\n");
    }else{
        No *no_aux = lista->fim;
    
        while(no_aux != NULL){
            printf("| %d | ", no_aux->dado);
            no_aux = no_aux->no_anterior;
        }
        printf("\n\n");
   }

}

void limpar_lista(Lista *lista){
    No *no_proximo;
    No *no_atual = lista->inicio;
    
        if(lista->inicio == NULL){
            printf("A lista nao contem itens !!!\n");
        } else {
            while (no_atual != NULL){
                no_proximo = no_atual->no_proximo;
                free(no_atual);
                no_atual = no_proximo;
            }
            printf("A lista foi esvaziada !!!\n");
            lista->inicio = NULL;
            lista->fim = NULL;
            lista->tamanho = 0;
        }

}

