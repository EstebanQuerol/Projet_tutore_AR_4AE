/*
 * playground.cpp
 *
 *  Created on: 23/03/2013
 *      Author: The augmented reality team
 */

//System includes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//OpenGL includes
#include <GL/glew.h>
#include <GL/glfw.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform.hpp>
using namespace glm;
#include "SOIL.h"

//AR includes
#include <GL/glut.h>
#include <AR/config.h>
#include <AR/video.h>
#include <AR/param.h>			// arParamDisp()
#include <AR/ar.h>
#include <AR/gsub_lite.h>

//Own functions includes
#include <shader.hpp>
#include <texture.hpp>

// ============================================================================
//	Constants
// ============================================================================
#define VIEW_SCALEFACTOR		0.012		// 1.0 ARToolKit unit becomes 0.025 of my OpenGL units.
#define VIEW_DISTANCE_MIN		0.1			// Objects closer to the camera than this will not be displayed.
#define VIEW_DISTANCE_MAX		100.0		// Objects further away from the camera than this will not be displayed.

// ============================================================================
//	Global variables
// ============================================================================

// Preferences.
static int prefWindowed = TRUE;
static int prefWidth = 640;					// Fullscreen mode width.
static int prefHeight = 480;				// Fullscreen mode height.
static int prefDepth = 32;					// Fullscreen mode bit depth.
static int prefRefresh = 0;					// Fullscreen mode refresh rate. Set to 0 to use default rate.

// Drawing
static ARParam		gARTCparam;//camera parameters structure
static ARGL_CONTEXT_SETTINGS_REF gArglSettings = NULL;
GLuint texture[1];

// Image acquisition.
static ARUint8		*gARTImage = NULL;

// Transformation matrix retrieval.
static double		gPatt_width     = 80.0;	// Per-marker, but we are using only 1 marker.
static double		gPatt_centre[2] = {0.0, 0.0}; // Per-marker, but we are using only 1 marker.
static double		gPatt_trans[3][4];		// Per-marker, but we are using only 1 marker.
static int			gPatt_found = FALSE;	// Per-marker, but we are using only 1 marker.
static int			gPatt_id;				// Per-marker, but we are using only 1 marker.

// Marker detection.
static int			gARTThreshhold = 100;
static long			gCallCountMarkerDetect = 0;

// OpenGL3.3


GLuint programID;
GLuint MatrixID;
GLuint Texture;
GLuint TextureID;
GLuint VertexArrayID;
glm::mat4 MVP;

GLuint vertexbuffer;
GLuint uvbuffer;

//Image path
//For now paths are static but looking to do it dynamic in the future
char * imgpath="../Images/Pedro_Company.jpg";;
char * img1="../Images/Pedro_Company.jpg";
char * img2="../Images/aperture-science.bmp";
//imgpath=img1;


//imgpath="../Images/Pedro_Company.jpg";
//imgpath[1]="../Images/aperture-science.jpg";
static int createImage(void);

void switchimage(void){
	if (imgpath==img1){
		imgpath=img2;
		createImage();
	}
	else{
		imgpath=img1;
		createImage();
	}
}
/******************************************/
/*Functions*/
/******************************************/

static int setupCamera(const char *cparam_name, char *vconf, ARParam *cparam)
{
    ARParam			wparam;
	int				xsize, ysize;

    // Open the video path.
    if (arVideoOpen(vconf) < 0) {
    	fprintf(stderr, "setupCamera(): Unable to open connection to camera.\n");
    	return (FALSE);
	}

    // Find the size of the window.
    if (arVideoInqSize(&xsize, &ysize) < 0) return (FALSE);
    fprintf(stdout, "Camera image size (x,y) = (%d,%d)\n", xsize, ysize);

	// Load the camera parameters, resize for the window and init.
    if (arParamLoad(cparam_name, 1, &wparam) < 0) {
		fprintf(stderr, "setupCamera(): Error loading parameter file %s for camera.\n", cparam_name);
        return (FALSE);
    }
    arParamChangeSize(&wparam, xsize, ysize, cparam);
    fprintf(stdout, "*** Camera Parameter ***\n");
    arParamDisp(cparam);

    arInitCparam(cparam);

	if (arVideoCapStart() != 0) {
    	fprintf(stderr, "setupCamera(): Unable to begin camera data capture.\n");
		return (FALSE);
	}

	return (TRUE);
}

static int setupMarker(const char *patt_name, int *patt_id)
{
	// Loading only 1 pattern in this example.
	if ((*patt_id = arLoadPatt(patt_name)) < 0) {
		fprintf(stderr, "setupMarker(): pattern load error !!\n");
		return (FALSE);
	}

	return (TRUE);
}
static int createImage(void){

	// Initialize GLEW(for mipmaps)
	glewExperimental = true; // Needed for core profile
	if (glewInit() != GLEW_OK) {
		fprintf(stderr, "Failed to initialize GLEW\n");
		return -1;
	}

	glEnable(GL_TEXTURE_2D);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);
	// Accept fragment if it closer to the camera than the former one
	glDepthFunc(GL_LESS);

   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
   glGenerateMipmap(GL_TEXTURE_2D);
   glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_CLAMP);
   glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_CLAMP);

   glGenTextures(1,&texture[0]);//Memory allocation
   /* load an image file directly as a new OpenGL texture */
	texture[0] = SOIL_load_OGL_texture
		(
		imgpath,
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS
		);
	printf("texture found\n");

	if(texture[0] == 0)
		fprintf(stderr, "no texture found\n");

		return 0;


}
static void draw(void){



	glClear(GL_DEPTH_BUFFER_BIT);
	glBindTexture(GL_TEXTURE_2D, texture[0]);

	glBegin (GL_QUADS);
			   glTexCoord2f(0.0f, 0.0f);
			   glVertex3f(0.0f, 0.0f,  0.0f);  // Bottom Left Of The Texture and Quad


			   glTexCoord2f(1.0f, 0.0f);
			   glVertex3f(1.5f, 0.0f,  0.0f);  // Bottom Left Of The Texture and Quad

			   glTexCoord2f(1.0f, 1.0f);
			   glVertex3f(1.5f, 2.0f,  0.0f);  // Bottom Left Of The Texture and Quad


			   glTexCoord2f(0.0f, 1.0f);
			   glVertex3f(0.0f, 2.0f,  0.0f);  // Bottom Left Of The Texture and Quad

	glEnd();

}

static void Quit(void)
{
	arglCleanup(gArglSettings);
	arVideoCapStop();
	arVideoClose();
	// Cleanup VBO
	glDeleteBuffers(1, &vertexbuffer);
	//glDeleteBuffers(1, &colorbuffer);
	glDeleteBuffers(1, &uvbuffer);
	glDeleteProgram(programID);
	glDeleteVertexArrays(1, &VertexArrayID);
	// Close OpenGL window and terminate GLFW
	glDeleteTextures(1,&texture[0]);
	exit(0);
}

static void Idle(void)
{
	static int ms_prev;
	int ms;
	float s_elapsed;
	ARUint8 *image;

	ARMarkerInfo    *marker_info;					// Pointer to array holding the details of detected markers.
    int             marker_num;						// Count of number of markers detected.
    int             j, k;

	// Find out how long since Idle() last ran.
	ms = glutGet(GLUT_ELAPSED_TIME);
	s_elapsed = (float)(ms - ms_prev) * 0.001;
	if (s_elapsed < 0.01f) return; // Don't update more often than 100 Hz.
	ms_prev = ms;

	// Update drawing.
	//DrawCubeUpdate(s_elapsed);

	// Grab a video frame.
	if ((image = arVideoGetImage()) != NULL) {
		gARTImage = image;	// Save the fetched image.

		gCallCountMarkerDetect++; // Increment ARToolKit FPS counter.

		// Detect the markers in the video frame.
		if (arDetectMarker(gARTImage, gARTThreshhold, &marker_info, &marker_num) < 0) {
			exit(-1);
		}

		// Check through the marker_info array for highest confidence
		// visible marker matching our preferred pattern.
		k = -1;
		for (j = 0; j < marker_num; j++) {
			if (marker_info[j].id == gPatt_id) {
				if (k == -1) k = j; // First marker detected.
				else if(marker_info[j].cf > marker_info[k].cf) k = j; // Higher confidence marker detected.
			}
		}

		if (k != -1) {
			// Get the transformation between the marker and the real camera into gPatt_trans.
			arGetTransMat(&(marker_info[k]), gPatt_centre, gPatt_width, gPatt_trans);
			gPatt_found = TRUE;
		} else {
			gPatt_found = FALSE;
		}

		// Tell GLUT the display has changed.
		glutPostRedisplay();
	}
}

//
//	This function is called on events when the visibility of the
//	GLUT window changes (including when it first becomes visible).
//
static void Visibility(int visible)
{
	if (visible == GLUT_VISIBLE) {
		glutIdleFunc(Idle);
	} else {
		glutIdleFunc(NULL);
	}
}
//
//	This function is called when the
//	GLUT window is resized.
//
static void Reshape(int w, int h)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glViewport(0, 0, (GLsizei) w, (GLsizei) h);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// Call through to anyone else who needs to know about window sizing here.
}


static void Display(void)
{
    GLdouble p[16];
	GLdouble m[16];

	// Select correct buffer for this context.
	glDrawBuffer(GL_BACK);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear the buffers for new frame.

	arglDispImage(gARTImage, &gARTCparam, 1.0, gArglSettings);	// zoom = 1.0.
	arVideoCapNext();
	gARTImage = NULL; // Image data is no longer valid after calling arVideoCapNext().




	// Projection transformation.
	arglCameraFrustumRH(&gARTCparam, VIEW_DISTANCE_MIN, VIEW_DISTANCE_MAX, p);
	glMatrixMode(GL_PROJECTION);
	glLoadMatrixd(p);
	glMatrixMode(GL_MODELVIEW);

	// Viewing transformation.
	glLoadIdentity();
	// Lighting and geometry that moves with the camera should go here.
	// (I.e. must be specified before viewing transformations.)
	//none

	if (gPatt_found) {
		// Calculate the camera position relative to the marker.

		// Replace VIEW_SCALEFACTOR with 1.0 to make one drawing unit equal to 1.0 ARToolKit units (usually millimeters).
		arglCameraViewRH(gPatt_trans, m, VIEW_SCALEFACTOR);
		glLoadMatrixd(m);


		// All lighting and geometry to be drawn relative to the marker goes here.

		draw();


	}// gPatt_found
	// Setup argl library for current context.

	// Any 2D overlays go here.
	//none

	glutSwapBuffers();
	//////////////////////////////////////////////////////////////////////
	/// Close Routines ///////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////




}

void keycheck(unsigned char in_key,int mouse_x,int mouse_y){

	// Check if the ESC key was pressed
	if(in_key==27){
		Quit();
	}
	if(in_key==' '){

	}
	if(in_key=='n'){
		switchimage();
	}
}

int main (int argc, char** argv){

	char glutGamemode[32];
	const char * cparam_name="../../lib/ARToolKit/bin/Data/camera_para.dat";

#ifdef _WIN32
		char *vconf="Data\\WDM_camera_flipV.xml";
#else
		char *vconf="v4l2src device=/dev/video0 use-fixed-fps=false ! ffmpegcolorspace ! capsfilter caps=video/x-raw-rgb,bpp=24 ! identity name=artoolkit ! fakesink";
#endif
		const char *patt_name  = "../../lib/ARToolKit/bin/Data/patt.hiro";
// ----------------------------------------------------------------------------

// Library inits.


	glutInit(&argc, argv);

//setup Camera, obtention des paramètres et capture des images
	if (setupCamera(cparam_name,vconf,&gARTCparam) < 0) {
		fprintf(stderr, "Unable to setup camera.\n");
		exit (-1);
	}


// Set up GL context(s) for OpenGL to draw into.
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	if (!prefWindowed) {
		if (prefRefresh) sprintf(glutGamemode, "%ix%i:%i@%i", prefWidth, prefHeight, prefDepth, prefRefresh);
		else sprintf(glutGamemode, "%ix%i:%i", prefWidth, prefHeight, prefDepth);
		glutGameModeString(glutGamemode);
		glutEnterGameMode();
	} else {
		glutInitWindowSize(prefWidth, prefHeight);
		glutCreateWindow(argv[0]);
		glutSetWindowTitle ("Playground");
	}


	// Setup argl library for current context.
	if ((gArglSettings = arglSetupForCurrentContext()) == NULL) {
		fprintf(stderr, "main(): arglSetupForCurrentContext() returned error.\n");
		exit(-1);
	}
	//debugReportMode(gArglSettings);
	glEnable(GL_DEPTH_TEST);
	arUtilTimerReset();

	if (!setupMarker(patt_name, &gPatt_id)) {
		fprintf(stderr, "main(): Unable to set up AR marker.\n");
		Quit();
	}



    createImage();


	glutDisplayFunc(Display);
	glutReshapeFunc(Reshape);
	glutVisibilityFunc(Visibility);
	glutKeyboardFunc(keycheck);
	glutMainLoop();


	return 0;
}


