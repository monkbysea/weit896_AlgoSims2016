#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    //many balls
    for(int i = 0; i< 50; i++){
        
        MyBall temp;
        balls.push_back(temp);
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    ball1.update(); //one ball
    
    //many balls
    for(int i = 0; i< 50; i++){
        
        balls[i].update();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255, 0, 0);
    ball1.draw();//one ball
    
    //many balls
    for(int i = 0; i< 50; i++){
//        ofSetColor(0, 255, 0);
        balls[i].draw();
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
