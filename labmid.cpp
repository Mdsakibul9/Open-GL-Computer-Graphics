#include <GL/gl.h>
#include <GL/glut.h>

void display(void)
{


    glClear(GL_COLOR_BUFFER_BIT);


    glColor3f(0.75, 0.75, 0.75);
    glBegin(GL_POLYGON);

    glVertex2d(-40, 0);
    glVertex2d(-50, 15);
    glVertex2d(-30, 15);
    glVertex2d(-20, 0);
    glVertex2d(-30, -15);
    glVertex2d(-50, -15);

    glEnd();

    glColor3f(0.75, 0.75, 0.75);
    glBegin(GL_POLYGON);

    glVertex2d(15, 0);
    glVertex2d(0, 15);
    glVertex2d(18, 15);
    glVertex2d(32, 0);
    glVertex2d(18, -15);
    glVertex2d(0, -15);

    glEnd();

    glColor3f(0.75, 0.75, 0.75);
    glBegin(GL_POLYGON);
    glVertex2d(32, 0);
    glVertex2d(48, 15);
    glVertex2d(66, 15);
    glVertex2d(52, 0);
    glVertex2d(66, -15);
    glVertex2d(48, -15);

    glEnd();


    glColor3f(0.75, 0.75, 0.75);
    glBegin(GL_POLYGON);
    glVertex2d(-20, 0);
    glVertex2d(0, 15);
    glVertex2d(0, 0);

    glEnd();
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2d(-16, 1);
    glVertex2d(-1.5, 13);
    glVertex2d(-1.5, 1);

    glEnd();

    glColor3f(0.75, 0.75, 0.75);
    glBegin(GL_POLYGON);
    glVertex2d(-20, 0);
    glVertex2d(0, -15);
    glVertex2d(-20, -15);
    glEnd();

    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2d(-18, -2);
    glVertex2d(-4, -14);
    glVertex2d(-18, -14);
    glEnd();




    glFlush();


}

void init(void) {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-100, 100, -40, 40);

}
int main(int argc, char** argv)
{
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