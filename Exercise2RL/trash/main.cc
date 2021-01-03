#include <cstdlib>
#include <iostream>
#include <GL/glut.h>
#include <unistd.h>

using namespace std;

float posY = 0;

void setup() 
{
    //specifies color to clear the window
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

    //specify coordinate system in drawing shapes
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);

}

void displayLine() 
{

    //clear the window to the color specified in setup function

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //specify color in drawing line
    glColor3f(1.0f, 0.0f, 0.0f);

    //start drawing a line
    glBegin(GL_LINES);
    glVertex2f(-0.9f, (posY - 0.1));
    glVertex2f(-0.9f, (posY + 0.1));
    glEnd();

    //wait until buffers completely displayed
    glutSwapBuffers();
    //done drawing, refresh screen
    glutPostRedisplay(); 
}

void update() 
{
    posY += 0.1;
    cout << "posY = " << posY << endl;
    glutDisplayFunc(displayLine); //draw a line
    sleep(1);
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv); //initialize window
    glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
    glutInitWindowSize(500,400); //specify window size
    glutCreateWindow("Game of Pong"); //create a window
    setup();
    int running = 0;
    while (running < 5)
    {
        cout << "####SMTH######" << endl;           
        update(); 
        cout << "SMTH" << endl;    
        ++running;
    } 
    glutMainLoop();
    //display the window
    system("PAUSE");
    return EXIT_SUCCESS;
}
