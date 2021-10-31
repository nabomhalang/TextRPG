
Text RPG
=============

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
inven.addItem(Weapon(0, 0, "Nomal Weapon2", 0, 0, 0, 0));
inven.addItem(Weapon(0, 0, "Nomal Weapon3", 0, 0, 0, 0));
inven.addItem(Armor(0, 0, "Nomal Armor_had", 0, 0, 0, 0));
inven.addItem(Armor(0, 0, "Nomal Armor_arms", 0, 0, 0, 0));
inven.addItem(Armor(0, 0, "Nomal Armor_body", 0, 0, 0, 0));
inven.addItem(Armor(0, 0, "Nomal Armor_legs", 0, 0, 0, 0));

for (size_t i = 0; i < inven.size(); i++)
{
	cout << inven[i].item_debugPrint() << endl;
}
```