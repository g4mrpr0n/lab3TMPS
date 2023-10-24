#pragma once
#include "..\abstractions\inventory\BookAbstract.h"

class BookDecorator : public BookAbstract {
private:
	BookAbstract* book;

public:
	BookDecorator(BookAbstract* b) : book(b) {}

	std::string getName() override {
		return book->getName();
	}

	BookGenreAbstract* getGenre() override {
		return book->getGenre();
	}
	std::string getAuthor() override {
		return book->getAuthor();
	}
	int getYear() override {
		return book->getYear();
	}

	double getPrice() override {
		return book->getPrice();
	}

	std::string getType() override {
		return book->getType();
	}
};