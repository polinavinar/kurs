#include "Header.h"
#include "Shop.h"

void Shop::result(Game * game)
{
	cout << "ÒÎÂÀÐ ÍÀÉÄÅÍ Â ÌÀÃÀÇÈÍÅ" << endl;
}

Shop::Shop()
{
	filename = "Shop.txt";
	cout << endl << "~~~~~~~~~ ÑÎÄÅÐÆÈÌÎÅ ÌÀÃÀÇÈÍÀ ~~~~~~~~~" << endl << endl;
	read_from_file(filename); //çàïîëíåíèå ìàññèâà ñ èãðàìè â áàçîâîì êëàññå
}

string Shop::get_filename() { return filename; }
