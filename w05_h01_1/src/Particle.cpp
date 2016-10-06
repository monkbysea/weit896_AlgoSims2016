//
//  Particle.cpp
//  springweb
//
//  Created by TAO WEI on 10/2/16.
//
//

#include "Particle.hpp"

Particle::Particle(){
    setInitialCondition(ofPoint(0,0), ofPoint(0,0));
   
    
}

void Particle::setInitialCondition(ofPoint _pos, ofPoint _vel){
    
    pos.set(_pos.x, _pos.y);
    vel.set(_vel.x, _vel.y);
}

void Particle::update(){
    vel +=acc;
    pos +=vel;
}



void Particle::applySpringforce(ofPoint anchor,float _k,float _restLength){
    
    //Steps to create the springy effect
    ofVec2f force = pos - anchor; // the direction of the vector
    k=_k;
    restLength=_restLength;
    float currentLength = force.length();
    float x = currentLength - restLength;
    //normalize refers to vector math whereby you multiply the vector by the "unit vector"
    force.normalize();
    force *= -1 * k * x;  //applying Hooke's Law
    acc+=force;
    
}

void Particle::resetForce(){
    acc.set(0,0);
    
}

void Particle::draw(){
    ofSetColor(255);
    ofCircle(pos, 1);
}