#include <stdio.h>

#include "CMesh.h"

#define BUFFER_OFFSET(i) ((char *)NULL + (i))

/*
 Declaratiile clasei CMesh - clasa pentru reprezentarea unui model 3D
 */

// CONSTRUCTORI CMesh
//-------------------------------------------------

CMesh::CMesh(int maxverts, int maxfaces)
{
    nverts = 0;
    nfaces = 0;
    this->maxverts = maxverts;
    this->maxfaces = maxfaces;
    verts = new Vector3D[maxverts];
    faces = new Face[maxfaces];
    revNormal = false;

    bufferArray = (Vertex *) malloc(maxfaces * 3 * sizeof(Vertex));
    indexArray = (GLushort *) malloc(maxfaces * 3 * sizeof(GLushort));
}

// contructor gol

CMesh::CMesh()
{
    CMesh(0, 0);
}

CMesh::~CMesh()
{
    if(verts != NULL)
	delete verts;
    if(faces != NULL)
	delete faces;
    if(bufferArray != NULL)
	free(bufferArray);
    if(indexArray != NULL)
	free(indexArray);
}

// adauga punct

void CMesh::AddVertex(Vector3D *vertex)
{
    verts[nverts++] = *vertex;
}

// adauga fata

void CMesh::AddFace(Face *face)
{
    faces[nfaces++] = *face;
}

GLint CMesh::GetNumFaces()
{
    return (GLint)this->nfaces;
}

Vertex* CMesh::GetBufferArray()
{
    this->bufferArray;
}

GLushort* CMesh::GetIndexArray()
{
    this->indexArray;
}

// determina centru

Vector3D CMesh::GetCenter()
{
    Vector3D center;
    for (int i = 0; i < nverts; i++)
    {
        center.x += verts[i].x;
        center.y += verts[i].y;
        center.z += verts[i].z;
    }
    center = center / nverts;
    return center;
}

// determina dimensiuni

Vector3D CMesh::GetDimensions()
{
    Vector3D min = Vector3D(9999, 9999, 9999);
    Vector3D max = Vector3D(0, 0, 0);

    for (int i = 0; i < nverts; i++)
    {
        max.x = (max.x < verts[i].x) ? verts[i].x : max.x;
        min.x = (min.x > verts[i].x) ? verts[i].x : min.x;

        max.y = (max.y < verts[i].y) ? verts[i].y : max.y;
        min.y = (min.y > verts[i].y) ? verts[i].y : min.y;

        max.z = (max.z < verts[i].z) ? verts[i].z : max.z;
        min.z = (min.z > verts[i].z) ? verts[i].z : min.z;
    }

    Vector3D dimensions = max - min;

    return dimensions;
}

// functie de desenare apelata de Draw din Object3D

void CMesh::PrepareVBO()
{
    if (verts != NULL && bufferArray != NULL && indexArray != NULL)
    {
        glGenBuffers(1, &vboID);
        glBindBuffer(GL_ARRAY_BUFFER, vboID);

        int currentVertex = 0;
        for (int i = 0; i < nfaces; i++)
        {
            CMesh::Face face = faces[i];
            Vector3D norm = (face.normal * (revNormal ? -1 : 1));
            for (int j = 0; j < face.nverts; j++)
            {
                Vector3D *vert = face.verts[j];
                bufferArray[currentVertex].x = vert->x;
                bufferArray[currentVertex].y = vert->y;
                bufferArray[currentVertex].z = vert->z;
                bufferArray[currentVertex].nx = norm.x;
                bufferArray[currentVertex].ny = norm.y;
                bufferArray[currentVertex].nz = norm.z;
                bufferArray[currentVertex].r = 1.0f;
                bufferArray[currentVertex].g = 1.0f;
                bufferArray[currentVertex].b = 1.0f;
                bufferArray[currentVertex].a = 1.0f;
                indexArray[currentVertex] = currentVertex++;
            }

        }

        glBufferData(GL_ARRAY_BUFFER, maxfaces * 3 * sizeof(Vertex), NULL,
                     GL_STATIC_DRAW);
        glBufferSubData(GL_ARRAY_BUFFER, 0, maxfaces * 3 * sizeof(Vertex),
                        bufferArray);
        glNormalPointer(GL_FLOAT, sizeof(Vertex), BUFFER_OFFSET(12));
        glColorPointer(4, GL_FLOAT, sizeof(Vertex), BUFFER_OFFSET(24));
        glVertexPointer(3, GL_FLOAT, sizeof(Vertex), BUFFER_OFFSET(0));

        glGenBuffers(1, &idxID); // Generate buffer
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, idxID); // Bind the element array buffer
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, maxfaces * 3 * sizeof(GLushort),
                     indexArray, GL_STATIC_DRAW);
    }

}

void CMesh::Draw(bool Wireframe)
{

    // daca este wireframe
    if (Wireframe)
    {
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    } // daca nu este wireframe
    else
    {
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    }

    if (verts != NULL && bufferArray != NULL && indexArray != NULL)
    {

        glBindBuffer(GL_ARRAY_BUFFER, vboID);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, idxID);

        glEnableClientState(GL_COLOR_ARRAY);
        glEnableClientState(GL_NORMAL_ARRAY);
        glEnableClientState(GL_VERTEX_ARRAY);

        glNormalPointer(GL_FLOAT, sizeof(Vertex), BUFFER_OFFSET(12));
        glColorPointer(4, GL_FLOAT, sizeof(Vertex), BUFFER_OFFSET(24));
        glVertexPointer(3, GL_FLOAT, sizeof(Vertex), BUFFER_OFFSET(0));

        glDrawElements(GL_TRIANGLES, maxfaces * 3, GL_UNSIGNED_SHORT,
                       BUFFER_OFFSET(0));

        glDisableClientState(GL_COLOR_ARRAY);
        glDisableClientState(GL_NORMAL_ARRAY);
        glDisableClientState(GL_VERTEX_ARRAY);

    }

    glPushMatrix();
        glScalef(0.2, 0.2, 0.2);
        glutSolidSphere(5, 100, 100);
    glPopMatrix();
 
//     glDeleteBuffers(1, &vboID);
//     glDeleteBuffers(1, &idxID);
}

// CONSTRUCTORI Face
//-------------------------------------------------

// constructor gol

CMesh::Face::Face(int maxverts)
{
    nverts = 0;
    this->maxverts = maxverts;
    verts = new Vector3D*[maxverts];
    normal = Vector3D(0, 1, 0);
}

CMesh::Face::Face()
{
    CMesh::Face(0);
}

// adauga punct

void CMesh::Face::AddVertex(Vector3D *vertex)
{
    verts[nverts++] = vertex;
}

// seteaza normala fetei

void CMesh::Face::SetNormal(Vector3D *normal)
{
    this->normal = *normal;
}

void CMesh::SetBufferArray(Vertex *bufferArray)
{
    this->bufferArray = bufferArray;
}

void CMesh::SetIndexArray(GLushort *indexArray)
{
    this->indexArray = indexArray;
}
