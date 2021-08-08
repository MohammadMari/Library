#include "dvd.h"
#include <iostream>


//I could use base function but I want it to look nice
void DVD::PrintDetails()
{
	cout << "-----------------------------------------------------" << endl;
	cout << "ID: " << ID << endl;
	cout << "Type: " << GetType() << endl;
	cout << "Title: " << Title << endl;
	cout << "Category: " << Category << endl;
	cout << "Run time: " << RunTime << endl;
	cout << "Studio: " << Studio << endl;
	cout << "Release date: " << ReleaseDate << endl;
	cout << "Cost: " << Cost << endl; //format
	cout << "Days allowed out: " << Period << endl;
	cout << "Status: " << Status << endl; //format
	cout << "-----------------------------------------------------" << endl;
}

void DVD::SetCategory(string category)
{
	Category = category;
}

void DVD::SetRuntime(string runtime)
{
	RunTime = runtime;
}

void DVD::SetStudio(string studio)
{
	Studio = studio;
}

void DVD::SetRelease(string release)
{
	ReleaseDate = release;
}

string DVD::GetCategory()
{
	return Category;
}

string DVD::GetRunTime()
{
	return RunTime;
}

string DVD::GetStudio()
{
	return Studio;
}

string DVD::GetReleaseDate()
{
	return ReleaseDate;
}

string DVD::GetType()
{
	return "DVD";
}
