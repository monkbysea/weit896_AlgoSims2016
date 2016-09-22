#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowShape(1024,768);
    
    ofSetFrameRate(60);
    
    ofSetBackgroundAuto(false);
    ofBackground(0);
    numTriangles = 50;
    distance=5;
    alpha = 150;
    angle=0;
    xOrig=ofGetWidth()/2;
    yOrig=ofGetHeight()/2;
        

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){;
    
   
    
//    for (int t=0; t<numTriangles; ++t) {

        
//        xOffset=cos(angle)*distance;
//        yOffset=sin(angle)*distance;
//
//        Pos.x=xOrig+xOffset;
//        Pos.y=yOrig+yOffset;
    
//    Pos.x=xOrig;
//    Pos.y=yOrig;
    
        // Define a triangle at the center that points to the right
//        ofVec2f p1(Pos.x, Pos.y+6.25);
//        ofVec2f p2(Pos.x, Pos.y);
//        ofVec2f p3(Pos.x, Pos.y-6.25);
    
//        ofPushMatrix();
//        ofTranslate(ofGetWidth()/2,ofGetHeight()/2);
//        float rotation = ofRandom(360); 
//        p1.rotate(rotation);
//        p2.rotate(rotation);
//        p3.rotate(rotation);
//        
//        ofVec2f triangleOffset(distance, 0.0);
//        triangleOffset.rotate(rotation);
//        ofPopMatrix();
//        
//        p1 += Pos + triangleOffset;
//        p2 += Pos + triangleOffset;
//        p3 += Pos + triangleOffset;
//    
//        ofColor aqua(0, 252, 255, alpha);
//        ofColor purple(198, 0, 205, alpha);
//        ofColor inbetween = aqua.getLerped(purple, ofRandom(1.0));
//        ofSetColor(inbetween);
    ofSetColor(255);
    ofDrawTriangle(10, 10, 30, 30, 50, 50);

//        ofDrawTriangle(p1, p2, p3);
//        angle+=0.2;
//        distance+=1;
//        }

}