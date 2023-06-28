#include<windows.h>
#include<GL/glut.h>
#include<stdlib.h>
#include<math.h>
double  r = .2, s = .3, fl = 0.05;
int i;
float  tx = 10, bx = 10, cx = 10, tb = 10;

//-------------------------------Circle for flag----------------------------
void fcircle(double r, double cx, double cy) {
    int x, y, p;

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
}

//--------------------------------Flowers------------------------------------

void flower(double x, double y)
{


    glBegin(GL_TRIANGLE_FAN);
    for (i = 0;i < 360;i++)
    {
        x = x + cos((i * 3.14) / 180) * fl;
        y = y + sin((i * 3.14) / 180) * fl;

        glVertex2d(x, y);

    }


    glEnd();



}

//-----------------------sky------------------------------------------------------------------

//-----------------------cloud-----------------------------------------------------------------


void cloud(double x, double y)
{


    glBegin(GL_TRIANGLE_FAN);
    for (i = 0;i < 360;i++)
    {
        x = x + cos((i * 3.14) / 180) * r;
        y = y + sin((i * 3.14) / 180) * r;

        glVertex2d(x, y);

    }


    glEnd();



}
void sun(double x, double y)
{


    glBegin(GL_TRIANGLE_FAN);
    for (i = 0;i < 360;i++)
    {
        x = x + cos((i * 3.14) / 180) * s;
        y = y + sin((i * 3.14) / 180) * s;

        glVertex2d(x, y);

    }


    glEnd();



}
// ------------------------------------Fence-------------------------------------------------
void fence(int x)
{
    glBegin(GL_POLYGON);
    glColor3f(0.72, 0.52, 0.04);

    glVertex2d(190 - x, 130);
    glVertex2d(190 - x, 70);
    glVertex2d(187 - x, 70);
    glVertex2d(187 - x, 130);
    glVertex2d(190 - x, 130);



    glEnd();

}

//--------------------------------------------------------------------------------------------





void display()
{

    glClear(GL_COLOR_BUFFER_BIT);
    //-----------------------sky------------------------------------------------------------------
    glColor3ub(135, 206, 250);//light blue
    glRecti(-200, 300, 200, 100);
    //-----------------------------------field------------------------------
    glBegin(GL_POLYGON);
    glColor3ub(0, 100, 0);//green

    glVertex2d(-200, 100);
    glVertex2d(-100, 160);
    glVertex2d(0, 100);
    glVertex2d(50, 70);
    glVertex2d(100, 180);
    glVertex2d(200, 100);
    glColor3ub(255, 215, 0);//gold
    glVertex2d(200, -200);

    glVertex2d(-200, -200);
    glColor3ub(255, 215, 0);//gold
    glVertex2d(-200, 100);

    glEnd();

    //-------------------SUN-------------------------
    glColor3ub(255, 215, 0);
    sun(90, 250);
    //----------------------------Tree---------------------------
        //for left part of the tree
    glColor3ub(139, 69, 19);//
    glRecti(150, 200, 157, 100);
    glColor3ub(100, 190, 0);
    sun(140, 190);
    sun(170, 190);
    sun(160, 210);
    sun(140, 175);
    sun(170, 170);
    sun(145, 165);

    glColor3ub(139, 69, 19);//
    glRecti(120, 200, 127, 100);
    glColor3ub(0, 150, 0);
    sun(110, 190);
    sun(140, 190);
    sun(130, 210);
    sun(120, 175);
    sun(140, 170);


    glColor3ub(139, 69, 19);//
    glRecti(180, 200, 187, 100);
    glColor3ub(0, 100, 0);
    sun(170, 190);
    sun(200, 190);
    sun(190, 210);
    sun(170, 175);
    sun(200, 170);



    glColor3ub(139, 69, 19);//
    glRecti(80, 200, 87, 100);
    glColor3ub(120, 190, 0);
    sun(70, 190);
    sun(100, 190);
    sun(90, 210);
    sun(80, 175);
    sun(100, 170);




    // ------------------------------------fence--------------------------
    int x = 0;
    for (int i = 0;i < 39;i++)
    {
        fence(x);
        x += 10;
    }

    glColor3ub(184, 134, 11);
    glRecti(-200, 120, 200, 115);
    glRecti(-200, 100, 200, 95);
    glRecti(-200, 85, 200, 80);


    //-------------------------------------TREE------------------------

    glColor3ub(139, 69, 19);//
    glRecti(-20, 200, -13, 140);
    glColor3ub(0, 100, 0);
    sun(-30, 190);
    sun(0, 190);
    sun(-10, 210);
    sun(-30, 175);
    sun(-0, 170);

    glBegin(GL_POLYGON); // Main Tree // first part
    glColor3ub(139, 69, 19);//
    glVertex2d(-170, 160);
    glVertex2d(-168, 120);
    glColor3ub(139, 69, 19);//
    glVertex2d(-178, 40);
    glVertex2d(-145, 40);
    glColor3ub(139, 69, 19);//
    glVertex2d(-153, 120);
    glVertex2d(-150, 160);
    glVertex2d(-170, 160);
    glEnd();
    glBegin(GL_POLYGON);  // Main Tree // second part
    glColor3ub(139, 69, 19);//
    glVertex2d(-153, 100);
    glVertex2d(-100, 200);
    glVertex2d(-95, 200);
    glVertex2d(-153, 80);
    glVertex2d(-153, 100);
    glEnd();
    glBegin(GL_POLYGON);  // Main Tree // third part
    glColor3ub(139, 69, 19);//
    glVertex2d(-170, 160);
    glVertex2d(-185, 210);
    glVertex2d(-190, 210);
    glVertex2d(-168, 90);
    glVertex2d(-170, 160);

    glEnd();
    glBegin(GL_POLYGON);  // Main Tree // fourth part
    glColor3ub(139, 69, 19);//
    glVertex2d(-160, 160);
    glVertex2d(-150, 210);
    glVertex2d(-140, 210);
    glVertex2d(-150, 160);
    glVertex2d(-160, 160);


    glEnd();
    glColor3ub(0, 128, 0);//leaf
    sun(-95, 200);
    sun(-80, 180);
    sun(-110, 180);
    sun(-120, 200);

    sun(-150, 200);
    sun(-130, 180);
    sun(-125, 220);
    sun(-140, 230);

    sun(-190, 210);
    sun(-180, 200);
    sun(-175, 225);
    sun(-195, 190);

    //-------------------Khor kuto------------------------------------
    glColor3f(0.7, 0.3, 0.0);
    cloud(-133, 10);
    cloud(-133, -12);
    cloud(-143, -4);
    cloud(-123, 2);
    cloud(-125, -4);


    //-----------------------------------------------TUBEWELL-----------------------------------------

    glBegin(GL_POLYGON);  // First part

    glColor3ub(0, 100, 0);//
    glVertex2d(115, 65);
    glVertex2d(95, 5);
    glVertex2d(145, 5);
    glVertex2d(165, 65);
    glVertex2d(115, 65);

    glEnd();
    glBegin(GL_POLYGON);  // second part

    glColor3ub(143, 188, 143);//
    glVertex2d(120, 58);
    glVertex2d(104, 13);
    glVertex2d(140, 12);
    glVertex2d(155, 58);
    glVertex2d(120, 58);

    glEnd();
    glColor3ub(0, 0, 0);// third part
    glRecti(95, 5, 145, -6);

    glBegin(GL_POLYGON);  // fourth  part
    glColor3ub(0, 0, 0);//
    glVertex2d(165, 65);
    glVertex2d(166, 55);
    glVertex2d(145, -6);
    glVertex2d(145, 5);
    glVertex2d(165, 65);
    glEnd();
    glBegin(GL_POLYGON);  // tubewell 1st part
    glColor3f(0.55, 0.55, 0.55);
    glVertex2d(120, 85);
    glVertex2d(120, 30);
    glVertex2d(125, 28);
    glVertex2d(130, 30);
    glVertex2d(130, 85);
    glVertex2d(125, 87);
    glVertex2d(120, 85);
    glEnd();
    glBegin(GL_POLYGON);  // tubewell second part
    glColor3ub(255, 215, 0);//golden rod
    glVertex2d(120, 85);
    glVertex2d(125, 80);
    glVertex2d(130, 85);
    glVertex2d(125, 87);
    glVertex2d(120, 85);

    glEnd();
    glColor3ub(205, 133, 63);//golden rod // tubewell third part
    glRecti(123, 100, 126, 85);

    glBegin(GL_POLYGON);  // tubewell fourth part
    glColor3f(0.65, 0.65, 0.65);//saddle brown
    glVertex2d(126, 100);
    glVertex2d(128, 102);
    glVertex2d(128, 110);
    glVertex2d(126, 113);
    glVertex2d(124, 111);
    glVertex2d(100, 80);
    glVertex2d(90, 70);
    glVertex2d(90, 65);
    glVertex2d(100, 73);
    glVertex2d(126, 100);
    glEnd();
    glBegin(GL_POLYGON);  // tubewell 5th part
    glColor3f(1.0, 0.5, 0.0);//golden rod
    glVertex2d(130, 70);
    glVertex2d(140, 70);
    glVertex2d(140, 50);
    glVertex2d(136, 50);
    glVertex2d(136, 60);
    glVertex2d(130, 60);
    glVertex2d(130, 70);

    glEnd();
    glColor3ub(210, 105, 30);//golden rod //tubewell last part
    glRecti(123, 29, 127, 20);
    glColor3ub(139, 69, 19);//saddle brown
    glRecti(118, 22, 132, 14);


    //___________________________________________House 3_________________________________________________


    glBegin(GL_POLYGON);  // First part

    glColor3f(0.4f, 0.4f, 0.35f);
    glVertex2d(-70, 150);
    glVertex2d(-20, 159);
    glVertex2d(-32, 98);
    glVertex2d(-85, 99);

    glEnd();


    glBegin(GL_POLYGON);  // First part

    glColor3f(0.1f, 0.1f, 0.1f);
    glVertex2d(-20, 159);
    glVertex2d(-12, 140);
    glVertex2d(-32, 98);

    glEnd();















    // End of the house 3 ____________________________________________________________________________________________

    // --------------------------------------- HOUSE one----------------------------
    glBegin(GL_POLYGON);  // first Part
    glColor3ub(128, 0, 0);//gray
    glVertex2d(-58, 115);
    glVertex2d(-75, 145);
    glVertex2d(-115, 150);//point
    glVertex2d(-90, 100);
    glVertex2d(-62, 100);
    glVertex2d(-58, 115);

    glEnd();
    glBegin(GL_POLYGON);  // second Part
    glColor3ub(120, 0, 0);//maroon   
    glVertex2d(-115, 150);
    glVertex2d(-130, 100);
    glVertex2d(-120, 100);//point
    glVertex2d(-108, 137);//point
    glVertex2d(-115, 150);
    glEnd();
    glBegin(GL_POLYGON);  // third Part
    glColor3ub(46, 139, 87);//
    glVertex2d(-108, 137);
    glVertex2d(-120, 100);
    glVertex2d(-120, 45);
    glVertex2d(-90, 40);//point
    glVertex2d(-90, 100);
    glVertex2d(-108, 137);
    glEnd();


    glBegin(GL_POLYGON);  // fourth Part
    glColor3ub(143, 188, 143);//
    glVertex2d(-90, 40);
    glVertex2d(-60, 45);
    glVertex2d(-60, 100);
    glVertex2d(-90, 100);

    glEnd();
    glColor3ub(120, 0, 0);//maroon // Door One
    glRecti(-75, 80, -65, 40);
    glColor3ub(120, 0, 0);//maroon // Door One
    glRecti(-110, 90, -100, 70);
    glBegin(GL_POLYGON);  // third Part (lower part 1)
    glColor3ub(0, 0, 0);//
    glVertex2d(-90, 40);
    glVertex2d(-123, 45);
    glVertex2d(-123, 35);
    glVertex2d(-90, 30);
    glVertex2d(-90, 40);

    glEnd();
    glBegin(GL_POLYGON);  // third Part (lower part 2)
    glColor3ub(0, 0, 0);//
    glVertex2d(-90, 40);
    glVertex2d(-55, 45);
    glVertex2d(-55, 35);
    glVertex2d(-90, 30);
    glVertex2d(-90, 40);


    glEnd();




    //-------------------------------------------  HOUSE  two  -------------------------------------------------
    glBegin(GL_POLYGON);  // First part

    glColor3ub(25, 25, 112);//midnight blue
    glVertex2d(-50, 140);
    glVertex2d(0, 149);
    glVertex2d(-12, 88);
    glVertex2d(-65, 89);
    glVertex2d(-50, 140);
    glEnd();





    glBegin(GL_POLYGON);  // Second Part
    glColor3ub(70, 130, 180);//midnight blue
    glVertex2d(-60, 90);
    glVertex2d(-60, 30);
    glVertex2d(-10, 25);
    glVertex2d(-10, 95);
    glEnd();


    //---------------------------------------Door------------------------------------------
    glColor3ub(25, 25, 112);//midnight blue
    glRecti(-45, 70, -30, 27);

    //--------------------------------------------------------------------------
    glBegin(GL_POLYGON);   // Third part 
    glColor3ub(95, 158, 160);//midnight blue
    glVertex2d(-10, 25);
    glVertex2d(18, 35);
    glVertex2d(18, 100);
    glVertex2d(0, 148);
    glVertex2d(-10, 100);
    glVertex2d(-10, 25);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.09, 0.09, 0.43);//midnight blue
    glVertex2d(-1, 150);
    glVertex2d(20, 100);
    glVertex2d(17, 90);
    glVertex2d(-4, 140);
    glVertex2d(-1, 150);

    glEnd();


    glBegin(GL_POLYGON);  // door
    glColor3f(0.09, 0.09, 0.43);//midnight blue
    glVertex2d(0, 70);
    glVertex2d(10, 73);
    glVertex2d(10, 32);
    glVertex2d(0, 29);
    glVertex2d(0, 70);


    glEnd();
    glBegin(GL_POLYGON);  // (lower part 1)
    glColor3f(0.0, 0.0, 0.0);//
    glVertex2d(-10, 25);
    glVertex2d(-10, 15);
    glVertex2d(20, 27);
    glVertex2d(20, 37);
    glVertex2d(-10, 25);


    glEnd();
    glBegin(GL_POLYGON);  // (lower part 2)
    glColor3f(0.0, 0.0, 0.0);//
    glVertex2d(-10, 25);
    glVertex2d(-62, 30);
    glVertex2d(-62, 20);
    glVertex2d(-10, 15);
    glVertex2d(-10, 25);




    glEnd();


    //------------------------------------------RIVER--------------------------------------------------  
    glBegin(GL_POLYGON);
    glColor3ub(30, 144, 255);
    glVertex2d(-200, -50);
    glVertex2d(200, -30);
    glColor3f(0.0, 0.0, 0.5);
    glVertex2d(200, -200);
    glVertex2d(-200, -200);
    glVertex2d(-200, -50);
    glEnd();
    glBegin(GL_POLYGON); // border
    glColor3f(0.5, 0.5, 0.0);
    glVertex2d(-200, -45);
    glVertex2d(200, -25);
    glVertex2d(200, -30);
    glVertex2d(-200, -50);
    glVertex2d(-200, -45);
    glEnd();

    //-------------------------------------------CLOUD-------------------------------------------------
    glPushMatrix();
    glColor3f(0.86, 0.86, 0.86);
    glTranslatef(tx, 0, 0);
    cloud(0, 250);
    cloud(15, 245);
    cloud(10, 240);
    cloud(-2, 243);



    cloud(-80, 250);
    cloud(-95, 245);
    cloud(-90, 240);
    cloud(-90, 243);
    cloud(-75, 243);

    glPopMatrix();
    tx += .01;
    if (tx > 200)
        tx = -200;

    glutPostRedisplay();








    // Dead boat at the side of shore
    glColor3f(0.55, 0.27, 0.0745);//ash color

    glBegin(GL_POLYGON);
    glVertex2d(200, -10);
    glVertex2d(185, -20);
    glVertex2d(170, -40);
    glVertex2d(170, -20);
    glVertex2d(200, -10);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2d(170, -20);
    glVertex2d(170, -40);
    glVertex2d(140, -45);
    glVertex2d(110, -40);
    glVertex2d(105, -20);
    glVertex2d(170, -20);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2d(105, -20);
    glVertex2d(110, -40);
    glVertex2d(95, -25);
    glVertex2d(80, -10);
    glVertex2d(105, -20);
    glEnd();


    // Another dead boat going 
    glColor3f(0.2f, 0.2f, 0.2f);//Black

    glBegin(GL_POLYGON);
    glVertex2d(180, -30);
    glVertex2d(165, -40);
    glVertex2d(150, -60);
    glVertex2d(150, -40);
    glVertex2d(180, -30);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2d(150, -40);
    glVertex2d(150, -60);
    glVertex2d(120, -65);
    glVertex2d(90, -60);
    glVertex2d(85, -40);
    glVertex2d(150, -40);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2d(85, -40);
    glVertex2d(90, -60);
    glVertex2d(75, -45);
    glVertex2d(60, -30);
    glVertex2d(85, -40);
    glEnd();




    // End of the dead boat




    // Another boat going to back 

    glPushMatrix();
    glColor3f(0.0f, 0.0f, 0.0f);//Black
    glTranslatef(cx, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2d(180, -50);
    glVertex2d(165, -80);
    glVertex2d(150, -100);
    glVertex2d(150, -80);
    glVertex2d(180, -50);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2d(150, -80);
    glVertex2d(150, -100);
    glVertex2d(120, -105);
    glVertex2d(90, -100);
    glVertex2d(85, -80);
    glVertex2d(150, -80);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2d(85, -80);
    glVertex2d(90, -100);
    glVertex2d(75, -85);
    glVertex2d(60, -50);
    glVertex2d(85, -80);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3f(0.55, 0.27, 0.0745);//wood color
    glVertex2d(85, -80);
    glVertex2d(87, -60);
    glVertex2d(93, -42);
    glVertex2d(97, -35);
    glVertex2d(105, -30);
    glVertex2d(120, -28);
    glVertex2d(120, -80);
    glVertex2d(85, -80);

    glEnd();


    glBegin(GL_POLYGON);
    glColor3f(0.55, 0.27, 0.0745);//wood color
    glVertex2d(150, -80);
    glVertex2d(148, -60);
    glVertex2d(142, -42);
    glVertex2d(138, -35);
    glVertex2d(130, -30);
    glVertex2d(115, -28);
    glVertex2d(115, -80);
    glVertex2d(150, -80);


    glEnd();


    // Boat Internal Line of the hut
    // for creating enternal line of the BOAT 


    glBegin(GL_LINE_STRIP);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2d(148, -60);
    glVertex2d(87, -60);
    glEnd();
    glBegin(GL_LINE_STRIP);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2d(142, -42);
    glVertex2d(93, -42);
    glEnd();
    glBegin(GL_LINE_STRIP);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2d(115, -30);
    glVertex2d(115, -100);
    glEnd();
    glBegin(GL_LINE_STRIP);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2d(130, -30);
    glVertex2d(130, -80);
    glEnd();
    glBegin(GL_LINE_STRIP);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2d(100, -32);
    glVertex2d(100, -80);
    glEnd();

    glPopMatrix();
    cx -= .03;
    if (cx < -250)
        cx = 250;


    glutPostRedisplay();


    //____________________________________Flowers_______________________________________


    // 1st Flower
    glColor3f(0.0, .3, 0.0);
    glRecti(-88, 5, -89.5, -9);
    glColor3f(1.0f, 0.5f, 0.0f);
    flower(-88, 5.5);

    glColor3f(0.0, 0.3, 0.0);
    glRecti(-92, 5, -93.5, -9);
    glColor3f(1.0f, 0.0f, 0.0f);
    flower(-92, 5.5);

    glColor3f(0.0, 0.3, 0.0);
    glRecti(-96, 5, -97.5, -9);
    glColor3f(1.0f, 1.0f, 0.0f);
    flower(-96, 5.5);

    glColor3f(0.0, 0.3, 0.0);
    glBegin(GL_POLYGON);
    glVertex2d(-84, -4);
    glVertex2d(-78, -7);
    glVertex2d(-84, -11);
    glVertex2d(-90, -9);

    glEnd();


    glColor3f(0.0, 0.3, 0.0);
    glBegin(GL_POLYGON);

    glVertex2d(-100, -4);
    glVertex2d(-94, -9);
    glVertex2d(-100, -11);
    glVertex2d(-106, -7);

    glEnd();



    //Second flower 
    glColor3f(0.0, .3, 0.0);
    glRecti(-38, 5, -39.5, -9);
    glColor3f(1.0f, 0.5f, 0.0f);
    flower(-38, 5.5);

    glColor3f(0.0, 0.3, 0.0);
    glRecti(-42, 5, -43.5, -9);
    glColor3f(1.0f, 0.0f, 0.0f);
    flower(-42, 5.5);

    glColor3f(0.0, 0.3, 0.0);
    glRecti(-46, 5, -47.5, -9);
    glColor3f(1.0f, 1.0f, 0.0f);
    flower(-46, 5.5);

    glColor3f(0.0, 0.3, 0.0);
    glBegin(GL_POLYGON);
    glVertex2d(-34, -4);
    glVertex2d(-28, -7);
    glVertex2d(-34, -11);
    glVertex2d(-40, -9);

    glEnd();


    glColor3f(0.0, 0.3, 0.0);
    glBegin(GL_POLYGON);

    glVertex2d(-50, -4);
    glVertex2d(-44, -9);
    glVertex2d(-50, -11);
    glVertex2d(-56, -7);

    glEnd();



    //3rd flower

    glColor3f(0.0, .3, 0.0);
    glRecti(-168, 30, -169.5, 16);
    glColor3f(1.0f, 0.5f, 0.0f);
    flower(-168, 30.5);

    glColor3f(0.0, 0.3, 0.0);
    glRecti(-172, 30, -173.5, 16);
    glColor3f(1.0f, 0.0f, 0.0f);
    flower(-172, 30.5);

    glColor3f(0.0, 0.3, 0.0);
    glRecti(-176, 30, -177.5, 16);
    glColor3f(1.0f, 1.0f, 0.0f);
    flower(-176, 30.5);

    glColor3f(0.0, 0.3, 0.0);
    glBegin(GL_POLYGON);
    glVertex2d(-164, 21);
    glVertex2d(-158, 18);
    glVertex2d(-164, 14);
    glVertex2d(-170, 16);

    glEnd();


    glColor3f(0.0, 0.3, 0.0);
    glBegin(GL_POLYGON);

    glVertex2d(-180, 21);
    glVertex2d(-174, 16);
    glVertex2d(-180, 14);
    glVertex2d(-186, 18);

    glEnd();

    //4th flower
    glColor3f(0.0, .3, 0.0);
    glRecti(168, 30, 169.5, 16);
    glColor3f(1.0f, 0.5f, 0.0f);
    flower(168, 30.5);

    glColor3f(0.0, 0.3, 0.0);
    glRecti(172, 30, 173.5, 16);
    glColor3f(1.0f, 0.0f, 0.0f);
    flower(172, 30.5);

    glColor3f(0.0, 0.3, 0.0);
    glRecti(176, 30, 177.5, 16);
    glColor3f(1.0f, 1.0f, 0.0f);
    flower(176, 30.5);

    glColor3f(0.0, 0.3, 0.0);
    glBegin(GL_POLYGON);
    glVertex2d(164, 21);
    glVertex2d(158, 18);
    glVertex2d(164, 14);
    glVertex2d(170, 16);

    glEnd();


    glColor3f(0.0, 0.3, 0.0);
    glBegin(GL_POLYGON);

    glVertex2d(180, 21);
    glVertex2d(174, 16);
    glVertex2d(180, 14);
    glVertex2d(186, 18);

    glEnd();




    // 5th Flower
    glColor3f(0.0, .3, 0.0);
    glRecti(88, 5, 89.5, -9);
    glColor3f(1.0f, 0.5f, 0.0f);
    flower(88, 5.5);

    glColor3f(0.0, 0.3, 0.0);
    glRecti(92, 5, 93.5, -9);
    glColor3f(1.0f, 0.0f, 0.0f);
    flower(92, 5.5);

    glColor3f(0.0, 0.3, 0.0);
    glRecti(96, 5, 97.5, -9);
    glColor3f(1.0f, 1.0f, 0.0f);
    flower(96, 5.5);

    glColor3f(0.0, 0.3, 0.0);
    glBegin(GL_POLYGON);
    glVertex2d(84, -4);
    glVertex2d(78, -7);
    glVertex2d(84, -11);
    glVertex2d(90, -9);

    glEnd();


    glColor3f(0.0, 0.3, 0.0);
    glBegin(GL_POLYGON);

    glVertex2d(100, -4);
    glVertex2d(94, -9);
    glVertex2d(100, -11);
    glVertex2d(106, -7);

    glEnd();



    //6th flower 
    glColor3f(0.0, .3, 0.0);
    glRecti(38, 5, 39.5, -9);
    glColor3f(1.0f, 0.5f, 0.0f);
    flower(38, 5.5);

    glColor3f(0.0, 0.3, 0.0);
    glRecti(42, 5, 43.5, -9);
    glColor3f(1.0f, 0.0f, 0.0f);
    flower(42, 5.5);

    glColor3f(0.0, 0.3, 0.0);
    glRecti(46, 5, 47.5, -9);
    glColor3f(1.0f, 1.0f, 0.0f);
    flower(46, 5.5);

    glColor3f(0.0, 0.3, 0.0);
    glBegin(GL_POLYGON);
    glVertex2d(34, -4);
    glVertex2d(28, -7);
    glVertex2d(34, -11);
    glVertex2d(40, -9);

    glEnd();


    glColor3f(0.0, 0.3, 0.0);
    glBegin(GL_POLYGON);

    glVertex2d(50, -4);
    glVertex2d(44, -9);
    glVertex2d(50, -11);
    glVertex2d(56, -7);

    glEnd();

    //7th flower

    glColor3f(0.0, .3, 0.0);
    glRecti(-73, 5, -74.5, -9);
    glColor3f(1.0f, 0.5f, 0.0f);
    flower(-73, 5.5);

    glColor3f(0.0, 0.3, 0.0);
    glRecti(-77, 5, -78.5, -9);
    glColor3f(1.0f, 0.0f, 0.0f);
    flower(-77, 5.5);

    glColor3f(0.0, 0.3, 0.0);
    glRecti(-81, 5, -82.5, -9);
    glColor3f(1.0f, 1.0f, 0.0f);
    flower(-81, 5.5);

    glColor3f(0.0, 0.3, 0.0);
    glBegin(GL_POLYGON);
    glVertex2d(-69, -4);
    glVertex2d(-63, -7);
    glVertex2d(-69, -11);
    glVertex2d(-75, -9);

    glEnd();


    glColor3f(0.0, 0.3, 0.0);
    glBegin(GL_POLYGON);

    glVertex2d(-85, -4);
    glVertex2d(-79, -9);
    glVertex2d(-85, -11);
    glVertex2d(-91, -7);

    glEnd();











    //_____________________________________________End of flowers____________________________________________


    //-------------------------------------------Kite-----------------------------------------------------
    glColor3f(0.7, 0.0, 0.0);
    glBegin(GL_POLYGON);

    glVertex2d(10, 250);
    glVertex2d(21, 262);
    glVertex2d(30, 257);
    glVertex2d(25, 247);

    glEnd();

    glLineWidth(1.2f);
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINE_STRIP);
    glVertex2d(11, 250);
    glVertex2d(29, 257);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glVertex2d(21, 262);
    glVertex2d(25, 247);
    glEnd();



    glColor3f(1.0, .4, 0.0);
    glBegin(GL_POLYGON);

    glVertex2d(10, 250);
    glVertex2d(8, 245);
    glVertex2d(6, 253);


    glEnd();






    glLineWidth(0.3f);
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINE_STRIP);
    glVertex2d(23, 254.5);
    glVertex2d(55, 200);
    glEnd();











    //


    //-------------------------------------------creation of Flag----------------------------------------------
    glColor3f(0.00, 0.50, 0.00);
    glBegin(GL_POLYGON);
    glVertex2d(24.5, 148);
    glVertex2d(24.5, 198);
    glVertex2d(80, 198);
    glVertex2d(80, 148);



    glEnd();

    glColor3f(0.6, 0.4, 0.2);
    glBegin(GL_POLYGON);
    glVertex2d(21.5, 198);
    glVertex2d(24.5, 198);
    glVertex2d(24.5, 40);
    glVertex2d(21.5, 40);
    glEnd();

    fcircle(15, 52.5, 173);

    // Khorer Gada
    glColor3f(0.8f * 0.3f, 0.3f * 0.3f, 0.0f);
    glRecti(48, 115, 52, 129);

    glColor3f(0.8, 0.3, 0.0);
    glBegin(GL_POLYGON);
    glVertex2d(26, 30);
    glVertex2d(26, 70);
    glVertex2d(34, 100);
    glVertex2d(42, 110);
    glVertex2d(50, 120);
    glVertex2d(50, 30);

    glEnd();
    glColor3f(0.8, 0.3, 0.0);
    glBegin(GL_POLYGON);
    glVertex2d(74, 30);
    glVertex2d(74, 70);
    glVertex2d(66, 100);
    glVertex2d(58, 110);
    glVertex2d(50, 120);
    glVertex2d(50, 30);

    glEnd();

    glColor3f(0.8f * 0.3f, 0.3f * 0.3f, 0.0f);
    glBegin(GL_POLYGON);
    glVertex2d(74, 30);
    glVertex2d(74, 18);
    glVertex2d(26, 18);
    glVertex2d(26, 30);


    glEnd();






    //End of khorer gada


    //-------------------------------------------BOAT-------------------------------------------------
    glPushMatrix();
    glColor3f(0.0f, 0.0f, 0.0f);//Black
    glTranslatef(bx, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2d(-180, -70);
    glVertex2d(-165, -100);
    glVertex2d(-150, -120);
    glVertex2d(-150, -100);
    glVertex2d(-180, -70);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2d(-150, -100);
    glVertex2d(-150, -120);
    glVertex2d(-120, -125);
    glVertex2d(-90, -120);
    glVertex2d(-85, -100);
    glVertex2d(-150, -100);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2d(-85, -100);
    glVertex2d(-90, -120);
    glVertex2d(-75, -105);
    glVertex2d(-60, -70);
    glVertex2d(-85, -100);
    glEnd();
    glColor3ub(211, 211, 211);
    sun(-165, 260);
    sun(-185, 245);
    sun(-180, 240);
    sun(-152, 243);

    //--------------------------BOAT FLAG----------------------------
    glBegin(GL_POLYGON);
    glColor3f(0.68, 0.85, 0.9);
    glVertex2d(-57, -40);
    glVertex2d(-50, -10);
    glVertex2d(-49, 10);
    glVertex2d(-50, 30);
    glVertex2d(-55, 45);
    glVertex2d(-63, 57);
    glVertex2d(-73, 68); // end
    glVertex2d(-105, 45);
    glVertex2d(-50, -10);


    glEnd();
    glBegin(GL_POLYGON);
    // glColor3ub(173, 216, 230);
    glColor3f(0.68, 0.85, 0.9);

    glVertex2d(-68, -70);
    glVertex2d(-57, -40);
    glVertex2d(-85, 10);
    glVertex2d(-68, -70);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(173, 216, 230);
    glVertex2d(-85, -100);
    glVertex2d(-68, -70);
    glVertex2d(-80, -10);
    glVertex2d(-85, -100);

    glEnd();


    glColor3f(0.54, 0.27, 0.075);
    glRecti(-88, 80, -86, -100);  // Boat stand
    glBegin(GL_POLYGON);
    glColor3f(0.55, 0.27, 0.0745);//wood color
    glVertex2d(-85, -100);
    glVertex2d(-87, -80);
    glVertex2d(-93, -62);
    glVertex2d(-97, -55);
    glVertex2d(-105, -50);
    glVertex2d(-120, -48);
    glVertex2d(-120, -100);
    glVertex2d(-85, -100);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.55, 0.27, 0.0745);//wood color
    glVertex2d(-150, -100);
    glVertex2d(-148, -80);
    glVertex2d(-142, -62);
    glVertex2d(-138, -55);
    glVertex2d(-130, -50);
    glVertex2d(-115, -48);
    glVertex2d(-115, -100);
    glVertex2d(-150, -100);


    glEnd();


    // for creating enternal line of the BOAT 
    glBegin(GL_LINE_STRIP);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2d(-142, -62);
    glVertex2d(-73, 68);
    glVertex2d(-73, 63);

    glVertex2d(-142, -62);
    glVertex2d(-105, 45);
    glEnd();
    glBegin(GL_LINE_STRIP);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2d(-148, -80);
    glVertex2d(-87, -80);
    glEnd();
    glBegin(GL_LINE_STRIP);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2d(-142, -62);
    glVertex2d(-93, -62);
    glEnd();
    glBegin(GL_LINE_STRIP);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2d(-115, -48);
    glVertex2d(-115, -100);
    glEnd();
    glBegin(GL_LINE_STRIP);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2d(-130, -50);
    glVertex2d(-130, -100);
    glEnd();
    glBegin(GL_LINE_STRIP);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2d(-100, -52);
    glVertex2d(-100, -100);
    glEnd();
    glPopMatrix();
    bx += .03;
    if (bx > 270)
        bx = -180;


    glutPostRedisplay();







    //Moving birds

    glPushMatrix();
    glColor3f(0.86, 0.86, 0.86);
    glTranslatef(tb, 0, 0);
    glColor3f(0, 0, 0);

    glBegin(GL_POLYGON);
    glVertex2d(-200, 250);
    glVertex2d(-195, 255);
    glVertex2d(-197, 250);
    glVertex2d(-195, 245);
    glEnd();


    glBegin(GL_POLYGON);
    glVertex2d(-205, 255);
    glVertex2d(-200, 260);
    glVertex2d(-202, 255);
    glVertex2d(-200, 250);
    glEnd();


    glBegin(GL_POLYGON);
    glVertex2d(-205, 245);
    glVertex2d(-200, 250);
    glVertex2d(-202, 245);
    glVertex2d(-200, 240);
    glEnd();



    glBegin(GL_POLYGON);
    glVertex2d(-210, 260);
    glVertex2d(-205, 265);
    glVertex2d(-207, 260);
    glVertex2d(-205, 255);
    glEnd();


    glBegin(GL_POLYGON);
    glVertex2d(-210, 240);
    glVertex2d(-205, 245);
    glVertex2d(-207, 240);
    glVertex2d(-205, 235);
    glEnd();


    glBegin(GL_POLYGON);
    glVertex2d(-215, 265);
    glVertex2d(-210, 270);
    glVertex2d(-212, 265);
    glVertex2d(-210, 260);
    glEnd();


    glBegin(GL_POLYGON);
    glVertex2d(-215, 235);
    glVertex2d(-210, 240);
    glVertex2d(-212, 235);
    glVertex2d(-210, 230);
    glEnd();
    //
    glBegin(GL_POLYGON);
    glVertex2d(-220, 270);
    glVertex2d(-215, 275);
    glVertex2d(-217, 270);
    glVertex2d(-215, 265);
    glEnd();


    glBegin(GL_POLYGON);
    glVertex2d(-220, 230);
    glVertex2d(-215, 235);
    glVertex2d(-217, 230);
    glVertex2d(-215, 225);
    glEnd();

    //


    glBegin(GL_POLYGON);
    glVertex2d(-225, 225);
    glVertex2d(-220, 230);
    glVertex2d(-222, 225);
    glVertex2d(-220, 220);
    glEnd();









    glPopMatrix();
    tb += .07;
    if (tb > 280)
        tb = -180;




    glutPostRedisplay();
    glColor3f(1.0, 1.0, 1.0);
    glRecti(-210, 310, -200, -210);
    glRecti(200, 310, 210, -210);
    glFlush();
}



void init()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-210, 210, -220, 310);


}





int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1200, 800);
    glutInitWindowPosition(10, 10);
    glutCreateWindow("201-15-13625; 201-15-13715; 201-15-13733 ");
    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
