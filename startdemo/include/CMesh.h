#ifndef CMESH_H
#define CMESH_H


#include "Vector3D.h"
#include "Vector4D.h"
#include "Vertex.h"

#include "common.h"

/*
 Clasa mesh - pentru reprezentarea unui model 3D
 */

class CMesh
{
public:

	/*
	 Clasa interioara Face
	 */

	class Face
	{
		// VARIABILE
		//-------------------------------------------------
	public:
		// nr maxim de puncte, nr curent de puncte
		int maxverts, nverts;

		Vector3D **verts; // punctele
		Vector3D normal; // normala

		// FUNCTII
		//-------------------------------------------------
	public:
		// constructor fara parametri
		Face();
		Face(int _nverts);
		void AddVertex(Vector3D *vertex); // adauga punct
		void SetNormal(Vector3D *normal); // seteaza normala
	};

	// VARIABILE
	//-------------------------------------------------
public:
	// numar de puncte
	int maxverts, nverts;

	// vector puncte
	Vector3D *verts;

	//numar fete
	int maxfaces, nfaces;

	// vector fete
	Face *faces;
	Vertex *bufferArray;
	GLushort *indexArray;
	GLuint vboID;
	GLuint idxID;

	// centrul modelului
	Vector3D center;
	// marimile pe x,y,z
	Vector3D dimensions;

	// normala inversata -- hack pt fisiere .off cu normala gresita
	bool revNormal;

	// FUNCTII
	//-------------------------------------------------
public:
	// constructor:
	CMesh();
	CMesh(int _maxverts, int _maxfaces);
	
	~CMesh();

	/* DOMINO STUFF */

	// getters
	GLint GetNumFaces();
	Vertex* GetBufferArray();
	GLushort *GetIndexArray();
	Vector3D GetCenter();
	Vector3D GetDimensions();

	// setters
	void SetBufferArray(Vertex *bufferArray);
	void SetIndexArray(GLushort *indexArray);

	/* SPECIFIC STUFF */

	void AddVertex(Vector3D *vertex);
	void AddFace(Face *face);
	void PrepareVBO();

	// va fi apelata de Model
	void Draw(bool);

};

#endif /* CMESH_H*/
