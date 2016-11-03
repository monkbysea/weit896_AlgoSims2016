//
//  Particle.hpp
//  vectorfield_cam_gui
//
//  Created by TAO WEI on 11/2/16.
//
//

#pragma once
#include "ofMain.h"

class Particle {
public:
    Particle();
    
    
    ofVec3f pos;
    ofVec3f vel;
    ofVec3f accel;
    float mass;
    
    void applyForce( ofVec3f force );
    void update();
    void draw();
};

