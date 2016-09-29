//
//  MyPlanet.hpp
//  planet
//
//  Created by TAO WEI on 9/25/16.
//
//

#pragma once
#include "ofMain.h"

//Inheritence
class MyPlanet : public ofPoint    {
public:
    
    void set(float _dist, float _intAngle);
    void update(float _step, ofPoint _center);
    
    void draw(int _width,int _height);
    
    ///variables
    
    int distance;
    float angle;
    int width, height;
    ofImage imgEarth;
};