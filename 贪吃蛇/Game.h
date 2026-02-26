#pragma once
#ifndef GAME_H
#define GAME_H
#include <vector>
#include <iostream>
#include<string>

enum PageState { MENU, PLAYING, RECORD,OPTION, EXIT };
enum Direction { UP, DOWN, LEFT, RIGHT };
const int WIDTH = 60;
const int HEIGHT = 20;
class Point 
{
    public:
        int x;
        int y;
    Point(int x = 0, int y = 0) : x(x), y(y) {}
};
void DrawGame(const std::vector<Point>& snake, Point& food, int WIDTH, int HEIGHT);
void MoveSnake(std::vector<Point>& snake, Point& food, Direction dir, bool& gameover,const int& WIDTH,const int& HEIGHT);
int ReadHighScore(const std::string& filename = "highscore.txt");
void WriteHighScore(int score, const std::string& filename = "highscore.txt");
#endif