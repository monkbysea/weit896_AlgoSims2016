//
//  rectangle.hpp
//  xeno shapes
//
//  Created by TAO WEI on 9/7/16.
//
//

#pragma once

#include "ofMain.h"


class rectangle {
    
public:
    
    rectangle();
    void draw(float R, float G, float B);
    
    void xenoToPoint(float catchX, float catchY,float catchUpSpeed);
    
    ofPoint pos;
    
       
};