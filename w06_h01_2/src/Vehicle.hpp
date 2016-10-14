#pragma once

#include "ofMain.h"
#include "Path.hpp"

class Vehicle{
public:
    void setInit(ofVec2f l, float ms, float mf);
    void run();
    void follow(Path p);
    ofVec2f getNormalPoint(ofVec2f p, ofVec2f a, ofVec2f b);
    void update();
    void applyForce(ofVec2f force);
    void seek(ofVec2f target);
    void render();
    void borders();
    
    ofVec2f location;
    ofVec2f velocity;
    ofVec2f acceleration;
    float r;
    float maxforce;    // Maximum steering force
    float maxspeed;
};

