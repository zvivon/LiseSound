#include "ofApp.h"


void ofApp::setup()
{
    ofBackground(ofColor::black);
    ////////// Runthis on terminal ls -ls /dev/cu* - This command lets you see all the serial devices on your computer.
    ////////// Copy the name of your ardunio in here, like the red port downhere
    serial.setup("/dev/cu.usbmodem1411", 9600); // MAC
    //serial.setup("/dev/ttyACM0", 9600); // Raspberry Pi
    mySound.load("LISE_VO_DEADHORSE_2.wav");
    mySound.setVolume(0.5f);
    buttonValue_0 = true;
}

void ofApp::update()
{
    // As long as there is serial data available to read, repeat.
    while (serial.available() > 0)
    {
        // Read the byte.
        char b = serial.readByte();
        
        // End of line character.
        if (b == '\n')
        {
            // Split the buffer on the commas.
            std::vector<std::string> tokens = ofSplitString(buffer, ",");
            
            // The number of tokens in our packet is 3, here we check to make
            // sure that our packet is correctly formed.
            if (tokens.size() == 3)
            {
                buttonValue_0 = ofToBool(tokens[0]);
                curSensorVal1 = ofToBool(tokens[1]); // Since we reversed the sensors.
                curSensorVal2 = ofToBool(tokens[2]);
                
                // Process sensor data.
            }
            buffer = "";
        }
        else
        {
            // If it's not the line feed character, add it to the buffer.
            buffer += b;
        }
    }
}

void ofApp::draw()
{
    ofSetColor(ofColor::green);
    ofFill();
}

void ofApp::processSensorData() {
    // Is button pressed?
    if (buttonValue_0 != true)
    {
        // Is sound playing?
        if (!mySound.isPlaying()) {
            mySound.play();
            // Loop the sound.
            mySound.setLoop(true);
        } else {
            mySound.stop();
            // Stop looping the sound.
            mySound.setLoop(false);
        }
    }
    
    // Do something with sensor 1 value.
    if (curSensorVal1 == true && tracking == false) {
        // Start tracking.
        
        prevSensorVal1 = curSensorVal1;
        tracking = true;
        ofResetElapsedTimeCounter();
        
        cout << "Start tracking" << endl;
    }
    
    // Do something with sensor 2 value.
    if (curSensorVal2 == true && prevSensorVal1 == true) {
        elapsedTime = ofGetElapsedTimeMillis();
        if (elapsedTime < minTime) {
            // Unexpected. Somebody is trying to exit. 
        } else if (elapsedTime < maxTime) {
            // Play the sound since somebody has entered.
            if (!mySound.isPlaying()) {
                mySound.play();
            }
            
            // Print this.
            prevSensorVal1 = false;
            // Stop tracking.
            tracking = false;
            
            
            cout << "Somebody entered" << endl;
            cout << "Elapsed Time is " << elapsedTime << endl;
        } else {
         
            
        }
    }
}

void ofApp::keyPressed(int key) {
    // Restart tracking.
    if (key == 49) {
        tracking = false;
    }
}

