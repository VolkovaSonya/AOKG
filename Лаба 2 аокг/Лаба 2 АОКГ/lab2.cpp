#include <stdio.h>
#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "GL/freeglut.h"
#include "GraphicObject.h"
double Colors[5][3] = { {1.0,0.0,0.0},{1.0,1.0,1.0},{0.0,0.0,1.0},{1.0,1.0,0.5},{0.0,1.0,1.0} };
// ������ �������� ��� ������
const int graphicObjectCount = 4;
GraphicObject graphicObjects[graphicObjectCount];

//int i = 0;

// ������� ���������� ������ 20 ��
void Simulation(int value)
{
	// ������������� ������� ����, ��� ���� ��������� � �����������
	glutPostRedisplay();
	// ��� �� ������� ����� ������� ��� ��� ����� 20 ��
	glutTimerFunc(20, Simulation, 0);
}

// �������, ���������� ��� ��������� �������� ����
void Reshape(int w, int h)
{
	// ���������� ����� ������� ���������, ������ ���� ������� ����
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	// ���������� ������� �������� � ���������� ��������
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(25.0, (float)w / h, 0.2, 70.0);
};


// ������� ���������� ��� ����������� ����
// � ��� ����� � �������������, �� �������� glutPostRedisplay
void Display(void)
{
	// �������� ����� �����
	glClearColor(1.0, 1.0, 0.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	// �������� ���� �������
	glEnable(GL_DEPTH_TEST);

	// ������������� ������
	//glMatrixMode(GL_MODELVIEW);
	//glLoadIdentity();
	//gluLookAt(15, 10, 20, 0, 0, 0, 0, 1, 0);

	// ������������� ������
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(15, 15, 7.5, 0, 0, 0, 0, 1, 0);

	// ������� �������
	for (int i = 0; i < graphicObjectCount; i++) {
		graphicObjects[i].draw();
	};
	// ����� ��������� � ������� �������
	glutSwapBuffers();
};
// ������� ��������� ������� ������
void KeyboardFunc(unsigned char key, int x, int y)
{
	printf("Key code is %i\n", (unsigned int)key);
};
int main(int argc, char** argv) {

	// ������������� ���������� GLUT
	glutInit(&argc, argv);
	// ������������� ������� (������ ������)
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH | GLUT_MULTISAMPLE);

	// �������� ����:
	// 1. ������������� ������� ����� ���� ����
	glutInitWindowPosition(200, 200);
	// 2. ������������� ������ ����
	glutInitWindowSize(600, 600);
	// 3. ������� ����
	glutCreateWindow("laba2");

	// ������������� �������, ������� ����� ���������� ��� ����������� ����
	glutDisplayFunc(Display);
	// ������������� �������, ������� ����� ���������� ��� ��������� �������� ����
	glutReshapeFunc(Reshape);
	// ������������� ������� ������� ����� ������� ����� 20 ��
	glutTimerFunc(20, Simulation, 0);
	// ������������� �������, ������� ����� ���������� ��� ������� �� �������
	glutKeyboardFunc(KeyboardFunc);

	graphicObjects[0].setPosition(4.0, 0.0, 0.0);
	graphicObjects[0].set�olor(1.0, 0.0, 0.0);
	graphicObjects[0].setAngle(180);
	graphicObjects[1].setPosition(-4.0, 0.0, 0.0);
	graphicObjects[1].set�olor(1.0, 1.0, 1.0);
	graphicObjects[1].setAngle(0);
	graphicObjects[2].setPosition(0.0, 0.0, 4.0);
	graphicObjects[2].set�olor(0.0, 1.0, 0.0);
	graphicObjects[2].setAngle(90);
	graphicObjects[3].setPosition(0.0, 0.0, -4.0);
	graphicObjects[3].setAngle(-90);
	graphicObjects[3].set�olor(0.0, 0.0, 1.0);

	// �������� ���� ��������� ��������� ��
	glutMainLoop();
}