/*
Exercicio Pratico 05
Nome: Jonathas Luis De Sousa
Matricula: 202010136
Plataforma: Linux
Linguagem: C++
*/
#include <cstdlib>
#include <iostream>
#include <GL/glut.h>
GLfloat horzangle = -45.0, vertangle = 30.0, distance = -3.0;
#define SPACEBAR 32
#define RETURN 13
int op = 1;
/* Create checkerboard texture */
#define checkImageWidth 64
#define checkImageHeight 64
static GLubyte checkImage[checkImageHeight][checkImageWidth][4];
#ifdef GL_VERSION_1_1
static GLuint texName;
#endif
void makeCheckImage(void)
{
    int i, j, c;
    for (i = 0; i < checkImageHeight; i++)
    {
        for (j = 0; j < checkImageWidth; j++)
        {
            c = ((((i & 0x8) == 0) ^ ((j & 0x8)) == 0)) * 255;
            checkImage[i][j][0] = (GLubyte)c;
            checkImage[i][j][1] = (GLubyte)c;
            checkImage[i][j][2] = (GLubyte)c;
            checkImage[i][j][3] = (GLubyte)255;
        }
    }
}
void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
    glEnable(GL_DEPTH_TEST);
    makeCheckImage();
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
#ifdef GL_VERSION_1_1
    glGenTextures(1, &texName);
    glBindTexture(GL_TEXTURE_2D, texName);
#endif
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
#ifdef GL_VERSION_1_1
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, checkImageWidth,
                 checkImageHeight,
                 0, GL_RGBA, GL_UNSIGNED_BYTE, checkImage);
#else
    glTexImage2D(GL_TEXTURE_2D, 0, 4, checkImageWidth, checkImageHeight,
                 0, GL_RGBA, GL_UNSIGNED_BYTE, checkImage);
#endif
}
void RenderScene(void)
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0f, 0.0f, distance);
    glRotatef(vertangle, 1.0f, 0.0f, 0.0f);
    glRotatef(horzangle, 0.0f, 1.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
#ifdef GL_VERSION_1_1
    glBindTexture(GL_TEXTURE_2D, texName);
#endif
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, 0.4f);
    glVertex3f(0.0f, 0.2f, 0.4f);
    glVertex3f(0.0f, 0.2f, 0.0f);
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
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 0.2f, 0.0f);
    glVertex3f(0.2f, 0.3f, 0.0f);
    glVertex3f(0.4f, 0.2f, 0.0f);
    glVertex3f(0.4f, 0.0f, 0.0f);
    glEnd();
    glEnable(GL_TEXTURE_2D);
    glBegin(GL_QUAD_STRIP);
    glColor3f(0.0f, 1.0f, 1.0f);
    glTexCoord2f(0.0, 0.0);
    glVertex3f(0.0f, 0.2f, 0.0f);
    glTexCoord2f(0.0, 1.0);
    glVertex3f(0.0f, 0.2f, 0.4f);
    glTexCoord2f(1.0, 1.0);
    glVertex3f(0.2f, 0.3f, 0.0f);
    glTexCoord2f(1.0, 0.0);
    glVertex3f(0.2f, 0.3f, 0.4f);
    glTexCoord2f(0.0, 0.0);
    glVertex3f(0.4f, 0.2f, 0.0f);
    glTexCoord2f(0.0, 1.0);
    glVertex3f(0.4f, 0.2f, 0.4f);
    glEnd();
    glDisable(GL_TEXTURE_2D);
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
    glutPostRedisplay();
}
int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGBA);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("OpenGL - Mouse");
    init();
    glutReshapeFunc(ChangeSize);
    glutKeyboardFunc(KeyboardFunc);
    glutSpecialFunc(SpecialKeys);
    glutDisplayFunc(RenderScene);
    glutMainLoop();
    return 0;
}