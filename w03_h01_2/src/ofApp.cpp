#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
//    ofSetupOpenGL(800, 800, OF_WINDOW);
    ofSetWindowShape(800,800);
    ofSetBackgroundAuto(false);
    ofSetFrameRate(30);
    ofBackground(0);
    ofSetColor(255);
    radius=5;
    alpha=255;
    colors[0]=ofColor(184,207,216,alpha);
    colors[1]=ofColor(86,133,143,alpha);
    colors[2]=ofColor(244,179,8,alpha);
    colors[3]=ofColor(241,161,4,alpha);
    colors[4]=ofColor(192,81,216,alpha);
    xNose=ofGetWidth()/2;
    yNose=ofGetHeight()/3;
    
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    for(int i=0;i<5;i++){
    ofSetColor (colors[i],alpha);
    xEye = ofGetWidth()/4 + cos(angle) * scalar;
    yEye= ofGetHeight()/4 + sin(angle) * scalar;
    
    xEye2 = ofGetWidth()*3/4 + cos(angle) * scalar;
    yEye2= ofGetHeight()/4 + sin(angle) * scalar;
    
    xMouth=ofGetWidth()*.5+ cos(angle) * 100;
    yMouth=ofGetHeight()*.9+sin(angle) * 100;
        

        
    ofEllipse( xEye, yEye, radius, radius);
    ofEllipse( xEye2, yEye2, radius, radius);
    
        if(yNose<ofGetHeight()*2/3){
    ofEllipse( xNose, yNose,15,15);
        }
        if((angle>PI*5/4)&&(angle<PI*7/4)){
//            ofPushMatrix();
//            ofTranslate(ofGetWidth()/2,ofGetHeight()/2);
            ofEllipse( xMouth, yMouth,15,15);
//            ofPopMatrix();
        }
    angle += speed;
    scalar += 0.1;
    alpha-=0.1;
    yNose +=0.2;
    xMouth+=0.2;

        
}
//    if(alpha=0){
//        alpha=255;
//    }
//    
//    if(radius=0){
//        radius=20;
//    }

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
