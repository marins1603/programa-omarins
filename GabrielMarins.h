#ifndef GabrielMarins_H_INCLUDED
#define GabrielMarins_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

//calculando a disponibilidade
float *Disponibilidade (int *tempoProd, int *tempoMaq1, int *tempoMaq2,int qtd);

// calculando a Performance
float *Performance( int *qtdProd, int *tempoProd, int *tempoMaq1, int *tempoMaq2, int *tempoCiclo, int qtd);

//calculando a Qualidade
float *Qualidade(int *qtdBoa, int *qtdRuim, int qtd);

//qualculando o OEE -Overall Equipment Effectiveness
float *OEE(float *dis, float *perf, float *quali,int qtd);

//arquiva os dados de todas as maquinas
void arquivar(char *nome[],float *dis,float *perf,float *quali,float *oee, int qtd);

//imprime os dados na tela
void imprimir(char *nome[],float *disp, float *perf, float *qual, float *oee ,int qtd);

//arquiva os nomes de cada maquina;
void arquivarnomes(char *nome[],int qtd);
#endif /* GabrielMarins_H_INCLUDED */

