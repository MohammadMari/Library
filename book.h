#pragma once
#include "LibraryItem.h"

class Book : public LibraryItem
{
public:
	Book(int ID, float cost, int status, int period, string author, string title, string ISBN, string category) : LibraryItem(ID, cost, status, period, title) 
	{
		Author = author;
		ISBNNumber = ISBN;
		Category = category;
	};

	void PrintDetails();

	void SetAuthor(string author);
	void SetISBN(string isbn);
	void SetCategory(string category);

	string GetAuthor();
	string GetISBN();
	string GetCategory();

	string GetType();

private:
	string Author;
	string ISBNNumber;
	string Category;
};