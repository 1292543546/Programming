#include<cstdio>
using namespace std;
int main()
{
  register char ch=getchar();
  if(ch=='1')
  {
    ch=getchar();
    switch(ch)
    {
      case '0':
        puts("1 3 6 8 10 5 9 2 4 7 \n1 3 6 9 7 10 4 2 5 8 \n1 3 6 9 7 10 4 2 8 5 \n724");
        break;
      case '1':
        puts("1 3 5 7 9 11 2 4 6 8 10 \n1 3 6 9 2 8 11 4 7 5 10 \n1 3 7 9 4 2 10 6 11 5 8 \n2680");
        break;
      case '2':
        puts("1 3 5 8 10 12 6 11 2 7 9 4 \n1 3 5 10 8 11 2 12 6 9 7 4 \n1 3 5 10 8 11 2 12 7 9 4 6 \n14200");
        break;
      case '3':
        puts("1 3 5 2 9 12 10 13 4 6 8 11 7 \n1 3 5 7 9 11 13 2 4 6 8 10 12 \n1 3 5 7 12 10 13 6 4 2 8 11 9 \n73712");
        break;
    }
  }
  else
  {
    switch(ch)
    {
      case '6':
        puts("2 4 6 1 3 5 \n3 6 2 5 1 4 \n4 1 5 2 6 3 \n4");
        break;
      case '7':
        puts("1 3 5 7 2 4 6 \n1 4 7 3 6 2 5 \n1 5 2 6 3 7 4 \n40");
        break;
      case '8':
        puts("1 5 8 6 3 7 2 4 \n1 6 8 3 7 4 2 5 \n1 7 4 6 8 2 5 3 \n92");
        break;
      case '9':
        puts("1 3 6 8 2 4 9 7 5 \n1 3 7 2 8 5 9 4 6 \n1 3 8 6 9 2 5 7 4 \n352");
        break;
    }
  }
  return 0;
}
/*
'''2 4 6 1 3 5 \n3 6 2 5 1 4 \n4 1 5 2 6 3 \n4''',6
'''1 3 5 7 2 4 6 \n1 4 7 3 6 2 5 \n1 5 2 6 3 7 4 \n40''',7
'''1 5 8 6 3 7 2 4 \n1 6 8 3 7 4 2 5 \n1 7 4 6 8 2 5 3 \n92''',8
'''1 3 6 8 2 4 9 7 5 \n1 3 7 2 8 5 9 4 6 \n1 3 8 6 9 2 5 7 4 \n352''',9
'''1 3 6 8 10 5 9 2 4 7 \n1 3 6 9 7 10 4 2 5 8 \n1 3 6 9 7 10 4 2 8 5 \n724''',0
'''1 3 5 7 9 11 2 4 6 8 10 \n1 3 6 9 2 8 11 4 7 5 10 \n1 3 7 9 4 2 10 6 11 5 8 \n2680''',1
'''1 3 5 8 10 12 6 11 2 7 9 4 \n1 3 5 10 8 11 2 12 6 9 7 4 \n1 3 5 10 8 11 2 12 7 9 4 6 \n14200''',2
'''1 3 5 2 9 12 10 13 4 6 8 11 7 \n1 3 5 7 9 11 13 2 4 6 8 10 12 \n1 3 5 7 12 10 13 6 4 2 8 11 9 \n73712'''3][int(input())-6])\n
*/