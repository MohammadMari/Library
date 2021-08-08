#include "book.h"
#include <iostream>

void Book::PrintDetails()
{
	cout << "-----------------------------------------------------" << endl;
	cout << "ID: " << ID << endl;
	cout << "Type: " << GetType() << endl;
	cout << "Author: " << Author << endl;
	cout << "Title: " << Title << endl;
	cout << "ISBN: " << ISBNNumber << endl;
	cout << "Category: " << Category << endl;
	cout << "Cost: " << Cost << endl; //format
	cout << "Days allowed out: " << Period << endl;
	cout << "Status: " << Status << endl; //format
	cout << "-----------------------------------------------------" << endl;
}

void Book::SetAuthor(string author)
{
	Author = author;
}

void Book::SetISBN(string isbn)
{
	ISBNNumber = isbn;
}

void Book::SetCategory(string category)
{
	Category = category;
}

string Book::GetAuthor()
{
	return Author;
}

string Book::GetISBN()
{
	return ISBNNumber;
}

string Book::GetCategory()
{
	return Category;
}

string Book::GetType()
{
	return "Book";
}
