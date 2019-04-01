#include "Header.h"
#include "Game.h"
using namespace std;

Game::Game()
{
	name[0] = EOF;
	genre[0] = EOF;
	year = 0;
	platform[0] = EOF;
	sys_req[0] = EOF;
	developer[0] = EOF;
	quantity = 0;
}

Game::Game(char * name1, char * genre1, int year1, char * platform1, char * sys_req1, char * developer1, int quantity1)
{
	strcpy(name, name1);
	strcpy(name, name1);
	year = year1;
	strcpy(name, name1);
	strcpy(name, name1);
	strcpy(name, name1);
	quantity = quantity1;
}

void Game::set_game(void)
{
	cout << "Введите название " << endl;
	cin >> name;
	cout << "Введите жанр " << endl;
	cin >> genre;
	cout << "Введите год выпуска " << endl;
	cin >> year;
	cout << "Введите игровую платформу " << endl;
	cin >> platform;
	cout << "Введите системные требования " << endl;
	cin >> sys_req;
	cout << "Введите разработчика " << endl;
	cin >> developer;
	cout << "Введите количество " << endl;
	cin >> quantity;
}

void Game::show_game(void)
{
	cout << "Название игры: " << name << "; Жанр игры: " << genre << "; Год выпуска " << year << "; Игровая платформа " << platform << "; Cистемные требования " << sys_req << endl;
	cout << "; Разработчик " << developer << "; Количество " << quantity << ";" << endl;
}
