#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "blackjack_play"
#include "blackjack_after"

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



//card processing functions ---------------

//calculate the actual card number in the blackjack game
int getCardNum(int cardnum) {
	
	if(cardnum%13==1)
		return 1; 

	else if(cardnum%13==2)
		return 2;	

	else if(cardnum%13==3)
		return 3;

	else if(cardnum%13==4)
		return 4;

	else if(cardnum%13==5)
		return 5;	

	else if(cardnum%13==6)
		return 6;

	else if(cardnum%13==7)
		return 7;

	else if(cardnum%13==8)
		return 8;

	else if(cardnum%13==9)
		return 9;

	else if(cardnum%13==10)
		return 10;	

	else if(cardnum%13==11)
		return 10;

	else if(cardnum%13==12)
		return 10;

	else if(cardnum%13==0)
		return 10;
}
	
//print the card information (e.g. DiaA)
void printCard(int cardnum)
{
	char *s[]={"SPD", "DIA", "HRT", "CLV" };	
	char *p[]={ "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
	printf("%s %s", s[cardnum/13], p[cardnum%13]);
}

//card array controllers -------------------------------

//mix the card sets and put in the array
int mixCardTray(void) {
	
	int i;                                             
	srand((unsigned int)time(NULL));    
 	for(i=0;i< N_CARDSET*N_CARD;i++){

        CardTray[i] == i;}
        
    printf(" --> card is mixed and put into the tray");
}

//get one card from the tray
int pullCard(void) {
	return CardTray[cardIndex++]; //next card
}




//playing game functions -----------------------------

//player settiing
int configUser(void) {
	int n_user;
	
	printf("Input the number of players (MAX:5) : ");
	scanf("%d", &n_user);
	
	if(n_user>5){
		printf("too many players!\n");
		return main();}
		
	else{
		return 0;}
	
}
