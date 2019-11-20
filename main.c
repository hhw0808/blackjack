#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
int CardTray[N_CARDSET*N_CARD];
int cardIndex = 0;							


//player info
int dollar[N_MAX_USER];						//dollars that each player has
int n_user;									//number of users


//play yard information
int cardhold[N_MAX_USER+1][N_MAX_CARDHOLD];	//cards that currently the players hold
int cardSum[N_MAX_USER];					//sum of the cards
int bet[N_MAX_USER];						//current betting 
int gameEnd = 0; 							//game end flag

//some utility functions

//get an integer input from standard input (keyboard)
//return : input integer value
//         (-1 is returned if keyboard input was not integer)
int getIntegerInput(void) {
    int input, num;
    
    num = scanf("%d", &input);
    fflush(stdin);
    if (num != 1) //if it fails to get integer
        input = -1;
    
    return input;
}


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


//betting
int betDollar(void) {
	int bet;
	printf("-> your betting (total:$%d) :",N_DOLLAR);
	scanf("%d",bet);
	
	if (bet>N_DOLLAR){
	
		printf("bet again.");
		return betDollar();}	
			
	N_DOLLAR=N_DOLLAR-bet;
	return 0;
}


//offering initial 2 cards
void offerCards(void) {
	int i;
	//1. give two card for each players
	for (i=0;i<n_user;i++)
	{
		cardhold[i][0] = pullCard();
		cardhold[i][1] = pullCard();
	}
	//2. give two card for the operator
	cardhold[n_user][0] = pullCard();
	cardhold[n_user][1] = pullCard();
	
	return;
}

//print initial card status
void printCardInitialStatus(void) {
	int i;
	printf(" ----------- CARD OFFERING ---------------\n");
	
	printf("--- server: X ");
	printCard(cardhold[n_user][1]);
	printf("\n");
	printf(" -> you: ");

	printCard(cardhold[0][0]);
	printf(" ");
	printCard(cardhold[0][1]);
	printf("\n");

	for(i=1;i<n_user;i++){	

		printf(" -> player %d: ",i);
		printCard(cardhold[i][0]);
		printf(" ");
		printCard(cardhold[i][1]); 
		printf("\n");}

}

	 


int getAction(void) {
	int y;	
	printf(":::Action? 0-go, others-stay");
	scanf("%d", y);
	if (y==0){
		return 0;}
	else{
		return 1;};
		
}	



void printUserCardStatus(int user, int cardcnt) {
	int i;
	
	printf("   -> card : ");
	for (i=0;i<cardcnt;i++)
		printCard(cardhold[user][i]);
	printf("\t ::: ");
}




// calculate the card sum and see if : 1. under 21, 2. over 21, 3. blackjack
int calcStepResult() {
	
	int i;
	cardSum[user]=0;
	
	if
	
	else if
	
	else if
	
}

int checkResult() {
	
}

int checkWinner() {
	
}



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
		
		betDollar();
		offerCards(); //1. give cards to all the players
		
		printCardInitialStatus();
		printf("\n------------------ GAME start --------------------------\n");
		
		//each player's turn
		for (i=0; i=n_user; i++) //each player
		{
			while () //do until the player dies or player says stop
			{
				//print current card status printUserCardStatus();
				//check the card status ::: calcStepResult()
				//GO? STOP? ::: getAction()
				//check if the turn ends or not
			}
		}
		
		//result
		checkResult();
	} while (gameEnd == 0);
	
	checkWinner();
	
	
	return 0;
}
