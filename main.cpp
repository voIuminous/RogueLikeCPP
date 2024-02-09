/*
 Omer BAHADIR
 - This is very old code
 - some very inefficient methods of calculation were used
*/ 

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

// initialize the functions
void updMap();
void drawMap();

// character
struct character {
	std::string name;
	int damage;
	int exp;
	int lvl;
	int health;
	int coins;
	bool characterDead;
} player; // initialize instantly

// enemy
struct enemy {
	std::string name;
	int damage;
	int health;
	int expDrpd; // exp dropped
	int coinsDrpd;
	bool bossDead;
} enemO, enemT, enemF; // enemy one, enemy two, enemy three

bool oneHundUsed = false;

const std::string character = "O";
const std::string enemyO = "!";
const std::string enemyT = "$";
const std::string enemyF = "&";
const std::string unknownS = "?";
const std::string unknownST = "?";

// character decisions
char abc;
char mov;

int maximum_number = 1;
int minimum_number = -1;

// starting positions
unsigned int charX = 4;
unsigned int charY = 5;

unsigned int enemyOX = 20;
unsigned int enemyOY = 10;

unsigned int enemyTX = 23;
unsigned int enemyTY = 11;

unsigned int enemyFX = 13;
unsigned int enemyFY = 17;

unsigned int unknownSX = 14;
unsigned int unknownSY = 18;

unsigned int unknownSTX = 300;
unsigned int unknownSTY = 300;

// damage and health changes as the person levels up (p stands for player)
unsigned int pDamage;
unsigned int pHealth;

bool foundStaff = false;

int oneHund = rand() % 101;

bool staffEqpd = false;
bool swordEqpd = false;

std::string inventory[5] = {" ", " ", " ", " ", " "};

std::string shop[5] = {"Armor", " ", " ", " ", " "};

std::string map[20][29] = {
	{" ", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", " ", "\n"},	
	{"#", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", "#", "\n"},
	{"#", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", "#", "\n"},
	{"#", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", "#", "\n"},
	{"#", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", "#", "\n"},
	{"#", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", "#", "\n"},
	{"#", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", "#", "\n"},
	{"#", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", "#", "\n"},
	{"#", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", "#", "\n"},
	{"#", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", "#", "\n"},
	{"#", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", "#", "\n"},
	{"#", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", "#", "\n"},
	{"#", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", "#", "\n"},
	{"#", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", "#", "\n"},
	{"#", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", "#", "\n"},
	{"#", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", "#", "\n"},
	{"#", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", "#", "\n"},
	{"#", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", "#", "\n"},
	{"#", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", "#", "\n"},
	{" ", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", " ", "\n"}
};

int main() {
	srand(time(NULL));

	pDamage = rand() % 1000 + 500;
	pHealth = 3000;

	enemO.bossDead = false;
	enemT.bossDead = false;
	enemF.bossDead = false;

	enemO.name = "Booss";
	enemT.name = "Igris";
	enemF.name = "Wamuu";

	enemO.health = 3000;
	enemT.health = 6000;
	enemF.health = 9000;

	enemO.damage = (rand() % 100) + 50;
	enemT.damage = (rand() % 500) + 100;
	enemF.damage = (rand() % 1000) + 500;

	enemO.expDrpd = (rand() % 1000) + 500;
	enemT.expDrpd = (rand() % 5000) + 1000;
	enemF.expDrpd = (rand() % 10000) + 5000;

	std::cout << "What is your name? > ";
	std::cin >> player.name;

	player.damage = pDamage;
	player.lvl = 1;
	player.exp = 0;
	player.health = pHealth;
	player.coins = 0;

	map[charY][charX] = character;
	map[enemyOY][enemyOX] = enemyO;
	map[enemyTY][enemyTX] = enemyT;
	map[enemyFY][enemyFX] = enemyF;
	map[unknownSY][unknownSX] = unknownS;

	drawMap();

	while (1 + 5 == 6)
		updMap();
	
	return 0;
}

void drawMap() {
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 29; j++) {
			std::cout << map[i][j];
		}
	}
}

void updMap() {
	srand(time(NULL));
	std::cout << "> ";
	std::cin >> mov;

	if (mov == '4') {
		std::cout << "The point of the game is to fight all three bosses. But you better be prepared before that!" 
		<< "\nIf you type 1 in the console, you check your own stats!\nIf you type 2 in the console you check your inventory!"
		<< "\nIf you type 3 You check the shop!\nIf you type 4 you get this page!\nuse WASD to move around" << std::endl;
	}

	if (mov == '3') {
		for (int i = 0; i < 5; i++) {
			std::cout << shop[i] << ", ";
		}
		std::cout << std::endl;

		std::cout << "\nPlease select an item to buy." << std::endl;
		std::cout << "> ";
		std::cin >> mov;

		if (mov == '1') {
			if (player.coins >= 100) {
				inventory[2] = "Armor";
				shop[0] = " ";

				std::cout << "You now have armor! Check your inventory" << std::endl;
			} else if (player.coins <= 100) {
				std::cout << "You sadly do not have enough money." << std::endl;
			}
		}
	}

	if (mov == '2') {
		for (int i = 0; i < 5; i++) {
			std::cout << inventory[i] << ", ";
		}
		std::cout << std::endl;
	}

	if (mov == '1') {
		std::cout << "Coins:  " << player.coins  << std::endl;
		std::cout << "Health: " << player.health << std::endl;
		std::cout << "Level:  " << player.lvl    << std::endl;
		std::cout << "EXP:    " << player.exp    << std::endl;
	}

	if (enemO.bossDead == true) {
		map[enemyOY][enemyOX] = " ";
	}
	if (enemT.bossDead == true) {	
		map[enemyTY][enemyTX] = " ";
	}
	if (enemF.bossDead == true) {
		map[enemyFY][enemyFX] = " ";
	}

	if (map[enemyOY - 1][enemyOX - 1] == "#" || map[enemyOY + 1][enemyOX + 1] == "#" || map[enemyOY - 1][enemyOX + 1] == "#" || map[enemyOY + 1][enemyOX - 1] == "#" || map[enemyOY - 1][enemyOX] == "#" || map[enemyOY + 1][enemyOX] == "#" || map[enemyOY][enemyOX - 1] == "#" || map[enemyOY][enemyOX + 1] == "#") {
		if (enemO.bossDead == false) {
			map[enemyOY][enemyOX] = " ";
			enemyOX = 20;
			enemyOY = 10;
			map[enemyOY][enemyOX] = enemyO;
		}
	} else {
		if (enemO.bossDead == false) {
			map[enemyOY][enemyOX] = " ";
			enemyOY = enemyOY + (rand() % (maximum_number + 1 - minimum_number)) + minimum_number;
			enemyOX = enemyOX + (rand() % (maximum_number + 1 - minimum_number)) + minimum_number;
			map[enemyOY][enemyOX] = enemyO;
		}
	}

	if (map[enemyTY - 1][enemyTX - 1] == "#" || map[enemyTY + 1][enemyTX + 1] == "#" || map[enemyTY - 1][enemyTX + 1] == "#" || map[enemyTY + 1][enemyTX - 1] == "#" || map[enemyTY - 1][enemyTX] == "#" || map[enemyTY + 1][enemyTX] == "#" || map[enemyTY][enemyTX - 1] == "#" || map[enemyTY][enemyTX + 1] == "#") {
		if (enemT.bossDead == false) {
			map[enemyTY][enemyTX] = " ";
			enemyTX = 23;
			enemyTY = 11;
			map[enemyTY][enemyTX] = enemyT;
		}
	} else {
		if (enemT.bossDead == false) {
			map[enemyTY][enemyTX] = " ";
			enemyTY = enemyTY + (rand() % (maximum_number + 1 - minimum_number)) + minimum_number;
			enemyTX = enemyTX + (rand() % (maximum_number + 1 - minimum_number)) + minimum_number;
			map[enemyTY][enemyTX] = enemyT;
		}
	}
	if (map[enemyFY - 1][enemyFX - 1] == "#" || map[enemyFY + 1][enemyFX + 1] == "#" || map[enemyFY - 1][enemyFX + 1] == "#" || map[enemyFY + 1][enemyFX - 1] == "#" || map[enemyFY - 1][enemyFX] == "#" || map[enemyFY + 1][enemyFX] == "#" || map[enemyFY][enemyFX - 1] == "#" || map[enemyFY][enemyFX + 1] == "#") {
		if (enemF.bossDead == false) {
			map[enemyFY][enemyFX] = " ";
			enemyFX = 13;
			enemyFY = 17;
			map[enemyFY][enemyFX] = enemyF;
		}
	} else {
		if (enemF.bossDead == false) {
			map[enemyFY][enemyFX] = " ";
			enemyFY = enemyFY + (rand() % (maximum_number + 1 - minimum_number)) + minimum_number;
			enemyFX = enemyFX + (rand() % (maximum_number + 1 - minimum_number)) + minimum_number;
			map[enemyFY][enemyFX] = enemyF;
		}
	}

	if (map[charY][charX] == map[enemyOY][enemyOX] && enemO.bossDead == false) {
		std::cout << "You have encountered: " << enemO.name << std::endl;

		while (enemO.bossDead == false) {
			std::cout << "\n" << std::endl;
			std::cout << "(Type a, b, or c) Will you:\n a. Fight\n b. Check Stats of the Enemy\n c. Retreat" << std::endl;
			std::cout << "> ";
			std::cin >> abc;

			if (abc == 'a') {
				enemO.damage = (rand() % 1000) + 500;
				enemO.expDrpd = (rand() % 10000) + 5000;
				enemO.coinsDrpd = (rand() % 100) + 50;

				if (swordEqpd == false && staffEqpd == false) {
					player.damage = pDamage;
				} else if (swordEqpd == true) {
					player.damage = pDamage + (rand() % 750 + 500);
				} else if (staffEqpd == true) {
					player.damage = pDamage + (rand() % 1500 + 750);
				}

				int damage = player.damage;

				std::cout << "\n" << std::endl;

				enemO.health -= damage;
				std::cout << "You have dealt " << damage << " damage" << std::endl;
				std::cout << "The enemy now has " << enemO.health << " health left." << std::endl;

				std::cout << "\n";

				player.health -= enemO.damage;
				std::cout << "They dealt " << enemO.damage << " amount of damage." << std::endl;
				std::cout << "You now have " << player.health << " amount of health yes" << std::endl;

				if (enemO.health <= 0) {
					enemO.bossDead = true;
					std::cout << "\nYou have killed the boss." << std::endl;

					player.exp += enemO.expDrpd;
					player.lvl += 1;

					std::cout << "Congratulations! You won " << enemO.expDrpd << " exp and are now level " << player.lvl << std::endl;
					std::cout << "You also won " << enemO.coinsDrpd << " coins." << std::endl;

					player.coins += enemO.coinsDrpd;

					map[charY][charX] = " ";
					charX = 4;
					charY = 5;
					map[charY][charX] = character;
				}

				if (player.health <= 0) {
					std::cout << "You have died. Game over." << std::endl;
					exit(EXIT_FAILURE);
				}
			}
			if (abc == 'b') {
				std::cout << "Health: " << enemO.health << std::endl;
				std::cout << "Damage: " << enemO.damage << std::endl;
			}
			if (abc == 'c') {
				std::cout << "\n" << std::endl;
				std::cout << "Not an option buddy." << std::endl;
			}


			if (player.lvl == 2) {
				pDamage = rand() % 2000 + 1000;
				player.damage = pDamage;
				pHealth = 6000;
				player.health = pHealth;
			} else if (player.lvl == 3) {
				pDamage = rand() % 3000 + 2000;
				player.damage = pDamage;
				pHealth = 9000;
				player.health = pHealth;
			} else if (player.lvl == 4) {
				pDamage = rand() % 4000 + 3000;
				player.damage = pDamage;
				pHealth = 12000;
				player.health = pHealth;
			}
		}
	}

	if (map[charY][charX] == map[enemyTY][enemyTX] && enemT.bossDead == false) {
		std::cout << "You have encountered: " << enemT.name << std::endl;

		while (enemT.bossDead == false) {
			std::cout << "\n" << std::endl;
			std::cout << "(Type a, b, or c) Will you:\n a. Fight\n b. Check Stats of the Enemy\n c. Retreat" << std::endl;
			std::cout << "> ";
			std::cin >> abc;

			if (abc == 'a') {
				enemT.damage = (rand() % 1000) + 500;
				enemT.expDrpd = (rand() % 10000) + 5000;
				enemO.coinsDrpd = (rand() % 100) + 50;

				if (swordEqpd == false && staffEqpd == false) {
					player.damage = pDamage;
				} else if (swordEqpd == true) {
					player.damage = pDamage + (rand() % 750 + 500);
				} else if (staffEqpd == true) {
					player.damage = pDamage + (rand() % 1500 + 750);
				}

				int damage = player.damage;

				std::cout << "\n" << std::endl;

				enemT.health -= damage;
				std::cout << "You have dealt " << damage << " damage" << std::endl;
				std::cout << "The enemy now has " << enemT.health << " health left." << std::endl;

				std::cout << "\n";

				player.health -= enemT.damage;
				std::cout << "They dealt " << enemT.damage << " amount of damage." << std::endl;
				std::cout << "You now have " << player.health << " amount of health" << std::endl;

				if (enemT.health <= 0) {
					enemT.bossDead = true;
					std::cout << "\nYou have killed the boss." << std::endl;

					player.exp += enemT.expDrpd;
					player.lvl += 1;

					std::cout << "Congratulations! You won " << enemT.expDrpd << " exp and are now level " << player.lvl << std::endl;
					std::cout << "You also won " << enemT.coinsDrpd << " coins." << std::endl;

					player.coins += enemT.coinsDrpd;

					map[charY][charX] = " ";
					charX = 4;
					charY = 5;
					map[charY][charX] = character;
				}

				if (player.health <= 0) {
					std::cout << "You have died. Game over." << std::endl;
					exit(EXIT_FAILURE);
				}
			}
			if (abc == 'b') {
				std::cout << "Health: " << enemT.health << std::endl;
				std::cout << "Damage: " << enemT.damage << std::endl;
			}
			if (abc == 'c') {
				std::cout << "\n" << std::endl;
				std::cout << "Not an option buddy." << std::endl;
			}

			if (player.lvl == 2) {
				pDamage = rand() % 2000 + 1000;
				player.damage = pDamage;
				pHealth = 6000;
				player.health = pHealth;
			} else if (player.lvl == 3) {
				pDamage = rand() % 3000 + 2000;
				player.damage = pDamage;
				pHealth = 9000;
				player.health = pHealth;
			} else if (player.lvl == 4) {
				pDamage = rand() % 4000 + 3000;
				player.damage = pDamage;
				pHealth = 12000;
				player.health = pHealth;
			}
		}
	}

	if (map[charY][charX] == map[enemyFY][enemyFX] && enemF.bossDead == false) {	
		std::cout << "You have encountered: " << enemF.name << std::endl;

		while (enemF.bossDead == false) {
			std::cout << "\n" << std::endl;
			std::cout << "(Type a, b, or c) Will you:\n a. Fight\n b. Check Stats of the Enemy\n c. Retreat" << std::endl;
			std::cout << "> ";
			std::cin >> abc;

			if (abc == 'a') {
				enemF.damage = (rand() % 1000) + 500;
				enemF.expDrpd = (rand() % 10000) + 5000;
				enemO.coinsDrpd = (rand() % 100) + 50;

				if (swordEqpd == false && staffEqpd == false) {
					player.damage = pDamage;
				} else if (swordEqpd == true) {
					player.damage = pDamage + (rand() % 750 + 500);
				} else if (staffEqpd == true) {
					player.damage = pDamage + (rand() % 1500 + 750);
				}

				int damage = player.damage;

				std::cout << "\n" << std::endl;

				enemF.health -= damage;
				std::cout << "You have dealt " << damage << " damage" << std::endl;
				std::cout << "The enemy now has " << enemF.health << " health left." << std::endl;

				std::cout << "\n";

				player.health -= enemF.damage;
				std::cout << "They dealt " << enemF.damage << " amount of damage." << std::endl;
				std::cout << "You now have " << player.health << " amount of health left" << std::endl;

				if (enemF.health <= 0) {
					enemF.bossDead = true;
					std::cout << "\nYou have killed the boss." << std::endl;

					player.exp += enemF.expDrpd;
					player.lvl += 1;

					std::cout << "Congratulations! You won " << enemF.expDrpd << " exp and are now level " << player.lvl << std::endl;
					std::cout << "You also won " << enemF.coinsDrpd << " coins." << std::endl;

					player.coins += enemF.coinsDrpd;

					if (player.lvl == 2) {
						pDamage = rand() % 2000 + 1000;
						pHealth = 6000;
					} else if (player.lvl == 3) {
						pDamage = rand() % 3000 + 2000;
						pHealth = 9000;
					}

					map[charY][charX] = " ";
					charX = 4;
					charY = 5;
					map[charY][charX] = character;
				}

				if (player.health <= 0) {
					std::cout << "You have died. Game over." << std::endl;
					exit(EXIT_FAILURE);
				}
			}
			if (abc == 'b') {
				std::cout << "Health: " << enemF.health << std::endl;
				std::cout << "Damage: " << enemF.damage << std::endl;
			}
			if (abc == 'c') {
				std::cout << "\n" << std::endl;
				std::cout << "Not an option buddy." << std::endl;
			}

			if (player.lvl == 2) {
				pDamage = rand() % 2000 + 1000;
				player.damage = pDamage;
				pHealth = 6000;
				player.health = pHealth;
			} else if (player.lvl == 3) {
				pDamage = rand() % 3000 + 2000;
				player.damage = pDamage;
				pHealth = 9000;
				player.health = pHealth;
			} else if (player.lvl == 4) {
				pDamage = rand() % 4000 + 3000;
				player.damage = pDamage;
				pHealth = 12000;
				player.health = pHealth;
			}
		}
	}

	oneHund = rand() % 101;

	if (map[charY][charX] == map[unknownSY][unknownSX]) {
		std::cout << "Found an sword!" << std::endl;	
		unknownSY = 0;
		unknownSX = 0;
		map[unknownSY][unknownSX] = " ";
		inventory[0] = "Sword";
		swordEqpd = true;
		staffEqpd = false;
	}

	if (oneHund == 1 && oneHundUsed == false) {
		unknownSTX = 12;
		unknownSTY = 13;
		map[unknownSTY][unknownSTX] = unknownST;
		foundStaff = true;
		oneHundUsed = true;
	}

	if (foundStaff == true) {
		if (map[charY][charX] == map[unknownSTY][unknownSTX]) { 
			std::cout << "You have gotten a staff!" << std::endl;
			unknownSTY = 0;
			unknownSTX = 0;
			map[unknownSTY][unknownSTX] = " ";
			inventory[1] = "Staff";
			staffEqpd = true;
			swordEqpd = false;
		}
	}

	if (inventory[0] == "Sword" && inventory[1] == "Staff") {
		if ((staffEqpd == false && swordEqpd == true) || (staffEqpd == true && swordEqpd == false)) {
			char resultOf;

			std::cout << "You have two items in your inventory, which one would you like to equip?\n1. Sword\n2. Staff\n> ";
			std::cin >> resultOf;

			if (resultOf == '1') {
				swordEqpd = true;
				staffEqpd = false;

				inventory[1] = " ";
			} else if (resultOf == '2') {
				staffEqpd = true;
				swordEqpd = false;

				inventory[0] = " ";
			}

			std::cout << std::endl;
		}
	}

	switch(mov) {
		case 'w':
			std::cout << "\n\n" << std::endl;
			map[charY][charX] = " ";
			charY--;
			map[charY][charX] = character; 

			drawMap();

			break;
	
		case 'a':
			std::cout << "\n\n" << std::endl;
			map[charY][charX] = " ";
			charX--;
			map[charY][charX] = character; 

			drawMap();

			break;

		case 's':
			std::cout << "\n\n" << std::endl;
			map[charY][charX] = " ";
			charY++;
			map[charY][charX] = character; 

			drawMap();

			break;

		case 'd':
			std::cout << "\n\n" << std::endl;
			map[charY][charX] = " ";
			charX++;
			map[charY][charX] = character; 

			drawMap();

			break;
	}
}
