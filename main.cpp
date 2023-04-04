#include <stdlib.h>
#include <GL/glut.h>
#include <iostream>

#include "definitions.h"
#include "lines.h"
#include "shapes.h"

Color BgColor = Color(255,255,255);

GLint WINDOW_WIDTH = 600,
      WINDOW_HEIGHT = 600;

void InitGlut(int *argc, char **argv) {
    glutInit(argc, argv);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    GLint screen_width = glutGet(GLUT_SCREEN_WIDTH),
          screen_height = glutGet(GLUT_SCREEN_HEIGHT);

    glutInitWindowPosition((screen_width - WINDOW_WIDTH) / 2, (screen_height - WINDOW_WIDTH) / 2);
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    glutCreateWindow("House");
}

void Init(GLvoid) {
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, WINDOW_WIDTH, WINDOW_HEIGHT, 0);
}

void DrawTriangle(Point p1, Point p2, Point p3, Color color){
    glLineWidth(5.0);
    glBegin(GL_TRIANGLES);
        glColor3f(color.red, color.green, color.blue);
        glVertex2i(p1.x, p1.y);

        glColor3f(color.red, color.green, color.blue);
        glVertex2i(p2.x, p2.y);

        glColor3f(color.red, color.green, color.blue);
        glVertex2i(p3.x, p3.y);
    glEnd();
}

void DrawSquare(Point p1, Point p2, Point p3, Point p4, Color color){
    glLineWidth(5.0);
    glBegin(GL_POLYGON);
        glColor3f(color.red, color.green, color.blue);
        glVertex2i(p1.x, p1.y);

        glColor3f(color.red, color.green, color.blue);
        glVertex2i(p2.x, p2.y);

        glColor3f(color.red, color.green, color.blue);
        glVertex2i(p3.x, p3.y);

        glColor3f(color.red, color.green, color.blue);
        glVertex2i(p4.x, p4.y);
    glEnd();
}

void Draw(GLvoid){
    glClearColor(BgColor.red, BgColor.green, BgColor.blue, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    Shapes();
    Lines();

    glFlush();
}

void GreyBackground(int key, int x, int y){
    BgColor = COLOR_GREY;
    glutPostRedisplay();
}

void BlackBackground(unsigned char key, int x, int y){
    if(glutGetModifiers() == GLUT_ACTIVE_CTRL){
        if(key == ' '){
            BgColor = COLOR_BLACK;
        }
    }
    else{
        BgColor = COLOR_WHITE;
    }
    glutPostRedisplay();
}

int main(int argc, char *argv[]) {
    InitGlut(&argc, argv);
    Init();

    glClear(GL_COLOR_BUFFER_BIT);
    glutDisplayFunc(Draw);
    glutSpecialFunc(GreyBackground);
    glutKeyboardFunc(BlackBackground);
    glutMainLoop();

    return EXIT_SUCCESS;
}
