#ifndef _STROKE_H_
#define _STROKE_H_
#include "Shape.h"

class Stroke : public Shape
{
    private:
        point endP;
        double width;
};

#endif