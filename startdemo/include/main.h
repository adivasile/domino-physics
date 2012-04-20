#ifndef MAIN_H
#define MAIN_H

// INCLUDES
//---------------------------------------------------------------------------

#include "common.h"

// DEFINES
//---------------------------------------------------------------------------

/* TASTE */
#define ESC	27
#define ENTER 13
#define BACKSPACE 8

/* aux */
#define PI 3.14159265
#define RAD  57.2957795
#define NONE -1

//--------------------------------
/* Proprietati fereastra */

#define APP_TITLE "Domino Engine: Demo"

// rezolutie initiala
#define DEFAULT_WIN_W	    800
#define DEFAULT_WIN_H	    600

// pozitie initiala
#define DEFAULT_WIN_POS_X	100
#define DEFAULT_WIN_POS_Y	100

#define DEFAULT_FULLSCREEN	false   // initial non-fullscreen

//--------------------------------
/* proprietati camera (observator) */

#define CAMERA_MOVE_SPEED	1

#define MOUSE_LOOK_X 1
#define MOUSE_LOOK_Y 1

//--------------------------------
/* scena */
// ROOM
#define ROOM_LENGTH 300
#define ROOM_WIDTH  100
#define ROOM_HEIGHT 50


#define PLANE_PRIMITIVE 0
#define SPHERE_PRIMITIVE 1
#define BOX_PRIMITIVE 2


//--------------------------------
/* picking */
    
// FUNCTII
//--------------------------------------------------------------------------

void output(GLfloat x, GLfloat y, GLfloat z, int i, char *format,...);
void drawHUD();
void inputHandler();
void pick(int x, int y);
void toggleFullscreen();

#define absf(x) (x<0)?(-x):(x)

void cleanup();

#endif // MAIN_H
