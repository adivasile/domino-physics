#ifndef LIGHT_H
#define LIGHT_H

#include "CSceneNode.h"

// tipul de iluminare

enum IlluminationType {
    Ideal, // lumina omnidirectionala
    Spot // lumina directionala
};

/*
        Light
        Clasa pentru desenarea si activarea unei lumini
 */

// derivata din CSceneNode

class Light : public CSceneNode {
private:


    // VARIABILE
    //-------------------------------------------------
public:
    static int BaseId;
    // tipul luminii - nu este folosit, inca
    IlluminationType LightType;

private:
    // id-ul asignat. pleaca din 0 si este folosit pentru GL_LIGHT0 + id
    int id;
    GLfloat constantAttenuation;
    GLfloat linearAttenuation;
    GLfloat quadraticAttenuation;

    // pentru spot :
    GLfloat cutoff;
    Vector3D direction;
    GLfloat exponent;


    // FUNCTII
    //-------------------------------------------------
public:
    // constructor fara parametri
    Light();

    // plaseaza lumina in scena si o activeaza
    void Illuminate();

    // activeaza lumina
    void Enable();
    // dezactiveaza lumina
    void Disable();

    // seteaza tipul de lumina
    void SetLightType(IlluminationType LightType);
    IlluminationType GetLightType();

    // seteaza atenuarea
    void SetAttenuation(GLfloat _constantAttenuation, GLfloat _linearAttenuation, GLfloat _quadtraticAttenuation);
    Vector3D GetAttenuation();

    // pentru spot :

    void SetDirection(Vector3D _direction);
    Vector3D GetDirection();

    void SetCutoff(GLfloat _cutoff);
    GLfloat GetCutoff();

    void SetExponent(GLfloat _exponent);
    GLfloat GetExponent();
};

#endif
