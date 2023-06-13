#include <iostream>
#include <fstream>
#include <vector>
#include <time.h>
#include <windows.h>
#include <algorithm>
#include <conio.h>
#include <string>
using namespace std;

vector<int> numInput() {
    vector<int> num;
    int temp;

    cout << "Введите четырёхзначное число: ";

    for (int i = 0; i < 4; i++)
    {
        cin >> temp;
        num.push_back(temp);
    }

    return num;
}

vector<int> numGen() {
    srand(time(NULL));

    vector<int> num;

    for (int i = 0; i < 4; i++)
    {
        num.push_back(rand() % 10);
    }

    return num;
}

void game() {
    vector<int> nums {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> bot_num = numGen();
    vector<int> user_num;
    int bulls = 0; //на своих местах
    int cows = 0; //не на своих местах.
    int game_progress = 0;
    int temp = 0;

    while (true) {

        user_num = numInput();

        for (int j = 0; j < 4; j++)
        {
            if (user_num[j] == bot_num[temp])
            {
                bulls++;
            }
            temp++;
        }

        if (bulls == 4)
        {
            cout << "Вы отгадали число за " << game_progress + 1 << " ходов";
            break;
        }

        for (int h = 0; h < 4; h++)
        {
            for (int g = 0; g < 4; g++)
            {
                if (user_num[h] == bot_num[g])
                {
                    cows++;
                }
            }
        }

        for (int i = 0; i < 4; i++) {
            cout << user_num[i];
        }

        cout  << ": " << bulls << " быков, " << cows << " коров" << endl;

        bulls = 0;
        cows = 0;
        temp = 0;
        game_progress++;
    }
}

void main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    setlocale(LC_ALL, "Russian");

    game();
}