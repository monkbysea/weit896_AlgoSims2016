//
//  MyPlanet.cpp
//  planet
//
//  Created by TAO WEI on 9/25/16.
//
//

#include "MyPlanet.hpp"


void MyPlanet::set(float _dist, float _intAngle){
    
    
    distance = _dist;
    angle = _intAngle;
    imgEarth.load("earth.png");
    
}


void MyPlanet::update(float _step, ofPoint _center){
    
    angle+= _step;
    
    x = _center.x + distance * cos(angle);
    y = _center.y + distance * sin(angle);
    
}

void MyPlanet::draw(int _width,int _height){
    
    width=_width;
    height=_height;
    
    imgEarth.draw(x,y,width,height);
    
    
}


