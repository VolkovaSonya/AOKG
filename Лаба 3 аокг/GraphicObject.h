#ifndef  GRAPHICOBJECT_H
#define  GRAPHICOBJECT_H
#include <windows.h>
#include <GL/freeglut.h>
#include <ostream>
struct pos {
	float x;
	float y;
	float z;
};

class GraphicObject {
private:
	pos position;
	float color[3];
	float angle;
	float size;
public:
	GraphicObject();
	GraphicObject(float* pos, float ang, float* color, float size = 1.0f);
	void setPosition(float x, float y, float z);
	//void setAngle(GLfloat ang);
	// Задать угол поворота в градусах относительно оси OY
	void setAngle(float a);
	// Задать цвет модели
	void setColor(float r, float g, float b);
	void setSize(float size);
	void draw(void);

};
#endif
