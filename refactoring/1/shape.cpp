#include"shape.h"
#include<cmath>
Shape::Shape(Type _type, Coordinates x,Coordinates y,Coordinates z)
{
    type = _type;

    int a = abs(x.values[0] - x.values[1]);
    int b = abs(y.values[0] - y.values[1]);
    int c = abs(z.values[0] - z.values[1]);

    switch (type)
    {
        case Type::LINE:
            target_x.push_back(x.values[0]) ; target_y.push_back( y.values[0]);
            target_x.push_back(x.values[1]); target_y.push_back(y.values[1]);
            square = 0;
            volume = 0;
            break;
        case Type::SQUARE:
            target_x.insert(target_x.end(), { x.values[0], x.values[1], x.values[2], x.values[3] });
            target_y.insert(target_y.end(), { y.values[0], y.values[1], y.values[2], y.values[3] });
            square = a * b;
            volume = 0;
            break;
        case Type::CUBE:
            for (int i = 0; i < 8; ++i) {
                target_x.push_back(x.values[i]);
                target_y.push_back(y.values[i]);
                target_z.push_back(z.values[i]);
            }
            square = 2 * a * b + 2 * a * c + 2 * b * c;
            volume = a * b * c;
            break;
        default:
            break;
    }
}

Shape::Shape(Type _type, int _x1, int _y1, double R, double H): type(_type) {
    switch (type) {
        case Type::CIRCLE:
            target_x.push_back(_x1);
            target_y.push_back(_y1);
            radius = R;
            square = M_PI * R * R;
            volume = 0;
            break;
        case Type::CYLINDER:
            target_x.push_back(_x1);
            target_y.push_back(_y1);
            radius = R;
            height = H;
            square = M_PI * R * R + 2 * R * height;
            volume = M_PI * R * R * height;
            break;
        default:
            break;
    }

}