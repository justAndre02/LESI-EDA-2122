/*****************************************************************//**
 * @file   plano.c
 * @brief  Manipula��o de um Plano de Produ��o
 * 
 * @author lufer
 * @date   May 2022
 *********************************************************************/
#include <stdio.h>
#include "plano.h"
#include <stdlib.h>

void IniciaPlano(Cel p[][T], int codJob, int codOper) {

	for (int l = 0; l < M; l++){
		for (int col = 0; col < T; col++) {
			p[l][col].idJob = codJob;
			p[l][col].idOper = codOper;
		}
	}
}

/**
 * @brief Ocupa uma unidade de tempo do Plano.
 * 
 * @param p		Plano
 * @param mId	Maquina
 * @param t		Tempo
 * @param codJob	Job
 * @param codOper	Operacao
 */
void OcupaUm(Cel p[][T], int mId, int t, int codJob, int codOper) {
	//testar
	p[mId][t].idJob = codJob;
	p[mId][t].idOper = codOper;
	//printf("%d, %d, %d, %d, %d", p, mId, t, codJob, codOper);
}

/**
 * @brief Ocupa v�rias unidades de tempo.
 * 
 * @param p	- Plano
 * @param mId	- Maquina
 * @param totTempo	- Tempo a ocupar
 * @param c	- Job e Operacao
 */
void OcupaVarios(Cel p[][T], int mId, int totTempo, Cel* c) {
	
	//Fase 1: Procurar a primeira "casa" livre
	int col = 0;
	if (p[mId][col].idJob != -1){
		col++;
	}

	//Fase 1 - Ocupa a partir da posi��o livre encontrada
	totTempo += col;	//porqu�?

	for (; col < totTempo; col++) {
		p[mId][col].idJob = c->idJob;
		p[mId][col].idOper = c->idOper;
	}

	//Fase 2 - Procurar quando a opera��o anterior

	//Fase 3 - Verficar se ap�s posi��o livre existe tempo suficiente...
}

Ocupa(Cel p[][T], int mId, int totTempo, int codJ, int codO) {
	Cel c = { .idJob=codJ, .idOper=codO };
	OcupaVarios(p, mId, totTempo, &c);
	printf("\nPlano: Maquina: %d, Tempo Decorrido: %d, Célula %d: Job - %d || Operação - %d\n", mId, totTempo, c, codJ, codO);
}

/**
 * @brief Carrega dados de um ficheiro CSV.
 * 
 * @param fileName
 * @return 
 */
Job* CarregarDadosFicheiro(char* fileName) {
	FILE* fp;
	char texto[MAX];
	int a, b, c, d;

	Job *listaJobs = NULL;

	Job auxJob;
	Oper auxOper;
	Maquina auxMaq;

	//char d[20];

	fp = fopen(fileName, "r");
	if (fp == NULL) {
        perror("Failed to open file");
        exit(1);
    };

	while (!feof(fp)) {
		if (fgets(texto, MAX, fp) != NULL)
		{
			sscanf(texto, "%d;%d;%d;%d", &auxJob.codJob, &auxOper.cod, &auxMaq.codM, &auxMaq.t);
			printf("LIDO: %d - %d - %d - %d \n", auxJob.codJob, auxOper.cod, auxMaq.codM, auxMaq.t);
		}
	}
	fclose(fp);
	return listaJobs;
}

