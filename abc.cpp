#include<windows.h>
#include<GL/glut.h>
#include<GL/gl.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.0, 1.0, 0.0);
    glBegin(GL_TRIANGLES);
    glVertex3f(250.0, 675.0, 0.0);
    glVertex3f(500.0, 925.0, 0.0);
    glVertex3f(750.0, 675.0, 0.0);
    glEnd();

    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex3f(250.0, 100.0, 0.0);
    glVertex3f(250.0, 675.0, 0.0);
    glVertex3f(750.0, 675.0, 0.0);
    glVertex3f(750.0, 100.0, 0.0);
    glEnd();

    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex3f(400.0, 100.0, 0.0);
    glVertex3f(400.0, 500.0, 0.0);
    glVertex3f(600.0, 500.0, 0.0);
    glVertex3f(600.0, 100.0, 0.0);
    glEnd();

    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex3f(275.0, 300.0, 0.0);
    glVertex3f(275.0, 400.0, 0.0);
    glVertex3f(375.0, 400.0, 0.0);
    glVertex3f(375.0, 300.0, 0.0);
    glEnd();

    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex3f(625.0, 300.0, 0.0);
    glVertex3f(625.0, 400.0, 0.0);
    glVertex3f(725.0, 400.0, 0.0);
    glVertex3f(725.0, 300.0, 0.0);
    glEnd();

    glFlush();


}

void init(void) {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 1000, 0, 1000);

}


int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("201-15-13625_sec:A_Sakib");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}