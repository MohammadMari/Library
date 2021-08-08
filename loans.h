#pragma once
#include "loan.h"
#include <vector>

class Patrons;
class LibraryItems;

class Loans 
{
public:
	//TODO:
	/*
		1. Check out book.
		2. Check in
		3. List overdue.
		4. list for patron
		5. update loan status based off system clock.
		6. re-check a book
		7. edit loan
		8. report lost.
	*/

	void CheckOutBook(Patrons patrons, LibraryItems items);
	void ListForPatron(LibraryItems items);
	void CheckInBook(Patrons patrons, LibraryItems items);
	void ListOverdue();
	void ReCheck(LibraryItems items);
	void EditLoan(LibraryItems items);
	void UpdateLoanStatus(Patrons& patrons);

	//void EditLoan();
	void ReportLost(LibraryItems items);

	Loan* SearchLoan(int* id);
	void UpdateFines(Patrons& patrons, LibraryItems& items);

	void PayFine(Patrons patrons);


	void Save();
	void Load();
	void Clean();

private:
	std::vector<Loan*> loans;
};