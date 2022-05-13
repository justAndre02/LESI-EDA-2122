/**
Uso de Bibliotecas
*/
#include <stdio.h>
#include "c:\temp\Funcoes.h"

int x = 10;


/**
 * @brief Fun��o recursiva local auxiliar
 * 
 * @param y
 * @return 
 */
int Aux(int y) {
	static int f = 0;
	if (y > 0) {
		f += y;
		//y++;
		x++;
		y--;
		return Aux(y);
	}	
	else
		return(f);
}


/**
 * @brief Utiliza��o de fun��es internas e externas (em bibliotecas).
 * 
 * @return 
 */
int main() {

	int aux = Soma(12, 13);	//Soma est� implementada na biblioteca externa
	printf("%d\n", x);

	int x1 = Aux(3);		//Aux est� implementada neste m�dulo
	printf("X=%d - Y=%d", x, Aux(12));

}


