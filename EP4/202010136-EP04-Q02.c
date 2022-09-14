/*
 * Codigo do Exercício Prático 04 - 2ª parte - serrilhado
 * Nome: Jonathas Luis de Sousa
 * Matricula: 202010136
 * Plataforma: Linux
 */

#include <stdio.h>
#include <GL/glut.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

int run = 1;
int op = 0;

void init()
{
    srand(time(NULL));
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.0, 0.0, 0.0, 0.0);
}

void ponto(float x, float y)
{
    glBegin(GL_POINTS);
    glColor3f(1, 0, 0);
    glVertex2f(x, y);
    glColor3f(0.5, 0, 0);
    glVertex2f(x + 0.001, y);
    glVertex2f(x - 0.001, y);
    glEnd();
}

float Numrandom(float minimo, float maximo)
{
    float scale = rand() / (float)RAND_MAX;
    return minimo + scale * (maximo - minimo);
}

void display(void)
{
    glPointSize(3);
    float x0 = Numrandom(-1.0f, 1.0f);
    float x1 = Numrandom(x0, 1.0f);
    float a = Numrandom(-1.0f, 1.0f);

    float x = x0;
    while (x <= x1 && run == 1)
    {
        float y = a * x;
        ponto(x, y);
        x += 0.001;
    }

    glFlush();
}

void reshape(int w, int h)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (w <= h)
    {
        gluOrtho2D(-1.0, 1.0,
                   -1.0 * (GLfloat)h / (GLfloat)w, 1.0 * (GLfloat)h / (GLfloat)w);
    }
    else
    {
        gluOrtho2D(-1.0 * (GLfloat)w / (GLfloat)h,
                   1.0 * (GLfloat)w / (GLfloat)h, -1.0, 1.0);
    }
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'p':
        run *= -1;
        break;
    case 'a':
        op *= -1;
        break;
    }
    glutPostRedisplay();
}

void idle(void)
{
    sleep(1);
    glutPostRedisplay();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow(argv[0]);
    init();

    glutIdleFunc(idle);
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}