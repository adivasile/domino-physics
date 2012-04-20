#ifndef TEST1_H
#define TEST1_H

#include "Test.h"

class Test1 : public Test
{
    // camera  
    Camera *camera1;
    
    // lumini
    Light *light;

public:
    Test1();
    virtual ~Test1();
    
    void draw();
};

#endif // TEST1_H
