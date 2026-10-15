#include "unit.hpp"
unit::unit(int current_hp,float x_coordinate, float y_coordinate,order current_order): 
    object( current_hp, x_coordinate,y_coordinate,current_order) {}

footman::footman(int current_hp,float x_coordinate, float y_coordinate, order current_order): 
    unit(current_hp,x_coordinate, y_coordinate,current_order) {} 

void footman::show(sf::RenderWindow& w, int cells_size) const {
    sf::CircleShape circ {};
    circ.setRadius(10);
    float x = this->x_coordinate;
    float y = this->y_coordinate;
    circ.setFillColor(sf::Color::Red);
    circ.setPosition({x,y});
    w.draw(circ);
}
int footman::damage() const  {
    return 5;
}
int footman::max_hp () const  {return 40;}
float footman::get_movement_speed () const  {return 5;}