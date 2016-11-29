#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::exit()
{
    getImages.stopThread();
}
//--------------------------------------------------------------
void ofApp::setup()
{
    ofSetWindowShape(1280, 720);
    

    

    instagram.setup("50945680.5c50e54.a02247d8b6b4428c9fe308c2b32e4a04","self");
    instagram.setCertFileLocation(ofToDataPath("ca-bundle.crt",false));
    images.clear();
    images.resize(12);
    instagram.getUserRecentMedia("self",12);
    if (!instagram.getImageURL().empty())
    {
        for ( int i = 0; i < instagram.getImageURL().size(); i++)
        {
            getImages.loadFromURL(images[i], instagram.getImageURL()[i]);
            
        }
        
    }

    
    
    shader.load( "kaleido" );
    ksectors=10;
    kangle=-10;
    kx=0.5;
    ky=0.5;
    

    
    fbo.allocate( ofGetWidth(), ofGetHeight(), GL_RGB );
    
    
    

    
}
//--------------------------------------------------------------
void ofApp::update()
{

    
//    images.clear();
//    images.resize(12);
//    instagram.getUserRecentMedia("self",12);
//    if (!instagram.getImageURL().empty())
//    {
//        for ( int i = 0; i < instagram.getImageURL().size(); i++)
//        {
//            getImages.loadFromURL(images[i], instagram.getImageURL()[i]);
//            
//        }
//        
//    }
//
    float time = ofGetElapsedTimef();
    float timeScale = 0.001;
    float noise =ofNoise(time*timeScale);
    float theta=ofMap(noise, 0, 1, 0, 2*PI);
    ksectors+=sin(theta*0.01)*5;
    kangle+=sin(theta*0.002)*5;
    kx*=abs(sin(theta*0.02));
//    ky*=abs(sin(theta*0.01));
    if (ksectors>50){
        ksectors=10;
    }
    if (kangle>50){
        kangle=-10;
    }
    
}

//---------------------------------------------------------------
void ofApp::draw2(){
    fbo.begin();
    ofBackground(0);
    instagram.drawJSON(10);
    
    float time = ofGetElapsedTimef();
    
    
    if (!images.empty()) {
        for (int i = 0; i < images.size(); i++) {
            
            //            ofSetColor(255, 255, 255);
            ofSetColor( 255, imageAlpha );
            
            if (images[i].isAllocated()) {
                if(i <= 3) {
                    ofPushMatrix();
                    ofTranslate(5*(i+1)+125+250*i, 5+125);
                    ofRotate(time*10);
                    images[i].draw(-125, -125,250,250);
                    ofPopMatrix();
                }
                else if(i >= 4 && i <= 7) {
                    ofPushMatrix();
                    ofTranslate(5*(i-4+1)+125+250*(i-4), 5+125+250+5);
                    ofRotate(time*10);
                    images[i].draw(-125, -125, 250,250);
                    ofPopMatrix();
                    
                }
                else if(i >= 8 && i <= 11) {
                    ofPushMatrix();
                    ofTranslate(5*(i-8+1)+125+250*(i-8), 5+125+250+250+5+5);
                    ofRotate(time*10);
                    images[i].draw(-125, -125, 250,250);
                    ofPopMatrix();
                    
                }
               
            }
        }
    }
    
   
    
    fbo.end();
    
    ofSetColor( 255 );
    
    
    
        shader.begin();
        shader.setUniform1i( "ksectors", ksectors );
        shader.setUniform1f( "kangleRad", ofDegToRad(kangle) );
        shader.setUniform2f( "kcenter", kx*ofGetWidth(),
                            ky*ofGetHeight() );
        shader.setUniform2f( "screenCenter", 0.5*ofGetWidth(),
                            0.5*ofGetHeight() );
    
    fbo.draw( 0, 0, ofGetWidth(), ofGetHeight() );
   

}

//--------------------------------------------------------------
void ofApp::draw()
{
//    ofColor centerColor = ofColor(85, 78, 68);
//    ofColor edgeColor(0, 0, 0);
//    ofBackgroundGradient(centerColor, edgeColor, OF_GRADIENT_CIRCULAR);
 
    draw2();
    
}
//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
    

    switch (key) {
        case 'l':
            images.clear();
            images.resize(12);
            instagram.getUserRecentMedia("self",12);
            if (!instagram.getImageURL().empty())
            {
                for ( int i = 0; i < instagram.getImageURL().size(); i++)
                {
                    getImages.loadFromURL(images[i], instagram.getImageURL()[i]);
                    
                }
                
            }
            break;
        case 'f':
            images.clear();
            images.resize(12);
            instagram.getUserFeed(12);
            if (!instagram.getImageURL().empty())
            {
                for ( int i = 0; i < instagram.getImageURL().size(); i++)
                {
                    getImages.loadFromURL(images[i], instagram.getImageURL()[i]);
                }
            }
            break;
        case 'c':
            images.clear();
            break;
        default:
            break;
    }
}
//--------------------------------------------------------------
void ofApp::keyReleased(int key)
{

}
//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y )
{

}
//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button)
{

}
//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{

}
//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button)
{

}
//--------------------------------------------------------------
void ofApp::mouseScrolled(int x, int y, float scrollX, float scrollY)
{
    instagram.mouseScroll(scrollY);
}
