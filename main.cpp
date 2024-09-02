// Chi Chiu Pong
// 8/13/2023
// CS003A 2023 Summer2 Project 2
// Compiled, built and ran on Microsoft Visual Studio Community Edition 2022 64 bit
// Microsoft .NET Framework Version 4.8.09032

// library header with all the necessary files
#include "menu.h"

// main function to run the library
int main() {
	string filename1 = "book.txt", filename2 = "person.txt";
	BookLinkedListPtr library1 = bookDataStructure(filename1);
	PersonLinkedListPtr library2 = personDataStructure(filename2);
	int choice = 0;
	do {
		cout << "\n-----------------------\n";
		cout << "         Menu\n";
		cout << "-----------------------\n";
		cout << "1. Search a book\n";
		cout << "2. Rent a book\n";
		cout << "3. Return a book\n";
		cout << "4. Show my information\n";
		cout << "5. Show all books\n";
		cout << "6. Exit\n";
		cout << "Select (1~6) : ";
		cin >> choice;
		switch (choice) {
		case(1):
		{
			menu1(library1, library2);
			break;
		}
		case(2):
		{
			menu2(library1, library2);
			break;
		}
		case(3):
		{
			menu3(library1, library2);
			break;}
		case(4):
		{
			menu4(library1, library2);
			break;
		}
		case(5):
		{
			menu5(library1);
			break;
		}
		case(6): {
			cout << "Exiting... ..." << endl;
			exit(1);
		}
		default: {
			cout << "Wrong input\n";
			choice = 1;
			break;}
		}
	} while (choice <= 6 && choice >= 1);
	return 0;
}