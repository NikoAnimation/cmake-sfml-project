#include <iostream>

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

void threadFunc_windowThread(int id) {
	sf::Vector2i winSize(500, 500);

	sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
	sf::RenderWindow window(sf::VideoMode(winSize.x, winSize.y, desktop.bitsPerPixel), "am bouncy");
	window.setFramerateLimit(60);

	sf::Vector2f vel(5, 5);
	sf::Vector2f pos(window.getPosition().x, window.getPosition().y);

	switch (id) {
		case 0:
			vel = sf::Vector2f(12, 5);
			break;
		case 1:
			vel = sf::Vector2f(5, -12);
			break;
		case 2:
			vel = sf::Vector2f(-24, 12);
			break;
		case 3:
			vel = sf::Vector2f(-13, -4);
			break;
	}

	while (window.isOpen()) {

		float grav = 1;
		vel.y += grav;

		auto monitorSize = sf::Vector2f(desktop.width, desktop.height - 40);
		pos += vel;

		if (pos.y + winSize.y > monitorSize.y) {
			pos.y = monitorSize.y - winSize.y;
			vel.y = -vel.y;
		}
		if (pos.y < 0) {
			pos.y = 0;
			vel.y = -vel.y;
		}
		if (pos.x + winSize.x > monitorSize.x) {
			pos.x = monitorSize.x - winSize.x;
			vel.x = -vel.x;
		}
		if (pos.x < 0) {
			pos.x = 0;
			vel.x = -vel.x;
		}

		window.setPosition(sf::Vector2i(std::round(pos.x), std::round(pos.y)));

		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}

		float t = 0.016;
		sf::sleep(sf::seconds(t));

		/*window.clear(sf::Color::Transparent);

		sf::Texture texture;
		texture.loadFromFile("dvd screensaver.png", sf::IntRect(0, 0, winSize.x, winSize.y));
		texture.setSmooth(true);
		sf::Sprite sprite(texture);

		window.draw(sprite);

		window.display();*/
	}
}