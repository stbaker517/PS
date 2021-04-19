#include<iostream>
#include<cmath>
int check(char*str)
{
    if(strcmp(str,"black")==0)
    return 0;
    
 if(strcmp(str,"brown")==0)	return 1;
 if(strcmp(str,"red")==0)	return 2;
 if(strcmp(str,"orange")==0)	return 3;
 if(strcmp(str,"yellow")==0)	return 4;
 if(strcmp(str,"green")==0)		return 5;
 if(strcmp(str,"blue")==0)	return 6;
 if(strcmp(str,"violet")==0)	return 7;
 if(strcmp(str,"grey")==0)	return 8;
 if(strcmp(str,"white")==0)return 9;
}
int main(){
    char str[10];
    int a[3],result=0;
    for(int i=0;i<3;i++)
    {
        scanf("%s",str);
        getchar();
        a[i]=check(str);
    }
    result=(a[0]+a[1])*(int)pow(10,a[2]);
    printf("%d",result);
}