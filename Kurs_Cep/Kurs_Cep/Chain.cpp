#include "Header.h"
#include "Chain.h"
#include "Game.h"

void Сhain::result(Game * game) {}

Сhain::Сhain()
{
	next = nullptr;
	game_list = nullptr;
	size_of_game_list = NULL;
}

Сhain * Сhain::setNext(Сhain * сhain)
{
	next = сhain;
	return next;
}

void Сhain::search(Game * game)
{
	bool flag = false;
	for (int i = 0; i < size_of_game_list; i++)
	{
		if (!strcmp(game_list[i].name, game->name) && !strcmp(game_list[i].platform, game->platform) && (game_list[i].quantity >= game->quantity))
		{
			flag = true;
		}
	}

	if (flag)
	{
		result(game);
		return;
	}
	else
	{
		if (next)
		{
			next->search(game);
		}
		else
		{
			cout << "Игра нигде не была найдена." << endl;
			return;
		}
	}
}

void Сhain::add_to_file(string file)
{
	int add_value; //сколько игр хотим добавить
	read_from_file(file);

	cout << "Сколько игр вы хотите добавить в базу? " << endl;
	cin >> add_value;
	size_of_game_list += add_value;

	write_to_file(file, add_value);
}

void Сhain::write_to_file(string file, int add_val)
{
	ofstream out;
	Game tmp;
	try
	{
		out.open(file, ios::out);
		if (!out.is_open()) {
			throw 505;
		}

		out.write(reinterpret_cast<char*>(&size_of_game_list), sizeof(int));

		for (int i = 0; i < size_of_game_list - add_val; i++)
		{
			out.write(reinterpret_cast<char*>(&game_list[i]), sizeof(Game)); //перезаписываем содержимое gamelist
		}

		for (int i = 0; i < add_val; i++)
		{
			tmp.set_game();
			out.write(reinterpret_cast<char*>(&tmp), sizeof(Game)); //добавляем новые данные
		}
		out.close();
	}
	catch (const int &ex)
	{
		cout << "Ошибка открытия файла!" << endl << "Код ошибки: #" << ex << endl;
	}
}

void Сhain::read_from_file(string file)
{
	ifstream in;
	try
	{
		in.open(file, ios::in);
		if (!in.is_open())
		{
			throw 505;
		}
		else
		{
			if (in.peek() == EOF)
			{
				throw 510;
			}
		}
		in.read(reinterpret_cast<char*>(&size_of_game_list), sizeof(int));
		game_list = new Game[size_of_game_list];
		for (int i = 0; i < size_of_game_list; i++)
		{
			in.read(reinterpret_cast<char*>(&game_list[i]), sizeof(Game));
			game_list[i].show_game();
		}
		in.close();
	}
	catch (const int &ex)
	{
		cout << "Ошибка работы файла!" << endl << "Код ошибки: #" << ex << endl;
	}
}

Сhain::~Сhain()
{
	if (game_list)
	{
		delete[] game_list;
	}
	if (next)
	{
		delete next;
	}
}
