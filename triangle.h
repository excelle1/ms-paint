#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <cmath>
#include <GL/freeglut.h>
#include "Color.h"
#include "Shape.h"

class Triangle: public Shape{
private:
    float radius;
 //   Color color;
    

public:
    
    Triangle() {
        x = 0.0f;
        y = 0.0f;
        radius = 0.1f;
        selected = false;
    }

    Triangle(float x, float y, float radius, Color color) {
        this->x = x;
        this->y = y;
        this->radius = radius;
        this->color = color;
        selected = false;
    }

    void draw() {
        glColor3f(color.getR(), color.getG(), color.getB());

        float inc = ( 2 * M_PI) / 3;
        glBegin(GL_POLYGON);
            for (float theta = 0; theta < 2*M_PI; theta += inc){
                glVertex2f(radius * cos(theta) + x, radius * sin(theta) + y);
            }
        glEnd();

        if (selected) {
            Triangle outer(x, y, radius - 0.02f, Color(1.0f, 1.0f, 1.0f));
            Triangle inner(x, y, radius - 0.04f, color);
            outer.draw();
            inner.draw();
        }
    }

    bool contains(float mx, float my) {
        if (radius >= sqrt((pow((mx - x), 2) + pow((my - y), 2)))) {
            return true;
        } else {
            return false;
        }
    }

};

#endif
