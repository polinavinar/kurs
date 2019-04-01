#include "Header.h"
#include "Game.h"
#include "Chain.h"
#include "Site.h"
#include "Shop.h"
#include "Warehose.h"

const int NotUsed = system("color 1E");
using namespace std;

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