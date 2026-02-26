#include"Game.h"
#include<vector>
#include<iostream>
#include<windows.h>
#include <fstream>
using namespace std;


// 蛇移动函数
void MoveSnake(std::vector<Point>& snake, Point& food, Direction dir, bool& gameover,const int& WIDTH,const int& HEIGHT)
{
    cout << "当前蛇头坐标: (" << snake[0].x << ", " << snake[0].y << ")" << endl;
	// 获取蛇头位置
	Point head = snake.front();
	// 根据方向更新蛇头位置
	switch (dir) 
    {
		case UP: head.y--; break;
		case DOWN: head.y++; break;
		case LEFT: head.x--; break;
		case RIGHT: head.x++; break;
	}
	// 检查撞墙
    if (head.x < 0 || head.x > WIDTH - 1 || head.y < 0 || head.y > HEIGHT - 1) {
        gameover = true;
        return;
    }
    //撞自己身体的判定
    for (int i = 1; i < snake.size(); i++) {
        if (head.x == snake[i].x && head.y == snake[i].y) {
            gameover = true;
            return;
        }
    }
    bool eatFood = (head.x == food.x && head.y == food.y);
	// 更新蛇的位置
	snake.insert(snake.begin(), head);
    if (!eatFood) {
        snake.pop_back(); // 没吃到：删尾巴
    }
    else {
        // 吃到果实：重新生成
        food.x = rand() % WIDTH;
        food.y = rand() % HEIGHT;
    }
    cout << "蛇的长度: " << snake.size() << endl;
	cout << "得分数量：" << snake.size() - 1 << endl; // 得分

}

//界面绘制函数
    void DrawGame(const std::vector<Point>&snake, Point & food, int WIDTH, int HEIGHT)
    {
        //获取控制台句柄
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        // 设置光标位置为 (0,0) 即左上角
        COORD coord = { 0, 0 };
        SetConsoleCursorPosition(hConsole, coord);

        // 绘制上边框
        for (int i = 0; i < WIDTH + 2; i++)
        {
            cout << "#";
        }
        cout << endl;
        for (int y = 0; y < HEIGHT; y++) {
            cout << "#"; // 左边框（移到行首，避免重叠）
            for (int x = 0; x < WIDTH; x++) {
                bool isSnake = false;

                // 1. 先画蛇头（snake的第一个元素，用@）
                if (snake.size() > 0 && snake[0].x == x && snake[0].y == y) {
                    cout << "@";
                    isSnake = true;
                }
                // 2. 再画蛇身（snake从第二个元素开始，用●）
                else {
                    for (int i = 1; i < snake.size(); i++) {
                        if (snake[i].x == x && snake[i].y == y) {
                            cout << "●";
                            isSnake = true;
                            break;
                        }
                    }
                }

                // 3. 不是蛇的位置：画果实（*）或空白（ ）
                if (!isSnake) {
                    if (x == food.x && y == food.y) {
                        cout << "*"; // 果实用*表示
                    }
                    else {
                        cout << " "; // 空白区域
                    }
                }
            }
            cout << "#" << endl; // 右边框（移到行尾，避免错位）
        }
        // 绘制下边框
        for (int i = 0; i < WIDTH + 2; i++) cout << "#";
        cout << endl;
    };

    // 读取最高分
    int ReadHighScore(const string& filename) {
        ifstream file(filename); // 读文件
        int highScore = 0;
        if (file.is_open()) {
            file >> highScore; // 读取文件里的数字
            file.close();
        }
        return highScore;
    }

    // 写入文件
    void WriteHighScore(int score, const string& filename) {
        ofstream file(filename); 
        if (file.is_open()) {
            file << score; // 写入分数
            file.close();
        }
    }