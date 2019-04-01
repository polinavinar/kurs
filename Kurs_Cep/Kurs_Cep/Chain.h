#pragma once
#include "Header.h"
#include "Game.h"
class Сhain {
protected:

	Сhain * next;						// более умелый полицейский, который получит дело, если для текущего оно слишком сложное
	Game *game_list;					// массив с играми
	int size_of_game_list;				// размер массива с играми
	virtual void result(Game* game);	// результат найденной игры

public:

	Сhain();

	///Если не обнаружили нужную нам игру в этом узле, переходим на следующий
	Сhain* setNext(Сhain* сhain);


	/// Если не обнаружили нужную нам игру в этом узле, переходим на следующий
	void search(Game* game);

	///дозапись в файл
	void add_to_file(string file);


	///запись в файл
	void write_to_file(string file, int add_val);

	///чтение из файла
	void read_from_file(string file);

	virtual ~Сhain();
};
