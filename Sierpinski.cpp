
/*
*  Program: Sierpinski Triangles
*  Description: Simple program that generates Sierpisnki triangles recursively
*               using GLUT (OpenGL Utility Toolkit). Each triangle has a random color. 
*               Number of the nested triangles can be modified by adjusting the DEPTH defined below.
*  Name: Mihai-Alexandru Ilie
*  Date: 16.03.2023
*/


#include <GL/glut.h>

#define WIDTH 693    //WIDTH of the window
#define HEIGHT 600   //HEIGHT of the window

#define SPEED 5      //Triangle generation speed
#define DEPTH 7      //The number of the nested triangles


//Struct for storing the points needed for drawing triangles
struct point
{
    float x;
    float y;
};

void sierpinski(point, point, point, int);
void drawTriangle(point, point, point);
point middle(point, point);
float randomFloat();
void display();

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutInitWindowPosition(100, 50);
    glutCreateWindow("Sierpinski Triangle");
    glutDisplayFunc(display);

    point a, b, c;
    //vertices for the first triangle
    a.x = -1.0f;
    a.y = -1.0f;
    b.x = 1.0f;
    b.y = -1.0f;
    c.x = 0.0f;
    c.y = 1.0f;
    drawTriangle(a, b, c);   //draw first triangle
    sierpinski(a, b, c, DEPTH);
    glFlush();
    glutMainLoop();

    return 0;
}

//Draws a triangle at the received points
void drawTriangle(point a, point b, point c)
{
    glBegin(GL_TRIANGLES);
        glColor3f(randomFloat(), randomFloat(), randomFloat()); // random color for each triangle
        glVertex2f(a.x, a.y);
        glVertex2f(b.x, b.y);
        glVertex2f(c.x, c.y);
    glEnd();
}

//Recursive function for drawing Sierpinski triangle.
void sierpinski(point a, point b, point c, int depth)
{
    if (depth == 0)
        return;

    glFlush();
    drawTriangle(middle(a, b), middle(b, c), middle(a, c));  //Draws the triangle for current iteration
    Sleep(SPEED);
    sierpinski(a, middle(a, b), middle(a, c), depth - 1);   //Calling the function for the next triangles
    Sleep(SPEED);
    sierpinski(b, middle(a, b), middle(b, c), depth - 1);
    Sleep(SPEED);
    sierpinski(c, middle(a, c), middle(b, c), depth - 1);
}

//Returns the middle point of the segment determined by the 2 given points
point middle(point a, point b)
{
    point mid;
    mid.x = (a.x + b.x) / 2.0f;
    mid.y = (a.y + b.y) / 2.0f;
    return mid;
}

//Random float between 0 and 1
float randomFloat()
{
    return (float)(rand()) / (float)(RAND_MAX);
}

//Function needed by the GL
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
}
