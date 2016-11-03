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
    
    void setup(int _width, int _height,int _depth, int  _res);
    void seedField(float _time);
    //    void setNoise(float _time = 1.0);
    ofVec3f getForceAtPosition( ofVec3f pos );

    
    void update();
    void draw(int _res);
    
   vector< vector< vector<ofVec3f> > > flowList;
    
    int width, height, depth, res;
    
//    float brightness,si,co;
    
    ofVideoGrabber vid;
};
