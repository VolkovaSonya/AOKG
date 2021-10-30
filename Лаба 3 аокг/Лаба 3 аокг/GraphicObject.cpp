#include "GraphicObject.h"
#include "GLM/GLM/glm.hpp"
#include "GLM/GLM/gtx/transform.hpp"
#include "GLM/GLM/gtc/type_ptr.hpp"
//using namespace glm;
// �����������
GraphicObject::GraphicObject(void)
{
}
// ������ ������� �������
void GraphicObject::setPosition(float x, float y, float z)
{
	position[0] = x;
	position[1] = y;
	position[2] = z;
}
// ������ ���� �������� � �������� ������������ ��� OY
void GraphicObject::setAngle(float a)
{
	angle = a;
}
// ������ ���� ������
void GraphicObject::set�olor(float r, float g, float b)
{
	color[0] = r;
	color[1] = g;
	color[2] = b;
}
// ������� ������
void GraphicObject::draw(void)
{
	glPushMatrix();
	//glColor3f(color[0], color[1], color[2]);
	//glTranslatef(position[0], position[1], position[2]);
	//glRotatef(angle, 0.0, 1.0, 0.0);
	glColor3fv(glm::value_ptr(color));
	this->modelMatrix = glm::translate(position) * glm::rotate(glm::radians(angle), glm::vec3(0.0, 1.0, 0.0));
	glMultMatrixf(glm::value_ptr(this->modelMatrix));
	
	glutWireTeapot(1.0);
	glPopMatrix();
}
