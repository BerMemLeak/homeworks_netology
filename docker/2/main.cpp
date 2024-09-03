#include <iostream>
#include "./Shape/Inherited_figures/Square/Square.h"
#include "./Shape/Inherited_figures/Cube/Cube.h"
#include "./Shape/Inherited_figures/Circle/Circle.h"
#include "./Shape/Inherited_figures/Cylinder/Cylinder.h"

#include <cassert> // Для assert



int main() {
    Square rect(1, 1, 5, 3);
    std::cout<< "До преобразования \n";
    rect.display();
    rect.shift(2, 3);
    std::cout<< "После преобразования \n";
    rect.display();
    try {
        Cube cube(0, 0, 10, 10, 0, 10);

        std::cout << "Initial state of the cube:\n";
        cube.display();

        cube.shift(5, 5, 5);
        std::cout << "\nAfter shifting by (5, 5, 5):\n";
        cube.display();

        cube.scaleX(2);
        std::cout << "\nAfter scaling X by 2:\n";
        cube.display();

        cube.scaleY(0.5);
        std::cout << "\nAfter scaling Y by 0.5:\n";
        cube.display();

        cube.scale(2);
        std::cout << "\nAfter scaling uniformly by 2:\n";
        cube.display();

    } catch (const std::exception& e) {
        std::cerr << "An error occurred: " << e.what() << std::endl;
    }

    return 0;
}
