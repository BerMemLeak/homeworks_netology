#include "Rhombus.h"

Rhombus::Rhombus():Quadrangle("Ромб", 30, 30, 30, 30, 30, 40, 30, 30) {
    if(((a != c)||(a != b)) ||(a != d)|| ( A != C || B != D)){
        throw MyError("Ошибка создания ромба. \n\n");
    }
}
