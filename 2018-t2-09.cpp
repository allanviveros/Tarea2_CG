// Universidad Tecnica Federico Santa Maria
// Departamento de Informatica
// INF342 Computación Grafica
// Hubert Hoffmann
// T2
// Juan Pablo Leon (201473047-2)
// Allan Viveros (201473056-k)
// Numero de Grupo: 9

#include <GL/glut.h>

void init();
void mydisplay();

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(700, 700);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Tarea 2, Computación Gráfica: Juan Pablo León y Allan Viveros");
	glutDisplayFunc(mydisplay);

	init();

	glutMainLoop();

}

void init() {
	glClearColor(1.0, 1.0, 1.0, 1.0); //color de fondo
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
}

void mydisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_POLYGON);
	glVertex2f(-0.9, 0.9);
	glVertex2f(0.9, 0.9);
	glVertex2f(0.9, 0.3);
	glVertex2f(-0.9, 0.3);
	glEnd();

	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex2f(0.0, 0.0);
	glVertex2f(0.9, 0.0);
	glVertex2f(0.9, -0.9);
	glVertex2f(0.0, -0.9);
	glEnd();

	glColor3f(1.0, 0.0, 0);
	glBegin(GL_TRIANGLES);
	glVertex2f(-0.55, 0.0);
	glVertex2f(-0.2, -0.9);
	glVertex2f(-0.9, -0.9);
	glEnd();
	glFlush();
}
