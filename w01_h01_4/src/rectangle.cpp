//
//  rectangle.cpp
//  xeno shapes
//
//  Created by TAO WEI on 9/7/16.
//
//

#include "rectangle.hpp"

#include "rectangle.hpp"


rectangle:: rectangle() {
    }

void rectangle::draw(float R,float G,float B){
    
    ofFill();
    
    ofSetRectMode(OF_RECTMODE_CENTER);
    
    ofSetColor( R,  G,  B);
    
    ofDrawRectangle(pos.x, pos.y, 40, 40);
}

void rectangle::xenoToPoint(float catchX, float catchY,float catchUpSpeed){
    //Xeno formula:
    //myPos = (1-pct) * myPos + pct * targetPos
    
    pos.x = catchUpSpeed * catchX + (1-catchUpSpeed) *pos.x;
    pos.y = catchUpSpeed * catchY + (1-catchUpSpeed) *pos.y;
    
}