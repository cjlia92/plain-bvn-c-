#include<graphics.h>
#include<conio.h>
#include <iostream>
using namespace std;
IMAGE background, stillb[4], stilla[4];
struct role
{
    int x = 10;
    int y = 300;
}role;
void Initial()
{
    loadimage(&background, _T("pictures\\background\\0.png"));
    loadimage(&stilla[0], _T("pictures\\still\\a0.png"));
    loadimage(&stilla[1], _T("pictures\\still\\a1.png"));
    loadimage(&stilla[2], _T("pictures\\still\\a2.png"));
    loadimage(&stilla[3], _T("pictures\\still\\a3.png"));

    loadimage(&stillb[0], _T("pictures\\still\\b0.png"));
    loadimage(&stillb[1], _T("pictures\\still\\b1.png"));
    loadimage(&stillb[2], _T("pictures\\still\\b2.png"));
    loadimage(&stillb[3], _T("pictures\\still\\b3.png"));
}
void PrintBackground()
{
    putimage(0, 0, &background);
}
void PrintStill() 
{
    for (int i = 0; i < 4; i++)
    {
        BeginBatchDraw();
        putimage(role.x, role.y, &stillb[i], SRCAND);
        putimage(role.x, role.y, &stilla[i], SRCPAINT);
        EndBatchDraw();
        Sleep(100);
    }
}
void Move()
{
    if (GetAsyncKeyState('d') || GetAsyncKeyState('D'))
    {
        role.x+=10; 
    }
    if (GetAsyncKeyState('a') || GetAsyncKeyState('A'))
    {
        role.x -= 10;
    }
}
int main() 
{
    Initial();
    initgraph(1280,720);
    while(1)
    {
        PrintBackground();
        PrintStill();
        Move();
    }
    system("pause");
	return 0;
}