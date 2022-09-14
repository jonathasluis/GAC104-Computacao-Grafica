#include <iostream>
#include <GL/glut.h> // a glut inclui a gl.h

void desenhaParede(){
    glBegin(GL_LINES);
    glVertex2d(0.95,-0.8);
    glVertex2d(0.95,0.95);
    glVertex2d(-0.95,0.95);
    glVertex2d(0.95,0.95);
    glVertex2d(-0.95,0.95);
    glVertex2d(-0.95,-0.95);
    glVertex2d(0.95,-0.95);
    glVertex2d(-0.95,-0.95);
    glVertex2d(0.95,-0.95);
    glVertex2d(0.95,-0.9);
    glEnd();
}

void desenhaJanela(){
    glBegin(GL_LINE_LOOP);
    glVertex2d(-0.95,0.4);
    glVertex2d(-0.95,0.7);
    glVertex2d(-0.9,0.7);
    glVertex2d(-0.9,0.4);
    glEnd();
}
    

void desenhaCama(){
    glBegin(GL_LINE_LOOP);
    glVertex2d(-0.8,-0.9);
    glVertex2d(-0.8,-0.5);
    glVertex2d(0.2,-0.5);
    glVertex2d(0.2,-0.9);
    glEnd();

    glBegin(GL_LINES);
    glVertex2d(-0.5,-0.5);
    glVertex2d(-0.5,-0.9);
    glEnd();
}

void desenhaGuardaRoupa(){
    glBegin(GL_LINE_LOOP);
    glVertex2d(0.6,-0.4);
    glVertex2d(0.9,-0.4);
    glVertex2d(0.9,0.9);
    glVertex2d(0.6,0.9);
    glEnd();  
}

void desenhaComoda(){
    glBegin(GL_LINE_LOOP);
    glVertex2d(-0.8,0.9);
    glVertex2d(-0.3,0.9);
    glVertex2d(-0.3,0.7);
    glVertex2d(-0.8,0.7);
    glEnd();
}

void desenhaCriado(){
    glBegin(GL_LINE_LOOP);
    glVertex2d(-0.8,-0.3);
    glVertex2d(-0.5,-0.3);
    glVertex2d(-0.5,0.0);
    glVertex2d(-0.8,0.0);
    glEnd();
}

void RenderScene()
{
    glClear(GL_COLOR_BUFFER_BIT);
    desenhaParede();
    desenhaJanela();
    desenhaCama();
    desenhaGuardaRoupa();
    desenhaComoda();
    desenhaCriado();
    glFlush();
}

void SetupRC()
{
    glClearColor(0.0f, 0.0f, 1.0f, 1.0f);  // cor de fundo da janela
}



int main(int argc, char* argv[])
{
    // Procedimento de inicializacao da GLUT
    glutInit(&argc, argv);

    // Indica que deve ser usado um unico frame buffer e representacao de cores RGB
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    // Cria uma janela com o titulo especificado
    glutCreateWindow("Programa Basico com OpenGL e GLUT");

    // Especifica para a OpenGL que funcao deve ser chamada para geracao da imagem
    glutDisplayFunc(RenderScene);

    // Executa a inicializacao de parametros de exibicao
    SetupRC();

    // Escrever informacoes sobre a versao de OpenGL em uso porque pode ser util saber.
    std::cout << "Usando OpenGL '" << glGetString(GL_VERSION) << "' implementado por '"
              << glGetString(GL_VENDOR) << "' em arquitetura '" << glGetString(GL_RENDERER)
              << "'.\nExtensoes disponiveis: " << glGetString(GL_EXTENSIONS) << std::endl;

    // Entra no loop de tratamento de eventos da GLUT
    glutMainLoop();
    return 0;
}
