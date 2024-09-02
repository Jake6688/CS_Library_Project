#include "book.h"

// Book class constructor
Book::Book() {
	code = 0;
	title = "";
	available = 0;
	rented = 0;
}

// argumented constructor
Book::Book(int tcode, string ttitle, int tavalable,
	int trented):code(tcode),title(ttitle),available(tavalable),
	rented(trented) {}

// setters
void Book::setCode(int tcode) {
	code = tcode;
}
void Book::setTitle(string ttitle) {
	title = ttitle;
}
void Book::setAvailable(int tavailable) {
	available = tavailable;
}
void Book::setRented(int trented) {
	rented = trented;
}

// setters
int Book::getCode()  const {
	return code;
}
string Book::getTitle()  const {
	return title;
}
int Book::getAvailable()  const {
	return available;
}
int Book::getRented()  const {
	return rented;
}

// book class member functions
void Book::rentBook() {
	available -= 1;
	rented += 1;
}

void Book::returnBook() {
	available+=1;
	rented-=1;
}

// ChildrenBook class constructors
ChildrenBook::ChildrenBook() {
	age = 0;
}

// argumented constructor
ChildrenBook::ChildrenBook(int tcode, string ttitle, int tage, int tavailable, int trent)
	: Book(tcode, ttitle, tavailable, trent), age(tage) {}

// setters and getters
void ChildrenBook::setAge(int tage) {
	age = tage;
}
int ChildrenBook::getAge()  const {
	return age;
}

string ChildrenBook::getPublisher()  const {
	return "";
}

int ChildrenBook::getPublishDate() const{
	return 0; 
}

void ChildrenBook::print() const {
	cout << this->getTitle() << "(" << this->getCode() << ")" << " exists." << endl;
	cout << "category : Children" << endl;
	cout << "age : " << this->getAge() << endl;
	cout << this->getAvailable() << " available, " << this->getRented() << " rented" << endl;
}

// FictionBook class constructors
ComputerBook::ComputerBook() {
	publisher = "";
}
ComputerBook::ComputerBook(int tcode, string ttitle, string tpublisher, int tavailable, int trent)
	: Book(tcode, ttitle, tavailable, trent), publisher(tpublisher) {}

// setters and getters
void ComputerBook::setPublisher(string tpublisher) {
	publisher = tpublisher;
}
string ComputerBook::getPublisher()  const {
	return publisher;
}
// virtual implementation
int ComputerBook::getAge() const{
	return 0;
}
int ComputerBook::getPublishDate() const {
	return 0;
}
void ComputerBook::print() const {
	cout << this->getTitle() << "(" << this->getCode() << ")" << " exists." << endl;
	cout << "category : Computer" << endl;
	cout << "Publisher : " << this->getPublisher() << endl;
	cout << this->getAvailable() << " available, " << this->getRented() << " rented" << endl;
}

// Novel class constructors
Novel::Novel() {
	publish_date = 0;
}
Novel::Novel(int tcode, string ttitle, int tpublish_date, int tavailable, int trent) 
	: Book(tcode, ttitle, tavailable, trent), publish_date(tpublish_date) {}

// setters and getters
void Novel::setPublishDate(int tpublish_date) {
	publish_date = tpublish_date;
}
int Novel::getPublishDate()  const {
	return publish_date;
}
// virtual implementation
int Novel::getAge() const {
	return 0;
}
string Novel::getPublisher() const {
	return "";
}

void Novel::print() const {
	cout << this->getTitle() << "(" << this->getCode() << ")" << " exists." << endl;
	cout << "category : Computer" << endl;
	cout << "Publish Date : " << this->getPublishDate() << endl;
	cout << this->getAvailable() << " available, " << this->getRented() << " rented" << endl;
}

// BookNode class constructor
BookNode::BookNode():data(), link(nullptr){}

// argumented constructor
BookNode::BookNode(BookPtr newBook):data(newBook), link(nullptr){}

// setters and getters
void BookNode::setData(BookPtr newBook) {
	data = newBook;
}
void BookNode::setLink(BookNode* tlink) {
	this->link = tlink;
}
BookPtr BookNode::getData() const {
	return this->data;
}
BookNodePtr BookNode::getLink() const {
	return this->link;
}

// BookLinked List constructor
BookLinkedList::BookLinkedList():head(nullptr){}
// Book Linked List destructor
BookLinkedList::~BookLinkedList() {
	while(head){
		delete head;
		head = head->getLink();
	}
}

// Book Linked List setter
void BookLinkedList::setHead(BookNodePtr newHead) {
	head = newHead;
}

// Book Linked List getter
BookNodePtr BookLinkedList::getHead() const{
	return this->head;
}

// Book Linked List member functions
void BookLinkedList::insertNode(BookNodePtr newBookNode) {
	BookNodePtr temp = head, prev = nullptr;

	if (!head) {
		//cout << "creating head for linkedlist " << endl;
		head = newBookNode;
		return;
	}

	while (temp && (temp->getData()->getCode() <= newBookNode->getData()->getCode())) {
		prev = temp;
		temp = temp->getLink();
	}

	if (!prev) { // Insert at the beginning of the list
		newBookNode->setLink(head);
		head = newBookNode;
	}
	else { // Insert in the middle or at the end of the list
		newBookNode->setLink(prev->getLink());
		prev->setLink(newBookNode);
	}
}
void BookLinkedList::print()const {
	BookNodePtr temp = head;

	while (temp) {
		if ((temp->getData()->getCode() >= 1001) && (temp->getData()->getCode() <= 2000)) {
			cout << temp->getData()->getCode() << " " << temp->getData()->getTitle() <<
			" " << temp->getData()->getAge() << " " << temp->getData()->getAvailable() << " " << temp->getData()->getRented() << endl;
		}
		else if ( (temp->getData()->getCode() >= 2001) && (temp->getData()->getCode() <= 3000)) {
			cout << temp->getData()->getCode() << " " << temp->getData()->getTitle() <<
				" " << temp->getData()->getPublisher() << " " << temp->getData()->getAvailable() << " " << temp->getData()->getRented() << endl;
		}
		else if ( (temp->getData()->getCode() >= 3001) && (temp->getData()->getCode() <= 4000) ) {
			cout << temp->getData()->getCode() << " " << temp->getData()->getTitle() <<
				" " << temp->getData()->getPublishDate() << " " << temp->getData()->getAvailable() << " " << temp->getData()->getRented() << endl;
		}
		else {
			cout << "This book : " << temp->getData()->getTitle() << " is not categorized!" << endl;
		}
		temp = temp->getLink();
	}
}

// search book in library by code
BookNodePtr bookSearch(int code, BookLinkedList* arr1){			// search book by code	
	for (int i = 0; i < 3; i++) {								// search book in each of the three category		
		BookNodePtr temp = (arr1+i)->getHead();					// get head of each linked list
		while (temp) {											// search book in each linked list	
			if (temp->getData()->getCode() == code) {			// if found, return the book
				return temp;	
			}	
			temp = temp->getLink();								// if not found, go to next node
		}
	}
	return nullptr;												// if not found in all three category, return nullptr
}

// search book in library by title
BookNodePtr bookSearch(string title, BookLinkedList* arr1) {	// search book by title
	for (int i = 0; i < 3; i++) {								// search book in each of the three category
		BookNodePtr temp = (arr1 + i)->getHead();				// get head of each linked list	
		while (temp) {											// search book in each linked list
			if (temp->getData()->getTitle() == title) {			// if found, return the book
				//cout << "found book with title : " << temp->getData()->getTitle() << endl; // " << temp->getData()->getCode() << endl;"
				return temp;
			}
			temp = temp->getLink();								// if not found, go to next node
		}
	}
	return nullptr;												// if not found in all three category, return nullptr
}

// Precondition: create Book DataStructure
BookLinkedListPtr bookDataStructure(string filename) {  // create a data structure that stores all books
	BookLinkedListPtr temp = new BookLinkedList[3];     // create 3 linked list for each category
													    // [0] for children, [1] for computer, [2] for novel
	ifstream infile;
	infile.open(filename);								// open infile with filename
	if (infile.fail()) {
		cout << "Error opening file" << endl;			// open file fail exception handling
		exit(1);
	}

	int code = 0, age = 0, available = 0, rent = 0, published_date = 0;				// declare features that books have
	string title = "", publisher = "";
	while (infile >> code) {
		if (code >= 1001 && code <= 2000) { // if between code 1001 and 2000
			infile >> title >> age >> available >> rent;
			BookPtr newBook = new ChildrenBook(code, title, age, available, rent);	// create Children book object
			BookNodePtr newBookNode = new BookNode(newBook);
			temp[0].insertNode(newBookNode);										// insert newBookNode into a Book Linked list that only stores childern books
		}
		else if (code >= 2001 && code <= 3000) {
			infile >> title >> publisher >> available >> rent;
			BookPtr newBook = new ComputerBook(code, title, publisher, available, rent);	// create Computer book object
			BookNodePtr newBookNode = new BookNode(newBook);
			temp[1].insertNode(newBookNode);										// insert newBookNode into a Book Linked list that only stores computer books
		}
		else if (code >= 3001 && code <= 4000) {
			infile >> title >> published_date >> available >> rent;
			BookPtr newBook = new Novel(code, title, published_date, available, rent);		// create Novel object
			BookNodePtr newBookNode = new BookNode(newBook);
			temp[2].insertNode(newBookNode);										// insert newBookNode into a Book Linked list that only stores novels
		}
		code = 0, age = 0, available = 0, rent = 0, published_date = 0;             // reset all features for next next book
		title = "", publisher = "";
	}

	return temp;																	// return an size 3 array with 3 linked list's head
																					// [0] for children, [1] for computer, [2] for novel
}	