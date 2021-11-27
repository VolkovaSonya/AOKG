#include <stdio.h>
#include <GL/freeglut.h>
#include <GL/GL.h>
#include <GL/GLU.h>
#include <windows.h>
#include <string>
#include <algorithm>
#include <cmath>
#include <iostream>
#include "GraphicObject.h"
#include "Camera2.h"
#include "Camera.h"


const char* title = "LAB3";
const int gObjectCount = 4;
int windowSizeX = 1024, windowSizeY = 768;

float Positions[gObjectCount][3] = {
	{-4.0f,0,0}, {0,0,4.0f}, {0,0,-4.0f}, {4.0f,0,0}
};
float Angles[gObjectCount] = {
	0.0f, 90.0f, -90.0f, -180.0f
};
float Colors[gObjectCount][3] = {
	{1, 0, 0}, {0, 1, 0}, {0, 0, 1}, {1, 1, 1}
};
float objectSize = 1.0f;

GraphicObject** gObjects;

Camera camera1;
Camera2 camera2;

unsigned char State = 1;

LARGE_INTEGER OldValue, NewValue, Time, frequency, n_v, o_v;
float count_fps=0.0;

inline double thisDelta(LARGE_INTEGER& nTick, LARGE_INTEGER& oTick) {
	return double(nTick.QuadPart - oTick.QuadPart) / frequency.QuadPart;
}

inline double getSimTime() {
	o_v = n_v;
	QueryPerformanceCounter(&n_v);
	return thisDelta(n_v, o_v);
}

void FPS() {
	QueryPerformanceCounter(&n_v);
	double delta = thisDelta(n_v, o_v);
	if (delta > 0.5) {
		std::string tmp1(title);
		std::string tmp2 = tmp1 + " FPS: " + std::to_string((int)(count_fps / delta));
		const char* tmpChar = tmp2.c_str();
		glutSetWindowTitle(tmpChar);
		count_fps = 0;
		o_v = n_v;
	}
}

void Simulation() {
	/*double simTimePassed = getSimTime();*/
	OldValue = NewValue;
	QueryPerformanceCounter(&NewValue);//возвращает текущее значение счетчика производительности реализуемого операционной системой	
	QueryPerformanceFrequency(&Time);//на сколько увеличивается внутренний счетчик производительности за одну секунду
	double SimulationTime = ((double)NewValue.QuadPart / Time.QuadPart) - ((double)OldValue.QuadPart / Time.QuadPart);//время между двумя моментами
	bool CameraLeft = GetAsyncKeyState(VK_LEFT);
	bool CameraRight = GetAsyncKeyState(VK_RIGHT);
	bool CameraUp = GetAsyncKeyState(VK_UP);
	bool CameraDown = GetAsyncKeyState(VK_DOWN);
	bool CameraForward = GetAsyncKeyState(VK_SPACE);
	bool CameraBackward = GetAsyncKeyState(VK_TAB);
	if (State == 1) {
		camera1.setKey(CameraLeft, CameraRight,
			CameraUp, CameraDown,
			CameraForward, CameraBackward);
		camera1.simulate(SimulationTime);
	}
	else if (State == 2) {
		camera2.setKey(CameraUp, CameraDown, CameraLeft, CameraRight);
		camera2.simulate(SimulationTime);
	}
	glutPostRedisplay();
}

void Reshape(int w, int h) {
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(25.0, (double)w / h, 0.1, 100.0);
}

void Display(void) {
	QueryPerformanceCounter(&n_v);
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	if (State == 1) {
		camera1.apply();
	}
	else if (State == 2) {
		camera2.apply();
	}
	for (int i = 0; i < gObjectCount; i++)
		gObjects[i]->draw();
	glutSwapBuffers();
	count_fps++;
	FPS();
	count_fps++;
}


void Keyboard(unsigned char key, int x, int y) {
	switch (key) {
	case '1': {
		std::cout << "\1";
		State = 1;

	}; break;
	case '2': {
		std::cout << "\n2";
		State = 2;
		camera2.getLastXYForCamera();
	}; break;
	}
}

int main(int argc, char** argv) {
	QueryPerformanceFrequency(&frequency);

	gObjects = new GraphicObject * [gObjectCount];
	for (int i = 0; i < gObjectCount; i++)
		gObjects[i] = new GraphicObject(Positions[i], Angles[i], Colors[i]);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_MULTISAMPLE);
	glutInitWindowPosition(300, 300);
	glutInitWindowSize(windowSizeX, windowSizeY);
	glutCreateWindow(title);
	glutDisplayFunc(Display);
	glutReshapeFunc(Reshape);
	glutIdleFunc(Simulation);
	glutKeyboardFunc(Keyboard);
	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);
	QueryPerformanceCounter(&n_v);
	
	glutMainLoop();
	for (int i = 0; i < gObjectCount; i++)
		delete[i] gObjects[i];
	delete[] gObjects;
	return 0;
}