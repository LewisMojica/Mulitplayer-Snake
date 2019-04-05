#include <stdio.h>
#include <stdlib.h>

#include "snake.h"
#include "screen.h"
#include "config.h"
#include "struct.h"


int lose2 = 0;
int score2;
int lives1,lives2;

char player1[20], player2[20];



head Head2;
body Body2[max_length];
int body_length2;

////////////////
food Food;
food Live;
unsigned int live_cnt;
////////////////

int lose1 = 0;
int score1;

head Head1;
body Body1[max_length];
int body_length1;




void initGame1(){
	body_length1 = initial_length;
	lose1 = 0;
	score1 = initial_length;
	lives1 = initial_lives;
	setHead1();
	
	int i;
	
	for(i = initial_length; i < max_length; i++)
		Body1[i].x = - 1;
	//se inicia el cuerpo de la serpiente
	
	/* -y = arriba	  +x = derecha	   +y = abajo	  -x = izquierda   */
	if(Head1.dir == 0){
		
			
		for (i = 0; i < initial_length ; i++){
			Body1[i].y = Head1.y + 1 + i;
			Body1[i].x = Head1.x;
		}	
	}
	else if(Head1.dir == 2){
		for (i = 0; i < initial_length ; i++){
			Body1[abs(i - initial_length + 1)].y = Head1.y - initial_length + i;
			Body1[i].x = Head1.x;
		}
	}
	else if(Head1.dir == 1){
		for (i = 0; i < initial_length ; i++){
			Body1[abs(i - initial_length + 1)].x = Head1.x - initial_length + i;
			Body1[i].y = Head1.y;
		}
	}
	else if(Head1.dir == 3){
		for (i = 0; i < initial_length ; i++){
			Body1[i].x = Head1.x + 1 + i;
			Body1[i].y = Head1.y;
		}
	}
	updateGame();
}

void setHead1(){
	Head1.x = (rand() % (x_size/2)) + (x_size/4);
	Head1.y = (rand() % (y_size/2)) + (y_size/4);
	
	
	// se asigna una direccion aleatorea a la serpiente
	/* 0 = -y = arriba	   1 = +x derecha	   2 = +y = abajo	   3 = -x izquierda   */
	do
		setDir1(rand() % 4);
	while(Head1.dir == 4);	
}

void setDir1(int dir){
	if((abs(dir - Head1.dir) != 2)){
	Head1.dir = dir;
	char tmp;
	switch(Head1.dir){
		case 0:tmp = '^';
		break;
		case 1: tmp = '>';
		break;
		case 2: tmp = 'v';
		break;
		case 3: tmp = '<';
		break;
	}
	
		setPixel(Head1.x, Head1.y, tmp);
	}

}



void move1(){
	int i;
	for(i = body_length1 - 1;i > 0; i--){
		Body1[i].x = Body1[i-1].x;
		Body1[i].y = Body1[i-1].y;
	}
	
	Body1[0].x = Head1.x;
	Body1[0].y = Head1.y;
	
	switch(Head1.dir){
		case 0:
			Head1.y--;
			break;
		case 1:
			Head1.x++;
			break;
		case 2:
			Head1.y++;
			break;
		case 3:
			Head1.x--;
			break;	
	}
	if(Head1.x == Food.x && Head1.y == Food.y){
		addSize1();
		setFood();
	}
	
	if(live_cnt > 20 && Head1.x == Live.x && Head1.y == Live.y){
		live_cnt = 0;
		lives1++;
	}
	
	if(Head1.x > x_size || Head1.x < 0 || Head1.y > y_size - 1 || Head1.y < 0){
		lose1 = 1;
	}
	
	int flag = 0;
	
//	for (i = 0; i < body_length1; i++){
//		if(Head1.x == Body1[i].x && Head1.y == Body1[i].y)
//			flag += 1;
//	}
//	
	if(flag > 0){
		lose1 = 1;
	}
	if(onHead() == 1){
		lose1 = 1;
	}
	
//	if(lose1 == 1){
//		born1();
//	}
	if(lose1 == 1){
		 lives1 --;
		 born1();
	}
}

void addSize1(){
	if (body_length1 < max_length){
		body_length1+=5;
		if(body_length1 > max_length){
			body_length1 = max_length;
		}
		score1 = body_length1;
		updateGame();
	}
}

int itsOver1(){
	return lose1;
}


void debug1(){
	int i;
	printf("HEAD -> %d, %d",Head1.x,Head1.y);
//	for(i = 0; i<5;i++){
//		printf("\n%d , %d",Body[i].x,Body[i].y);
//	}
	 printf(" ||| Score: %d, food -> %d, %d",body_length1, Food.x,Food.y);
}

int getScore1(){
	return score1;
}

void born1(){
	if(lives1 > 0){
		updateGame();
		ScreenUpdate();
		body_length1 = initial_length;
		lose1 = 0;
		score1 = initial_length;
		setHead1();
		//se inicia el cuerpo de la serpiente
		
		/* -y = arriba	  +x = derecha	   +y = abajo	  -x = izquierda   */
		int i;
		if(Head1.dir == 0){
			
				
			for (i = 0; i < initial_length ; i++){
				Body1[i].y = Head1.y + 1 + i;
				Body1[i].x = Head1.x;
			}	
		}
		else if(Head1.dir == 2){
			for (i = 0; i < initial_length ; i++){
				Body1[abs(i - initial_length + 1)].y = Head1.y - initial_length + i;
				Body1[i].x = Head1.x;
			}
		}
		else if(Head1.dir == 1){
			for (i = 0; i < initial_length ; i++){
				Body1[abs(i - initial_length + 1)].x = Head1.x - initial_length + i;
				Body1[i].y = Head1.y;
			}
		}
		else if(Head1.dir == 3){
			for (i = 0; i < initial_length ; i++){
				Body1[i].x = Head1.x + 1 + i;
				Body1[i].y = Head1.y;
			}
		}
		sleep(1);
	}
	else{
		updateGame();
		ScreenUpdate();
		gameOver1();
	}
}

void gameOver1(){
	printf("\n\n                         ");
	printf("%s ha perdido :(\n\n          Presione la tecla de espacio para volver a jugar",player1);
	while(getch() != ' ');
	newGame();
	
}


int getLives1(){
	return lives1;
}


////////////////////////////////////////////
////////////////////////////////////////////
////////////////////////////////////////////

void newGame(){
	setFood();
	setLive();
	initGame1();
	initGame2();
}
void setFood(){
	Food.x = (rand() % x_size);
	Food.y = (rand() % y_size);
	setPixel(Food.x, Food.y, food_char);
}

void move(){
	live_cnt++;
	if(live_cnt > live_interval * 2){
		live_cnt = 0;
		setLive();
	}
		
	move1();
	move2();
}

void setLive(){
	Live.x = (rand() % x_size);
	Live.y = (rand() % y_size);
	setPixel(Live.x, Live.y, live_char);
}

void quitLive(){
	
}

void updateGame(){
	ScreenInit();
	int i;
	//se actualiza el cuerpo
	for (i = body_length2 - 1; i >= 0; i--){
		setPixel(Body2[i].x,Body2[i].y,body_char2);
	}
	//se actualiza la cabeza
	setDir2(Head2.dir);
	
	//se actualiza la comida
	setPixel(Food.x,Food.y,food_char);
	////////////////////////////////////
	//se actualiza el cuerpo
	for (i = body_length1 - 1; i >= 0; i--){
		setPixel(Body1[i].x,Body1[i].y,body_char);
	}
	//se actualiza la cabeza
	setDir1(Head1.dir);
	
	//se actualiza la comida
	setPixel(Food.x,Food.y,food_char);
	
	//se escribe la vida si esta habilitada
	if(live_cnt > live_interval){
		setPixel(Live.x,Live.y,live_char);
	}
}

int onHead(){
	int i;
//	int out = 0;
	
	for(i = 0; i < body_length1; i++){
		if(Head1.x == Body2[i].x && Head1.y == Body2[i].y)
			return 1;
		if(Head2.x == Body1[i].x && Head2.y == Body1[i].y)
			return 2;
	}
	return 0;
}

void getNames(){
	printf("Ingrese el nombre del jugador 1 >");
	scanf("%s",&player1);
	printf("Ingrese el nombre del jugador 2 >");
	scanf("%s",&player2);
}
////////////////////////////////////////////
////////////////////////////////////////////
////////////////////////////////////////////

void initGame2(){

	lives2 = initial_lives;
	
	body_length2 = initial_length;
	score2 = initial_length;
	
	setFood();
	setHead2();
	lose2 = 0;
	//se inicia el cuerpo de la serpiente
	
	/* -y = arriba	  +x = derecha	   +y = abajo	  -x = izquierda   */
	int i;
	
	for(i = initial_length; i < max_length; i++)
		Body2[i].x = - 1;
		
	if(Head2.dir == 0){
		
			
		for (i = 0; i < initial_length ; i++){
			Body2[i].y = Head2.y + 1 + i;
			Body2[i].x = Head2.x;
		}	
	}
	else if(Head2.dir == 2){
		for (i = 0; i < initial_length ; i++){
			Body2[abs(i - initial_length + 1)].y = Head2.y - initial_length + i;
			Body2[i].x = Head2.x;
		}
	}
	else if(Head2.dir == 1){
		for (i = 0; i < initial_length ; i++){
			Body2[abs(i - initial_length + 1)].x = Head2.x - initial_length + i;
			Body2[i].y = Head2.y;
		}
	}
	else if(Head2.dir == 3){
		for (i = 0; i < initial_length ; i++){
			Body2[i].x = Head2.x + 1 + i;
			Body2[i].y = Head2.y;
		}
	}
	updateGame();
	
}

void setHead2(){
	Head2.x = (rand() % (x_size/2)) + (x_size/4);
	Head2.y = (rand() % (y_size/2)) + (y_size/4);
	
	
	// se asigna una direccion aleatorea a la serpiente
	/* 0 = -y = arriba	   1 = +x derecha	   2 = +y = abajo	   3 = -x izquierda   */
	do
		setDir2(rand() % 4);
	while(Head2.dir == 4);	
}

void setDir2(int dir){
	if((abs(dir - Head2.dir) != 2)){
	Head2.dir = dir;
	char tmp;
	switch(Head2.dir){
		case 0:tmp = '^';
		break;
		case 1: tmp = '>';
		break;
		case 2: tmp = 'v';
		break;
		case 3: tmp = '<';
		break;
	}
	
		setPixel(Head2.x, Head2.y, tmp);
	}

}




void move2(){
	int i;
	for(i = body_length2 - 1;i > 0; i--){
		Body2[i].x = Body2[i-1].x;
		Body2[i].y = Body2[i-1].y;
	}
	
	Body2[0].x = Head2.x;
	Body2[0].y = Head2.y;
	
	switch(Head2.dir){
		case 0:
			Head2.y--;
			break;
		case 1:
			Head2.x++;
			break;
		case 2:
			Head2.y++;
			break;
		case 3:
			Head2.x--;
			break;	
	}
	if(Head2.x == Food.x && Head2.y == Food.y){
		addSize2();
		setFood();
	}
	if(live_cnt > 20 && Head2.x == Live.x && Head2.y == Live.y){
		live_cnt = 0;
		lives2++;
	}
	
	if(Head2.x > x_size || Head2.x < 0 || Head2.y > y_size - 1 || Head2.y < 0){
		lose2 = 1;
	}
	
	int flag = 0;
	
//	for (i = 0; i < body_length2; i++){
//		if(Head2.x == Body2[i].x && Head2.y == Body2[i].y)
//			flag += 1;
//	}
	
	if(flag > 0){
		lose2 = 1;
		
	}
//	
	if(onHead() == 2){
		lose2 = 1;
	}
	
	if(lose2 == 1){ 
		lives2--;
		born2();
		
	}
//	
//	if(lose2 == 1){
//		born2();
//	}
//	if(lives2 > 0)
//		lose2 = 0;
//	else
//		lose2 = 1;
	
		
}

void addSize2(){
	if (body_length2 < max_length){
		int pre_length = body_length2;
		body_length2+=5;
		if(body_length2 > max_length){
			body_length2 = max_length;
		}
		score2 = body_length2;
		int i;
		
//		setPixel(Body2[body_length2 - 2].x,Body2[body_length2 - 2].y,body_char);
		updateGame();
	}
}

int itsOver2(){
	return lose2;
}


void debug2(){
	int i;
	printf("HEAD -> %d, %d",Head2.x,Head2.y);
//	for(i = 0; i<5;i++){
//		printf("\n%d , %d",Body2[i].x,Body2[i].y);
//	}
	 printf(" ||| Score: %d, food -> %d, %d",body_length2, Food.x,Food.y);
}

int getScore2(){
	return score2;
}

int getLives2(){
	return lives2;
}

void gameOver2(){
	printf("\n\n                         ");
	printf("%s ha perdido :(\n\n          Presione la tecla de espacio para volver a jugar",player2);
	while(getch() != ' ');
	newGame();
}
void born2(){
	if(lives2 > 0){
		updateGame();
		ScreenUpdate();
		body_length2 = initial_length;
		score2 = initial_length;
		setHead2();
		lose2 = 0;
		//se inicia el cuerpo de la serpiente
		
		/* -y = arriba	  +x = derecha	   +y = abajo	  -x = izquierda   */
		int i;
		if(Head2.dir == 0){
			
				
			for (i = 0; i < initial_length ; i++){
				Body2[i].y = Head2.y + 1 + i;
				Body2[i].x = Head2.x;
			}	
		}
		else if(Head2.dir == 2){
			for (i = 0; i < initial_length ; i++){
				Body2[abs(i - initial_length + 1)].y = Head2.y - initial_length + i;
				Body2[i].x = Head2.x;
			}
		}
		else if(Head2.dir == 1){
			for (i = 0; i < initial_length ; i++){
				Body2[abs(i - initial_length + 1)].x = Head2.x - initial_length + i;
				Body2[i].y = Head2.y;
			}
		}
		else if(Head2.dir == 3){
			for (i = 0; i < initial_length ; i++){
				Body2[i].x = Head2.x + 1 + i;
				Body2[i].y = Head2.y;
			}
		}
		sleep(1);
	}
	else{
		updateGame();
		ScreenUpdate();
		gameOver2();	
	}
}

