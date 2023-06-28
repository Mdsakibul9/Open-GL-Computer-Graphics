#include<GL/gl.h>
#include<GL/glut.h>


void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);

    glLineWidth(2.0);

    glColor3f(0.0, 1.0, 0.0);
    glBegin(GL_POLYGON);


    glVertex2d(15, 20);
    glVertex2d(15, 35);
    glVertex2d(50, 0);
    glVertex2d(15, -35);
    glVertex2d(15, -20);
    glVertex2d(-60, -20);
    glVertex2d(-60, 20);

    glEnd();

    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2d(-55, -15);
    glVertex2d(-55, 15);
    glVertex2d(15, 15);
    glVertex2d(15, -15);
    glVertex2d(-55, -15);
    glEnd();

    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2d(18, 25);
    glVertex2d(45, 0);
    glVertex2d(18, -25);
    glVertex2d(18, 25);
    glEnd();

    glColor3f(0.0, 1.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2d(50, 0);
    glVertex2d(70, 20);
    glVertex2d(90, 0);
    glVertex2d(70, -20);
    glEnd();

    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2d(55, 0);
    glVertex2d(70, 15);
    glVertex2d(85, 0);
    glVertex2d(70, -15);
    glEnd();


    glFlush();


}






void init(void) {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-100, 100, -100, 100);

}



int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("201-15-13625");
    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}