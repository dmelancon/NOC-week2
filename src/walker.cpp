//
//  walker.cpp
//  week2
//
//  Created by Dan on 2/7/14.
//
//

#include "walker.h"
Walker::Walker(float x, float y, float m) {
    mass = m;
    loc.set(x, y);
    vel.set(ofRandom(-1.0,1.0),ofRandom(-1.0,1.0));
    accel.set(0,0);
    r = ofRandom(255);
   g = ofRandom(255);
   b = ofRandom(255);
    lifespan = 0;
}
void Walker::display(){
//    if (lifespan <100){
    ofSetColor(255,ofMap(mass,0,400,255,200));
    ofEllipse(loc.x, loc.y, mass*.5,mass*.5);
//    }
}
void Walker::update(){
//    if(lifespan <100){
    vel+=accel;
    loc +=vel;
    accel.set(0,0);
//    lifespan ++;
//    mass-= .1;
//    }
}
void Walker::checkEdges(){
        if (loc.y >= ofGetHeight()) {
            vel.y *= -.89;
            loc.y = ofGetHeight()-(mass/4);
            
        
    }
    if (loc.y < 0) {
        vel.y *= -1;
        loc.y = 0;
        
    }
    if (loc.x > ofGetWidth()) {
        vel.x *= -1;
        loc.x = ofGetWidth();
        
    }
    if (loc.x < 0) {
        vel.x *= -1;
        loc.x = 0;
        
    }

    

}

void Walker::applyForce(ofVec2f force){
    force /= mass;
    accel +=force;

    
}

