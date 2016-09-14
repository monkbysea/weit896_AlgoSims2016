#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetVerticalSync(true);
    ofEnableAlphaBlending();
    
    myRect1.pos.x = 100;
    myRect1.pos.y = 50;
    myRect2.pos.x = 140;
    myRect2.pos.y = 70;
    myRect3.pos.x = 170;
    myRect3.pos.y = 90;
    

}

//--------------------------------------------------------------
void ofApp::update(){
    myRect1.xenoToPoint(mouseX, mouseY,0.03);
    myRect2.xenoToPoint(mouseX, mouseY,0.05);
    myRect3.xenoToPoint(mouseX, mouseY,0.06);
    

}

//--------------------------------------------------------------
void ofApp::draw(){
    myRect1.draw(255,0,0);
    myRect2.draw(0,255,0);
    myRect3.draw(0,0,255);
    
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
