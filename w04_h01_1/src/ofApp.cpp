#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
//    ofEnableAntiAliasing();
    ofSetWindowShape(1131,707);

    ofSetCircleResolution(1000);
    planet.set(250,0);
    gui.setup();
    gui.add(width.setup("width", 50, 10, 100));
    gui.add(height.setup("height",50,10,100));
    gui.add(distance.setup("distance",300,100,500));
    gui.add(angle.setup("angle",0,0,90));
    gui.add(step.setup("step",0.01,0,0.1));


    imgSun.load("sun.png");
    imgSpace.load("space.png");
    hoorey.load("hoorey.mp3");
    hoorey.setVolume(0.5);
    hoorey.play();
    hoorey.setLoop(true);
    
}

//--------------------------------------------------------------
void ofApp::update(){
    planet.update(step, ofPoint(ofGetWidth()*0.5, ofGetHeight()*0.5));
}

//--------------------------------------------------------------
void ofApp::draw(){
    imgSpace.draw(0,0);
    imgSun.draw(ofGetWidth()/2-100, ofGetHeight()/2-100,200,200);
    
    
    planet.draw(width, height);
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
