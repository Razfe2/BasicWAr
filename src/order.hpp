#pragma once
#include <variant>
namespace orders {
    struct do_nothing {

    };
    struct move {
        int x_coordinate ;
        int y_coordinate ;
        move(int x_coordinate, int y_coordinate): x_coordinate(x_coordinate), y_coordinate(y_coordinate) {}
    };

}
 using order = std::variant<orders::do_nothing,orders::move>;