//
//  myObj.cpp
//  moving square
//
//  Created by TAO WEI on 9/7/16.
//
//

#include "myObj.hpp"

#include "MyObj.hpp"

void MyObj::setSrc(float _x, float _y){
    
    src.set(_x, _y);
    
}

void MyObj::setDst(float _x, float _y){
    
    dst.set(_x, _y);
    
}

//Here is formulas for using power functions:
//pct = powf(num,exp); myPoss = (1-pct) * a + pct * b;

void MyObj::powUpdatePct(float _pct, float _shaper){
    
    float Powpct = powf(_pct, _shaper);
    pos = dst * Powpct + src * (1.0 - Powpct);
    
}

void MyObj::draw(){

    ofSetColor(255,0, 0);
    ofRect(pos,10,10);
    
}