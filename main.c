#include <conio.h>
#include <system.h>

int main() {
  int x,xv,y,yv,i,fudge;


  x=10;
  xv=-1;
  y=-4;
  yv=1;
  fudge=15;

  set_graphics(VDP_SPR_8x8MAG);
  //VDP_SET_REGISTER(VDP_REG_COL, COLOR_WHITE << 4 | COLOR_BLACK);

  gotoxy(0,0);
  cputs("Hello sprite!");


  sprite(0, 42, COLOR_WHITE, x, y);

  while (!kbhit()) {
    VDP_WAIT_VBLANK_CRU
    
    x=x+xv;
    y=y+yv;
    if (y>177 || y<-4) {
      yv=yv*-1;
    }
    if (x>244 || x<0) {
      xv=xv*-1;
    }

      
    sprite(0, 42, COLOR_WHITE, y, x);
  }
  exit();
  return 0;
}
