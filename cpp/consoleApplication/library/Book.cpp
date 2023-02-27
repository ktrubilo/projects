#include "Book.h"

using namespace std;

Book::Book() {}

Book::Book(string name, string author, int numberOfPages) {
	this->name = name;
	this->author = author;
	this->numberOfPages = numberOfPages;
}

void Book::getDataFromBook(int num) {
	cout << num << ". " << name << " " << author << ", number of pages: " << numberOfPages;
}

void Book::modifyDataFromBook(string name, string author, int numberOfPages) {
	if (name == "0" && numberOfPages == 0) {
		this->author = author;
	} else if (author == "0" && numberOfPages == 0) {
		this->name = name;
	} else if(author == "0" && name == "0") {
		this->numberOfPages = numberOfPages;
	} else {
		this->name = name;
		this->author = author;
		this->numberOfPages = numberOfPages;
	}
}

string Book::getName() {
	return name;
}

string Book::getAuthor() {
	return author;
}

int Book::getNumOfPages() {
	return numberOfPages;
}