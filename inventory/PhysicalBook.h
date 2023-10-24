#pragma once
#include "Book.h"
class PhysicalBook : public Book {
public:
	PhysicalBook(std::string name, std::string author, int year, BookGenreAbstract* genre, double price) :
		Book(name, author, year, genre, price) {}

	std::string getType() override {
		return "Physical Book";
	}
};