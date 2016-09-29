#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowShape(1024,768);
    
    ofSetFrameRate(10);
    
    ofSetBackgroundAuto(false);
    ofBackground(0);
    gui.setup();
    gui.add(numTriangles.setup("num", 50, 50, 300));
    gui.add(minOffset.setup("min",25,15,50));
    gui.add(maxOffset.setup("max",200,150,350));
    gui.add(alpha.setup("alpha",150,0,255));

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
//    int numTriangles=50;
//    int minOffset=25;
//    int maxOffset=200;
//    int alpha=150;
    
    for (int t=0; t<numTriangles; ++t) {
        float offsetDistance = ofRandom(minOffset, maxOffset);
        
        ofVec2f Pos(ofGetWidth()/2, ofGetHeight()/2);
        
        // Define a triangle at the origin (0,0) that points to the right
        ofVec2f p1(0, 6.25);
        ofVec2f p2(25, 0);
        ofVec2f p3(0, -6.25);
        
        float rotation = ofRandom(360);
        p1.rotate(rotation);
        p2.rotate(rotation);
        p3.rotate(rotation);
        
        ofVec2f triangleOffset(offsetDistance, 0.0);
        triangleOffset.rotate(rotation);
        
        p1 += Pos + triangleOffset;
        p2 += Pos + triangleOffset;
        p3 += Pos + triangleOffset;
        
        ofColor aqua(0, 252, 255, alpha);
        ofColor purple(198, 0, 205, alpha);
        ofColor inbetween = aqua.getLerped(purple, ofRandom(1.0));
        ofSetColor(inbetween);
        
        ofDrawTriangle(p1, p2, p3);
        
        gui.draw();
        
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
