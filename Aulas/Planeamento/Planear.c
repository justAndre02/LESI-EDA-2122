/**
*  @file GereContactos.c
 * @author lufer
 * @date 2022
 * @brief Lista Ligadas Simples (vers�o 1)
 *
 * Metodos para manipular uma Lista Ligada Simples de Contactos
 * @bug No known bugs.
*/

#include "plano.h"
#include  <locale.h>
#include <stdio.h>

int main() {
	setlocale(LC_ALL, "Portuguese");
	
	Job* listaJobs = NULL;
	int teste;
	
	//listaJobs=CarregarDadosFicheiro("Dados.csv");
	
	#pragma region ESCALONAMENTO
	Cel plano[M][T];

	//IniciaPlano(plano, 1, 1);
	//OcupaUm(plano, 1, 9, 1, 1);

	// Cel aux;
	// aux.idJob = 1;
	// aux.idOper = 1;

	//OcupaVarios(plano, 1, 6, &aux);

	Ocupa(plano, 2, 3, 1, 1);

#pragma endregion
}