#include<graphics.h>
#include<conio.h>

int main() 
{
    initgraph(500,500);
    IMAGE background,stillb[4],stilla[4];
    loadimage(&background, _T("pictures\\background\\0.png"));
    loadimage(&stilla[0], _T("pictures\\still\\a0.png"));
    loadimage(&stilla[1], _T("pictures\\still\\a1.png"));
    loadimage(&stilla[2], _T("pictures\\still\\a2.png"));
    loadimage(&stilla[3], _T("pictures\\still\\a3.png"));

    loadimage(&stillb[0], _T("pictures\\still\\b0.png"));
    loadimage(&stillb[1], _T("pictures\\still\\b1.png"));
    loadimage(&stillb[2], _T("pictures\\still\\b2.png"));
    loadimage(&stillb[3], _T("pictures\\still\\b3.png"));
    
    
    
    while(1)
    {
        putimage(0, 0, &background);
        for (int i = 0; i < 4; i++)
        {
            BeginBatchDraw();
            putimage(10, 300, &stillb[i], SRCAND);
            putimage(10, 300, &stilla[i], SRCPAINT);
            EndBatchDraw();
            Sleep(100);
        }
    }
    system("pause");
	return 0;
}