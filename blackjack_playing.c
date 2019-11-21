#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "blackjack_play"
#include "blackjack_after"
#include "blackjack_before"

#define N_CARDSET			1
#define N_CARD				52
#define N_DOLLAR			50


#define N_MAX_CARDNUM		13
#define N_MAX_USER			5
#define N_MAX_CARDHOLD		10
#define N_MAX_GO			17
#define N_MAX_BET			5

#define N_MIN_ENDCARD		30	

//card tray object
extern int CardTray[N_CARDSET*N_CARD];
extern int cardIndex = 0;							


//player info
extern int dollar[N_MAX_USER];						//dollars that each player has
extern int n_user;									//number of users


//play yard information
extern int cardhold[N_MAX_USER+1][N_MAX_CARDHOLD];	//cards that currently the players hold
extern int cardholdnum[N_MAX_CARDHOLD]; //card number that players hold
extern int cardSum[N_MAX_USER];					//sum of the cards
extern int bet[N_MAX_USER];						//current betting 
extern int gameEnd = 0; 							//game end flag
extern int roundnum=1;




int main(int argc, char *argv[]) {
	int roundIndex = 0;
	int max_user;
	int i;
	
	srand((unsigned)time(NULL));
	
	//set the number of players
	configUser();


	//Game initialization --------
	//1. players' dollar
	
	//2. card tray
	mixCardTray();



	//Game start --------
	do {
		printf("------------------------------------------------\n");
		printf("------------ ROUND %d (cardIndex:%d)--------------------------\n");
		printf("------------------------------------------------\n", roundnum, cardIndex);
		
		betDollar();
		offerCards(); //1. give cards to all the players
		
		printCardInitialStatus();
		printf("\n------------------ GAME start --------------------------\n\n");
		
		//your turn
		printf(">>> my turn! -------------\n");
		printUserCardStatus(int user, int cardcnt);
		getAction(void)
		
		
		//each player's turn
		for (i=0; i=n_user; i++) //each player
		{
			cardholdnum[]=2;
			while (1) //do until the player dies or player says stop
			{
				printf(">>> player %d turn! -------------\n",n_user)
				printUserCardStatus(int user, int cardcnt);
				calcStepResult(int user, int cardcnt)
				
				if (cardSum>=17){				
					printf("       ::STAY!");}
				else{				
					printf("       ::GO!");}
				
				//check if the turn ends or not
			}
		}
		
		//result
		checkResult();
		roundnum++;
	} while (gameEnd == 0);
	
	checkWinner();
	
	
	return 0;
}
