//
//  attractor.h
//  week2
//
//  Created by Dan on 2/9/14.
//
//

#ifndef week2_attractor_h
#define week2_attractor_h
#include "ofMain.h"
#include "walker.h"
class Attractor {
    
public:
   Attractor();
    ofVec2f attract(Walker);
    void display(float, float);
    float mass,G;
    ofVec2f dragOffset;
    ofVec2f location,force;
    int mouseX;
    int mouseY;
    
};



#endif
