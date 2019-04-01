#pragma once
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
	Game();
	///конструктор с параметрами
	Game(char* name1, char* genre1, int year1, char* platform1, char* sys_req1, char* developer1, int quantity1);
	///Сеттер
	void set_game(void);
	///просмотр
	void show_game(void);
};

