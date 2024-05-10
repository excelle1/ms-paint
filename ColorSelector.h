#ifndef COLOR_SELECTOR_H
#define COLOR_SELECTOR_H

#include "Rectangle.h"
#include "Rectangle.h"
#include "Toolbar.h" 
#include "Circle.h"
#include "Button.h"
#include "Point.h"
#include "Color.h"
#include <iostream>

struct ColorSelector{ 
    private:
    Rectangle area;
    Rectangle display;  
    Rectangle rLine; 
    Rectangle gLine; 
    Rectangle bLine; 

    Button rPlus; 
    Button rMinus; 
    Button gPlus; 
    Button gMinus; 
    Button bPlus; 
    Button bMinus;
    Button clearButton;
    Button downButton; 
    Button upButton;

    Circle rCircle; 
    Circle bCircle; 
    Circle gCircle; 

    Rectangle redButton; 
    Rectangle greenButton; 
    Rectangle blueButton; 

    Color currentColor; 
    Circle currentPosition;
    Button pressedCondition; 


    public:
    ColorSelector(){
       rLine = Rectangle(-0.67f,-0.8f,0.7f,0.05f,Color(1.0f,0.0f,0.0f));
       gLine = Rectangle(-0.67f,-0.87f,0.7f,0.05f,Color(0.0f,1.0f,0.0f));
       bLine = Rectangle(-0.67f,-0.94f,0.7f,0.05f,Color(0.0f,0.0f,1.0f)); 
       rCircle = Circle(-0.67f,-0.82f,0.02,Color(0.0f,0.0f,0.0f));
       rMinus = Button("-",-0.79f,-0.8f,0.05f);
       rPlus = Button("+",0.06f,-0.8f,0.05f);
       gCircle = Circle(-0.67f,-0.89,0.02,Color(0.0f,0.0f,0.0f));
       gMinus = Button("-",-0.79f,-0.87f,0.05f);
       gPlus = Button("+",0.06f,-0.87f,0.05f);
       bCircle = Circle(-0.67f,-0.96,0.02,Color(0.0f,0.0f,0.0f));
       bMinus = Button("-",-0.79f,-0.94f,0.05f);
       bPlus = Button("+",0.06f,-0.94f,0.05f); 
       upButton = Button("UP",0.7f,-0.8f,0.2);
       //downButton = Button("DOWNm")
       area = Rectangle(-0.8f, -0.8f, 1.8f, 2.0f, Color(0.8f, 0.8f, 0.8f));
       display = Rectangle(-1.0f,-0.8f,0.2f,0.2f,Color(0.0f,0.0f,0.0f)); 
       

        //currentColor.setRed();
       // redButton.select();
    }

    Color getCurrentColor(){
        return currentColor;
    }
    
    void draw(){
        area.draw();
        rLine.draw();
        gLine.draw();
        bLine.draw();
        display.draw();
        rCircle.draw();
        gCircle.draw();
        bCircle.draw();
        rPlus.draw();
        rMinus.draw();
        gPlus.draw();
        gMinus.draw();
        bPlus.draw();
        bMinus.draw();
      //  clearButton.draw();
    }

    bool contains(float x, float y){
        return area.contains(x, y);
    }

   // void deselectAll(){
       // redButton.deselect();
      //  greenButton.deselect();
      //  blueButton.deselect();
   // }

   void handleMouseClick(float x, float y){
         float red = currentColor.getR();
         float green = currentColor.getG();
         float blue = currentColor.getB();  



        if (rPlus.isClicked(x,y)){ 
            rCircle.moveRight();
            rPlus.pressedState();
            rMinus.unpressedState();
            gPlus.unpressedState();
            gMinus.unpressedState();
            bPlus.unpressedState();
            bMinus.unpressedState();
            red = std::min(1.0f, red + 0.1f);
            currentColor = Color(red,green,blue);
            display.setColor(currentColor);

        } 
        else if (rMinus.isClicked(x,y)){ 
            rCircle.moveLeft();
            rMinus.pressedState();
            rPlus.unpressedState();
            gPlus.unpressedState();
            gMinus.unpressedState();
            bPlus.unpressedState();
            bMinus.unpressedState();
            red = std::min(1.0f, red - 0.1f);
            currentColor = Color(red,green,blue);
            display.setColor(currentColor);

        } 
        else if (gPlus.isClicked(x,y)){
            gCircle.moveRight();
            gPlus.pressedState();
            rPlus.unpressedState();
            rMinus.unpressedState();
            gMinus.unpressedState();
            bPlus.unpressedState();
            bMinus.unpressedState();

            green = std::min(1.0f, green + 0.1f);

            currentColor = Color(red,green,blue);
            display.setColor(currentColor);
            
        }
        else if (gMinus.isClicked(x,y)){
            gCircle.moveLeft();
            gMinus.pressedState();
            rPlus.unpressedState();
            rMinus.unpressedState();
            gPlus.unpressedState();
            bPlus.unpressedState();
            bMinus.unpressedState();
            green = std::min(1.0f, green - 0.1f);
            currentColor = Color(red,green,blue);
            display.setColor(currentColor);
        } 
        else if(bPlus.isClicked(x,y)){
            bCircle.moveRight();
            bPlus.pressedState();
            rPlus.unpressedState();
            rMinus.unpressedState();
            gPlus.unpressedState();
            gMinus.unpressedState();
            bMinus.unpressedState();
            blue = std::min(1.0f, blue + 0.1f);
            currentColor = Color(red,green,blue);
            display.setColor(currentColor);

        } else if (bMinus.isClicked(x,y)){ 
            bCircle.moveLeft();
            bMinus.pressedState();
            rPlus.unpressedState();
            rMinus.unpressedState();
            gPlus.unpressedState();
            gMinus.unpressedState();
            bPlus.unpressedState();
            blue = std::min(1.0f, blue - 0.1f);
            currentColor = Color(red,green,blue);
            display.setColor(currentColor);

        } else if (upButton.isClicked(x,y)){ 
            bMinus.unpressedState();
            rPlus.unpressedState();
            rMinus.unpressedState();
            gPlus.unpressedState();
            gMinus.unpressedState();
            bPlus.unpressedState();
            clearButton.pressedState(); 
            
            
        
          //  sCounter = 0; 
          //  cCounter = 0; 
           // hCounter = 0;
           // scribbleCounter = 0;
       /* if (redButton.contains(x, y)){
           // deselectAll();
            //redButton.select();
          //  currentColor.setRed();
        }
        else if (greenButton.contains(x, y)){
            deselectAll();
            greenButton.select();
            currentColor.setGreen();
        }
        else if (blueButton.contains(x, y)){
            deselectAll();
            blueButton.select();
            currentColor.setBlue();
        }
    }
    */
        } 

   } 
   void leftMouseUp(float x, float y){
            rPlus.unpressedState();
            rMinus.unpressedState();
            gPlus.unpressedState();
            gMinus.unpressedState();
            bPlus.unpressedState();
            bMinus.unpressedState();
            clearButton.unpressedState(); 
   }
};

#endif
