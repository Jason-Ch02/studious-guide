#define _CRT_SECURE_NO_WARNINGS
#include<fstream>
#include"Game.h"
#include <iostream>
#include <conio.h>   // 用于 _getch()
#include <windows.h> // 用于 system("cls")
#include<vector>
#include <ctime>
#include <string>  
#include <chrono>
#include <thread>

//#include"Snake.h"
using namespace std;
int gameSpeed = 100;
vector<Point>snake;

int main() {
    srand((unsigned int)time(NULL));
    int frameCount = 0;
    PageState state = MENU;   // 开始时处于菜单
    int highScore = ReadHighScore("highscore.txt");  //文件读取

    while (true) {
        if (state == MENU) {
            // 清屏，显示菜单选项
            system("cls");
            cout << "=== 贪吃蛇游戏 ===" << endl;
            cout << "1. 开始游戏" << endl;
            cout << "2. 查看记录" << endl;
            cout << "3. 选择难度" << endl;
            cout << "4. 退出游戏" << endl;
            cout << "请选择 (1-4): " << endl;
            // 获取一个按键（不需要按回车）
            char ch = _getch();

            switch (ch) {
            case '1':
                state = PLAYING;   // 切换到游戏页面
                break;
            case '2':
                state = RECORD;    // 切换到记录页面
                break;
			case '3':
				state = OPTION;    // 切换到选项页面
                break;
            case '4':
                state = EXIT;      // 准备退出
                break;
            default:
                // 按了其他键，报错
                cout << "输入有误" << endl;
                this_thread::sleep_for(chrono::milliseconds(1000));
                break;
            }
        }
        else if (state == RECORD) {
            // 显示最高记录
            system("cls");
            cout << "===== 游戏记录 =====" << endl;
            cout << "当前最高分: " << highScore << "分（蛇长度： "<<highScore+1<<")"<<endl;
            cout << "按任意键返回菜单...";
            char ch=_getch();// 等待按键
			(void)ch; // 避免未使用变量的警告
            state = MENU;            // 返回菜单
        }
        else if (state == PLAYING) {
            // 初始化
            snake.clear();
            snake.push_back(Point(WIDTH / 2, HEIGHT / 2)); // 初始位置
            Direction dir = RIGHT; // 默认向右
            bool GameOver = false;
            Point food;
            // 生成果实位置
            food.x = rand() % WIDTH;
            food.y = rand() % HEIGHT;

            // 隐藏控制台光标（避免闪烁）
            HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            CONSOLE_CURSOR_INFO cursorInfo;
            GetConsoleCursorInfo(hConsole, &cursorInfo);
            cursorInfo.bVisible = false;
            SetConsoleCursorInfo(hConsole, &cursorInfo);

            // 主循环
            while (!GameOver) {
                // 1. 绘制画面（用光标定位替代cls，避免清输入）
                COORD coord = { 0, 0 };
                SetConsoleCursorPosition(hConsole, coord);
                DrawGame(snake,food, WIDTH, HEIGHT);

                // 2. 非阻塞检测按键（核心：没按键也不卡）
                if (_kbhit()) {
                    char ch = _getch();
                        switch (ch) {
                        case 'w': case 'W': if (dir != DOWN) dir = UP; break;
                        case 's': case 'S': if (dir != UP) dir = DOWN; break;
                        case 'a': case 'A': if (dir != RIGHT) dir = LEFT; break;
                        case 'd': case 'D': if (dir != LEFT) dir = RIGHT; break;
                        case 'x': case 'X': GameOver = true; break; // 按X退出游戏
                        
                    }
                }

                // 3. 移动蛇
                MoveSnake(snake,food, dir, GameOver, WIDTH, HEIGHT);

                // 4. 控制游戏速度
               this_thread::sleep_for(chrono::milliseconds(gameSpeed));
            }
            while (!GameOver) {
            }
            // 1. 将光标移到游戏画面下方（HEIGHT+3行，避免覆盖游戏画面）
            COORD gameOverCoord = { 0, HEIGHT + 5 }; // HEIGHT是游戏区域高度，+3空出边框和换行
            SetConsoleCursorPosition(hConsole, gameOverCoord);

            // 2. 打印游戏结束提示
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY); // 红色高亮
            cout << "========================" << endl;
            cout << "        游戏结束        " << endl;
            cout << "      请按任意键继续    " << endl;
            cout << "========================" << endl;
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // 恢复默认白色

            int currentScore =static_cast<int>(snake.size()) - 1;
            // 更新最高分
            if (currentScore > highScore) {
                highScore = currentScore;
                WriteHighScore(highScore,"highscore.txt"); // 写入文件
            }
            // 3. 等待用户按任意键
            _getch();
            // 游戏结束后恢复光标，切回菜单
            cursorInfo.bVisible = true;
            SetConsoleCursorInfo(hConsole, &cursorInfo);
            state = MENU;
        }
       
        else if (state == OPTION)
        {
			// 显示选项界面
            system("cls");
            cout << "========================" << endl;
			cout << "        选择难度        " << endl;
			cout << "1. 简单 (100ms)" << endl;
			cout << "2. 中等 (70ms)" << endl;
			cout << "3. 困难 (40ms)" << endl;
            cout << "      请按任意键返回    " << endl;
            cout << "========================" << endl;
            char diff = _getch();
            switch (diff)
            {
            case '1':
                gameSpeed = 100;
                cout << "选择成功" << endl;
                this_thread::sleep_for(chrono::milliseconds(1000));
                break;
            case '2':
                gameSpeed = 60;
                cout << "选择成功" << endl;
                this_thread::sleep_for(chrono::milliseconds(1000));
                break;
            case '3':
                gameSpeed = 30;
                cout << "选择成功" << endl;
                this_thread::sleep_for(chrono::milliseconds(1000));
                break;
            default:
                break;
            }
           
            state = MENU;

        }
        else if (state == EXIT) {
            // 退出程序
            break;
        }
    }

    return 0;
}