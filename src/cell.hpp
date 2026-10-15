#pragma once
#include <SFML/Graphics.hpp>
class cell {
    private :
    int x_coordinate;
    int y_coordinate;
    public :
    cell (int x_coordinate,int y_coordinate) ;
    sf::Color color() const ;
    int get_x_coordinate () const;
    int get_y_coordinate () const;

};