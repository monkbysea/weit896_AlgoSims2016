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
    
    //---------mesh------------
    gridWidth = 200;
    gridHeight =200;
    
    int scale = 6;
    
    //make a grid of connected lines
    //which are really this notion of vertices
    for(int x = 0; x< gridWidth; x++){
        for(int y = 0; y < gridHeight; y++){
            
            //create our mesh:
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
    
//    //load sound
//    int w = img.getWidth();
//    int h = img.getHeight();
//    
//    for(int x = 0; x<w ; x+=res){
//        for(int y = 0; y <h; y+=res){
//            int i=x+y*(w/res);
//            ofSoundPlayer temp;
//            temp.load("bounce.wav");
//            temp.setMultiPlay(true);
//            sounds.push_back(temp);
//        }
//    }
//    sounds[0].load("vox1.wav");
//    sounds[1].load("vox2.wav");
//    sounds[2].load("vox3.wav");
//    sounds[3].load("vox4.wav");
//    sounds[4].load("vox5.wav");
//    sounds[5].load("vox6.wav");
    
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
//            mesh.setColor(i, ofColor(perlin*255, perlin*255, 255));
            
        }
    }
    
    //update sounds
//    int w = img.getWidth();
//    int h = img.getHeight();
//    float radius;
//    
//    for(int x = 0; x<w ; x+=res){
//        for(int y = 0; y <h; y+=res){
//            float theta = ofMap( ofNoise(x*0.001, y*0.003, zOff*0.001), 0, 1, 0, TWO_PI);
//            radius=abs(sin(theta/4))*res;
 
//            if(x=200){
//                sound1.play();
//                float volume=ofMap(radius, 0, 5, 0.1, 0.5);
//                sound1.setVolume(volume);
//            }
//            if(x=400){
//                sound2.play();
//                float volume=ofMap(radius, 0, 5, 0.1, 0.5);
//                sound2.setVolume(volume);
//                //                float volume=ofMap(radius, 0, 5, 0.1, 0.5);
//            }
//            
//            if(x=600){
//                sound3.play();
//                float volume=ofMap(radius, 0, 5, 0.1, 0.5);
//                sound3.setVolume(volume);
//                //                float volume=ofMap(radius, 0, 5, 0.1, 0.5);
//            }
//            
//            if(x=800){
//                sound4.play();
//                float volume=ofMap(radius, 0, 5, 0.1, 0.5);
//                sound4.setVolume(volume);
//                //                float volume=ofMap(radius, 0, 5, 0.1, 0.5);
//            }
//            
//            if(x=1000){
//                sound5.play();
//                float volume=ofMap(radius, 0, 5, 0.1, 0.5);
//                sound5.setVolume(volume);
//                //                float volume=ofMap(radius, 0, 5, 0.1, 0.5);
//            }
//            
//            if(x=1200){
//                sound6.play();
//                float volume=ofMap(radius, 0, 5, 0.1, 0.5);
//                sound6.setVolume(volume);
//                //                float volume=ofMap(radius, 0, 5, 0.1, 0.5);
//            }

//        }
//    }
    
//    float num=ofMap(radius, 0, 5, 1, 6);
//    int i=floor(num+0.5);
//    
//    if(ofGetFrameNum()<150){
//    sounds[i].play();
//    }
   
//    sound4.play();
//    float volume4=ofMap(radius,0,5,0.01,0.05);
//    sound4.setVolume(volume4);
//    
//    sound5.play();
//    float volume5=ofMap(radius,0,5,0.05,0.1);
//    sound5.setVolume(volume5);
//    
//    sound6.play();
//    float volume6=ofMap(radius,0,5,0.02,0.25);
//    sound6.setVolume(volume6);



    
    
    
    
    
    
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
    if(ofGetFrameNum()>300){
//        fbo2.begin();
        img.resize(200, 200);
        cam.begin();
      
        mesh.draw();
      
        cam.end();
        
//        fbo2.end();
//        fbo2.draw(-640,-507,1280,1014);
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
