#pragma once
#include "Bookshelf.h"
#include "Book.h"

#include <iostream>
#include <fstream>

class Library
{
	int bookshelfAmount;
	Bookshelf* bookshelfs;
	Book* books;
	std::fstream file;
public:
	Library(const int,const std::string);
	~Library();

	void printLibrary();

	void modifyBook();
	void removeBook();
	void addBook();

	void updateTextFile(const std::string);
};

