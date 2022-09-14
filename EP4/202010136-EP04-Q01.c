#include <stdio.h>
#include <GL/glut.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

void init()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
}

void ponto(float x, float y)
{
    glBegin(GL_POINTS);
    glVertex2f(x, y);
    glEnd();
}

float Numrandom(float minimo, float maximo)
{
    srand(time(NULL));
    float scale = rand() / (float)RAND_MAX;
    return minimo + scale * (maximo - minimo);
}


int run = 1;

void display(void)
{
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glPointSize(10);


    float x0 = Numrandom(-1.0f, 1.0f);
    float x1 = Numrandom(x0, 1.0f);
    float a =  Numrandom(-1.0f, 1.0f) * -1;

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
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (w <= h)
        glOrtho(-1.5, 1.5, -1.5 * (GLfloat)h / (GLfloat)w,
                1.5 * (GLfloat)h / (GLfloat)w, -10.0, 10.0);
    else
        glOrtho(-1.5 * (GLfloat)w / (GLfloat)h,
                1.5 * (GLfloat)w / (GLfloat)h, -1.5, 1.5, -10.0, 10.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'p':
        if (run == 1)
        {
            run = 0;
        }
        else
        {
            run = 1;
        }
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
    glutIdleFunc(idle);
    glutDisplayFunc(display);
    init();
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}