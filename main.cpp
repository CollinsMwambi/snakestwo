#include <GL/gl.h>
#include <GL/glut.h>
#include "game.h"

#define COLUMNS 40
#define ROWS 40

void display_callback();
void reshape_callback(int, int );
void init(){
    glClearColor(0.0, 0.0, 0.0, 1.0);
    initGrid(COLUMNS, ROWS);
}

int main(int argc, char **argv) {
    //initialise glut and display mode and window size
    glutInit(&argc,argv);
    //double buffer window
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(500, 500);
    glutCreateWindow("KENYAN SNAKE");
    glutDisplayFunc(display_callback);
    glutReshapeFunc(reshape_callback);
    init();
    glutMainLoop();
 return 0;
}
void display_callback();
void reshape_callback(int, int );
void init(){
    glClearColor(0.0, 0.0, 0.0, 1.0);
    initGrid(COLUMNS, ROWS);
}

int main(int argc, char **argv) {
    //initialise glut and display mode and window size
    glutInit(&argc,argv);
    //double buffer window
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(500, 500);
    glutCreateWindow("KENYAN SNAKE");
    glutDisplayFunc(display_callback);
    glutReshapeFunc(reshape_callback);
    init();
    glutMainLoop();
 return 0;
}

void display_callback()
{
    glClear(GL_COLOR_BUFFER_BIT);
    drawGrid();
    glutSwapBuffers();
}
//used to set viewport
void reshape_callback(int w, int h){
    glViewport(0,0,(GLsizei)w,(GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, COLUMNS, 0.0, ROWS, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
}
