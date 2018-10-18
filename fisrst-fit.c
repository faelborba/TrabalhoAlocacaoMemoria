//First-fit

#include <stdio.h>

int main(){
	int nblocos = 0, nprocessos = 0, i = 0, j = 0;
	int bloco[20], processo[20];

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
	j=0;
	for(i=0; i<nblocos; i++){//for dos blocos
		for(j=j; j<nprocessos; j++){
			if(processo[j]<=bloco[i]){
				printf("O processo %d foi alocado no bloco %d \n",j,i);
				processo[j]=100000;
				j++;
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