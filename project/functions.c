#include<stdio.h>
#include"functions.h"
#include<stdlib.h>
#include<string.h>
#include<conio.h>

void menu(){
	system("cls");
	printf("\033[32m***LIBRARY MANAGEMENT***\033[0m");
	printf("\n    CHOOSE YOUR ROLE");
	printf("\n========================");
	printf("\n[1] Admin.");
	printf("\n[2] User.");
	printf("\n[0] Exit the Program.");
	printf("\n========================");
	printf("\nEnter The Choice: ");
}

void getPassWordAdmin(char *pass, int length){
    int i = 0;
    char ch;
    while (i < length - 1) {
        ch = getch();
		if(length > 21){
			break;
		}
        if (ch == 13){
            break;
        }
        if (ch == 8){
            if (i > 0) {
                printf("\b \b");
                i--;
            }
        } else {
            printf("*");
            pass[i++] = ch;
        }
    }
    pass[i] = '\0';

}

void Admin(){
	system("cls");
	printf("\033[32m***LIBRARY MANAGEMENT***\033[0m\n");
	printf("LOG IN\n");
	printf("========================\n");
	getchar();
	char AdminInput[20]; char AdminPass[20];
	printf("Admin: ");
	fgets(AdminInput, sizeof(AdminInput), stdin);
	AdminInput[strlen(AdminInput) - 1] = '\0';
	printf("Password(max 20 charate): ");
	getPassWordAdmin(AdminPass,20);
	printf("========================\n");
}

void User(){
	system("cls");
	printf("\033[32m***LIBRARY MANAGEMENT***\033[0m\n");
	printf("DO YOU HAVE ACCOUNT\n");
	printf("[1] YES.\n");
	printf("[2] NO.\n");
	printf("[0] Exit.\n");
	printf("Enter The Choice: ");
}

void Yes(){
	system("cls");
	printf("\033[32m***LIBRARY MANAGEMENT***\033[0m\n");
	printf("ENTER YOUR ACCOUNT\n");
	printf("========================\n");
	getchar();
	char userInput[20]; char userPass[20];
	printf("User: ");
	fgets(userInput, sizeof(userInput), stdin);
	userInput[strlen(userInput) - 1] = '\0';
	printf("Password: ");
	fgets(userPass, sizeof(userPass), stdin);
	userPass[strlen(userPass) - 1] = '\0';
	printf("========================\n");
}

void No(){
	system("cls");
	printf("\033[32m***LIBRARY MANAGEMENT***\033[0m\n");
	printf("CREATIVE YOUR ACCOUNT\n");
	printf("========================\n");
	getchar();
	char userCreInput[20]; char userCrePass[20];
	printf("User: ");
	fgets(userCreInput, sizeof(userCreInput), stdin);
	userCreInput[strlen(userCreInput) - 1] = '\0';
	printf("Password: ");
	fgets(userCrePass, sizeof(userCrePass), stdin);
	userCrePass[strlen(userCrePass) - 1] = '\0';
	printf("========================\n");
}

void End(){
	system("cls");
	printf("========= THANK YOU =========\n");
	printf("======== SEE YOU SOON =======\n");
	printf("\n");
	printf("_____________________________\n");
}

void MenuAdmin(){
	system("cls");
	printf("\033[32m***LIBRARY MANAGEMENT***\033[0m\n");
	printf("Menu admin\n");
	printf("========================\n");
	printf("[1] Add a new book.\n");
	printf("[2] Delete a book.\n");
	printf("[3] Edit a book.\n");
	printf("[4] Show all books.\n");
	printf("[5] Search a book,\n");
	printf("[6] Status.\n");
	printf("[0] Exit program.\n");
	printf("========================\n");
	printf("Enter the choice: ");
}

void Status(){
	int choice = -1;
	system("cls");
	printf("\033[32m***LIBRARY MANAGEMENT***\033[0m\n");
	printf("Menu Status\n");
	printf("========================\n");
	printf("[1] Phieu muon.\n");
	printf("[2] Phieu tra.\n");
	printf("Press 'b' to back or '0' return Menu\n");
	printf("========================\n");
	printf("Enter the choice: ");
	scanf("%d", &choice);
}

void MenuUser(){
	int choice = -1;
	system("cls");
	printf("\033[32m***LIBRARY MANAGEMENT***\033[0m\n");
	printf("Menu user\n");
	printf("========================\n");
	printf("[1] Muon sach.");
	printf("[2] ");
	scanf("%d", &choice);
}

void AddBook(Book book[],int *n){
	int number;
	system("cls");
	printf("\033[32m***LIBRARY MANAGEMENT***\033[0m\n");
	printf("========================\n");
	printf("Nhap so luong sach ban muon them: ");
	scanf("%d", &number);
	for(int i = *n; i < *n + number; i++){
		getchar();
		int temp = i + 1;
		sprintf(book[i].bookId, "%d", temp);
		printf("Enter name book: ");
		fgets(book[i].title,30,stdin);
		book[i].title[strcspn(book[i].title,"\n")] = '\0';
		printf("Enter author book: ");
		fgets(book[i].author,20,stdin);
		book[i].author[strcspn(book[i].author,"\n")] = '\0';
		printf("Enter quantity: ");
		scanf("%d", &book[i].quantity);
		printf("Enter price: ");
		scanf("%lf",&book[i].price);
		printf("Enter publication: ");
		scanf("%d %d %d", &book[i].publication.day, &book[i].publication.month, &book[i].publication.year);
	}
	*n = *n + number;	
}

void saveBookToFile(Book book[], int n){
	int choice;
	FILE *fptr = fopen("dataBook.bin", "wb");
	if(fptr == NULL){
		printf("\033[31mError open file!!!\033[0m");
		return;
	}
	fwrite(book,sizeof(Book),n,fptr);
	printf("Save the file successfully");
	fclose(fptr);
	printf("\nEnter '0' to exit: ");
	scanf("%d", &choice);
}

void showAllBookFile(Book book[], int n){
	system("cls");
	int choice;
	Book readFile[1000];
	FILE *fptr = fopen("dataBook.bin", "rb");
	if(fptr == NULL){
		printf("\033[31mError open file!!!\033[0m");
		return;
	}
	n = fread(readFile, sizeof(Book), 1000, fptr);
	printf("***ALL BOOKS***\n\n");
	printf("|==========|==============================|====================|==========|====================|==========|");
	printf("\n|ID\t   |BOOK\t\t\t  |AUTHOR\t       |QUAN\t  |PRICE\t       |PUBL\t  |\n");
	printf("|==========|==============================|====================|==========|====================|==========|");
	for(int i=0;i<n;i++){
		printf("\n|%-10s|",readFile[i].bookId);
		printf("%-30s|",readFile[i].title);
		printf("%-20s|",readFile[i].author);
		printf("%-10d|",readFile[i].quantity);
		printf("%-20lf|",readFile[i].price);
		printf("%-2d/%-2d/%-4d|", readFile[i].publication.day, readFile[i].publication.month, readFile[i].publication.year);
		printf("\n|----------|------------------------------|--------------------|----------|--------------------|----------|");
	}
	
	printf("\n\n\033[32mLAY DU LIEU THANH CONG\033[0m\n");
	fclose(fptr);
	printf("\nEnter '0' to back: ");
	scanf("%d", &choice);
}
    
