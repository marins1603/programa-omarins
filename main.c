#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "lib.h"
main(){

int temProg[10],temMaqPrep[10], temMaqReabas[10];
int qtdProduzida[10], qtdRefug[10];
int temCicloPad[10];
float *qual;
float *perf;
float *disp;
float *oee;
char *nome[15];
int qtdequip;
int i;
	printf("Digite a quantidade de equipamentos que voce quer analisar:");
	scanf("%d",&qtdequip);
	for(i=0;i<qtdequip;i++){
		printf("\nEQUIPAMENTO %d\n", i+1);
		printf("Tipo de equipamento:");
		nome[i]=(char*)malloc(sizeof(char) * 30);
		scanf("%s", nome[i]);
		printf("Digite o valor do tempo Programado(min):");
		scanf("%d",&temProg[i]);
		printf("Digite o valor da Maquina parada para preparacao(min):");
		scanf("%d",&temMaqPrep[i]);	
		printf("Digite o valor da Maquina parada aguardando reabastecimento(min):");
		scanf("%d",&temMaqReabas[i]);
		printf("Digite a quantidade produzida no periodo:");
		scanf("%d",&qtdProduzida[i]);
		printf("Digite a quantidade de pecas Refugadas:");
		scanf("%d",&qtdRefug[i]);
		printf("Digite o tempo de clico padrao do item(seg):");
		scanf("%d",&temCicloPad[i]);
}
disp=Disponibilidade(temProg,temMaqPrep,temMaqReabas,qtdequip);
perf=Performance(qtdProduzida,temProg,temMaqPrep,temMaqReabas,temCicloPad,qtdequip);
qual=Qualidade(qtdProduzida, qtdRefug,qtdequip);
oee=OEE(disp,qual,perf,qtdequip);

//arqnomes(nome,qtdequip);
imprimir(nome,disp,perf,qual,oee,qtdequip);
/*for(i=0;i<qtdequip;i++){
//printf("nome do equipamento %s\n", nome[i]);
printf("Disponibilidade: %.2f\n",disp[i]);
printf("Performance: %.2f\n",perf[i]);
printf("Qualidade: %.2f\n",qual[i]);//
printf("OEE / Overall Equipment Effectiveness:%.2f",oee[i]);
}
*/
arquivarnomes(nome,qtdequip);
arquivar(nome,disp,perf,qual,oee,qtdequip);
free(disp);
free(perf);	
free(qual);
free(oee);
}

