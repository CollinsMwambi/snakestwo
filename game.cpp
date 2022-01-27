#include <GL/gl.h>
#include <GL/glut.h>
#include <ctime>
#include "game.h"


int gridX, gridY;
//variables to keep track of snake position
int posX = 20, posY = 20;
//variable to store current direction the snake is moving
short sDirection = RIGHT;
bool food = true;
int foodX, foodY;
extern bool gameOver;
//function to initialize grid
void initGrid (int x, int y){
    gridX = x;
    gridY = y;
}
void unit(int, int);
//function to draw grid

void drawGrid(){
    
    for (int x =0; x<gridX;x++){
        for (int y = 0; y < gridY; ++y) {
            unit(x, y);
        }
    }

}
void unit(int x , int y){

    //for the borders of the snake
    if (x==0 || y==0 || x == gridX-1 || y == gridY-1){
        glLineWidth(3.0);
        glColor3f(1.0, 1.0, 1.0);
    }
    else{
        glLineWidth(1.0);
        glColor3f(1.0, 1.0, 1.0);
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
//function for the food
void drawFood(){

    if (food)
        random(foodX, foodY);
    food = false;
    glRectf(foodX, foodY, foodX+1, foodY+1);
    glColor3f(0.0, 1.0, 0.0); //color of food = green
}
void random(int &x, int &y){
    int _maxX = gridX-2;
    int _maxY = gridY - 2;
    int _min = 1;
    srand(time(NULL));
    x = _min + rand() % (_maxX - _min);
    y = _min + rand() & (_maxY - _min);
}


void drawSnake(){
    if (sDirection == UP)
        posY++;
    else if(sDirection== DOWN)
        posY--;
    else if (sDirection== RIGHT)
        posX++;
    else if (sDirection== LEFT)
        posX--;
    //color of snake = blue
    glColor3f(0.0, 0.0, 1.0);
    glRectd(posX, posY, posX+1, posY+1);
    if (posX = 0 || posX == gridX-1 || posY == 0 || posY == gridY-1)
        gameOver = true;
    if(posX == foodX && posY =foodY)
        food = true;



}
