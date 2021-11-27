#include "Camera2.h"
#include <iostream>
#include "GLM/GLM/glm.hpp"
#include "GLM/GLM/gtc/matrix_transform.hpp"

Camera2::Camera2() {
	cameraPos = glm::vec3(0.0, 0.0, 0.0);
	cameraFront = glm::vec3(0.0, 0.0, -1.0);
	cameraUp = glm::vec3(0.0, 1.0, 0.0);
	setVectorAndMoveValues();
}
Camera2::Camera2(GLfloat posX, GLfloat posY, GLfloat posZ, GLfloat targetX, GLfloat targetY, GLfloat targetZ, GLfloat upX, GLfloat upY, GLfloat upZ) {
	cameraPos = glm::vec3(posX, posY, posZ);
	cameraFront = glm::vec3(targetX, targetY, targetZ);
	cameraUp = glm::vec3(upX, upY, upZ);
	setVectorAndMoveValues();
}
Camera2::~Camera2(void) {

}
void Camera2::setKey(bool forward, bool fallback, bool left, bool right) {
	moveForward = forward;
	moveBack = fallback;
	moveLeft = left;
	moveRight = right;
}

void Camera2::simulate(double sec) {
	float deltaSpeed = speed * sec;
	if (moveForward) {
		cameraPos += deltaSpeed * cameraFront;
	}
	if (moveBack) {
		cameraPos -= deltaSpeed * cameraFront;
	}
	if (moveLeft) {
		cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * deltaSpeed;
	}
	if (moveRight) {
		cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * deltaSpeed;
	}
	updateCameraCords();
}
void Camera2::getLastXYForCamera() {
	lastX = glutGet(GLUT_SCREEN_WIDTH) / 2;
	lastY = glutGet(GLUT_SCREEN_HEIGHT) / 2;
}
void Camera2::apply() {
	glm::vec3 newFront = cameraFront + cameraPos;
	gluLookAt(cameraPos.x, cameraPos.y, cameraPos.z, newFront.x, newFront.y, newFront.z, cameraUp.x, cameraUp.y, cameraUp.z);
}

void Camera2::updateCameraCords() {
	cameraPos = glm::vec3(cameraPos.x, cameraPos.y, cameraPos.z);
	cameraFront = glm::vec3(cameraFront.x, cameraFront.y, cameraFront.z);
	cameraUp = glm::vec3(cameraUp.x, cameraUp.y, cameraUp.z);
}
void Camera2::setVectorAndMoveValues() {
	yaw = -90.0;
	pitch = 0.0;
	moveLeft = false;
	moveRight = false;
	moveForward = false;
	moveBack = false;
}
