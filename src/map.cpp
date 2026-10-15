#include "map.hpp"
grid::grid (int height, int width) : 
        height(height),
        width(width)                 {
    std::vector<cell> cells {};
    for (int i=0;i< height*width;++i) {
        cells.push_back(cell(i/width,i%width));
    }
    this->cells=cells;
}
cell& grid::at(int i,int j) {return (this->cells)[j+i*(this->width)]; }
const cell& grid::at(int i,int j) const {return (this->cells)[j+i*(this->width)]; }
int grid::get_height () const {return this->height;}
int grid::get_width() const  {return this->width;}
void grid::show(sf::RenderWindow& w, int cells_size) const {
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
    for (auto it=(this->objects).begin();it<(this->objects).end();++it) {
        (*it)->show(w,cells_size);
    }
}

void grid::add_object(std::unique_ptr<object> ptr) {
    (this->objects).push_back(std::move(ptr));
}