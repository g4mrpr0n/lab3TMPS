# Topic: *Structural Design Patterns*


## Author: Globa Georgeana

----

## Objectives:
&ensp; &ensp; __1. Study and understand the Structural Design Patterns.__

&ensp; &ensp; __2. As a continuation of the previous laboratory work, think about the functionalities that your system will need to provide to the user.__

&ensp; &ensp; __3. Implement some additional functionalities, or create a new project using structural design patterns.__

## Theory:
&ensp; &ensp; Structural design patterns are a category of design patterns that focus on the composition of classes and objects to form larger structures and systems. They provide a way to organize objects and classes in a way that is both flexible and efficient, while allowing for the reuse and modification of existing code. Structural design patterns address common problems encountered in the composition of classes and objects, such as how to create new objects that inherit functionality from existing objects, how to create objects that share functionality without duplicating code, or how to define relationships between objects in a flexible and extensible way.

&ensp; &ensp; Some examples of from this category of design patterns are:

   * Adapter
   * Bridge
   * Composite
   * Decorator
   * Facade
   * Flyweight
   * Proxy


## Implementation

This project is a Bookstore Management System, implemented in C++.

&ensp; The first design pattern - Proxy. A proxy object derived from `Book` type can be useful instead of working with actual `Book` objects:
```cpp
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
```

==================================================================
&ensp; Decorator=> `DiscountDecorator` adds a discount to a book object without modifying the book's structure. This allows to easily extend and customize the behavior of the book objects using decorators. 

```cpp
class DiscountDecorator : public BookDecorator {
private:
	double discountPercentage;

public:
	DiscountDecorator(BookAbstract* b, double discount) : BookDecorator(b), discountPercentage(discount) {}

	double getPrice() override {
		double originalPrice = BookDecorator::getPrice();
		double newprice = originalPrice * (1 - discountPercentage);
		return newprice;
	}
};
```

==================================================================

&ensp; The Adapter: Using a uniform `PaymentLibrary` interface, it is possible to easily process payments through several gateways within the project. As a result, we can handle several payment gateways without tightly attaching the code to each gateway's unique interface.

```cpp
class PaymentLibraryAdapter : public PaymentAbstract {
private:
	PaymentLibrary externalPayment;

public:
	PaymentLibraryAdapter(PaymentLibrary extPayment) : externalPayment(extPayment) {}

	float getRate(char x) override {
		return externalPayment.calculatePaymentRate(x);
	}
};
```

==================================================================

&ensp; Finally, the Bridge pattern. It was used to separate the abstract concept of a `Book` from its concrete implementations, which in this case are `PhysicalBook` and `Ebook`. The `Book` class has been made abstract and includes a new virtual method getType(), which must be implemented by any concrete subclasses.

```cpp
class Ebook : public Book {
public:
	Ebook(std::string name, std::string author, int year, BookGenreAbstract* genre, double price) :
		Book(name, author, year, genre, price) {}

	std::string getType() override {
		return "Ebook";
	}
};
```
```cpp
class PhysicalBook : public Book {
public:
	PhysicalBook(std::string name, std::string author, int year, BookGenreAbstract* genre, double price) :
		Book(name, author, year, genre, price) {}

	std::string getType() override {
		return "Physical Book";
	}
};
```

## Conclusions / Screenshots / Results
In conclusion, implementing Structural design patterns offers extra flexibility and sustainability for structuring and organizing the code, and it is a very elegant and clever way to do so. It helps build maintainable and clean code, and they're really cool.