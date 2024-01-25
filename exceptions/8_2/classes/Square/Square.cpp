#include "Square.h"

Square::Square(): EquilateralQuadrangle("Квадрат", 10 , 90){
    // вот тут непонятная проверка, если я все равно одну сторону передаю
    if( A != 90 ){
        throw MyError("Ошибка создания квадрата. \n\n");
    }
}