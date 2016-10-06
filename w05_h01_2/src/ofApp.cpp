#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    gui.setup();
    gui.add(k.setup("spirng", 0.005, 0.001, 0.1));
    gui.add(restLength.setup("restLength",50,20,100));
    gui.add(r.setup("red", 100, 0, 255));
    gui.add(g.setup("green",100,0,255));
    gui.add(b.setup("blue",100,50,255));


    
    ptsW = 200;
    ptsH = 200;
    
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
    int count = 0;
    
    for(int i = 0; i< ptsW; i++){
        for(int j = 0; j < ptsH; j++){
            
            float x = ofMap(i,0, ptsW, 0,ofGetWidth());
            float y = ofMap(j,0, ptsH, 0,ofGetHeight());
            
            particles[count].resetForce();
            
            particles[count].applySpringforce(ofPoint(ofGetWidth()/2,ofGetHeight()/2),k,restLength);
            
            
            particles[count].update();
            
            
            
            
            
            count++;
            
        }
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
    for(int i =0; i< particles.size(); i++){
        
        particles[i].draw(r,g,b);
        
    }
     gui.draw();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
