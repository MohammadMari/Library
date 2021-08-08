#pragma once
#include "LibraryItem.h"

class DVD : public LibraryItem
{
public:
	DVD(int ID, float cost, int status, int period, string title, string category,  string runtime, string studio, string release) : LibraryItem(ID, cost, status, period, title)
	{
		Category = category;
		RunTime = runtime;
		Studio = studio;
		ReleaseDate = release;
	};

	void PrintDetails();
	void SetCategory(string category);
	void SetRuntime(string runtime);
	void SetStudio(string studio);
	void SetRelease(string release);

	string GetCategory();
	string GetRunTime();
	string GetStudio();
	string GetReleaseDate();

	string GetType();
private:
	string Category, RunTime, Studio, ReleaseDate;
};