#pragma once
#include "Chain.h"

class Warehouse : public Сhain {
protected:
	string filename;
	void result(Game* game);

public:

	Warehouse(); //конструктор
	string get_filename();
};

