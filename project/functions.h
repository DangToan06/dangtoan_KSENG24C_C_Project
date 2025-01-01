#include "datatypes.h"

void menu();
void Admin();
void User();
void Yes();
void No();
void End();
void MenuUser();
void MenuAdmin();
void Status();
void AddBook(Book book[],int *n);
void DeleteBook(Book book[], int *n);
void EditBook(Book book[], int n);
void ShowAllBook();
void SearchBook();
void saveBookToFile(Book book[],int n);
void showAllBookFile(Book book[], int n);
void checkInput(int *n);
void checkInputFloat(double *n);
void checkInputPublication(int *day,int *month,int *years);
int checkInputCharater(char *string, char charater);
void delete(Book book[], int *n);