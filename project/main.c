#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
#include<conio.h>

int main(int argc, char *argv[]){
	int userChoice, choiceUser1, choiceAdmin1;
	int n;
	char check;
	Book book[100];
	do{
		menu();
		while(1){
			if(scanf("%d", &userChoice) != 1){
				printf("\033[31m\nERROR.YOU MUST ENTER [1][2][0]:\033[0m ");
				while((check = getchar()) != '\n' && check != EOF);
			}else if(userChoice < 0 || userChoice > 3){
				printf("\033[31m\nERROR.YOU MUST ENTER [1][2][0]:\033[0m ");
			}else{
				break;
			}
		}
		switch(userChoice){
			case 1:
				Admin();
				do{
					MenuAdmin();
					while(1){
						if(scanf("%d", &choiceAdmin1) != 1){
							printf("\033[31m\nERROR!!!YOU MUST ENTER [1][2][3][4][5][6][0]:\033[0m ");
							while((check = getchar()) != '\n' && check != EOF);
						}else if(choiceAdmin1 < 0 || choiceAdmin1 > 7){
							printf("\033[31m\nERROR!!!YOU MUST ENTER [1][2][3][4][5][6][0]:\033[0m ");
						}else{
							break;
						}
					}
					switch(choiceAdmin1){
						case 1:
							AddBook(book,&n);
							saveBookToFile(book,n);
							break;
						case 2:
							DeleteBook(book,&n);
							break;
						case 3:
							EditBook(book,n);
							saveBookToFile(book,n);
							break;
						case 4:
							showAllBookFile(book, n);
							break;
						case 5:
							break;
						case 6:
							Status();
							break;
					}
				}while(choiceAdmin1 != 0 );
				break;
			case 2:
				User();
				scanf("%d", &choiceUser1);
				switch(choiceUser1){
				case 1:
					Yes();
					MenuUser();
					break;
				case 2:
					No();
					MenuUser();
					break;
				}
				break;
		}
	}while(userChoice != 0);
	End();
	return 0;
}

