//
//  attractor.cpp
//  week2
//
//  Created by Dan on 2/9/14.
//
//
#include "ofBaseApp.h"
#include "attractor.h"
#include "walker.h"
Attractor::Attractor() {
        location.set(ofGetWidth()/2, ofGetHeight()/2);
        mass = 30;
        G = 1;
        }
    
ofVec2f Attractor::attract(Walker w) {
        force.set(location);
        force -= w.loc;                                // Calculate direction of force
        float d = force.length();                           // Distance between objects
        d = ofClamp(d, 5.0, 25.0);                          // Limiting the distance to eliminate "extreme" results for very close or very far objects
        force.normalize();                                  // Normalize vector (distance doesn't matter here, we just want this vector for direction)
        float strength = (G * mass * w.mass) / (d * d);     // Calculate gravitional force magnitude
        force *= strength;                                  // Get force vector --> magnitude * direction
        return force;
    }
void Attractor::display(float x, float y){
location.set(x,y);
}