#pragma once

#include "AllClasses.h"



Snake::Snake(std::string name, int x, int y, int weight, int height):
x(x), y(y), weight(weight), height(height) {
	snakeTexture.loadFromFile(name);
	snakeSp.resize(4);
	snakeSp[0].setTexture(snakeTexture);
	snakeSp[0].setTextureRect(sf::IntRect::Rect(0, 1, 42, 42));
	snakeSp[0].setScale(50./42,50./42);
	snakeSp[0].setOrigin(sf::Vector2f(snakeSp[0].getLocalBounds().width, snakeSp[0].getLocalBounds().height) / 2.f);
	snakeSp[0].setRotation(-90);
	snakeSp[0].setPosition(175, 175);


	for (size_t i = 1; i < 3; ++i) {
		snakeSp[i].setTexture(snakeTexture);
		snakeSp[i].setTextureRect(sf::IntRect::Rect(84, 85, 42, 40));
		snakeSp[i].setScale(50./42, 50./40);
		snakeSp[i].setPosition(snakeSp[i-1].getPosition().x - 50,
			snakeSp[i-1].getPosition().y);
		snakeSp[i].setOrigin(sf::Vector2f(snakeSp[i].getLocalBounds().width, snakeSp[i].getLocalBounds().height) / 2.f);
		snakeSp[i].setRotation(-90);
	}

	snakeSp.back().setTexture(snakeTexture);
	snakeSp.back().setTextureRect(sf::IntRect::Rect(42, 85, 42, 40));
	snakeSp.back().setScale(50. / 42, 50. / 40);
	snakeSp.back().setOrigin(sf::Vector2f(snakeSp.back().getLocalBounds().width, snakeSp.back().getLocalBounds().height) / 2.f);
	snakeSp.back().setRotation(90);
	snakeSp.back().setPosition(25,175);

	dx = 0;
	dy = 0;
}

Snake& Snake::operator=(const Snake  sn)
{
	this->x = sn.x;
	this->y = sn.y;
	this->weight = sn.weight;
	this->height = sn.height;
	this->snakeTexture = sn.snakeTexture;
	this->snakeSp = sn.snakeSp;
	this->placeForNext = sn.placeForNext;
	this->dx = sn.dx;
	this->dy = sn.dy;

	return *this;

}

sf::Sprite& Snake::operator[](const int i)
{
	return snakeSp[i];
}

void Snake::pressKey(sf::Clock& animationClock) {
	if (!this->checkRepeat()) {

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			if (dx == 0) {


				placeForNext = snakeSp.back().getPosition();
				penaltimate = snakeSp[snakeSp.size() - 2];
				tailRotate = snakeSp.back().getRotation();
				snakeSp.back().setPosition(snakeSp[snakeSp.size()-2].getPosition());
				snakeSp.back().setRotation(snakeSp[snakeSp.size() - 2].getRotation()+180);
				for (size_t i = snakeSp.size() - 2; i > 1; --i) {
					snakeSp[i].setPosition(snakeSp[i - 1].getPosition());
					snakeSp[i].setTextureRect(snakeSp[i - 1].getTextureRect());
					snakeSp[i].setRotation(snakeSp[i-1].getRotation());
				}

				snakeSp[0].setRotation(270);
				if (dy < 0) snakeSp[1].setTextureRect(sf::IntRect::Rect(85, 0, 41, 41));
				else if (dy > 0) snakeSp[1].setTextureRect(sf::IntRect::Rect(42, 0, 41, 41));
				snakeSp[1].setRotation(snakeSp[0].getRotation());
				dx = 1;
				dy = 0;

				//snakeSp[1].setScale(1, 1);
				snakeSp[1].setPosition(snakeSp[0].getPosition());
				snakeSp[0].setPosition(snakeSp[0].getPosition().x + 50, snakeSp[0].getPosition().y);
				animationClock.restart();
			}

		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			if (dx == 0) {


				placeForNext = snakeSp.back().getPosition();
				penaltimate = snakeSp[snakeSp.size() - 2];
				tailRotate = snakeSp.back().getRotation();
				snakeSp.back().setPosition(snakeSp[snakeSp.size() - 2].getPosition());
				snakeSp.back().setRotation(snakeSp[snakeSp.size() - 2].getRotation()+180);
				for (size_t i = snakeSp.size() - 2; i > 1; --i) {
					snakeSp[i].setPosition(snakeSp[i - 1].getPosition());
					snakeSp[i].setTextureRect(snakeSp[i - 1].getTextureRect());
					snakeSp[i].setRotation(snakeSp[i-1].getRotation());
				}
				snakeSp[0].setRotation(90);
				if (dy < 0) snakeSp[1].setTextureRect(sf::IntRect::Rect(42, 0, 41, 41));
				else if (dy > 0) snakeSp[1].setTextureRect(sf::IntRect::Rect(85, 0, 41, 41));
				snakeSp[1].setRotation(snakeSp[0].getRotation());
				dx = -1;
				dy = 0;
				//snakeSp[1].setScale(1, 1);
				snakeSp[1].setPosition(snakeSp[0].getPosition());
				snakeSp[0].setPosition(snakeSp[0].getPosition().x - 50, snakeSp[0].getPosition().y);
				animationClock.restart();
			}
		}

		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
			if (dy == 0) {

				placeForNext = snakeSp.back().getPosition();
				penaltimate = snakeSp[snakeSp.size() - 2];
				tailRotate = snakeSp.back().getRotation();
				snakeSp.back().setPosition(snakeSp[snakeSp.size() - 2].getPosition());
				snakeSp.back().setRotation(snakeSp[snakeSp.size() - 2].getRotation()+180);
				for (size_t i = snakeSp.size() - 2; i > 1; --i) {
					snakeSp[i].setPosition(snakeSp[i - 1].getPosition());
					snakeSp[i].setTextureRect(snakeSp[i - 1].getTextureRect());
					snakeSp[i].setRotation(snakeSp[i-1].getRotation());
				}

				snakeSp[0].setRotation(180);
				if (dx > 0) snakeSp[1].setTextureRect(sf::IntRect::Rect(42, 0, 41, 41));
				else if (dx < 0) snakeSp[1].setTextureRect(sf::IntRect::Rect(85, 0, 41, 41));
				snakeSp[1].setRotation(snakeSp[0].getRotation());
				std::cout << dx << '\t';
				dx = 0;
				dy = -1;

				//snakeSp[1].setScale(1, 1);
				snakeSp[1].setPosition(snakeSp[0].getPosition());
				snakeSp[0].setPosition(snakeSp[0].getPosition().x, snakeSp[0].getPosition().y - 50);
				animationClock.restart();
			}

		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			if (dy == 0) {

				placeForNext = snakeSp.back().getPosition();
				penaltimate = snakeSp[snakeSp.size() - 2];
				tailRotate = snakeSp.back().getRotation();
				snakeSp.back().setPosition(snakeSp[snakeSp.size() - 2].getPosition());
				snakeSp.back().setRotation(snakeSp[snakeSp.size() - 2].getRotation()+180);
				for (size_t i = snakeSp.size() - 2; i > 1; --i) {
					snakeSp[i].setPosition(snakeSp[i - 1].getPosition());
					snakeSp[i].setTextureRect(snakeSp[i - 1].getTextureRect());
					snakeSp[i].setRotation(snakeSp[i-1].getRotation());
				}

				snakeSp[0].setRotation(0);
				if (dx > 0) snakeSp[1].setTextureRect(sf::IntRect::Rect(85, 0, 41, 41));
				else if (dx < 0) snakeSp[1].setTextureRect(sf::IntRect::Rect(42, 0, 41, 41));
				snakeSp[1].setRotation(snakeSp[0].getRotation());
				dx = 0;
				dy = 1;

				//snakeSp[1].setScale(1, 1);
				snakeSp[1].setPosition(snakeSp[0].getPosition());
				snakeSp[0].setPosition(snakeSp[0].getPosition().x, snakeSp[0].getPosition().y + 50);
				animationClock.restart();
			}

		}

	}
}




void Snake::move(sf::Clock& animationClock,float& animationTime) {
	if (animationTime > 0.5f) {
		if (dx != 0 || dy != 0) {
			/*CurrentFrame += animatonParam * time;
			if (CurrentFrame > 6) animatonParam = -0.005;
			else if (CurrentFrame < 0) animatonParam = 0.005;*/
			placeForNext = snakeSp.back().getPosition();
			penaltimate = snakeSp[snakeSp.size() - 2];
			tailRotate = snakeSp.back().getRotation();

			snakeSp.back().setPosition(snakeSp[snakeSp.size() - 2].getPosition());
			snakeSp.back().setRotation(snakeSp[snakeSp.size() - 2].getRotation() + 180);
			for (size_t i = snakeSp.size() - 2; i > 1; --i) {
				snakeSp[i].setPosition(snakeSp[i - 1].getPosition());
				snakeSp[i].setTextureRect(snakeSp[i - 1].getTextureRect());
				snakeSp[i].setRotation(snakeSp[i-1].getRotation());
				snakeSp[i].setScale(snakeSp[i - 1].getScale());
			}
			snakeSp[1].setTextureRect(sf::IntRect::Rect(84, 85, 42, 41));
			snakeSp[1].setPosition(snakeSp[0].getPosition());
			snakeSp[1].setRotation(snakeSp[0].getRotation());
			snakeSp[0].setPosition(snakeSp[0].getPosition().x + 50 * dx, snakeSp[0].getPosition().y + 50 * dy);
		}


		animationClock.restart();
	}


}




inline sf::Vector2f Snake::getPosition(const int8_t pos)
{
	return snakeSp[pos].getPosition();
}



inline void Snake::setPosition(int8_t index,const float& x, const float& y)
{
	snakeSp[index].setPosition(x, y);
}

std::vector<sf::Sprite>& Snake::getSnake()
{
	return snakeSp;
}

size_t Snake::getSnakeSize()
{
	return snakeSp.size();
}

void Snake::pushBack(sf::Sprite last)
{
	snakeSp.push_back(last);
}

sf::Sprite& Snake::lastBlock()
{
	return snakeSp.back();
}

void Snake::drawSnake(sf::RenderWindow& window)
{
	for (size_t i = 0; i < Snake::getSnakeSize(); ++i) {
		window.draw(snakeSp[i]);
	}

}

inline sf::Vector2f& Snake::getPlaceForNext() {
	return placeForNext;
}

bool Snake::checkRepeat()
{

	for (size_t i = 4; i < snakeSp.size();++i) {
		if (snakeSp[i].getPosition() == snakeSp[0].getPosition()) {
			return true;
		}
	}
	return false;
}

void Snake::stopMove()
{
	dx = 0;
	dy = 0;
}

void Snake::setFirstPos()
{
	snakeSp.resize(4);
	snakeSp[0].setTexture(snakeTexture);
	snakeSp[0].setTextureRect(sf::IntRect::Rect(0, 1, 42, 42));
	snakeSp[0].setScale(50. / 42, 50. / 42);
	snakeSp[0].setOrigin(sf::Vector2f(snakeSp[0].getLocalBounds().width, snakeSp[0].getLocalBounds().height) / 2.f);
	snakeSp[0].setRotation(-90);
	snakeSp[0].setPosition(175, 175);


	for (size_t i = 1; i < 3; ++i) {
		snakeSp[i].setTexture(snakeTexture);
		snakeSp[i].setTextureRect(sf::IntRect::Rect(84, 85, 42, 40));
		snakeSp[i].setScale(50. / 42, 50. / 40);
		snakeSp[i].setPosition(snakeSp[i - 1].getPosition().x - 50,
			snakeSp[i - 1].getPosition().y);
		snakeSp[i].setOrigin(sf::Vector2f(snakeSp[i].getLocalBounds().width, snakeSp[i].getLocalBounds().height) / 2.f);
		snakeSp[i].setRotation(-90);
	}

	snakeSp.back().setTexture(snakeTexture);
	snakeSp.back().setTextureRect(sf::IntRect::Rect(42, 85, 42, 40));
	snakeSp.back().setScale(50. / 42, 50. / 40);
	snakeSp.back().setOrigin(sf::Vector2f(snakeSp.back().getLocalBounds().width, snakeSp.back().getLocalBounds().height) / 2.f);
	snakeSp.back().setRotation(90);
	snakeSp.back().setPosition(25, 175);

	dx = 0;
	dy = 0;
}

sf::Sprite& Snake::getPenaltimateSp()
{
	return this->penaltimate;
}

float Snake::getTailRotate()
{
	return tailRotate;
}






//Food classes method

Food::Food(std::string filename, int x, int y, int weight, int height) :x(x), y(y), weight(weight), height(height) {
	foodTexture.loadFromFile(filename);
	foodSp.setTexture(foodTexture);
	foodSp.setTextureRect(sf::IntRect::Rect(x, y, weight, height));
	foodSp.setScale(50./210, 50./210);
	foodSp.setPosition(25, 25);
	foodSp.setOrigin(sf::Vector2f(foodSp.getLocalBounds().width, foodSp.getLocalBounds().height) / 2.f);
}

void Food::installFood(Snake& snake, std::vector<int>& freeBlock)
{
	if (snake.getPosition(0) == foodSp.getPosition()) {
		for (auto& i : snake.getSnake()) {
			freeBlock[((i.getPosition().y-25) * 20 / 50) + ((i.getPosition().x-25) / 50)] = 0;
		}

			snake.pushBack(snake.lastBlock());
			snake.lastBlock().setPosition(snake.getPlaceForNext());
			snake.lastBlock().setRotation(snake.getTailRotate());
			snake[snake.getSnakeSize() - 2]=snake.getPenaltimateSp();

		
		std::random_device rd;
		std::discrete_distribution <> dist(freeBlock.begin(), freeBlock.end());
		int x = dist(rd);
		//std::cout << x << '\t';

		foodSp.setPosition((x % 20) * 50+25, (x / 20) * 50+25);
		//snakeClock.restart();

		for (auto& i : snake.getSnake()) {
			freeBlock[((i.getPosition().y-25) * 20 / 50) + ((i.getPosition().x-25) / 50)] = 1;
		}

	}

}

void Food::draw(sf::RenderWindow& window)
{
	window.draw(foodSp);
}
