#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
        
    int i;
    int numSnowflakes;
    vector<ofPoint> points;
    vector<ofPoint> velocities;
    int numLines;
    int minRadius;
    int maxRadius;
    float angle;
    float distance;
    float xOffset;
    float yOffset;
//    float rotateAngle=0;
//    float aVelocity=0;
//    float aAcceleration = 0.001;
    
    float alpha = ofMap(distance, minRadius, maxRadius, 50, 0);
};
