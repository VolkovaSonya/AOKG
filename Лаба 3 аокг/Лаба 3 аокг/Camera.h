#pragma once
#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "GL/freeglut.h"
#include "math.h"
//	КЛАСС ДЛЯ РАБОТЫ С КАМЕРОЙ
class Camera
{
private:
	//направления движения камеры
	bool	CameraLeft, CameraRight, CameraUp, CameraDown, CameraForward, CameraBackward;
	float	angle_horizon;//горизонтальный ox
	float	angle_vertical;//вертикальный oz
	float	radius;


	//	необходимые свойства
public:
	//матрица камеры
	GLdouble	CameraMatrix[9];

	//	конструкор и деструктор - загрузка начальных параметров камеры из файла и их сохранение
	Camera();
	~Camera();

	//	установка признаков нажатых клавиш
	void	setKey(bool left, bool right, bool up, bool down, bool forward, bool backward);
	//	движение камеры в ранее выбранном направлении
	//	sec - количество секунд прошедших с момента последнего вызова
	void	simulate(float sec);
	//	функция для установки матрицы камеры
	void	apply();

};