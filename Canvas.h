#ifndef CANVAS_H
#define CANVAS_H

#include "Rectangle.h"
#include "Toolbar.h"
#include "Point.h"
#include "Scribble.h"
#include "Circle.h" 
#include "hexagon.h"
#include "triangle.h" 
#include "ColorSelector.h"



class Canvas{ 
private:
Rectangle area;

Shape * shapes[1000]; 
int shapeCounter; 
int selectedShape;

float offsetX;
float offsetY;

public:
    Canvas(){
        area = Rectangle(-0.8, 1, 1.8, 1.8, Color(1,1,1));
    
        shapeCounter = 0; 
        selectedShape = -1;
        offsetX = 0;
        offsetY = 0;
    }

    void draw(){
        area.draw();  

         for (int i = 0; i < shapeCounter; i++){
            shapes[i]->draw();
        }
    }

    void Clear(){
        for (int i = 0; i < shapeCounter; i++){
            delete shapes[i];
            
        }
        shapeCounter = 0; 
    }

    void eraseShape(float x, float y) {
        int indexToDelete = -1;

        for (int i = 0; i < shapeCounter; i++) {
            if (shapes[i]->contains(x, y)) {
                indexToDelete = i;
                break;
            }
        }
        
        if (indexToDelete != -1) {                
            delete shapes[indexToDelete];
            for (int i = indexToDelete; i < shapeCounter - 1; i++) {
                shapes[i] = shapes[i + 1];
            }
            shapeCounter--;
        }
    }

    void handleMouseClick(float x, float y, Tool selectedTool, Color color){
             if (selectedTool == PENCIL){
            shapes[shapeCounter] = new Scribble(); 
            shapeCounter++;
            ((Scribble*)shapes[shapeCounter-1])->addPoint(x, y, color);
             } 
    

        else if (selectedTool == ERASER){
            eraseShape(x, y);
        }
        else if (selectedTool == SQUARE){
           shapes[shapeCounter] = new Rectangle(x, y, 0.3, 0.3, color);
            shapeCounter++;
        }
        else if (selectedTool == CIRCLE){ 
            shapes[shapeCounter] = new Circle(x, y, 0.15, color);
            shapeCounter++;
        } 
        else if (selectedTool == HEXAGON){
            shapes[shapeCounter] = new Hexagon(x,y,0.17,color);
            shapeCounter++;
        } 
        else if (selectedTool == TRIANGLE){
            shapes[shapeCounter] = new Triangle(x,y,0.2,color);
            shapeCounter++;
        }
        else if (selectedTool == MOUSE){ 
             for (int i = 0; i < shapeCounter; i++){
                shapes[i]->deselect();
             }
             selectedShape = -1;
            for (int i = shapeCounter-1; i >= 0; i--){
                if (shapes[i]->contains(x, y)){
                    shapes[i]->select();
                    selectedShape = i;
                    offsetX = x - shapes[i]->getX();
                    offsetY = shapes[i]->getY() - y;
                }
            } 
            if (selectedShape != -1) {
                shapes[selectedShape]->setColor(color);
            }
        } 
        else if (selectedTool == CLEAR)
            Clear(); 
    }
    void handleMouseDrag(float x, float y, Tool selectedTool, Color color){
        if (selectedTool == PENCIL){
            ((Scribble*)shapes[shapeCounter-1])->addPoint(x, y, color);
        }
        else if (selectedTool == ERASER){

        }
        else if (selectedTool == MOUSE){

            if (selectedShape != -1){
                shapes[selectedShape]->setX(x-offsetX);
                shapes[selectedShape]->setY(y + offsetY);
            }  
            }   
        else if (selectedTool == UP){ 
            arrayUp(x,y);
        }  
        else if (selectedTool == DOWN){ 
            arrayDown(x,y);
        }
        }  

    void arrayUp(float x, float y){
        int index = -1; 
        for (int i = 0; i < shapeCounter; i++){
            if (shapes[i]->contains(x,y)){
                index = i; 
                break;
            }
        }
        if (index != -1 && index+1 < shapeCounter && shapes[index]->isSelected()){
         std::swap(shapes[index], shapes[index+1]);
        }
    }   

    void arrayDown(float x, float y){
        int index = -1; 
        for (int i = 0; i < shapeCounter; i++ ){
            if (shapes[i]->contains(x,y)){
                index = i; 
                break; 
            }
        } 
        if (index != -1 && index-1 > -1 && shapes[index]->isSelected()){
         std::swap(shapes[index], shapes[index-1]);
        }
    }

    bool contains(float x, float y){
        return area.contains(x, y);
    }  
};
#endif
