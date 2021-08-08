#pragma once
#include <time.h>
#include "LibraryItems.h"

enum LoanStatus 
{
	LWITHDRAWN,
	LRETURNED,
	LLATE,
	LLOST,
};


class Loan 
{
public:
	Loan(int Loanid, int bookid, int patronid, time_t time);
	Loan(int Loanid, int bookid, int patronid, time_t time, int status, bool rechecked, time_t turnedIn);

	int GetPatronID();
	int GetBookID();
	int GetLoanID();
	int GetStatus();
	time_t GetDueDate();
	time_t GetReturnDate();

	void SetStatus(int status);
	void SetItemID(int id);
	void SetPatronID(int id);
	void SetDueDate(time_t time);
	void CheckIn();
	void Recheck(LibraryItems items);
	void PrintDetails();

	bool GetRecheck();

private:
	int LoanID;
	int BookID;
	int PatronID;
	//due date n shit
	int Status = LWITHDRAWN;
	bool Rechecked = false;
	time_t DueDate;
	time_t DateTurnedIn = 0;
};