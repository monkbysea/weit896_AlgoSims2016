#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(15);
    gui.setup();
    gui.add(res.setup("resolution", 10, 5, 30));
    
    vf.setup(ofGetWidth(), ofGetHeight(), 10);
    
    
    for (int i = 0; i < 50000; i++) {
        Particle p;
        p.setInit(ofPoint(ofRandom(ofGetWidth()),ofRandom(ofGetHeight())));
        particles.push_back(p);
//        cout << p.pos << endl;
    }

}

//--------------------------------------------------------------
void ofApp::update(){
    
    vf.seedField(1.0);
   
    for (int i = 0; i < particles.size(); i++) {
        particles[i].addForce( vf.getForce(particles[i].getPosition()) * 0.15 );
        particles[i].update();
        particles[i].infiniteWalls();
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
    
    for (int i = 0; i < particles.size(); i++) {
        particles[i].draw();
    }
    
    //the new way of writing for loops "for each loop"
    //& means reference
    //    for(auto & particle: particles){
    //        particle.draw();
    //    }
    
    vf.draw(res);
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
