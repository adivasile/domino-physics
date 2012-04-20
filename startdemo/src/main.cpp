#include "main.h"

#include "CSceneNode.h"
#include "frames.h"

#include "Test1.h"

// VARIABILE GLOBALE
//--------------------------------------------------------------------------

//--------------------------------
/* Proprietati fereastra */

GLint win_w = DEFAULT_WIN_W, win_h = DEFAULT_WIN_H, win_x = DEFAULT_WIN_POS_X, win_y = DEFAULT_WIN_POS_Y;

GLfloat aspect = win_w / win_h;

// pentru fullscreen toogle
GLint old_win_w = win_w, old_win_h = win_h,old_win_x = win_x, old_win_y = win_y;

GLboolean fullscreen = DEFAULT_FULLSCREEN;

//--------------------------------
/* INPUT */
GLboolean keys[256], specialKeys[256], typing;
char inputLabel[256], inputText[256];

// mouse
GLint mouseX0, mouseY0,
mouseClickedX, mouseClickedY,
mouseRightClickedX, mouseRightClickedY, mouseRotX, mouseRotY;
GLfloat mouseMoveX, mouseMoveY, mouseAngleX, mouseAngleY;
GLboolean mouseMoved, mouseClicked, mouseRightClicked, mouseMiddleClicked;

// picked object
CSceneNode* selObject;
int selIndex;

Test* test;

//--------------------------------
/* flags */

int testNum = 0;


GLboolean paused;

// FUNCTII
//--------------------------------------------------------------------------

// functie de proiectie/window resize
void reshape(int w, int h) {
    win_w = w;
    win_h = h;
    // recalculare aspect ratio ( Width/ Height )
    aspect = (GLfloat) win_w / (GLfloat) win_h;

    // Main Window
    glViewport(0, 0, (GLsizei) win_w, (GLsizei) win_h);

    // intram in modul proiectie
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    // incarcam matrice de perspectiva
    gluPerspective(45, aspect, 1.0, 1000.0);
}

// initializare program
void init(void) {

    // pregatim o scena noua in opengl
    glClearColor(1.0, 1.0, 1.0, 0.0);

    test = new Test1();

        
}

// SCENA
//-------------------------------------------------

/* desenare scena */
void drawScene(void) {

    // initilizeaza stiva de nume necesara pentru selectie
    glInitNames();

    // Shading model
    glShadeModel(GL_SMOOTH);

    // Activeaza iluminarea
    glEnable(GL_LIGHTING);

    // seteaza modul de desenare al poligoanelor
    glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);

    glLineWidth(1);

    glDisable(GL_LIGHTING);

    drawHUD();
    test->draw();
}

// logica de desenare HUD
void drawHUD() {


    Vector3D camera_pos = test->currentCamera->GetPosition();

    char outputText[512];

    if (selIndex != NONE)
    {
        sprintf(outputText, "Object selected!");

        output (camera_pos.x - 4.5,
                camera_pos.y + 3.5,
                camera_pos.z - 10, 0, outputText);

    }

    if (!typing)
        return;

    output (camera_pos.x - 4.5,
            camera_pos.y - 3.5,
            camera_pos.z - 10, 0, outputText);
}


void output(GLfloat x, GLfloat y, GLfloat z, int i, char *format,...)
{
    va_list args;
    char buffer[1024],*p;
    va_start(args,format);
    vsprintf(buffer, format, args);
    va_end(args);
    Vector3D camera_pos = test->currentCamera->GetPosition();
    glPushMatrix();
    //rotatie similara ca la camera pentru a pastra textul in vedere
    glTranslatef (camera_pos.x,
                  camera_pos.y,
                  camera_pos.z);
    glRotatef (mouseAngleY, 0, 1, 0);
    glRotatef (mouseAngleX, 1, 0, 0);
    glRotatef (0, 0, 0, 1);
    glTranslatef (-camera_pos.x,
                  -camera_pos.y,
                  -camera_pos.z);
    glTranslatef (x,y,z);
    glColor3f (1.0, 0.0, 0.0);
    if (i)
        glScalef (0.001, 0.001, 0.001);
    else
        glScalef (0.002, 0.002, 0.002);
    //afisare text
    for (p = buffer; *p; p++)
        glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, *p);
    glPopMatrix();
}

/* randare scena */
void display(void) {

    // stergere ecran
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glEnable(GL_ALPHA_TEST);
    glAlphaFunc(GL_EQUAL, 1);
    glEnable(GL_DEPTH_TEST);

    // Render Pass - deseneaza scena
    drawScene();
    glDepthMask(GL_FALSE);
    glAlphaFunc(GL_LESS, 1);
    glEnable(GL_BLEND);
    glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    // Render Pass 2 - deseneaza scena
    drawScene();
    glDepthMask(GL_TRUE);
    glDisable(GL_ALPHA_TEST);
    glDisable(GL_BLEND);

    frameEnd(GLUT_BITMAP_HELVETICA_10, 1.0, 0.0, 0.0, 0.02, 0.96);

    // double buffering
    glutSwapBuffers();
}

void idle() {
    ;
}

/*
 * ruleaza la un anumit interval determinat de FPS;
 * face procesarea efectiva a jocului
 * */
void timer(int value)
{
    frameStart();

    glutTimerFunc(0, timer, value);

    if (!typing)
        inputHandler();

    glutPostRedisplay();
}

// INPUT
//-------------------------------------------------

// apelata in timpul procesarii jocului pentru sincronizare
void inputHandler() {
    //  --- keyboard / mouse events ---

    // toogle fullscreen
    if (specialKeys[GLUT_KEY_F1]) {
        fullscreen = !fullscreen;
        toggleFullscreen();
    }

    // zoom +
    if ((keys['w'] || keys['W'])) {
        test->currentCamera->MoveForward(CAMERA_MOVE_SPEED);
    }
    // zoom -
    if (keys['s'] || keys['S']) {
        test->currentCamera->MoveBackward(CAMERA_MOVE_SPEED);
    }
    // stanga
    if (keys['a'] || keys['A']) {
        test->currentCamera->MoveLeft(CAMERA_MOVE_SPEED);
    }
    // dreapta
    if (keys['d'] || keys['D']) {
        test->currentCamera->MoveRight(CAMERA_MOVE_SPEED);
    }

    if (keys['p'] || keys['P']) {
        paused = !paused;
    }

    //rotiri camera
    if (mouseRotX != 0) {
        test->currentCamera->RotateX(0.01* MOUSE_LOOK_X * mouseRotX);	//rotire camera
        mouseAngleX += RAD* MOUSE_LOOK_X * mouseRotX;
        mouseRotX = 0;
    }

    if (mouseRotY != 0) {
        test->currentCamera->RotateY(-0.01* MOUSE_LOOK_Y * mouseRotY);	//rotire camera
        mouseAngleY -= -RAD* MOUSE_LOOK_Y  * mouseRotY;
        mouseRotY = 0;
    }

    if (keys['r'] || keys['R']) {
        test->currentCamera->reset();
        mouseAngleX = mouseAngleY = 0;
    }

    if (specialKeys[GLUT_KEY_UP])
    {
        ;
    }
    if (specialKeys[GLUT_KEY_DOWN])
    {
        ;
    }
    if (specialKeys[GLUT_KEY_LEFT])
    {
        ;
    }
    if (specialKeys[GLUT_KEY_RIGHT])
    {
        ;
    }
    if (specialKeys[GLUT_KEY_PAGE_UP])
    {
        ;
    }
    if (specialKeys[GLUT_KEY_PAGE_DOWN])
    {
        ;
    }

    if (mouseClicked) {
        pick(mouseClickedX, mouseClickedY);
    }

    // set keys to false
    memset(keys,0,sizeof(keys));
    memset(specialKeys,0,sizeof(keys));

}

// handlere taste ascii
void keyboard(unsigned char key, int x, int y) {

    if (typing) {
        keys[key] = true;
        return;
    }

    switch (key) {
        // la escape se iese din program
    case ESC:
        cleanup();
        exit(0);

    case 'w':
    case 'W':
        keys['w'] = keys['W'] = true;
        break;
    case 's':
    case 'S':
        keys['s'] = keys['S'] = true;
        break;
    case 'a':
    case 'A':
        keys['a'] = keys['A'] = true;
        break;
    case 'd':
    case 'D':
        keys['d'] = keys['D'] = true;
        break;

    case 'r':
    case 'R':
        keys['r'] = keys['R'] = true;
        break;
    case 'p':
    case 'P':
        keys['p'] = keys['P'] = true;
        break;
    case 't':
    case 'T':
        keys['t'] = keys['T'] = true;
        break;
    case 'f':
    case 'F':
        keys['f'] = keys['F'] = true;
        break;
    case ENTER:
        keys[ENTER] = true;
        break;
    case BACKSPACE:
        keys[BACKSPACE] = true;
        break;

    default:
        break;
    }
}
void keyboardUp(unsigned char key, int x, int y) {

    if (typing) {
        keys[key] = false;
        return;
    }

    switch (key) {

    case 'w':
    case 'W':
        keys['w'] = keys['W'] = false;
        break;
    case 's':
    case 'S':
        keys['s'] = keys['S'] = false;
        break;
    case 'a':
    case 'A':
        keys['a'] = keys['A'] = false;
        break;
    case 'd':
    case 'D':
        keys['d'] = keys['D'] = false;
        break;

    case 'r':
    case 'R':
        keys['r'] = keys['R'] = false;
        break;
    case 'p':
    case 'P':
        keys['p'] = keys['P'] = false;
        break;
    case 't':
    case 'T':
        keys['t'] = keys['T'] = false;
        break;
    case 'f':
    case 'F':
        keys['f'] = keys['F'] = false;
        break;

    case ENTER:
        keys[ENTER] = false;
        break;
    case BACKSPACE:
        keys[BACKSPACE] = false;
        break;

    default:
        break;
    }
}

// handlere taste speciale
void keyboard(int key, int x, int y) {
    switch (key) {
    case GLUT_KEY_F1:
        specialKeys[GLUT_KEY_F1] = true;
        break;
    case GLUT_KEY_UP:
        specialKeys[GLUT_KEY_UP] = true;
        break;
    case GLUT_KEY_DOWN:
        specialKeys[GLUT_KEY_DOWN] = true;
        break;
    case GLUT_KEY_LEFT:
        specialKeys[GLUT_KEY_LEFT] = true;
        break;
    case GLUT_KEY_RIGHT:
        specialKeys[GLUT_KEY_RIGHT] = true;
        break;
    case GLUT_KEY_PAGE_UP:
        specialKeys[GLUT_KEY_PAGE_UP] = true;
        break;
    case GLUT_KEY_PAGE_DOWN:
        specialKeys[GLUT_KEY_PAGE_DOWN] = true;
        break;
    }
}
void keyboardUp(int key, int x, int y) {
    switch (key) {
    case GLUT_KEY_F1:
        specialKeys[GLUT_KEY_F1] = false;
        break;
    case GLUT_KEY_UP:
        specialKeys[GLUT_KEY_UP] = false;
        break;
    case GLUT_KEY_DOWN:
        specialKeys[GLUT_KEY_DOWN] = false;
        break;
    case GLUT_KEY_LEFT:
        specialKeys[GLUT_KEY_LEFT] = false;
        break;
    case GLUT_KEY_RIGHT:
        specialKeys[GLUT_KEY_RIGHT] = false;
        break;
    case GLUT_KEY_PAGE_UP:
        specialKeys[GLUT_KEY_PAGE_UP] = false;
        break;
    case GLUT_KEY_PAGE_DOWN:
        specialKeys[GLUT_KEY_PAGE_DOWN] = false;
        break;
    }
}

// handler mouse
void mouse(int button, int state, int x, int y) {

    if (button == GLUT_LEFT_BUTTON) {
        if (state == GLUT_DOWN)
        {
            mouseClickedX = x;
            mouseClickedY = y;
            mouseClicked = true;
        }
        else
            mouseClicked = false;

    } else if (button == GLUT_RIGHT_BUTTON) {
        if (state == GLUT_DOWN)
        {
            mouseRightClickedX = x;
            mouseRightClickedY = y;
            mouseX0 = x;
            mouseY0 = y;
            mouseRightClicked = true;
        }
        else
            mouseRightClicked = false;
    } else if (button == GLUT_MIDDLE_BUTTON) {
        if (state == GLUT_DOWN)
        {
            mouseMiddleClicked = true;
        }
        else
        {
            mouseMiddleClicked = false;

        }
    }

}

//tratarea rotatiilor camerei
void move (int x,int y) {
    if (mouseMiddleClicked == false)
        return;

    //daca s-a miscat  pe y
    if (y  < mouseMoveY)
        mouseRotX = 1;
    else
        if (y  > mouseMoveY)
            mouseRotX = -1;
    //daca s-a miscat pe x
    if (x < mouseMoveX)
        mouseRotY = 1;
    else
        mouseRotY = -1;

    mouseMoveX = x;
    mouseMoveY = y;
}


// PICKING

/* determina obiectul selectat*/
void processhits (GLint hits, GLuint buffer[])
{
    int i;
    GLuint names, *ptr, minZ,*ptrNames=NULL, numberOfNames;

    selIndex = NONE;

    ptr = (GLuint *) buffer;
    minZ = 0xffffffff;
    for (i = 0; i < hits; i++) {
        names = *ptr;
        ptr++;
        if (*ptr < minZ) {
            numberOfNames = names;
            minZ = *ptr;
            ptrNames = ptr+2;
        }

        ptr += names+2;
    }

    selIndex = *ptrNames;
    ptrNames = NULL;

}

/* mod selectie */
void pick(int x, int y)
{
    GLuint buffer[1024];
    GLint nhits;
    GLint viewport[4];

    // initial nici un selObj selectat
    selIndex = NONE;

    glGetIntegerv(GL_VIEWPORT, viewport);
    glSelectBuffer(1024, buffer);

    // se intra in modul de selectie
    glRenderMode(GL_SELECT);

    // se renderizeaza doar o zona mica din jurul cursorului mouseului
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();

    glGetIntegerv(GL_VIEWPORT,viewport);
    gluPickMatrix(x,viewport[3]-y,1.0f,1.0f,viewport);

    gluPerspective(45,(viewport[2]-viewport[0])/(GLfloat) (viewport[3]-viewport[1]),0.1,100);
    glMatrixMode(GL_MODELVIEW);

    // se va desena scena in modul de selectie (de fapt nimic nu este desenat propriu-zis : "desenarea" se face
    // in bufferul de selectie si nu pe ecran
    drawScene();

    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    nhits=glRenderMode(GL_RENDER);

    // proceseaza bufferul de selectie si alege obiectul cel mai apropiat (daca exista)
    if (nhits != 0) {
        processhits(nhits,buffer);
    }
}

// setare fullscreen
void toggleFullscreen() {
    if (fullscreen) {
        old_win_w = win_w;
        old_win_h = win_h;
        old_win_x = glutGet((GLenum) GLUT_WINDOW_X);
        old_win_y = glutGet((GLenum) GLUT_WINDOW_Y);
        glutFullScreen();
    } else {
        glutReshapeWindow(old_win_w, old_win_h);
        glutPositionWindow(old_win_x, old_win_y);
    }
}

void cleanup()
{
    delete test;
}

// MAIN
//-------------------------------------------------
int main(int argc, char** argv) {
    
    if(argc > 1)
	testNum  = atoi(argv[1]);
    
    srand((unsigned) time(NULL));

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_ALPHA | GLUT_DEPTH);
    glutInitWindowSize(win_w, win_h);
    glutInitWindowPosition(win_x, win_y);

    glutCreateWindow(APP_TITLE);

    glewInit();


    toggleFullscreen();

    glutDisplayFunc(display);

    glutIdleFunc(idle);
    glutTimerFunc(0, timer, 0);

    glutReshapeFunc(reshape);

    glutKeyboardFunc(keyboard);
    glutSpecialFunc(keyboard);
    glutKeyboardUpFunc(keyboardUp);
    glutSpecialUpFunc(keyboardUp);

    glutMouseFunc(mouse);
    glutMotionFunc(move);
    glutPassiveMotionFunc(move);

    init();

    glutMainLoop();

    cleanup();

    return 0;
}
