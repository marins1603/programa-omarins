#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "GabrielMarins.h"
//calculando a disponibilidade

float *Disponibilidade (int *tempoProd, int *tempoMaq1, int *tempoMaq2,int qtd){
int i;
int *tempProg;
float *disponi;
tempProg=(int*)malloc(qtd*sizeof(int));
disponi=(float*)malloc(qtd*sizeof(float));
if(tempProg == NULL){
        printf("Erro ");
        return NULL;
    }
  else  if(disponi == NULL){
        printf("Erro ");
        return NULL;
    }
    
for(i=0;i<qtd;i++){
*(tempProg+i)= (tempoProd[i]-tempoMaq1[i])-tempoMaq2[i];
*(disponi+i) = (float) tempProg[i] *100/tempoProd[i];
}

return disponi;
}

// calculando a Performance
float *Performance( int *qtdProd, int *tempoProd, int *tempoMaq1, int *tempoMaq2, int *tempoCiclo, int qtd){
int i;
float *prodTeorica;
float *performance=0;
int *tempProg;
tempProg=(int*)malloc(qtd*sizeof(int));
performance=(float*)malloc(qtd*sizeof(float));
prodTeorica=(float*)malloc(qtd*sizeof(float));
if(tempProg == NULL){
        printf("Erro ");
        return NULL;
    }
  else  if(performance == NULL){
        printf("Erro ");
        return NULL;
    }
     else  if(prodTeorica == NULL){
        printf("Erro ");
        return NULL;
    }

for(i=0;i<qtd;i++){
*(tempProg+i)= (tempoProd[i]-tempoMaq1[i])-tempoMaq2[i];
*(prodTeorica+i)=(float) (tempProg[i] *60)/tempoCiclo[i];
*(performance+i) = (qtdProd[i]/prodTeorica[i])*100;
}


return performance;
}

//calculando a Qualidade
float *Qualidade(int *qtdBoa, int *qtdRuim, int qtd){
int i;
float *qualidade =(float*)malloc(qtd*sizeof(float));
if(qualidade == NULL){
        printf("Erro ");
        return NULL;
    }
for(i=0;i<qtd;i++){
*(qualidade+i)= (float)(qtdBoa[i]-qtdRuim[i])/qtdBoa[i]*100;
}
return qualidade;
}

//qualculando o OEE -Overall Equipment Effectiveness

float *OEE(float *dis, float *perf, float *quali,int qtd){
float *oee=(float*)malloc(qtd*sizeof(float));
int i;
if(oee == NULL){
        printf("Erro ");
        return NULL;
    }
for(i=0;i<qtd;i++){
*(oee+i) = (dis[i]*perf[i]*quali[i])/10000;
}
return oee;
}

void arquivar(char *nome[], float *dis,float *perf,float *quali,float *oee, int qtd){
	  FILE *arq;
        arq = fopen("./arquivos.txt","ab");
        if(arq==NULL){
            printf("Erro ao criar Arquivo!\n");
        }
		if(qtd>=1){
		arquivar(nome,dis,perf,quali,oee,qtd-1);
		nome[qtd-1]= strupr(nome[qtd-1]);
        fprintf(arq,"MAQUINA %d: %s\n", qtd, nome[qtd-1]);
		fprintf(arq,"EQUIPAMENTO: %d\n",qtd);
		fprintf(arq,"DISPONIBILIDADE: %.2f\n",dis[qtd-1]);
		fprintf(arq,"PERFORMANCE: %.2f\n",perf[qtd-1]);
		fprintf(arq,"QUALIDADE: %.2f\n",quali[qtd-1]);
		fprintf(arq,"OEE: %.2f\n\n",oee[qtd-1]);
	}
	fclose(arq);
}

void imprimir(char *nome[],float *disp, float *perf, float *qual, float *oee ,int qtd){
	int i;
 
	for(i=0; i<qtd; i++){
	nome[i]= strupr(nome[i]);
	printf("nome do equipamento %s\n", nome[i]);
	printf("Disponibilidade: %.2f\n",disp[i]);
	printf("Performance: %.2f\n",perf[i]);
	printf("Qualidade: %.2f\n",qual[i]);//
	printf("OEE / Overall Equipment Effectiveness:%.2f\n",oee[i]);
	}
}

void arquivarnomes(char *nome[],int qtd){
	int i;
	 FILE *arq;
        arq = fopen("./arquivos.txt","ab");
        if(arq==NULL){
            printf("Erro ao criar Arquivo!\n");
        }
        fputs("LISTA DE TODAS AS MAQUINAS:\n",arq);
	for(i=0; i<qtd; i++){
		nome[i]= strupr(nome[i]);
        fprintf(arq,"MAQUINA %d: %s\n", i+1, nome[i]);
    }
}



