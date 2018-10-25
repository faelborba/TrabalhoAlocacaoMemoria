/***Algoritmo de alocação de memória Best-fit 
****Desenvolvidor por Rafael Borba dos Santos
****Para A disciplina de Sistemas Operacionais da Ulbra
****/
#include <stdio.h>
#include <stdlib.h>

int main(){
	int nblocos = 0, nprocessos = 0, i = 0, j = 0, testa= 0, armazena = 0, posicao = 0;
	int bloco[20], processo[20];

	printf("\nBem vindo ao Best-fit");

	printf("\nDigite o número de blocos de memoria: "); 
	scanf("%d", &nblocos);// definição da quantidade de blocos
	for(i=0; i<nblocos; i++){// nesse trecho, definimos o tamanho de memória que cada bolco irá possuir.
		printf("\nDigite o tamanho do bloco %d: ", i);
		scanf("%d", &bloco[i]);
	}
	printf("Digite a quantidade de processos: \n"); 
	scanf("%d", &nprocessos);
	for(i=0;i<nprocessos; i++){
		printf("Digite o tamanho do processo %d \n", i);
		scanf("%d", &processo[i]);
	}
	armazena = -1;
	for(j=0; j<nprocessos; j++){
		for(i=0; i<nblocos; i++){//for dos blocos
			if(processo[j]==bloco[i]){// se o processo for do tamanho do bloco já armazena e segue o fluxo para testar o próximo processo
				printf("O processo %d foi alocado no bloco %d \n",j,i);
				armazena = -1;
				bloco[i] = 0;
				processo[j]=100000;
				break;
			}

			if(processo[j] < bloco[i]){
				if(armazena < processo[j]){
					//printf("##Entreiii\n");
					armazena = processo[j];
					posicao = i;
				}
				
			}
			if((i == nblocos - 1) && armazena != -1){// quando chegamos ao final do vetor de blocos alocamos na melhor posição encontrada.
				printf("O processo %d foi alocado no bloco %d \n",j,posicao);
				armazena = -1;
				bloco[posicao] = bloco[posicao]-processo[j];
				processo[j]=100000;
				break;
			}
			
		}		
	}

	for(i=0; i<nprocessos; i++){
		if(processo[i]!=100000){
			printf("Processo %d não foi alocado\n",i);
		}
	}
}