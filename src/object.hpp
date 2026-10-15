#pragma once
#include <SFML/Graphics.hpp>
#include <tuple>
#include "order.hpp"
class game;
class object {
    friend class game;
    protected :
    int current_hp;
    float x_coordinate;
    float y_coordinate;
    order current_order;
    public :
    object(int current_hp,float x_coordinate, float y_coordinate, order current_order);
    virtual ~object()=default;
    virtual int max_hp() const =0;
    virtual void show(sf::RenderWindow& w, int cells_size) const =0;
    std::tuple<float,float> get_position() const;
    std::tuple<float,float> get_position() ;
    int get_current_hp() const ;
    virtual float get_movement_speed() const=0;
    void set_x_position(float x);
    void set_y_position(float y);


};