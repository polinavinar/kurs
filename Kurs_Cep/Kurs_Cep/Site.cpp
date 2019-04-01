#include "Header.h"
#include "Site.h"

void Site::result(Game * game)
{
	{
		cout << "ÒÎÂÀÐ ÍÀÉÄÅÍ ÍÀ ÑÀÉÒÅ" << endl;
	}
}

Site::Site()
{
	filename = "Site.txt";
	cout << endl << "~~~~~~~~~ ÑÎÄÅÐÆÈÌÎÅ ÑÀÉÒÀ ~~~~~~~~~" << endl << endl;
	read_from_file(filename); //çàïîëíåíèå ìàññèâà ñ èãðàìè â áàçîâîì êëàññå
}

string Site::get_filename() { return filename; }
