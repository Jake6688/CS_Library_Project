#include "person.h"
#include "book.h"

// Person class constructor
Person::Person() : id(0), name(""), count(0) {}

Person::Person(int tid, string tname, int tcount) :id(tid), name(tname), count(tcount) {}

// Person class setters
void Person::setId(int tid){
	this->id = tid;
}

void Person::setName(string tname) {
	this->name = tname;
}

void Person::setCount(int tcount) {
	this->count = tcount;
}

// Person class getters
int Person::getId() const {
	return this->id;
}

string Person::getName() const {
	return this->name;
}

int Person::getCount() const {
	return this->count;
}

// Student class constructors
Student::Student() :Person(){
	for (int i = 0; i < 2; i++) {
		code[i] = 0;
	}
}

Student::Student(int tid, string tname, int tcount, int code1, int code2) :Person(tid, tname, tcount) {
	code[0] = code1;
	code[1] = code2;
}

// Student class setters
void Student::setCode(int code1) {
	code[0] = code1;
}

const int* Student::getCode() const {
	return code;
}

// Student class member functions
// Precondition: given a student and a book code, add the book code to the student's rented book array
// and update rented count
void Student::rentBook(int code) {
	for (int i = 0; i < 2; i++) {
		if (this->code[i] == 0) {
			this->code[i] = code;
		}
	}
	this->setCount(this->getCount() + 1);
}

// Precondition: given a student and a book code, remove the book code from the student's rented book array
// and update rented count
void Student::returnBook(int code) {							// Precondition: given a student and a book code, remove the book code
	for (int i = 0; i < 2; i++) {								// from the student's rented book array
		if (this->code[i] == code) {						
			this->code[i] = 0;									
		}
	}
	this->setCount(this->getCount() - 1);						// update new rented information for student 
}

// Precondition: given a student and a book code, check if the book is rented
bool Student::checkRented(int code) const {						// Precondition: given a student and a book code, check if the book is rented
	for (int i = 0; i < 2; i++) {
		if (this->code[i] == code) {							// if the book code is in the student book code array return true
			return true;
		}
	}
	return false;												// else return false
}

// Teacher class constructors
Teacher::Teacher():Person(){
	for (int i = 0; i < 3; i++) {
		code[i] = 0;
	}
}

Teacher::Teacher(int tid, string tname, int tcount, int code1, int code2, int code3) :Person(tid, tname, tcount) {
	code[0] = code1;
	code[1] = code2;
	code[2] = code3;
}

// Teacher class setters
void Teacher::setCode(int code1) {
	code[0] = code1;
}

const int* Teacher::getCode() const {
	return code;
}

// Teacher class member functions
// Precondition: given a teacher and a book code, add the book code to the teacher's rented book array
// and update rented count
void Teacher::rentBook(int code) {
	if (this->getCount() >= 3) {
		cout << "Teachers can't rent more than 3 books" << endl;
		return;
	}
	for (int i = 0; i < 3; i++) {
		if (this->code[i] == 0) {
			this->code[i] = code;
		}
	}
	this->setCount(this->getCount() + 1);
}

// Precondition: given a teacher and a book code, remove the book code from the teacher's rented book array
// and update rented count
void Teacher::returnBook(int code) {

	cout << "called student return book" << endl;
	for (int i = 0; i < 3; i++) {												// for each book code in the teacher's rented book array
		if (this->code[i] == code) {											// if the book code is in the array
			this->code[i] = 0;													// set the book code to 0
		}
	}
	this->setCount(this->getCount() - 1);										// update teacher rented count  
}

// Precondition: given a teacher and a book code, check if the book is rented
bool Teacher::checkRented(int code) const {
	for (int i = 0; i < 3; i++) {												// for each book code in the teacher's rented book array
		if (this->code[i] == code) {											// if the book code is in the array
			return true;														// return true
		}
	}
	return false;
}

// Person Node class constructors
PersonNode::PersonNode():link(nullptr), data(nullptr){}

PersonNode::PersonNode(PersonPtr tdata) : link(nullptr), data(tdata){}

// Person Node class setters
void PersonNode::setData(PersonPtr tdata) {
	data = tdata;
}

void PersonNode::setLink(PersonNode* link) {
	this->link = link;
}

// Person Node class getters
const PersonPtr PersonNode::getData() const {
	return data;
}

PersonNode* PersonNode::getLink() const {
	return this->link;
}

// Person Linked List class constructors
PersonLinkedList::PersonLinkedList():head(nullptr){}

// Person Linked List destructor
PersonLinkedList::~PersonLinkedList() {
	PersonNodePtr temp;
	while (head) {															// Delete all nodes in the linked list
		temp = head;
		head = head->getLink();												
		delete temp;
	}
}

// Person Linked List class setter
void PersonLinkedList::setHead(PersonNodePtr ptr){
	head = ptr;
}

// Person Linked List class getter
PersonNodePtr PersonLinkedList::getHead() const {
	return head;
}

// Person Linked List class member functions
void PersonLinkedList::insert(PersonNodePtr tperson) {
	PersonNodePtr temp = head, prev = nullptr;
	if (!head) {												// Create head for linked list
		head = tperson;
		return;
	}
	while (temp && (temp->getData()->getId() <= tperson->getData()->getId())) {	// Find the correct position to insert the node
		prev = temp;
		temp = temp->getLink();
	}
	if (!prev) {												// Insert at the beginning of the list
		tperson->setLink(head);
		head = tperson;
	}
	else {														// Insert in the middle or at the end of the list
		tperson->setLink(prev->getLink());
		prev->setLink(tperson);
	}
}

// Precondition: For the current node as head print the linked list
void PersonLinkedList::print() {
	PersonNodePtr temp = head;
	while (temp) {
		cout << " ID : " << temp->getData()->getId() << " Name : " << temp->getData()->getName() << " Rented : " << temp->getData()->getCount() << " \n";
		temp = temp->getLink();
	}
	cout << endl;
}

// Precondition: Given a person id and a person linked list array, search for the person in the array
PersonNodePtr personSearch(int id, PersonLinkedListPtr arr1) {	
	for (int i = 0; i < 2; i++) {								
		PersonNodePtr temp = (arr1 + i)->getHead();				// create temp ptr to traverse the person linked list
		while (temp) {
			if (temp->getData()->getId() == id) {				// if the person is found return tempo
				return temp;
			}
			temp = temp->getLink();								// go to next node	
		}
	}
	return nullptr;												// if person not found return nullptr
}

// Precondition: Given correct filename to a txt file containing person information in required format 
// make a array with length 2, arr[0] contains head of teacher, arr[1] contains head of student.
PersonLinkedList* personDataStructure(string filename) {

	PersonLinkedList* PersonList = new PersonLinkedList[2];		// create new array to return

	ifstream infile;					
	infile.open(filename);													

	if (infile.fail()) {										// filename exception check
		cout << "Error opening file " << filename << endl;
		exit(1);
	}

	int tid = 0, trented = 0, t1 = 0, t2 = 0, t3 = 0;			// temporary variables to store data
	string tname = "";
	while (!(infile.eof())) {
		infile >> tid >> tname >> trented;

		if (trented == 0) { ; }
		else if (trented == 1)
		{
			infile >> t1;
		}
		else if (trented == 2) {
			infile >> t1 >> t2;
		}
		else if (trented == 3) {
			infile >> t1 >> t2 >> t3;
		}

		if (tid <= 100 && tid >= 1) {							// id is teacher id, craete teacher object
			{
				PersonPtr newPerson = new Teacher(tid, tname, trented, t1, t2, t3);
				PersonNodePtr newPersonNode = new PersonNode(newPerson);
				PersonList[0].insert(newPersonNode);
			}
		}

		else if (tid >= 101 && tid <= 300) {					// id is student id, create student object
			{
				PersonPtr newPerson = new Student(tid, tname, trented, t1, t2);
				PersonNodePtr newPersonNode = new PersonNode(newPerson);
				PersonList[0].insert(newPersonNode);
			}
		}

		tid = 0,t1=0,t2=0,t3=0, tname = "", trented = 0;		// reset temporary variables
	}
	infile.close();												// close file
	return PersonList;											// return array							
}