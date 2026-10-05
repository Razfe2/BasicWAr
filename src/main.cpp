#include <SFML/Graphics.hpp>
#include "map.hpp"
#define MAP_LENGTH 400
#define NUMBER_CELLS_SQUARE_ROOT 10  

int main()
{
	map map {NUMBER_CELLS_SQUARE_ROOT,NUMBER_CELLS_SQUARE_ROOT};
	sf::RenderWindow window( sf::VideoMode( {400, 400 }), "Basic WAr" );
	sf::CircleShape shape( 100.f );
	shape.setFillColor( sf::Color::Green );

	while ( window.isOpen() )
	{
		while ( const std::optional event = window.pollEvent() )
		{
			if ( event->is<sf::Event::Closed>() )
				window.close();
		}

		window.clear();
		map.show(window,MAP_LENGTH/NUMBER_CELLS_SQUARE_ROOT);
		window.display();
	}
}
