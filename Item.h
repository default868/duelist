#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include "Player.h"
using namespace std;

//501 - Наголенники берсерка
//502 - Поножи палача
//503 - Желет кузнеца
//504 - Шлем рыцаря
//505 - Меч Пантеона
//506 - Щит гладиатора

class Item
{
private:
	string name;
	int id = 0;
	int health = 0;
	int exp = 0;
	int lvl = 0;
	int dmg = 0;
	int hitChance = 0;
	int defChance = 0;
	int parChance = 0;
public:
	Item() {}
	Item(int id)
	{
		if (id == 501)
		{
			this->id = id;
			this->name = "Наголенники берсерка";
			this->parChance = 5;
			this->defChance = 10;
		}
		if (id == 502)
		{
			this->id = id;
			this->name = "Поножи палача";
			this->parChance = -5;
			this->defChance = 5;
		}
		if (id == 503)
		{
			this->id = id;
			this->name = "Желет кузнеца";
			this->defChance = 10;
			this->parChance = -5;
			this->health = 50;
		}
		if (id == 504)
		{
			this->id = id;
			this->name = "Шлем рыцаря";
			this->defChance = 5;
			this->health = 25;
		}
		if (id == 505)
		{
			this->id = id;
			this->name = "Меч Пантеона";
			this->hitChance = 20;
			this->dmg = 10;
		}
		if (id == 506)
		{
			this->id = id;
			this->name = "Щит гладиатора";
			this->defChance = 35;
			this->parChance = -10;
		}
	}

	void printItem(int id)
	{
		if (id == 501)
		{
			cout << "Наголенники берсерка" << endl;
		}
		if (id == 502)
		{
			cout << "Поножи палача" << endl;
		}
		if (id == 503)
		{
			cout << "Желет кузнеца" << endl;
		}
		if (id == 504)
		{
			cout << "Шлем рыцаря" << endl;
		}
		if (id == 505)
		{
			cout << "Меч Пантеона" << endl;
		}
		if (id == 506)
		{
			cout << "Щит гладиатора" << endl;
		}
	}

	int getId()
	{
		return id;
	}
	/*int operator=(string str)
	{

	}*/

	void loadInv(Player player)
	{
		ifstream inventory("items.txt");
		for (int i = 0; i <= 6; i++)
		{
			int tempID;
			inventory >> tempID;
			Item item(tempID);
			if (tempID > 500 && tempID < 507)
				player.inv[i] = item;
		}
	}
	void saveInv(Player player)
	{
		ofstream inventory("items.txt");
		for (int i = 0; i <= 6; i++)
			inventory << player.inv[i].id << endl;
	}

	~Item() {}
};