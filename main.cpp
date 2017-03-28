#include "stdafx.h"
#include "platecglut.h"

#define d_map_size 5
#define d_initial_height 0.5f

void update(int value);
void reshape(int w, int h);
void keyboard(unsigned char key, int x, int y);
void display(void);
std::vector<float> display_map;
int main(int argc, char **argv)
{
	GeometryGenerator geo_gen;
	std::vector<float> display_map = geo_gen.CreateTestTerrain(d_map_size, d_initial_height);
	
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Plate Tectonics Demo");
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutTimerFunc(1000, update, 0);
	glutMainLoop();
	return 0;
}

void update(int value)
{
	glutPostRedisplay();
}

void reshape(int w, int h)
{
}

void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 27: exit(0);
	default: break;
	}
}

void display(void)
{


	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_POINTS);
	{

		for (size_t y = 0; y < d_map_size; ++y)
			for (size_t x = 0; x < d_map_size; ++x)
			{
				





			}
	} glEnd();

	glutSwapBuffers();
}