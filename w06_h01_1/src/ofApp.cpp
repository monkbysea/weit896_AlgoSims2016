#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    num=5;
    for(int i = 0; i< num; i++){
    ofPoint tempDest;
        tempDest.set(ofRandomWidth(),ofRandomHeight());
        dests.push_back(tempDest);
    
        Particle tempCar;
        tempCar.setInit(ofGetWindowSize()/2, ofPoint(ofRandom(5,10),ofRandom(-5,5)));
        cars.push_back(tempCar);
        cars[i].color=ofColor(255,255,0);
    }

    
    ofBackground(255);
    
}

//--------------------------------------------------------------
void ofApp::update(){
    // apply steering force
    for(int i=0;i<num;i++){
        for(int j=0;j<num;j++){
        cars[i].seek(dests[i]);
        float area=50;
        if( cars[i].getPosition().distance( cars[j].getPosition() ) < area ){
            cars[i].color = ofColor(255,0,0);
            
            
            cars[i].addRepulsionForce( cars[j].getPosition(), area,  0.1 );
            }else{
            cars[i].color = ofColor(255,255,0);
            }
        
        // update physics
        cars[i].update();
               if( cars[i].getPosition().distance(dests[i]) < 5){
            dests[i] = ofPoint( ofRandomWidth(), ofRandomHeight() );
        }

        }
    }
    
    
   }

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
    for(int i=0;i<num;i++){
    ofSetColor( cars[i].color );
    ofCircle( dests[i], 4 );
    cars[i].draw();
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
