#include<stdio.h>
void transpose(int a[10][10],int b[10][10],int m,int n,int p);
void print(int a[10][10],int m,int n)
main()
{
  file*fp;
  fp=fopen("transpose.txt","w");
  fprintf("the matrix to read %d",a[i][j]);
  fprintf(fp,%d,a[i][j]);
  fclose(fp);
  fp=fopen("transpose.txt","r");
  transpose(a,b,m,n,p);
  fprintf("the matrix after transpose is");
  fprintf(fp,%d,b[j][i]);




}
int transpose(int a[10][10],int b[10][10],int m.int n,int p)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            b[j][i]=a[i][j];
        }
    }

}
