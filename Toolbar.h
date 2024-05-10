#ifndef TOOLBAR_H
#define TOOLBAR_H

#include "Rectangle.h"
#include "Texture.h" 


enum Tool {PENCIL, ERASER, SQUARE, TRIANGLE, CIRCLE, HEXAGON, MOUSE, CLEAR,UP,DOWN};

class Toolbar{ 
    private:
    Rectangle area;
    Tool selectedTool;

    Texture mouseButton;
    Texture pencilButton;
    Texture eraserButton;
    Texture squareButton;
    Texture triangleButton; 
    Texture circleButton; 
    Texture hexagonButton;
    Texture clearButton; 
    Texture upButton; 
    Texture downButton;

    void delesectAll(){
        mouseButton.setState(false);
        pencilButton.setState(false);
        eraserButton.setState(false);
        squareButton.setState(false);
        triangleButton.setState(false);
        circleButton.setState(false); 
        hexagonButton.setState(false); 
        clearButton.setState(false);
        upButton.setState(false); 
        downButton.setState(false);
    }

public:
    Toolbar(){
        area = Rectangle(-1, 1, 0.2, 2, Color(0.8,0.8,0.8));
        mouseButton = Texture("assets/mouse.png", -1, 1, 0.2, 0.2);
        pencilButton = Texture("assets/pencil.png", -1, 0.8, 0.2, 0.2);
        eraserButton = Texture("assets/eraser.png", -1, 0.6, 0.2, 0.2);
        squareButton = Texture("assets/square.png", -1, 0.4, 0.2, 0.2);
        triangleButton = Texture("assets/triangle.png", -1,0.2, 0.2,0.2);
        circleButton = Texture("assets/circle1.png",-1,0.0,0.2,0.2);
        hexagonButton = Texture("assets/hexagon.png",-1,-0.2,0.2,0.2);
        clearButton = Texture("assets/4584377.png",-1,-0.4,0.2,0.2); 
        upButton = Texture("assets/up.png", -1,-0.6,0.1,0.2); 
        downButton = Texture("assets/down.png",-0.9,-0.6,0.1,0.2);
        selectedTool = PENCIL;
        pencilButton.setState(false);
    }

    void draw(){
        area.draw();
        mouseButton.draw();
        pencilButton.draw();
        eraserButton.draw();
        squareButton.draw();
        triangleButton.draw(); 
        circleButton.draw(); 
        hexagonButton.draw();
        clearButton.draw();
        upButton.draw();
        downButton.draw();
    }

    bool contains(float x, float y){
        return area.contains(x, y);
    }

    void handleMouseClick(float x, float y){
        if (mouseButton.contains(x, y)){
            delesectAll();
            mouseButton.setState(true);
            selectedTool = MOUSE;
        }
        else if (pencilButton.contains(x, y)){
            delesectAll();
            pencilButton.setState(true);
            selectedTool = PENCIL;
        }
        else if (eraserButton.contains(x, y)){
            delesectAll();
            eraserButton.setState(true);
            selectedTool = ERASER;
        }
        else if (squareButton.contains(x, y)){
            delesectAll();
            squareButton.setState(true);
            selectedTool = SQUARE;
        } 
        else if (triangleButton.contains(x,y)){
            delesectAll(); 
            triangleButton.setState(true); 
            selectedTool = TRIANGLE;
        } 
        else if (circleButton.contains(x,y)){
            delesectAll(); 
            circleButton.setState(true); 
            selectedTool = CIRCLE;
        } 
        else if (hexagonButton.contains(x,y)){
            delesectAll(); 
            hexagonButton.setState(true); 
            selectedTool = HEXAGON;
        } 
        else if (clearButton.contains(x,y)){
            delesectAll();
            clearButton.setState(true);
            selectedTool = CLEAR;
        } 
        else if (upButton.contains(x,y)){
            delesectAll(); 
            upButton.setState(true); 
            selectedTool = UP;
        } 
        else if (downButton.contains(x,y)){ 
            delesectAll(); 
            downButton.setState(true); 
            selectedTool = DOWN; 
        }
    }

    Tool getSelectedTool(){
        return selectedTool;
    }

};

#endif
