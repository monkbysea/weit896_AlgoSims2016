#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    image.load("stars.jpg");
    image.resize(200, 200);
    
    gui.setup();
    gui.add(r.setup("red", 85, 0, 255));
    gui.add(g.setup("green",78,0,255));
    gui.add(b.setup("blue",68,0,255));
    gui.add(timeScale.setup("timeScale",5.0,1.0,20.0));
    gui.add(displacementScale.setup("displacementScale",0.75,0.0,4.0));
    gui.add(maxSpeed.setup("maxSpeed",1.0,1.0,5.0));
    gui.add(minSpeed.setup("minSpeed",0.25,0.0,0.75));

    
    

    
    //    mesh.setMode(OF_PRIMITIVE_POINTS);
    mesh.setMode(OF_PRIMITIVE_LINES);
    
    //    mesh.enableColors();
    mesh.enableIndices();
    
    
    float intensityThreshold =150;
    int w = image.getWidth();
    int h = image.getHeight();
    for (int x=0; x<w; ++x) {
        for (int y=0; y<h; ++y) {
            ofColor c = image.getColor(x, y);
            float intensity = c.getLightness();
            if (intensity >= intensityThreshold) {
                float saturation = c.getSaturation();
                float z = ofMap(saturation, 0, 255, -100, 100);
                ofVec3f pos(x*4, y*4, z);
                mesh.addVertex(pos);
                // When addColor(...), the mesh will automatically convert
                // the ofColor to an ofFloatColor
                mesh.addColor(c);
                offsets.push_back(ofVec3f(ofRandom(0,100000),
                                          ofRandom(0,100000), ofRandom(0,100000)));
            }
        }
    }
    
    // Let's add some lines!
    float connectionDistance = 25;
    int numVerts = mesh.getNumVertices();
    for (int a=0; a<numVerts; ++a) {
        ofVec3f verta = mesh.getVertex(a);
        for (int b=a+1; b<numVerts; ++b) {
            ofVec3f vertb = mesh.getVertex(b);
            float distance = verta.distance(vertb);
            if (distance <= connectionDistance) {
                // In OF_PRIMITIVE_LINES, every pair of vertices or indices will be
                // connected to form a line
                mesh.addIndex(a);
                mesh.addIndex(b);
            }
        }
    }
    
    meshCentroid = mesh.getCentroid();
    
    for (int i=0; i<numVerts; ++i) {
        ofVec3f vert = mesh.getVertex(i);
        float distance = vert.distance(meshCentroid);
        float angle = atan2(vert.y-meshCentroid.y,
                            vert.x-meshCentroid.x);
        distances.push_back(distance);
        angles.push_back(angle);
    }
    
    orbiting = false;
    startOrbitTime = 0.0;
    
    meshCopy = mesh;

    mouseDisplacement = false;
}

//--------------------------------------------------------------
void ofApp::update(){
    if (mouseDisplacement) {
        
        ofVec3f mouse(mouseX, ofGetHeight()-mouseY, 0);
        
        for (int i=0; i<mesh.getNumVertices(); ++i) {
            ofVec3f vertex = meshCopy.getVertex(i);
            float distanceToMouse = mouse.distance(vertex);
            
            float displacement = ofMap(distanceToMouse, 0, 400, 300.0,
                                       0, true);
            
            ofVec3f direction = vertex - mouse;
            
            direction.normalize();
            
            ofVec3f displacedVertex = vertex + displacement*direction;
            mesh.setVertex(i, displacedVertex);
        }
    }
    
    
    
    int numVerts = mesh.getNumVertices();
    for (int i=0; i<numVerts; ++i) {
        ofVec3f vert = mesh.getVertex(i);
        float time = ofGetElapsedTimef();
//        float timeScale = 5.0;
//        float displacementScale = 0.75;
        ofVec3f timeOffsets = offsets[i];
        vert.x += (ofSignedNoise(time*timeScale+timeOffsets.x)) *
        displacementScale;
        vert.y += (ofSignedNoise(time*timeScale+timeOffsets.y)) *
        displacementScale;
        vert.z += (ofSignedNoise(time*timeScale+timeOffsets.z)) *
        displacementScale;
        mesh.setVertex(i, vert);
    }
    
    if (orbiting) {
        int numVerts = mesh.getNumVertices();
        for (int i=0; i<numVerts; ++i) {
            ofVec3f vert = mesh.getVertex(i);
            float distance = distances[i];
            float angle = angles[i];
            float elapsedTime = ofGetElapsedTimef() - startOrbitTime;
            
//            float speed = ofMap(distance, 0, 200, 1, 0.25, true);
            float speed = ofMap(distance, 0, 200, maxSpeed, minSpeed, true);
            
            float rotatedAngle = elapsedTime * speed + angle;
            
            vert.x = distance * cos(rotatedAngle) + meshCentroid.x;
            vert.y = distance * sin(rotatedAngle) + meshCentroid.y;
            mesh.setVertex(i, vert);
        }
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
//    ofColor centerColor = ofColor(85, 78, 68);
    ofColor centerColor = ofColor(r, g, b);
    ofColor edgeColor(0, 0, 0);
    ofBackgroundGradient(centerColor, edgeColor, OF_GRADIENT_CIRCULAR);
    gui.draw();
    easyCam.begin();
    ofPushMatrix();
    ofTranslate(-ofGetWidth()/2, -ofGetHeight()/2);
    mesh.draw();
    ofPopMatrix();
    easyCam.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == 'o') {
        orbiting = !orbiting; // This inverts the boolean
        startOrbitTime = ofGetElapsedTimef();
        mesh = meshCopy; //
        
    }
    
    if (key == 'm') {
        mouseDisplacement = !mouseDisplacement; // Inverts the boolean
        mesh = meshCopy; // Restore the original mesh
    }
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
