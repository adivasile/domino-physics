#include "CSceneNode.h"

/*
 Model
 Clasa pentru desenare si modificare a unui obiect 3d.
 */

// CONSTRUCTORI
//-------------------------------------------------

CSceneNode::CSceneNode()
{
	;
}

CSceneNode::CSceneNode(CMesh* mesh)
{
    glGetFloatv(GL_MODELVIEW_MATRIX, transformMatrix);
	  defaultSettings();
	  this->mesh = mesh;
	  this->mesh->PrepareVBO();
}

CSceneNode::~CSceneNode()
{
    ;
}

// seteaza toti parametrii la valorile lor default
void CSceneNode::defaultSettings()
{
	Lighted = true;
	Wireframe = false;
	Visible = true;

	scale = Vector3D(1.0, 1.0, 1.0);

	color = Vector3D(1, 1, 1);
	alpha = 1.0;

	diffuse = Vector4D(1, 1, 1, 1);
	ambient = Vector4D(1, 1, 1, 1);
	specular = Vector4D(0.0, 0.0, 0.0, 0);
	emission = Vector4D(0.0, 0.0, 0.0, 0);
	shininess = 100;
}

// DRAW
//-------------------------------------------------
void CSceneNode::Render()
{
	// daca nu este vizibil, nu-l desenam
	if (!Visible)
		return;

	
    // translatie
    glTranslatef(position.x, position.y, position.z);

    // rotatie
    glRotatef(rotation.x, 1.0, 0.0, 0.0);
    glRotatef(rotation.y, 0.0, 1.0, 0.0);
    glRotatef(rotation.z, 0.0, 0.0, 1.0);

    // scalare
    glScalef(scale.x, scale.y, scale.z);
     
    glColor3f(color.x, color.y, color.z);
    if (Lighted)
    {
      glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, diffuse.Array());
    }

    // culoare speculara
    if (Lighted)
    {
      glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular.Array());
      glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, &shininess);
      glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, emission.Array());
    }
    else
      glDisable( GL_LIGHTING);

    glPushMatrix();
        if(Wireframe)
        {
              glutSolidSphere(1.0,8,16);
        } else
        {
              glutWireSphere(1.0,8,16);
        }

        if (!Lighted)
          glEnable( GL_LIGHTING);
    
    glPopMatrix();
}


// SETTERS
//-------------------------------------------------

// seteaza model Mesh

void CSceneNode::SetMesh(CMesh * mesh)
{
	this->mesh = mesh;
}

void CSceneNode::SetPosition(Vector3D position)
{
	  this->position = position;
}

void CSceneNode::SetRotation(Vector3D rotation)
{
	this->rotation = rotation;
}

// seteaza scalare

void CSceneNode::SetScale(Vector3D scale)
{
	  this->scale = scale;
}


// seteaza culoare normala => seteaza si culoarea difuza

void CSceneNode::SetColor(Vector3D color)
{
	this->color = color;
	diffuse = Vector4D(this->color.x, this->color.y, this->color.z, alpha);
}
// seteaza opacitate

void CSceneNode::SetAlpha(GLfloat alpha)
{
	this->alpha = alpha;
	diffuse.a = alpha;
}

// setare culoare difuza => seteaza si culoare normala

void CSceneNode::SetDiffuse(Vector4D diffuse)
{
	this->diffuse = diffuse;
	color = Vector3D(this->diffuse.x, this->diffuse.y, this->diffuse.z);
	alpha = this->diffuse.a;
}
// setare culoare ambientala

void CSceneNode::SetAmbient(Vector4D ambient)
{
	this->ambient = ambient;
}
// setare culoare speculara

void CSceneNode::SetSpecular(Vector4D color)
{
	this->specular = color;
}
// setare culoare emisie

void CSceneNode::SetEmission(Vector4D emission)
{
	this->emission = emission;
}
// setare stralucire

void CSceneNode::SetShininess(GLfloat shininess)
{
	this->shininess = shininess;
}

// GETTERS
//-------------------------------------------------

// intoarce color

Vector3D CSceneNode::GetColor()
{
	return color;
}
// intoarce opacitate

GLfloat CSceneNode::GetAlpha()
{
	return alpha;
}

Vector3D CSceneNode::GetPosition()
{
	return this->position;
}

Vector3D CSceneNode::GetRotation()
{
	return this->rotation;
}

Vector3D CSceneNode::GetScale()
{
	return this->scale;
}

// intoarce dimensiunile

Vector3D CSceneNode::GetDimensions()
{
	return mesh->GetDimensions() * this->scale;
}

// intoarce centrul

Vector3D CSceneNode::GetCenter()
{
	return mesh->GetCenter() * this->scale + this->position;
}

// OTHERS
//-------------------------------------------------

void CSceneNode::Scale(Vector3D scale)
{
	this->scale = this->scale * scale;
}

GLboolean CSceneNode::IsVisible()
{
	return this->Visible;
}

