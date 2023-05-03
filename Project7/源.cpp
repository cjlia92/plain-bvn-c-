#include<graphics.h>
#include<conio.h>
#include <iostream>
using namespace std;
struct role
{
    int x = 10;
    int y = 600;
    int height = -43;
    int width = 38;
};
struct Attackwind
{
    int x;
    int y;
    int width;
    int height;
};
class Role {
public:
    role player;
    Role(int a, int b, int c, int d)
    {
        player.x = a;
        player.y = b;
        player.height = c;
        player.width = d;
    }
    int Isjumping = 0;//Jugde how many times the role has jumped.
    int Isattacking = 0;//Jugde how many times the role has attacked.
    void Initial();
    void PrintBackground();
    void PrintStill();
    int IsJump();
    int IsJumping();
    int IsGround();
    int IsRun();
    void PrintRun();
    void PrintJump();
    int IsAttack();
    void PrintAttack();
    void PrintMove();
};
IMAGE background, stillb[4], stilla[4], runb[8], runa[8], jumpa, jumpb, attacka[3], attackb[3];
void Role::Initial()
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

    loadimage(&attacka[0], _T("pictures\\attack\\a0.png"));
    loadimage(&attackb[0], _T("pictures\\attack\\b0.png"));
    loadimage(&attacka[1], _T("pictures\\attack\\a1.png"));
    loadimage(&attackb[1], _T("pictures\\attack\\b1.png"));
    loadimage(&attacka[2], _T("pictures\\attack\\a2.png"));
    loadimage(&attackb[2], _T("pictures\\attack\\b2.png"));
}
void Role::PrintBackground()
{
    putimage(0, 0, &background);
}
void Role::PrintStill()
{
    for (int i = 0; i < 4; i++)
    {
        if (IsRun())
        {
            return;
        }
        if (IsJump())
        {
            return;
        }
        BeginBatchDraw();
        PrintBackground();
        putimage(player.x, player.y, &stillb[i], SRCAND);
        putimage(player.x, player.y, &stilla[i], SRCPAINT);
        EndBatchDraw();
        Sleep(100);
    }
}
int Role::IsJump()
{

    if (GetAsyncKeyState('K') && Isjumping < 1)
    {
        Isjumping++;
        IsGround();
        return 1;
    }
    return 0;
}
int Role::IsJumping()
{
    if (player.y < 600)
    {
        return 1;
    }
    return 0;
}
int Role::IsGround()
{
    if (player.y == 600)
    {
        Isjumping = 0;
        return 1;
    }
    return 0;
}
int Role::IsRun()
{
    if (GetAsyncKeyState('D'))
    {
        return 1;
    }
    if (GetAsyncKeyState('A'))
    {
        return 1;
    }
    return 0;
}
void Role::PrintRun()
{
    for (int i = 0; i < 8; i++)
    {

        if (IsRun())
        {
            BeginBatchDraw();
            PrintBackground();
            if (GetAsyncKeyState('D'))
            {
                if (player.x < 1232)
                {
                    player.x += 15;
                }
            }
            if (GetAsyncKeyState('A'))
            {
                if (player.x > 10)
                {
                    player.x -= 15;
                }
            }
            putimage(player.x, player.y, &runb[i], SRCAND);
            putimage(player.x, player.y, &runa[i], SRCPAINT);
            EndBatchDraw();
            Sleep(50);
        }
        if (IsJump())
        {
            PrintJump();
            break;
        }
    }
}
void Role::PrintJump()
{
    for (int i = 0; i < 8; i++)
    {
        player.y -= 18;
        if (GetAsyncKeyState('D'))
        {
            player.x += 15;
        }
        if (GetAsyncKeyState('A'))
        {
            player.x -= 15;
        }
        BeginBatchDraw();
        PrintBackground();
        putimage(player.x, player.y, 43, 49, &jumpb, 43 * (i % 2), 0, SRCAND);
        putimage(player.x, player.y, 43, 49, &jumpa, 43 * (i % 2), 0, SRCPAINT);
        EndBatchDraw();
        Sleep(25);
    }
    if (IsJump())
    {
        PrintJump();
    }
    for (int i = 0; i < 7; i++)
    {
        if (IsJump())
        {
            PrintJump();
        }
        player.y += 18;
        if (GetAsyncKeyState('D'))
        {
            player.x += 15;
        }
        if (GetAsyncKeyState('A'))
        {
            player.x -= 15;
        }
        BeginBatchDraw();
        PrintBackground();
        putimage(player.x, player.y, 43, 49, &jumpb, 43 * 2, 0, SRCAND);
        putimage(player.x, player.y, 43, 49, &jumpa, 43 * 2, 0, SRCPAINT);
        EndBatchDraw();
        Sleep(25);
    }
    player.y += 18;
    BeginBatchDraw();
    PrintBackground();
    putimage(player.x, player.y, 43, 49, &jumpb, 43 * 3, 0, SRCAND);
    putimage(player.x, player.y, 43, 49, &jumpa, 43 * 3, 0, SRCPAINT);
    EndBatchDraw();
    Sleep(25);
}
int Role::IsAttack()
{
    if (GetAsyncKeyState('J'))
    {
        return 1;
    }
    return 0;
}
void Role::PrintAttack()
{
    //the first attack.
    for (int i = 0; i < 4; i++) {
        player.x += 3;
        BeginBatchDraw();
        PrintBackground();
        if (i == 0 || i == 3)
        {
            putimage(player.x, player.y, 34, 48, &attackb[0], 155 * (i % 2), 0, SRCAND);
            putimage(player.x, player.y, 34, 48, &attacka[0], 155 * (i % 2), 0, SRCPAINT);
        }
        if (i == 1 || i == 2)
        {
            putimage(player.x, player.y, 50, 48, &attackb[0], 40 + 57 * ((i + 1) % 2), 0, SRCAND);
            putimage(player.x, player.y, 50, 48, &attacka[0], 40 + 57 * ((i + 1) % 2), 0, SRCPAINT);
        }
        EndBatchDraw();
        Sleep(150);
    }
    //the second attack.
    if (IsAttack())
    {

        for (int i = 0; i < 5; i++)
        {
            player.x += 3;
            BeginBatchDraw();
            PrintBackground();
            if (i == 0 || i == 1)
            {
                putimage(player.x, player.y, 48, 47, &attackb[1], 48 * (i % 2), 0, SRCAND);
                putimage(player.x, player.y, 48, 47, &attacka[1], 48 * (i % 2), 0, SRCPAINT);
            }
            if (i == 2)
            {
                putimage(player.x, player.y, 60, 47, &attackb[1], 106, 0, SRCAND);
                putimage(player.x, player.y, 60, 47, &attacka[1], 106, 0, SRCPAINT);
            }
            if (i == 3)
            {
                putimage(player.x, player.y, 50, 47, &attackb[1], 175, 0, SRCAND);
                putimage(player.x, player.y, 50, 47, &attacka[1], 175, 0, SRCPAINT);
            }
            if (i == 4)
            {
                putimage(player.x, player.y, 33, 47, &attackb[1], 233, 0, SRCAND);
                putimage(player.x, player.y, 33, 47, &attacka[1], 233, 0, SRCPAINT);
            }
            EndBatchDraw();
            Sleep(110);
        }
    }
    else
    {
        return;
    }
    //the third attack.
    if (IsAttack())
    {
        for (int i = 0; i < 7; i++)
        {
            if (i >= 2 && i <= 4)
            {
                player.x += 20;
            }
            BeginBatchDraw();
            PrintBackground();
            if (i == 0 || i == 1 || i == 2)
            {
                putimage(player.x, player.y, 46, 44, &attackb[2], 46 * (i % 3), 0, SRCAND);
                putimage(player.x, player.y, 46, 44, &attacka[2], 46 * (i % 3), 0, SRCPAINT);
            }
            if (i == 3)
            {
                putimage(player.x, player.y, 62, 44, &attackb[2], 138, 0, SRCAND);
                putimage(player.x, player.y, 62, 44, &attacka[2], 138, 0, SRCPAINT);
            }
            if (i == 4)
            {
                putimage(player.x, player.y, 55, 44, &attackb[2], 209, 0, SRCAND);
                putimage(player.x, player.y, 55, 44, &attacka[2], 209, 0, SRCPAINT);
            }
            if (i == 5)
            {
                putimage(player.x, player.y, 48, 44, &attackb[2], 283, 0, SRCAND);
                putimage(player.x, player.y, 48, 44, &attacka[2], 283, 0, SRCPAINT);
            }
            if (i == 6)
            {
                putimage(player.x, player.y, 38, 44, &attackb[2], 331, 0, SRCAND);
                putimage(player.x, player.y, 38, 44, &attacka[2], 331, 0, SRCPAINT);
            }
            EndBatchDraw();
            Sleep(100);
        }
    }
    else
    {
        return;
    }
}
void Role::PrintMove()
{
    IsGround();
    if (IsRun())
    {
        PrintRun();
    }
    else if (IsJump())
    {
        PrintJump();

    }
    else if (IsAttack())
    {
        PrintAttack();
    }
    else
    {
        if (IsGround())
        {
            PrintStill();
        }
    }
    return;
}

int main()
{
    Role A(10, 600, -43, 38);
    A.Initial();
    initgraph(1280, 720);
    while (1)
    {
        A.PrintBackground();
        A.PrintMove();
    }
    system("pause");
    return 0;
}