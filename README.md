
Text RPG
=============

+ [1일차](#10-31)
+ [2일차](#11-02)
+ [3일차](#11-15)
+ [4일차](#11-18)
+ [5일차](#11-21)

10-31
-------------

### Main menu
<img src="./images/mainMenu.png">

### Status print
<img src="./images/Status.png">

+ 캐릭터 저장 character.txt파일 안에 정보 저장됨
+ 무기 및 갑옷 class 완성 Inventory class 생성후 .addItem()으로 생성 가능

### example


```c++
Inventory inven;
inven.addItem(Weapon(0, 0, "Nomal Weapon", 0, 0, 0, 0));
inven.addItem(Weapon(0, 0, "Nomal Weapon2", 0, 0));
inven.addItem(Weapon(0, 0, "Nomal Weapon3"));
inven.addItem(Armor(0, 0, "Nomal Armor_had", 0, 0, 0));
inven.addItem(Armor(0, 0, "Nomal Armor_arms", 0, 0));
inven.addItem(Armor(0, 0, "Nomal Armor_body", 0));
inven.addItem(Armor(0, 0, "Nomal Armor_legs"));

for (size_t i = 0; i < inven.size(); i++)
{
	cout << inven[i].item_debugPrint() << endl;
}
```
<img src="./images/itemAdd_example.png">

11-02
--------------
##### using namespace std; 삭제...

### Event 생성
#### Puzzle 생성

+ 경험치 알고리즘 : 레벨과 행운에 따라서 경험치가 올라간다.

```c++
iint gainExp = (rand() % (chances * character.getLevel() * character.getLuck())) + 5;
```
<img src="./images/puzzle.png">
<img src="./images/puzzle_exp.png">

+ 퀴즈 세팅 파일은 같은 디렉토리 안 puzzle안에 존재한다.

<img src="./images/puzzle_level.png">

+ 필요 경험치가 넘었을 경우 자동으로 다음 레벨로 넘어간다.

```c++
void Character::initialize(const std::string name)
{
	this->distanceTravelled = 0;

	this->name = name;
	this->level = 1;
	this->exp = 0;
	this->expNext = static_cast<int>((50 / 3) * ((pow(level, 3) - 6 * pow(level, 2) + 17 * level) - 12) + 100); //레벨 필요치 알고리즘
	
	this->gold = 1000;

	this->strength = 5;
	this->vitality = 5;
	this->dexterity = 5;
	this->intelligence = 5;
	
	this->hpMax = (this->vitality * 2) + (this->strength/2);
	this->hp = this->hpMax;
	this->mpMax = this->vitality + (this->strength / 2) + (this->dexterity/3);
	this->mp = this->mpMax;
	this->damageMin = this->strength;
	this->damageMax = this->strength + 2;
	this->defence = this->dexterity + (this->intelligence/2);
	this->accuracy = (this->dexterity / 2);
	this->luck = this->intelligence;

	this->statPoints = 0;
	this->skillPoints = 0;
}
```

+ 캐릭터 init 설정
+ 잘못된 입력 예외 처리
+ 캐릭터 저장 및 로드 기능 추가 (추가 : 로드 시 맨 처음 있는 캐릭터만 불러와짐 선택할 수 있도록 바꿔야할거 같음)

11-15
-------------
--간격이 너무 길어서 코드를 까먹어ㅠ--
### 계정쪽으로 많은것들이 바뀌였습니다.

+ 이제 시작할때 캐릭터를 불러올 수 있습니다. 원하는 캐릭터 선택은 "캐릭터 선택하기"에 들어가서 선택하실 수 있습니다.
+ loading 기능을 완성 시켰습니다. 불러오기로 모든 캐릭터들을 vector에 넣어준 후 select하여 로그인합니다.
+ statPoint와 skillPoint를 정보창에서 보여주고 레벨업 칸에서 statPoints를 사용하여 기본 4가지의 힘중에 하나를 골라 올릴 수 있습니다.
+ dArray라는 자료구조 완성 : 적들(enemies)를 담기 위해 만들었다.

```c++
dArrary<int> ints;
for (size_t i = 0; i < 5; i++)
{
	ints.push(i*3);
	std::cout << ints[i] << std::endl;
}
```
<img src="./images/login.png">
<img src="./images/select_character.png">

+ 캐릭터이름(레벨) 로 확인할 수 있으며 옆 숫자는 index입니다.
+ ※주의) 불러오기를 하지 않은체 새로 계정을 만든 후 로그인을 하면 기존에 있는 것들은 싹다 사라집니다.

이유)

```c++
void Game::SaveChacter()
{
	std::ofstream outFile(fileName);

	if (outFile.is_open())
		for (const auto& character : characters)
			outFile << character.getAsString() << "\n";

	outFile.close();
}
```
+ 캐릭터 저장 코드입니다. characters라는 vector를 안을 돌면서 저장을 하기 때문에 불러오기를 하지 않으면 덮어쓰기를 해버립니다.


11-18
-------------
### 드디어 적과의 싸움
+ +버그 수정 : 힘스탯이 0으로 불어와지는 현상, mp가 0으로 불러와지는 현상, 레벨업을 해도 기본스택이외는 안올라가는 현상


+ 여행을 나가면 랜덤한 확률로 적과 만나게 됩니다. 탈출하기, 공격하기, 방어하기, 아이템 사용하기를 고를 수 있습니다.
+ 저번에 만들었던 자료구조안에 적들이 push를 하게 되므로 탈출하게 되면 다음에 만날땐 저번에 못 죽인 적들도 같이 있습니다.
+ 적들의 체력과 주는 exp량은 플레이어의 레벨과 비례합니다.

<img src="./images/battle.png">

<img src="./images/enemy_kill.png">


11-21
-------------
### 이제 적들이 당신을 공격합니다!!!

```c++
if (combatRollPlayer < combatRollEnemy)
{
	std::cout << "Hit!!" << std::endl;
	damge = enemy[i].getDamge();
	character.takeDamges(damge);

	std::cout << damge << "만큼의 데미지를 입었습니다..." << std::endl;
	std::cout << "현재 HP : " << character.getHp() << " / " << character.getHpMax() << std::endl;

	if (!character.isAlive())
	{
		std::cout << "당신은 죽었습니다!!" << std::endl;
		playerDefeated = true;
	}
	system("pause");
}
else
{
	std::cout << "빗나갔습니다..." << std::endl;
	system("pause");
}
```

+ 위의 코드로 플레이어의 속도와 적 속도를 비교하여 어느것이 더 큰지에 따라서 공격을 먼저 시작한다.
+ 위의 코드는 적이 공격하는 코드이다 enemy안에 들어있는 모든 적들이 돌아가며 플레이어를 공격한다.

<img src="./images/enemy_Roll.png">

+ 적의 속도 공식

<img src="./images/character_Roll.png">

+ 캐릭터의 속도 공식

<img src="./images/battle.png">

+ 배틀창

<img src="./images/attacked.png">

+ 공격 당했을때

<img src="./images/enemy_kill.png">

+ 적을 죽였을때

<img src="./images/dead.png">

+ 캐릭터가 죽었을때, 로드를 하면 가장 최근 저장했던 파일을 읽어와 그때부터 다시 시작할 수 있습니다.


### 인터페이스가 바뀌였습니다.

<img src="./images/status_after.png">

+ 정보창에 무기, 투구, 상의, 하의, 장갑창이 생깁니다. 골드랑 여행거리가 표시됩니다.

