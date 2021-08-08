#pragma once

#include "LibraryItem.h"


class CD : public LibraryItem
{
public:
	CD(int ID, float cost, int status, int period, string artist, string title, int numtracks, string release, string genre) : LibraryItem(ID, cost, status, period, title)
	{
		Artist = artist;
		ReleaseDate = release;
		Genre = genre;
	};

	void SetArtist(string artist);
	void SetReleaseDate(string ReleaseDate);
	void SetGenre(string genre);
	void SetTracks(int tracks);
	string GetArtist();
	string GetReleaseDate();
	string GetGenre();
	int GetTracks();
	void PrintDetails();

	string GetType()
	{
		return "CD";
	}
private:
	string Artist;
	int numTracks;
	string ReleaseDate;
	string Genre;
};