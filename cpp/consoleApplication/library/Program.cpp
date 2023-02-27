#include "Program.h"

using namespace std;

Program::Program() {
	loop = true;
	bookCount = getBookCount();
}

int Program::getBookCount() {
	int num = 0;

	fstream file(fileName, ios::in);
	if (file) {
		string unused;
		while (getline(file, unused)) {
			num++;
		}
	}
	file.close();

	return num;
}

void Program::menu() {
	cout << "1. Show bookshekfs" << endl;
	cout << "2. Modify book in bookshelf" << endl;
	cout << "3. Add book to bookshelf" << endl;
	cout << "4. Remove book from bookshelf" << endl;
	cout << "5. Close program" << endl;
	cout << "Choice: ";
	choice = _getch();
}

void Program::run() {
	library = new Library(bookCount, fileName);
	while (loop) {
		cout << endl;
		menu();
		switch (choice) {
		case '1':
			library->printLibrary();
			break;
		case '2':
			library->modifyBook();
			break;
		case '3':
			library->addBook();
			break;
		case '4':
			library->removeBook();
			break;
		case '5':
			library->updateTextFile(fileName);
			loop = false;
			break;
		}
	}
}

Program::~Program() {
	
}