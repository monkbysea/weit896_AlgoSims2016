//
//  Particle.cpp
//  vectorfield_cam_gui
//
//  Created by TAO WEI on 11/2/16.
//
//

#include "Particle.hpp"

Particle::Particle() {
    mass = 1.0;
}

void Particle::applyForce(ofVec3f force){
    accel += (force / mass);
}

void Particle::update(){
    vel += accel;
    pos += vel;
    
    vel*= 0.97;
    
    accel.set(0);
    
    if (pos.x > 1000) pos.x = 0;
    if (pos.y > 1000) pos.y = 0;
    if (pos.z > 1000) pos.z = 0;
    
    if (pos.x < 0) pos.x = 1000;
    if (pos.y < 0) pos.x = 1000;
    if (pos.z < 0) pos.x = 1000;
}

void Particle::draw() {
    //    ofCircle( pos, 2 );
    //    ofVertex(pos);
    glVertex3fv(&pos.x);
}