#include<graphics.h>
#include<conio.h>
#include <iostream>
#define key_down(D) ((GetAsyncKeyState('D'))?0:1)
using namespace std;
IMAGE background, stillb[4], stilla[4], runb[8], runa[8], jumpa, jumpb;
struct role
{
    int x = 10;
    int y = 600;
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

    loadimage(&runa[0], _T("pictures\\run\\a0.png"));
    loadimage(&runa[1], _T("pictures\\run\\a1.png"));
    loadimage(&runa[2], _T("pictures\\run\\a2.png"));
    loadimage(&runa[3], _T("pictures\\run\\a3.png"));
    loadimage(&runa[4], _T("pictures\\run\\a4.png"));
    loadimage(&runa[5], _T("pictures\\run\\a5.png"));
    loadimage(&runa[6], _T("pictures\\run\\a6.png"));
    loadimage(&runa[7], _T("pictures\\run\\a7.png"));

    loadimage(&runb[0], _T("pictures\\run\\b0.png"));
    loadimage(&runb[1], _T("pictures\\run\\b1.png"));
    loadimage(&runb[2], _T("pictures\\run\\b2.png"));
    loadimage(&runb[3], _T("pictures\\run\\b3.png"));
    loadimage(&runb[4], _T("pictures\\run\\b4.png"));
    loadimage(&runb[5], _T("pictures\\run\\b5.png"));
    loadimage(&runb[6], _T("pictures\\run\\b6.png"));
    loadimage(&runb[7], _T("pictures\\run\\b7.png"));

    loadimage(&jumpa, _T("pictures\\jump\\a.png"));
    loadimage(&jumpb, _T("pictures\\jump\\b.png"));
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
        PrintBackground();
        putimage(role.x, role.y, &stillb[i], SRCAND);
        putimage(role.x, role.y, &stilla[i], SRCPAINT);
        EndBatchDraw();
        Sleep(100);
    }
}
int IsJump()
{
    if (GetAsyncKeyState('K'))
    {
        return 1;
    }

    return 0;
}
int IsJumping()
{
    if (role.y < 600)
    {
        return 1;
    }
    return 0;
}
int IsGround()
{
    if (role.y = 600)
    {
        return 1;
    }
    return 0;
}
int IsRun()
{
    if (key_down(D))
    {
        return 1;
    }
    if (GetAsyncKeyState('A') )
    {
        return 1;
    }
    return 0;
}
void PrintRun()
{
    for (int i = 0; i < 8; i++)
    {
        if(i==0||IsRun())
        {
            BeginBatchDraw();
            PrintBackground();
            if (GetAsyncKeyState('D'))
            {
                role.x += 15;
            }
            if (GetAsyncKeyState('A'))
            {
                role.x -= 15;
            }
            putimage(role.x, role.y, &runb[i], SRCAND);
            putimage(role.x, role.y, &runa[i], SRCPAINT);
            EndBatchDraw();
            Sleep(100);
        }
        if (IsJump())
        {
            break;
        }
    }
}

void PrintJump()
{
    for (int i = 0; i < 4; i++)
    {
        BeginBatchDraw();
        PrintBackground();
        role.y -= 30;
        putimage(role.x, role.y, 43, 49, &jumpb, 43 * (i % 2), 0, SRCAND);
        putimage(role.x, role.y, 43, 49, &jumpa, 43 * (i % 2), 0, SRCPAINT);
        EndBatchDraw();
        Sleep(100);       
    }
    for (int i =0; i < 3; i++)
    {
        BeginBatchDraw();
        PrintBackground();
        role.y += 30;
        putimage(role.x, role.y, 43, 49, &jumpb, 43 * 2, 0, SRCAND);
        putimage(role.x, role.y, 43, 49, &jumpa, 43 * 2, 0, SRCPAINT);
        EndBatchDraw();
        Sleep(100);
    }
    BeginBatchDraw();
    PrintBackground();
    role.y += 30;
    putimage(role.x, role.y, 43, 49, &jumpb, 43 * 3, 0, SRCAND);
    putimage(role.x, role.y, 43, 49, &jumpa, 43 * 3, 0, SRCPAINT);
    EndBatchDraw();
    Sleep(100);
}
void PrintMove()
{
    if (IsRun())
    {
        PrintRun();
    }
    else if (IsJump()) {
        PrintJump();
    }
    else
    {
        if(IsGround())
        {
            PrintStill();
        }
    }
    return;
}
int main() 
{
    Initial();
    initgraph(1280,720);
    while(1)
    {
        PrintBackground();
        
        PrintMove();
    }
    system("pause");
	return 0;
}