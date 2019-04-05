#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include "screen.h"
#include "config.h"
#include "snake.h"

void welcome();
void gameOver(int);
void getNames();
void hidecursor();


char player1[20];
char player2[20];

int main(int argc, char *argv[]) {
	hidecursor();
	getNames();
	welcome();
	clock_t begin = clock();


	srand(time(NULL));
	
	newGame();
	ScreenUpdate();
	int out = 0;
	char in;
	hidecursor();
	while(out == 0){
		if(kbhit() != 0){
		switch(getch()){
			case 'w':
				setDir1(0); 
				updateGame();
				break;
			case 'd':
				setDir1(1); 
				updateGame();
				break;
			case 's':
				setDir1(2); 
				updateGame();
				break;
			case 'j':
				setDir2(3); 
				updateGame();
				break;
			case 'i':
				setDir2(0); 
				updateGame();
				break;
			case 'l':
				setDir2(1); 
				updateGame();
				break;
			case 'k':
				setDir2(2); 
				updateGame();
				break;
			case 'a':
				setDir1(3); 
				updateGame();
				break;
			case 'p':
				initGame1();
				initGame2();
				break;	
			case 'q':
				out = 1;
		}
	}	
		if(((double)(clock() - begin)/CLOCKS_PER_SEC) >= 1/refresh_rate){
			move();
			updateGame();
			ScreenUpdate();
			begin = clock();
		}
//		if (itsOver1() == 1) {
//			gameOver(1);
//			ScreenInit();
//			initGame1();
//			initGame2();
//			ScreenUpdate();
//		}
//		if (itsOver2() == 1) {
//			gameOver(2);
//			ScreenInit();
//			initGame1();
//			initGame2();
//			ScreenUpdate();
//		}
	}
	return 0;
}


void welcome(){
	printf("\n\n                         Snake mulijugador\n                              ++++++>\n\n          Presione la tecla de espacio para comenzar a jugar");
	while(getch() != ' ');
}

void gameOver(int in){
	printf("\n\n                         ");
	if(in == 1){
		printf("%s", player1);
	}
	else{
		printf("%s",player2);
	}
	
	printf(" ha perdido :(\n\n          Presione la tecla de espacio para volver a jugar");
	while(getch() != ' ');
}





void hidecursor()
{
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 100;
   info.bVisible = FALSE;
   SetConsoleCursorInfo(consoleHandle, &info);
}
