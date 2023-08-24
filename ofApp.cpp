#include "ofApp.h"	

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(30);
	ofSetWindowTitle("openFrameworks");

	ofBackground(39);
	ofSetLineWidth(5);
	ofEnableDepthTest();
	
	ofSetCircleResolution(60);
}


//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.begin();

	ofNoFill();
	ofSetColor(255);
	ofDrawCircle(glm::vec2(), 200);

	ofRotateX(25);

	auto radius = 230;
	auto deg_start = ofGetFrameNum() * 5;

	for (int deg = deg_start; deg < deg_start + 90; deg++) {

		ofFill();
		ofSetColor(255, ofMap(deg, deg_start, deg_start + 90, 0, 255));

		ofDrawSphere(radius * cos(deg * DEG_TO_RAD), 0, radius * sin(deg * DEG_TO_RAD), 10);
	}

	this->cam.end();
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}