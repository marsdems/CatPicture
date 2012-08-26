/**********************************************************
* Mike Marsden
* Dr. Brinkman
* CSE274
* 8.26.2012
**********************************************************/
#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class CatPictureApp : public AppBasic {
  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();

  private:
	float rValue;
	float gValue;
	float bValue;
};

void CatPictureApp::setup()
{
	//Red, green, blue values are set initially to be different
	rValue = 0.0f;
	gValue = 0.5f;
	bValue = 1.0f;
}

void CatPictureApp::mouseDown( MouseEvent event )
{
}

void CatPictureApp::update()
{
	// RGB values increment at different rates
	rValue = rValue + 0.01f;
	gValue = gValue + 0.02f;
	bValue = bValue + 0.03f;
	if (rValue > 1.0f) {
		rValue = 0.0f;
	}
	if (gValue > 1.0f) {
		gValue = 0.0f;
	}
	if (bValue > 1.0f) {
		bValue = 0.0f;
	}
}

void CatPictureApp::draw()
{
	// clear out the window with random values
	gl::clear( Color( rValue, gValue, bValue) ); 
}

CINDER_APP_BASIC( CatPictureApp, RendererGl )
