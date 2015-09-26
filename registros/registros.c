#include <curses.h>
void registros1(long int *registros) /* Función que no retorna, solo muestra los registros almacenados */
{
	int i; /* Se crea una variables la cual inicia el contador del for */
	//mvprintw(0,3,"Registrosss"); /* Imprime en pantalla haciendo uso de la libreria curses */
    for(i=0;i<4;i++) /* Condición a evaluar hasta cumplir con la condición i<4 */
	{
		mvprintw((2+i),3,"%d %d %d\n",registros[i],registros[i+1],registros[i+2]); /* Imprime en pantalla los valores de los registros haciendo uso del printw de la libreria curses */
    }
}
