//
//  Boid.cpp
//  Swirlies
//
//  Created by Cameron Browning on 7/10/15.
//
//

#include "Boid.h"

void Boid::setup(){
    //os(ofRandom(TWO_PI))*ofRandom(50.0f);
    //y = sin(ofRandom(TWO_PI))*ofRandom(50.0f);
    float randAngle =ofRandom(TWO_PI);
    float randRadius = ofRandom(100.0f);
    x = cos(randAngle)*randRadius;
    y = sin(randAngle)*randRadius;
    ax = ay = 0.0f;
    vx = ofRandom(2.0f)-1.0f;
    vy = ofRandom(2.0f)-1.0f;
    size = ofRandom(4);
    
}
void Boid::update(float _max){

    af = MIN(MAX(-1000.0f/MIN(ofDistSquared(x, y, 0, 0),5.0f),-_max),_max);
    angle = atan2(y,x);
    ay = sin(angle)*af;
    ax = cos(angle)*af;
    aangle =atan2(ay,ax);
    
    
    vx += ax*0.9f;
    vy += ay*0.9f;
    
    //vx = MAX(MIN(vx,5.0f),-5.0f);
    //vy = MAX(MIN(vy,5.0f),-5.0f);
    
    vangle = atan2(vy,vx);
    
    vf = sqrt(vx*vx+vy*vy);
    /*
    float maxvf = 3.0f;
    if(vf>maxvf){
        float divf = maxvf/vf;
        vx*=divf;
        vy*=divf;
    }
    */
    x+= vx*0.9f;
    y+= vy*0.9f;

}
void Boid::draw(){
    ofPushMatrix();
    ofTranslate(x,y);
    ofRotate(vangle*180.0f/PI);
    ofRect(-size/2,-size/2,size,size);
    ofPopMatrix();
}
Boid::Boid(){
    // empty constructor
      ofLog() << "creating boid";
}
Boid::~Boid(){
    ofLog() << "destroying boid";
    // empty destructor
}