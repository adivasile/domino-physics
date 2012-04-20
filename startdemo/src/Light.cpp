#include "Light.h"

// id-ul de baza
int Light::BaseId = 0;

// constructor fara parametri, mosteneste constructorul de Sfera din Object3D
// deoarece dorim ca lumina sa fie ilustrata printr-o sfera

Light::Light() {
    color = Vector3D(1, 1, 1);

    // valori default
    diffuse = Vector4D(1, 1, 1, 1);
    ambient = Vector4D(0.5, 0.5, 0.5, 0.5);
    specular = Vector4D(1, 1, 1, 0.5);

    scale = Vector3D(0.5, 0.5, 0.5);

    // id-ul este unic, id-ul de baza incrementat
    id = BaseId++;

    // default lumina este omnidirectionala
    LightType = Ideal;

    constantAttenuation = 1;
    linearAttenuation = 0.1f;
    quadraticAttenuation = 0.0;

    direction = Vector3D(0.0, -1.0, 0.0);
    cutoff = 90.0;
    exponent = 9;
}
// functie care plaseaza efectiv lumina in scena

void Light::Illuminate() {
    // atenuari standard
    glLightf(GL_LIGHT0 + id, GL_CONSTANT_ATTENUATION, constantAttenuation);
    glLightf(GL_LIGHT0 + id, GL_LINEAR_ATTENUATION, linearAttenuation);
    glLightf(GL_LIGHT0 + id, GL_QUADRATIC_ATTENUATION, quadraticAttenuation);

    // culoarea difuza
    glLightfv(GL_LIGHT0 + id, GL_DIFFUSE, diffuse.Array());
    // culoarea ambientala
    glLightfv(GL_LIGHT0 + id, GL_AMBIENT, ambient.Array());
    // culoarea speculara
    glLightfv(GL_LIGHT0 + id, GL_SPECULAR, specular.Array());
    // pozitia luminii
    glLightfv(GL_LIGHT0 + id, GL_POSITION, Vector4D(position.x, position.y, position.z, 1).Array());

    // daca este de tip spot , setam parametrii de spot ( se vor folosi valori default )
    if (LightType == Spot) {
        // directia spotului va fi in jos
        glLightfv(GL_LIGHT0 + id, GL_SPOT_DIRECTION, direction.Array());
        // deschidere de 45 de grade
        glLightf(GL_LIGHT0 + id, GL_SPOT_CUTOFF, cutoff);
        glLightf(GL_LIGHT0 + id, GL_SPOT_EXPONENT, exponent);
    }

    Enable();
}

//functie care activeaza lumina
void Light::Enable() {
    glEnable(GL_LIGHT0 + id);
}
// functie care dezactiveaza lumina
void Light::Disable() {
    glDisable(GL_LIGHT0 + id);
}

// seteaza tipul de lumina
void Light::SetLightType(IlluminationType _LightType) {
    LightType = _LightType;
}
IlluminationType Light::GetLightType() {
    return LightType;
}

// seteaza atenuarea
void Light::SetAttenuation(GLfloat _constantAttenuation, GLfloat _linearAttenuation, GLfloat _quadraticAttenuation) {
    constantAttenuation = _constantAttenuation;
    linearAttenuation = _linearAttenuation;
    quadraticAttenuation = _quadraticAttenuation;
}
Vector3D Light::GetAttenuation() {
    return Vector3D(constantAttenuation, linearAttenuation, quadraticAttenuation);
}

// pentru spot :

void Light::SetDirection(Vector3D _direction) {
    direction = _direction;
}
Vector3D Light::GetDirection() {
    return direction;
}

void Light::SetCutoff(GLfloat _cutoff) {
    cutoff = _cutoff;
}
GLfloat Light::GetCutoff() {
    return cutoff;
}

void Light::SetExponent(GLfloat _exponent) {
    exponent = _exponent;
}
GLfloat Light::GetExponent() {
    return exponent;
}
