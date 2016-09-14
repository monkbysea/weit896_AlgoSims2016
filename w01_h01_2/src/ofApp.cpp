#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    circle1.setup();
    circle2.setup();
    
    mX = circle1.x;
    mY = circle1.y;
    
    mX2 = circle2.x;
    mY2 = circle2.y;
    
    mySwitch = 0;
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    circle1.draw(mX,mY);
    circle2.draw(mX2,mY2);
    
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
    
    if(mySwitch==0){
        mX = ofGetMouseX();
        mY = ofGetMouseY();
        mySwitch++;
    } else if(mySwitch==1){
        mX2 = ofGetMouseX();
        mY2 = ofGetMouseY();
        mySwitch--;
    }
    
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
