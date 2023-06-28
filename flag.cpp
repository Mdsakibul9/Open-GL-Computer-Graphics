#include <GL/gl.h>
#include <GL/glut.h>

int x, y, r, p, cx, cy;
void display(void)
{


    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.00, 0.50, 0.00);
    glBegin(GL_POLYGON);
    glVertex2d(-140, 50);
    glVertex2d(-140, 200);
    glVertex2d(140, 200);
    glVertex2d(140, 50);



    glEnd();

    glColor3f(0.6, 0.4, 0.2);
    glBegin(GL_POLYGON);
    glVertex2d(-156, -240);
    glVertex2d(-156, 200);
    glVertex2d(-141, 200);
    glVertex2d(-141, -240);

    glEnd();
    r = 50;
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

        cx = 0;
        cy = 125;


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

    glFlush();


}

void init(void) {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-250, 250, -250, 250);

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