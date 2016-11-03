//
//  Particle.cpp
//  vectorfield_cam_gui
//
//  Created by TAO WEI on 11/2/16.
//
//

#include "Particle.hpp"

Particle::Particle() {
    //    pos.x = ofGetWindowWidth()*0.5;
    //    pos.y = ofGetWindowHeight()*0.5;
    //    pos.z = 0.0;
    
    vel.set(0,0,0);
    acc.set(0,0,0);
    
    damp = 0.99; // de resistance!!!
    radius = 0.5;
}

void Particle::setInit(ofPoint _pos, ofPoint _vel){
    pos = _pos;
    vel = _vel;
    acc.set(0,0,0);
}

ofPoint Particle::getPosition(){
    return pos;
}

ofPoint Particle::getVelocity(){
    return vel;
}

float Particle::getRadius(){
    return radius;
}

void Particle::addForce(ofPoint _force){
    acc += _force;
}



void Particle::update() {
    
    vel += acc;
    vel *= damp;
    pos += vel;
    acc *= 0.0;
    
}

void Particle::bounding(){
    if( pos.x < 0.0+radius || pos.x > ofGetWidth()-radius ){
        pos.x -= vel.x; // Bounced back! think of this as an undo;
        vel.x *= -1.0;
    }
    
    if( pos.y < 0.0+radius || pos.y > ofGetHeight()-radius ){
        pos.y -= vel.y; // Bounced back! think of this as an undo;
        vel.y *= -1.0;
    }
}

void Particle::infiniteWalls(){
    if( pos.x < 0.0 ){
        pos.x = ofGetWidth()-1;
        
    }
    
    if( pos.x > ofGetWidth()){
        pos.x = 1;
        
    }
    
    if( pos.y < 0){
        pos.y = ofGetHeight()-1;
        
    }
    
    if( pos.y > ofGetHeight()){
        pos.y = 1;
        
    }
}

void Particle::draw() {
    
    ofSetColor(252,231,104);
    ofCircle(pos, radius);
    
}