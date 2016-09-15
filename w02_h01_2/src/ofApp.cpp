#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowShape(1024,768);
    
    ofSetFrameRate(60); // Limit the speed of our program to 60 frames per second
    
    ofSetBackgroundAuto(false); // Stop the background from being redrawn each frame
    // We still want to draw on a black background, so we need to draw
    // the background before we do anything with the brush
    ofBackground(0);
    int numSnowflakes=200;
        for(i=0; i<numSnowflakes;i++){
        ofPoint p;
        points.push_back(p);
        points[i]=ofPoint(ofRandom(0,1024), ofRandom(0,768));
        ofPoint v;
        velocities.push_back(v);
        velocities[i]=ofPoint(ofRandom(0,10), ofRandom(0,10));

    }
}

//--------------------------------------------------------------
void ofApp::update(){
//points[i]=points[i]+velocity; //why can't I put position update here?
    points[i]=points[i]+velocities[i];

}

//--------------------------------------------------------------
void ofApp::draw(){
//    if (ofGetMousePressed(OF_MOUSE_BUTTON_LEFT)) {
        int numLines = 200;
        int minRadius = 15;
        int maxRadius = 85;
        for (int i=0; i<numLines; i++) {
            float angle = ofRandom(ofDegToRad(360.0));
            float distance = ofRandom(minRadius, maxRadius);
            float xOffset = cos(angle) * distance;
            float yOffset = sin(angle) * distance;
            
            float alpha = ofMap(distance, minRadius, maxRadius, 50, 0); // Make shorter lines more opaque
            ofSetColor(255, alpha);
           
            
            ofSetLineWidth(ofRandom(1.0, 4.0));
            ofLine(points[i].x, points[i].y, points[i].x+xOffset, points[i].y+yOffset);
            points[i]=points[i]+velocities[i];
        }
    }


//create an array to store the random positions for the points
//vector<ofPoint> points;
//creat another array to store the velocity for each generated positions
//vector<ofPoint> velocities;
