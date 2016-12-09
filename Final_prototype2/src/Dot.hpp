//
//  Dot.hpp
//  final
//
//  Created by TAO WEI on 12/6/16.
//
//

#pragma once
#include "ofMain.h"

class Dot {
public:
    
    void setup(float _x, float _y);
    void draw(float _radius);
    void update();
    
    ofVec2f pos,vel;
    float angle;
    float radius;
    ofColor color;
};