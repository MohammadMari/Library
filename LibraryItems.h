#pragma once
#include "LibraryItem.h"
#include "cd.h"
#include "book.h"
#include "dvd.h"
#include <vector>

class LibraryItems
{
public:
	void NewBook();
	void NewCD();
	void NewDVD();
	void NewItem();
	void RemoveItem();
	void EditItem();
	LibraryItem* SearchItem(int* id);

	void ListItems();
	virtual void ListItemDetails();

	void Save();
	void Load();

	void Clean();

private:
	vector<LibraryItem*> items;
};