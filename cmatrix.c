/************************************************************************

  The Matrix Rain Screen Saver

  This code is converted from QBASIC to C.

  QBasic Code from
  http://codegolf.stackexchange.com/questions/17285/make-the-matrix-digital-rain-using-the-shortest-amount-of-code

************************************************************************/

#include <rtthread.h>
#include <stdlib.h>
#include <vt100.h>

static int t[VT_DEFAULT_COL_SIZE];

static void sub_d(int p, int s, int x, int y)
{
    rt_uint8_t r;
    rt_uint8_t g;

    r = (p % 16) * 16;
    g = 180 - p;
    if (r < 10)
    {
        vt_set_font_color(VT_F_BLACK);
    }
    else
    {
        if (g > 170)
        {
            vt_set_font_color(VT_F_WHITE);
        }
        else if (g < 170)
        {
            vt_set_font_color(VT_F_GREEN);
        }
    }

    if ((y >= 0) && (y < VT_DEFAULT_ROW_SIZE) && (x < VT_DEFAULT_COL_SIZE))
    {
        char c;
        c = 33 + (x * y) % 94;
        vt_draw_char_at(y, x, c);
    }
}

static void cmatrix(int argc, char const *argv[])
{
    int i;
    int x;
    int y;
    int k;

    vt_hide_cursor();
    vt_store_screen();
    vt_clearall();

    for (i = 0; i < VT_DEFAULT_COL_SIZE; i++)
    {
        //t[i] = - random() % 50;
        t[i] = - rand() % 50;
    }

    //sub_d(1,1,10,10);
    while (1)
    {
        for (k = 1; k < VT_DEFAULT_COL_SIZE; k++)
        {
            i = rand() % (VT_DEFAULT_COL_SIZE-1);
            if (t[i] > 28)t[i] = 0;
            t[i] = t[i] + 1;
            y = t[i];
            sub_d( 0     , 0, i, y - 6);
            sub_d( 2  + x, 0, i, y - 5);
            sub_d( 2  + x, 0, i, y - 4);
            sub_d( 10 + x, 0, i, y - 3);
            sub_d( 10 + x, 0, i, y - 2);
            sub_d( 11 + x, 0, i, y - 1);
            sub_d( 0     , 2 + x, i, y);
        }
    }

    vt_restore_screen();
    vt_show_cursor();
}
MSH_CMD_EXPORT(cmatrix, matrix rain)
