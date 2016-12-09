#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowShape(1280,1014);
    res=5;
    img.load("starrynight.jpg");
    ofSetBackgroundAuto(false);
    ofSetFrameRate(30);
    ofEnableAlphaBlending();
    ofBackground(0);
    
    //----------------
    zOff = 0.0;
    zOffSpeed = 0.001;
    
    //---------meshplane------------
    gridWidth = 200;
    gridHeight =200;
    
    int scale = 6;
    
    //make a grid of connected lines
    //which are really this notion of vertices
    for(int x = 0; x< gridWidth; x++){
        for(int y = 0; y < gridHeight; y++){
            
            //create mesh:
            mesh.addVertex(ofPoint(
                                   (x-gridWidth*0.5)*scale,
                                   (y-gridHeight*0.5)*scale,
                                   0));
            ofColor c = img.getColor(x*5,y*5);
            mesh.addColor(c);
        }
    }
    
    //create the triangle indices
    for(int x=0; x < gridWidth-1; x++){
        for(int y=0; y< gridHeight-1; y++){
            //loop through the squares to get the indices
            i1 = x + gridWidth * y;
            i2 = x+1 + gridWidth * y;
            i3 = x + gridWidth * (y+1);
            i4 = x+1 + gridWidth * (y+1);
            
            mesh.addTriangle(i1, i2, i3);
            mesh.addTriangle(i2, i3, i4);
        }
    }
   
    //------orbiting dots----------
    int w = img.getWidth();
    int h = img.getHeight();
    maxSpeed=1.0;
    minSpeed=0.25;
    
    for(int x = 0; x<w ; x+=res){
        for(int y = 0; y <h; y+=res){
            Dot temp;
            temp.setup(x,y);
            dots.push_back(temp);
            ofColor c = img.getColor(x,y);
            colors.push_back(c);
            
        }
    }
    
    for(int i=0;i<dots.size();i++){
        ofPoint center=ofPoint(640,507);
        float distance=ofDist(dots[i].pos.x,dots[i].pos.y,640,507);
        float angle=atan2(dots[i].pos.x-center.x,dots[i].pos.y-center.y);
        distances.push_back(distance);
        angles.push_back(angle);
    }


    startOrbitTime=20.0;

    
    
    
    fbo1.allocate( ofGetWidth(), ofGetHeight(), GL_RGB );
    fbo2.allocate( ofGetWidth(), ofGetHeight(), GL_RGB );
        

}

//--------------------------------------------------------------
void ofApp::update(){
    ofSetWindowTitle(ofToString(ofGetFrameRate(),0));
    
    
    //------mesh----------
    float time = ofGetElapsedTimef();
    
    //Now we want to loop through every vertex:
    //0, 1, 2, 3...
    
    for(int x = 0; x< gridWidth; x++){
        for(int y = 0; y < gridHeight; y++){
            int i = x + gridWidth *y;
            
            ofPoint p = mesh.getVertex(i);
            
            float perlin = ofNoise(x*0.05, y*0.05, time *0.5);
            p.z = perlin * 100;
            
            mesh.setVertex(i, p);
//          mesh.setColor(i, ofColor(perlin*255, perlin*255, 255));
            
        }
    }
    
    
    
    
    
    
    
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    //    string msg;
    
    //    switch (addMode) {
    
    if(ofGetFrameNum()<300){
        fbo1.begin();
        ofBackground(10,50,80,10);
        float time=ofGetElapsedTimef();
        int w = img.getWidth();
        int h = img.getHeight();
        
        for(int x = 0; x<w ; x+=res){
            for(int y = 0; y <h; y+=res){
        
                float theta = ofMap( ofNoise(x*0.001, y*0.003, zOff*0.001), 0, 1, 0, TWO_PI);
                float radius=abs(sin(theta/4))*res;
                float alpha=255*abs(sin(theta));
                ofColor c = img.getColor(x,y);
                ofSetColor(c);
                
                ofDrawCircle(x+res/2, y+res/2, radius/2);
                
                zOff += zOffSpeed;
               
                
            }
        }
        fbo1.end();
        fbo1.draw(0,0,ofGetWidth(), ofGetHeight());
    }
    
    
    if(ofGetFrameNum()>300&&ofGetFrameNum()<600){

        img.resize(200, 200);
        cam.begin();
      
        mesh.draw();
      
        cam.end();


    }
    
    if(ofGetFrameNum()>600){
    
            fbo2.begin();
            ofBackground(10,50,80,10);
            float time=ofGetElapsedTimef();
    
        for(int i=0;i<dots.size();i++){
            Dot &d = dots[i];
            ofPoint center=ofPoint(640,507);
            float dist=800;
            float distance=distances[i];
            float angle=angles[i];
            float elapsedTime = ofGetElapsedTimef() - startOrbitTime;
            float speed = ofMap(distance, 0, 800, maxSpeed, minSpeed, true);
            
            float rotatedAngle = elapsedTime * speed + angle;
            if(distances[i]<dist){
                d.pos.x = distance * cos(rotatedAngle) + center.x;
                d.pos.y = distance * sin(rotatedAngle) + center.y;
                ofSetColor(colors[i]);
                d.draw(res/2);
            }

            
        }
            
            fbo2.end();
            fbo2.draw(0,0,ofGetWidth(), ofGetHeight());
    
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
