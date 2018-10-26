/***Algoritmo de alocação de memória Worst-fit 
****Desenvolvidor por Rafael Borba dos Santos e Andressa Sias
****Para A disciplina de Sistemas Operacionais da Ulbra
****/

#include <stdio.h>
#include <stdlib.h>

int main(){
	int nlacunas = 0, nprocessos = 0, i = 0, j = 0, k = 0, armazena = 0, posicao = 0;
	int lacuna[20], processo[20];

	printf("\nBem vindo ao Worst-fit"); 
	printf("\nDigite o número de lacunas de memoria: "); 
	scanf("%d", &nlacunas);// definição da quantidade de lacunas
	for(i=0; i<nlacunas; i++){// nesse trecho, definimos o tamanho de memória que cada bolco irá possuir.
		printf("\nDigite o tamanho do lacuna %d: ", i);
		scanf("%d", &lacuna[i]);
	}
	printf("Digite a quantidade de processos: \n"); 
	scanf("%d", &nprocessos);
	for(i=0;i<nprocessos; i++){
		printf("Digite o tamanho do processo %d \n", i);
		scanf("%d", &processo[i]);
	}
	printf("\nDados de entrada");
	printf("\nLacunas: ");
	for(k=0; k<nlacunas; k++){
		if(k + 1 == nlacunas ){
			printf("e %dK ",lacuna[k]);
		}else if(k + 2 == nlacunas ){
			printf("%dK ",lacuna[k]);
		}else{
			printf("%dK, ",lacuna[k]);
		}
	}
	printf("\nProcessos: ");
	for(k=0; k<nprocessos; k++){
		if(k + 1 == nprocessos ){
			printf("e %dK ",processo[k]);
		}else if(k + 2 == nprocessos ){
			printf("%dK ",processo[k]);
		}else{
			printf("%dK, ",processo[k]);
		}
	}
	armazena = -1;
	for(j=0; j<nprocessos; j++){
		for(i=0; i<nlacunas; i++){//for dos lacunas

			if(processo[j] <= lacuna[i]){
				if(armazena < lacuna[i] - processo[j] ){//se o armazena for maior que o processo armazena recebe o processo 
					armazena = lacuna[i] - processo[j];
					posicao = i;
				}
				
			}
			if((i == nlacunas - 1)){// quando chegamos ao final do vetor de lacunas alocamos na melhor posição encontrada.
				printf("\n O processo %d foi alocado no lacuna %d \t: ",j,posicao);
				armazena = -1;
				lacuna[posicao] = lacuna[posicao]-processo[j];
				processo[j]=100000;
				break;
			}
			
		}
		if(processo[j]!=100000){
			printf("\n O Processo %d não foi alocado \t\t: ",j);
		}
		for(k=0; k<nlacunas; k++){
			if(k + 1 == nlacunas ){
				printf("e %dK ",lacuna[k]);
			}else if(k + 2 == nlacunas ){
				printf("%dK ",lacuna[k]);
			}else{
				printf("%dK, ",lacuna[k]);
			}
		}			
	}
	printf("\n\n");
}