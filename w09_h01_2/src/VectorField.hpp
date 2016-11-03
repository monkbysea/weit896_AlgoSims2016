//
//  VectorField.hpp
//  vectorfield_cam_gui
//
//  Created by TAO WEI on 11/2/16.
//
//

#pragma once

#include "ofMain.h"

class VectorField {
public:
    
    void setup(int _w, int _h, int  _res);
    void seedField(float _time);
    //    void setNoise(float _time = 1.0);
    ofPoint getForce(ofPoint _pos);
    
    void update();
    void draw(int _res);
    
    vector< vector<ofPoint> > table;
    
    int width, height, cols, rows, res;
    
//    float brightness,si,co;
    
    ofVideoGrabber vid;
};
