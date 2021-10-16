
#ifndef GRAPHICOBJECT_H
#define GRAPHICOBJECT_H
#include <stdio.h>
#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "GL/freeglut.h"
#include "math.h"

#include "GLM/GLM/glm.hpp"
#include "GLM/GLM/gtx/transform.hpp"
#include "GLM/GLM/gtc/type_ptr.hpp"
//using namespace glm;

class GraphicObject
{
private:
	// Позиция и угол поворота для объекта
	//GLfloat position[3];
	GLfloat angle;
	// Матрица модели (расположение объекта) ‐ чтоб не вычислять каждый раз
	//GLfloat modelMatrix[16];
	// Цвет модели
	//GLfloat color[3];
	glm::mat4 modelMatrix;
	glm::vec3 position;
	glm::vec3 color;
public:
	// Конструктор
	GraphicObject(void);
	// Задать позицию объекта
	void setPosition(float x, float y, float z);
	// Задать угол поворота в градусах относительно оси OY
	void setAngle(float a);
	// Задать цвет модели
	void setСolor(float r, float g, float b);
	// Вывести объект
	void draw(void);
};
#endif
