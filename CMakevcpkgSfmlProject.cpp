// CMakevcpkgSfmlProject.cpp: определяет точку входа для приложения.
//

#include "CMakevcpkgSfmlProject.h"
#include<vector>


int main()
{
	sf::RenderWindow window(sf::VideoMode(1000, 500), "My test window");


	sf::Texture myFaceText;
	myFaceText.loadFromFile("C:/Users/vanya/Downloads/3_xG3Y4hwpg.jpg");

	std::vector <sf::Sprite> myFaceSpr;
	myFaceSpr.resize(4);
	myFaceSpr[0].setTexture(myFaceText);
	myFaceSpr[0].setTextureRect(sf::Rect(500, 400, 500, 500));
	myFaceSpr[0].setScale(0.1, 0.1);
	myFaceSpr[0].setPosition(150, 150);

	for (size_t i = 1; i < myFaceSpr.size(); ++i) {
		myFaceSpr[i] = myFaceSpr[i-1];
		myFaceSpr[i].setPosition(myFaceSpr[i].getPosition().x - 50,
			myFaceSpr[i].getPosition().y);
	}



	sf::Texture foodText;
	myFaceText.loadFromFile("C:/Users/vanya/Downloads/3_xG3Y4hwpg.jpg");
	sf::Sprite foodSprite;
	foodSprite.setTexture(foodText);
	foodSprite.setTextureRect(sf::Rect(0, 0, 250, 250));
	foodSprite.setScale(0.2, 0.2);
	



	sf::Clock clock;
	sf::Clock snakeClock;
	sf::Clock animationClock;
	float CurrentFrame = 0;
	float dx = 0;
	float dy = 0;
	float animatonParam = 0.001;


	while (window.isOpen()) {

		float time = clock.getElapsedTime().asMicroseconds();
		float snakeTime = snakeClock.getElapsedTime().asSeconds();
		float animationTime = animationClock.getElapsedTime().asSeconds();
		//float animationTime = clock3.getElapsedTime().asSeconds();

		sf::Event event;
		clock.restart();
		time = time / 800;


		
		if (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}
		

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
			if (dx == 0) {
				dx = 1;
				dy = 0;
				sf::Vector2 tmp= myFaceSpr[0].getPosition();
				myFaceSpr[0].setPosition(myFaceSpr[0].getPosition().x + 50, myFaceSpr[0].getPosition().y);
				for (size_t i = myFaceSpr.size()-1; i>1; --i) {
					myFaceSpr[i].setPosition(myFaceSpr[i-1].getPosition());
				}
				if (myFaceSpr.size() > 1) myFaceSpr[1].setPosition(tmp);
			}
			animationClock.restart();
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
			if (dx == 0) {
				dx = -1;
				dy = 0;
				sf::Vector2 tmp = myFaceSpr[0].getPosition();
				myFaceSpr[0].setPosition(myFaceSpr[0].getPosition().x -50, myFaceSpr[0].getPosition().y);
				for (size_t i = myFaceSpr.size() - 1; i > 1; --i) {
					myFaceSpr[i].setPosition(myFaceSpr[i - 1].getPosition());
				}
				if (myFaceSpr.size() > 1) myFaceSpr[1].setPosition(tmp);
			}
			animationClock.restart();
		}

		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			if (dy == 0) {
				dx = 0;
				dy = -1;
				sf::Vector2 tmp = myFaceSpr[0].getPosition();
				myFaceSpr[0].setPosition(myFaceSpr[0].getPosition().x, myFaceSpr[0].getPosition().y-50);
				for (size_t i = myFaceSpr.size() - 1; i > 1; --i) {
					myFaceSpr[i].setPosition(myFaceSpr[i - 1].getPosition());
				}
				if (myFaceSpr.size() > 1) myFaceSpr[1].setPosition(tmp);

			}
			animationClock.restart();
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
			if (dy == 0) {
				dx = 0;
				dy = 1;
				sf::Vector2 tmp = myFaceSpr[0].getPosition();
				myFaceSpr[0].setPosition(myFaceSpr[0].getPosition().x, myFaceSpr[0].getPosition().y + 50);
				for (size_t i = myFaceSpr.size() - 1; i > 1; --i) {
					myFaceSpr[i].setPosition(myFaceSpr[i - 1].getPosition());
				}
				if (myFaceSpr.size() > 1) myFaceSpr[1].setPosition(tmp);
			}
			animationClock.restart();
		}

		


		if (animationTime > 0.5f) {
			if (dx != 0 || dy != 0) {
				CurrentFrame += animatonParam * time;
				if (CurrentFrame > 6) animatonParam = -0.005;
				else if (CurrentFrame < 0) animatonParam = 0.005;
				sf::Vector2 tmp = myFaceSpr[0].getPosition();
				myFaceSpr[0].setPosition(myFaceSpr[0].getPosition().x + 50 * dx, myFaceSpr[0].getPosition().y + 50 * dy);
				myFaceSpr[0].setTextureRect(sf::Rect(1000, 400 + static_cast<int>(CurrentFrame * 10), -500, 500));
				for (size_t i = myFaceSpr.size() - 1; i > 1; --i) {
					myFaceSpr[i].setPosition(myFaceSpr[i - 1].getPosition());
					myFaceSpr[i].setTextureRect(sf::Rect(1000, 400 + static_cast<int>(CurrentFrame * 10), -500, 500));
				}
				if (myFaceSpr.size() > 1) {

					myFaceSpr[1].setPosition(tmp);
					myFaceSpr[1].setTextureRect(sf::Rect(1000, 400 + static_cast<int>(CurrentFrame * 10), -500, 500));
				}
			}
			

			animationClock.restart();
		}

		/*if (dx < 0) {
			CurrentFrame += updown * time;
			if (CurrentFrame > 6) updown = -0.005;
			else if (CurrentFrame < 0) updown = 0.005;

			for (size_t i = 0; i < myFaceSpr.size(); ++i) {
				myFaceSpr[i].move(dx*time, 0);
				myFaceSpr[i].setTextureRect(sf::Rect(500, 400 + static_cast<int>(CurrentFrame * 10), 500, 500));
			}
		}

		if (dy > 0) {
			CurrentFrame += updown * time;
			if (CurrentFrame > 6) updown = -0.005;
			else if (CurrentFrame < 0) updown = 0.005;
			//sf::Vector2 tmp = myFaceSpr[0].getPosition();
			for (size_t i = 0; i < myFaceSpr.size(); ++i) {
				myFaceSpr[i].move(0, dy * time);
				myFaceSpr[i].setTextureRect(sf::Rect(1000, 400 + static_cast<int>(CurrentFrame * 10), -500, 500));
			}

		}

		if (dy < 0) {
			CurrentFrame += updown * time;
			if (CurrentFrame > 6) updown = -0.005;
			else if (CurrentFrame < 0) updown = 0.005;

			for (size_t i = 0; i < myFaceSpr.size(); ++i) {
				myFaceSpr[i].move(0, dy*time);
				myFaceSpr[i].setTextureRect(sf::Rect(500, 400 + static_cast<int>(CurrentFrame * 10), 500, 500));
			}
		}*/

		if (snakeTime > 3) {
			foodSprite.setPosition(rand() % 950, rand() % 450);
			snakeClock.restart();
		}


		window.clear();

		for (size_t i = 0; i < myFaceSpr.size(); ++i) {
			window.draw(myFaceSpr[i]);
		}
		window.draw(foodSprite);
	
		window.display();

		/*if (snakeTime > 3 * myFaceSpr.size()) {
		
			myFaceSpr.resize(myFaceSpr.size()+1);
			*(myFaceSpr.end() - 1) = *(myFaceSpr.end() - 2);
			myFaceSpr[myFaceSpr.size() - 1].setPosition(myFaceSpr[myFaceSpr.size() - 2].getPosition().x - 400 * dx,
				myFaceSpr[myFaceSpr.size() - 2].getPosition().y - 400 * dy);
			//myFaceSpr[myFaceSpr.size() - 1].setColor(sf::Color::Red);
		}*/
		//std::cout << dx << "\t" << dy <<"\n";
	}

	return 0;
	
	
}


