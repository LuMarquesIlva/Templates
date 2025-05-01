#include <ncurses.h>

int main() 
{
	initscr(); /* Start curses mode */
	printw("Olá, Mundo !!!"); /* Print Olá, Mndo */
	refresh(); /* Print it on the real screen */
	getch(); /* Wait for user input */
	endwin(); /* end curses mode */

	return 0;
}
