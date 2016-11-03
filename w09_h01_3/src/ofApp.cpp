#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(15);
    gui.setup();
    gui.add(res.setup("resolution", 10, 5, 30));
    
    vf.setup(1000, 1000,1000, 30);
    
    
//    for (int i = 0; i < 50000; i++) {
//        Particle p;
//        p.setInit(ofPoint(ofRandom(ofGetWidth()),ofRandom(ofGetHeight())));
//        particles.push_back(p);
//    }
    for( int i=0; i<100000; i++ ){
        addParticle();
    }
    
    ofBackground (0);

}

void ofApp::addParticle() {
    Particle part;
    part.pos = ofVec3f( ofRandom(vf.width), ofRandom(vf.height), ofRandom(vf.depth) );
    
    particles.push_back( part );
}

//--------------------------------------------------------------
void ofApp::update(){
    
    vf.seedField(1.0);
   
    for( int i=0; i<particles.size(); i++ ){
        particles[i].applyForce( vf.getForceAtPosition(particles[i].pos ) * 0.005 );
        particles[i].update();
    }

}

//--------------------------------------------------------------
void ofApp::draw(){

    
    myCam.begin();
    
    ofPushMatrix(); {
        ofTranslate(vf.width*0.5*-1, vf.height*0.5*-1, vf.depth*0.5*-1);
        
        
        
        //vf.draw();
        
        glBegin(GL_POINTS);
        for( int i=0; i<particles.size(); i++ ){
            particles[i].draw();
        }
        glEnd();
        
    } ofPopMatrix();
    myCam.end();
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
