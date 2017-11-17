#pragma once


#include "ofMain.h"


class ofApp: public ofBaseApp
{
public:
    void setup() override;
    void update() override;
    void draw() override;
    void processSensorData();
    void keyPressed(int key) override;

    const int minTime = 4500; // Half-second. 500 milli seconds
    const int maxTime = 9000;
    
    // An instance of the serial object. One instance is needed for each active
    // serial connection.
    ofSerial serial;

    // A buffer to store our buffered data.
    std::string buffer;
    
    // The value of the potentiometer.
    unsigned int potValue = 0;

    // The value of the first button.
    bool buttonValue_0 = false;
    
    // The value of the sensors.
    bool curSensorVal1 = false;
    bool prevSensorVal1 = false;
    bool curSensorVal2 = false;
    bool prevSensorVal2 = false;
    
    ofSoundPlayer   mySound;
    
    unsigned long int elapsedTime;
    // Are we tracking?
    bool tracking = false;
    
    // Keeps track of a list of incoming people
    // These are sensor1Val that we think.
    // Use this in a bit. 
    vector<bool> incomingPeople;
};
