#include "Engine.h"

namespace domino
{
// CONSTRUCTOR
//-------------------------------------------------

Engine::Engine()
{
    //deviceType = "cpu"; // for debugging

    initialize();
}

int Engine::initialize()
{
    /* Call base class Initialize to get default configuration */
    initialized = true;
    return 0;
}

int Engine::setup()
{
    return 0;
}

// DESTRUCTOR
//-------------------------------------------------

Engine::~Engine()
{
    // worlds.clear();
}


// SETTERS
//-------------------------------------------------

// void Engine::AddWorld(DominoItem* world)
// {
//     worlds.push_back(world);
// }
// 


// OTHER
//-------------------------------------------------

int Engine::run()
{

    // unsigned int num_worlds = worlds.size();

    // for (int i = 0; i<num_worlds; i++)
    // {
    //     ((World*)worlds.at(i))->Update();
    // }


    
    return 0;
}

}
