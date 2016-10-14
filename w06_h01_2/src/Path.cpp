//
//  Path.cpp
//  path following
//
//  Created by TAO WEI on 10/12/16.
//
//

#include "Path.hpp"

Path::Path(){
    radius = 20;
    start = ofPoint(0,ofGetHeight()/3);
    end = ofPoint(ofGetWidth(),2*ofGetHeight()/3);
}

void Path::display(){;
    ofSetLineWidth(radius*2);
    ofSetColor(0, 0, 0, 100);
    ofDrawLine(start.x, start.y, end.x, end.y);
    
    ofSetLineWidth(1);
    ofSetColor(0);
    ofDrawLine(start.x, start.y, end.x, end.y);
    
}