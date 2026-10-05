#include "map.hpp"
map::map (int height, int width) : 
        height(height),
        width(width)                 {
    std::vector<cell> cells {};
    for (int i=0;i< height*width;++i) {
        cells.push_back(cell());
    }
    this->cells=cells;
}
cell& map::at(int i,int j) {return (this->cells)[j+i*(this->width)]; }
const cell& map::at(int i,int j) const {return (this->cells)[j+i*(this->width)]; }
int map::get_height () const {return this->height;}
int map::get_width() const  {return this->width;}

void map::show(sf::RenderWindow& w, int cells_size) const {
    sf::RectangleShape rect ( {float(cells_size),float(cells_size)}) ;
    rect.setOutlineColor(sf::Color(0, 0, 0, 120));
    rect.setOutlineThickness(-1.f);
    for (int i=0;i<this->height;++i) {
        for(int j=0;j<this->width;++j) {
            rect.setPosition( {j*float(cells_size),i*float(cells_size)});
            rect.setFillColor((this->at(i,j)).color());
            w.draw(rect);

        }
    }
}