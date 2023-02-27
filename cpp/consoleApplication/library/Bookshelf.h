#pragma once

#include <iostream>
#include <conio.h>
#include <vector>

#include "Book.h"

class Bookshelf
{
	std::vector<Book*> vect;
public:
	Bookshelf();
	~Bookshelf() = default;
	
	void modifyBook(int);
	void removeBook(int);
	void printBookshelf(int);

	void addBook(Book*);

	std::vector<Book*> getVector();
};

