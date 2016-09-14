#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundAuto(false);//this commands give you the drawing trails

    ofSetWindowShape(800, 800);
    ofBackground(0);
    ofEnableSmoothing();
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(0,10);
//    ofFill();
//   ofRectMode(OF_RECTMODE_CENTER);
//    ofRect(0,0,ofGetWidth(), ofGetHeight()); //how to clear the canvas to creat the fading effect?
    
    x = r * cos(theta);
    y = r * sin(theta);
    ofNoFill();
    ofSetLineWidth(2);
    ofSetColor(117,185,198,10);
    ofCircle(ofGetWidth()/2, ofGetHeight()/2, r, r);
    r+=0.5;
    
    
    ofSetColor(117,185,198,10);
    ofSetLineWidth(1);
    ofLine(0,i,ofGetWidth()/2+x,ofGetHeight()/2-y);
    ofLine(i,ofGetHeight(),ofGetWidth()/2-x,ofGetHeight()/2-y);
    ofLine(ofGetWidth(),ofGetHeight()-i,ofGetWidth()/2-x,ofGetHeight()/2+y);
    ofLine(ofGetWidth()-i,0,ofGetWidth()/2+x,ofGetHeight()/2+y);
    
    ofPushMatrix();
    ofTranslate(200,200);
    ofNoFill();
    ofSetLineWidth(2);
    ofSetColor(117,185,198,10);
    ofCircle(ofGetWidth()/2, ofGetHeight()/2, r, r);
    r+=0.5;
    
    
    ofSetColor(117,185,198,10);
    ofSetLineWidth(1);
    ofLine(0,i,ofGetWidth()/2+x,ofGetHeight()/2-y);
    ofLine(i,ofGetHeight(),ofGetWidth()/2-x,ofGetHeight()/2-y);
    ofLine(ofGetWidth(),ofGetHeight()-i,ofGetWidth()/2-x,ofGetHeight()/2+y);
    ofLine(ofGetWidth()-i,0,ofGetWidth()/2+x,ofGetHeight()/2+y);

    ofPopMatrix();
    
    ofPushMatrix();
    ofTranslate(200,-200);
    ofNoFill();
    ofSetLineWidth(2);
    ofSetColor(117,185,198,10);
    ofCircle(ofGetWidth()/2, ofGetHeight()/2, r, r);
    r+=0.5;
    
    
    ofSetColor(117,185,198,10);
    ofSetLineWidth(1);
    ofLine(0,i,ofGetWidth()/2+x,ofGetHeight()/2-y);
    ofLine(i,ofGetHeight(),ofGetWidth()/2-x,ofGetHeight()/2-y);
    ofLine(ofGetWidth(),ofGetHeight()-i,ofGetWidth()/2-x,ofGetHeight()/2+y);
    ofLine(ofGetWidth()-i,0,ofGetWidth()/2+x,ofGetHeight()/2+y);
    
    ofPopMatrix();
    
    ofPushMatrix();
    ofTranslate(-200,-200);
    ofNoFill();
    ofSetLineWidth(2);
    ofSetColor(117,185,198,10);
    ofCircle(ofGetWidth()/2, ofGetHeight()/2, r, r);
    r+=0.5;
    
    
    ofSetColor(117,185,198,10);
    ofSetLineWidth(1);
    ofLine(0,i,ofGetWidth()/2+x,ofGetHeight()/2-y);
    ofLine(i,ofGetHeight(),ofGetWidth()/2-x,ofGetHeight()/2-y);
    ofLine(ofGetWidth(),ofGetHeight()-i,ofGetWidth()/2-x,ofGetHeight()/2+y);
    ofLine(ofGetWidth()-i,0,ofGetWidth()/2+x,ofGetHeight()/2+y);
    
    ofPopMatrix();
    
    ofPushMatrix();
    ofTranslate(-200,200);
    ofNoFill();
    ofSetLineWidth(2);
    ofSetColor(117,185,198,10);
    ofCircle(ofGetWidth()/2, ofGetHeight()/2, r, r);
    r+=0.5;
    
    
    ofSetColor(117,185,198,10);
    ofSetLineWidth(1);
    ofLine(0,i,ofGetWidth()/2+x,ofGetHeight()/2-y);
    ofLine(i,ofGetHeight(),ofGetWidth()/2-x,ofGetHeight()/2-y);
    ofLine(ofGetWidth(),ofGetHeight()-i,ofGetWidth()/2-x,ofGetHeight()/2+y);
    ofLine(ofGetWidth()-i,0,ofGetWidth()/2+x,ofGetHeight()/2+y);
    
    ofPopMatrix();
    theta += 0.005;
    j+=0.05;
    i+=j;
    c+=3;
    //z+=0.01;
    if(r>=400){
        r=0;
        theta=0;
        i=0;
        j=0;
        //z=0;
    }
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
