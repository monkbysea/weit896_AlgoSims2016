//
//  VectorField.cpp
//  vectorfield_cam_gui
//
//  Created by TAO WEI on 11/2/16.
//
//

#include "VectorField.hpp"

void VectorField::setup(int _width, int _height, int _depth, int  _res){
    width = _width;
    height = _height;
    depth=_depth;
    res = _res; // passing in 20, so the space between each dot is 20 pixels
    vid.initGrabber(width,height,true);
    
    
    int cols = width / res;
    int rows = height / res;
    int layers= depth/res;
    
//    for(int x = 0; x < cols; x++){
//        
//        vector<ofPoint> column;
//        
//        column.resize(rows);
//        table.push_back(column);
//        
//        for(int y = 0; y < rows; y++){
//            //note that table[x] is a 1D array and table[x][y] is an ofPoint
//            table[x][y] = ofPoint(5,5); //this is the vector field!//
//        }
//    }
    for (int z = 0; z < layers; z++) {
        vector< vector<ofVec3f> > myPlaneList;
        flowList.push_back ( myPlaneList );
        
        for (int y = 0; y < rows; y++) {
            vector<ofVec3f> myList;
            flowList[z].push_back ( myList );
            
            for (int x = 0; x < cols; x++) {
                ofVec3f dir( 5, 5, 5 );
                flowList[z][y].push_back ( dir );
            }
        }
    }

}

void VectorField::seedField(float _time){
    vid.update();
    
       for( int z = 0; z < flowList.size(); z++){
        for( int y = 0; y < flowList[z].size(); y++){
            for( int x=0; x<flowList[z][y].size(); x++){
                //get pixel color
                            int i = (y*res*width+x*res)*3;
                            int r = vid.getPixels()[i+0];
                            int g = vid.getPixels()[i+1];
                            int b = vid.getPixels()[i+2];
                //
                //            //calculate brightness
                            float br = (r+b+g) / 765.0;
                
                //use HSB color
                ofSetColor(ofColor::fromHsb(br*255,255,255));
                
                //calculate sine and cosine of brightness
                float noise = ofMap( ofNoise(x*0.05, y*0.05,z*0.05, _time*0.1), 0, 1, 0, TWO_PI);
                
                flowList[z][y][x].set( ofVec3f( cos(br*noise) * 20.0, sin(br*noise) * 20.0, sin (br*noise) * 20.0 ) );
                
            }
        }
    }

}



void VectorField::draw(int _res){
    res=_res;
    for( int z = 0; z < flowList.size(); z++){
        for( int y = 0; y < flowList[z].size(); y++){
            for( int x=0; x<flowList[z][y].size(); x++){
                ofVec3f np( x*res, y*res, z*res );
                
                //get pixel color
                int i = (y*res*width+x*res)*3;
                int r = vid.getPixels()[i+0];
                int g = vid.getPixels()[i+1];
                int b = vid.getPixels()[i+2];
                //
                //            //calculate brightness
                float br = (r+b+g) / 765.0;
                
                //use HSB color
                ofSetColor(ofColor::fromHsb(br*255,255,255));
                
                ofLine ( np, np+flowList[z][y][x] );
            }
        }
    }

}

ofVec3f VectorField::getForceAtPosition( ofVec3f pos ){
    float pctX = pos.x / width;
    float pctY = pos.y / height;
    float pctZ = pos.z / depth;
    
    int cols = width / res;
    int rows = height / res;
    int layers = depth / res;
    
    int xVal = ofClamp( pctX * cols, 0, cols-1 );
    int yVal = ofClamp( pctY * rows, 0, rows-1 );
    int zVal = ofClamp( pctZ * layers, 0, layers-1 );
    
    ofVec3f newPos;
    newPos.set( flowList[zVal][yVal][xVal] );
    
    return newPos;

}

//void VectorField::update(){
//    for (int x = 0; x < table.size(); x++) {
//        for (int y = 0; y < table[x].size(); y++) {
//            table[x][y] *= 0.5; //try setting to 0.1 and seeing the effects this has on the particles
//        }
//    }
//}

