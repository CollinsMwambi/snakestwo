#include <GL/gl.h>
#include <GL/glut.h>
#include "game.h"

int gridX, gridY;
//variables to keep track of snake position
int posX[60] = { 20,20,20,20, 20 }, posY[60] = { 20,19,18,16,16 }; //arrays for position of the snake
int snake_length = 5;
//variable to store current direction the snake is moving
short sDirection = RIGHT;
bool food = true;
int foodX, foodY;
bool food1 = true;
int food1x, food1y;
extern bool gameOver;
extern int score;
//function to initialize grid
void initGrid(int x, int y) {
    gridX = x;
    gridY = y;
}
void unit(int, int);
//function to draw grid

void drawGrid() {

    for (int x = 0; x < gridX; x++) {
        for (int y = 0; y < gridY; ++y) {
            unit(x, y);
        }
    }

}
void unit(int x, int y) {

    //for the borders of the snake
    if (x == 0 || y == 0 || x == gridX - 1 || y == gridY - 1) {
        glLineWidth(3.0);
        glColor3f(1.0, 1.0, 1.0);
    }
    else {
        glLineWidth(1.0);
        glColor3f(1.0, 1.0, 1.0);
    }

    glLineWidth(1.0);
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(x, y);
    glVertex2f(x + 1, y);
    glVertex2f(x + 1, y + 1);
    glVertex2f(x, y + 1);
    glEnd();
}
//function for the food
void drawFood() {

    if (food) 
        random(foodX, foodY);
        food = false;//if the food available at that point then move to the next random
    glRectf(foodX, foodY, foodX + 1, foodY + 1);
    glColor3f(0.0, 0.5, 0.5); 
    if (food1) 
        random1(food1x, food1y);
        food1 = false;
    glRecti(food1x, food1y, food1x + 1, food1y + 1);
    glColor3f(0.6, 0.8, 1.0);
}

    glLineWidth(1.0);
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_LINE_LOOP);
        glVertex2f(x, y);
        glVertex2f(x+1, y);
        glVertex2f(x+1, y+1);
        glVertex2f(x, y+1);
    glEnd();
}

