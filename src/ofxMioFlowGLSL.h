#pragma once

#include "ofMain.h"
#include "FlowShader.h"

class ofxMioFlowGLSL  
{
	public:

		ofxMioFlowGLSL();

		void setup(int wI,int hI);

		void update(ofTexture& cur, bool _runReposition );

		void drawFlowGrid(const ofRectangle & rect);
		void drawFlowGridRaw(const ofRectangle & rect);
		void drawReposition(const ofRectangle & rect);

		void drawFlowGrid(int x,int y);
		void drawFlowGridRaw(int x,int y);
		void drawReposition(int x,int y);
     
		bool isSetup() { return flowIsSetup;}
	
		int getWidth()  { return width; }
		int getHeight() { return height; }

		ofTexture& getFlowBlurTexture();
		ofTexture& getFlowRawTexture();

		ofParameter<float> lambda;
		ofParameter<float> blurAmount;
		ofParameter<int>   numBlurPasses;
		ofParameter<float> displaceAmount; 
		ofParameter<float> flowScale; 

		ofFbo lastTex;  
		ofFbo fboFlow;
		ofFbo fboBlurH,fboBlurV;
		ofFbo fboRepos;

	private: 

		int width, height;  


		FlowShader flowShader;

		bool flowIsSetup;
};