#pragma once
#include "..\abstractions\inventory\InventoryAbstract.h"
#include "..\abstractions\views\InventoryDisplayAbstract.h"
#include "..\abstractions\inventory\BookAbstract.h"

class InventoryDisplay :public InventoryDisplayAbstract
{
public:
	void printInventory(InventoryAbstract* b) override
	{
		std::map<int, BookAbstract*> newMap = b->getBookMap();
		for (auto i = newMap.begin(); i != newMap.end(); ++i)
			std::cout << "\n\n" << i->first << ": " << b->getBookCount()[i->first] << " " << i->second->getName() << " " << i->second->getAuthor() << " " << i->second->getGenre()->getGenreId() << " " << i->second->getPrice() << "\n";
	}
};
