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
int cardholdnum[N_MAX_CARDHOLD]; //card number that players hold
int cardSum[N_MAX_USER];					//sum of the cards
int bet[N_MAX_USER];						//current betting 
int gameEnd = 0; 							//game end flag
int roundnum=1;

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
	int i;
	int bet;
	
	printf(" ------- BETTING STEP -------\n");
	printf("-> your betting (total:$%d) :",N_DOLLAR);
	scanf("%d",bet);
	
	if (bet>N_DOLLAR){
	
		printf("bet again.");
		return betDollar();}	
			
	N_DOLLAR=N_DOLLAR-bet;
	
	for (i=1;i<n_user;i++){
		
		bet[i] = rand()% N_MAX_BET+1;
		printf("-> player%d bets $%d (out of $%d)\n",i,bet[i],dollar[i]);}
		
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
		return 1;}
		
}	



void printUserCardStatus(int user, int cardcnt) {
	int i;
	
	printf("   -> card : ");
	for (i=0;i<cardcnt;i++)
		printCard(cardhold[user][i]);
	printf("\t ::: ");
}




// calculate the card sum
int calcStepResult(int user, int cardcnt) {
	
	int i;
	cardSum[user]=0;
	
	for (i=0; i<cardcnt;i++){
		cardSum[user]+=cardnum;
	}
	
	//see if : 1. under 21, 2. over 21, 3. blackjack

	if(cardSum[user]<21){
		printf("(%d)", cardSum[user]);
		return 1;
	}

	else if(cardSum[user]>21){
		printf("(%d)",cardSum[user]);
		return 2;
	}

	else{
		printf("(%d, blackjack)", cardSum[user]);

		return 3;
	}
	
}

int checkResult() {
	int i;
	printf("------------------------------------------------\n------------ ROUND %d result...", roundnum);

	printf("   -> your result : "); //your result
	
	if(cardSum[0]<=21&&cardSum[n_user]<=21)//not blackjack, not overflow
	{
			if(cardSum[0]>=cardSum[n_user]) 
			{ 
				printf("win!\n");
				dollar[0]=dollar[0]+bet[0];

				printf("(sum:%d) --> $%d\n",cardSum[0],dollar[0]);}

			else if(cardSum[0]<cardSum[n_user])
			{
				printf("lose!\n");
				dollar[0]=dollar[0]-bet[0];
				printf("(sum:%d) --> $%d\n",cardSum[0],dollar[0]);}

			else if(cardSum[n_user]==21)
			{	
					printf("lose!\n");
					dollar[0]=dollar[0]-bet[0];

					printf("(sum:%d) --> $%d\n",cardSum[0],dollar[0]);	

			}

				else if(cardSum[0]==21)
				{
					printf("win!\n");

					dollar[0]=dollar[0]+bet[0]+bet[];
					printf("(sum:%d) --> $%d\n",cardSum[0],dollar[0]);

				}

			}

		else if(cardSum[0]>21)
		{
			printf("lose due to overflow!\n");
			printf("(sum:%d)\n",cardSum[0]);
		}

		else if(cardSum[n_user]>21)
		{
			if(cardSum[0]<=21)
			{
				printf("win!\n");
				dollar[0]=dollar[0]+bet[0];
				printf("(sum:%d) --> %d\n",cardSum[0],dollar[0]);
			}

			else if(cardSum[0]>21)
			{
				printf("lose due to overflow!\n");	
				printf("(sum:%d)\n",cardSum[0]);
				printf("(sum:%d) --> $%d\n",cardSum[0],,dollar[0]);	
			}

		}

	
	//players result

	for(i=1;i<n_user;i++){
		printf("   -> %d'th player's result : ",i);
		
		if(cardSum[i]<=21&&cardSum[n_user]<=21){
			if(cardSum[i]>=cardSum[n_user]) 
			{ 
				printf("win!\n");
				dollar[i]=dollar[i]+bet[i];
				printf("(sum:%d) --> $%d\n",cardSum[i],dollar[i]);
			}

			else if(cardSum[i]<cardSum[n_user])
			{
				printf("lose!\n");
				dollar[i]=dollar[i]-bet[i];
				printf("(sum:%d) --> $%d\n",cardSum[i],dollar[i]);
			}

			else if(cardSum[n_user]==21)
			{	
				if(cardSum[i]!=21)
				{
					printf("lose!\n");
					dollar[i]=dollar[i]-bet[i];
					printf("(sum:%d) --> $%d\n",cardSum[i],dollar[i]);	
				}

				else if(cardSum[i]==21)
				{
					printf("win!\n");
					dollar[i]=dollar[i]+bet[i]+bet[i];
					printf("(sum:%d) --> $%d\n",cardSum[i],dollar[i]);
				}
			}

		}

		else if(cardSum[n_user]>21)

		{

			if(cardSum[i]<=21)

			{
				printf("win!\n");
				dollar[i]=dollar[i]+bet[i];
				printf("(sum:%d) --> $%d\n",cardSum[i],dollar[i]);

			}

			else if(cardSum[i]>21)
			{
				printf("lose due to overflow!\n");	
				dollar[i]=dollar[i]-bet[i];
				printf("(sum:%d) --> $%d\n",cardSum[i],dollar[i]);
			}
		}

		else if(cardSum[i]>21)
		{
			printf("lose due to overflow!\n");
			dollar[i]=dollar[i]-bet[i];
			printf("(sum:%d) --> $%d\n",cardSum[i],dollar[i]);
		}
	}	
}

int checkWinner() {
	
	printf(" -------------------------------------------\n");
	printf("game end! your money :$ %d",dollar[0]);
	
	int i;
	
	for(i=1;i<n_user;i++){
		printf("players's money :$%d $%d $%d\n",dollar[i]);}
	
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
