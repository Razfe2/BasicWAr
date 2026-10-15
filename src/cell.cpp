#include "cell.hpp"

cell::cell(int x_coordinate, int y_coordinate): 
    x_coordinate(x_coordinate), y_coordinate(y_coordinate) {}

int cell::get_x_coordinate() const {return this->x_coordinate;}

int cell::get_y_coordinate() const {return this->y_coordinate;}

sf::Color cell::color () const {return sf::Color(80, 160, 70);}