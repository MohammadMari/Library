#include "patron.h"
#include <iostream>

Patron::Patron(string name, int id)
{
	Name = name;
	ID = id;
}

Patron::Patron(string name, int id, int BooksOut, float Fine)
{
	Name = name;
	ID = id;
	NumBooksOut = BooksOut;
	FineBalance = Fine;
}

void Patron::WithdrawBook()
{
	NumBooksOut++;
}

void Patron::ReturnBook()
{
	NumBooksOut--;
}

void Patron::PrintDetails()
{
	cout << "-----------------------------------------------------" << endl;
	cout << "ID: " << ID << endl;
	cout << "Name: " << Name << endl;
	cout << "Books out: " << NumBooksOut << endl;
	cout << "Fine: " << FineBalance << endl; //format this
	cout << "-----------------------------------------------------" << endl;
}


//get sets
string Patron::GetName()
{
	return Name;
}

int Patron::GetID()
{
	return ID;
}

float Patron::GetFine()
{
	return FineBalance;
}

int Patron::GetBooksOut()
{
	return NumBooksOut;
}

void Patron::PayFine(float amt)
{
	AmtPaid += amt;
}

void Patron::FixFine()
{
	FineBalance = FineBalance - AmtPaid;
}

void Patron::SetName(string name)
{
	Name = name;
}

void Patron::SetID(int id)
{
	ID = id;
}

void Patron::SetFine(float fine)
{
	FineBalance = fine;
}

void Patron::SetBooksOut(int books)
{
	NumBooksOut = books;
}

