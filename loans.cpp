#include "loans.h"
#include <iostream>
#include "patrons.h"
#include "LibraryItems.h"
#include <time.h> 
#include <fstream>

using namespace std;

void Loans::CheckOutBook(Patrons patrons, LibraryItems items)
{
	int patronID, itemID;
	cout << "Enter Patron ID: ";
	cin >> patronID;

	cout << "Enter item ID: ";
	cin >> itemID;

	auto item = items.SearchItem(&itemID);
	auto patron = patrons.SearchPatron(&patronID);
	
	if (!item || !patron)
	{
		cout << "Something went wrong!" << endl;
		return;
	}
	
	if (items.SearchItem(&itemID)->GetStatus() != IN)
	{
		cout << "Book not available right now!" << endl;
		return;
	}

	if (patron->GetBooksOut() >= 6)
	{
		cout << "Cannot checkout more than 6 books!" << endl;
		return;
	}

	item->SetStatus(OUT);
	patron->WithdrawBook();


	//http://www.cplusplus.com/reference/ctime/time/
	time_t DueDate;
	time(&DueDate); //gets current time
	DueDate += 86400 * item->GetPeriod(); //days it can be out
	struct tm* timeinfo;
	timeinfo = localtime(&DueDate);
	cout << "Due: " << asctime(timeinfo);

	auto loan = new Loan(loans.size(), itemID, patronID, DueDate);

	loans.push_back(loan);
}

void Loans::ListForPatron(LibraryItems items)
{
	int id;
	cout << "Enter patron ID: ";
	cin >> id;
	for (auto loan : loans)
	{
		if (loan->GetPatronID() == id && loan->GetStatus() != LRETURNED)
		{
			auto temp = loan->GetBookID();
			cout << "Loan ID: " << loan->GetLoanID() << " Item type: " << items.SearchItem(&temp)->GetType() << " Item Title: " << items.SearchItem(&temp)->GetTitle() << endl;
		}
	}
}

void Loans::CheckInBook(Patrons patrons, LibraryItems items)
{
	int id;
	cout << "Enter item ID: ";
	cin >> id;

	for (auto loan : loans)
	{
		if (loan->GetBookID() == id && loan->GetStatus() != LRETURNED)
		{
			auto temp = loan->GetPatronID();
			auto temp2 = loan->GetBookID();
			patrons.SearchPatron(&temp)->ReturnBook();
			items.SearchItem(&temp2)->SetStatus(IN);
			loan->CheckIn();
			cout << "Item checked in." << endl;
			return;
		}
	}

	cout << "Problem checking in item." << endl;
}

void Loans::ListOverdue()
{
	for (auto loan : loans)
	{
		if (loan->GetStatus() == LLATE)
		{
			loan->PrintDetails();
		}
	}
}

void Loans::ReCheck(LibraryItems items)
{
	int id;
	cout << "Enter item ID to recheck: ";
	cin >> id;

	for (auto loan : loans)
	{
		if (loan->GetBookID() == id)
		{
			loan->Recheck(items);
		}
	}
	
}

void Loans::EditLoan(LibraryItems items)
{
	int id;
	cout << "Enter loan ID you would like to edit: ";
	cin >> id;

	auto loan = SearchLoan(&id);

	cout << "1. Change item ID." << endl;
	cout << "2. Change patron." << endl;
	cout << "3. Change status." << endl;
	cout << "Enter choice: ";

	int input;
	cin >> input;
	
	if (input == 1)
	{
		int newID;
		cout << "Enter new item ID: ";
		cin >> newID;

		auto oldID = loan->GetBookID();
		auto oldItem = items.SearchItem(&oldID);
		
		oldItem->SetStatus(IN);
		loan->SetDueDate(loan->GetDueDate() - (86400 * oldItem->GetPeriod()));

		auto newItem = items.SearchItem(&newID);

		newItem->SetStatus(OUT);
		loan->SetDueDate(loan->GetDueDate() + (86400 * newItem->GetPeriod()));

		loan->SetItemID(newID);
	}
	else if (input == 2)
	{
		int newID;
		cout << "Enter new patron ID: ";
		cin >> newID;

		loan->SetPatronID(newID);
	}
	else if (input == 3)
	{
		int status;
		cout << "Enter new status: ";
		cin >> status;
		loan->SetStatus(status);
	}
}

void Loans::ReportLost(LibraryItems items)
{
	int id;
	cout << "Enter item ID of lost book: ";
	cin >> id;

	for (auto loan : loans)
	{
		if (loan->GetBookID() == id)
		{
			loan->SetStatus(LLOST);
			items.SearchItem(&id)->SetStatus(LOST);
		}
	}
}

Loan* Loans::SearchLoan(int* id)
{
	if (id)
	{
		if ((*id + 1) > loans.size())
		{
			cout << "Couldn't find loan." << endl;
			return nullptr;
		}
		auto item = *(loans.begin() + *id);
		return item;
	}
	else
	{
		id = new int;
		cout << "Enter loan ID: ";
		cin >> *id;

		loans.at(*id)->PrintDetails();

		return nullptr;
	}
}

void Loans::UpdateFines(Patrons& patrons, LibraryItems& items)
{
	time_t timer;
	time(&timer);

	patrons.Refresh();

	for (auto loan : loans)
	{
		if (loan->GetStatus() == LLOST)
		{
			int pid = loan->GetPatronID();
			int iid = loan->GetBookID();
			auto patron = patrons.SearchPatron(&pid);
			auto item = items.SearchItem(&iid);

			patron->SetFine(item->GetCost() + patron->GetFine());
		}
		else if (loan->GetDueDate() < timer && loan->GetStatus() != LRETURNED)
		{
			int pid = loan->GetPatronID();
			int iid = loan->GetBookID();
			auto patron = patrons.SearchPatron(&pid);
			auto item = items.SearchItem(&iid);

			int daysLate = (timer - loan->GetDueDate()) / 86400;

			if (daysLate > 10)
				daysLate = 10;

			patron->SetFine((daysLate * .25) + patron->GetFine());
			item->SetStatus(OVERDUE);
			loan->SetStatus(LLATE);
		}
		else if (loan->GetStatus() == LRETURNED && loan->GetDueDate() < loan->GetReturnDate())
		{
			int pid = loan->GetPatronID();
			int iid = loan->GetBookID();
			auto patron = patrons.SearchPatron(&pid);

			if (patron == nullptr)
				continue;
			auto item = items.SearchItem(&iid);

			int daysLate = (loan->GetReturnDate() - loan->GetDueDate()) / 86400;

			if (daysLate > 10)
				daysLate = 10;

			patron->SetFine((daysLate * .25) + patron->GetFine());
		}
	}
}

void Loans::PayFine(Patrons patrons)
{
	int id;
	cout << "Enter patron ID: ";
	cin >> id;

	float amt;
	cout << "Enter amount to pay: ";
	cin >> amt;

	patrons.SearchPatron(&id)->PayFine(amt);
}

void Loans::Save()
{
	//https://stackoverflow.com/questions/17032970/clear-data-inside-text-file-in-c
	ofstream write;
	write.open("loans.txt", ofstream::out | ofstream::trunc);
	for (auto loan : loans)
	{
		write << loan->GetBookID() << "," << loan->GetDueDate() << "," << loan->GetLoanID() << "," << loan->GetPatronID() << "," << loan->GetReturnDate() << "," << loan->GetStatus() << "," << loan->GetRecheck() << "," << endl;
	}
	write.close();
}

void Loans::Load()
{
	string line;
	ifstream myfile("loans.txt");
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			if (!line.empty())
			{
				string part;
				int item, duedate, loanID, patronID, returnDate, status;
				bool recheck;
				int count = 0;
				for (int i = 0; i < line.size(); i++)
				{
					if (line.at(i) != ',')
					{
						part += line.at(i);
					}
					else
					{

						switch (count)
						{
						case 0: item = stoi(part); break;
						case 1: duedate = stoi(part); break;
						case 2: loanID = stoi(part); break;
						case 3: patronID = stoi(part); break;
						case 4: returnDate = stoi(part); break;
						case 5: status = stoi(part); break;
						case 6: recheck = stoi(part); break;
						}
						part = "";
						count++;

					}
				}
				auto temp = new Loan(loanID, item,patronID ,duedate, status, recheck, returnDate);
				loans.push_back(temp);
			}

		}
		myfile.close();
	}
}

void Loans::Clean()
{
	for (int i = 0; i < loans.size(); i++)
	{
		delete loans.at(i);
	}

	loans.clear();
}
