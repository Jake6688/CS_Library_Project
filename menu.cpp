#include "menu.h"
#include <string>

// Menu 1 Search book
void menu1(BookLinkedListPtr arr1, PersonLinkedListPtr arr2) {
	cout << "Enter code	: ";
	int tcode;
	cin >> tcode;
    cout << "Enter title : ";
	string ttitle;
	cin >> ttitle;
	BookNodePtr temp1;
	temp1 = bookSearch(ttitle, arr1);
	try {														// Exception handling for not matching 
		if (temp1) {
			cout << endl;
			temp1->getData()->print();
			cout << endl;
		}
		else {
			throw 0;
		}
	}
	catch (int exceptionCase) {
		switch (exceptionCase) {
			case(0): {
				cout << "No match (code and title do not match)" << endl;
				return;
			}
		}
	}
}

// Menu 2 Rent book
// Assume book name and id are correct, no exception handling cases not specified 
// on power point
void menu2(BookLinkedListPtr arr1, PersonLinkedListPtr arr2) {
	int id = 0, foundname = 0;
	string title = "";
	cout << "Enter your id	: ";
	cin >> id;
	cout << "Enter book title : ";
	cin >> title;
	BookNodePtr temp1;
	temp1 = bookSearch(title, arr1);															// search title in book linked list
	PersonNodePtr temp2;
	temp2 = personSearch(id, arr2);																// search id in person linked list
	try {
		if (temp1->getData()->getAvailable() <= 0) {											// Book not available exception handle
			throw 1;
		}
		if ((temp2->getData()->getId() <= 300 && temp2->getData()->getId() >= 101)				// if Student and borrowed 2 books
			&& (temp2->getData()->getCount() >= 2)) {											// Student rented max exception handling
			throw 2;
		}
		else if ((temp2->getData()->getId() <= 100 && temp2->getData()->getId() >= 1)			// if Teacher and borrowed 3 books
			&& (temp2->getData()->getCount() >= 3)) {											// Teacher rented max exception handling
			throw 3;
		}
		else {																					// if no exception	
				char choice;
				cout << "Do you want to rent '" << temp1->getData()->getTitle() << "' (y/n)?";
				cin >> choice;
				if (choice == 'y') {															// If renting
					temp1->getData()->rentBook();												// book data update with new rent
					temp2->getData()->rentBook(temp1->getData()->getCode());					// person rents book with book code
					cout << "***** Rent Succeed. Check your info!" << endl;
				}
				else if (choice == 'n') {														// Not renting 
					cout << "***** Not renting" << endl;
				}
		}
	}
	catch (int exceptionCase) {
		switch (exceptionCase) {
		case 1:
			cout << "The book is not abailable (all rented out)." << endl;
			return;
		case 2:
			cout << "You already rented 2 books." << endl;
			return;
		case 3:
			cout << "You already rented 3 books." << endl;
			return;
		}
	}
}

// Menu 3 Return book 
void menu3(BookLinkedListPtr arr1, PersonLinkedListPtr arr2) {
	int id = 0, code = 0;
	cout << "Enter your id : ";
	cin >> id;
	cout << "Enter the book code to return : ";
	cin >> code;

	BookNodePtr temp1;
	temp1 = bookSearch(code, arr1);														// search title in book linked list			
	PersonNodePtr temp2;
	temp2 = personSearch(id, arr2);														// search id in person linked list										

	char choice;

	try {
		if (temp2->getData()->checkRented(code) == false ) {									// Person didnt borrorwed book exception handling
			throw 0;																			
		}
		else {
			cout << "Do you want to return " << temp1->getData()->getTitle() << "(y/n)?";
			cin >> choice;
			if (choice == 'y') {
				temp1->getData()->returnBook();													// update book info
				temp2->getData()->returnBook(code);												// update person info
				cout << "***** Return Succeed. Check your info!" << endl;
			}
			else if (choice == 'n') {															// Not returning
				cout << "***** Not returning" << endl;
				return;
			}
		}
	}
	catch (int exceptionCase) {
		switch (exceptionCase) {
		case 0:
			cout << "The id " << id << " did not rent this book." << endl;
			return;
		}
	}
}

// Menu 4 Show Person Info
void menu4(BookLinkedListPtr arr1, PersonLinkedListPtr arr2) {
	int id = 0;
	string name = "";
	cout << "Enter your id : ";
	cin >> id;
	cout << "Enter your name : ";
	cin >> name;

	int rented = 0;																		// rented book count
	int* tempArr = nullptr;																// dynamic array to store rented book codes

	PersonNodePtr temp = arr2->getHead();

	while (temp) {
		if (temp->getData()->getId() == id && temp->getData()->getName() == name) {		// if person exists
			rented = temp->getData()->getCount();										// check person rented book count
			tempArr = new int[rented];													// create dynamic array with rented book count
			for (int i = 0; i < rented; i++) {											// loop rented times
				//cout << temp->getData()->getName() << " borrowed " << temp->getData()->getCode()[i];
				tempArr[i] = temp->getData()->getCode()[i];								// store rented book codes in temparr
			}
			break;
		}
		temp = temp->getLink();															// move to next person
	}

	cout << "\nYou rented " << rented << " books." << endl;

	for (int i = 0; i < rented; i++) {
		int code = tempArr[i];																		// for each rented book code in temparr
		for (int j = 0; j < 3; j++) {																// loop 3 times for 3 book linked list					
			BookNodePtr temp2 = arr1[j].getHead();													// temp2 points to head of book linked list		
			while (temp2) {																			// raverse book linked list
				if (temp2->getData()->getCode() == code && code >= 1001 && code <= 2000) {			// if children book, print info
					cout << "* " << temp2->getData()->getTitle() << "("						
						<< temp2->getData()->getCode() << ")"
						<< " - " << "age " << temp2->getData()->getAge() << endl;
					break;
				}
				else if (temp2->getData()->getCode() == code && code >= 2001 && code <= 3000) {		// if computer book, print info
					cout << "* " << temp2->getData()->getTitle() << "("
						<< temp2->getData()->getCode() << ")"
						<< " - " << "Publisher " << temp2->getData()->getPublisher() << endl;
					break;
				}
				else if (temp2->getData()->getCode() == code && code >= 3001 && code <= 4000) {		// if Novel, print info
					cout << "* " << temp2->getData()->getTitle() << "(" 
						<< temp2->getData()->getCode() << ")"
						<< " - " << "Publish Date " << temp2->getData()->getPublishDate() << endl;
					break;
				}
				temp2 = temp2->getLink();															// move to next book	
			}
		}
	}
}

// Menu 5 Show all Book Info
void menu5(BookLinkedListPtr bookLinkedList) {

	BookNodePtr temp = bookLinkedList[0].getHead();
	cout << "====================================================================================\n";
	cout << "                                    Children Book\n";
	cout << "====================================================================================\n";
	cout << "code                         title             age           available        rented\n";
	cout << "------------------------------------------------------------------------------------\n";
	while (temp) {

		string titleString = "";										// string to store title for printing no underscore titles

		for (int i = 0; i < temp->getData()->getTitle().size(); i++) {	// for each character in title
			if (temp->getData()->getTitle()[i] != '_') {
				titleString += temp->getData()->getTitle()[i];			// if not underscore, add to titleString	
			}
			else if (temp->getData()->getTitle()[i] == '_') {			// if underscore, add space to titleString
				titleString += " ";
			}
		}

		cout << temp->getData()->getCode() << setw(35) << titleString << setw(10) << temp->getData()->getAge()	// print book info
			<< setw(16) << temp->getData()->getAvailable() << setw(16) << temp->getData()->getRented() << endl;
		temp = temp->getLink();																					// move to next book					
	}cout << endl;

	temp = bookLinkedList[1].getHead();
	cout << "====================================================================================\n";
	cout << "                                    Computer Book\n";
	cout << "====================================================================================\n";
	cout << "code                       title                publisher         available   rented\n";
	cout << "------------------------------------------------------------------------------------\n";
	while (temp) {

		string titleString = "", publisherString = "";						// string to store title and publisher for printing no underscore titles and publisher

		for (int i = 0; i < temp->getData()->getTitle().size(); i++) {		// for each character in title
			if (temp->getData()->getTitle()[i] != '_') {					// if not underscore, add to titleString
				titleString += temp->getData()->getTitle()[i];
			}
			else if (temp->getData()->getTitle()[i] == '_') {				// if underscore, add space to titleString
				titleString += " ";
			}
		}

		for (int i = 0; i < temp->getData()->getPublisher().size(); i++) {	// for each character in publisher
			if (temp->getData()->getPublisher()[i] != '_') {				// if not underscore, add to publisherString
				publisherString += temp->getData()->getPublisher()[i];
			}
			else if (temp->getData()->getPublisher()[i] == '_') {			// if underscore, add space to publisherString
				publisherString += " ";
			}
		}

		cout << temp->getData()->getCode() << setw(35) << titleString << setw(20) << publisherString << setw(12)	// print book info
			<< temp->getData()->getAvailable() << setw(10) << temp->getData()->getRented() << endl;
		temp = temp->getLink();																						// move to next book
	}cout << endl;

	temp = bookLinkedList[2].getHead();
	cout << "====================================================================================\n";
	cout << "                                       Novel\n";
	cout << "====================================================================================\n";
	cout << "code                       title           published date      available      rented\n";
	cout << "------------------------------------------------------------------------------------\n";
	while (temp) {

		string titleString = "";											// string to store title for printing no underscore titles	

		for (int i = 0; i < temp->getData()->getTitle().size(); i++) {		// for each character in title
			if (temp->getData()->getTitle()[i] != '_') {
				titleString += temp->getData()->getTitle()[i];
			}
			else if (temp->getData()->getTitle()[i] == '_') {				// if underscore, add space to titleString
				titleString += " ";
			}
		}

		cout << temp->getData()->getCode() << setw(35) << titleString << setw(12) << temp->getData()->getPublishDate()	// print book info
			<< setw(16) << temp->getData()->getAvailable() << setw(14) << temp->getData()->getRented() << endl;
		temp = temp->getLink();																							// move to next book
	}cout << endl;
}