#include "GraphicObject.h"
GraphicObject::GraphicObject() {
	setPosition(0, 0, 0);
	setAngle(0);
	setColor(1.0f, 1.0f, 1.0f);
	setSize(1.0f);
}
GraphicObject::GraphicObject(float* pos, float ang, float* color, float size) {
	setPosition(pos[0], pos[1], pos[2]);
	setAngle(ang);
	setColor(color[0], color[1], color[2]);
	setSize(size);
}
void GraphicObject::setPosition(float x, float y, float z) {
	position.x = x;
	position.y = y;
	position.z = z;
}

// задать угол поворота в градусах относительно оси OY
void GraphicObject::setAngle(float a)
{
	angle = a;
}
// «адать цвет модели
void GraphicObject::setColor(float r, float g, float b)
{
	color[0] = r;
	color[1] = g;
	color[2] = b;
}
void GraphicObject::setSize(float value = 1.0) {
	size = value;
	if (size <= 0)
		value = 1.0f;
	else size=value;
}
void GraphicObject::draw(void) {
	glPushMatrix();
	glColor3f(color[0], color[1], color[2]);
	glTranslatef(position.x, position.y, position.z);
	glRotatef(angle, 0.0f, 1.0f, 0.0f);
	glutWireTeapot(size);
	glPopMatrix();
}

