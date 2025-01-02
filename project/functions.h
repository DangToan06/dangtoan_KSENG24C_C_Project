#include "datatypes.h"

void menu();
void Admin();
void User();
void Yes();
void No();
void End();
void MenuUser();
void MenuAdmin();
void MenuStatus();
void AddBook(Book book[],int *n);
void DeleteBook(Book book[], int n);
void EditBook(Book book[], int n);
void SearchBook(Book book[], int n);
void saveBookToFile(Book book[],int n);
void showAllBookFile(Book book[], int n);
void checkInput(int *n);
void checkInputFloat(double *n);
void checkInputPublication(int *day,int *month,int *years);
int checkInputCharater(char *string, char charater);
void Delete(Book book[], int *n, char positionDelele[]);
void MenuSorting(Book book[], int n);
void UpSort(Book book[], int n);
void DownSort(Book book[], int n);
void saveSortBook(Book book[], int n);
void lowercaseSwap(char nameBook[], int n);
void uppercaseFirstLetter(char nameBook[]);
void InformationCannotBeLeftBlank(char str[]);