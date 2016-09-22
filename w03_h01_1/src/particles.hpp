//
//  particles.hpp
//  fireworks
//
//  Created by TAO WEI on 9/21/16.
//
//

#pragma once

#include "ofMain.h"

class Particle{
    
public:
    
    void draw();
    void setup();
    void explosion();
    
    void restart();
    
    ofPoint pos;
    ofPoint vel;
    ofPoint a;
    ofColor color;
    
    float radius;
    int someNumber;
    int alpha;
    
};


