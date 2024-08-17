#include "transform.h"

transform::transform( Shape& sh): shape(sh){}

Shape transform::shift(int m, int n, int k)
{
    switch (shape.getType())
    {
        case Shape::LINE:
            shape.target_x[0] += m; shape.target_y[0] += n;
            shape.target_x[1] += m; shape.target_y[1] += n;
            break;
        case Shape::SQUARE:
            for (int i = 0; i < 4; ++i) {
                shape.target_x[i] += m;
                shape.target_y[i] += n;
            }
            break;
        case Shape::CUBE:
            for (int i = 0; i < 8; ++i) {
                shape.target_x[i] += m;
                shape.target_y[i] += n;
                shape.target_z[i] += k;
            }
    }
    return shape;
}

Shape transform::scaleX(int a)
{
    switch (shape.getType())
    {
        case Shape::LINE:
            for (int i = 0; i < 2; ++i) {
                shape.target_x[i] *= a;
            }
            break;
        case Shape::SQUARE:
            for (int i = 0; i < 4; ++i) {
                shape.target_x[i] *= a;
            }
            break;
        case Shape::CUBE:
            for (int i = 0; i < 8; ++i) {
                shape.target_x[i] *= a;
            }
            break;
    }
    return shape;
}

Shape transform::scaleY(int d)
{
    switch (shape.getType())
    {
        case Shape::LINE:
            for (int i = 0; i < 2; ++i) {
                shape.target_y[i] *= d;
            }
            break;
        case Shape::SQUARE:
            for (int i = 0; i < 4; ++i) {
                shape.target_y[i] *= d;
            }
            break;
        case Shape::CUBE:
            for (int i = 0; i < 8; ++i) {
                shape.target_y[i] *= d;
            }
            break;
    }
    return shape;
}

Shape transform::scaleZ(int e)
{
    switch (shape.getType())
    {
        case Shape::LINE:
            for (int i = 0; i < 2; ++i) {
                shape.target_z[i] *= e;
            }
            break;
        case Shape::SQUARE:
            for (int i = 0; i < 4; ++i) {
                shape.target_z[i] *= e;
            }
            break;
        case Shape::CUBE:
            for (int i = 0; i < 8; ++i) {
                shape.target_z[i] *= e;
            }
            break;
    }
    return shape;
}


Shape transform::scale(int s)
{
    switch (shape.getType())
    {
        case Shape::LINE:
            for (int i = 0; i < 2; ++i) {
                shape.target_x[i] /= s;
                shape.target_y[i] /= s;
            }
            break;
        case Shape::SQUARE:
            for (int i = 0; i < 4; ++i) {
                shape.target_x[i] /= s;
                shape.target_y[i] /= s;
            }
            break;
        case Shape::CUBE:
            for (int i = 0; i < 8; ++i) {
                shape.target_x[i] /= s;
                shape.target_y[i] /= s;
                shape.target_z[i] /= s;
            }
            break;
    }
    return shape;
}
