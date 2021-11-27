#include "Game.h"
#include <Windows.h>

Game::Game()
{
	amount = 0;
	choice = 0;
	playing = true;
	activeCharacter = 0;
	fileName = "Characters.txt";
}

Game::~Game()
{

}

//Functions
void Game::initGame()
{
	std::ifstream characters;
	Weapon::initNames();
	Armor::initNames();

	characters.open(this->getFilename());

	if (characters.is_open())
		this->LoadChacter();
	else
	{
		this->CreateNewChacter();
		this->SaveChacter();
	}

	characters.close();
}

void Game::mainMenu()
{
	Event evn;

	while (this->playing) {
		system("cls");
		
		if (this->characters[this->activeCharacter].isAlive())
		{

			if (this->characters[this->activeCharacter].getExp() >= this->characters[this->activeCharacter].getExpNext())
			{
				std::cout << this->characters[this->activeCharacter].getLevel() + 1 << "랩으로 레벨 업 !! \n\n";
				this->characters[this->activeCharacter].levelUp();
			}


			std::cout << "──────메인 메뉴──────────" << std::endl;
			std::cout << "접속중인 캐릭터 = " << this->characters[this->activeCharacter].getName() << " ( " << this->activeCharacter + 1 << " / " << this->characters.size() << ") " << std::endl;
			std::cout << "0: 끝내기" << std::endl;
			std::cout << "1: 여행가기" << std::endl;
			std::cout << "2: 쇼핑하기" << std::endl;
			std::cout << "3: 쉬기" << std::endl;
			std::cout << "4: 캐릭터 설정" << std::endl;
			std::cout << "─────────────────────" << std::endl;

			std::cout << "선택 : ";
			std::cin >> choice;

			if (std::cin.fail())
			{
				std::cout << "잘못된 입력,.,." << std::endl;
				std::cin.clear();
				std::cin.ignore(100, '\n');
				Sleep(800);
				continue;
			}

			switch (choice)
			{
			case 0:
				playing = false;
				this->SaveChacter();
				break;

			case 1:
				Travel();
				break;

			case 3:
				evn.chacterRest(this->characters[this->activeCharacter]);
				break;

			case 4:
				system("cls");
				std::cout << "──────캐릭터 정보─────────────" << std::endl;
				std::cout << "1: 캐릭터 정보" << std::endl;
				std::cout << "2: 캐릭터 만들기" << std::endl;
				std::cout << "3: 캐릭터 저장하기" << std::endl;
				std::cout << "4: 캐릭터 불러오기" << std::endl;
				std::cout << "5: 캐릭터 선택하기" << std::endl;
				std::cout << "6: 포인트 레벨 업" << std::endl;
				std::cout << "7: 인벤토리" << std::endl;
				std::cout << "8: 뒤로 가기" << std::endl;
				std::cout << "────────────────────────" << std::endl;

				std::cout << "선택 : ";
				std::cin >> choice;

				while (std::cin.fail())
				{
					std::cout << "잘못된 입력입니다." << std::endl;
					std::cin.clear();
					std::cin.ignore(100, '\n');

					std::cout << "선택 : ";
					std::cin >> choice;
				}

				switch (choice)
				{
				case 1:
					characters[this->activeCharacter].GetChacterStatus();
					break;
				case 2:
					std::cin.ignore();
					this->CreateNewChacter();
					this->SaveChacter();
					break;
				case 3:
					std::cin.ignore();
					this->SaveChacter();
					std::cout << "캐릭터가 저장되었습니다!!" << std::endl;
					Sleep(700);
					break;
				case 4:
					std::cin.ignore();
					this->LoadChacter();
					break;

				case 5:
					selectCharacter();
					break;

				case 6:
					std::cin.ignore();
					this->levelupCharacter();
					break;

				case 7:
					system("cls");
					std::cout << "──────────인벤토리───────────" << std::endl;
					std::cout << "0: 인벤토리 보기" << std::endl;
					std::cout << "1: 장비 착용" << std::endl;
					std::cout << "─────────────────────────" << std::endl;

					std::cout << "선택 : ";
					std::cin >> this->choice;

					while (std::cin.fail() || this->choice < 0 || this->choice > 1)
					{
						std::cout << "잘못된 입력입니다." << std::endl;
						std::cin.clear();
						std::cin.ignore(100, '\n');

						std::cout << "선택 : ";
						std::cin >> this->choice;
					}

					switch (this->choice)
					{
					case 0:
						system("cls");
						std::cout << "──────────인벤토리───────────" << std::endl;
						std::cout << this->characters[this->activeCharacter].getInventoryAsString();
						std::cout << "─────────────────────────" << std::endl;
						system("pause");
						break;

					case 1:
						if (this->characters[this->activeCharacter].getInventorySize() <= 0)
						{
							std::cout << "장비가 존재하지 않습니다." << std::endl;
							system("pause");
						}
						else
						{
							system("cls");
							std::cout << "──────────인벤토리───────────" << std::endl;
							std::cout << this->characters[this->activeCharacter].getInventoryAsString();
							std::cout << "─────────────────────────" << std::endl;

							std::cout << "선택 : ";
							std::cin >> this->choice;

							while (std::cin.fail() || this->choice < 0 || this->choice > this->characters[this->activeCharacter].getInventorySize())
							{
								std::cout << "잘못된 입력입니다." << std::endl;
								std::cin.clear();
								std::cin.ignore(100, '\n');

								std::cout << "선택 : ";
								std::cin >> this->choice;
							}
							this->characters[this->activeCharacter].equipItem(this->choice);
							std::cin.ignore(100, '\n');
						}
						
						break;
					default:
						break;
					}
					break;
				default:
					break;
				}
				break;

			default:
				break;
			}
		}
		else
		{
			system("cls");
			std::cout << "당신은 죽었습니다. 로드하겠습니까? " << std::endl;
			std::cout << "0: yes, 1: no" << std::endl;

			std::cout << "선택 : ";
			std::cin >> choice;

			while (std::cin.fail() || this->choice < 0 || this->choice > 1)
			{
				std::cout << "잘못된 입력입니다." << std::endl;
				std::cin.clear();
				std::cin.ignore(100, '\n');

				std::cout << "당신은 죽었습니다. 로드하겠습니까? " << std::endl;
				std::cout << "0: yes, 1: no" << std::endl;
				std::cout << "선택 : ";
				std::cin >> choice;
			}
			std::cin.clear();
			std::cin.ignore(100, '\n');

			if (this->choice == 0)
				this->LoadChacter();
			else
				this->playing = false;
		}
	}
}

void Game::levelupCharacter()
{
	this->characters[this->activeCharacter].levelUp();

	if (this->characters[this->activeCharacter].getStatusPoints() > 0)
	{
		std::cout << "당신은 " << this->characters[this->activeCharacter].getStatusPoints() << " 만큼의 포인트를 가지고 있습니다" << std::endl;
		
		std::cout << "0: 힘" << std::endl;
		std::cout << "1: 활력" << std::endl;
		std::cout << "2: 손재주" << std::endl;
		std::cout << "3: 지능" << std::endl;
		
		std::cout << "어떤 스테이터스를 올리실 껀가요? : ";
		std::cin >> choice;
		std::cout << "얼마 만큼 올리실 건가요? : ";
		std::cin >> amount;

		while (std::cin.fail() || this->choice > 3 || this->characters[this->activeCharacter].getStatusPoints() < this->amount )
		{
			std::cout << "잘못된 입력,.,." << std::endl;
			std::cin.clear();
			std::cin.ignore(100, '\n');
			Sleep(800);

			std::cout << "어떤 스테이터스를 올리실 껀가요? : ";
			std::cin >> choice;
			std::cout << "얼마 만큼 올리실 건가요? : ";
			std::cin >> amount;
		}
		std::cin.ignore(100, '\n');
		std::cout << std::endl;

		switch (this->choice)
		{
		case 0:
			this->characters[this->activeCharacter].addStatus(0, this->amount);
			break;

		case 1:
			this->characters[this->activeCharacter].addStatus(1, this->amount);
			break;

		case 2:
			this->characters[this->activeCharacter].addStatus(2, this->amount);
			break;

		case 3:
			this->characters[this->activeCharacter].addStatus(3, this->amount);
			break;

		default:
			break;
		}
	}
	else
	{
		std::cout << "포인트가 존재하지 않습니다." << std::endl;
		system("pause");
	}
	this->characters[this->activeCharacter].updateStats();
}

void Game::CreateNewChacter()
{
	std::string name = "";

	std::cout << "캐릭터의 이름을 입력해 주세요 : ";
	std::getline(std::cin, name);

	for (size_t i = 0; i < this->characters.size(); i++)
	{
		while (name == this->characters[i].getName())
		{
			std::cout << "동일한 이름의 캐릭터가 존재합니다!!" << std::endl;

			std::cout << "캐릭터의 이름을 입력해 주세요 : ";
			std::getline(std::cin, name);
		}
	}

	this->characters.push_back(Character(name));

	this->activeCharacter = characters.size() - 1;
	this->characters[this->activeCharacter].initialize(name);
}

void Game::SaveChacter()
{
	std::ofstream outFile(fileName);

	if (outFile.is_open())
	{
		for (size_t i = 0; i < this->characters.size(); i++)
		{
			outFile << this->characters[i].getAsString() << "\n";
			outFile << this->characters[i].getInventoryAsStringSave() << "\n";
		}
	}
		
	outFile.close();
	std::cout << "저장을 완료했습니다. 아무키나 눌러주세요..." << std::endl;
	system("pause>nul");
}

void Game::LoadChacter()
{
	std::ifstream inFile(fileName);

	this->characters.clear();

	std::string name = "";
	int distanceTravelled = 0;
	int gold = 0;
	int level = 0;
	int exp = 0;
	int strength = 0;
	int vitality = 0;
	int dexterity = 0;
	int intelligence = 0;
	int statPoints = 0;

	int hp = 0;
	int mp = 0;
	int accuracy = 0;
	int luck = 0;

	std::string line = "";
	std::stringstream str;

	int itemType = 0;
	int defence = 0;
	int type = 0;
	int damgeMin = 0;
	int damgeMax = 0;

	int buyVlaue = 0;
	int sellVlue = 0;
	int rarity = 0;

	Inventory TempItem;
	
	if (inFile.is_open())
	{
		while (std::getline(inFile, line))
		{
			str.str(line);
			str >> name;
			str >> distanceTravelled;
			str >> gold;
			str >> level;
			str >> exp;
			str >> strength;
			str >> vitality;
			str >> dexterity;
			str >> intelligence;
			str >> hp;
			str >> mp;
			str >> statPoints;

			//Character
			Character temp(name, distanceTravelled, gold, level, exp, strength, vitality, dexterity, intelligence, hp, mp, statPoints);

			//Weapon
			str >> itemType >> name >> level >> rarity >> buyVlaue >> sellVlue >> damgeMin >> damgeMax;
			Weapon weapon(damgeMin, damgeMax, name, level, buyVlaue, sellVlue, rarity);
			temp.setWeapon(weapon);
			//Armor_head
			str >> itemType >> name >> level >> rarity >> buyVlaue >> sellVlue >> defence >> type;
			Armor armor_head(type, defence ,name, level, buyVlaue, sellVlue, rarity);
			temp.setArmorHead(armor_head);
			//Armor_body
			str >> itemType >> name >> level >> rarity >> buyVlaue >> sellVlue >> defence >> type;
			Armor armor_body(type, defence, name, level, buyVlaue, sellVlue, rarity);
			temp.setArmorBody(armor_body);
			//Armor_arms
			str >> itemType >> name >> level >> rarity >> buyVlaue >> sellVlue >> defence >> type;
			Armor armor_arms(type, defence, name, level, buyVlaue, sellVlue, rarity);
			temp.setArmorArms(armor_arms);
			//Armor_legs
			str >> itemType >> name >> level >> rarity >> buyVlaue >> sellVlue >> defence >> type;
			Armor armor_legs(type, defence, name, level, buyVlaue, sellVlue, rarity);
			temp.setArmorLegs(armor_legs);

			str.clear();
			line.clear();
			std::getline(inFile, line);

			str.str(line);

			while (str >> itemType >> name >> level >> rarity >> buyVlaue >> sellVlue >> damgeMin >> damgeMax)
			{
				temp.addItem(Weapon(damgeMin, damgeMax, name, level, buyVlaue, sellVlue, rarity));
			}

			str.clear();
			line.clear();
			std::getline(inFile, line);

			str.str(line);

			while (str >> itemType >> name >> level >> rarity >> buyVlaue >> sellVlue >> defence >> type)
			{
				temp.addItem(Armor(type, defence, name, level, buyVlaue, sellVlue, rarity));
			}

			str.clear();
			line.clear();

			this->characters.push_back(Character(temp));
			this->activeCharacter = characters.size() - 1;
			this->characters[this->activeCharacter].updateStats();

			std::cout << temp.getName() << " 불러오기 성공" << std::endl;
		}
	}
	inFile.close();

	if (this->characters.size() <= 0) {
		std::cout << "캐릭터가 존재하지 않습니다" << std::endl;
		this->CreateNewChacter();
	}
	system("pause");
}

void Game::selectCharacter()
{
	system("cls");
	std::cout << "──────캐릭터 선택─────────────" << std::endl;
	for (size_t i = 0; i < this->characters.size(); i++)
	{
		std::cout << i << ": " << this->characters[i].getName() << "(" << this->characters[i].getLevel() << ")" << std::endl;
	}
	std::cout << "────────────────────────" << std::endl;
	std::cout << "캐릭터를 선택해주세요 : ";
	std::cin >> choice;

	while (std::cin.fail() || this->choice < 0 || this->choice >= this->characters.size() )
	{
		std::cout << "잘못된 입력,.,." << std::endl;
		std::cin.clear();
		std::cin.ignore(100, '\n');

		std::cout << "캐릭터를 선택해주세요 : ";
		std::cin >> choice;
	}
	std::cin.ignore(100, '\n');

	this->activeCharacter = this->choice;
	std::cout << this->characters[this->activeCharacter].getName() << "가 선택되었습니다." << std::endl;
	this->characters[this->activeCharacter].updateStats();
}

void Game::Travel()
{
	Event event;
	this->characters[this->activeCharacter].travel();

	event.generateEvent(this->characters[this->activeCharacter], this->enemies);
}

void Game::characterMenu()
{

}

void Game::inventoryEquip()
{

}
