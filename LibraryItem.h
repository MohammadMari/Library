#pragma once
#include <string>

using namespace std;

enum checkstatus
{
	IN = 0,
	OUT,
	LOST,
	OVERDUE,
};

class LibraryItem
{
public:
	LibraryItem(int id, float cost, int status, int period, string title)
	{
		Title = title;
		ID = id;
		Cost = cost;
		Status = status;
		Period = period;
	}

	string GetTitle();
	void SetTitle(string title);

	void SetID(int id);
	void SetCost(float id);
	void SetStatus(int id);
	void SetPeriod(int id);

	int GetID();
	float GetCost();
	int GetStatus();
	int GetPeriod();

	virtual string GetType()
	{
		return "";
	}

	virtual void PrintDetails();

protected:
	int ID = 0;
	float Cost = 0;
	int Status = 0;
	int Period = 0;
	string Title;
};