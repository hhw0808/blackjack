#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(void) {
	int p;
	
	printf("Input the number of players (MAX:5) : ");
	scanf("%d", &p);
	
	if(p>5){
		printf("too many players!\n");
		return main();}
		
	else{
		printf("-->card is mixed and put into the tray");
		return 0;}
	
}
