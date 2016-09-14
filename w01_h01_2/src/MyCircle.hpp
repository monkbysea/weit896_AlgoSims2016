//
//  MyCircle.hpp
//  two circles
//
//  Created by TAO WEI on 9/7/16.
//
//

#pragma once //just do this dont ask question FOR NOW

#include "ofMain.h"

class MyCircle{
    
public:
    
    void setup();
    void update();  
    void draw(float _x, float _y);
    
    float x;
    float y;
    int dim;
    ofColor color;
    
    
    MyCircle();
    
    
    
private:
    
    

    
};
//how to set the class so that i can set diff colors to each objects?