#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		
    int numLines;
    int minRadius;
    int maxRadius;
    float angle;
    float distance;
    float xOffset;
    float yOffset;
    
    float alpha = ofMap(distance, minRadius, maxRadius, 50, 0);
};
