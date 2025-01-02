#include<stdio.h>
#include"functions.h"
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<ctype.h>

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

void checkInput(int *n){
	char check;
	while(1){
		if(scanf("%d", n) != 1){
			printf("\033[31m\nERROR!!!YOU MUST ENTER INTEGEN:\033[0m ");
			while((check = getchar()) != '\n' && check != EOF);
		}else{
			break;
		}
	}
}

void checkInputFloat(double *n){
	char check;
	while(1){
		if(scanf("%lf", n) != 1){
			printf("\033[31m\nERROR!!!YOU MUST ENTER INTEGEN OR FLOAT:\033[0m ");
			while((check = getchar()) != '\n' && check != EOF);
		}else{
			break;
		}
	}
}

void checkInputPublication(int *day, int *month, int *years){
    int checkDay, checkMonth, checkYear;
    do {
        checkDay = 0, checkMonth = 0, checkYear = 0;
        scanf("%d %d %d", day, month, years);
        
        if (*years > 0) {
            checkYear = 1;
        }
        
        switch (*month) {
            case 1:
			case 3:
			case 5:
			case 7:
			case 8:
			case 10:
			case 12:
                if (*day <= 31 && *day >= 1) {
                    checkDay = 1;
                }
                checkMonth = 1;
                break;
            case 2:
                if (*years % 400 == 0 || (*years % 4 == 0 && *years % 100 != 0)) {
                    if (*day <= 29 && *day >= 1) {
                        checkDay = 1;
                    }
                } else {
                    if (*day <= 28 && *day >= 1) {
                        checkDay = 1;
                    }
                }
                checkMonth = 1;
                break;
            case 4:
			case 6:
			case 9:
			case 11:
                if (*day <= 30 && *day >= 1) {
                    checkDay = 1;
                }
                checkMonth = 1;
                break;
        }
        
        if (!checkDay || !checkMonth || !checkYear) {
            printf("\033[31mWARNING: THE DATE YOU ENTER IS INVALID. PLEASE RE-ENTER:\033[0m ");
        }
    } while (!checkDay || !checkMonth || !checkYear);
}

int checkInputCharater(char *string, char charater){

	for(int i = 0; i < strlen(string); i++){
		string[i] = toupper(string[i]);
		if(string[i] == charater){
			return 1;
		}
	}
	return 0;
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
	printf("[6] Sorting.\n");
	printf("[7] Status.\n");
	printf("[0] Exit program.\n");
	printf("========================\n");
	printf("Enter the choice: ");
}

void MenuStatus(){
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

void MenuSorting(Book book[], int n){
	int choice = -1;
	char check;
	system("cls");
	printf("\033[32m***LIBRARY MANAGEMENT***\033[0m\n");
	printf("Menu Status\n");
	printf("========================\n");
	printf("[1] Up sort.\n");
	printf("[2] Down sort.\n");
	printf("========================\n");
	printf("Enter the choice: ");
	while(1){
		if(scanf("%d", &choice) != 1){
			printf("\033[31m\nERROR!!!YOU MUST ENTER [1][2]:\033[0m ");
			while((check = getchar()) != '\n' && check != EOF);
		}else if(choice < 0 || choice > 3){
			printf("\033[31m\nERROR!!!YOU MUST ENTER [1][2]:\033[0m ");
		}else{
			break;
		}
	}
	switch (choice){
		case 1:
			UpSort(book,n);
			saveSortBook(book,n);
			break;
		case 2:
			DownSort(book,n);
			saveSortBook(book,n);
			break;
	}
}

void UpSort(Book book[], int n){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n - i - 1; j++){
			if(book[j].price < book[j+1].price){
				Book temp = book[j];
				book[j] = book[j + 1];
				book[j + 1] = temp;
			}
		}
	}
}

void DownSort(Book book[], int n){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n - i - 1; j++){
			if(book[j].price > book[j+1].price){
				Book temp = book[j];
				book[j] = book[j + 1];
				book[j + 1] = temp;
			}
		}
	}
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
	char check;
	system("cls");
	printf("\033[32m***LIBRARY MANAGEMENT***\033[0m\n");
	printf("========================\n");
	printf("Nhap so luong sach ban muon them: ");
	checkInput(&number);
	for(int i = *n;i < *n + number; i++){
		getchar();
		int temp = i + 1;
		sprintf(book[i].bookId, "%d", temp);
		printf("Enter name book: ");
		InformationCannotBeLeftBlank(book[i].title);
		lowercaseSwap(book[i].title,strlen(book[i].title));
		uppercaseFirstLetter(book[i].title);
		book[i].title[strcspn(book[i].title,"\n")] = '\0';
		printf("Enter author book: ");
		InformationCannotBeLeftBlank(book[i].author);
		lowercaseSwap(book[i].author,strlen(book[i].author));
		uppercaseFirstLetter(book[i].author);
		book[i].author[strcspn(book[i].author,"\n")] = '\0';
		printf("Enter quantity: ");
		checkInput(&book[i].quantity);
		printf("Enter price: ");
		checkInputFloat(&book[i].price);
		getchar();
		printf("Enter publication: ");
		checkInputPublication(&book[i].publication.day, &book[i].publication.month, &book[i].publication.year);
	}
	*n = *n + number;	
}

void InformationCannotBeLeftBlank(char str[]){
	int check = 0;
	fgets(str,30,stdin);
	do{
		for(int i = 0; i < strlen(str); i++){
			if(str[i] != '\n'){
				check ++;
			}
		}
		if(check == 0){
			printf("\n\033[31mEnter Again:\033[0m ");
			fgets(str,30,stdin);
			str[strcspn(str,"\n")] = '\0';
		}
	}while(check == 0);
}

void saveBookToFile(Book book[], int n){
	getchar();
	int choice;
	FILE *fptr = fopen("dataBook.bin", "wb");
	if(fptr == NULL){
		printf("\033[31mError open file!!!\n");
		printf("PLEASE ENTER RANDOM KEYBOARD TO EXIT!!!\033[0m");
		getchar();
		return;
	}
	fwrite(book,sizeof(Book),n,fptr);
	printf("\033[32mSave the file successfully!!!\033[0m");
	fclose(fptr);
	printf("\nEnter '0' to Exit: ");
	scanf("%d", &choice);
}

void saveSortBook(Book book[], int n){
	getchar();
	int choice;
	FILE *fileOpen = fopen("sortBook.bin", "wb");
	if(fileOpen == NULL){
		printf("\033[31mError open file!!!\n");
		printf("PLEASE ENTER RANDOM KEYBOARD TO EXIT!!!\033[0m");
		getchar();
		return;
	}
	fwrite(book,sizeof(Book),n,fileOpen);
	fclose(fileOpen);
	Book readFile[1000];
	FILE *fileRead = fopen("sortBook.bin", "rb");
	if(fileRead == NULL){
		printf("\033[31mError open file!!!\n");
		printf("PLEASE ENTER RANDOM KEYBOARD TO EXIT!!!\033[0m");
		getchar();
		return;
	}
	n = fread(readFile, sizeof(Book), 1000, fileRead);
	printf("\n***BOOKS AFTER SORTNG***\n\n");
	printf("|==========|==============================|====================|==========|====================|==========|");
	printf("\n|ID\t   |BOOK\t\t\t  |AUTHOR\t       |QUANTITY  |PRICE\t       |PUBL\t  |\n");
	printf("|==========|==============================|====================|==========|====================|==========|");
	for(int i=0;i<n;i++){
		printf("\n|%-10s|",readFile[i].bookId);
		printf("%-30s|",readFile[i].title);
		printf("%-20s|",readFile[i].author);
		printf("%-10d|",readFile[i].quantity);
		printf("%-20.3lf|",readFile[i].price);
		printf("%-2d/%-2d/%-4d|", readFile[i].publication.day, readFile[i].publication.month, readFile[i].publication.year);
		printf("\n|----------|------------------------------|--------------------|----------|--------------------|----------|");
	}
	
	printf("\n\n\033[32mSorting success!!!\033[0m\n");
	fclose(fileRead);
	printf("\nEnter '0' to back: ");
	scanf("%d", &choice);

}

void showAllBookFile(Book book[], int n){
	system("cls");
	int choice;
	Book readFile[1000];
	FILE *fptr = fopen("dataBook.bin", "rb");
	if(fptr == NULL){
		printf("\033[31mError open file!!!\n");
		printf("PLEASE ENTER RANDOM KEYBOARD TO EXIT!!!\033[0m");
		getchar();
		return;
	}
	n = fread(readFile, sizeof(Book), 1000, fptr);
	printf("***ALL BOOKS***\n\n");
	printf("|==========|==============================|====================|==========|====================|==========|");
	printf("\n|ID\t   |BOOK\t\t\t  |AUTHOR\t       |QUANTITY  |PRICE\t       |PUBL\t  |\n");
	printf("|==========|==============================|====================|==========|====================|==========|");
	for(int i=0;i<n;i++){
		printf("\n|%-10s|",readFile[i].bookId);
		printf("%-30s|",readFile[i].title);
		printf("%-20s|",readFile[i].author);
		printf("%-10d|",readFile[i].quantity);
		printf("%-20.3lf|",readFile[i].price);
		printf("%-2d/%-2d/%-4d|", readFile[i].publication.day, readFile[i].publication.month, readFile[i].publication.year);
		printf("\n|----------|------------------------------|--------------------|----------|--------------------|----------|");
	}
	
	printf("\n\n\033[32mLAY DU LIEU THANH CONG\033[0m\n");
	fclose(fptr);
	printf("\nEnter '0' to back: ");
	scanf("%d", &choice);
}

void EditBook(Book book[], int n){
	system("cls");
	getchar();
	int flag = -1;
	char position[10];
	printf("Enter the book id you want to edit: ");
	scanf("%s", position);
	do{
	flag = -1;
	for(int i = 0; i < n; i++){
		if(strcmp(book[i].bookId, position) == 0){
			flag = i;
		}
	}
	if(flag == -1){
		printf("\033[31mBook id dose NOT EXSIT!!\033[0m");
		printf("\033[31m\nPLEASE ENTER AGAIN: \033[0m");
		scanf("%s", position);
	}
	}while(flag == -1);
	Book readFile[1000];
	FILE *fptr = fopen("dataBook.bin", "rb");
	if(fptr == NULL){
		printf("\033[31mError open file!!!\n");
		printf("PLEASE ENTER RANDOM KEYBOARD TO EXIT!!!\033[0m");
		getchar();
		return;
	}
	n = fread(readFile, sizeof(Book), 1000, fptr);
	printf("\n\033[36m***THE INFOR OLD BOOK***\033[0m\n");
	printf("\nBook id: %s",readFile[flag].bookId);
	printf("\nBook name: %s",readFile[flag].title);
	printf("\nAuthor: %s",readFile[flag].author);
	printf("\nQuantity: %d",readFile[flag].quantity);
	printf("\nPrice: %.3lf",readFile[flag].price);
	printf("\nPublication: %d/%d/%d\n", readFile[flag].publication.day, readFile[flag].publication.month, readFile[flag].publication.year);
	fclose(fptr);
	printf("\n\033[36m***UPDATE THE NEW BOOK***\033[0m\n");
	getchar();
	printf("Enter name book: ");
	fgets(book[flag].title,30,stdin);
	book[flag].title[strcspn(book[flag].title,"\n")] = '\0';
	printf("Enter author book: ");
	fgets(book[flag].author,20,stdin);
	book[flag].author[strcspn(book[flag].author,"\n")] = '\0';
	printf("Enter quantity: ");
	checkInput(&book[flag].quantity);
	printf("Enter price: ");
	checkInputFloat(&book[flag].price);
	getchar();
	printf("Enter publication: ");
	checkInputPublication(&book[flag].publication.day, &book[flag].publication.month, &book[flag].publication.year);
}

void Delete(Book book[], int *n, char positionDelele[]){
	for(int i = atoi(positionDelele) - 1; i < *n; i++){
		book[i] = book[i+1];
	}
	*n = *n - 1;
}
   
void DeleteBook(Book book[], int n){
	system("cls");
	getchar();
	int flag = -1;
	char position[10];
	char userChoice[10];
	char temp[10];
	printf("Enter id you want to delete: ");
	scanf("%s", position);
	do{
		flag = -1;
		for(int i = 0; i < n; i++){
			if(strcmp(book[i].bookId , position) == 0){
				flag = i;
			}
		}
		if(flag == -1){
			printf("\033[31mBook id dose NOT EXSIT!!\033[0m");
			printf("\033[31m\nPLEASE ENTER AGAIN:\033[0m ");
			scanf("%s", position);
		}
	}while(flag == -1);
	Book readBook[10];
	FILE *fptr = fopen("dataBook.bin", "rb");
	if(fptr == NULL){
		printf("\033[31mERROR OPEN FILE!!!");
		printf("PLEASE ENTER RANDOM KEYBOARD TO EXIT!!!\033[0m");
		getchar();
		return;
	}
	n = fread(readBook,sizeof(Book),10,fptr);
	printf("\n\033[36m***BOOKS BEFORE DELETE***\033[0m\n");
	printf("\nBook id: %s",readBook[flag].bookId);
	printf("\nBook name: %s",readBook[flag].title);
	printf("\nAuthor: %s",readBook[flag].author);
	printf("\nQuantity: %d",readBook[flag].quantity);
	printf("\nPrice: %.3lf",readBook[flag].price);
	printf("\nPublication: %d/%d/%d\n", readBook[flag].publication.day, readBook[flag].publication.month, readBook[flag].publication.year);
	fclose(fptr);
	printf("\n\033[36mAre you sure want to delete this book? (Y/N):\033[0m ");
	int check = 0;
	char yes = 'Y';
	char no = 'N';
	scanf("%s", userChoice);
	while(1){
		if(checkInputCharater(userChoice,yes)){
			Delete(book, &n, position);
			printf("\n\033[32mBooks delete success!!!\033[0m\n");
			saveBookToFile(book,n);
			getchar();
			break;
		}else if(checkInputCharater(userChoice,no)){
			printf("\n\033[33mBooks delete failed!!!\033[0m");
			printf("\nPLEASE ENTER RANDOM KEYBOARD TO EXIT!!!");
			getchar();
			getchar();
			break;
		}else{
			printf("\n\033[31mERROR.You must enter [Y/N], enter again:\033[0m ");
			scanf("%s", userChoice);
		}
	}
	
}

void uppercaseFirstLetter(char nameBook[]) {
    int check = 0;
	int length = strlen(nameBook);
    for(int i = 0; i < length; i++){
    	if(!check&& isalpha(nameBook[i])){
			nameBook[i] = toupper(nameBook[i]);
			check = 1;    		
		}else if(isspace(nameBook[i])){
			check = 0;
		}
	}
}

void lowercaseSwap(char nameBook[], int n){
	for(int i = 0; i < n; i++){
		nameBook[i] = tolower(nameBook[i]);
	}
}

void SearchBook(Book book[], int n){
	system("cls");
	getchar();
	char inportNameBook[30];
	int flag = -1;
	printf("Enter the book title: ");
	fgets(inportNameBook,30,stdin);
	inportNameBook[strcspn(inportNameBook,"\n")] = '\0';
	lowercaseSwap(inportNameBook,n);
	uppercaseFirstLetter(inportNameBook);
	for(int i = 0; i < n ; i++){
		if(strcmp(book[i].title,inportNameBook) == 0){
			flag = i;
		}
	}
	if(flag == -1){
		printf("\n\033[31mBOOK NOT FOUND\033[0m");
		printf("\nEnter random keyboard to continute....");
		getchar();
	}else{
		Book readFile[1000];
		FILE *fptr = fopen("dataBook.bin", "rb");
		if(fptr == NULL){
			printf("\033[31mError open file!!!\n");
			printf("PLEASE ENTER RANDOM KEYBOARD TO EXIT!!!\033[0m");
			getchar();
			return;
		}
		n = fread(readFile, sizeof(Book), 1000, fptr);
		printf("\n|==========|==============================|====================|==========|====================|==========|");
		printf("\n|ID\t   |BOOK\t\t\t  |AUTHOR\t       |QUANTITY  |PRICE\t       |PUBL\t  |\n");
		printf("|==========|==============================|====================|==========|====================|==========|");
		printf("\n|%-10s|",readFile[flag].bookId);
		printf("%-30s|",readFile[flag].title);
		printf("%-20s|",readFile[flag].author);
		printf("%-10d|",readFile[flag].quantity);
		printf("%-20.3lf|",readFile[flag].price);
		printf("%-2d/%-2d/%-4d|", readFile[flag].publication.day, readFile[flag].publication.month, readFile[flag].publication.year);
		printf("\n|----------|------------------------------|--------------------|----------|--------------------|----------|\n");
		fclose(fptr);
		printf("\nPLEASE ENTER RANDOM KEYBOARD TO EXIT...\033[0m");
		getchar();
	}
}

