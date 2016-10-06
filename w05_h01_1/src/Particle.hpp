//
//  Particle.hpp
//  springweb
//
//  Created by TAO WEI on 10/2/16.
//
//

#pragma once

#include "ofMain.h"

class Particle{
    
public:
    Particle();
    void setInitialCondition(ofPoint _pos, ofPoint _vel);
    void update();
    void draw();
    void applySpringforce(ofPoint anchor,float _k, float _restLength);
    void resetForce();
    
    

    ofPoint pos, vel, acc; //force is also known an acceleration. Newton F = ma
    float k;
    float restLength;

    
    
    
};


