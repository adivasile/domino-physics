#ifndef CSCENE_NODE_H
#define CSCENE_NODE_H

#include "Vector3D.h"
#include "Vector4D.h"
#include "CMesh.h"

/*
 CSceneNode
 Clasa pentru desenare si modificare a unui obiect 3d.
 */
class CSceneNode
{
	// VARIABILE
	//-------------------------------------------------
	// publice
public:
	bool Wireframe; // daca va fi desenat wireframe
	bool Visible; // daca va fi sau nu desenat
	bool Lighted; // daca este sau nu luminat

protected:
	CMesh* mesh;

	Vector3D position; // pozitie
	Vector3D rotation; // rotatie
	Vector3D scale; // scalare
	GLfloat transformMatrix[16];

	Vector3D color; // culoare
	GLfloat alpha; // opacitate

	Vector4D diffuse; // culoarea/lumina difuza
	Vector4D ambient; // culoarea/lumina ambientala
	Vector4D specular; // culoarea/lumina speculara
	Vector4D emission; // culoarea/lumina emisa
	GLfloat shininess; // stralucire

	// FUNCTII ::
	//-------------------------------------------------
public:
	CSceneNode();
	CSceneNode(CMesh *);
	
	~CSceneNode();

	/* DOMINO STUFF */

	// setters
	void SetPosition(Vector3D position);
	void SetRotation(Vector3D rotation);
	void SetScale(Vector3D scale);

	// getters
	Vector3D GetPosition();
	Vector3D GetRotation();
	Vector3D GetScale();
	Vector3D GetDimensions();
	Vector3D GetCenter();

	// other
	GLboolean IsVisible();


	// functie de desenare
	void Render();

	// setters
	void SetMesh(CMesh*);
	void SetColor(Vector3D);
	void SetAlpha(GLfloat);
	void SetDiffuse(Vector4D);
	void SetAmbient(Vector4D);
	void SetSpecular(Vector4D);
	void SetEmission(Vector4D);
	void SetShininess(GLfloat);

	// getters
	Vector3D GetColor();
	GLfloat GetAlpha();

	// other
	void Scale(Vector3D);

protected:
	// seteaza valorile default
	void defaultSettings();
};

#endif /* CSCENE_NODE_H */
