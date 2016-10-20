#include "ofApp.h"
//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowShape(2000,1000);
    //Set up sound sample
    sound.load( "problem.mp3" );
    sound.setLoop( true );
    sound.play();
 
    
    
    //Set spectrum values to 0
    for (int i=0; i<N; i++) {
        float temp;
        spectrum.push_back(temp);
        spectrum[i] = 0.0f;
    }
    
    //Initialize points offsets by random numbers
    for ( int j=0; j<n; j++ ) {
        ofPoint p_temp;
        p.push_back(p_temp);
        float tx_temp, ty_temp,tz_temp;
        tx.push_back(tx_temp);
        ty.push_back(ty_temp);
        tz.push_back(tz_temp);
        tx[j] = ofRandom( 0, 1000 );
        ty[j] = ofRandom( 0, 1000 );
        tz[j] = ofRandom( 0, 1000);
        float t;
        theta.push_back(t);
        float ph;
        phi.push_back(ph);
        theta[j]=ofRandom(0,2*PI);
        phi[j]=ofRandom(0,PI);
        float chPh;
        changePhi.push_back(chPh);
        float cT;
        changeTheta.push_back(cT);
        changePhi[j]=ofRandom(0,0.02);
        changeTheta[j]=ofRandom(0,0.02);
        float color;
        colors.push_back(color);
        colors[j]=ofColor(ofRandom(255),ofRandom(255),ofRandom(255));
        
        
        
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    //Update sound engine
    ofSoundUpdate();
    
    //Get current spectrum with N bands
    float *val = ofSoundGetSpectrum( N );
    //We should not release memory of val,
    //because it is managed by sound engine
    
    //Update our smoothed spectrum,
    //by slowly decreasing its values and getting maximum with val
    //So we will have slowly falling peaks in spectrum
    for ( int i=0; i<N; i++ ) {
        spectrum[i] *= 0.97;	//Slow decreasing
        spectrum[i] = max( spectrum[i], val[i] );
    }
    
    //Update particles using spectrum values
    
    //Computing dt as a time between the last
    //and the current calling of update()
    float time = ofGetElapsedTimef();
    float dt = time - time0;
    dt = ofClamp( dt, 0.0, 0.1 );
    time0 = time; //Store the current time
    
    //Update Rad and Vel from spectrum
    //Note, the parameters in ofMap's were tuned for best result
    //just for current music track
    Rad = ofMap( spectrum[ bandRad ], 1, 2, 400, 600, true );
    Vel = ofMap( spectrum[ bandVel ], 0, 0.1, 0.5, 1.2 );
    
    //Update particles positions
    for (int j=0; j<n; j++) {
        tx[j] += Vel * dt;	//move offset
        ty[j] += Vel * dt;	//move offset
        tz[j] += Vel * dt;
        //Calculate Perlin's noise in [0, 1] and
        //multiply on Rad
        
        p[j]=ofPoint (  ofNoise( tx[j] ) * Rad*cos(theta[j])*sin(phi[j]),
                        ofNoise( ty[j] ) * Rad*sin(theta[j])*sin(phi[j]),
                        ofNoise( tz[j] ) * Rad*cos(phi[j])
                    );
        theta[j]+=changeTheta[j];
        phi[j]+=changePhi[j];
        
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
    
    //Draw spectrum
    ofSetColor( 0, 0, 0 );
    for (int i=0; i<N; i++) {
        
        //Draw bandRad and bandVel by white color,
        //and other by random color
        if ( i == bandRad || i == bandVel ) {
            ofSetColor(255);
        }
        else {
            ofSetColor(ofRandom(255), ofRandom(255), ofRandom(255)); //Random color
        }
        ofRect( 10 + i * 5, 700, 3, -spectrum[i] * 150 );
    }
    
    cam.begin();
    //Draw cloud
    
    
    //Draw points
   
    
    for (int i=0; i<n; i++) {
        ofDrawCircle( p[i], 0.1 );
    }
    
    //Draw lines between near points
    float dist = 180;	//Threshold parameter of distance
    for (int j=0; j<n; j++) {
        for (int k=j+1; k<n; k++) {
            float distance=ofDist( p[j].x, p[j].y,p[j].z, p[k].x, p[k].y,p[k].z );
            if ( distance < dist ) {
              
                
                float alpha = ofMap(distance,0,180,150,0);
                

                ofSetColor(colors[j],alpha);//how to vary the color along the line
                
                ofSetLineWidth(0.0001);
                

                ofDrawLine( p[j], p[k] );
            }
        }
    }
    
    
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
