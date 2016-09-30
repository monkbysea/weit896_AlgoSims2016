#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    //setting up the grid
    
    ptsW = 100;
    ptsH = 100;
    
    for(int i = 0; i< ptsW; i++){
        for(int j = 0; j < ptsH; j++){
            
            float x = ofMap(i,0, ptsW, 0,ofGetWidth());
            float y = ofMap(j,0, ptsH, 0,ofGetHeight());
            
            Particle tempP;
            tempP.setInitialCondition(ofPoint(x,y), ofPoint(0,0));
            particles.push_back(tempP);
            
        }
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    //Magic Sauce:
    // on every frame
    // we reset the forces
    // add in any forces on the particle
    // perfom damping and
    // then update
    
    int count = 0;
    
    for(int i = 0; i< ptsW; i++){
        for(int j = 0; j < ptsH; j++){
            
            float x = ofMap(i,0, ptsW, 0,ofGetWidth());
            float y = ofMap(j,0, ptsH, 0,ofGetHeight());
            
            particles[count].resetForce();
            particles[count].addAttractionForce(ofPoint(x,y), 100, 0.1);
            particles[count].addRepulsionForce(ofPoint(mouseX, mouseY), 50, 0.2);
            
            particles[count].addDampingForce();
            particles[count].update();
            
            
            count++;
            
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(20,147,255);
    ofSetColor(20,230,245);
    for(int i =0; i< particles.size(); i++){
        particles[i].draw();
        
    }
}

