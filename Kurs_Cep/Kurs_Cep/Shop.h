#pragma once
#include "Chain.h"

class Shop : public Сhain {
protected:
	string filename;
	void result(Game* game);

public:

	Shop(); //конструктор
	string get_filename();
};