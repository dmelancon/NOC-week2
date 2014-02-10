//
//  liquid.cpp
//  week2
//
//  Created by Dan on 2/9/14.
//
//

#include "liquid.h"

Liquid::Liquid(float x_, float y_, float w_, float h_, float c_) {
    x = x_;
    y = y_;
    w = w_;
    h = h_;
    c = c_;
}
bool Liquid::contains(Walker wa){
    ofVec2f l = wa.loc;
    if (l.x > x && l.x < x + w && l.y > y && l.y < y + h) {
        return true;
    }
    else {
        return false;
    }
}
ofVec2f Liquid::drag(Walker wa) {
    float speed = wa.vel.length();
    float dragMagnitude = c * speed * speed;
    ofVec2f dragForce = wa.vel;
    dragForce *= -1;
    dragForce.normalize();
    dragForce *= dragMagnitude;
    return dragForce;
}
void Liquid::display(){
    ofSetColor(200);
    ofRect(x,y,w,h);
}