// The sample model.  You should build a file
// very similar to this for when you make your model.
#include "modelerview.h"
#include "modelerapp.h"
#include "modelerdraw.h"
#include <FL/gl.h>
#include <math.h>

#include "modelerglobals.h"

// To make a SampleModel, we inherit off of ModelerView
class SampleModel : public ModelerView 
{
public:
    SampleModel(int x, int y, int w, int h, char *label) 
        : ModelerView(x,y,w,h,label) { }

    virtual void draw();
};

// We need to make a creator function, mostly because of
// nasty API stuff that we'd rather stay away from.
ModelerView* createSampleModel(int x, int y, int w, int h, char *label)
{ 
    return new SampleModel(x,y,w,h,label); 
}

// We are going to override (is that the right word?) the draw()
// method of ModelerView to draw out SampleModel
void SampleModel::draw()
{
    // This call takes care of a lot of the nasty projection 
    // matrix stuff.  Unless you want to fudge directly with the 
	// projection matrix, don't bother with this ...
    ModelerView::draw();

	// draw the floor
	setAmbientColor(.1f, .1f, .1f);
	setDiffuseColor(COLOR_RED);
	glPushMatrix();
	glTranslated(-5, 0, -5);
	drawBox(10, 0.01f, 10);
	glPopMatrix();

	// draw the sample model
	setAmbientColor(.1f, .1f, .1f);
	setDiffuseColor(COLOR_GREEN);
	glPushMatrix();
	glTranslated(VAL(XPOS), VAL(YPOS), VAL(ZPOS));


	//body
	glPushMatrix();
	glTranslated(-0.5, 2.25, -0.5);
	glScaled(1, 1.5, 1);
	drawBox(1, 1, 1);
	glPopMatrix();

	//head
	glPushMatrix();
	glTranslated(0, 3.75, 0);
	glScaled(0.5, 0.5, 0.5);
	glRotated(-90, 1.0, 0.0, 0.0);
	drawCylinder(1, 1, 1);
	glPopMatrix();

	//rightArm
	//shoulder
	glPushMatrix();
	glTranslated(-0.75, 3.5, 0);
	drawSphere(0.25);
	//uArm
	glPushMatrix();
	glTranslated(-0.25, -0.75, -0.25);
	glScaled(0.5, 0.75, 0.5);
	drawBox(1, 1, 1);
	glPopMatrix();
	//elbow
	glTranslated(0, -0.85, 0);
	drawSphere(0.25);
	//lArm
	glTranslated(-0.25, -0.85, -0.25);
	glScaled(0.5, 0.75, 0.5);
	drawBox(1, 1, 1);
	glPopMatrix();

	//leftArm
	//shoulder
	glPushMatrix();
	glTranslated(0.75, 3.5, 0);
	drawSphere(0.25);
	//uArm
	glPushMatrix();
	glTranslated(-0.25, -0.75, -0.25);
	glScaled(0.5, 0.75, 0.5);
	drawBox(1, 1, 1);
	glPopMatrix();
	//elbow
	glTranslated(0, -0.85, 0);
	drawSphere(0.25);
	//lArm
	glTranslated(-0.25, -0.85, -0.25);
	glScaled(0.5, 0.75, 0.5);
	drawBox(1, 1, 1);
	glPopMatrix();
	
	//lowerBody
	glPushMatrix();
	glTranslated(0, 2.15, 0);
	glPushMatrix();
	glScaled(0.5, 0.1, 0.5);
	glRotated(-90, 1.0, 0.0, 0.0);
	drawCylinder(1, 1, 1);
	glPopMatrix();
	//glPopMatrix();

	//leftLeg
	//uArm
	glPushMatrix();
	//ankle
	glTranslated(-0.25, -0.1, 0);
	drawSphere(0.25);
	//lArm
	glPushMatrix();
	glTranslated(-0.25, -1.1, -0.25);
	glScaled(0.45, 1, 0.45);
	drawBox(1, 1, 1);
	glPopMatrix();
	//elbow
	glTranslated(0, -1.1, 0);
	drawSphere(0.25);
	//lArm
	glTranslated(-0.25, -0.9, -0.25);
	glScaled(0.45, 0.75, 0.45);
	drawBox(1, 1, 1);
	glPopMatrix();



	//rightLeg
	//uArm
	glPushMatrix();
	//ankle
	glTranslated(0.25, -0.1, 0);
	drawSphere(0.25);
	//lArm
	glPushMatrix();
	glTranslated(-0.25, -1.1, -0.25);
	glScaled(0.45, 1, 0.45);
	drawBox(1, 1, 1);
	glPopMatrix();
	//elbow
	glTranslated(0, -1.1, 0);
	drawSphere(0.25);
	//lArm
	glTranslated(-0.25, -0.9, -0.25);
	glScaled(0.45, 0.75, 0.45);
	drawBox(1, 1, 1);
	glPopMatrix();
	
	glPopMatrix();
	//lowerBodyEnd


	
	
	
	/*
	// draw cannon
	glPushMatrix();
	glRotated(VAL(ROTATE), 0.0, 1.0, 0.0);
	glRotated(-90, 1.0, 0.0, 0.0);
	drawCylinder(VAL(HEIGHT), 0.1, 0.1);

	glTranslated(0.0, 0.0, VAL(HEIGHT));
	drawCylinder(1, 1.0, 0.9);

	glTranslated(0.0, 0.0, 0.5);
	glRotated(90, 1.0, 0.0, 0.0);
	drawCylinder(4, 0.1, 0.2);
	glPopMatrix();
	*/

	glPopMatrix();
}

int main()
{
	// Initialize the controls
	// Constructor is ModelerControl(name, minimumvalue, maximumvalue, 
	// stepsize, defaultvalue)
    ModelerControl controls[NUMCONTROLS];
    controls[XPOS] = ModelerControl("X Position", -5, 5, 0.1f, 0);
    controls[YPOS] = ModelerControl("Y Position", 0, 5, 0.1f, 0);
    controls[ZPOS] = ModelerControl("Z Position", -5, 5, 0.1f, 0);
    controls[HEIGHT] = ModelerControl("Height", 1, 2.5, 0.1f, 1);
	controls[ROTATE] = ModelerControl("Rotate", -135, 135, 1, 0);

    ModelerApplication::Instance()->Init(&createSampleModel, controls, NUMCONTROLS);
    return ModelerApplication::Instance()->Run();
}
