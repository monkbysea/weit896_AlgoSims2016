#pragma once

#include "ofMain.h"
#include "Particle.hpp"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		   
    vector<Particle> particles;
    int ptsW;
    int ptsH;
    
};
