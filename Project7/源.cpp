#include<graphics.h>
#include<conio.h>
#include <iostream>
#include<mmsystem.h>
#pragma comment(lib,"winmm.lib")
#define RIGHT 1
#define LEFT 0
using namespace std;

struct role
{
    int x;
    int y;
    int height;
    int width;
    int Isjumping;//Jugde how many times the role has jumped.
    int Isattacking;//Jugde how many times the role has attacked.
    bool face;
    int blood;
};
class Role {
public:
    role player1;
    role player2;
    Role(int a, int b, int c, int d, int e, int f, int g, int h)
    {
        player1.x = a;
        player1.y = b;
        player1.height = c;
        player1.width = d;
        player1.face = RIGHT;
        player2.x = e;
        player2.y = f;
        player2.height = g;
        player2.width = h;
        player2.face = LEFT;
        player1.blood = 324;
        player2.blood = 324;

    }
    void Initial();
    void PrintBackground();
    void PrintStill(role&, role&, IMAGE*, IMAGE*, IMAGE*, IMAGE*);
    int IsJumpA(role&);
    int IsJumpB(role&);
    int IsJumping(role&);
    int IsGround(role&);
    int IsRunA(role&);
    int IsRunB(role&);
    void PrintRun(role&, role&, IMAGE*, IMAGE*, IMAGE*, IMAGE*);
    void PrintJump(role&, role&, IMAGE*, IMAGE*, IMAGE*, IMAGE*);
    int IsAttack();
    void PrintAttack(role&, IMAGE(*)[7], IMAGE(*)[7], IMAGE(*)[7], IMAGE(*)[7]);
    void PrintFarAttack(role&, IMAGE*, IMAGE*, IMAGE*, IMAGE*);
    void PrintMove();
    void PrintFall(role&, role&, IMAGE*, IMAGE*, IMAGE*, IMAGE*);
    inline void  PutImage(role&, IMAGE*, IMAGE*, IMAGE*, IMAGE*);
    int IsStruck(role&);
    int IsFarAttack();
};
IMAGE background, stillb[4], stilla[4], runb[8], runa[8], jumpa[4], jumpb[4], attacka[3][7], attackb[3][7], strucka[3], struckb[3], blood[3], farattack[5], farattackmovea[6], farattackmoveb[6], farattackfire[5], downa[6], downb[6];
IMAGE Lstillb[4], Lstilla[4], Lrunb[8], Lruna[8], Ljumpa[4], Ljumpb[4], Lattacka[3][7], Lattackb[3][7], Lstrucka[3], Lstruckb[3];
void Role::Initial()
{
    //background.
    loadimage(&background, _T("pictures\\background\\0.png"));
    //Blood
    loadimage(&blood[0], _T("pictures\\blood\\b.png"));
    loadimage(&blood[1], _T("pictures\\blood\\a.png"));
    loadimage(&blood[2], _T("pictures\\blood\\blood.png"));
    //still
    loadimage(&stilla[0], _T("pictures\\still\\a0.png"));
    loadimage(&stilla[1], _T("pictures\\still\\a1.png"));
    loadimage(&stilla[2], _T("pictures\\still\\a2.png"));
    loadimage(&stilla[3], _T("pictures\\still\\a3.png"));
    loadimage(&stillb[0], _T("pictures\\still\\b0.png"));
    loadimage(&stillb[1], _T("pictures\\still\\b1.png"));
    loadimage(&stillb[2], _T("pictures\\still\\b2.png"));
    loadimage(&stillb[3], _T("pictures\\still\\b3.png"));
    //Lstill
    loadimage(&Lstilla[0], _T("pictures\\Lstill\\a0.png"));
    loadimage(&Lstilla[1], _T("pictures\\Lstill\\a1.png"));
    loadimage(&Lstilla[2], _T("pictures\\Lstill\\a2.png"));
    loadimage(&Lstilla[3], _T("pictures\\Lstill\\a3.png"));
    loadimage(&Lstillb[0], _T("pictures\\Lstill\\b0.png"));
    loadimage(&Lstillb[1], _T("pictures\\Lstill\\b1.png"));
    loadimage(&Lstillb[2], _T("pictures\\Lstill\\b2.png"));
    loadimage(&Lstillb[3], _T("pictures\\Lstill\\b3.png"));

    //run
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
    //Lrun
    loadimage(&Lruna[0], _T("pictures\\Lrun\\a0.png"));
    loadimage(&Lruna[1], _T("pictures\\Lrun\\a1.png"));
    loadimage(&Lruna[2], _T("pictures\\Lrun\\a2.png"));
    loadimage(&Lruna[3], _T("pictures\\Lrun\\a3.png"));
    loadimage(&Lruna[4], _T("pictures\\Lrun\\a4.png"));
    loadimage(&Lruna[5], _T("pictures\\Lrun\\a5.png"));
    loadimage(&Lruna[6], _T("pictures\\Lrun\\a6.png"));
    loadimage(&Lruna[7], _T("pictures\\Lrun\\a7.png"));
    loadimage(&Lrunb[0], _T("pictures\\Lrun\\b0.png"));
    loadimage(&Lrunb[1], _T("pictures\\Lrun\\b1.png"));
    loadimage(&Lrunb[2], _T("pictures\\Lrun\\b2.png"));
    loadimage(&Lrunb[3], _T("pictures\\Lrun\\b3.png"));
    loadimage(&Lrunb[4], _T("pictures\\Lrun\\b4.png"));
    loadimage(&Lrunb[5], _T("pictures\\Lrun\\b5.png"));
    loadimage(&Lrunb[6], _T("pictures\\Lrun\\b6.png"));
    loadimage(&Lrunb[7], _T("pictures\\Lrun\\b7.png"));
    //jump
    loadimage(&jumpa[0], _T("pictures\\jump\\a0.png"));
    loadimage(&jumpa[1], _T("pictures\\jump\\a1.png"));
    loadimage(&jumpa[2], _T("pictures\\jump\\a2.png"));
    loadimage(&jumpa[3], _T("pictures\\jump\\a3.png"));
    loadimage(&jumpb[0], _T("pictures\\jump\\b0.png"));
    loadimage(&jumpb[1], _T("pictures\\jump\\b1.png"));
    loadimage(&jumpb[2], _T("pictures\\jump\\b2.png"));
    loadimage(&jumpb[3], _T("pictures\\jump\\b3.png"));
    //Ljump
    loadimage(&Ljumpa[0], _T("pictures\\Ljump\\a0.png"));
    loadimage(&Ljumpa[1], _T("pictures\\Ljump\\a1.png"));
    loadimage(&Ljumpa[2], _T("pictures\\Ljump\\a2.png"));
    loadimage(&Ljumpa[3], _T("pictures\\Ljump\\a3.png"));
    loadimage(&Ljumpb[0], _T("pictures\\Ljump\\b0.png"));
    loadimage(&Ljumpb[1], _T("pictures\\Ljump\\b1.png"));
    loadimage(&Ljumpb[2], _T("pictures\\Ljump\\b2.png"));
    loadimage(&Ljumpb[3], _T("pictures\\Ljump\\b3.png"));

    //attack
    loadimage(&attacka[0][0], _T("pictures\\attack\\a00.png"));
    loadimage(&attacka[0][1], _T("pictures\\attack\\a01.png"));
    loadimage(&attacka[0][2], _T("pictures\\attack\\a02.png"));
    loadimage(&attacka[0][3], _T("pictures\\attack\\a03.png"));
    loadimage(&attacka[1][0], _T("pictures\\attack\\a10.png"));
    loadimage(&attacka[1][1], _T("pictures\\attack\\a11.png"));
    loadimage(&attacka[1][2], _T("pictures\\attack\\a12.png"));
    loadimage(&attacka[1][3], _T("pictures\\attack\\a13.png"));
    loadimage(&attacka[1][4], _T("pictures\\attack\\a14.png"));
    loadimage(&attacka[2][0], _T("pictures\\attack\\a20.png"));
    loadimage(&attacka[2][1], _T("pictures\\attack\\a21.png"));
    loadimage(&attacka[2][2], _T("pictures\\attack\\a22.png"));
    loadimage(&attacka[2][3], _T("pictures\\attack\\a23.png"));
    loadimage(&attacka[2][4], _T("pictures\\attack\\a24.png"));
    loadimage(&attacka[2][5], _T("pictures\\attack\\a25.png"));
    loadimage(&attacka[2][6], _T("pictures\\attack\\a26.png"));
    loadimage(&attackb[0][0], _T("pictures\\attack\\b00.png"));
    loadimage(&attackb[0][1], _T("pictures\\attack\\b01.png"));
    loadimage(&attackb[0][2], _T("pictures\\attack\\b02.png"));
    loadimage(&attackb[0][3], _T("pictures\\attack\\b03.png"));
    loadimage(&attackb[1][0], _T("pictures\\attack\\b10.png"));
    loadimage(&attackb[1][1], _T("pictures\\attack\\b11.png"));
    loadimage(&attackb[1][2], _T("pictures\\attack\\b12.png"));
    loadimage(&attackb[1][3], _T("pictures\\attack\\b13.png"));
    loadimage(&attackb[1][4], _T("pictures\\attack\\b14.png"));
    loadimage(&attackb[2][0], _T("pictures\\attack\\b20.png"));
    loadimage(&attackb[2][1], _T("pictures\\attack\\b21.png"));
    loadimage(&attackb[2][2], _T("pictures\\attack\\b22.png"));
    loadimage(&attackb[2][3], _T("pictures\\attack\\b23.png"));
    loadimage(&attackb[2][4], _T("pictures\\attack\\b24.png"));
    loadimage(&attackb[2][5], _T("pictures\\attack\\b25.png"));
    loadimage(&attackb[2][6], _T("pictures\\attack\\b26.png"));
    //Lattack
    loadimage(&Lattacka[0][0], _T("pictures\\Lattack\\a00.png"));
    loadimage(&Lattacka[0][1], _T("pictures\\Lattack\\a01.png"));
    loadimage(&Lattacka[0][2], _T("pictures\\Lattack\\a02.png"));
    loadimage(&Lattacka[0][3], _T("pictures\\Lattack\\a03.png"));
    loadimage(&Lattacka[1][0], _T("pictures\\Lattack\\a10.png"));
    loadimage(&Lattacka[1][1], _T("pictures\\Lattack\\a11.png"));
    loadimage(&Lattacka[1][2], _T("pictures\\Lattack\\a12.png"));
    loadimage(&Lattacka[1][3], _T("pictures\\Lattack\\a13.png"));
    loadimage(&Lattacka[1][4], _T("pictures\\Lattack\\a14.png"));
    loadimage(&Lattacka[2][0], _T("pictures\\Lattack\\a20.png"));
    loadimage(&Lattacka[2][1], _T("pictures\\Lattack\\a21.png"));
    loadimage(&Lattacka[2][2], _T("pictures\\Lattack\\a22.png"));
    loadimage(&Lattacka[2][3], _T("pictures\\Lattack\\a23.png"));
    loadimage(&Lattacka[2][4], _T("pictures\\Lattack\\a24.png"));
    loadimage(&Lattacka[2][5], _T("pictures\\Lattack\\a25.png"));
    loadimage(&Lattacka[2][6], _T("pictures\\Lattack\\a26.png"));
    loadimage(&Lattackb[0][0], _T("pictures\\Lattack\\b00.png"));
    loadimage(&Lattackb[0][1], _T("pictures\\Lattack\\b01.png"));
    loadimage(&Lattackb[0][2], _T("pictures\\Lattack\\b02.png"));
    loadimage(&Lattackb[0][3], _T("pictures\\Lattack\\b03.png"));
    loadimage(&Lattackb[1][0], _T("pictures\\Lattack\\b10.png"));
    loadimage(&Lattackb[1][1], _T("pictures\\Lattack\\b11.png"));
    loadimage(&Lattackb[1][2], _T("pictures\\Lattack\\b12.png"));
    loadimage(&Lattackb[1][3], _T("pictures\\Lattack\\b13.png"));
    loadimage(&Lattackb[1][4], _T("pictures\\Lattack\\b14.png"));
    loadimage(&Lattackb[2][0], _T("pictures\\Lattack\\b20.png"));
    loadimage(&Lattackb[2][1], _T("pictures\\Lattack\\b21.png"));
    loadimage(&Lattackb[2][2], _T("pictures\\Lattack\\b22.png"));
    loadimage(&Lattackb[2][3], _T("pictures\\Lattack\\b23.png"));
    loadimage(&Lattackb[2][4], _T("pictures\\Lattack\\b24.png"));
    loadimage(&Lattackb[2][5], _T("pictures\\Lattack\\b25.png"));
    loadimage(&Lattackb[2][6], _T("pictures\\Lattack\\b26.png"));

    //struck
    loadimage(&strucka[0], _T("pictures\\struck\\a0.png"));
    loadimage(&strucka[1], _T("pictures\\struck\\a1.png"));
    loadimage(&strucka[2], _T("pictures\\struck\\a2.png"));
    loadimage(&struckb[0], _T("pictures\\struck\\b0.png"));
    loadimage(&struckb[1], _T("pictures\\struck\\b1.png"));
    loadimage(&struckb[2], _T("pictures\\struck\\b2.png"));

    //Lstruck
    loadimage(&Lstrucka[0], _T("pictures\\Lstruck\\a0.png"));
    loadimage(&Lstrucka[1], _T("pictures\\Lstruck\\a1.png"));
    loadimage(&Lstrucka[2], _T("pictures\\Lstruck\\a2.png"));
    loadimage(&Lstruckb[0], _T("pictures\\Lstruck\\b0.png"));
    loadimage(&Lstruckb[1], _T("pictures\\Lstruck\\b1.png"));
    loadimage(&Lstruckb[2], _T("pictures\\Lstruck\\b2.png"));

    //farattack
    loadimage(&farattack[0], _T("pictures\\farattack\\0.png"));
    loadimage(&farattack[1], _T("pictures\\farattack\\1.png"));
    loadimage(&farattack[2], _T("pictures\\farattack\\2.png"));
    loadimage(&farattack[3], _T("pictures\\farattack\\3.png"));
    loadimage(&farattack[4], _T("pictures\\farattack\\4.png"));
    loadimage(&farattackmovea[0], _T("pictures\\farattack\\move0a.png"));
    loadimage(&farattackmovea[1], _T("pictures\\farattack\\move1a.png"));
    loadimage(&farattackmovea[2], _T("pictures\\farattack\\move2a.png"));
    loadimage(&farattackmovea[3], _T("pictures\\farattack\\move3a.png"));
    loadimage(&farattackmovea[4], _T("pictures\\farattack\\move4a.png"));
    loadimage(&farattackmovea[5], _T("pictures\\farattack\\move5a.png"));
    loadimage(&farattackmoveb[0], _T("pictures\\farattack\\move0b.png"));
    loadimage(&farattackmoveb[1], _T("pictures\\farattack\\move1b.png"));
    loadimage(&farattackmoveb[2], _T("pictures\\farattack\\move2b.png"));
    loadimage(&farattackmoveb[3], _T("pictures\\farattack\\move3b.png"));
    loadimage(&farattackmoveb[4], _T("pictures\\farattack\\move4b.png"));
    loadimage(&farattackmoveb[5], _T("pictures\\farattack\\move5b.png"));

    //fire
    loadimage(&farattackfire[0], _T("pictures\\farattack\\0.png"));
    loadimage(&farattackfire[1], _T("pictures\\farattack\\1.png"));
    loadimage(&farattackfire[2], _T("pictures\\farattack\\2.png"));
    loadimage(&farattackfire[3], _T("pictures\\farattack\\3.png"));
    loadimage(&farattackfire[4], _T("pictures\\farattack\\4.png"));
    //down
    loadimage(&downa[0], _T("pictures\\down\\a0.png"));
    loadimage(&downa[1], _T("pictures\\down\\a1.png"));
    loadimage(&downa[2], _T("pictures\\down\\a2.png"));
    loadimage(&downa[3], _T("pictures\\down\\a3.png"));
    loadimage(&downa[4], _T("pictures\\down\\a4.png"));
    loadimage(&downa[5], _T("pictures\\down\\a5.png"));
    loadimage(&downb[0], _T("pictures\\down\\b0.png"));
    loadimage(&downb[1], _T("pictures\\down\\b1.png"));
    loadimage(&downb[2], _T("pictures\\down\\b2.png"));
    loadimage(&downb[3], _T("pictures\\down\\b3.png"));
    loadimage(&downb[4], _T("pictures\\down\\b4.png"));
    loadimage(&downb[5], _T("pictures\\down\\b5.png"));


}
inline void Role::PutImage(role& A, IMAGE* imb, IMAGE* ima, IMAGE* Limb, IMAGE* Lima) {
    if (A.face == RIGHT)
    {
        putimage(A.x, A.y, imb, SRCAND);
        putimage(A.x, A.y, ima, SRCPAINT);
    }
    if (A.face == LEFT)
    {
        putimage(A.x, A.y, Limb, SRCAND);
        putimage(A.x, A.y, Lima, SRCPAINT);
    }
}
void Role::PrintBackground()
{
    putimage(0, 0, &background);
    putimage(141, 100, &blood[0], SRCAND);
    putimage(141, 100, &blood[1], SRCPAINT);
    putimage(268, 135, player1.blood, 19, &blood[2], 0, 0);
    putimage(1004 - player2.blood, 135, player2.blood, 19, &blood[2], 0, 0);
}

void Role::PrintStill(role& A, role& B, IMAGE* imb, IMAGE* ima, IMAGE* Limb, IMAGE* Lima)
{
    for (int i = 0; i < 4; i++)
    {
        BeginBatchDraw();
        PrintBackground();
        PutImage(A, imb + i, ima + i, Limb + i, Lima + i);
        PutImage(B, imb + i, ima + i, Limb + i, Lima + i);
        EndBatchDraw();
        Sleep(100);
        if (IsRunA(A) || IsRunB(B))
        {
            return;
        }
        if (IsJumpA(A) || IsJumping(A))
        {
            return;
        }
        if (IsJumpB(B) || IsJumping(B))
        {
            return;
        }
        if (IsFarAttack())
        {
            return;
        }
    }
}
int Role::IsJumpA(role& A)
{
    if (GetAsyncKeyState('K') && A.Isjumping < 1)
    {
        A.Isjumping++;
        IsGround(A);
        return 1;
    }
    return 0;
}
int Role::IsJumpB(role& B)
{

    if (GetAsyncKeyState(VK_NUMPAD2) && B.Isjumping < 1)
    {
        B.Isjumping++;
        IsGround(B);
        return 1;
    }
    return 0;
}
int Role::IsJumping(role& A)
{
    if (A.y < 600)
    {
        return 1;
    }
    return 0;
}
int Role::IsGround(role& A)
{
    if (player1.x + 38 < player2.x)
    {
        player1.face = RIGHT;
        player2.face = LEFT;
    }
    if (player2.x + 38 < player1.x)
    {
        player2.face = RIGHT;
        player1.face = LEFT;
    }
    if (player1.y == 600)
    {
        A.Isjumping = 0;
        return 1;
    }
    return 0;
}
int Role::IsStruck(role& B)
{
    if (IsAttack())
    {
        if (player1.face == RIGHT)
        {
            if (player1.x + 48 > B.x && player1.x < B.x + 86)
            {
                return 1;
            }
        }
        else
        {
            if (player1.x  < B.x + 48 && player1.x > B.x)
            {
                return 1;
            }
        }
    }
    return 0;
}
int Role::IsRunA(role& A)
{
    if (GetAsyncKeyState('D'))
    {
        A.face = RIGHT;
        return 1;
    }
    if (GetAsyncKeyState('A'))
    {
        A.face = LEFT;
        return 1;
    }
    return 0;
}
int Role::IsRunB(role& B)
{
    if (GetAsyncKeyState(VK_RIGHT))
    {
        B.face = RIGHT;
        return 1;
    }
    if (GetAsyncKeyState(VK_LEFT))
    {
        B.face = LEFT;
        return 1;
    }
    return 0;
}
void Role::PrintRun(role& A, role& B, IMAGE* imb, IMAGE* ima, IMAGE* Limb, IMAGE* Lima)//more variables make running process move smooth.
{
    for (int i = 0; i < 8; i++)
    {
        BeginBatchDraw();
        PrintBackground();
        if (IsRunA(A))
        {
            if (GetAsyncKeyState('D'))
            {
                if (((A.x + 15 < 1232) && ((A.x + 53) < B.x)) || (A.x > B.x))
                {
                    A.x += 15;
                }
            }
            else if (GetAsyncKeyState('A') && (A.x - 15 > player2.x + 38) || (A.x < player2.x))
            {
                if (A.x - 15 > 10)
                {
                    A.x -= 15;
                }
            }
            PutImage(A, imb + i, ima + i, Limb + i, Lima + i);
        }
        else//STILL
        {
            PutImage(A, stillb + i % 4, stilla + i % 4, Lstillb + i % 4, Lstilla + i % 4);
        }
        if (IsRunB(B))
        {
            if (GetAsyncKeyState(VK_RIGHT))
            {
                if (B.x < 1232)
                {
                    B.x += 15;
                }
            }
            if (GetAsyncKeyState(VK_LEFT))
            {
                if (B.x > 10)
                {
                    B.x -= 15;
                }
            }
            PutImage(B, imb + i, ima + i, Limb + i, Lima + i);
        }
        else//STILL
        {
            PutImage(B, stillb + i % 4, stilla + i % 4, Lstillb + i % 4, Lstilla + i % 4);
        }
        Sleep(50);
        EndBatchDraw();
        if (IsJumpA(A))
        {
            PrintJump(player1, player2, jumpb, jumpa, Ljumpb, Ljumpa);
            return;
        }
        if (IsAttack())
        {

            PrintAttack(A, &attackb[0], &attacka[0], &Lattackb[0], &Lattacka[0]);
        }
    }
}
void Role::PrintJump(role& A, role& B, IMAGE* imb, IMAGE* ima, IMAGE* Limb, IMAGE* Lima)
{
    for (int i = 0; i < 8; i++)
    {
        if (GetAsyncKeyState('D'))
        {
            if (A.x < 1232)
            {
                A.x += 15;
            }
        }
        if (GetAsyncKeyState('A'))
        {
            if (A.x > 10)
            {
                A.x -= 15;
            }
        }
        BeginBatchDraw();
        PrintBackground();
        A.y -= 18;
        PutImage(A, imb + i % 2, ima + i % 2, Limb + i % 2, Lima + i % 2);
        PutImage(B, stillb + i % 4, stilla + i % 4, Lstillb + i % 4, Lstilla + i % 4);
        EndBatchDraw();
        Sleep(28);
    }
    if (IsJumpA(A))
    {
        PrintJump(player1, player2, jumpb, jumpa, Ljumpb, Ljumpa);
    }
    if (IsJumping(A))
    {
        PrintFall(player1, player2, jumpb, jumpa, Ljumpb, Ljumpa);
    }
}
void Role::PrintFall(role& A, role& B, IMAGE* imb, IMAGE* ima, IMAGE* Limb, IMAGE* Lima)
{
    for (int i = 0; i < 7; i++)
    {
        if (IsJumpA(A))
        {
            PrintJump(player1, player2, jumpb, jumpa, Ljumpb, Ljumpa);
        }
        A.y += 18;
        if (GetAsyncKeyState('D'))
        {
            if (A.x < 1232)
            {
                A.x += 15;
            }
        }
        if (GetAsyncKeyState('A'))
        {
            if (A.x > 10)
            {
                A.x -= 15;
            }
        }
        BeginBatchDraw();
        PrintBackground();
        PutImage(A, imb + 2, ima + 2, Limb + 2, Lima + 2);
        PutImage(B, stillb + i % 4, stilla + i % 4, Lstillb + i % 4, Lstilla + i % 4);
        EndBatchDraw();
        Sleep(25);
    }
    A.y += 18;
    BeginBatchDraw();
    PrintBackground();
    PutImage(A, imb + 3, ima + 3, Limb + 3, Lima + 3);
    PutImage(B, stillb + 3, stilla + 3, Lstillb + 3, Lstilla + 3);
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
int Role::IsFarAttack()
{
    if (GetAsyncKeyState('U'))
    {
        return 1;
    }
    return 0;
}
void Role::PrintAttack(role& A, IMAGE(*imb)[7], IMAGE(*ima)[7], IMAGE(*Limb)[7], IMAGE(*Lima)[7])
{
    //the first attack.
    for (int i = 0; i < 4; i++) {
        if (A.face == RIGHT)
        {
            A.x += 4;
        }
        else
        {
            A.x -= 4;
        }
        BeginBatchDraw();
        PrintBackground();
        PutImage(A, *imb + i, *ima + i, *Limb + i, *Lima + i);
        if (IsStruck(player2))
        {
            player2.blood -= 5;
            if (A.face == RIGHT)
            {
                player2.x += 5;
            }
            else
            {
                player2.x -= 5;
            }
            PutImage(player2, struckb, strucka, Lstruckb, Lstrucka);
        }
        else
        {
            PutImage(player2, stillb + i, stilla + i, Lstillb + i, Lstilla + i);
        }
        EndBatchDraw();
        Sleep(80);
    }
    //the second attack.
    if (GetAsyncKeyState('J'))
    {
        for (int i = 0; i < 5; i++)
        {

            if (A.face == RIGHT)
            {
                A.x += 4;
            }
            else
            {
                A.x -= 4;
            }
            BeginBatchDraw();
            PrintBackground();
            PutImage(A, *(imb + 1) + i, *(ima + 1) + i, *(Limb + 1) + i, *(Lima + 1) + i);
            if (IsStruck(player2))
            {
                player2.blood -= 5;
                if (A.face == RIGHT)
                {
                    player2.x += 5;
                }
                else
                {
                    player2.x -= 5;
                }
                PutImage(player2, struckb + 1, strucka + 1, Lstruckb + 1, Lstrucka + 1);
            }
            else
            {
                PutImage(player2, stillb + i % 4, stilla + i % 4, Lstillb + i % 4, Lstilla + i % 4);
            }
            EndBatchDraw();
            Sleep(100);
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
                if (A.face == RIGHT)
                {
                    A.x += 20;
                }
                else
                {
                    A.x -= 20;
                }
            }
            BeginBatchDraw();
            PrintBackground();
            PutImage(A, *(imb + 2) + i, *(ima + 2) + i, *(Limb + 2) + i, *(Lima + 2) + i);
            if (IsStruck(player2))
            {
                player2.blood -= 5;
                if (i >= 2 && i <= 4)
                {
                    if (A.face == RIGHT)
                    {
                        player2.x += 30;
                    }
                    else
                    {
                        player2.x -= 30;
                    }
                }
                PutImage(player2, struckb + 2, strucka + 2, Lstruckb + 2, Lstrucka + 2);
            }
            else
            {
                PutImage(player2, stillb + i % 4, stilla + i % 4, Lstillb + i % 4, Lstilla + i % 4);
            }

            EndBatchDraw();
            Sleep(100);
        }
    }
    else
    {
        return;
    }
    Sleep(100);
}
void Role::PrintFarAttack(role& A, IMAGE* imb, IMAGE* ima, IMAGE* Limb, IMAGE* Lima)
{
    for (int i = 0; i < 5; i++)
    {
        BeginBatchDraw();
        PrintBackground();
        PutImage(player1, farattackmoveb + i, farattackmovea + i, farattackmoveb + i, farattackmovea + i);
        Sleep(200);
        PutImage(player2, stillb + i % 4, stilla + i % 4, Lstillb + i % 4, Lstilla + i % 4);
        EndBatchDraw();
    }
    for (int i = 0; i < 10; i++)
    {
        BeginBatchDraw();
        PrintBackground();
        PutImage(player1, farattackmoveb + 5, farattackmovea + 5, farattackmoveb + 5, farattackmovea + 5);
        putimage(player1.x + 40 + 20 * i, player1.y - 20, farattackfire + i % 5, SRCPAINT);
        if (player1.x + 40 + 20 * i + 100 > player2.x)
        {
            if (i < 6)
            {
                putimage(player2.x, player2.y, Lstruckb + i, SRCAND);
                putimage(player2.x, player2.y, Lstrucka + i, SRCPAINT);
                player2.x += 20;
                player2.blood -= 5;
            }
            else if (i == 6)
            {
                player2.y -= 20;
                putimage(player2.x, player2.y, downb, SRCAND);
                putimage(player2.x, player2.y, downa, SRCPAINT);
                player2.x += 20;
                player2.y += 20;
                player2.blood -= 5;
            }
            else
            {
                Sleep(100);
                putimage(player2.x, player2.y, downb + 1, SRCAND);
                putimage(player2.x, player2.y, downa + 1, SRCPAINT);
            }
        }
        else
        {
            PutImage(player2, stillb + i % 4, stilla + i % 4, Lstillb + i % 4, Lstilla + i % 4);
        }
        Sleep(200);
        EndBatchDraw();
    }
}
void Role::PrintMove()
{
    IsGround(player1);
    if (IsRunA(player1) || IsRunB(player2))
    {
        PrintRun(player1, player2, runb, runa, Lrunb, Lruna);
    }
    else if (IsJumpA(player1))
    {
        PrintJump(player1, player2, jumpb, jumpa, Ljumpb, Ljumpa);
    }
    else if (IsAttack())
    {
        PrintAttack(player1, &attackb[0], &attacka[0], &Lattackb[0], &Lattacka[0]);
    }
    else if (IsFarAttack())
    {
        PrintFarAttack(player1, farattack, farattack, farattack, farattack);
    }
    else
    {
        if (IsGround(player1))
        {
            PrintStill(player1, player2, &stillb[0], &stilla[0], &Lstillb[0], &Lstilla[0]);
        }
    }
    return;
}

int main()
{
    Role A(10, 600, 43, 38, 900, 600, 43, 38);
    A.Initial();
    initgraph(1280, 720);
    mciSendString(L"open naruto.mp3 alias bgm", 0, 0, 0);//´ò¿ªÒôÀÖ
    mciSendString(L"play bgm repeat", 0, 0, 0);//²¥·ÅÒôÀÖ

    while (1)
    {
        A.PrintMove();
        if (A.player2.blood <= 0)
        {
            break;
        }
    }

    return 0;
}
