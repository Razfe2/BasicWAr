#include "game.hpp"
#include <cmath> 
game::game (grid& current_grid): current_grid(current_grid) {}

void game::evolve(float dt) {
    for (auto it=(this->current_grid).objects.begin();it<(this->current_grid).objects.end();++it) {
        order variant_order =(*it)->current_order;
        if (orders::move* m =std::get_if<orders::move>(&variant_order)) {
            float x_pos= (*it)->x_coordinate;
            float y_pos= (*it)->y_coordinate;
            float x_gap= m->x_coordinate-x_pos;
            float y_gap= m->y_coordinate-y_pos;
            float deplacement_norm = (*it)->get_movement_speed()*5*dt;

            if (x_gap == 0) {
                if (y_gap >deplacement_norm) (*it)->set_y_position(y_pos+deplacement_norm);
                else {
                    if (y_gap < - deplacement_norm) (*it)->set_y_position(y_pos-deplacement_norm);
                    else (*it)->set_y_position(m->y_coordinate);
                }
            }
            float deplacement_squared_norm = deplacement_norm*deplacement_norm;
            float slope= y_gap/x_gap;
            float x_deplacement_squared = deplacement_squared_norm/(1+slope*slope);
            float y_deplacement_squared = (deplacement_squared_norm-x_deplacement_squared);
            float new_x_coordinate;
            float new_y_coordinate;
            if (x_gap>0) 
                new_x_coordinate= x_pos + std::sqrt(x_deplacement_squared);
            else  
                new_x_coordinate= x_pos - std::sqrt(x_deplacement_squared);
            if (y_gap>0) 
                new_y_coordinate= y_pos + std::sqrt(y_deplacement_squared);
            else 
                new_y_coordinate= y_pos - std::sqrt(y_deplacement_squared);
            (*it)->set_x_position(new_x_coordinate);
            (*it)->set_y_position(new_y_coordinate);
        }
    }
}