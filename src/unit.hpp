#pragma once
#include "object.hpp"
#include <SFML/Graphics.hpp>
#include "order.hpp"

class unit : public object{
    public :
    unit(int current_hp,float x_coordinate, float y_coordinate,order current_order) ;
    virtual int damage () const =0;


};

class footman : public unit{
    private : 
    public :
    footman(int current_hp,float x_coordinate, float y_coordinate,order current_order);
    int damage() const override;
    void show(sf::RenderWindow& w, int cells_size) const override;
    int max_hp () const override;
    float get_movement_speed() const override;

};