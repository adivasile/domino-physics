#include "Test1.h"

#define M 8
#define N 8
#define M2 1
#define N2 1
#define NUM_OBJECTS M*N+M2*N2

static float randFloatRange(float a, float b)
{
	return ((b-a)*((float)rand()/RAND_MAX))+a;
}

Test1::Test1()
{
    unsigned int numObjects = NUM_OBJECTS;
    
    printf("Initializing test 1....");
    
    camera1 = currentCamera = new Camera();
    light = new Light();
    
    // initializare camere/observator        
    camera1->SetPosition(Vector3D(N*1, 0, M*4));
    
    // initializare lumina
    
    light->SetPosition(Vector3D(0,ROOM_HEIGHT/2-10,ROOM_LENGTH/16)); 
    light->SetAttenuation(0.1,0.1,0);

    CMesh * mesh1 = OFF::ReadFileMesh("res/sphere.off");
    CMesh * planeMesh = OFF::ReadFileMesh("res/plane.off");

    CSceneNode* obj = new CSceneNode(mesh1);
    objects.push_back(obj);
    obj->SetColor(Vector3D(0, 1, 0));
    obj->SetSpecular(Vector4D(1, 1, 1, 1));
    obj->SetShininess(10);
    obj->SetPosition(Vector3D(2, 1, 0));

}

Test1::~Test1()
{
        objects.clear();
    
    if(light != NULL) delete light;
    if(camera1 != NULL) delete camera1;
}

void Test1::draw()
{
    camera1->Render();
    light->Illuminate();
    for(int i = 0; i < objects.size(); i++)
    {
        objects.at(i)->Render();	
    }
}

