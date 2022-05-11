// морской бой черновик.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <ctime>
#include <iomanip>
#include <windows.h>

using namespace std;

const char SHIP = 10;

void showFiledMy(char** field1)
{
    system("cls");
    cout << endl;
    int border1 = _msize(field1) / sizeof(field1[0]);
    int border2 = _msize(field1[0]) / sizeof(field1[0][0]);
    cout << "\t\t MOPСКОЙ БОЙ" << endl << endl;
    cout << "\t А Б В Г Д Е Ж З И К"<<endl;
    for (int i = 0; i < border1; i++)
    {
        cout << setw(8) << i + 1 << char(124);
        for (int j = 0; j < border2; j++)
        {            
            cout << field1[i][j];
            cout << char(124);
        }
        cout << endl;
    }
}
void showFiledEnemy(char** field2)
{   
    int border1 = _msize(field2) / sizeof(field2[0]);
    int border2 = _msize(field2[0]) / sizeof(field2[0][0]);
    cout << "\t А Б В Г Д Е Ж З И К" << endl;
    for (int i = 0; i < border1; i++)
    {
        cout << setw(8) << i + 1 << char(124);
        for (int j = 0; j < border2; j++)
        {
            cout << field2[i][j];
            cout << char(124);
        }
        cout << endl;
    }
}
void sideMyShip(char** field1, int y, int x, int side, int pal)
{            
    if (x < 1 || x > 10 || y < 1 || y > 10);    
    switch (side)
    {
    case 1:   //вверх       
        for (int i = y; i > x - pal; i--)
        {
           field1[i - 1][x - 1] = '0';           
        }       
        break;        
    case 2:  //вниз
        for (int i = y - 1; i < x + pal - 1; i++)
        {
           field1[i][x - 1] = '0';          
        }
        break;
    case 3:  //вправо
        for (int i = x - 1; i < y + pal - 1; i++)
        {
           field1[y - 1][i] = '0';           
        }
        break;
    case 4:  //влево
        for (int i = x - 1; i > y - pal - 1; i--)
        {
           field1[y - 1][i] = '0';          
        }
        break;
    }    
}
bool testMyShip(char** field1, int y, int x, int side, int pal)
{
    bool flag = true;
    for (int i = 0; i < 5; i++)
    {
        if (x < 1 || x > 10 || y < 1 || y > 10)
        {
            flag = false;
            break;
        }
        if (field1[x][y] == '0' || field1[x - 1][y] == '0' || field1[x + 1][y] == '0'
            || field1[x][y - 1] == '0' || field1[x][y + 1] == '0'|| field1[x - 1][y - 1] == '0'
            || field1[x + 1][y + 1] == '0'|| field1[x-1][y + 1] == '0'|| field1[x + 1][y - 1] == '0')
        {
            flag = false;
            break;
        }
    }
    return true;
}
void setMyShip(char** field1, int y, int x, int side, int pal = 4)
{       
    for (int i = 0; i < 5 - pal; i++)
    {
        cin >> y >> x >> side >> pal;
    }
    sideMyShip(field1, y, x, side, pal);
    testMyShip(field1, y, x, side, pal);
}
void MyShip(char** field1, int y, int x, int side, int pal)
{
    while (true)
    {
        cout << "Введите координаты цели " << endl;
        cin >> x;
        cin >> y;
        if (field1[y][x] >= '0')
        {
            cout << "Попал" << endl;
        }
        else
        {
            cout << "Промах " << endl;
        }                
    }
}
int main()

{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(time(NULL));
    char** field1 = new char* [10];
    char** field2 = new char* [10];
    for (int i = 0; i < 10; i++)
    {
        field1[i] = new char[10];
        for (int j = 0; j < 10; j++)
        {
            field1[i][j] = char(126);
        }
    }
    for (int i = 0; i < 10; i++)
    {
        field2[i] = new char[10];
        for (int j = 0; j < 10; j++)
        {
            field2[i][j] = char(126);
        }
    }
    cout << endl;
    showFiledMy(field1);
    showFiledEnemy(field2);
    char y = 0;
    int x=0, side=0, pal=0;        
    testMyShip(field1, y, x, side, pal);
    setMyShip(field1, y, x, side, pal);
    cout << endl;        
    showFiledMy(field1);    
    showFiledEnemy(field2);
    MyShip(field1, y, x, side, pal);
    showFiledEnemy(field2);
}
