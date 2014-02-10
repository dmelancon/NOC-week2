//
//  walker.h
//  week2
//
//  Created by Dan on 2/7/14.
//
//

#ifndef __week2__walker__
#define __week2__walker__

#include <iostream>
#include "ofMain.h"

class Walker {
    
public:
    Walker(float, float ,float);
    void update();
    void display();
    void checkEdges();
    void applyForce(ofVec2f);
    ofVec2f vel;
    ofVec2f loc;
    ofVec2f accel;
    float mass;
    float r, g, b;
    int lifespan;
};


#endif /* defined(__week2__walker__) */
