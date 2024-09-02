#define MENU_H
#ifdef MENU_H
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "book.h"
#include "person.h"
using namespace std;

// Menu 1 Search book
void menu1(BookLinkedListPtr, PersonLinkedListPtr);
// Menu 2 Rent book
void menu2(BookLinkedListPtr, PersonLinkedListPtr);
// Menu 3 Return book
void menu3(BookLinkedListPtr, PersonLinkedListPtr);
// Menu 4 Show my information
void menu4(BookLinkedListPtr, PersonLinkedListPtr);
// Menu 5 Show all books
void menu5(BookLinkedListPtr);

#endif MENU_H