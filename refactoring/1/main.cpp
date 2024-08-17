#include "shape.h"
#include "transform.h"
#include <iostream>




int main(){
    Coordinates x(1,2);
    Coordinates y(1,2);
    Coordinates z(1,2);

    Shape::Type myType = Shape::Type::LINE;
    Shape myShape(myType, x, y, z);
    transform tr(myShape);
    tr.shift(2,3,4);
    std::cout<<'\n'<<myShape.getType();
}

