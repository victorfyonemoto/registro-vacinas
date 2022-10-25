#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#define SIZE 100

struct dados{
	char nome[SIZE];
	char cpf[15];
	char vacina[50];
	//char lote[SIZE]; o programa não executa com esse char
	char dia[10];		
};

struct dados cadastrar(){
	struct dados pessoa;
	printf("Informe o nome completo \n");
	fflush(stdin);
	gets(pessoa.nome);
	printf("\nInforme o CPF para registro no seguinte formato\n");
	printf("Formato: ***.***.***-** \n");
	fflush(stdin);
	gets(pessoa.cpf);
	printf("\nInforme a vacina aplicada\n");
	fflush(stdin);
	gets(pessoa.vacina);
	/*printf("Informe o número do lote \n");
	fflush(stdin);
	gets(pessoa.lote);*/
	printf("\nInforme a data no formato: DD/MM/AAAA\n");
	fflush(stdin);
	gets(pessoa.dia);
	printf("\nPressione enter para concluir o registro e retornar ao menu principal");
	fflush(stdin);
	return pessoa;
}


void listar(struct dados vacinados[9999], int qtdRegistros){
	int i;
	for(i = 0; i < qtdRegistros; i++){
		printf("================================================================================\n");
		printf("Nome: %s\n", vacinados[i].nome);
		printf("CPF: %s\n", vacinados[i].cpf);
		printf("Vacina: %s\n", vacinados[i].vacina);
		//printf("Lote: %s\n", vacinados[i].lote);
		printf("Data da aplicação: %s\n", vacinados[i].dia);
	}
	printf("================================================================================\n");
	printf("\nPressione enter para retornar ao menu principal");
	fflush(stdin);
}

/*void buscar(struct dados vacinados[9999], int qtdRegistros){	
	char busca[15];
	int j;
	printf("Informe o CPF que deseja buscar no seguinte formato\n");
	printf("Formato: ***.***.***-** \n");
	fflush(stdin);
	gets(busca);
	for(j = 0; j < qtdRegistros; j++){
		if(busca == vacinados[j].cpf){
			printf("Nome: %s\n", vacinados[j].nome);
			printf("CPF: %s\n", vacinados[j].cpf);
			printf("Vacina: %s\n", vacinados[j].vacina);
			printf("Lote: %s\n", vacinados[j].lote);
			printf("Data da aplicação: %s\n", vacinados[j].data);
		}else{
			printf("Registro não encontrado");
		}
	}	
}*/

int main(void){
	setlocale(LC_ALL, "Portuguese");
	int op = 0;
	int cont = 0;
	struct dados vacinados[9999];
    do{
    	system("cls");
		printf("=========================== Registro de Vacinação ==============================");
        printf("\n\n[1] - Criar Registro\n");
        printf("\n[2] - Pesquisar\n");
        printf("\n[3] - Listar os registros\n");
        printf("\n[4] - Sair \n\n");
        printf("================================================================================\n\n");
        printf("O que você gostaria de fazer ? \n");
        scanf("%d", &op);
        switch (op){
        case 1:{
        	system("cls");
			printf("=========================== Cadastro ==============================\n\n");
            vacinados[cont] = cadastrar();
            cont++;
            break;
			}
        case 2:{
        	system("cls");
        	printf("=========================== Pesquisar ==============================\n\n");
            //registro = pesquisar();
            break;
    		}
        case 3:{
        	system("cls");
        	printf("=========================== Registros ==============================\n\n");
            listar(vacinados, cont);
            break;
        	}
		case 4:{
			printf("Fim da execução, pressione enter.\n");
			break;
			}
        default:{
	    	printf("Opção Inválida \n");
	    	break;
			}
        }
        getch();
    }while (op != 4);
    printf("\nPressione enter novamente para fechar o programa\n");
}
