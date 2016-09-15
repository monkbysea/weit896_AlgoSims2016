//
//  MyBall.hpp
//  bouncing balls
//
//  Created by TAO WEI on 9/15/16.
//
//

#pragma once

#include "ofMain.h"

class MyBall {
    
    
public:
    
    MyBall();
    
    void update();
    void draw();
    
    ofPoint position;
    
    ofVec2f velocity;
    
    int radius;
    
    
    
};