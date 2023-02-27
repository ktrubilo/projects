#pragma once

#include "Library.h"

#include <iostream>
#include <string>
#include <conio.h>

const std::string fileName = "books.txt";

class Program
{
	int bookCount;
	bool loop;
	char choice;
	Library* library;
	void menu();
	int getBookCount();
public:
	Program();
	~Program();
	void run();
};