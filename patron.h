#include <string>

using namespace std;


class Patron
{
public:
	Patron(string name, int id);
	Patron(string name, int id, int BooksOut, float Fine);

	void WithdrawBook();
	void ReturnBook();

	void PrintDetails();
	
	void SetName(string name);
	void SetID(int id);
	void SetFine(float fine);
	void SetBooksOut(int books);

	string GetName();
	int GetID(); 
	float GetFine();
	int GetBooksOut();

	void PayFine(float amt);

	void FixFine();

private:
	string Name;
	int ID;
	float FineBalance = 0;
	int NumBooksOut = 0;
	float AmtPaid = 0;
};