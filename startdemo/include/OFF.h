#ifndef OFF_H
#define OFF_H

#include <assert.h>
#include <string.h>
#include <ctype.h>

#include "CMesh.h"

/*
        Clasa OFF -- contine o functie statica pentru citirea din fisier .off
 */


class OFF {
    // FUNCTII
    //-------------------------------------------------
public:
    //  creeaza un mesh pe baza unui fisier .off
    static CMesh *ReadFileMesh(const char *filename);

};
#endif
