//
//  liquid.h
//  week2
//
//  Created by Dan on 2/9/14.
//
//

#ifndef __week2__liquid__
#define __week2__liquid__

#include <iostream>
#include "ofMain.h"
#include "walker.h"
class Liquid {
    
public:
    Liquid(float, float ,float,float,float);
    bool contains(Walker);
    void display();
    ofVec2f drag(Walker);
    float x,y,w,h,c;
    
    
};
#endif /* defined(__week2__liquid__) */
