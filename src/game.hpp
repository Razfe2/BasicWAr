#pragma once
#include "map.hpp"
#include "unit.hpp"

class game {
    private :
    grid& current_grid;
    public :
    game (grid& current_grid) ;
    void evolve(float dt);
};