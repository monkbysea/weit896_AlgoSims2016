#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    num = 2000;
    ofSetFrameRate(60);
    mesh.setMode(OF_PRIMITIVE_LINES);
    mesh. enableIndices();
    
    
    for(int i=0; i< num; i++){
        //we need to initliaze all of our arrays
        
        ofPoint p;
        points.push_back(p);
        
        float t;
        theta.push_back(t);
        
        float ph;
        phi.push_back(ph);
        
        int r;
        radius.push_back(r);
        
        
        theta[i] = ofRandom(0, 2*PI);
        phi[i] = ofRandom(0,PI);
        //        radius[i] = 180; //if you leave a constant number the points will be evenly distributed on the surface
        radius[i] =200;
        
        
        points[i] = ofPoint(
                            radius[i]*cos(theta[i])*sin(phi[i]),
                            radius[i]*sin(phi[i])*sin(theta[i]),
                            radius[i]*cos(phi[i])
                            );
        mesh.addVertex(points[i]);
        
        offsets.push_back(ofVec3f(ofRandom(0,100),
                                  ofRandom(0,100), ofRandom(0,100)));
       
//        x1=i;
//        x2=i+1;
        
    }
    float connectionDistance = 25;
    int numVerts = mesh.getNumVertices();
    for (int a=0; a<numVerts; ++a) {
        ofVec3f verta = mesh.getVertex(a);
        for (int b=a+1; b<numVerts; ++b) {
            ofVec3f vertb = mesh.getVertex(b);
            float distance = verta.distance(vertb);
            if (distance <= connectionDistance) {
                mesh.addIndex(a);
                mesh.addIndex(b);
            }
        }
    }

}

//--------------------------------------------------------------
void ofApp::update(){
    float time = ofGetElapsedTimef();
    
    int numVerts = mesh.getNumVertices();
    for(int i = 0; i<numVerts; i++){
        
//        ofPoint p = mesh.getVertex(i);
        
//        float perlin = ofNoise(phi[i]*0.05,theta[i]*0.05,time *0.5);
        
//        radius[i] = ofNoise(time*0.5+radius[i])*200;
//        phi[i]=ofNoise(time*0.5+phi[i])*PI;
//        theta[i]=ofNoise(time*0.5+theta[i])*2*PI;
//        cout << radius[i] << endl; //Why didn't it do what I expected?
        
        
        ofVec3f vert = mesh.getVertex(i);
        float time = ofGetElapsedTimef();
        float timeScale = 5.0;
        float displacementScale = 0.75;
        ofVec3f timeOffsets = offsets[i];
        vert.x += (ofSignedNoise(time*timeScale+timeOffsets.x)) *
        displacementScale*10;
        vert.y += (ofSignedNoise(time*timeScale+timeOffsets.y)) *
        displacementScale*10;
        vert.z += (ofSignedNoise(time*timeScale+timeOffsets.z)) *
        displacementScale*10;
        
//        mesh.setVertex(i, p);
        mesh.setVertex(i, vert);
//        mesh.setColor(i, ofColor(255, 255, 255));
        
        
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    cam.begin();
    
    mesh.draw();
    
    cam.end();
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
