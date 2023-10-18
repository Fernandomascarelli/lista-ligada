#include <stdio.h>
#include <stdlib.h>
#include "func.h"

void pausa_e_limpa(){
   system("pause");
  system("cls");
}

void menu(Lista *lista){  // basicamente o menu que puxa as funÃ§oes

    int op, num;
	
	do{
		printf("-------------------------------------\n");
      printf("|               Menu                |\n");
      printf("-------------------------------------\n");
      printf("| 1 - Adicionar um numero no inicio |\n");
      printf("| 2 - Adicionar um numero no final  |\n");
      printf("| 3 - Remover o numero do inicio    |\n");
      printf("| 4 - Remover o numero do final     |\n");
      printf("| 5 - Buscar o elemento do inicio   |\n");
      printf("| 6 - Buscar o elemento do final    |\n");
      printf("| 7 - Imprimir inicio ao fim        |\n");
		printf("| 8 - Imprimir fim ao inicio        |\n");
      printf("| 9 - Limpar lista inteira          |\n");
      printf("| 0 - Sair                          |\n");
      printf("-------------------------------------\n");
		printf("Resposta: ");
      scanf("%d", &op);
		
		system("cls");

			switch(op){
			
				case 1:
               printf("Digite o Numero: ");
               scanf("%d", &num);
               inserir_no_inicio(lista, num);
               printf("\nNumero inserido com Sucesso !!!\n\n");
               pausa_e_limpa();
					break;
				case 2:
               printf("Digite o Numero: ");
               scanf("%d", &num);
               inserir_no_final(lista, num);
               printf("\nNumero inserido com Sucesso !!!\n\n");
               pausa_e_limpa();
					break;
				case 3: 
               remover_no_inicio(lista);
               printf("Inicio removido com Sucesso.\n");
               pausa_e_limpa();
					break;
				case 4: 
               remover_no_final(lista);
               printf("Final removido com Sucesso.\n");
               pausa_e_limpa();
					break;
				case 5:
               num = buscar_inicio(lista);
               printf("Numero do inicio: %d\n", num);
               pausa_e_limpa();
					break;				
				case 6:
               num = buscar_final(lista);
               printf("Numero do final: %d\n", num);
               pausa_e_limpa();
					break;
				case 7:
               imprimir_lista_inicio(lista);
               pausa_e_limpa();
					break;
				case 8:
               imprimir_lista_fim(lista);
               pausa_e_limpa();
					break;
            case 9:
               limpar_lista(lista);
               pausa_e_limpa();
               break;
				default:
					if(op != 0){
						printf("Digita Direito !!\n");
                  pausa_e_limpa();
					}
               break;
			}
			
	}while(op != 0);
}

int main(){

   Lista *lista = criar_lista();
   
   menu(lista);

   destruir_lista(&lista);

   return 0;
}