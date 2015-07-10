//
//  Boid.h
//  Swirlies
//
//  Created by Cameron Browning on 7/10/15.
//
//

#ifndef __Swirlies__Boid__
#define __Swirlies__Boid__

#include <stdio.h>
#include "ofMain.h"

class Boid{
public:
    float x,y;
    float vx,vy;
    float ax,ay;
    float af;
    void setup();
    void update(float _max);
    void draw();
    Boid();
    ~Boid();
    
    float angle, aangle, vangle;
    float size;
    float vf;
};

#endif /* defined(__Swirlies__Boid__) */
