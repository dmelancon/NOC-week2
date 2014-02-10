#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
        ofBackground(0);
    ofEnableAlphaBlending();
      ofSetBackgroundAuto(true);
    liquid.push_back( new Liquid(0, ofGetHeight()/2, ofGetWidth(), ofGetHeight()/6, -0.03));
    liquid.push_back( new Liquid(0, ofGetHeight()/4, ofGetWidth(),ofGetHeight()/6, 0.03));
//    for (int i=0;i<1;i++) {
//        w.push_back(Walker(ofRandom(0,ofGetWidth()),0,ofRandom(20, 60)));
//    }
}


//--------------------------------------------------------------
void testApp::update(){
    
    for (int i = 0; i < w.size(); i++) {
 
//            wind.set(ofMap(mouseX,0,ofGetWidth(),-5,5),ofMap(mouseY,0,ofGetHeight(),-5,5));
//            w[i].applyForce(wind);
        ofVec2f mouse = a.attract(w[i]);
        a.display(mouseX,mouseY);
        w[i].applyForce(mouse);


        gravity.set(0, 0.03*w[i].mass);
        w[i].applyForce(gravity);
        w[i].checkEdges();
        for (int p = 0;  p <w.size(); p++){
            if(i != p){
            float dis = w[i].loc.distance(w[p].loc);
            if(dis<=((w[i].mass/4) + (w[p].mass/4 ))){
                w[i].mass = w[i].mass + w[p].mass;
//                w[i].loc = (4*w[i].loc+w[p].loc)/5;
                w.erase(w.begin()+p);
            }
            }
        }
            if (w[i].mass>= 400){
                
                for(int r = 0; r<300; r++){
                    w.push_back(Walker(ofRandom((w[i].loc.x-w[i].mass/4),(w[i].loc.x+w[i].mass/4) ),ofRandom((w[i].loc.y-w[i].mass/4),(w[i].loc.y+w[i].mass/4)), ofRandom(3)));
                                }
                                w.erase(w.begin()+i);
        }
        
      w[i].update();
       
}
    
}

//--------------------------------------------------------------
void testApp::draw(){

    if (w.size()<100 ){
       
                  w.push_back(Walker(ofRandom(0,ofGetWidth()),0,ofRandom(10)));
              

    }
    
    
    

            for (int i = 0; i < w.size(); i++) {
            
            for(int l = 0; l<liquid.size(); l++){
            if (liquid[l]->contains(w[i])) {
                ofVec2f dragForce = liquid[l]->drag(w[i]);
               w[i].applyForce(dragForce);
            }else{
                drag.set(w[i].vel);
                drag *= -1;
                speed = w[i].vel.length();
                float c = .005;
                drag *= c*speed*speed;
                w[i].applyForce(drag);
            }
            }
            w[i].display();
            
        }
    

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
    
    }

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
    

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}
