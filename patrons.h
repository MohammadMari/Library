#include "patron.h"
#include <vector>

class Loans;

class Patrons
{
public:
	void AddPatron();
	void EditPatron();
	void DeletePatron(Loans& loans);
	Patron* SearchPatron(int* id);
	void PrintAll();
	void PrintAllDetails();

	void Clean();

	//for my scuffed way of doing fees
	void Refresh();
	void FixPatrons();

	void Save();
	void Load();

	/*TODO:
	* 
	* ADD
	* EDIT
	* DELETE
	* SEARCH
	* PRINT list of all entries (name n shit)
	* PRINT details of all entity
	*
	*/
private:
	vector<Patron*> PatronList;
	int RemovedPatrons = 0;
};