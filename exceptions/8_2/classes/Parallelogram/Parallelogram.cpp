#include "Parallelogram.h"

Parallelogram::Parallelogram():Quadrangle("Парралеллограмм", 20, 30, 20, 30, 30, 40, 30, 40) {
    if(((a != c)||(b != d)) || ( A != C || B != D)){
        throw MyError("Ошибка создания параллелограмма. \n\n");
    }
}
