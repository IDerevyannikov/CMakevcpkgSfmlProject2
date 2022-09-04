#include "CMakevcpkgSfmlProject.h"
#include "AllClasses.h"

int main()
{
	sf::RenderWindow gameWindow(sf::VideoMode(1000, 500), "My test window");


	Snake mainSnake("C:/Users/vanya/Desktop/SFML programs/CMakevcpkgSfmlProject2/CMakevcpkgSfmlProject/Snake sprite sheet.png");
	Food apple("C:/Users/vanya/Desktop/SFML programs/CMakevcpkgSfmlProject2/CMakevcpkgSfmlProject/FoodSprite.png", 83, 94, 210, 210);

	Background bg;

	Counter pointCtr("C:/Users/vanya/Downloads/ComicMono.ttf");


	sf::Clock snakeClock;
	sf::Clock animationClock;
	

	std::vector<int> freeBlock((1000 / 50) * (500 / 50));
	std::fill(freeBlock.begin()+20, freeBlock.end(), 1);

	bool ispaused = false;
	sf::Event gameEvent;

	while (gameWindow.isOpen()) {

		float snakeTime = snakeClock.getElapsedTime().asSeconds();
		float animationTime = animationClock.getElapsedTime().asSeconds();


		
		if (gameWindow.pollEvent(gameEvent)) {
			if (gameEvent.type == sf::Event::Closed)
				gameWindow.close();

			else if (gameEvent.type ==sf::Event::KeyPressed) {

				if (gameEvent.key.code == sf::Keyboard::P) {
					ispaused = !ispaused;
				}

				else if ((mainSnake.checkRepeat() || ispaused) && gameEvent.key.code == sf::Keyboard::R) {
					ispaused = 0;
					pointCtr.setTextString("Point: 0");
					apple.installFood(mainSnake, freeBlock, pointCtr);
					mainSnake.setFirstPos();
				}

			}
		}
		
		if (!ispaused && !mainSnake.checkRepeat()) {
			mainSnake.pressKey(animationClock);
			mainSnake.move(animationClock, animationTime);


			apple.installFood(mainSnake, freeBlock, pointCtr);

			//if (mainSnake.checkRepeat()) {
				//mainSnake.stopMove();
				//continue;
			//}

			gameWindow.clear(sf::Color(0,141,150));
			bg.draw(gameWindow);
			mainSnake.drawSnake(gameWindow);
			apple.draw(gameWindow);
			pointCtr.draw(gameWindow);
			gameWindow.display();

		}
	}

	return 0;
	
}
