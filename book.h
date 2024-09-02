#define BOOK_H
#ifdef BOOK_H
#include <iostream>
#include <fstream>

using namespace std;

// Abstract class Book
class Book
{
public:
	// constructor
	Book();
	Book(int, string, int, int);
	// setters
	void setCode(int);
	void setTitle(string);
	void setAvailable(int);
	void setRented(int);
	void rentBook();
	void returnBook();
	// getters
	int getCode() const;
	string getTitle() const;
	int getAvailable() const;
	int getRented() const;
	// virtual function 
	virtual int getAge() const = 0;
	virtual string getPublisher() const = 0;
	virtual int getPublishDate() const = 0;
	virtual void print() const = 0;
private:
	// encapsulated member variables
	int code;
	string title;
	int available;
	int rented;
};
typedef Book* BookPtr;									// BookPtr is a pointer to Book

class ChildrenBook : public Book
{
public:
	// constructor
	ChildrenBook();
	ChildrenBook(int, string, int, int, int);
	// setters
	void setAge(int);
	// getters
	virtual int getAge() const;
	// virutals 
	string getPublisher() const;
	int getPublishDate() const;
	void print() const;
private:
	// encapsulated member variables
	int age;
};

// normal class Computer Book
class ComputerBook : public Book
{
public:
	// constructor
	ComputerBook();
	ComputerBook(int, string, string, int, int);
	// setter
	void setPublisher(string);
	// getter
	string getPublisher() const;
	// virtuals
	int getAge() const;
	int getPublishDate() const;
	void print() const;
private:
	string publisher;
};

// normal class Novel
class Novel : public Book
{
	// complete the class
public:
	// constructor
	Novel();
	Novel(int, string, int, int, int);
	// setter
	 void setPublishDate(int);
	// getter
	 int getPublishDate() const;
	//virtuals
	 int getAge() const;
	 string getPublisher() const;
	 void print() const;

private:
	// encapsulated member variables
	int publish_date;
};


class BookNode {
public:
	// constructor
	BookNode();
	BookNode(BookPtr);
	// setter
	void setData(BookPtr newBook);
	void setLink(BookNode* tlink);
	// getter
	BookPtr getData() const;
	BookNode* getLink() const;

private:
	// encapsulated member variables
	BookPtr data;
	BookNode* link;
};
typedef BookNode* BookNodePtr;							// BookNodePtr is a pointer to BookNode	

// Book class linked list
class BookLinkedList {
public:
	// constructor
	BookLinkedList(); // set head to NULL
	// destructor
	~BookLinkedList(); // delete nodes in the list
	// setter
	void setHead(BookNodePtr h);
	// getter
	BookNodePtr getHead() const;
	// member functins
	void insertNode(BookNodePtr);
	void print() const;
	friend BookNodePtr bookSearch(int, BookLinkedList*);
	friend BookNodePtr bookSearch(string, BookLinkedList*);
private:
	// encapsulated member variables
	BookNodePtr head;
};
typedef BookLinkedList* BookLinkedListPtr;				// BookLinkedListPtr is a pointer to BookLinkedList


BookLinkedListPtr bookDataStructure(string);// create library book data structure
											// Precondition: string is a valid txt file name including extention in the 
											// same directory as the program
											// Postcondition: returns a pointer to a size 3 array 
											// where each index contains the head of a book linkedlist
											// index 0: children books, index 1: computer books, index 2 : novels
#endif