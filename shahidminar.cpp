#include <GL/gl.h>
#include <GL/glut.h>

int x, y, r, p, cx, cy;
void display(void)
{


    glClear(GL_COLOR_BUFFER_BIT);

    r = 35;
    x = 0;
    y = r;
    p = 1 - r;

    while (x < y) {
        if (p < 0) {
            x = x + 1;

            p = p + (2 * x) + 1;
        }
        else {
            x = x + 1;
            y = y - 1;

            p = p + (2 * x) + 1 - (2 * y);
        }

        cx = -2.5;
        cy = 100;


        glColor3f(0.70, 0.0, 0.0);
        glBegin(GL_POLYGON);
        glVertex2d(cx + x, cy + y);
        glVertex2d(cx - x, cy + y);
        glVertex2d(cx + x, cy - y);
        glVertex2d(cx - x, cy - y);

        glVertex2d(cx + y, cy + x);
        glVertex2d(cx - y, cy + x);
        glVertex2d(cx + y, cy - x);
        glVertex2d(cx - y, cy - x);


    }
    glEnd();


    glColor3f(0.75, 0.75, 0.75);
    glBegin(GL_POLYGON);
    glVertex2d(-25, 60);
    glVertex2d(-25, 150);
    glVertex2d(-30, 150);
    glVertex2d(-30, 60);
    glEnd();
    glColor3f(0.75, 0.75, 0.75);
    glBegin(GL_POLYGON);
    glVertex2d(20, 60);
    glVertex2d(20, 150);
    glVertex2d(25, 150);
    glVertex2d(25, 60);
    glEnd();
    glColor3f(0.75, 0.75, 0.75);
    glBegin(GL_POLYGON);
    glVertex2d(-5, 60);
    glVertex2d(-5, 150);
    glVertex2d(-0, 150);
    glVertex2d(-0, 60);
    glEnd();

    glColor3f(0.75, 0.75, 0.75);
    glBegin(GL_POLYGON);
    glVertex2d(-40, 60);
    glVertex2d(-40, 145);
    glVertex2d(-65, 145);
    glVertex2d(-65, 60);
    glEnd();
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2d(-45, 60);
    glVertex2d(-45, 140);
    glVertex2d(-60, 140);
    glVertex2d(-60, 60);
    glEnd();

    glColor3f(0.75, 0.75, 0.75);
    glBegin(GL_POLYGON);
    glVertex2d(-70, 60);
    glVertex2d(-70, 125);
    glVertex2d(-95, 125);
    glVertex2d(-95, 60);
    glEnd();
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2d(-75, 60);
    glVertex2d(-75, 120);
    glVertex2d(-90, 120);
    glVertex2d(-90, 60);
    glEnd();

    glColor3f(0.75, 0.75, 0.75);
    glBegin(GL_POLYGON);
    glVertex2d(40, 60);
    glVertex2d(40, 145);
    glVertex2d(65, 145);
    glVertex2d(65, 60);
    glEnd();
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2d(45, 60);
    glVertex2d(45, 140);
    glVertex2d(60, 140);
    glVertex2d(60, 60);
    glEnd();

    glColor3f(0.75, 0.75, 0.75);
    glBegin(GL_POLYGON);
    glVertex2d(70, 60);
    glVertex2d(70, 125);
    glVertex2d(95, 125);
    glVertex2d(95, 60);
    glEnd();
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2d(75, 60);
    glVertex2d(75, 120);
    glVertex2d(90, 120);
    glVertex2d(90, 60);
    glEnd();



    glColor3f(0.75, 0.75, 0.75);
    glBegin(GL_POLYGON);
    glVertex2d(-30, 150);
    glVertex2d(-55, 180);
    glVertex2d(-50, 180);
    glVertex2d(-25, 150);
    glEnd();
    glColor3f(0.75, 0.75, 0.75);
    glBegin(GL_POLYGON);
    glVertex2d(-5, 150);
    glVertex2d(-30, 180);
    glVertex2d(-25, 180);
    glVertex2d(0, 150);
    glEnd();

    glColor3f(0.75, 0.75, 0.75);
    glBegin(GL_POLYGON);
    glVertex2d(20, 150);
    glVertex2d(-5, 180);
    glVertex2d(0, 180);
    glVertex2d(25, 150);
    glEnd();


    glColor3f(0.75, 0.75, 0.75);
    glBegin(GL_POLYGON);
    glVertex2d(-48, 175);
    glVertex2d(-50, 180);
    glVertex2d(0, 180);
    glVertex2d(0, 175);

    glEnd();

    glColor3f(0.54, 0.27, 0.07);
    glBegin(GL_POLYGON);
    glVertex2d(-100, 40);
    glVertex2d(-100, 60);
    glVertex2d(100, 60);
    glVertex2d(100, 40);

    glEnd();





    glFlush();


}

void init(void) {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-100, 100, 0, 200);

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