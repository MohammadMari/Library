#include "loan.h"
#include <iostream>
using namespace std;

Loan::Loan(int Loanid, int bookid, int patronid, time_t time)
{
	LoanID = Loanid;
	BookID = bookid;
	PatronID = patronid;
	DueDate = time;
}

Loan::Loan(int Loanid, int bookid, int patronid, time_t time, int status, bool rechecked, time_t turnedIn)
{
	LoanID = Loanid;
	BookID = bookid;
	PatronID = patronid;
	DueDate = time;
	Status = status;
	Rechecked = rechecked;
	DateTurnedIn = turnedIn;
}

int Loan::GetPatronID()
{
	return PatronID;
}

int Loan::GetBookID()
{
	return BookID;
}

int Loan::GetLoanID()
{
	return LoanID;
}

int Loan::GetStatus()
{
	return Status;
}

time_t Loan::GetDueDate()
{
	return DueDate;
}

time_t Loan::GetReturnDate()
{
	return DateTurnedIn;
}

void Loan::SetStatus(int status)
{
	Status = status;
}

void Loan::SetItemID(int id)
{
	BookID = id;
}

void Loan::SetPatronID(int id)
{
	PatronID = id;
}

void Loan::SetDueDate(time_t time)
{
	DueDate = time;
}

void Loan::CheckIn()
{
	time_t temp;
	time(&temp);
	Status = LRETURNED;
	DateTurnedIn = temp;
}

void Loan::Recheck(LibraryItems items)
{
	if (Rechecked)
	{
		cout << "This has already been rechecked!" << endl;
		return;
	}

	Rechecked = true;
	auto item = items.SearchItem(&BookID);

	DueDate += item->GetPeriod() * 86400;
}

void Loan::PrintDetails()
{
	string status;

	switch (Status)
	{
	case LWITHDRAWN: "OUT"; break;
	case LRETURNED: "RETURNED"; break;
	case LLATE: "LATE"; break;
	case LLOST: "LOST"; break;
	default: "UNKNOWN"; break;
	}
	struct tm* timeinfo;
	timeinfo = localtime(&DueDate);
	cout << "-----------------------------------------------------" << endl;
	cout << "Loan ID: " << LoanID << endl;
	cout << "Item ID: " << BookID << endl;
	cout << "Patron ID: " << PatronID << endl;
	cout << "Status: " << status << endl;
	cout << "Rechecked: " << Rechecked  << endl;
	cout << "Due: " << asctime(timeinfo);
	cout << "-----------------------------------------------------" << endl;
}

bool Loan::GetRecheck()
{
	return Rechecked;
}
