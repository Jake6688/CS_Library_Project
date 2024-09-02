#define PERSON_H
#ifdef  PERSON_H

#include <iostream>
#include <fstream>

using namespace std;

// virtual class Person
class Person
{
public:
	// constructor
	Person();
	Person(int , string, int);
	// setter 
	void setId(int);
	void setName(string);
	void setCount(int);
	// getter
	int getId() const;
	string getName() const;
	int getCount() const;
	
	// virtual functions
	virtual void rentBook(int) = 0;
	virtual void returnBook(int) = 0;
	virtual void setCode(int) = 0;
	virtual const int* getCode() const = 0;
	virtual bool checkRented(int) const = 0;

private:
	// encapsulated private data
	int id;
	string name;
	int count;
};
typedef Person* PersonPtr;								// PersonPtr is a pointer to Person

// normal class student
class Student : public Person
{
public:
	// constructor
	Student();
	Student(int, string, int, int, int);
	// setter
	void setCode(int);
	// getter
	virtual const int* getCode() const;
	// virtual functions
	virtual void rentBook(int);
	virtual void returnBook(int);
	virtual bool checkRented(int) const;
private:
	int code[2];
};

// normal class teacher
class Teacher : public Person
{
public:
	// constructor
	Teacher();
	Teacher(int, string, int, int, int, int);
	// setter
	virtual void setCode(int);
	// getter
	virtual const int* getCode() const;
	// virtual functions
	virtual void rentBook(int);
	virtual void returnBook(int);
	virtual bool checkRented(int) const;
private:
	int code[3];
};

// Person class Node
class PersonNode
{
public:		
	// constructor
	PersonNode();
	PersonNode(PersonPtr);
	// setter
	void setData(PersonPtr);
	void setLink(PersonNode*);
	// getter
	const PersonPtr getData() const;
	PersonNode* getLink() const;
private:
	PersonPtr data;
	PersonNode* link;
};
typedef PersonNode* PersonNodePtr;						// PersonNodePtr is a pointer to PersonNode	

// Person linkedlist
class PersonLinkedList
{
public:
	PersonLinkedList();
	~PersonLinkedList();
	void setHead(PersonNodePtr);
	PersonNodePtr getHead() const;
	void insert(PersonNodePtr);
	void print();
	friend PersonNodePtr personSearch(int, PersonLinkedList*);
private:
	PersonNodePtr head;
};
typedef PersonLinkedList* PersonLinkedListPtr;			// PersonLinkedListPtr is a pointer to PersonLinkedList

PersonLinkedList* personDataStructure(string filename); 
#endif