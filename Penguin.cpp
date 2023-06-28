#include <GL/glut.h>

void init()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-210, 210, -220, 310);
}

void drawFlower()
{
    // Draw the stem
    glColor3f(0.0f, 1.0f, 0.0f);
    glBegin(GL_POLYGON);
    glVertex2f(-10.0f, -220.0f);
    glVertex2f(-10.0f, -200.0f);
    glVertex2f(10.0f, -200.0f);
    glVertex2f(10.0f, -220.0f);
    glEnd();

    // Draw the petals
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glVertex2f(-10.0f, -190.0f);
    glVertex2f(-5.0f, -180.0f);
    glVertex2f(5.0f, -180.0f);
    glVertex2f(10.0f, -190.0f);
    glVertex2f(5.0f, -200.0f);
    glVertex2f(-5.0f, -200.0f);
    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw the flower bed background
    glColor3f(0.5f, 0.5f, 0.5f);
    glBegin(GL_POLYGON);
    glVertex2f(-210.0f, -220.0f);
    glVertex2f(-210.0f, -50.0f);
    glVertex2f(210.0f, -50.0f);
    glVertex2f(210.0f, -220.0f);
    glEnd();

    // Draw the flowers
    glPushMatrix();
    glTranslatef(-150.0f, 0.0f, 0.0f);
    drawFlower();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, 0.0f, 0.0f);
    drawFlower();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(150.0f, 0.0f, 0.0f);
    drawFlower();
    glPopMatrix();

    glFlush();
}

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1200, 800);
    glutInitWindowPosition(10, 10);
    glutCreateWindow("Flower Bed");
    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}