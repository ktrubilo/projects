#include "Bookshelf.h"

using namespace std;

const int STAYINT = 0;
const string STAYSTR = "0";

Bookshelf::Bookshelf() {}

void Bookshelf::addBook(Book* book) {
	vect.push_back(book);
}

void Bookshelf::removeBook(int num) {
	if (num < 1 || num>vect.size() + 1) return;
	vect.erase(vect.begin() + --num);
}

vector<Book*> Bookshelf::getVector() {
	return vect;
}

void Bookshelf::modifyBook(int num) {
	if (num < 1 || num>vect.size() + 1) return;

	char choice;
	string name, author;
	int numberOfPages;

	cout << "You wanna to modify: 1.name, 2.author, 3.number of pages or 4. all" << endl;
	cout << "[1/2/3/4]: ";
	choice = _getch();

	switch (choice) {
	case '1': 
		cout << "Write new name for this book: ";
		cin >> name;
		vect[--num]->modifyDataFromBook(name, STAYSTR, STAYINT);
		break;
	case '2':
		cout << "Write new author for this book: ";
		cin >> author;
		vect[--num]->modifyDataFromBook(STAYSTR, author, STAYINT);
		break;
	case '3':
		cout << "Write new numberOfPages for this book: ";
		cin >> numberOfPages;
		vect[--num]->modifyDataFromBook(STAYSTR, STAYSTR, numberOfPages);
		break;
	case '4':
		cout << "Write new name,author and number of pages for this book: ";
		cin >> name >> author >> numberOfPages;
		vect[--num]->modifyDataFromBook(name, author, numberOfPages);
		break;
	}
}

void Bookshelf::printBookshelf(int num) {
	cout << "-------------------- " << num << " --------------------" << endl;
	for (int i = 0; i < vect.size(); i++) {
		vect[i]->getDataFromBook(i+1);
		cout << endl;
	}
}