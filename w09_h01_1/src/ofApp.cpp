#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(30);
    ofSetBackgroundAuto(false);
    ofSetWindowShape(800,800);
    ofBackground(0);
    num=4096;
    for(int i = 0; i < num; i++) {
        ofPoint pos_temp = ofPoint(ofRandom(0,800),ofRandom(0,800));
        pos.push_back(pos_temp);
        
        ofPoint vel_temp;
        vel.push_back(vel_temp);
        
        ofPoint acc_temp;
        acc.push_back(acc_temp);
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    for(int i=0; i<num; i++){
        pos[i]+=vel[i];
        vel[i]+=acc[i];
        
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
//    float time = ofGetElapsedTimef();			//Get the time in seconds
//    
//    //Get periodic value in [-1,1], with wavelength equal to 1 second
//    float value = sin( time * M_TWO_PI * 2 );
//    
//    float v = ofMap( value, -1, 1, 0, 255 );
//    
//    ofBackground(v, 0, 0);
   
    for(int i=0; i<num; i++){

        
        ofSetColor(255,0,0);
        
        ofDrawCircle(pos[i],0.3);
        vel[i].x = 10*ofNoise(pos[i].x*.007, pos[i].y*.007, noisy*2)*cos(4*PI*ofNoise(pos[i].x*.007, pos[i].y*.007, noisy*.5));
        vel[i].y = 10*ofNoise(pos[i].x*.007, pos[i].y*.007, noisy*2)*sin(4*PI*ofNoise(pos[i].x*.007, pos[i].y*.007, noisy*.5));
        if(pos[i].x < 0 || pos[i].y < 0 || pos[i].x > 800 || pos[i].y > 800){
            pos[i].x = ofRandom(0, 800);
            pos[i].y = ofRandom(0, 800);
            vel[i].x = 0;
            vel[i].y = 0;
        }
        acc[i].x = 0;
        acc[i].y = 0;
    }
    noisy += .007;

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
