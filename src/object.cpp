#include "object.hpp"

object::object(int current_hp,float x_coordinate, float y_coordinate, order current_order) :
    current_hp(current_hp),x_coordinate(x_coordinate),y_coordinate(y_coordinate),current_order(current_order) {}

std::tuple<float,float> object::get_position() const {
    return std::make_tuple(this->x_coordinate,this->y_coordinate);
}
int object::get_current_hp () const {return this->current_hp;}
void object::set_x_position(float x) {this->x_coordinate=x;}
void object::set_y_position(float y) {this->y_coordinate=y;}