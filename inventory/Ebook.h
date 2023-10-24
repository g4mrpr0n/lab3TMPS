#pragma once
#include "Book.h"
class Ebook : public Book {
public:
	Ebook(std::string name, std::string author, int year, BookGenreAbstract* genre, double price) :
		Book(name, author, year, genre, price) {}

	std::string getType() override {
		return "Ebook";
	}
};