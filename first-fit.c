/***Algoritmo de alocação de memória First-fit 
****Desenvolvidor por Rafael Borba dos Santos
****Para A disciplina de Sistemas Operacionais da Ulbra
****/

#include <stdio.h>
#include <stdlib.h>

int main(){
	int nblocos = 0, nprocessos = 0, i = 0, j = 0;
	int bloco[20], processo[20];
	
	printf("\nBem vindo ao First-fit");
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
	
	for(j=0; j<nprocessos; j++){
		for(i=0; i<nblocos; i++){//for dos blocos
			if(processo[j]<=bloco[i]){
				printf("O processo %d foi alocado no bloco %d \n",j,i);
				bloco[i] = bloco[i]-processo[j];
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