#include <iostream>

typedef struct point
{
    int x, y;
} point;

typedef struct vector
{
    int x, y;
} vector;

int CP(point p1, point p2, point p3)
{
    //앞에거 두개가 선분을 이룬다.

    vector V1, V2;
    V1.x = p2.x - p1.x;
    V1.y = p2.y - p1.y;

    V2.x = p3.x - p1.x;
    V2.y = p3.y - p1.y;

    int cp = V1.x * V2.y - V1.y * V2.x;

    if (cp > 0)
        return 1;
    else if (cp < 0)
        return -1;
    else
        return 0;
}
int main()
{
    point p1, p2, p3, p4;

    scanf("%d %d %d %d", &p1.x, &p1.y, &p2.x, &p2.y); //선분1
    scanf("%d %d %d %d", &p3.x, &p3.y, &p4.x, &p4.y); //선분2

    //점일 때 고려를 안했네?

    if((p1.x == p2.x && p1.y == p2.y)&&(p3.x == p4.x && p3.y == p4.y))
    {//둘 다 점.
        if(p1.x==p3.x)
        {
            printf("1");
            return 0;

        }
        else {
            printf("0");
            return 0;
        }
    }
    else if (p1.x == p2.x && p1.y == p2.y) //점
    {
        if (CP(p3, p4, p1) == 0)
        {
            printf("1");
            return 0;
        }
    }
    else if (p3.x == p3.x && p4.y == p4.y) //점
    {
        if (CP(p1, p2, p4) == 0)
        {
            printf("1");
            return 0;
        }
    }

    //점일 때 처리했음.

    //세개의 점으로 이뤄졌을 때
    int same = 0;
    if (p1.x == p3.x && p1.y == p3.y)
        same = 1;
    if (p1.x == p4.x && p1.y == p4.y)
        same = 1;
    if (p2.x == p3.x && p2.y == p3.y)
        same = 1;
    if (p2.x == p4.x && p2.y == p4.y)
        same = 1;
    int cp1, cp2, cp3, cp4;
    cp1 = CP(p1, p2, p3);
    cp2 = CP(p1, p2, p4);
    cp3 = CP(p3, p4, p1);
    cp4 = CP(p3, p4, p2);
    if (same == 1)
        printf("1");
    else
    {
        if (cp1 * cp2 < 0 && cp3 * cp4 < 0)
            printf("1");

        else
            printf("0");
    }
}