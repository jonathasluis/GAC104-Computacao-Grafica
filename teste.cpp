#include <cstdlib>
#include <iostream>
#include <GL/glut.h>
// using namespace std;

GLfloat horzangle = -45.0, vertangle = 30.0, distance = -3.0;

#define SPACEBAR 32
#define RETURN 13

void RenderScene(void)
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0f, 0.0f, distance);
    glRotatef(vertangle, 1.0f, 0.0f, 0.0f);
    glRotatef(horzangle, 0.0f, 1.0f, 0.0f);
    glEnable(GL_DEPTH_TEST);
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    /*glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.7f, 0.0f, 0.0f);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 0.5f, 0.0f);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, 0.7f);
    glEnd();*/

    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 0.2f, 0.0f);
    glVertex3f(0.2f, 0.3f, 0.0f);
    glVertex3f(0.4f, 0.2f, 0.0f);
    glVertex3f(0.4f, 0.0f, 0.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, 0.4f);
    glVertex3f(0.0f, 0.2f, 0.4f);
    glVertex3f(0.0f, 0.2f, 0.0f);
    glEnd();

    glBegin(GL_QUAD_STRIP);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(0.0f, 0.2f, 0.0f);
    glVertex3f(0.0f, 0.2f, 0.4f);
    glVertex3f(0.2f, 0.3f, 0.0f);
    glVertex3f(0.2f, 0.3f, 0.4f);
    glVertex3f(0.4f, 0.2f, 0.0f);
    glVertex3f(0.4f, 0.2f, 0.4f);
    glEnd();

    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_LINE_STRIP);
    glVertex3f(0.0f, 0.0f, 0.4f);
    glVertex3f(0.4f, 0.0f, 0.4f);
    glVertex3f(0.4f, 0.0f, 0.0f);
    glEnd();
    
    glBegin(GL_LINES);
    glVertex3f(0.4f, 0.0f, 0.4f);
    glVertex3f(0.4f, 0.2f, 0.4f);
    glEnd();
    glFlush();
    glutSwapBuffers();
}

void ChangeSize(GLsizei width, GLsizei height)
{
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(30.0, width / height, 1.0, 10.0);
}

void SpecialKeys(int key, int x, int y)
{

    if (key == GLUT_KEY_UP)
        vertangle -= 5;

    if (key == GLUT_KEY_DOWN)
        vertangle += 5;

    if (key == GLUT_KEY_LEFT)
        horzangle -= 5;

    if (key == GLUT_KEY_RIGHT)
        horzangle += 5;

    glutPostRedisplay();
}

void KeyboardFunc(unsigned char key, int x, int y)
{
    if (key == 27) // se for a tecla ESC...
        exit(0);   // ...termina o programa

    if (key == ' ')
        distance += 0.5;

    if ((int)key == RETURN)
        distance -= 0.5;

    if (key == 'p')
        std::cout << "implementar";

    glutPostRedisplay();
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGBA);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("OpenGL - Mouse");
    glutReshapeFunc(ChangeSize);
    glutKeyboardFunc(KeyboardFunc);
    glutSpecialFunc(SpecialKeys);

    glutDisplayFunc(RenderScene);
    glutMainLoop();
    return 0;
}
