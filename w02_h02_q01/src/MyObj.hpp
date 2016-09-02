//
//  MyObj.hpp
//  w02_h02_q01
//
//  Created by TAO WEI on 9/1/16.
//
//

class MyObj{
    
public:
    void draw();
    void setSrc(float _x, float _y);
    void setDst(float _x,float _y);
    
    void updatePct(float _pct);
    
    void powUpdatePct(float _pct, float _shaper);
    
private:
    
    ofPoint src, dst;
    ofPoint pos;

};