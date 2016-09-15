//
//  MyBall.cpp
//  bouncing balls
//
//  Created by TAO WEI on 9/15/16.
//
//

#include "MyBall.hpp"

//Constructor
MyBall::MyBall(){
    
    //Dot Notation:
    velocity.x = ofRandom(0, 1);
    velocity.y = ofRandom(0,1);
    
    
    position.x = ofGetWidth()/2;
    position.y = ofGetHeight()/2;
}

void MyBall::update(){
    
    //x += 1 ===== x = x + 1
    position.x += velocity.x *5;
    position.y += velocity.y *3;
    
    //Bounding Conditions
    if(position.x < 0 || position.x > ofGetWidth()){
        velocity.x = velocity.x * -1;
        
    }
    
    if( position.y < 0 || position.y > ofGetHeight()){
        velocity.y = velocity.y * -1;
    }
    
}

void MyBall::draw(){
        ofSetColor(ofRandom(255), ofRandom(255), ofRandom(255));
    //    ofCircle(position.x, position.y, 10);
    radius=ofRandom(5,15);
    ofCircle(position, radius);
}

