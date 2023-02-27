#pragma once

#include <iostream>

class Book
{
	std::string name;
	std::string author;
	int numberOfPages;
public:
	Book();
	Book(std::string, std::string, int);
	~Book() = default;

	void getDataFromBook(int);
	void modifyDataFromBook(std::string, std::string, int);

	std::string getName();
	std::string getAuthor();
	int getNumOfPages();
};