#include <iostream>
#include <fstream>
#include <string>
#include <vector>
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
	//vector<vector<int>>eqipment;
public:
	Player()
	{
		this->health = 100;
		this->exp = 0;
		this->dmg = 10;
		this->lvl = 1;
		this->hitChance = 50;
		this->defChance = 50;
		this->parChance = 15;
		//eqipment.assign(3, vector<int>(5));
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
		/*if (lvl > 1)
		{
			this->hitChance = hitChance + lvl * 2;
			this->defChance = defChance + lvl * 2;
			this->parChance = parChance + lvl * 2;
		}*/
		//eqipment.assign(3, vector<int>(5));
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
};


bool try_chance()
{
	if (rand() % 2 == 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

class Game
{
public:
	Game() {};

	void GamePr(Player player, Player bot)
	{
		int tmpPh = player.getHealth();
		int tmpBh = bot.getHealth();
		bool tmpBCh;
		bool tmpBCh2;
		bool res;
		while (tmpBh >= 0 || tmpPh >= 0)
		{
			system("cls");
			cout << "Duel starts!\n";
			cout << "'a' - attack, 'd' - defence\n";
			char act;
			cin >> act;
			if (act == 'a')
			{
				if (rand() % 2 == 1)
				{
					tmpBCh = true;
				}
				else
				{
					tmpBCh = false;
					if (def_chance(bot.getDefChance()) == true)
					{
						tmpBCh2 = true;
					}
					else
					{
						tmpBCh2 = false;
					}
				}
				if (hit_chance(player.getHitChance()) == true)
				{
					if(tmpBCh == true || (tmpBCh == false && tmpBCh2 != true))
					{
						cout << "you injured a bot!\n";
						tmpBh -= player.getDamage();
					}
					else if (tmpBCh == false && tmpBCh2 == true)
					{
						cout << "blocked by bot!\n";
						if (par_chance(bot.getParChance()) == true)
						{
							tmpPh -= bot.getDamage() * 2;
							cout << "sad! bot has parried and dealed x2 damage to you!\n";
						}
					}			
				}
				else
				{
					cout << "miss!\n";
					if (tmpBCh == false)
					{
						cout << "NO WAY! BOT HAS BLOCKED... nothing\n";
					}
				}
				if (tmpBCh == true) 
				{
					if (hit_chance(bot.getHitChance()) == true)
					{
						cout << "bot injured you!\n";
						tmpPh -= bot.getDamage();
					}
					else
					{
						cout << "bot missed!\n";
					}
				}
				cout << "Your health: " << tmpPh;
				cout << "\nBot's health: " << tmpBh;
				cout << endl;
				system("pause");
			}
			else if (act == 'd')
			{
				if (rand() % 2 == 1)
				{
					tmpBCh = true;
				}
				else
				{
					tmpBCh = false;
					if (def_chance(bot.getDefChance()) == true)
					{
						tmpBCh2 = true;
					}
					else
					{
						tmpBCh2 = false;
					}
				}
				if (def_chance(player.getDefChance()) == true)
				{
					if (tmpBCh == true)
					{
						cout << "you've blocked bot's attack!\n";
						if (par_chance(player.getParChance()) == true)
						{
							tmpBh -= player.getDamage()*2;
							cout << "WOW! you have parried and dealed x2 damage to bot!\n";
						}
						
					}
				}
				else if (def_chance(player.getDefChance()) == true && tmpBCh == false)
				{
					cout << "you just blocked enemy's block -_-\n";
				}
				else if(def_chance(player.getDefChance()) == false)
				{
					if (tmpBCh == true)
					{
						cout << "unfortunately, bot has broke through the defense!\n";
						tmpPh -= bot.getDamage();
						//tmpBh -= player.getDamage();
					}
				}
				else
				{
					cout << "double block\n";
				}
				cout << "Your health: " << tmpPh;
				cout << "\nBot's health: " << tmpBh;
				cout << endl;
				system("pause");
			}
			else
			{
				cout << "wrong symbol! try again!\n";
				system("pause");
			}
			if (tmpBh <= 0)
			{
				cout << "congrats! you won!\n";
				player.expCt(10);
				system("pause");
				return;
			}
			else if (tmpPh <= 0)
			{
				cout << "unlucky :( bot won!\n";
				player.expCt(-10);
				system("pause");
				return;
			}
			else if (tmpBh == 0 && tmpPh == 0)
			{
				cout << "tie!\n";
				player.expCt(5);
				system("pause");
				return;
			}
		}
	}
	bool hit_chance(int hitChance)
	{
		if (rand() % 101 <= hitChance)
			return false;
		else
			return true;
	}
	bool def_chance(int defChance)
	{
		if (rand() % 101 <= defChance)
			return false;
		else
			return true;
	}
	bool par_chance(int parChance)
	{
		if (rand() % 101 <= parChance)
			return false;
		else
			return true;
	}

};

void StartMenu()
{
	Player player, bot;
	cout << "Hello! Welcome to the game!\n";
	cout << "If you already have account write 'p'\n";
	cout << "If you never played write 'c'\n";
	char tp;
	cin >> tp;
	if (tp == 'p')
	{
		player.loadPr();
		cout << "loaded!\n";
		bot = player;
		system("pause");
	}
	else if (tp == 'c')
	{
		cout << "created!\n";
		system("pause");
	}
	else
	{
		cout << "wrong symbol!\n";
		return;
	}
	int x = 0;
	while (x <= 4)
	{
		system("cls");
		cout << "Start duel - '1'\n";
		cout << "Show stats - '2'\n";
		cout << "Save progress - '3'\n";
		cout << "Quit - '4'\n";
		cin >> x;
		if (x == 1)
		{
			Game game;
			game.GamePr(player, bot);
			x = 0;
		}
		else if (x == 2)
		{
			player.showStats();
			x = 0;
			system("pause");
		}
		else if (x == 3) 
		{
			player.savePr();
			cout << "saved!\n";
			x = 0;
			system("pause");
		}
		else if (x == 4)
		{
			return;
		}
		else
		{
			cout << "wrong symbol! try again!\n";
			x = 0;
			system("pause");
		}
	}
}

int main()
{
	srand(time(NULL));
	StartMenu();
	return 0;
}