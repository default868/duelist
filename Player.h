#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include "Item.h"
using namespace std; 

class Player
{
private:
	int health;
	int exp;
	int lvl;
	int dmg;
	int hitChance;
	int defChance;
	int parChance;
public:
	vector<Item>inv;
	Player()
	{
		this->health = 100;
		this->exp = 0;
		this->dmg = 10;
		this->lvl = 1;
		this->hitChance = 50;
		this->defChance = 50;
		this->parChance = 15;
	}

	Player(int health, int exp, int dmg, int lvl, int hitChance, int defChance, int parChance)
	{
		this->health = health;
		this->exp = health;
		this->dmg = dmg;
		this->lvl = lvl;
		this->hitChance = hitChance;
		this->defChance = defChance;
		this->parChance = parChance;
	}
	int getHealth()
	{
		return health;
	}
	int getHitChance()
	{
		return hitChance;
	}

	int getDefChance()
	{
		return defChance;
	}

	int getParChance()
	{
		return parChance;
	}

	int getDamage()
	{
		return dmg;
	}

	void showInv()
	{
		for (int i = 0; i <= 6; i++)
		{
			inv[i].printItem(inv[i].getId());
		}

	}

	void showStats()
	{
		cout << "Health: " << this->health;
		cout << "\nExperience: " << this->exp;
		cout << "\nDamage: " << this->dmg;
		cout << "\nLevel: " << this->lvl;
		cout << "\nHit Chance: " << this->hitChance;
		cout << "\nDefence Chance: " << this->defChance;
		cout << "\nParry Chance: " << this->parChance;
		cout << endl;
	}

	void loadPr()
	{
		ifstream profile("profile.txt");
		profile >> this->health;
		profile >> this->exp;
		profile >> this->dmg;
		profile >> this->lvl;
		profile >> this->hitChance;
		profile >> this->defChance;
		profile >> this->parChance;
	}
	void savePr()
	{
		ofstream profile("profile.txt");
		profile << this->health << endl;
		profile << this->exp << endl;
		profile << this->dmg << endl;
		profile << this->lvl << endl;
		profile << this->hitChance << endl;
		profile << this->defChance << endl;
		profile << this->parChance << endl;
	}

	void expCt(int exp)
	{
		this->exp += exp;
		if (this->exp >= 100 && this->exp <= 199)
		{
			this->lvl++;
			this->exp -= 100;
			upgSp();
			expCt(exp);
		}
		else
		{
			return;
		}
	}

	void upgSp()
	{
		cout << "you have reached new level!\n";
		cout << "choose one from stats to upgrade!\n";
		cout << "Hit Chance - 1\n Defence Chance - 2\n Parry Chance - 3\n";
		int x;
		cin >> x;
		if (x == 1)
			this->hitChance += 2;
		if (x == 2)
			this->defChance += 2;
		if (x == 3)
			this->parChance += 2;
		else
			cout << "wrong symbol!\n";
	}
	~Player() {}
};