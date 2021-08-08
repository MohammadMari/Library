
library: main.o patron.o patrons.o loan.o loans.o book.o dvd.o cd.o LibraryItem.o LibraryItems.o
	g++ main.o patron.o patrons.o loan.o loans.o book.o dvd.o cd.o LibraryItem.o LibraryItems.o

main.o: main.cpp
	g++ -c main.cpp

patron.o: patron.cpp patron.h
	g++ -c patron.cpp

patrons.o: patrons.cpp patrons.h
	g++ -c patrons.cpp

loan.o: loan.cpp loan.h
	g++ -c loan.cpp

loans.o: loans.cpp loans.h
	g++ -c loans.cpp

book.o: book.cpp book.h
	g++ -c book.cpp

dvd.o: dvd.cpp dvd.h
	g++ -c dvd.cpp

cd.o: cd.cpp cd.h
	g++ -c cd.cpp
	
LibraryItem.o: LibraryItem.cpp LibraryItem.h
	g++ -c LibraryItem.cpp
	
LibraryItems.o: LibraryItems.cpp LibraryItems.h
	g++ -c LibraryItems.cpp

clean:
	rm *.o
