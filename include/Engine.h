#ifndef ENGINE_H_
#define ENGINE_H_

#define GROUP_SIZE 256
#include "DominoItem.h"
// #include "World.h"

namespace domino
{
class Engine : public DominoItem
{
private:

    bool initialized;

    // std::vector<DominoItem*> worlds;


public:
// CONSTRUCTOR
//-------------------------------------------------

    Engine();

    int initialize();

    int setup();



// DESTRUCTOR
//-------------------------------------------------

    ~Engine();

// SETTERS
//-------------------------------------------------

// GETTERS
//-------------------------------------------------

    // void AddWorld(DominoItem* world);
    

// OTHER
//-------------------------------------------------

    int run();

};
}

#endif /* ENGINE_H_ */
