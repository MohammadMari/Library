#include "cd.h"
#include <iostream>

void CD::PrintDetails()
{
	cout << "-----------------------------------------------------" << endl;
	cout << "ID: " << ID << endl;
	cout << "Type: " << GetType() << endl;
	cout << "Artist: " << Artist << endl;
	cout << "Title: " << Title << endl;
	cout << "Number of tracks: " << numTracks << endl;
	cout << "Release date: " << ReleaseDate << endl;
	cout << "Genre: " << Genre << endl;
	cout << "Cost: " << Cost << endl; //format
	cout << "Days allowed out: " << Period << endl;
	cout << "Status: " << Status << endl; //format
	cout << "-----------------------------------------------------" << endl;
}

void CD::SetArtist(string artist)
{
	Artist = artist;
}

void CD::SetReleaseDate(string ReleaseDate)
{
}

void CD::SetGenre(string genre)
{
	Genre = genre;
}

void CD::SetTracks(int tracks)
{
	numTracks = tracks;
}

string CD::GetArtist()
{
	return Artist;
}

string CD::GetReleaseDate()
{
	return ReleaseDate;
}

string CD::GetGenre()
{
	return Genre;
}

int CD::GetTracks()
{
	return numTracks;
}
