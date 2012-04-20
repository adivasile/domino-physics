#include "Camera.h"

//constructor cu setarile initiale
Camera::Camera()
{
	//Init with standard OGL values:
	reset();
}

//setarea pozitiilor initiale
void Camera::reset()
{
	Position = Vector3D (0.0, 0.0, 40.0);
	ForwardVector = Direction = Vector3D( 0.0, 0.0, -1.0);
	RightVector = Vector3D (1.0, 0.0, 0.0);
	UpVector = Vector3D (0.0, 1.0, 0.0);
	unghi = 0;
}

Vector3D Camera::GetPosition()
{
	return Position;
}

void Camera::SetPosition(Vector3D pos) {
	Position = pos;
}

//rotatie pe X
void Camera::RotateX (GLfloat Angle)
{
	Vector3D oldForwardVector = ForwardVector;

	unghi += Angle;	//se modifica unghiul
	ForwardVector = (ForwardVector*cos(Angle) + UpVector*sin(Angle)).Normalize();
	UpVector = (UpVector*cos(Angle)	- oldForwardVector*sin(Angle)).Normalize();
}

//rotatie pe Y
void Camera::RotateY (GLfloat Angle)
{
	Vector3D oldForwardVector = Direction;
	Direction = (Direction*cos(Angle) + RightVector*sin(Angle)).Normalize();
	RightVector = (RightVector*cos(Angle)- oldForwardVector*sin(Angle)).Normalize();
	//se roteste pe X de la pozitia modificata pe Y
	ForwardVector = Direction;
	UpVector = Vector3D (0.0, 1.0, 0.0);
	RotateX (unghi);
	unghi /= 2;
}

void Camera::Render( void )
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//The point at which the camera looks:
	Vector3D ViewPoint = Position + ForwardVector;

	//as we know the up vector, we can easily use gluLookAt:
	gluLookAt(	Position.x,Position.y,Position.z,
				ViewPoint.x,ViewPoint.y,ViewPoint.z,
				UpVector.x,UpVector.y,UpVector.z);
}

//modifica pozitia doar daca se afla in limitele cladirii
void Camera::updatePosition(Vector3D Pos)
{
	//se verifica limitele cladirii
	// if (Pos.x >= -ROOM_WIDTH/2+10 && Pos.x <= ROOM_WIDTH/2-10)
		Position.x = Pos.x;
	// if (Pos.z >= -ROOM_LENGTH/2+10 && Pos.z <= ROOM_LENGTH/2-10)
		Position.z = Pos.z;
	// if (Pos.y >= -ROOM_HEIGHT/2+10 && Pos.y <= ROOM_HEIGHT/2-10)
		Position.y = Pos.y;
}

//deplasare in fata
void Camera::MoveForward( GLfloat Distance ) {
	Vector3D Pos;	//vector temporar de modificare
	Pos.y = Position.y+Distance*ForwardVector.y;
	Pos.x = Position.x+Distance*ForwardVector.x;
	Pos.z = Position.z+Distance*ForwardVector.z;
	updatePosition(Pos);
}

//deplasare in spate (asemanator deplasare fata)
void Camera::MoveBackward( GLfloat Distance )
{
	Vector3D Pos;

	Pos.y = Position.y - Distance * ForwardVector.y;
	Pos.x = Position.x - Distance * ForwardVector.x;
	Pos.z = Position.z - Distance * ForwardVector.z;
	updatePosition(Pos);
}

//deplasare stanga (asemanator deplasare stanga)
void Camera::MoveRight ( GLfloat Distance ) {
	Vector3D Pos;

	Pos.y = Position.y + Distance * RightVector.y;
	Pos.x = Position.x + Distance * RightVector.x;
	Pos.z = Position.z + Distance * RightVector.z;
	updatePosition(Pos);
}

//deplasare dreapta (asemanator deplasare fata)
void Camera::MoveLeft ( GLfloat Distance ) {
	Vector3D Pos;

	Pos.y = Position.y - Distance * RightVector.y;
	Pos.x = Position.x - Distance * RightVector.x;
	Pos.z = Position.z - Distance * RightVector.z;
	updatePosition(Pos);
}
