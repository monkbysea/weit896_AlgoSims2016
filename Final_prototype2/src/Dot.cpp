//
//  Dot.cpp
//  final
//
//  Created by TAO WEI on 12/6/16.
//
//

#include "Dot.hpp"
void Dot::setup(float _x, float _y) {
    pos.x=_x;
    pos.y=_y;
}

void Dot::draw(float _radius) {
    ofCircle(pos.x+_radius,pos.y+_radius,_radius);
}

//void Dot::update() {
//}