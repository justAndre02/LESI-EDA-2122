/**
*  @file GereContactos.c
 * @author lufer
 * @date 2022
 * @brief	Lista Ligadas Simples (vers�o 1)
 *			Resolu��o Folha de Exerc�cios 4.3
 * Metodos para manipular uma �rvores Bin�rias de Hist�rico
 * @bug No known bugs.
*/
#include "Contatos.h"
#include "Pessoa.h"
#include "GenericaABP.h"
#include  <locale.h>

#pragma region GereInteiros
//M�todos para demmonstrar �rvore gen�rica aplicada a inteiros

int CompInt(int *x, int *y) {
	return (*x - *y);
}

void PrintInt(int* x) {
	printf("%d\n", *x);
}

#pragma endregion

int main() {
	setlocale(LC_ALL, "Portuguese");

#pragma region ArvoreGenericaInteiros

	//Exemplo �rvore gen�rica para conter inteiros
	Node* rootTemp = NULL;
	int x = 12;
	int y = 13;
	rootTemp = AddNode(rootTemp, &x, CompInt);
	rootTemp = AddNode(rootTemp, &y, CompInt);
	ShowTree(rootTemp, PrintInt);

#pragma endregion

#pragma region Lista_e_Arvore_Pessoas_Contactos

	//Inicia �rvore
	Node* historico = InitTree();

	Contacto* c1 = CriaContacto("Telef", "253123321");
	ListaContactos* contactos = NULL;
	contactos = InsereContactoListaContactos(contactos, c1);
	MostraContactos(contactos);

	Pessoa* p = CriaPessoa("PP", 12345);
	ListaPessoa* inicio = NULL;
	inicio = InserePessoaListaPessoas(inicio, p);

	Pessoa* p2 = CriaPessoa("JJ", 4321);
	inicio = InserePessoaListaPessoas(inicio, p2);
	MostraTodasPessoas(inicio);

	inicio = InsereContactoPessoa(inicio, c1, 12345);

	p = CriaPessoa("CC", 1);
	inicio = InserePessoaListaPessoas(inicio, p);

	p = CriaPessoa("DD", 13345);
	inicio = InserePessoaListaPessoas(inicio, p);

	Contacto* c2 = CriaContacto("Email", "aaa@bbb.pt");
	inicio = InsereContactoPessoa(inicio, c2, 4321);

	MostraContactosPessoa(inicio, 12345);
	MostraContactosPessoa(inicio, 4321);

	SavePessoas(inicio, "Pessoas.dat");
	SaveAll(inicio, "All.dat");

	MostraTodasPessoas(inicio);

	inicio = NULL;	//ATEN��O: n�o � suficiente NULL...deve destruir-se a lista
	inicio = GetAllPessoas("Pessoas.dat");
	inicio = GetAll("All.dat", inicio);

	puts("\nAp�s Ficheiro\n");
	MostraTodasPessoas(inicio);

	//Gere Historico
	inicio = RemovePessoaABP(inicio, 12345, &historico);
	puts("\nAp�s Remo��o (I)\n");
	MostraTodasPessoas(inicio);

	puts("\nHist�rico\n");
	ShowTree(historico, ShowPessoa);	//mesmo que &ShowPessoa
	inicio = RemovePessoaABP(inicio, 1, &historico);
	puts("\nAp�s Remo��o (II)\n");
	MostraTodasPessoas(inicio);
	puts("\nHist�rico\n");
	ShowTree(historico, ShowPessoa);	//mesmo que &ShowPessoa
	
	//Preservar e Carregar �rvore
	bool aux = GuardaHistorico(historico, "tree.dat");
	Node* historico2 = InitTree();
	historico2 = GetHistorico("tree.dat");
	ShowTree(historico2, ShowPessoa);

#pragma endregion
}