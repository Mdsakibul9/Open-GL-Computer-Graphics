#include <GL/gl.h>
#include <GL/glut.h>

float x, y, r, p, cx, cy, x1 = -10;
float circlePos = -130.0;  // Initial x position of the circle

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

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

        cx = circlePos;  // Use the dynamic x position

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

    // Update the circle position
    circlePos += 0.01;  // Adjust the value to control the speed of the movement
    if (circlePos > 250.0) {
        circlePos = -250.0;  // Reset the position when it goes beyond the window boundary
    }

    glutPostRedisplay();
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