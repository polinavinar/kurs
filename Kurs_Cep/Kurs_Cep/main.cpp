#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
const int NotUsed = system("color 1E");
using namespace std;

#define N 3

class Game {

	friend class Сhain;     // Полицейские имеют доступ к материалам следствия

	char name[50];			//название
	char genre[20];			//жанр
	int year;				//год выпуска
	char platform[10];		//игровая платформа (ПК, Xbox, PS)
	char sys_req[100];			//системные треб
	char developer[30];		//разработчик
	int quantity;			//количество

public:
	///конструктор
	Game() {
		name[0] = EOF;
		genre[0] = EOF;
		year = 0;
		platform[0] = EOF;
		sys_req[0] = EOF;
		developer[0] = EOF;
		quantity = 0;
	}

	///конструктор с параметрами
	Game(char* name1, char* genre1, int year1, char* platform1, char* sys_req1, char* developer1, int quantity1) {
		strcpy(name, name1);
		strcpy(name, name1);
		year = year1;
		strcpy(name, name1);
		strcpy(name, name1);
		strcpy(name, name1);
		quantity = quantity1;
	}

	///Сеттер
	void set_game(void)
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
	///просмотр
	void show_game(void)
	{
		cout << "Название игры: " << name << "; Жанр игры: " << genre << "; Год выпуска " << year << "; Игровая платформа " << platform << "; Cистемные требования " << sys_req << endl;
		cout << "; Разработчик " << developer << "; Количество " << quantity << ";" << endl;
	}
};

class Сhain {
protected:

	Сhain * next;						// более умелый полицейский, который получит дело, если для текущего оно слишком сложное
	Game *game_list;					// массив с играми
	int size_of_game_list;				// размер массива с играми
	virtual void result(Game* game) {}	// результат найденной игры

public:

	Сhain() {
		next = nullptr;
		game_list = nullptr;
		size_of_game_list = NULL;
	}

	///Если не обнаружили нужную нам игру в этом узле, переходим на следующий
	Сhain* setNext(Сhain* сhain)
	{
		next = сhain;
		return next;
	}


	/// Если не обнаружили нужную нам игру в этом узле, переходим на следующий
	void search(Game* game)
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

	///дозапись в файл
	void add_to_file(string file)
	{
		int add_value; //сколько игр хотим добавить
		read_from_file(file);

		cout << "Сколько игр вы хотите добавить в базу? " << endl;
		cin >> add_value;
		size_of_game_list += add_value;

		write_to_file(file, add_value);
	}


	///запись в файл
	void write_to_file(string file, int add_val)
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

	///чтение из файла
	void read_from_file(string file)
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


	virtual ~Сhain()
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
};

class Site : public Сhain {
protected:

	string filename;
	void result(Game* game)
	{
		cout << "ТОВАР НАЙДЕН НА сайте" << endl;
	}

public:

	Site() //конструктор
	{
		filename = "Site.txt";
		cout << endl << "~~~~~~~~~ СОДЕРЖИМОЕ САЙТА ~~~~~~~~~" << endl << endl;
		read_from_file(filename); //заполнение массива с играми в базовом классе
	}

	string get_filename() { return filename; }
};

class Shop : public Сhain {
protected:
	string filename;
	void result(Game* game)
	{
		cout << "ТОВАР НАЙДЕН В МАГАЗИНЕ" << endl;
	}

public:

	Shop() //конструктор
	{
		filename = "Shop.txt";
		cout << endl << "~~~~~~~~~ СОДЕРЖИМОЕ МАГАЗИНА ~~~~~~~~~" << endl << endl;
		read_from_file(filename); //заполнение массива с играми в базовом классе
	}

	string get_filename() { return filename; }
};

class Warehouse : public Сhain {
protected:
	string filename;
	void result(Game* game)
	{
		cout << "ТОВАР НАЙДЕН НА СКЛАДЕ" << endl;
	}

public:

	Warehouse() //конструктор
	{
		filename = "Warehouse.txt";
		cout << endl << "~~~~~~~~~ СОДЕРЖИМОЕ СКЛАДА ~~~~~~~~~" << endl << endl;
		read_from_file(filename); //заполнение массива с играми в базовом классе
	}

	string get_filename() { return filename; }
};

int main()
{
	setlocale(LC_ALL, "Russian");

	Сhain *chain;
	Game *game;
	Site *site;
	Shop *shop;
	Warehouse *warehouse;



	int swtch1 = 1;
	while (swtch1 != 0) {
		cout << endl << endl << "Выберите действие:" << endl <<
			"|1| <-> Вывести все данные из всех источников" << endl <<
			"|2| <-> Добавление элементов в базу" << endl <<
			"|3| <-> Найти игру на сайте -> магазине -> складе" << endl <<
			"|0| <-> Выход" << endl;
		cin >> swtch1;
		switch (swtch1)
		{
		case 1: /*Вывести все данные на экран*/
			chain = new Site;
			chain = new Shop;
			chain = new Warehouse;
			delete chain;
			break;
		case 2:
			cout << "Выберите действие:" << endl <<
				"|1| <-> Добавление игр на сайт" << endl <<
				"|2| <-> Добавление игр в магазин" << endl <<
				"|3| <-> Добавление игр на склад" << endl <<
				"|0| <-> Отмена" << endl;
			cin >> swtch1;
			switch (swtch1)
			{
			case 1: /*Добавление игр на сайт*/
				site = new Site;
				site->add_to_file(site->get_filename());
				delete site;
				break;
			case 2: /*Добавление игр в магазин*/
				shop = new Shop;
				shop->add_to_file(shop->get_filename());
				delete shop;
				break;
			case 3: /*Добавление игр на склад*/
				warehouse = new Warehouse;
				warehouse->add_to_file(warehouse->get_filename());
				delete warehouse;
				break;
			default:
				break;
			}
			break;
		case 3:
			std::cout << "OUTPUT:" << std::endl;
			chain = new Site;  // низший уровень в цепи сайт->магазин->склад
			chain->setNext(new Shop)->setNext(new Warehouse);

			cout << endl << "Введите данные об игре для поиска " << endl;
			game = new Game;
			game->set_game();

			chain->search(game);

			delete game;
			break;
		case 0:
			break;
		default:
			break;
		}
	}









	system("pause");
	return 0;
}