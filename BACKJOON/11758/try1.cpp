#include <iostream>

int main()
{
    int x1, x2, y1, y2, x3, y3;
    scanf("%d %d", &x1, &y1);
    scanf("%d %d", &x2, &y2);
    scanf("%d %d", &x3, &y3);

    //v1=(x1,x1),v2=(x2,y2)

    x1 = x2 - x1;
    y1 = y2 - y1;
    x2 = x3 - x2;
    y2 = y3 - y2;

    //vector produt x3

    x3 = x1 * y2 - y1 * x2;

    if (x3 == 0)
        printf("0");
    else if (x3 > 0)
        printf("1");
    else
        printf("-1");

    return 0;
}