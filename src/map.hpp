#pragma once
#include "cell.hpp"
#include <vector>
#include <SFML/Graphics.hpp>
#include <memory>
#include "object.hpp"
class game;
class grid {
    friend class game;
    private :
    int height ;
    int width;
    std::vector<cell> cells;
    std::vector<std::unique_ptr<object>> objects;
    
    public :
    grid (int height, int width);
    cell& at (int i, int j);
    const cell& at (int i, int j)const ;
    int get_height () const ;
    int get_width () const ;
    void show(sf::RenderWindow& w, int cells_size) const ;
    void add_object(std::unique_ptr<object> ptr) ;
    grid(const grid&) = delete;

};