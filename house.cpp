#include<GL/gl.h>
#include<GL/glut.h>

int x, y, r, p, i, j, xc, yc;
void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0, 0.25, 0.0);
    glBegin(GL_POLYGON);
    glVertex2d(-125, 200);
    glVertex2d(125, 200);
    glVertex2d(125, -175);
    glVertex2d(-125, -175);


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
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("201-15-13625");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;



}