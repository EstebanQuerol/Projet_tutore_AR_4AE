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
#include <dirent.h>

//OpenGL includes
#include <GL/glew.h>
//#include <GL/glfw.h>
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
//#include <shader.hpp>
//#include <texture.hpp>

// ============================================================================
//	Constants
// ============================================================================
#define VIEW_SCALEFACTOR		0.012		// 1.0 ARToolKit unit becomes 0.025 of my OpenGL units.
#define VIEW_DISTANCE_MIN		0.1			// Objects closer to the camera than this will not be displayed.
#define VIEW_DISTANCE_MAX		100.0		// Objects further away from the camera than this will not be displayed.
#define NEXT					1
#define PREV					0

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
static double		gPatt_width_I     = 42.0;	// Per-marker, but we are using only 1 marker.
static double		gPatt_centre_I[2] = {-28.0, 160.0}; // Per-marker, but we are using only 1 marker.
static double		gPatt_trans_I[3][4];		// Per-marker, but we are using only 1 marker.
static int			gPatt_found_I = FALSE;	// Per-marker, but we are using only 1 marker.
static int			gPatt_id_I;				// Per-marker, but we are using only 1 marker.

static double		gPatt_width_N     = 42.0;	// Per-marker, but we are using only 1 marker.
static double		gPatt_centre_N[2] = {-28.0, 111.0}; // Per-marker, but we are using only 1 marker.
static double		gPatt_trans_N[3][4];		// Per-marker, but we are using only 1 marker.
static int			gPatt_found_N = FALSE;	// Per-marker, but we are using only 1 marker.
static int			gPatt_id_N;				// Per-marker, but we are using only 1 marker.

static double		gPatt_width_S     = 42.0;	// Per-marker, but we are using only 1 marker.
static double		gPatt_centre_S[2] = {-28.0, 62.0}; // Per-marker, but we are using only 1 marker.
static double		gPatt_trans_S[3][4];		// Per-marker, but we are using only 1 marker.
static int			gPatt_found_S = FALSE;	// Per-marker, but we are using only 1 marker.
static int			gPatt_id_S;				// Per-marker, but we are using only 1 marker.

static double		gPatt_width_A     = 42.0;	// Per-marker, but we are using only 1 marker.
static double		gPatt_centre_A[2] = {-28.0, 13.0}; // Per-marker, but we are using only 1 marker.
static double		gPatt_trans_A[3][4];		// Per-marker, but we are using only 1 marker.
static int			gPatt_found_A = FALSE;	// Per-marker, but we are using only 1 marker.
static int			gPatt_id_A;				// Per-marker, but we are using only 1 marker.

static double		gPatt_width_NEXT     = 50.0;	// Per-marker, but we are using only 1 marker.
static double		gPatt_centre_NEXT[2] = {0.0, 0.0}; // Per-marker, but we are using only 1 marker.
static double		gPatt_trans_NEXT[3][4];		// Per-marker, but we are using only 1 marker.
static int			gPatt_found_NEXT = FALSE;	// Per-marker, but we are using only 1 marker.
static int			gPatt_id_NEXT;				// Per-marker, but we are using only 1 marker.

static double		gPatt_width_PREV     = 50.0;	// Per-marker, but we are using only 1 marker.
static double		gPatt_centre_PREV[2] = {0.0, 0.0}; // Per-marker, but we are using only 1 marker.
static double		gPatt_trans_PREV[3][4];		// Per-marker, but we are using only 1 marker.
static int			gPatt_found_PREV = FALSE;	// Per-marker, but we are using only 1 marker.
static int			gPatt_id_PREV;				// Per-marker, but we are using only 1 marker.

static int			etat_PREV = TRUE;
static int			etat_NEXT = TRUE;

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
char * imgpath="";
char* dir="/media/PENDRIVE/site/images/images/";

char prev[250];
char courante[250];
char next[250];

//imgpath=img1;


//imgpath="../Images/Pedro_Company.jpg";
//imgpath[1]="../Images/aperture-science.jpg";
static int createImage(void);

void switchimage(int sens){

	struct dirent *lecture;
	DIR *rep;
	char* aux="";
	char* auxbis="";
	char prem[250];
	//char dern[250];
	int REFAIRE=1;

	//Récupération du premier element du dosier
	rep = opendir(dir);
	while ((REFAIRE==1) && (lecture = readdir(rep))){
		aux=lecture->d_name;
		if (aux[0]!='.') {
			strcpy(prem,dir);
			strcat(prem,aux);
//			strcpy(dern,dir);
//			strcat(dern,aux);
			REFAIRE=0;
		}
	}
//	while (lecture = readdir(rep)){
//		aux=lecture->d_name;
//	}
//	strcpy(dern,dir);
//	strcat(dern,aux);
	closedir(rep);

	REFAIRE=1;


	if (sens == PREV) {
		fprintf(stdout,"\t PREV\n");
		if ((strcmp(prev,courante))){
			strcpy(next,courante);
			strcpy(courante,prev);
			if ((strcmp(prev,prem))){
				rep = opendir(dir);
				while ((lecture = readdir(rep))) {
					if (REFAIRE==1) {
						aux=lecture->d_name;
						strcpy(prev,dir);
						strcat(prev,aux);
						if (aux[0]!='.') {
							if (strcmp(prev,courante)) {
								REFAIRE=1;
							}
							else {
								strcpy(prev,dir);
								strcat(prev,auxbis);
								REFAIRE=0;
							}
							auxbis=aux;
						}
					}
				}

				closedir(rep);
			}
			else {
				strcpy(prev,prem);
			}
		}
	}

	REFAIRE=1;

	if (sens == NEXT) {
		if ((strcmp(next,courante))){
			rep = opendir(dir);
			strcpy(prev,courante);
			strcpy(courante,next);
			while ((REFAIRE==1) && (lecture = readdir(rep))) {
				aux=lecture->d_name;
				strcpy(next,dir);
				strcat(next,aux);
				if (aux[0]!='.')
				if  (!(strcmp(next,courante))){
					if ((lecture = readdir(rep))){
						aux=lecture->d_name;
						strcpy(next,dir);
						strcat(next,aux);
					}
					REFAIRE=0;
				}
			}
			closedir(rep);
		}
	}

	REFAIRE=1;

	fprintf(stdout," prev: %s \n courante: %s \n next:%s \n",prev,courante,next);

	imgpath=courante;
	createImage();
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
			if (marker_info[j].id == gPatt_id_I) {
				if (k == -1) k = j; // First marker detected.
				else if(marker_info[j].cf > marker_info[k].cf) k = j; // Higher confidence marker detected.
			}
		}

		if (k != -1) {
			// Get the transformation between the marker and the real camera into gPatt_trans.
			arGetTransMat(&(marker_info[k]), gPatt_centre_I, gPatt_width_I, gPatt_trans_I);
			gPatt_found_I = TRUE;
		} else {
			gPatt_found_I = FALSE;
		}

		k = -1;
		for (j = 0; j < marker_num; j++) {
			if (marker_info[j].id == gPatt_id_N) {
				if (k == -1) k = j; // First marker detected.
				else if(marker_info[j].cf > marker_info[k].cf) k = j; // Higher confidence marker detected.
			}
		}

		if (k != -1) {
			// Get the transformation between the marker and the real camera into gPatt_trans.
			arGetTransMat(&(marker_info[k]), gPatt_centre_N, gPatt_width_N, gPatt_trans_N);
			gPatt_found_N = TRUE;
		} else {
			gPatt_found_N = FALSE;
		}

		k = -1;
		for (j = 0; j < marker_num; j++) {
			if (marker_info[j].id == gPatt_id_S) {
				if (k == -1) k = j; // First marker detected.
				else if(marker_info[j].cf > marker_info[k].cf) k = j; // Higher confidence marker detected.
			}
		}

		if (k != -1) {
			// Get the transformation between the marker and the real camera into gPatt_trans.
			arGetTransMat(&(marker_info[k]), gPatt_centre_S, gPatt_width_S, gPatt_trans_S);
			gPatt_found_S = TRUE;
		} else {
			gPatt_found_S = FALSE;
		}

		k = -1;
		for (j = 0; j < marker_num; j++) {
			if (marker_info[j].id == gPatt_id_A) {
				if (k == -1) k = j; // First marker detected.
				else if(marker_info[j].cf > marker_info[k].cf) k = j; // Higher confidence marker detected.
			}
		}

		if (k != -1) {
			// Get the transformation between the marker and the real camera into gPatt_trans.
			arGetTransMat(&(marker_info[k]), gPatt_centre_A, gPatt_width_A, gPatt_trans_A);
			gPatt_found_A = TRUE;
		} else {
			gPatt_found_A = FALSE;
		}

		k = -1;
		for (j = 0; j < marker_num; j++) {
			if (marker_info[j].id == gPatt_id_PREV) {
				if (k == -1) k = j; // First marker detected.
				else if(marker_info[j].cf > marker_info[k].cf) k = j; // Higher confidence marker detected.
			}
		}

		if (k != -1) {
			// Get the transformation between the marker and the real camera into gPatt_trans.
			arGetTransMat(&(marker_info[k]), gPatt_centre_PREV, gPatt_width_PREV, gPatt_trans_PREV);
			gPatt_found_PREV = TRUE;
			if (etat_PREV==FALSE) {
				etat_PREV=TRUE;
			}
		} else {
			gPatt_found_PREV = FALSE;
			if (etat_PREV==TRUE && etat_NEXT==TRUE) {
				etat_PREV=FALSE;
				switchimage(PREV);
			}
		}

		k = -1;
		for (j = 0; j < marker_num; j++) {
			if (marker_info[j].id == gPatt_id_NEXT) {
				if (k == -1) k = j; // First marker detected.
				else if(marker_info[j].cf > marker_info[k].cf) k = j; // Higher confidence marker detected.
			}
		}

		if (k != -1) {
			// Get the transformation between the marker and the real camera into gPatt_trans.
			arGetTransMat(&(marker_info[k]), gPatt_centre_NEXT, gPatt_width_NEXT, gPatt_trans_NEXT);
			gPatt_found_NEXT = TRUE;
			if (etat_NEXT==FALSE) {
				etat_NEXT=TRUE;
			}
		} else {
			gPatt_found_NEXT = FALSE;
			if (etat_NEXT==TRUE && etat_PREV==TRUE) {
				etat_NEXT=FALSE;
				switchimage(NEXT);
			}
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

	if (gPatt_found_A) {
			// Calculate the camera position relative to the marker.

			// Replace VIEW_SCALEFACTOR with 1.0 to make one drawing unit equal to 1.0 ARToolKit units (usually millimeters).
			arglCameraViewRH(gPatt_trans_A, m, VIEW_SCALEFACTOR);
			glLoadMatrixd(m);


			// All lighting and geometry to be drawn relative to the marker goes here.

			draw();


		}
	else if (gPatt_found_S) {
		// Calculate the camera position relative to the marker.

		// Replace VIEW_SCALEFACTOR with 1.0 to make one drawing unit equal to 1.0 ARToolKit units (usually millimeters).
		arglCameraViewRH(gPatt_trans_S, m, VIEW_SCALEFACTOR);
		glLoadMatrixd(m);


		// All lighting and geometry to be drawn relative to the marker goes here.

		draw();


	}
	else if (gPatt_found_N) {
		// Calculate the camera position relative to the marker.

		// Replace VIEW_SCALEFACTOR with 1.0 to make one drawing unit equal to 1.0 ARToolKit units (usually millimeters).
		arglCameraViewRH(gPatt_trans_N, m, VIEW_SCALEFACTOR);
		glLoadMatrixd(m);


		// All lighting and geometry to be drawn relative to the marker goes here.

		draw();


	}
	else if (gPatt_found_I) {
		// Calculate the camera position relative to the marker.

		// Replace VIEW_SCALEFACTOR with 1.0 to make one drawing unit equal to 1.0 ARToolKit units (usually millimeters).
		arglCameraViewRH(gPatt_trans_I, m, VIEW_SCALEFACTOR);
		glLoadMatrixd(m);


		// All lighting and geometry to be drawn relative to the marker goes here.

		draw();


	} 		// gPatt_found
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
		switchimage(NEXT);
	}
}

int main (int argc, char** argv){

	char glutGamemode[32];
	const char * cparam_name="../../lib/ARToolKit/bin/Data/camera_para.dat";

#ifdef _WIN32
		char *vconf="Data\\WDM_camera_flipV.xml";
#else
		//char *vconf="v4l2src device=/dev/video0 use-fixed-fps=false ! ffmpegcolorspace ! capsfilter caps=video/x-raw-rgb,bpp=24 ! identity name=artoolkit ! fakesink";
		char *vconf="v4l2src device=/dev/video0 use-fixed-fps=false ! videoscale ! video/x-raw-yuv,width=620,height=460 ! ffmpegcolorspace ! capsfilter caps=video/x-raw-rgb,bpp=24 ! identity name=artoolkit ! fakesink";
#endif
		const char *patt_I  = "../../Ressources/Patterns/I.pat";
		const char *patt_N  = "../../Ressources/Patterns/N.pat";
		const char *patt_S  = "../../Ressources/Patterns/S.pat";
		const char *patt_A  = "../../Ressources/Patterns/A.pat";
		const char *patt_NEXT = "../../Ressources/Patterns/NEXT.pat";
		const char *patt_PREV = "../../Ressources/Patterns/PREV.pat";
// ----------------------------------------------------------------------------

		struct dirent *lecture;
		DIR *rep;
		int REFAIRE=1;

		rep = opendir(dir);
		while ((lecture = readdir(rep))) {
			printf("%s\n", lecture->d_name);
		}
		closedir(rep);

		rep = opendir(dir);

		while ((REFAIRE==1) && (lecture = readdir(rep))){
			if (lecture->d_name[0]!='.') {
				strcpy(prev,dir);
				strcat(prev,lecture->d_name);
				strcpy(courante,dir);
				strcat(courante,lecture->d_name);
				strcpy(next,dir);
				strcat(next,lecture->d_name);

				while ((REFAIRE==1) && (lecture = readdir(rep))){
					if (lecture->d_name[0]!='.') {
						strcpy(next,dir);
						strcat(next,lecture->d_name);
						REFAIRE=0;
					}
					else {
						REFAIRE=1;
					}
				}
				REFAIRE=0;
			}
			else {
				REFAIRE=1;
			}
		}
		closedir(rep);
		fprintf(stdout,"\n prev: %s \n courante: %s \n next:%s \n",prev,courante,next);

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

	if (!setupMarker(patt_I, &gPatt_id_I)) {
		fprintf(stderr, "main(): Unable to set up AR marker.\n");
		Quit();
	}
	if (!setupMarker(patt_N, &gPatt_id_N)) {
		fprintf(stderr, "main(): Unable to set up AR marker.\n");
		Quit();
	}
	if (!setupMarker(patt_S, &gPatt_id_S)) {
		fprintf(stderr, "main(): Unable to set up AR marker.\n");
		Quit();
	}
	if (!setupMarker(patt_A, &gPatt_id_A)) {
		fprintf(stderr, "main(): Unable to set up AR marker.\n");
		Quit();
	}
	if (!setupMarker(patt_NEXT, &gPatt_id_NEXT)) {
		fprintf(stderr, "main(): Unable to set up AR marker.\n");
		Quit();
	}
	if (!setupMarker(patt_PREV, &gPatt_id_PREV)) {
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
