/*
 * Author: Anugesh Balasubramaniam
 * Date: Dec 12, 2014 
 * 
 * Tic Tac Toe (2 Player)
 * -- This game allows 2 human players to play
 * -- tic tac toe against each other.
 * 
 * Made for and tested on Linux & Unix systems.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char board[3][3];
char player1 = 'X';
char player2 = 'O';

int gameOver = 0;
int switchPlayer = 0;

// initialize the game board with spaces
void initBoard(){
	
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			board[i][j] = ' ';
		}
	}
}

// check a position to see if it's empty
int checkPosition(char selectedPos){
	
	if (selectedPos != ' '){
		return 1;
	}
	return 0;
}

// place the player's character in the chosen position
int playerMove(char playerChar, int playerPos){
	
	if (playerPos == 1){
		if (checkPosition(board[0][0]) != 0){
			printf("Position is already taken\n\n");
			return 1;
	    }
		board[0][0] = playerChar;
	}
	else if (playerPos == 2){
		if (checkPosition(board[0][1]) != 0){
			printf("Position is already taken\n\n");
			return 1;
	    }
		board[0][1] = playerChar;
	}
	else if (playerPos == 3){
		if (checkPosition(board[0][2]) != 0){
			printf("Position is already taken\n\n");
			return 1;
	    }
		board[0][2] = playerChar;
	}
	else if (playerPos == 4){
		if (checkPosition(board[1][0]) != 0){
			printf("Position is already taken\n\n");
			return 1;
	    }
		board[1][0] = playerChar;
	}
	else if (playerPos == 5){
		if (checkPosition(board[1][1]) != 0){
			printf("Position is already taken\n\n");
			return 1;
	    }
		board[1][1] = playerChar;
	}
	else if (playerPos == 6){
		if (checkPosition(board[1][2]) != 0){
			printf("Position is already taken\n\n");
			return 1;
	    }
		board[1][2] = playerChar;
	}
	else if (playerPos == 7){
		if (checkPosition(board[2][0]) != 0){
			printf("Position is already taken\n\n");
			return 1;
	    }
		board[2][0] = playerChar;
	}
	else if (playerPos == 8){
		if (checkPosition(board[2][1]) != 0){
			printf("Position is already taken\n\n");
			return 1;
	    }
		board[2][1] = playerChar;
	}
	else if (playerPos == 9){
		if (checkPosition(board[2][2]) != 0){
			printf("Position is already taken\n\n");
			return 1;
	    }
		board[2][2] = playerChar;
	}
	
	return 0;
}

// check status of the game (win, draw, or continue)
int checkGameOver(){
	int totalRow1 = 0;
	int totalRow2 = 0;
	int totalRow3 = 0;;
	
	int totalCol1 = 0;
	int totalCol2 = 0;
	int totalCol3 = 0;
	
	int totalDiag1 = 0;
	int totalDiag2 = 0;
	
	int noSpaces = 0;

	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			
			if (board[i][j] == ' '){
				noSpaces = 1;
			}
			
			if ((i == 0) && (board[i][j] == player1)){
				totalRow1 = totalRow1 + 3;
				if (j == 2){
					totalDiag2 = totalDiag2 + 3;
				}
			}else if ((i == 0) && (board[i][j] == player2)){
				totalRow1 = totalRow1 + 5;
				if (j == 2){
					totalDiag2 = totalDiag2 + 5;
				}
			}
			
			if ((i == 1) && (board[i][j] == player1)){
				totalRow2 = totalRow2 + 3;
			}else if ((i == 1) && (board[i][j] == player2)){
				totalRow2 = totalRow2 + 5;
			}
			
			if ((i == 2) && (board[i][j] == player1)){
				totalRow3 = totalRow3 + 3;
				if (j == 0){
					totalDiag2 = totalDiag2 + 3;
				}
			}else if ((i == 2) && (board[i][j] == player2)){
				totalRow3 = totalRow3 + 5;
				if (j == 0){
					totalDiag2 = totalDiag2 + 5;
				}
			}
			
			if ((j == 0) && (board[i][j] == player1)){
				totalCol1 = totalCol1 + 3;
			}else if ((j == 0) && (board[i][j] == player2)){
				totalCol1 = totalCol1 + 5;
			}
			
			if ((j == 1) && (board[i][j] == player1)){
				totalCol2 = totalCol2 + 3;
			}else if ((j == 1) && (board[i][j] == player2)){
				totalCol2 = totalCol2 + 5;
			}
			
			if ((j == 2) && (board[i][j] == player1)){
				totalCol3 = totalCol3 + 3;
			}else if ((j == 2) && (board[i][j] == player2)){
				totalCol3 = totalCol3 + 5;
			}
			
			if ((i == j) && (board[i][j] == player1)){
				totalDiag1 = totalDiag1 + 3;
				if (i == 1){
					totalDiag2 = totalDiag2 + 3;
				}
			}else if ((i == j) && (board[i][j] == player2)){
				totalDiag1 = totalDiag1 + 5;
				if (i == 1){
					totalDiag2 = totalDiag2 + 5;
				}
			}	
		}	
	}
	
	if (totalRow1 == 9 || totalRow2 == 9 || totalRow3 == 9
	|| totalCol1 == 9 || totalCol2 == 9 || totalCol3 == 9
	|| totalDiag1 == 9 || totalDiag2 == 9){
		return 0;
	}
	
	if (totalRow1 == 15 || totalRow2 == 15 || totalRow3 == 15
	|| totalCol1 == 15 || totalCol2 == 15 || totalCol3 == 15
	|| totalDiag1 == 15 || totalDiag2 == 15){
		return 1;
	}
	
	if (noSpaces == 0){
		return 2;
	}
    
	return 3;
}

// display the game board to the screen
void printBoard(){
	for (int i = 0; i < 3; i++){
		printf("        ");
		for (int j = 0; j < 3; j++){
			printf("%c", board[i][j]);
			if(j != 2){
				printf(" | ");
			}
		}
		printf("\n");
		if (i != 2){
			printf("       ___________\n\n");
		}
	}
	printf("\n");
}

// display the game board with position numbers
void welcomeBoard(){
	printf("\n        1 | 2 | 3 \n");
	printf("       ___________\n\n");
	printf("        4 | 5 | 6 \n");
	printf("       ___________\n\n");
	printf("        7 | 8 | 9 \n\n\n");
	printf("Enter the position number of where you want to make your move\n\n");
}

// run and manage the game
void runGame(){
	
	int player = 0;
	int playerPos = 0;
	char inputPos[3] = "0";
	char restInput; 
	
	while(gameOver == 0){
		printf("\n\nPlayer %d's move >> ", player+1);
		scanf(" %[^\n]%*c", inputPos);
		
		printf("\n");
		
		if ((strlen(inputPos) > 1) || (atoi(&inputPos[0]) < 1) || (atoi(&inputPos[0]) > 9)){
			printf("Error! Please enter a number between 1 and 9\n\n");
		}else{
			playerPos = atoi(&inputPos[0]);
			if (player == 0){
				switchPlayer = playerMove(player1, playerPos);
				if (switchPlayer == 0) player = 1;
			}else{
				switchPlayer = playerMove(player2, playerPos);
				if (switchPlayer == 0) player = 0;
			}
		
			printBoard();
		
			if (checkGameOver() == 0){
				printf("GAME OVER! Player 1 is the winner!!\n\n");
				gameOver = 1;
			}else if (checkGameOver() == 1){
				printf("GAME OVER! Player 2 is the winner!!\n\n");
				gameOver = 1;
			}else if (checkGameOver() == 2){
				printf("GAME OVER!! IT'S A DRAW!!!\n\n");
				gameOver = 1;
			}
		}
		
		while(gameOver == 1){
			char newGame[3];
			printf("\n\n1) Start a new game\n2) Exit\n\n");
			printf("What would you like to do now? (1 or 2) >> ");
			scanf("%[^\n]%*c", newGame);
			
			printf("\n\n");
			
			if ((strlen(newGame) > 1) || (atoi(&newGame[0]) < 1) || (atoi(&newGame[0]) > 2)){
				printf("\nError! Please enter either 1 or 2\n\n");
			}else if (atoi(&newGame[0]) == 1){
				system("clear");
				initBoard();
				gameOver = 0;
				player = 0;
				switchPlayer = 0;
				printf("\nYOUR NEW GAME HAS BEGUN!\n\n");
				welcomeBoard();
			}else if (atoi(&newGame[0]) == 2){
				printf("\nTHANK YOU! Please come again!\n\n");
				exit(0);
			}
		}
	}
}

int main (){
	
	//clear the terimnal screen
	system("clear");
	
	//initialize the board
	initBoard();
	
	//print welcome message
	printf("\n********** Welcome to Anugesh's two player Tic Tac Toe Game **********\n");
	printf("********** Player 1 is X ******************** Player 2 is O **********\n\n");
 
	//print game board with position numbers
	welcomeBoard();
	
	//run the game
	runGame();
	
	return 0;
 }
