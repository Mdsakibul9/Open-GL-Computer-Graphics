#include<GL/gl.h>
#include<GL/glut.h>

int x, y, r, p, i, j, xc, yc;
void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);

    r = 150;
    x = 0;
    p = 1 - r;

    y = r;


    while (x < y) {
        if (p < 0) {
            x++;

            p = p + (2 * x) + 1;
        }
        else {
            x++;
            y = y - 1;

            p = p + (2 * x) + 1 - (2 * y);
        }
        xc = 0, yc = 30;
        glColor3f(1.0, 0.25, 0.0);
        glBegin(GL_POLYGON);
        glVertex2d(xc + x, yc + y);
        glVertex2d(xc - x, yc + y);
        glVertex2d(xc + x, yc - y);
        glVertex2d(xc - x, yc - y);


        glVertex2d(xc + y, yc + x);
        glVertex2d(xc - y, yc + x);
        glVertex2d(xc + y, yc - x);
        glVertex2d(xc - y, yc - x);

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

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1000, 1000);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("201-15-13625");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;



}