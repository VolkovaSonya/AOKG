#ifndef  CAMERA_H
#define  CAMERA_H
#include <windows.h>
#include <GL/freeglut.h>
#include "GLM/GLM/glm.hpp"

class Camera {
private:
	glm::vec3 cameraRight, cameraDirection, cameraPos, cameraFront, cameraUp;
	GLdouble radius;
	GLdouble yaw;//угловые движения объекта относительно вертикальной оси, а также небольшие изменения курса вправо или влево
	GLdouble pitch;//угловое движение объекта относительно главной поперечной оси инерции (величина того, насколько мы смотрим вверх или вниз)
	bool moveLeft, moveRight,
		moveUp, moveDown,
		zoomIn, zoomOut;
	void setVectorAndMoveValues();
	void updateCameraCords();
public:
	GLdouble speed = 90.0;
	Camera();
	Camera(float, float, float, float, float, float, float, float, float, float, float);
	~Camera(void);
	void setKey(bool, bool, bool, bool, bool, bool);
	void simulate(double);
	void apply();
};
#endif
