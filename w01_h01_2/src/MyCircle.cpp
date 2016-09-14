//
//  MyCircle.cpp
//  two circles
//
//  Created by TAO WEI on 9/7/16.
//
//

#include "MyCircle.hpp"

MyCircle::MyCircle(){
}

void MyCircle::setup(){
    x = ofRandom(0, ofGetWidth());
    y = ofRandom(0, ofGetHeight());
    dim=10;
    color.set(ofRandom(255),ofRandom(255),ofRandom(255));
    
}

void MyCircle::draw(float _x, float _y){
    x = _x;
    y = _y;
    ofSetColor(color);
    
    ofDrawCircle(x,y,dim);
}