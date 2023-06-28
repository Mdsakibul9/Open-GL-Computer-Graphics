#include<GL/gl.h>
#include<GL/glut.h>

float x = 0.0;
void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);


    glColor3f(0.0, 1.0, 0.0);

    glBegin(GL_POLYGON);
    glVertex2d(x, 180);
    glVertex2d(x + 15, 180);
    glVertex2d(x + 15, 220);
    glVertex2d(x, 220);




    if (x < 400) {
        x = x + 0.01;
    }
    else {
        x = 0;
    }


    glutPostRedisplay();
    glEnd();

    glFlush();


}






void init(void) {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 400, 0, 400);

}



int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("201-15-13625 201-15-13733 201-15-13715");
    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}