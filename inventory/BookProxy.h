#pragma once
#include "..\abstractions\inventory\BookAbstract.h"
#include "Book.h"
class BookProxy : public BookAbstract {
private:
	Book* realBook;
	std::string name;
	std::string author;
	int year;
	BookGenreAbstract* genre;
	double price;

public:
	BookProxy(const std::string& name, const std::string& author, int year, BookGenreAbstract* genre, double price)
		: name(name), author(author), year(year), genre(genre), price(price) {
		realBook = nullptr;
	}
	void check() {
		// Ensure that the real book object has been created
		if (realBook == nullptr) {
			// Lazy load the real book object when needed
			realBook = new Book(name, author, year, genre, price);
		}
	}

	BookGenreAbstract* getGenre() override {
		check();
		return realBook->getGenre();
	}

	std::string getName() override {
		check();
		return realBook->getName();
	}
	std::string getAuthor() override {
		check();
		return realBook->getAuthor();
	}

	double getPrice() override {
		check();
		return realBook->getPrice();
	}

	int getYear() override {
		check();
		return realBook->getYear();
	}

	std::string getType() override {
		check();
		return realBook->getType();
	}
};
