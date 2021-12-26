

#include "SFMLScene.h"
#include "iostream"
#include "Game/IGame.h"
#include "Field/Cell.h"
#include "Player/Player.h"
#include "Field/Field.h"


SFMLScene::SFMLScene(const IGame* setGame) : view(Vector2f(0, 0), Vector2f(VIEW_HEIGHT, VIEW_HEIGHT)),
										  window(VideoMode(400, 400), "Test!", Style::Close | Style::Resize),
										  game(setGame)
{

	//playingField = game->getField();
	// загрузка спрайт листа
	img.loadFromFile("img/pictures1.png");
	sprite.setTexture(img);

}

bool SFMLScene::windowIsOpen() const {
	if (window.isOpen()) return true;
	else return false;
}

void SFMLScene::ResizeView(const sf::RenderWindow& window, sf::View& view)// развёртка окна с маштабированием
{
	float aspectRatio = float(window.getSize().x / float(window.getSize().y));
	view.setSize(VIEW_HEIGHT * aspectRatio, VIEW_HEIGHT);
}

void SFMLScene::windowPollEvent() {

	while (window.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			window.close();
			break;
		case sf::Event::Resized:
			ResizeView(window, view);
			break;
		}
	}
}

void SFMLScene::draw() {

	//RenderWindow window(VideoMode(400, 400), "Test!", Style::Close | Style::Resize);
	//View view(Vector2f(0, 0), Vector2f(VIEW_HEIGHT, VIEW_HEIGHT));
	// загрузка спрайт листа
	//Texture img;
	//img.loadFromFile("pictures1.png");

	window.clear(Color::Black);

	for (int i = 0; i < game->getField().getWidth(); ++i) {
		for (int j = 0; j < game->getField().getHeight(); ++j) {
			if (game->getField().field[i][j].getPlayer()) {
				sprite.setTextureRect(IntRect(25, 25, 20, 20));
				sprite.setPosition(i * 20, j * 20);
				window.draw(sprite);
			}
			else if (game->getField().field[i][j].getEnemy()) {
				switch (game->getField().field[i][j].getEnemyType())
				{
				case Enemy::EnemyType::GOBLIN:
					sprite.setTextureRect(IntRect(75, 0, 20, 20));
					break;
				case Enemy::EnemyType::TROLL:
					sprite.setTextureRect(IntRect(50, 0, 20, 20));
					break;
				case Enemy::EnemyType::ORC:
					sprite.setTextureRect(IntRect(100, 0, 20, 20));
					break;
				}
				sprite.setPosition(i * 20, j * 20);
				window.draw(sprite);
			}
			else if (game->getField().field[i][j].getItem()) {
				switch (game->getField().field[i][j].getItemPointer()->getItemType())
				{
				case Item::ItemType::HEALTH_POTION:
					sprite.setTextureRect(IntRect(0, 25, 20, 20));
					break;
				case Item::ItemType::POWER_POTION:
					sprite.setTextureRect(IntRect(0, 50, 20, 20));
					break;
				case Item::ItemType::MANDALORIAN_ARMOR:
					sprite.setTextureRect(IntRect(25, 50, 20, 20));
					break;
				case Item::ItemType::BATTARY:
					sprite.setTextureRect(IntRect(50, 25, 20, 20));
					break;
				}

				sprite.setPosition(i * 20, j * 20);
				window.draw(sprite);
			}
			else if (!game->getField().field[i][j].getIsPassable()) {
				sprite.setTextureRect(IntRect(0, 0, 20, 20));
				sprite.setPosition(i * 20, j * 20);
				window.draw(sprite);
			}
			else if (game->getField().field[i][j].getIsPassable()) {
				sprite.setTextureRect(IntRect(25, 0, 20, 20));
				sprite.setPosition(i * 20, j * 20);
				window.draw(sprite);
			}
		}
	}


	if (game->ifRule()) {
		sprite.setTextureRect(IntRect(75, 25, 20, 20));
		Point exit = game->getField().getExit();
		sprite.setPosition(exit.x * 20, exit.y * 20);
		window.draw(sprite);
	}

	//Vector2f posCircle = leftWheel.spriteWheel.getPosition();
	//view.setCenter(posCircle);		камера на игрока
	//window.setView(view);

	if (!font.loadFromFile("HallFont.ttf"))
	{
		std::cout << "i don't know this";
	}

	text.setFont(font);
	text.setString("HP: " + std::to_string(game->getPlayerFromVector()->getHealth()));
	text.setCharacterSize(40);
	text.setFillColor(Color::Green);
	text.setStyle(Text::StrikeThrough);
	text.setPosition(game->getField().getWidth() * 20 + 5, 10);
	window.draw(text);
	text.setString("Energy: " + std::to_string(game->getPlayerFromVector()->getEnergy()));
	text.setPosition(game->getField().getWidth() * 20 + 5, 60);
	window.draw(text);

	text.setCharacterSize(30);
	text.setString("Power: " + std::to_string(game->getPlayerFromVector()->getAttack()));
	text.setPosition(game->getField().getWidth() * 20 + 5, 120);
	window.draw(text);
	text.setString("Armor: " + std::to_string(game->getPlayerFromVector()->getDefence()));
	text.setPosition(game->getField().getWidth() * 20 + 5, 150);
	window.draw(text);



	window.display();
}
	
