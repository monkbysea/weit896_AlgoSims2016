#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowShape(1024,768);
    
    ofSetFrameRate(60); // Limit the speed of our program to 60 frames per second
    
    ofSetBackgroundAuto(false); // Stop the background from being redrawn each frame
    // We still want to draw on a black background, so we need to draw
    // the background before we do anything with the brush
    ofBackground(0);
    int numSnowflakes=500;
        for(i=0; i<numSnowflakes;i++){
        ofPoint p;
        points.push_back(p);
        points[i]=ofPoint(ofRandom(0,1024), ofRandom(0,768));
        ofPoint v;
        velocities.push_back(v);
        velocities[i]=ofPoint(ofRandom(-1,1), ofRandom(-1,1));

    }
}

//--------------------------------------------------------------
void ofApp::update(){
//points[i]=points[i]+velocities[i]; //why can't I put position update here?
    

}

//--------------------------------------------------------------
void ofApp::draw(){
//    if (ofGetMousePressed(OF_MOUSE_BUTTON_LEFT)) {
        int numLines = 500;
        int minRadius = 5;
        int maxRadius = 30;
        for (int i=0; i<numLines; i++) {
            float angle = ofRandom(ofDegToRad(360.0));
            float distance = ofRandom(minRadius, maxRadius);
            float xOffset = cos(angle) * distance;
            float yOffset = sin(angle) * distance;
            
            float alpha = ofMap(distance, minRadius, maxRadius, 80, 0); // Make shorter lines more opaque
            ofSetColor(152,161,192,alpha);
           
            
            ofSetLineWidth(ofRandom(1.0, 4.0));
//            ofRotate(rotateAngle);
//            ofTranslate(points[i].x,points[i].y);
            ofLine(points[i].x, points[i].y, points[i].x+xOffset, points[i].y+yOffset);
            points[i]=points[i]+velocities[i];
//            aVelocity+=aAcceleration;
//            rotateAngle+=aVelocity;
        }
    }


//create an array to store the random positions for the points
//vector<ofPoint> points;
//creat another array to store the velocity for each generated positions
//vector<ofPoint> velocities;
