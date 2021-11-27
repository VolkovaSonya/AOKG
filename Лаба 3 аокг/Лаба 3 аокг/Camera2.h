#ifndef  CAMERA2_H
#define  CAMERA2_H
#include <windows.h>
#include <GL/freeglut.h>
#include "GLM/GLM/glm.hpp"
class Camera2 {
private:
	glm::vec3 cameraPos, cameraFront, cameraUp;
	GLdouble yaw, pitch;
	float lastX, lastY;
	bool moveForward, moveBack, moveLeft, moveRight;
	
	void setVectorAndMoveValues();
	void updateCameraCords();
public:
	GLfloat speed = 30.0f;
	GLfloat sensivity = 0.05f;
	Camera2();
	Camera2(GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat);
	~Camera2(void);
	void setKey(bool, bool, bool, bool);
	void getLastXYForCamera();
	void simulate(double);
	void apply();

};
#endif

