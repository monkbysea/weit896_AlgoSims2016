#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

    int numTriangles;
    int distance;
    int alpha;
    float angle;
    ofPoint Pos;
    float xOffset;
    float yOffset;
    float xOrig;
    float yOrig;
    
		
};
