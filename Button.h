#ifndef BUTTON_H
#define BUTTON_H

#include <GL/freeglut.h>
#include <string>

struct Button { 
    private:
    std::string text;
    float x;
    float y;
    float w;
    float h;
    bool pressed; 
    

public:  
    Button() {
        x = 0.0f;
        y = 0.0f;
        w = 0.06f;
        h = 0.05f;
        text = "Button";
        pressed = false;
    }

    Button(std::string text, float x, float y,float h) {
        this->text = text;
        this->x = x;
        this->y = y;
        this->h = h;
        w = 10.0f;
        pressed = false;
    }

    void draw() {
        float textWidth = 0.0f;
        for (int i = 0; i < text.length(); i++) {
            textWidth += glutBitmapWidth(GLUT_BITMAP_9_BY_15, text[i]);
        }
        float padding = 0.05f;
        textWidth =  textWidth / 200.0;
        w = textWidth + padding;

        glColor3f(1.0f, 1.0f, 1.0f);
        glBegin(GL_POLYGON);
            glVertex2f(x, y);
            glVertex2f(x + w, y);
            glVertex2f(x + w, y - h);
            glVertex2f(x, y - h);
        glEnd();

        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
            glVertex2f(x, y);
            glVertex2f(x + w, y);

            glVertex2f(x + w, y);
            glVertex2f(x + w, y - h);

            glVertex2f(x + w, y - h);
            glVertex2f(x, y - h);

            glVertex2f(x, y - h);
            glVertex2f(x, y);
        glEnd();

        if (pressed) {
            glRasterPos2f(x + (padding / 2) - 0.01, y - (h / 2) - 0.045);
        } else {
            glRasterPos2f(x + (padding / 2), y - (h / 2) - 0.025);
        }
        
        for (int i = 0; i < text.length(); i++) {
            glutBitmapCharacter(GLUT_BITMAP_9_BY_15, text[i]);
        }
    }

    bool isClicked(float mx, float my) {
        if (mx >= x && mx <= x + w && my <= y && my >= y - h) {
            return true;
        } else {
            return false;
        }
    }

    void pressedState(){
        pressed = true; 
    }
   
    void unpressedState(){
        pressed = false;
    }

};

#endif
