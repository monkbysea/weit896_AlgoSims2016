#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowShape(1024,768);
    
    ofSetFrameRate(60); // Limit the speed of our program to 60 frames per second
    
    ofSetBackgroundAuto(false); // Stop the background from being redrawn each frame
    // We still want to draw on a black background, so we need to draw
    // the background before we do anything with the brush
    ofBackground(0);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    if (ofGetMousePressed(OF_MOUSE_BUTTON_LEFT)) {
        int numLines = 30;
        int minRadius = 25;
        int maxRadius = 125;
        for (int i=0; i<numLines; i++) {
            
            // Formula for converting from polar to Cartesian coordinates:
            //    x = cos(polar angle) * (polar distance)
            //    y = sin(polar angle) * (polar distance)
            // We need our angle to be in radians if we want to use sin() or cos()
            // so we can make use of an openFrameworks function to convert from degrees
            // to radians
            float angle = ofRandom(ofDegToRad(360.0));
            float distance = ofRandom(minRadius, maxRadius);
            float xOffset = cos(angle) * distance;
            float yOffset = sin(angle) * distance;
            
            float alpha = ofMap(distance, minRadius, maxRadius, 50, 0); // Make shorter lines more opaque
            ofSetColor(255, alpha);
            
            ofSetLineWidth(ofRandom(1.0, 5.0)); // Remember, this doesn't work on all graphics cards
            ofLine(ofGetMouseX(), ofGetMouseY(), ofGetMouseX()+xOffset, ofGetMouseY()+yOffset);
        }
    }
}