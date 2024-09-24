#include <stdio.h>
int main ( ){
    int x1, y1, x2, y2;
    int xp,yp;
    scanf("%d  %d %d %d",&x1,&y1,&x2,&y2);
    scanf("%d  %d",&xp, &yp);
    
    if (y2>yp && yp>y1 && x2>xp && xp>x1){
        printf("Dentro!\n");
    }else{
        printf("Fora!\n");
    }

    return 0;
}