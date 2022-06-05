/*#include <SFML/Graphics.hpp>
#include<iostream>
using namespace std;

int main()
{

	sf::RenderWindow window(sf::VideoMode(800, 600), "Hello, SFML world!");
	window.setFramerateLimit(60);

	while (window.isOpen())
	{
	
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
        
        while (true) {
           
		window.clear();
		window.display();
	}


	return 0;
}
*/