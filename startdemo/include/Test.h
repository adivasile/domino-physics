#ifndef TEST_H
#define TEST_H

#include "main.h"
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

#include "CSceneNode.h"
#include "CMesh.h"
#include "OFF.h"
#include "Camera.h"
#include "Light.h"

#include <domino.h>


class Test
{
public:   
    //--------------------------------
    /* scena */

    // camera    
    Camera *currentCamera;
    std::vector<CSceneNode*> objects; 

    virtual void draw() = 0;
};

#endif // TEST_H
