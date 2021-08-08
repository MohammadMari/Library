#include "LibraryItems.h"
#include <iostream>
#include <fstream>


void LibraryItems::NewBook()
{
	string author, title, isbn, category;
	float cost;
	int period; //how long its checked out for

	cout << "Enter author: ";
	cin.ignore();
	getline(cin, author);
	cout << "Enter title: ";
	getline(cin, title);
	cout << "Enter ISBN Number: ";
	getline(cin, isbn);
	cout << "Enter category: ";
	getline(cin, category);

	cout << "Enter cost: ";
	cin >> cost;
	cout << "Enter how many days item is allowed to be out for: ";
	cin >> period;

	auto temp = new Book(items.size(), cost, IN, period, author, title, isbn, category);
	items.push_back(temp);

	cout << "Book has been successfuly added!" << endl;
}

void LibraryItems::NewCD()
{
	string artist, title, releasedate, genre;
	float cost;
	int period, numTracks; //how long its checked out for

	cout << "Enter artist: ";
	cin.ignore();
	getline(cin, artist);
	cout << "Enter title: ";
	getline(cin, title);
	cout << "Enter number of tracks: ";
	cin >> numTracks;
	cout << "Enter release date: ";
	cin.ignore();
	getline(cin, releasedate);
	cout << "Enter genre: ";
	getline(cin, genre);

	cout << "Enter cost: ";
	cin >> cost;
	cout << "Enter how many days item is allowed to be out for: ";
	cin >> period;

	auto temp = new CD(items.size(), cost, IN, period, artist, title, numTracks, releasedate, genre);
	items.push_back(temp);

	cout << "CD has been successfuly added!" << endl;
}

void LibraryItems::NewDVD()
{
	string title, category, runtime, studio, releasedate;
	float cost;
	int period; //how long its checked out for

	cout << "Enter title: ";
	cin.ignore();
	getline(cin, title);
	cout << "Enter category: ";
	getline(cin, category);
	cout << "Enter runtime: ";
	getline(cin, runtime);
	cout << "Enter studio: ";
	getline(cin, studio);
	cout << "Enter release date: ";
	getline(cin, releasedate);

	cout << "Enter cost: ";
	cin >> cost;
	cout << "Enter how many days item is allowed to be out for: ";
	cin >> period;

	auto temp = new DVD(items.size(), cost, IN, period, title, category, runtime, studio, releasedate);
	items.push_back(temp);

	cout << "DVD has been successfuly added!" << endl;
}


void LibraryItems::NewItem()
{
	int choice;
	cout << "1. New book." << endl;
	cout << "2. New CD." << endl;
	cout << "3. New DVD." << endl;
	cout << "Choice: ";
	cin >> choice;


	switch (choice)
	{
	case 1: NewBook(); break;
	case 2: NewCD(); break;
	case 3: NewDVD(); break;
	}
}

void LibraryItems::RemoveItem()
{
	int ID;
	cout << "Enter item ID you would like to remove: ";
	cin >> ID;
	if (items.size() > ID)
	{
		if (items.at(ID)->GetStatus() != IN)
		{
			cout << "Item is not in the library again! Try again later." << endl;
			return;
		}

		for (int i = ID + 1; i < items.size(); i++)
		{
			items.at(i)->SetID(items.at(i)->GetID() - 1);
		}

		items.erase(items.begin() + ID);
		cout << "Item successfully removed." << endl;
		return;
	}

	cout << "Item was not able to be removed." << endl;
}

void LibraryItems::EditItem()
{
	int id, choice;

	cout << "Enter ID of item you would like to edit: ";
	cin >> id;

	auto item = SearchItem(&id);

	if (!item)
	{
		cout << "Couldn't find item." << endl;
		return;
	}


	cout << "1. Change Title." << endl;
	cout << "2. Change Cost." << endl;
	cout << "3. Change Status." << endl;
	cout << "4. Change Period." << endl;

	if (item->GetType() == "CD")
	{
		CD* cd = static_cast<CD*>(item);
		cout << "5. Change Artist." << endl;
		cout << "6. Change number of tracks." << endl;
		cout << "7. Change release date." << endl;
		cout << "8. Change genre." << endl;

		cout << "Enter choice: ";
		cin >> choice;

		switch (choice)
		{
		case 1: {
			cout << "Enter new title: ";
			string temp;
			cin.ignore();
			getline(cin, temp);
			cd->SetTitle(temp);
		} break;
		case 2: {
			float tempCost;
			cout << "Enter new cost: ";
			cin.ignore();
			cin >> tempCost;
			cd->SetCost(tempCost);

		} break;
		case 3: {
			cout << "Enter new status: ";
			int status;
			cin >> status;
			cd->SetStatus(status);

		} break;
		case 4: {
			cout << "Enter new period: ";
			int period;
			cin >> period;
			cd->SetPeriod(period);

		} break;
		case 5: {
			cout << "Enter new artist: ";
			string temp;
			cin.ignore();
			getline(cin, temp);
			cd->SetArtist(temp);
		} break;
		case 6: {
			cout << "Enter number of tracks: ";
			int tracks;
			cin >> tracks;
			cd->SetTracks(tracks);
		} break;
		case 7: {
			cout << "Enter release date: ";
			string temp;
			cin.ignore();
			getline(cin, temp);
			cd->SetReleaseDate(temp);
		} break;
		case 8: {
			cout << "Enter new genre: ";
			string temp;
			cin.ignore();
			getline(cin, temp);
			cd->SetGenre(temp);
		} break;
		}
	}

	if (item->GetType() == "DVD")
	{
		DVD* dvd = static_cast<DVD*>(item);
		cout << "5. Change category." << endl;
		cout << "6. Change run time." << endl;
		cout << "7. Change studio." << endl;
		cout << "8. Change release date." << endl;

		cout << "Enter choice: ";
		cin >> choice;

		switch (choice)
		{
		case 1: {
			cout << "Enter new title: ";
			string temp;
			cin.ignore();
			getline(cin, temp);
			dvd->SetTitle(temp);
		} break;
		case 2: {
			float tempCost;
			cout << "Enter new cost: ";
			cin.ignore();
			cin >> tempCost;
			dvd->SetCost(tempCost);

		} break;
		case 3: {
			cout << "Enter new status: ";
			int status;
			cin >> status;
			dvd->SetStatus(status);

		} break;
		case 4: {
			cout << "Enter new period: ";
			int period;
			cin >> period;
			dvd->SetPeriod(period);

		} break;
		case 5: {
			cout << "Enter new category: ";
			string temp;
			cin.ignore();
			getline(cin, temp);
			dvd->SetCategory(temp);
		} break;
		case 6: {
			cout << "Enter new run time: ";
			string temp;
			cin.ignore();
			getline(cin, temp);
			dvd->SetRuntime(temp);
		} break;
		case 7: {
			cout << "Enter new studio: ";
			string temp;
			cin.ignore();
			getline(cin, temp);
			dvd->SetStudio(temp);
		} break;
		case 8: {
			cout << "Enter new release date: ";
			string temp;
			cin.ignore();
			getline(cin, temp);
			dvd->SetRelease(temp);
		} break;
		}
	}

	if (item->GetType() == "Book")
	{
		Book* book = static_cast<Book*>(item);
		cout << "5. Change Author." << endl;
		cout << "6. Change ISBN." << endl;
		cout << "7. Change category." << endl;

		cout << "Enter choice: ";
		cin >> choice;

		switch (choice)
		{
		case 1: {
			cout << "Enter new title: ";
			string temp;
			cin.ignore();
			getline(cin, temp);
			book->SetTitle(temp);
		} break;
		case 2: {
			float tempCost;
			cout << "Enter new cost: ";
			cin.ignore();
			cin >> tempCost;
			book->SetCost(tempCost);

		} break;
		case 3: {
			cout << "Enter new status: ";
			int status;
			cin >> status;
			book->SetStatus(status);

		} break;
		case 4: {
			cout << "Enter new period: ";
			int period;
			cin >> period;
			book->SetPeriod(period);

		} break;
		case 5: {
			cout << "Enter new author: ";
			string temp;
			cin.ignore();
			getline(cin, temp);
			book->SetAuthor(temp);
		} break;
		case 6: {
			cout << "Enter ISBN ";
			string temp;
			cin.ignore();
			getline(cin, temp);
			book->SetISBN(temp);
		} break;
		case 7: {
			cout << "Enter category: ";
			string temp;
			cin.ignore();
			getline(cin, temp);
			book->SetCategory(temp);
		} break;
		}
	}
}

LibraryItem* LibraryItems::SearchItem(int* id)
{
	if (items.size() == 0)
		return nullptr;

	if (id)
	{
		if ((*id + 1) > items.size())
		{
			cout << "Couldn't find item." << endl;
			return nullptr;
		}
		auto item = *(items.begin() + *id);
		return item;


	}
	else
	{
		id = new int;
		cout << "Enter item ID: ";
		cin >> *id;

		items.at(*id)->PrintDetails();
		return nullptr;
	}
}

void LibraryItems::ListItems()
{
	cout << "-----------------------------------------------------" << endl;
	for (int i = 0; i < items.size(); i++)
	{
		cout << items.at(i)->GetType() << " ID " << i << ": " << items.at(i)->GetTitle() << endl;
	}
	cout << "-----------------------------------------------------" << endl;
}

void LibraryItems::ListItemDetails()
{
	for (int i = 0; i < items.size(); i++)
	{
		items.at(i)->PrintDetails();
	}
}

void LibraryItems::Save()
{
	ofstream write;
	write.open("items.txt", ofstream::out | ofstream::trunc);
	for (auto item : items)
	{
		write << item->GetType() << "," << item->GetID() << "," << item->GetCost() << "," << item->GetStatus() << "," << item->GetPeriod() << "," << item->GetTitle() << ",";
		if (item->GetType() == "Book")
		{
			auto temp = (Book*)item;
			write << temp->GetAuthor() << "," << temp->GetISBN() << "," << temp->GetCategory() << "," << endl;
		}
		if (item->GetType() == "CD")
		{
			auto temp = (CD*)item;
			write << temp->GetArtist() << "," << temp->GetTracks() << "," << temp->GetReleaseDate() << "," << temp->GetGenre() << "," << endl;

		}
		if (item->GetType() == "DVD")
		{
			auto temp = (DVD*)item;
			write << temp->GetCategory() << "," << temp->GetRunTime() << "," << temp->GetStudio() << "," << temp->GetReleaseDate() << "," << endl;
		}
	}
	write.close();
}

void LibraryItems::Load()
{
	string line;
	ifstream myfile("items.txt");
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			if (!line.empty())
			{
				string part;
				string itemType, title;
				int itemID, period, status, numTracks;
				float cost;

				string Author, ISBN, Category, RunTime, Release, studio;

				int count = 0;
				for (int i = 0; i < line.size(); i++)
				{
					if (line.at(i) != ',')
					{
						part += line.at(i);
					}
					else
					{
						if (count == 0)
						{
							itemType = part;
						}
						else if (count <= 5)
						{
							switch (count)
							{
							case 1: itemID = stoi(part); break;
							case 2: cost = stof(part); break;
							case 3: status = stoi(part); break;
							case 4: period = stoi(part); break;
							case 5: title = part; break;
							}
						}
						else if (itemType == "Book")
						{
							switch (count)
							{
							case 6: Author = part; break;
							case 7: ISBN = part; break;
							case 8: Category = part; break;
							}
						}
						else if (itemType == "CD")
						{
							switch (count)
							{
							case 1: Author = part; break;
							case 2: numTracks = stoi(part); break;
							case 3: Release = part; break;
							case 4: Category = part; break;
							}
						}
						else if (itemType == "DVD")
						{
							switch (count)
							{
							case 1: Category = part; break;
							case 2: RunTime = part; break;
							case 3: studio = part; break;
							case 4: Release = part; break;
							}
						}


						part = "";
						count++;

					}
				}

				if (itemType == "Book")
				{
					auto book = new Book(itemID, cost, status, period, Author, title, ISBN, Category);
					items.push_back(book);
				}
				else if (itemType == "CD")
				{
					auto cd = new CD(itemID, cost, status, period, Author, title, numTracks, Release, Category);
					items.push_back(cd);
				}
				else if (itemType == "DVD")
				{
					auto dvd = new DVD(itemID, cost, status, period, title, Category, RunTime, studio, Release);
					items.push_back(dvd);
				}
			}

		}
		myfile.close();
	}
}

void LibraryItems::Clean()
{
	for (int i = 0; i < items.size(); i++)
	{
		delete items.at(i);
	}

	items.clear();
}
