#include "patrons.h"
#include <iostream>
#include <fstream>

void Patrons::AddPatron()
{
	Patron* temp;
	string name;
	cout << "Enter new patron name: ";
	cin.ignore();
	getline(cin, name);

	temp = new Patron(name, PatronList.size() + RemovedPatrons);

	PatronList.push_back(temp);
}

void Patrons::EditPatron()
{
	int id, choice;

	cout << "Enter ID of person you would like to edit: ";
	cin >> id;

	auto patron = SearchPatron(&id);

	if (!patron)
	{
		cout << "Couldn't find patron." << endl;
		return;
	}


	cout << "1. Change name." << endl;
	cout << "2. Change fine." << endl;
	cout << "3. Change books out." << endl;
	cout << "Enter choice: ";
	cin >> choice;
	switch (choice)
	{
	case 1: {
		string name;
		cout << "Enter new name: ";
		cin.ignore();
		getline(cin, name);
		patron->SetName(name);
	} break;
	case 2: {
		float fine;
		cout << "Enter new fine: ";
		cin >> fine;
		patron->SetFine(fine);
	} break;
	case 3: {
		int numBooksOut;
		cout << "Enter new amount of books out: ";
		cin >> numBooksOut;
		patron->SetBooksOut(numBooksOut);
	} break;
	}
}

//check for loans/fines before you remove
void Patrons::DeletePatron(Loans& loans)
{
	int ID;
	cout << "Enter patron ID you would like to remove: ";
	cin >> ID;

	if (PatronList.size() > ID)
	{
		if (PatronList.at(ID)->GetFine() > 0 || PatronList.at(ID)->GetBooksOut() > 0)
		{
			cout << "Patron has an outstanding balance or books out, delete failed!" << endl;
			return;
		}

		RemovedPatrons++;

		//PatronList.erase(PatronList.begin() + ID);
		PatronList.at(ID) = nullptr;
		cout << "Patron successfully removed." << endl;
		return;
	}

	cout << "Patron was not able to be removed." << endl;

}

//https://stackoverflow.com/questions/641864/returning-a-pointer-to-a-vector-element-in-c
Patron* Patrons::SearchPatron(int* id)
{
	if (PatronList.size() == 0)
		return nullptr;

	if (id)
	{

		if ((*id + 1) > PatronList.size())
		{
			cout << "Couldn't find patron." << endl;
			return nullptr;
		}
		auto patron = *(PatronList.begin() + *id);
		return patron;
	}
	else
	{
		id = new int;
		cout << "Enter patron ID: ";
		cin >> *id;

		PatronList.at(*id)->PrintDetails();
		return nullptr;
	}
}

void Patrons::PrintAll()
{
	if (PatronList.empty())
	{
		cout << "No patrons :(" << endl;
		return;
	}


	cout << "-----------------------------------------------------" << endl;
	for (int i = 0; i < PatronList.size(); i++)
	{
		cout << "ID " << i << ": " << PatronList.at(i)->GetName() << endl;
	}
	cout << "-----------------------------------------------------" << endl;
}

void Patrons::PrintAllDetails()
{
	if (PatronList.empty())
	{
		cout << "No patrons :(" << endl;
		return;
	}

	for (auto patron : PatronList)
	{
		if (!patron)
			return;
		patron->PrintDetails();
	}

}

void Patrons::Clean()
{
	for (int i = 0; i < PatronList.size(); i++)
	{
		delete PatronList.at(i);
	}

	PatronList.clear();
}

void Patrons::Refresh()
{
	for (auto patron : PatronList)
	{
		if (!patron)
			return;

		patron->SetFine(0);
	}
}

void Patrons::FixPatrons()
{
	for (auto patron : PatronList)
	{
		if (!patron)
			return;
		patron->FixFine();
	}
}

void Patrons::Save()
{
	ofstream write;
	write.open("patrons.txt", ofstream::out | ofstream::trunc);
	for (auto patron : PatronList)
	{
		write << patron->GetID() << "," << patron->GetName() << "," << patron->GetBooksOut() << "," << patron->GetFine() << "," << endl;
	}
}

void Patrons::Load()
{
	string line;
	ifstream myfile("patrons.txt");
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			if (!line.empty())
			{
				string part;
				int ID, booksOut;
				string name;
				float fine;
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
						case 0: ID = stoi(part); break;
						case 1: name = part; break;
						case 2: booksOut = stoi(part); break;
						case 3: fine = stof(part); break;
						}
						part = "";
						count++;

					}
				}
				auto temp = new Patron(name, ID, booksOut, fine);
				PatronList.push_back(temp);
			}

		}
		myfile.close();
	}
}
