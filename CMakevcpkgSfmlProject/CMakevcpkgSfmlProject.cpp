#include "CMakevcpkgSfmlProject.h"
#include "AllClasses.h"

int main()
{
	sf::Text text;
	sf::Font font;
	font.loadFromFile("C:/Users/vanya/Downloads/ComicMono.ttf");
	// select the font
	text.setFont(font); // font is a sf::Font

	// set the string to display

	// set the character size
	text.setCharacterSize(24); // in pixels, not points!

	// set the color
	text.setFillColor(sf::Color(0,0,0));


	std::string str;

	sf::RenderWindow window(sf::VideoMode(1000, 500), "My test window");


	std::string filename = "C:/Users/vanya/Desktop/SFML programs/CMakevcpkgSfmlProject2/CMakevcpkgSfmlProject/FoodSprite.png";
	Snake mySnake=Snake::Snake("C:/Users/vanya/Desktop/SFML programs/CMakevcpkgSfmlProject2/CMakevcpkgSfmlProject/Snake sprite sheet.png", 0, 0, 42, 42);
	Food food(filename, 83, 94, 210, 210);


	sf::Texture bgTex;
	bgTex.loadFromFile("C:/Users/vanya/Desktop/SFML programs/CMakevcpkgSfmlProject2/CMakevcpkgSfmlProject/white2.png");

	sf::Clock clock;
	sf::Clock snakeClock;
	sf::Clock animationClock;
	float CurrentFrame = 0;
	float dx = 0;
	float dy = 0;
	float animatonParam = 0.001;


	std::vector<int> freeBlock((1000 / 50) * (500 / 50));
	std::fill(freeBlock.begin()+20, freeBlock.end(), 1);

	bool ispaused = false;

	while (window.isOpen()) {

		float time = clock.getElapsedTime().asMicroseconds();
		float snakeTime = snakeClock.getElapsedTime().asSeconds();
		float animationTime = animationClock.getElapsedTime().asSeconds();

		sf::Event event;
		clock.restart();
		time = time / 800;

		
		if (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();

			else if (event.type ==sf::Event::KeyPressed) {
				if (event.key.code == sf::Keyboard::P) {
					ispaused = !ispaused;
				}

				else if ((mySnake.checkRepeat() || ispaused) && event.key.code == sf::Keyboard::R) {
					ispaused = 0;
					food.installFood(mySnake, freeBlock);
					mySnake.setFirstPos();
				}

			}
		}
		
		if (!ispaused) {
			mySnake.pressKey(animationClock);
			mySnake.move(animationClock, animationTime);


			food.installFood(mySnake, freeBlock);

			if (mySnake.checkRepeat()) {
				mySnake.stopMove();
				continue;
			}

			str = "Point: " + std::to_string(mySnake.getSnakeSize()-4);
			text.setString(str);

			text.setPosition(500 - text.getLocalBounds().width, 0);

			window.clear(sf::Color(0,141,150));
			bg.draw(window);
			mySnake.drawSnake(window);
			food.draw(window);


			window.draw(text);
			window.display();

		}
	}

	return 0;
	
	
}
