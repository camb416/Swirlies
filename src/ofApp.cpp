#include "ofApp.h"

float t;
float dt;
float r;

vector<Boid*> boids;
int numBoids;


//--------------------------------------------------------------
void ofApp::setup(){
    t = 0;
    dt = 0.3f;
    
    
    generateBoids();
    
 
    
    gui.setup(); // most of the time you don't need a name
    gui.add(maxAccel.setup( "max accel", 0.5f, 0.0f, 2.0f ));
    

}

void ofApp::generateBoids(){
    boids.clear();
    numBoids = 4096;
    for(int i=0;i<numBoids;i++){
        Boid * b = new Boid();
        b->setup();
        boids.push_back(b);
        
    }
    doSetup = false;
    ofSetBackgroundAuto(false);
}

//--------------------------------------------------------------
void ofApp::update(){
    t += dt;
    
    
    
    
    for(int i=0;i<numBoids;i++){
        Boid * b = boids.at(i);
        b->update(maxAccel);
    }
    
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofEnableAlphaBlending();
    ofSetColor(255,255,255,64);
    
    ofRect(0,0,ofGetWidth(),ofGetHeight());
    
    ofSetColor(0);
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2,ofGetHeight()/2);
    //ofRotate(t);
    for(int i=0;i<numBoids;i++){
        Boid * b = boids.at(i);
        b->draw();
    }
    ofPopMatrix();
    gui.draw();
    
    if(doSetup) generateBoids();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    //numBoids = 0;
    //boids.clear();
    doSetup = true;
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
