/*
 * Hello_World.c
 *
 *  Created on: 17/02/2013
 *      Author: Esteban Querol
 */

/*
 *
 *
 *
 * */

// ============================================================================
//	Includes
// ============================================================================
#include <stdio.h>
#include <stdlib.h>
#ifdef __APPLE__
#  include <GLUT/glut.h>
#else
#  include <GL/glut.h>
#endif
#include <AR/config.h>
#include <AR/video.h>
#include <AR/param.h>			// arParamDisp()
#include <AR/ar.h>
#include <AR/gsub_lite.h>

// ============================================================================
//	Global variables
// ============================================================================

// Image acquisition.
static ARUint8		*gARTImage = NULL;

// Drawing.
static ARParam		gARTCparam;
static ARGL_CONTEXT_SETTINGS_REF gArglSettings = NULL;

// ============================================================================
//	Functions
// ============================================================================

/* This function is called when the window needs redrawing
* at each call we make:
* 1.Clear the screen and draw the most recent frame from the camera as a video background.
* 2.Set up the OpenGL camera projection to match the calibrated ARToolKit camera parameters.
* 3.Check whether we have any active markers, and if so, position the OpenGL camera view for each one to place the coordinate system origin onto the marker.
* 4.Draw objects on top of any active markers (using the OpenGL camera).
*/
void Display(void){
	//Screen clearing
	//Select the right buffer for the pixels
	glDrawBuffer(GL_BACK);//Color buffer for each pixel
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);//sets the bitplane with new color buffer
	//We set last image captured as background
	arglDispImage(gARTImage, &gARTCparam, 1.0, gArglSettings);
	gARTImage = NULL;
}

int main(int argc, char** argv)
{
	while(1){
//
	}
}
