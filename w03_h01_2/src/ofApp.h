#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    float xEye, yEye;
    float xEye2, yEye2;
    float xNose,yNose;
    float xMouth,yMouth;
    float angle = 0.0;
    float scalar = 0;
    float speed = 0.05;
    float radius;
    float alpha;
    ofColor colors[5];

		
};
