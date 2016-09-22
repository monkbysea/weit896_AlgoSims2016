//
//  particles.cpp
//  fireworks
//
//  Created by TAO WEI on 9/21/16.
//
//

#include "particles.hpp"



void Particle::setup(){
    
    pos.x = ofGetWidth()/2;
    pos.y = 50;
    
    radius = 5;
    
    a.x=ofRandom(-0.05,0.05);
    a.y=ofRandom(0,0.05);
    
    vel.x = ofRandom(-2,2);
    vel.y = ofRandom(0, 3);
    
    alpha=255;
    color = ofColor(185, 197, 111,alpha);
    
    someNumber = ofRandom(1,400);
}

void Particle::explosion(){
    
    vel=vel+a;
    pos = pos + vel;
    
}

void Particle::draw(){
    
    ofSetColor(color);
    ofEllipse(pos.x, pos.y, radius, radius);
    radius-=0.02;
    alpha-=0.5;
    
}

void Particle::restart(){
    
    pos.x = ofGetWidth()/2;
    pos.y = 50;
}