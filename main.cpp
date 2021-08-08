#include <iostream>

#include "LibraryItems.h"
#include "loans.h"
#include "patrons.h"

//mtm0227

int PrintMenu()
{
	int choice;
	cout << "-----------------------------------------------------" << endl;
	cout << "1 - Borrow/return item." << endl; //loans
	cout << "2 - Manage patrons." << endl; //patrons
	cout << "3 - Manage items." << endl; //LibraryItems
	cout << "4 - Exit" << endl;
	cout << "-----------------------------------------------------" << endl;
	cout << "Choice: ";
	cin >> choice;

	return choice;
}

void ManageLoans(Loans& loans, Patrons& patrons, LibraryItems& items)
{
	cout << "-----------------------------------------------------" << endl;
	cout << "1 - Check out item." << endl; 
	cout << "2 - Return item." << endl; 
	cout << "3 - List overdue." << endl; 
	cout << "4 - List books for patron." << endl; 
	cout << "5 - Re-check." << endl; 
	cout << "6 - Edit loan." << endl; 
	cout << "7 - Report lost." << endl; 
	cout << "8 - Search loan." << endl; 
	cout << "9 - Pay fine." << endl; 
	cout << "10 - Exit" << endl;
	cout << "-----------------------------------------------------" << endl;

	int choice;
	cin >> choice;

	switch (choice)
	{
	case 1: loans.CheckOutBook(patrons, items); break;
	case 2: loans.CheckInBook(patrons, items); break;
	case 3: loans.ListOverdue(); break;
	case 4: loans.ListForPatron(items);  break;
	case 5: loans.ReCheck(items); break;
	case 6: loans.EditLoan(items); break;
	case 7: loans.ReportLost(items); break;
	case 8: loans.SearchLoan(nullptr); break;
	case 9: loans.PayFine(patrons); break;
	}
}

void ManagePatrons(Loans& loans, Patrons& patrons, LibraryItems& items)
{
	cout << "-----------------------------------------------------" << endl;
	cout << "1 - Register member." << endl; 
	cout << "2 - Remove member." << endl; 
	cout << "3 - Edit member details." << endl; 
	cout << "4 - Search member." << endl; 
	cout << "5 - List patrons." << endl; 
	cout << "6 - List with details." << endl; 
	cout << "7 - Exit" << endl;
	cout << "-----------------------------------------------------" << endl;
	int choice;
	cin >> choice;

	switch (choice)
	{
	case 1: patrons.AddPatron(); break;
	case 2: patrons.DeletePatron(loans); break;
	case 3: patrons.EditPatron(); break;
	case 4: patrons.SearchPatron(nullptr);  break;
	case 5: patrons.PrintAll(); break;
	case 6: patrons.PrintAllDetails(); break;
	}
}

void ManageItems(Loans& loans, Patrons& patrons, LibraryItems& items)
{
	cout << "-----------------------------------------------------" << endl;
	cout << "1 - Add item." << endl; 
	cout << "2 - Remove item." << endl;
	cout << "3 - Edit items." << endl; 
	cout << "4 - Search items." << endl; 
	cout << "5 - List items." << endl; 
	cout << "6 - List items with detail." << endl; 
	cout << "7 - Exit" << endl;
	cout << "-----------------------------------------------------" << endl;

	int choice;
	cin >> choice;

	switch (choice)
	{
	case 1: items.NewItem(); break;
	case 2: items.RemoveItem(); break;
	case 3: items.EditItem(); break;
	case 4: items.SearchItem(nullptr);  break;
	case 5: items.ListItems();  break;
	case 6: items.ListItemDetails();  break;
	}

}


int main()
{
	Loans loans;
	Patrons patrons;
	LibraryItems items;

	loans.Load();
	patrons.Load();
	items.Load();

	int input = -1;
	while (input != 4)
	{
		loans.UpdateFines(patrons, items);
		patrons.FixPatrons();

		input = PrintMenu();

		switch (input)
		{
		case 1: ManageLoans(loans, patrons, items);  break;
		case 2: ManagePatrons(loans, patrons, items); break;
		case 3: ManageItems(loans, patrons, items);  break;
		}
	}

	loans.Save();
	patrons.Save();
	items.Save();

	loans.Clean();
	patrons.Clean();
	items.Clean();
}