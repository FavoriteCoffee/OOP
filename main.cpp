#include <iostream>
#include <string>
#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "Field/Field.h"
#include "Game/Game.h"
#include "Point.h"
#include "Items/MandalorianArmor.h"
#include "Items/Battery.h"
#include "Items/HealthPotion.h"
#include "Items/PowerPotion.h"
#include "Game/Rules.h"
#include "IniFile/IniFile.h"
//#include "Logger.h"



int main() {
	Field field1(10, 10);
	Rule3 setRule;
	Game<Rule3> game1(&field1, setRule);
	game1.run();
	return 0;
}

//using namespace sf;
//
//static const float VIEW_HEIGHT = 400;
//
//void ResizeView(const sf::RenderWindow& window, sf::View& view)// развёртка окна с маштабированием
//{
//	float aspectRatio = float(window.getSize().x / float(window.getSize().y));
//	view.setSize(VIEW_HEIGHT * aspectRatio, VIEW_HEIGHT);
//}
//
//int main() {
//
//	RenderWindow window(VideoMode(400, 400), "Test!", Style::Close | Style::Resize);
//	View view(Vector2f(0, 0), Vector2f(VIEW_HEIGHT, VIEW_HEIGHT));
//	// загрузка спрайт листа
//	Texture img;
//	img.loadFromFile("pictures.png");
//
//	Player myPlayer();
//	//Player* P = myPlayer;
//	Field field1(10, 10);
//
//	Field field0;
//	field0 = std::move(field1);
//
//	//Field field0(field1);
//	//field0 = field1;
//	/*field.field[2][3].setIsPassiable(false);
//	field.field[7][9].setPlayerPointer(P);
//	field.field[1][1].setEnemyPointer(true);
//	field.field[1][7].setEnemyPointer(true);
//	field.field[0][2].setItemPointer(true);*/
//
//	//Goblin* goblin0 = new Goblin(1, 1);
//
//	Game game1(&field0);
//	field0.setEntry(2, 2);
//	field0.setExit(8, 2);
//
//	for (int i = 0; i < field0.getWidth(); ++i) {
//		for (int j = 0; j < field0.getHeight(); ++j) {
//			if ((i == 0) || (j == 0) || (i == field0.getWidth() - 1) || (j == field0.getHeight() - 1)) {
//				field0[i][j].setIsPassiable(false);
//			}
//		}
//	}
//
//	Player* player = new Player(&field0.field[field0.getEntry().x][field0.getEntry().y]);
//	//Player* player = new Player(&field0.field[2][2]);
//	//game1.vectorOfPointersToObjects.push_back(player);
//
//	Troll* troll0 = new Troll(&field0.field[5][5]);
//	Goblin* goblin0 = new Goblin(&field0.field[3][4]);
//	Orc* orc0 = new Orc(&field0.field[6][5]);
//
//	MandalorianArmor* armor0 = new MandalorianArmor(&field0.field[2][5]);
//	Battery* battery0 = new Battery(&field0.field[2][6]);
//	HealthPotion* heal0 = new HealthPotion(&field0.field[2][7]);
//	PowerPotion* power0 = new PowerPotion(&field0.field[2][8]);
//
//	Logger* gameLog = new Logger(player, goblin0, orc0, troll0, battery0, heal0, power0, armor0);
//
//	game1.vectorOfPointersToEnemies.push_back(troll0);
//	game1.vectorOfPointersToEnemies.push_back(goblin0);
//	game1.vectorOfPointersToEnemies.push_back(orc0);
//
//	
//
//	Sprite sprite;
//	sprite.setTexture(img);
//
//	Clock clock;
//	Time sleepTime = seconds(0.3);
//
//	while (window.isOpen())
//	{
//		if (field0.field[field0.getExit().x][field0.getExit().y].getPlayer() == true) {
//			std::cout << "game over"; break;
//		}
//		float time = clock.getElapsedTime().asMicroseconds();
//		clock.restart();
//
//		//time = time/ 1000;
//		//if (time > 0)
//			//time = 0.5;
//
//
//		Event event;
//		while (window.pollEvent(event))
//		{
//			switch (event.type)
//			{
//			case sf::Event::Closed:
//				window.close();
//				break;
//			case sf::Event::Resized:
//				ResizeView(window, view);
//				break;
//			}
//		}
//
//		if (Keyboard::isKeyPressed(Keyboard::Left)) { player->move(IObject::moveKey::LEFT); }
//		if (Keyboard::isKeyPressed(Keyboard::Up)) { player->move(IObject::moveKey::UP); }
//		if (Keyboard::isKeyPressed(Keyboard::Right)) { player->move(IObject::moveKey::RIGHT); }
//		if (Keyboard::isKeyPressed(Keyboard::Down)) { player->move(IObject::moveKey::DOWN); }
//
//
//		//field.moveGoblin(*goblin0);
//		//field.moveTroll(*troll0);
//
//		game1.moveEnemy(); 
//
//		if ((player->getCellPointer()->getItem()) && (game1.tryPicUp())) { player->pickUp(player->getCellPointer()->getItemPointer()); }
//		if ((player->getCellPointer()->getEnemy()) && (game1.tryFight())) { player->fighting(player->getCellPointer()->getEnemyPointer()); }
//
//		std:: cout << gameLog->logAllObjects();
//		//std::cout << gameLog;
//		//fout.open("file.txt");
//
//
//		//playerLog->check();
//
//		//if (Keyboard::isKeyPressed(Keyboard::Right)) { field.moveGoblin(*goblin0); }
//
//		//ОТРИСОВКА:
//		window.clear(Color::White);
//
//		for (int i = 0; i < field0.getWidth(); ++i) {
//			for (int j = 0; j < field0.getHeight(); ++j) {
//				if (field0.field[i][j].getPlayer()) {
//					sprite.setTextureRect(IntRect(25, 25, 20, 20));
//					sprite.setPosition(i * 20, j * 20);
//					window.draw(sprite);
//				}
//				else if (field0.field[i][j].getEnemy()){
//					switch (field0.field[i][j].getEnemyType())
//					{
//					case Enemy::EnemyType::GOBLIN:
//						sprite.setTextureRect(IntRect(75, 0, 20, 20));
//						break;
//					case Enemy::EnemyType::TROLL:
//						sprite.setTextureRect(IntRect(50, 0, 20, 20));
//						break;
//					case Enemy::EnemyType::ORC:
//						sprite.setTextureRect(IntRect(100, 0, 20, 20));
//						break;
//					}
//					sprite.setPosition(i * 20, j * 20);
//					window.draw(sprite);
//				}
//				else if (field0.field[i][j].getItem()){
//					switch (field0.field[i][j].getItemPointer()->getItemType())
//					{
//					case Item::ItemType::HEALTH_POTION:
//						sprite.setTextureRect(IntRect(0, 25, 20, 20));
//						break;
//					case Item::ItemType::POWER_POTION:
//						sprite.setTextureRect(IntRect(0, 50, 20, 20));
//						break;
//					case Item::ItemType::MANDALORIAN_ARMOR:
//						sprite.setTextureRect(IntRect(25, 50, 20, 20));
//						break;
//					case Item::ItemType::BATTARY:
//						sprite.setTextureRect(IntRect(50, 25, 20, 20));
//						break;
//					}
//					
//					sprite.setPosition(i * 20, j * 20);
//					window.draw(sprite);
//				}
//				else if(!field0.field[i][j].getIsPassable()){
//					sprite.setTextureRect(IntRect(0, 0, 20, 20));
//					sprite.setPosition(i * 20, j * 20);
//					window.draw(sprite);
//				}
//				else if (field0.field[i][j].getIsPassable()) {
//					sprite.setTextureRect(IntRect(25, 0, 20, 20));
//					sprite.setPosition(i * 20, j * 20);
//					window.draw(sprite);
//				}
//			}
//		}
//
//		
//
//		//Vector2f posCircle = leftWheel.spriteWheel.getPosition();
//		//view.setCenter(posCircle);		камера на игрока
//		//window.setView(view);
//
//
//
//		window.display();
//		
//		sleep(sleepTime);
//	}
//
//
//	/*
//	setlocale(0, "");
//
//	std::cout << "создаём поле 4х4 и выводим его:" << std::endl;
//
//	Field field(10, 10);
//
//	field.display();
//
//	std::cout << std::endl;
//
//	//std::cout << "выводим ширину и высоту поля:" << std::endl;
//	//std::cout << field.getWidth() << ", " << field.getHeight();
//
//	//std::cout << std::endl;
//
//	std::cout << "меняем координаты точек входа и выхода на (1, 2) и (3, 2) соответственно:" << std::endl;
//	field.setEntry(2, 2);
//	field.setExit(7, 5);
//	field.display();
//
//
//
//
//	std::cout << std::endl;
//
//	std::cout << "изменяем свойство <<проходимость>> клетки (2, 2): " << std::endl;
//	field[2][3].setIsPassiable(false);
//	field.display();
//
//	std::cout << std::endl;
//
//	std::cout << "назначаем позиции игрока, врага и предмета (0, 0), (1, 1) и (0, 2) соответственно:" << std::endl;
//	field[0][0].setPlayer(true);
//	field[1][1].setEnemy(true);
//	field[0][2].setItem(true);
//	field.display();
//
//	/*std::cout << std::endl;
//
//	std::cout << "при добавлении врага на одну клетку с героем отображается только герой (временно):" << std::endl;
//	field.getCell(0, 0).addEnemy();
//	field.display();
//
//	return 0;*/
//}