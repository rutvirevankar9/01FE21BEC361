#include<stdio.h>
void pos(int a[10][10]);
void pos(int a[10][10])
{
  int i,j,n;
  int w_s=0;
  int w_e=0;
  int b_s=0;
  int b_e=0;
  int pos1=0;
  int pos2=0;
  int pos3=0;
  int pos4=0;
  for(i=0;i<n;i++)
  {

      for(j=i+1;j<n;j++)
      {
          w_e=j+1;
          b_e=j+4;
          b_s=j+2;
          w_s=j+3;

      }


  }

          pos1=b_s;
          pos2=w_s;
          pos3=b_e;
          pos4=w_e;


}
int main()
{
    int a[10][10],n,p,i,j;
    char s[50];
    int  w_s;
    int w_e;
    int b_s;
    int b_e;
    int pos1;
    int pos2;
    int pos3;
    int pos4;

    printf("enter the value of n");
    scanf("%d",&n);
    pos(a);
    printf("enter the coin whose position needs to be displayed");
    scanf("%s",s);

    if(s==b_s)
    {

        printf("%d",pos1);

    }
    else
        if(s==w_s)
    {
        printf("%d",pos2);
    }
    else if(s==b_e)
    {
        printf("%d",pos3);

    }
    else
    {
        printf("%d",pos4);
    }



}
