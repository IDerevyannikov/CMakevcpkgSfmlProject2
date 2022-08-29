#pragma once

#include "CMakevcpkgSfmlProject.h"

class Snake {
public:
	Snake(std::string name, int x, int y, int weight, int height);

	Snake& operator = (const Snake sn);
	sf::Sprite& operator [](const int i);


	void pressKey(sf::Clock& animationClock);

	void move(sf::Clock& animationClock, float& animationTime);

	sf::Vector2f getPosition(const int8_t pos);

	void setPosition(int8_t index,const float & x, const float &y);

	std::vector <sf::Sprite>& getSnake();

	size_t getSnakeSize();

	void pushBack(sf::Sprite last);
	
	sf::Sprite& lastBlock();

	void drawSnake(sf::RenderWindow& window);

	sf::Vector2f& getPlaceForNext();

	bool checkRepeat();

	void stopMove();

	void setFirstPos();

	sf::Sprite& getPenaltimateSp();

	float getTailRotate();

private:
	int x, y, weight, height;
	int dx, dy;
	sf::Vector2f placeForNext;
	sf::Texture snakeTexture;
	std::vector <sf::Sprite> snakeSp;
	sf::Sprite penaltimate;
	float tailRotate;
};



//Class Food
class Food {
public:
	Food(std::string filename, int x, int y, int weight, int height);


	void installFood(Snake& snake, std::vector<int>& freeBlock);
	void draw(sf::RenderWindow& window);

private:

	int x, y, weight, height;
	int8_t dx, dy;
	sf::Texture foodTexture;
	sf::Sprite foodSp;
};