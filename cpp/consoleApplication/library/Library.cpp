#include "Library.h"

using namespace std;

Library::Library(const int bookCount, const string fileName) {
	int amount = 0;
	//set the number of books in bookshelfs
	for (int i = 2; i < bookCount; i++) {
		if (bookCount % i == 0) {
			amount = i;
			break;
		}
	}

	//create objects arrays
	bookshelfAmount = bookCount / amount;
	bookshelfs = new Bookshelf[bookshelfAmount];
	books = new Book[bookCount];

	file.open(fileName, ios::in);
	//get books from file to Book array
	if (file) {
		string name, author;
		int numberOfPages=0, i = 0;
		while (file >> name >> author >> numberOfPages) {
			books[i] = Book(name, author, numberOfPages);
			i++;
		}		
	}
	file.close();

	int num = 0;
	//add books to bookshelfs
	for (int i = 0; i < bookshelfAmount; i++) {
		for (int j = num; j < num + amount; j++) {
			bookshelfs[i].addBook(&books[j]);
		}
		num += amount;
	}
}

void Library::printLibrary() {
	for (int i = 0; i < bookshelfAmount; i++)
		bookshelfs[i].printBookshelf(i+1);
}

void Library::modifyBook() {
	int numBookshelf, numBook;

	cout << "Write the bookshelf number and book number: ";
	cin >> numBookshelf >> numBook;

	//cancel if user gives invalid bookshelf
	if (numBookshelf < 1 || numBookshelf > bookshelfAmount + 1) return;
	//else
	bookshelfs[--numBookshelf].modifyBook(numBook);
}

void Library::removeBook() {
	int numBookshelf, numBook;

	cout << "Write the bookshelf number and book number: ";
	cin >> numBookshelf >> numBook;

	//cancel if user gives invalid bookshelf
	if (numBookshelf < 1 || numBookshelf > bookshelfAmount + 1) return;
	//else
	bookshelfs[--numBookshelf].removeBook(numBook);
}

void Library::addBook() {
	int numBookshelf;

	cout << "Write the bookshelf number: ";
	cin >> numBookshelf;

	//cancel if user gives invalid bookshelf
	if (numBookshelf < 1 || numBookshelf > bookshelfAmount + 1) return;
	//else
	string name, author;
	int numberOfPages;

	cout << "Write new name,author and number of pages for this book: ";
	cin >> name >> author >> numberOfPages;

	bookshelfs[--numBookshelf].addBook(new Book(name, author, numberOfPages));
}

void Library::updateTextFile(const string fileName) {
	vector<Book*> vec;

	//clean file
	fstream file(fileName, ios::trunc);
	file.close();

	//update file with new data
	file.open(fileName, ios::out);
	for (int i = 0; i < bookshelfAmount; i++) {
		vec = bookshelfs[i].getVector();
		for (int j = 0; j < vec.size(); j++)
			file << vec[j]->getName() << " " << vec[j]->getAuthor() << " " << vec[j]->getNumOfPages() << endl;
	}
	file.close();
}

Library::~Library() {
	delete[] books;
	delete[] bookshelfs;
}