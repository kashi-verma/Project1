#include<conio.h>
#include<windows.h>
#include<cstdlib>
#include<ctime>
#include<iostream>
const int MAP_WIDTH = 20;
const int MAP_HEIGHT = 20;
const char SNAKE_SYMBOL = 'O';
const int STOP = 0;
const int LEFT = 1;
const int RIGHT = 2;
const int UP = 3;
const int DOWN = 4;
int headX,headY;
int foodX,foodY;
int score;
int direction;
int tailX[100],tailY[100];
int tailLength;
bool gameover;
void setup();
void draw();
void input();
void logic();
void generateFood();
int main(){
setup();
while(!gameover){
draw();
input();
logic();
Sleep(50);
}
system("cls");
std:: cout<<"Game Over!\n";
return 0;
}
void setup(){
gameover = false;
direction = STOP;
headX = MAP_WIDTH/2;
headY = MAP_HEIGHT/2;
score = 0;
tailLength = 0;
generateFood();
}
void draw(){
system("cls");
for(int i = 0;i<MAP_WIDTH + 2;i++){
std::cout<<"#";
}
std:: cout<<"\n";
for(int i = 0;i< MAP_HEIGHT;i++){
for(int j = 0;j<MAP_WIDTH;j++){
if(j == 0){
std::cout<<"#";
}
if(i == headY && j == headX){
std:: cout<<SNAKE_SYMBOL;
}
else if(i == foodY && j == foodX){
std::cout<<"F";
}
else{
bool printTail = false;
for(int k = 0;k< tailLength;k++){
if(tailX[k] == j && tailY[k] == i){
std::cout<<SNAKE_SYMBOL;
printTail = true;
}
}
if(!printTail){
std::cout<<" ";
}
}
if(j == MAP_WIDTH -1){
std::cout<<"#";
}
}
std::cout<<"\n";
}
for(int i = 0;i<MAP_WIDTH + 2;i++ ){
std::cout<<"#";
}
std::cout<<"\n";
std::cout<<"SCORE: "<<score<<"\n";
}
void input(){
if(_kbhit()){
switch(_getch()){
case 'a':
direction = LEFT;
break;
case 'd':
direction = RIGHT;
break;
case 'w':
direction = UP;
break;
case 's':
direction = DOWN;
break;
case 'x':
gameover = true;
break;
}
}
} 
void logic(){
int prevX = tailX[0];
int prevY = tailY[0];
int currX,currY;
tailX[0] = headX;
tailY[0] = headY;
for(int i = 1;i<tailLength;i++){
currX = tailX[i];
currY = tailY[i];
tailX[i] = prevX;
tailY[i] = prevY;
prevX = currX;
prevY = currY;
}
switch(direction){
case LEFT:
headX--;
break;
case RIGHT:
headX++;
break;
case UP:
headY--;
break;
case DOWN:
headY++;
break;
default:
break;
}
if(headX < 0 || headX >= MAP_WIDTH || headY < 0 || headY >= MAP_HEIGHT){
gameover = true;
}
for(int i = 0;i<tailLength;i++){
if(headX == tailX[i] && headY == tailY[i]){
gameover == true;
}
}
if(headX == foodX && headY == foodY){
score++;
tailLength++;
generateFood();
}
}
void generateFood(){
srand(time(NULL));
foodX = rand()%MAP_WIDTH;
foodY = rand()%MAP_HEIGHT;
for(int i = 0;i<tailLength;i++){
if(foodX == foodX && foodY == headY || foodX == tailX[i] && foodY ==
tailY[i]){
generateFood();
}
}
}
