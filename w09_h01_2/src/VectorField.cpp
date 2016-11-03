//
//  VectorField.cpp
//  vectorfield_cam_gui
//
//  Created by TAO WEI on 11/2/16.
//
//

#include "VectorField.hpp"

void VectorField::setup(int _w, int _h, int  _res){
    width = _w;
    height = _h;
    res = _res; // passing in 20, so the space between each dot is 20 pixels
    vid.initGrabber(width,height,true);
    
    
    cols = width / res;
    rows = height / res;
    
    for(int x = 0; x < cols; x++){
        
        vector<ofPoint> column;
        
        column.resize(rows);
        table.push_back(column);
        
        for(int y = 0; y < rows; y++){
            //note that table[x] is a 1D array and table[x][y] is an ofPoint
            table[x][y] = ofPoint(5,5); //this is the vector field!//
        }
    }
}

void VectorField::seedField(float _time){
    vid.update();
    
    for (int x = 0; x < table.size(); x++) {
        for (int y = 0; y < table[x].size(); y++) {
            //get pixel color
            int i = (y*res*width+x*res)*3;
            int r = vid.getPixels()[i+0];
            int g = vid.getPixels()[i+1];
            int b = vid.getPixels()[i+2];
            
            //calculate brightness
            float br = (r+b+g) / 765.0;
            //            brightness=br;
            //            return brightness;
            
            //            //use HSB color
            //            ofSetColor(ofColor::fromHsb(br*255,255,255));
            
            //calculate sine and cosine of brightness
            float noise = ofMap( ofNoise(x*0.05, y*0.05, _time*0.1), 0, 1, 0, TWO_PI);
//            co = cos(br*noise);
//            si = sin(br*noise);
            //            ofLine(x-5*co, y-5*si, x+5*co, y+5*si);
            
//            table[x][y]=ofPoint(x*res+5*co,y*res+5*si);
            table[x][y] = ofPoint( cos(br*noise), sin(br*noise) );
            
            
            
        }
    }
}



void VectorField::draw(int _res){
    res=_res;
    for (int x = 0; x < table.size(); x++) {
        for (int y = 0; y < table[x].size(); y++) {
            ofPushMatrix();
            ofTranslate(x*res, y*res); //assume your screen width is 1000 and res is 20, then cols = 1000/20 = 50 ==> so that means there will be 50 dots. so to get to the pixel you want to draw at you have to multiply back ==>50*res = 1000
            
            
            //get pixel color
            int i = (y*res*width+x*res)*3;
            int r = vid.getPixels()[i+0];
            int g = vid.getPixels()[i+1];
            int b = vid.getPixels()[i+2];
            
            //calculate brightness
            float br = (r+b+g) / 765.0;
            //            brightness=br;
            //            return brightness;
            
            //use HSB color
            ofSetColor(ofColor::fromHsb(br*255,255,255));
            
            ofLine(ofPoint(0,0), table[x][y]);
            ofPopMatrix();
        }
    }
}

ofPoint VectorField::getForce(ofPoint _pos){
    _pos /= res;
    
    int x = ofClamp(int(_pos.x),0, cols-1);
    int y = ofClamp(int(_pos.y),0, rows-1);
    
    return table[x][y];
}

//void VectorField::update(){
//    for (int x = 0; x < table.size(); x++) {
//        for (int y = 0; y < table[x].size(); y++) {
//            table[x][y] *= 0.5; //try setting to 0.1 and seeing the effects this has on the particles
//        }
//    }
//}

