#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    for(int j=0;j<5;j++){
        ofVideoPlayer tempvideo;
        tempvideo.load("street.mp4");
        videos.push_back(tempvideo);
        videos[j].play();
        videos[j].setVolume(0);
        
        ofMesh tempmesh;
        meshes.push_back(tempmesh);
        
    
    //setup fbo:
    fbo.allocate(videoWidth, videoHeight);
    
    //clear fbo
    fbo.begin();
    ofClear(255, 255, 255, 0);
    fbo.end();
    
    //adding vertices to the grid:
    for(int y=0; y<H; y++){
        for(int x=0; x<W; x++){
            
            meshes[j].addVertex(ofPoint(
                                   (x-W/2)*meshSize,
                                   (y-H/2)*meshSize,
                                   0));
            //add texture coordinates which will allow us to bind textures later on in the code:
            meshes[j].addColor(ofColor(255, 255, 255));
            
            
        }
    }
    
    //seting up the triangles:
    for(int y=0; y<H-1; y++){
        for(int x=0; x<W-1; x++){
            
            int i1 = x + W *y;
            int i2 = x+1 + W *y;
            int i3 = x + W * (y+1);
            int i4 = x+1 + W * (y+1);
        
            meshes[j].addTriangle(i1, i2, i3);
            meshes[j].addTriangle(i2, i4, i3);
           
            
        }
    }
}

}

//--------------------------------------------------------------
void ofApp::update(){
    
    for(int j=0;j<5;j++){
    videos[j].update();
    
        ////////////////////////////////
    //Map the video to the mesh
    if(videos[j].isFrameNew()){
        
        //how we update our fbo:
        fbo.begin();
        int alpha = 100;
        
        ofEnableAlphaBlending();
        ofSetColor(255, 255, 255, alpha);
        videos[j].draw(0,0);
        ofDisableAlphaBlending();
        
        fbo.end();
    }
}
    
    
    
    
    fbo.readToPixels(fboPixels);
    image.setFromPixels(fboPixels);
    ////////////////////////////////
    
    ////////////////////////////////
    //create dynamic movement based on the video brightness
    //loop through the vertices:
for(int j=0;j<5;j++){
    for(int y=0; y<H-1; y++){
        for(int x=0; x<W-1; x++){
            
            //each vertex index
            int i = x + W * y;
            ofPoint p = meshes[0].getVertex(i);
            
            float scaleX = videoWidth / W;
            float scaleY = videoHeight / H;
            
            //get the index of the pixel
            // # of pixels in the grid is videoWidth * videoHeight
            //we are mapping the point of the vertex
            //on the mesh to the pixel in the image
            
            int index = ((x*scaleX) + videoWidth * (y*scaleY)) * 4; //fbo has 4 components including alpha
            
            int brightness = fboPixels[index] / distortion;
            
            p.z = brightness;
            
            meshes[j].setVertex(i, p);
            
            
            
            meshes[j].setColor(i, ofColor(255, 255, 255));
            
        }
    }
}



    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    cam.begin();
    
    ofBackground(0);
    //draw mesh:
    
    float time = ofGetElapsedTimef();
    float timeScale = 0.1;
    float noise =0.3+ofNoise(time * timeScale)*0.9;
    
    
//    ofScale(noise*1.1,noise*1.1,noise*1.1);
    
//    ofRotateX(time*10);
//    ofRotateY(time*10);
    ofRotateZ(time*10);
    
    image.bind();
    meshes[0].draw();
    
    
//    ofPushMatrix();
//    ofTranslate(0,0,0);
//    meshes[1].draw();
//    ofPopMatrix();
//    
//    ofPushMatrix();
//    ofTranslate(0, ofGetHeight()/4,0);
//    meshes[2].draw();
//    ofPopMatrix();
//    
//    ofPushMatrix();
//    ofTranslate(ofGetWidth()*3/4, ofGetHeight()/4,0);
//    meshes[3].draw();
//    ofPopMatrix();
//    
//    ofPushMatrix();
//    ofTranslate(ofGetWidth()*3/4, ofGetHeight()*3/4,0);
//    meshes[4].draw();
//    ofPopMatrix();


    for(int j=0;j<5;j++){
        ofPushMatrix();
        ofTranslate(ofGetWidth()*j/4, ofGetHeight()*j/4,0);
        meshes[j].draw();
        ofPopMatrix();
    }
   
    image.unbind();
    
  
    cam.end();
    
//    for(int i = 0; i <5; i ++){
//        videos[i].draw(i*200, 0,200,200);
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
