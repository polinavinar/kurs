#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
const int NotUsed = system("color 1E");
using namespace std;

#define N 3

class Game {

	friend class �hain;     // ����������� ����� ������ � ���������� ���������

	char name[50];			//��������
	char genre[20];			//����
	int year;				//��� �������
	char platform[10];		//������� ��������� (��, Xbox, PS)
	char sys_req[100];			//��������� ����
	char developer[30];		//�����������
	int quantity;			//����������

public:
	///�����������
	Game() {
		name[0] = EOF;
		genre[0] = EOF;
		year = 0;
		platform[0] = EOF;
		sys_req[0] = EOF;
		developer[0] = EOF;
		quantity = 0;
	}

	///����������� � �����������
	Game(char* name1, char* genre1, int year1, char* platform1, char* sys_req1, char* developer1, int quantity1) {
		strcpy(name, name1);
		strcpy(name, name1);
		year = year1;
		strcpy(name, name1);
		strcpy(name, name1);
		strcpy(name, name1);
		quantity = quantity1;
	}

	///������
	void set_game(void)
	{
		cout << "������� �������� " << endl;
		cin >> name;
		cout << "������� ���� " << endl;
		cin >> genre;
		cout << "������� ��� ������� " << endl;
		cin >> year;
		cout << "������� ������� ��������� " << endl;
		cin >> platform;
		cout << "������� ��������� ���������� " << endl;
		cin >> sys_req;
		cout << "������� ������������ " << endl;
		cin >> developer;
		cout << "������� ���������� " << endl;
		cin >> quantity;
	}
	///��������
	void show_game(void)
	{
		cout << "�������� ����: " << name << "; ���� ����: " << genre << "; ��� ������� " << year << "; ������� ��������� " << platform << "; C�������� ���������� " << sys_req << endl;
		cout << "; ����������� " << developer << "; ���������� " << quantity << ";" << endl;
	}
};

class �hain {
protected:

	�hain * next;						// ����� ������ �����������, ������� ������� ����, ���� ��� �������� ��� ������� �������
	Game *game_list;					// ������ � ������
	int size_of_game_list;				// ������ ������� � ������
	virtual void result(Game* game) {}	// ��������� ��������� ����

public:

	�hain() {
		next = nullptr;
		game_list = nullptr;
		size_of_game_list = NULL;
	}

	///���� �� ���������� ������ ��� ���� � ���� ����, ��������� �� ���������
	�hain* setNext(�hain* �hain)
	{
		next = �hain;
		return next;
	}


	/// ���� �� ���������� ������ ��� ���� � ���� ����, ��������� �� ���������
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
				cout << "���� ����� �� ���� �������." << endl;
				return;
			}
		}

	}

	///�������� � ����
	void add_to_file(string file)
	{
		int add_value; //������� ��� ����� ��������
		read_from_file(file);

		cout << "������� ��� �� ������ �������� � ����? " << endl;
		cin >> add_value;
		size_of_game_list += add_value;

		write_to_file(file, add_value);
	}


	///������ � ����
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
				out.write(reinterpret_cast<char*>(&game_list[i]), sizeof(Game)); //�������������� ���������� gamelist
			}

			for (int i = 0; i < add_val; i++)
			{
				tmp.set_game();
				out.write(reinterpret_cast<char*>(&tmp), sizeof(Game)); //��������� ����� ������
			}
			out.close();
		}
		catch (const int &ex)
		{
			cout << "������ �������� �����!" << endl << "��� ������: #" << ex << endl;
		}

	}

	///������ �� �����
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
			cout << "������ ������ �����!" << endl << "��� ������: #" << ex << endl;
		}

	}


	virtual ~�hain()
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

class Site : public �hain {
protected:

	string filename;
	void result(Game* game)
	{
		cout << "����� ������ �� �����" << endl;
	}

public:

	Site() //�����������
	{
		filename = "Site.txt";
		cout << endl << "~~~~~~~~~ ���������� ����� ~~~~~~~~~" << endl << endl;
		read_from_file(filename); //���������� ������� � ������ � ������� ������
	}

	string get_filename() { return filename; }
};

class Shop : public �hain {
protected:
	string filename;
	void result(Game* game)
	{
		cout << "����� ������ � ��������" << endl;
	}

public:

	Shop() //�����������
	{
		filename = "Shop.txt";
		cout << endl << "~~~~~~~~~ ���������� �������� ~~~~~~~~~" << endl << endl;
		read_from_file(filename); //���������� ������� � ������ � ������� ������
	}

	string get_filename() { return filename; }
};

class Warehouse : public �hain {
protected:
	string filename;
	void result(Game* game)
	{
		cout << "����� ������ �� ������" << endl;
	}

public:

	Warehouse() //�����������
	{
		filename = "Warehouse.txt";
		cout << endl << "~~~~~~~~~ ���������� ������ ~~~~~~~~~" << endl << endl;
		read_from_file(filename); //���������� ������� � ������ � ������� ������
	}

	string get_filename() { return filename; }
};

int main()
{
	setlocale(LC_ALL, "Russian");

	�hain *chain;
	Game *game;
	Site *site;
	Shop *shop;
	Warehouse *warehouse;



	int swtch1 = 1;
	while (swtch1 != 0) {
		cout << endl << endl << "�������� ��������:" << endl <<
			"|1| <-> ������� ��� ������ �� ���� ����������" << endl <<
			"|2| <-> ���������� ��������� � ����" << endl <<
			"|3| <-> ����� ���� �� ����� -> �������� -> ������" << endl <<
			"|0| <-> �����" << endl;
		cin >> swtch1;
		switch (swtch1)
		{
		case 1: /*������� ��� ������ �� �����*/
			chain = new Site;
			chain = new Shop;
			chain = new Warehouse;
			delete chain;
			break;
		case 2:
			cout << "�������� ��������:" << endl <<
				"|1| <-> ���������� ��� �� ����" << endl <<
				"|2| <-> ���������� ��� � �������" << endl <<
				"|3| <-> ���������� ��� �� �����" << endl <<
				"|0| <-> ������" << endl;
			cin >> swtch1;
			switch (swtch1)
			{
			case 1: /*���������� ��� �� ����*/
				site = new Site;
				site->add_to_file(site->get_filename());
				delete site;
				break;
			case 2: /*���������� ��� � �������*/
				shop = new Shop;
				shop->add_to_file(shop->get_filename());
				delete shop;
				break;
			case 3: /*���������� ��� �� �����*/
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
			chain = new Site;  // ������ ������� � ���� ����->�������->�����
			chain->setNext(new Shop)->setNext(new Warehouse);

			cout << endl << "������� ������ �� ���� ��� ������ " << endl;
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