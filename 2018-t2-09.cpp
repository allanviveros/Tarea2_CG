// Universidad Tecnica Federico Santa Maria
// Departamento de Informatica
// INF342 Computación Grafica
// Hubert Hoffmann
// T2
// Juan Pablo Leon (201473047-2)
// Allan Viveros (201473056-k)
// Numero de Grupo: 9

#include <GL/glut.h>
#include "iostream"
using namespace std;

void init();
void mydisplay();
//Rectangle
float speedMoveRectangle = 0;
void AnimationRectangle(int time);
void CreateRectangle();
void MoveRectangle();
//Triangle
float speedRotateRectangle = 0;
void CreateTriangle();
void RotateTriangle();
void AnimationTriangle(int time);

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(700, 700);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Tarea 2, Computación Gráfica: Juan Pablo León y Allan Viveros");
	glutDisplayFunc(mydisplay);
	init();
	glutTimerFunc(0, AnimationRectangle, 10);
	glutTimerFunc(0, AnimationTriangle, 10);
	glutMainLoop();
}

void init() {
	glClearColor(1.0, 1.0, 1.0, 1.0); //color de fondo
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
}

void mydisplay(){
	glClear(GL_COLOR_BUFFER_BIT);

	MoveRectangle();
	
	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex2f(0.0, 0.0);
	glVertex2f(0.9, 0.0);
	glVertex2f(0.9, -0.9);
	glVertex2f(0.0, -0.9);
	glEnd();


	RotateTriangle();

	glFlush();
}

//Rectangle

void CreateRectangle() {
	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_POLYGON);
	glVertex2f(-0.9, 0.9);
	glVertex2f(0.9, 0.9);
	glVertex2f(0.9, 0.3);
	glVertex2f(-0.9, 0.3);
	glEnd();
}

void AnimationRectangle(int time) {
	speedMoveRectangle += 0.003;
	if (speedMoveRectangle > 2) {
		speedMoveRectangle = -2;
	}
	glutTimerFunc(time, AnimationRectangle, time);
	glutPostRedisplay();
}

void MoveRectangle() {
	glPushMatrix();
	glTranslatef(speedMoveRectangle, 0.0, 0.0);
	CreateRectangle();
	glPopMatrix();
}

//Triangle
void CreateTriangle() {
	glColor3f(1.0, 0.0, 0);
	glBegin(GL_TRIANGLES);
	glVertex2f(-0.55, 0.0);
	glVertex2f(-0.2, -0.9);
	glVertex2f(-0.9, -0.9);
	glEnd();
}

void AnimationTriangle(int time) {
	speedRotateRectangle += 1.5;
	glutTimerFunc(time, AnimationTriangle, time);
	glutPostRedisplay();
}

void RotateTriangle() {
	glPushMatrix();
	glTranslatef(-0.55, -0.45, 0);
	glRotatef(speedRotateRectangle, 0, 0, 1);
	glTranslatef(0.55, 0.45, 0);
	CreateTriangle();
	glPopMatrix();
}