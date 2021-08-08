#include "LibraryItem.h"
#include <iostream>



/*	int ID = 0;
	float Cost = 0;
	int Status = 0;
	int Period = 0;
	string Title;*/

void LibraryItem::PrintDetails()
{
	cout << "-----------------------------------------------------" << endl;
	cout << "ID: " << ID << endl;
	cout << "Title: " << Title << endl;
	cout << "Cost: " << Cost << endl; //format
	cout << "Days allowed out: " << Period << endl; 
	cout << "Status: " << Status << endl; //format
	cout << "-----------------------------------------------------" << endl;
}


//Set and get stuff down here

string LibraryItem::GetTitle()
{
	return Title;
}

void LibraryItem::SetTitle(string title)
{
	Title = title;
}

void LibraryItem::SetID(int id)
{
	ID = id;
}

void LibraryItem::SetCost(float cost)
{
	Cost = cost;
}

void LibraryItem::SetPeriod(int period)
{
	Period = period;
}

void LibraryItem::SetStatus(int status)
{
	Status = status;
}

int LibraryItem::GetID()
{
	return ID;
}

float LibraryItem::GetCost()
{
	return Cost;
}

int LibraryItem::GetPeriod()
{
	return Period;
}

int LibraryItem::GetStatus()
{
	return Status;
}