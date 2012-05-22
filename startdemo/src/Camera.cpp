#include "Camera.h"

Camera::Camera()
{
	//Init with standard OGL values:
	reset();
}

void Camera::reset()
{
	Position = Vector3D (0.0, 0.0, 40.0);
	ForwardVector = Direction = Vector3D( 0.0, 0.0, -1.0);
	RightVector = Vector3D (1.0, 0.0, 0.0);
	UpVector = Vector3D (0.0, 1.0, 0.0);
	angle = 0;
}

Vector3D Camera::GetPosition()
{
	return Position;
}

void Camera::SetPosition(Vector3D pos) {
	Position = pos;
}

void Camera::RotateX (GLfloat ang)
{
	Vector3D oldForwardVector = ForwardVector;

	angle += ang;	
	ForwardVector = (ForwardVector*cos(ang) + UpVector*sin(ang)).Normalize();
	UpVector = (UpVector*cos(ang)	- oldForwardVector*sin(ang)).Normalize();
}

void Camera::RotateY (GLfloat ang)
{
	Vector3D oldForwardVector = Direction;
	Direction = (Direction*cos(ang) + RightVector*sin(ang)).Normalize();
	RightVector = (RightVector*cos(ang)- oldForwardVector*sin(ang)).Normalize();

	ForwardVector = Direction;
	UpVector = Vector3D (0.0, 1.0, 0.0);
	RotateX (angle);
	angle /= 2;
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

void Camera::MoveForward( GLfloat Distance ) {
	Vector3D Pos;
	Pos.y = Position.y+Distance*ForwardVector.y;
	Pos.x = Position.x+Distance*ForwardVector.x;
	Pos.z = Position.z+Distance*ForwardVector.z;
}

void Camera::MoveBackward( GLfloat Distance )
{
	Vector3D Pos;

	Pos.y = Position.y - Distance * ForwardVector.y;
	Pos.x = Position.x - Distance * ForwardVector.x;
	Pos.z = Position.z - Distance * ForwardVector.z;
}

void Camera::MoveRight ( GLfloat Distance ) {
	Vector3D Pos;

	Pos.y = Position.y + Distance * RightVector.y;
	Pos.x = Position.x + Distance * RightVector.x;
	Pos.z = Position.z + Distance * RightVector.z;
}

void Camera::MoveLeft ( GLfloat Distance ) {
	Vector3D Pos;

	Pos.y = Position.y - Distance * RightVector.y;
	Pos.x = Position.x - Distance * RightVector.x;
	Pos.z = Position.z - Distance * RightVector.z;
}
