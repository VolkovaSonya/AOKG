#define _USE_MATH_DEFINES
#include "Camera.h"
#include <iostream>
#include <cmath>
#include "GLM/GLM/glm.hpp"
#include <GL/freeglut.h>

Camera::Camera() {
	cameraPos = glm::vec3(15.0, 15.0, 7.5);
	cameraFront = glm::vec3(0.0, 0.0, 0.0);
	cameraUp = glm::vec3(0.0, 1.0, 0.0);
	setVectorAndMoveValues();
	updateCameraCords();
}
Camera::Camera(GLfloat posX, GLfloat posY, GLfloat posZ, GLfloat targetX, GLfloat targetY, GLfloat targetZ, GLfloat upX, GLfloat upY, GLfloat upZ, GLfloat yaw, GLfloat pitch) {
	cameraPos = glm::vec3(posX, posY, posZ);
	cameraFront = glm::vec3(targetX, targetY, targetZ);
	cameraUp = glm::vec3(upX, upY, upZ);
	setVectorAndMoveValues();
	updateCameraCords();
}
Camera::~Camera(void) {

}
void Camera::setKey(bool left, bool right, bool up, bool down, bool forward, bool backward) {
	moveLeft = left;
	moveRight = right;
	moveUp = up;
	moveDown = down;
	zoomIn = forward;
	zoomOut = backward;
}
void Camera::simulate(double sec) {
	if (moveLeft) {
		yaw += sec * speed;
	}
	if (moveRight) {
		yaw -= sec * speed;
	}
	if (moveUp) {
		pitch += sec * speed;
	}
	if (moveDown) {
		pitch -= sec * speed;
	}
	if (zoomIn) {
		radius -= sec * speed;
	}
	if (zoomOut) {
		radius += sec * speed;
	}
	if (yaw > 360) {
		yaw = 0.0 + sec * speed;
	}
	else {
		if (yaw < 0)
			yaw = 360.0 - sec * speed;
	}
	if (pitch > 89)
		pitch = 89;
	else if (pitch < -89)
		pitch = -89.0;
	if (radius < 1)
		radius = 1;
	else if (radius > 90)
		radius = 90;

	updateCameraCords();
}
void Camera::apply() {
	gluLookAt(cameraPos.x, cameraPos.y, cameraPos.z, cameraFront.x, cameraFront.y, cameraFront.z, cameraUp.x, cameraUp.y, cameraUp.z);
}
void Camera::updateCameraCords() {
	cameraPos.x = radius * cos(glm::radians(pitch)) * cos(glm::radians(yaw));
	cameraPos.y = radius * sin(glm::radians(pitch));
	cameraPos.z = radius * cos(glm::radians(pitch)) * sin(glm::radians(yaw));
}
void Camera::setVectorAndMoveValues() {
	radius = cameraPos.x;
	pitch = cameraPos.y;
	yaw = cameraPos.z;
	moveLeft = false;
	moveRight = false;
	moveUp = false;
	moveDown = false;
	zoomIn = false;
	zoomOut = false;
}
