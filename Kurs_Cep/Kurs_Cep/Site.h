#pragma once
#include "Chain.h"

class Site : public Сhain {
protected:

	string filename;
	void result(Game* game);

public:

	Site(); //конструктор
	string get_filename();
};