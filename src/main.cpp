#include <SFML/Graphics.hpp>
#include "map.hpp"
#include "unit.hpp"
#include <memory>
#include "game.hpp"
#include <chrono>
#include <thread>
#define MAP_LENGTH 400
#define NUMBER_CELLS_SQUARE_ROOT 10  
#define CELLS_SIZE MAP_LENGTH/NUMBER_CELLS_SQUARE_ROOT

int main()
{
	grid grid {NUMBER_CELLS_SQUARE_ROOT,NUMBER_CELLS_SQUARE_ROOT};
	footman f1 (40,100,100,orders::move {200,200});
	grid.add_object(std::make_unique<footman>(f1));
	sf::RenderWindow window( sf::VideoMode( {400, 400 }), "Basic WAr" );
	sf::CircleShape shape( 100.f );
	shape.setFillColor( sf::Color::Green );

	using Clock = std::chrono::steady_clock;
	auto next = Clock::now();
	float dt=0.01;
	game g (grid);
	while ( window.isOpen() )
	{
		while ( const std::optional event = window.pollEvent() )
		{
			if ( event->is<sf::Event::Closed>() )
				window.close();
		}

		window.clear();
		grid.show(window,CELLS_SIZE);
		window.display();
		g.evolve(dt);
		next += std::chrono::duration_cast<Clock::duration>(std::chrono::duration<float>(dt));
		std::this_thread::sleep_until(next);

	}
}