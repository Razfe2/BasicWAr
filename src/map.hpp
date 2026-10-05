#pragma once
#include "cell.hpp"
#include <vector>
#include <SFML/Graphics.hpp>
class map {
    private :
    int height ;
    int width;
    std::vector<cell> cells;
    
    public :
    map (int height, int width);
    cell& at (int i, int j);
    const cell& at (int i, int j)const ;
    int get_height () const ;
    int get_width () const ;
    void show(sf::RenderWindow& w, int cells_size) const ;

};