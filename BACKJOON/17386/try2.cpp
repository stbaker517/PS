#include <iostream>

typedef struct point
{
    int x, y;
} point;
typedef struct Vector
{
    int x, y;
} Vector;
int Dot_Product(point, point, point);
int Cross_Product(point, point, point);
int Isitpoint(point, point);

int check();
int main()
{
    /*int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("%d left\n",n-1-i);
        check();
        printf("\n");
    }*/
    check();
}

int Isitpoint(point p1, point p2)
{
    if (p1.x == p2.x && p1.y == p2.y)
        return 1;
    else
        return 0;
}

int Dot_Product(point p1, point p2, point p3)
{
    Vector v1, v2;
    v1.x = p2.x - p1.x;
    v1.y = p2.y - p1.y;
    v1.x = p3.x - p1.x;
    v1.y = p3.y - p1.y;

    int result = v1.x * v2.x - v1.y * v2.y;

    if (result > 0) //less than 90
        return 1;
    else if (result == 0) //90
        return 0;
    else
        return -1;
}
int Cross_Product(point p1, point p2, point p3)
{
    Vector v1, v2;
    v1.x = p2.x - p1.x;
    v1.y = p2.y - p1.y;
    v2.x = p3.x - p1.x;
    v2.y = p3.y - p1.y;

    int result = v1.x * v2.y - v1.y * v2.x;
    if (result > 0) 
        return 1;
    else if (result == 0) 
        return 0;
    else
        return -1;
}

int check()
{
    point p1, p2, p3, p4;
    scanf("%d %d %d %d", &p1.x, &p1.y, &p2.x, &p2.y);
    scanf("%d %d %d %d", &p3.x, &p3.y, &p4.x, &p4.y);

    //점 먼저 확인

    if (Isitpoint(p1, p2) && Isitpoint(p3, p4)) //하나의 겹치는 점인가?
    {
        if (Isitpoint(p1, p3))
        {
            printf("1");
            return 0;
        }
    }

    int cp1, cp2, cp3, cp4;
    cp1 = Cross_Product(p1, p2, p3);
    cp2 = Cross_Product(p1, p2, p4);
    cp3 = Cross_Product(p3, p4, p1);
    cp4 = Cross_Product(p3, p4, p2);

   
    if(cp1*cp2<0&&cp3*cp4<0)//단순 교차
    {
        printf("1");
        return 0;
    }
    else if(cp1*cp2==0)//점 하나가 선분 위에 있음.
    {
        //선분 안에 점 존재
        //p3가 선분 안에 존재
        
        //cp1이 0이면
        if(cp1==0)
        {
            if(abs(p3.x-p1.x)<=abs(p2.x-p1.x))
            {
                if((p3.x-p1.x)*(p2.x-p1.x)>=0)
                {printf("1");
                return 0;}
            }
        }
        if(cp2==0)
        {
            if(abs(p4.x-p1.x)<=abs(p2.x-p1.x))
            {
                if((p4.x-p1.x)*(p2.x-p1.x)>=0)
                {printf("1");
                return 0;}
            }
        }

        //p4가 선분 안에 존재
        //같은 직선 위에 겹치게 존재

        //같은 직전에 안 겹치게 존재
    }
    else if(cp3*cp4==0)//점 하나가 선분 위에 있음.
    {
        if(cp3==0)
        {
            if(abs(p1.x-p3.x)<=abs(p4.x-p3.x))
            {
                if((p1.x-p3.x)*(p4.x-p3.x)>=0)
                {printf("1");
                return 0;}
            }
        }
        if(cp4==0)
        {
            if(abs(p2.x-p3.x)<=abs(p4.x-p3.x))
            {
                if((p2.x-p3.x)*(p4.x-p3.x)>=0)
                {printf("1");
                return 0;}
            }
        }
    }
    else
    {
        printf("0");
        return 0;
    }
    return 0;
}