#ifndef CAMERA_H
#define CAMERA_H

#include "Vector3D.h"

class Camera {

public:
	Camera();	//constructor fara parametrii
	void Render ( void );	//pozitionare
	void MinimapSettings();	//setarile camerei pentru minimap
	void RotateX ( GLfloat Angle );	//rotatie pe X
	void RotateY ( GLfloat Angle );	//rotatie pe Y
	//miscari fata, spate, stanga, dreapta
	void MoveForward ( GLfloat Distance );
	void MoveBackward ( GLfloat Distance );
	void MoveRight ( GLfloat Distance );
	void MoveLeft ( GLfloat Distance );
	Vector3D GetPosition ();
	void SetPosition (Vector3D);
	void reset();
	void updatePosition(Vector3D);
	GLfloat unghi;
	Vector3D Position;	//pozitia in cadrul scenei
	Vector3D ForwardVector;
	Vector3D Direction;	//directia de deplasare a jucatorului (y constant)
	Vector3D RightVector;
	Vector3D UpVector;
};

#endif
