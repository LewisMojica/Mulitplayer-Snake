#include "screen.h"
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#include "snake.h"
#include "config.h"

char map[x_size][y_size];
int score;

void ScreenInit(){
	int x,y;
	
	for(x = 0; x < x_size; x++)
		for (y = 0; y < y_size; y++)
			map[x][y] = ' ';
}

void ScreenUpdate(){
	system("cls");
	_write();
}

void _write(){
	int x,y;
	printf("\n");
	
	for (x = 1; x <= left_margin + x_size*0.1; x++)
		printf(" "); //margen izquierdo
		
	printf("Puntuacion: %d", getScore1());
	for(x = 0; x < (x_size*0.4 ); x++)
		printf(" ");
		
	printf("Puntuacion: %d\n", getScore2(),getLives2());
	
	
	for (x = 8; x <= left_margin + x_size*0.2; x++)
		printf(" "); //margen izquierdo
		
	printf("Vidas: %d      ", getLives1());
	for(x = 0; x < (x_size*0.4 ); x++)
		printf(" ");
		
	printf("Vidas: %d\n",getLives2());
	
	for (x = 2; x <= top_margin; x++)
		printf("\n"); //margen superior
		
	for (x = 1; x <= left_margin; x++)
		printf(" "); //margen izquierdo
		
	for(x = 0; x <= x_size + 1; x++)
		printf("%c",border_char); //extremo superior
	
	printf("\n");
	for (x = 1; x <= left_margin; x++)
		printf(" "); //margen izquierdo
	
	
	printf("%c",border_char);
	
	
	
	for(y = 0; y < y_size; y++){
		for (x = 0; x < x_size; x++)
			printf("%c", map[x][y]);
			
		printf("%c\n",border_char);
		for (x = 1; x <= left_margin; x++)
			printf(" "); //margen izquierdo
		
		printf("%c",border_char);
		
	}
	
	for(x = 0; x <= x_size; x++){
		printf("%c",border_char);
	}
	printf("\n");
}

void setPixel(int x, int y, char cha){
	if(y < y_size && y >= 0 && x < x_size && x >= 0)
		map[x][y] = cha;
}


