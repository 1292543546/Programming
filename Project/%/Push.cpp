#include<iostream>
#include<map>
#include<cstring>
std::map<std::string,bool>mp;
inline void init();
int main()
{
  init();
  if(mp["��ʵѧ�����Ÿ��Ѿ���"],mp["����λ�������"],mp["�������ö�"],mp["����˯����������"],mp["��Ϸ����ú�"])
  {
  	std::cout<<"��ʵ����̫ǿ��"<<std::endl;
  }
  else
  {
  	std::cout<<"��ʵ���ܱ�ø�ǿ"<<std::endl;
  }
  return 0;
}














inline void init()
{
  mp["��ʵѧ�����Ÿ��Ѿ���"]=0;
  mp["�������ö�"]=1;
  mp["����λ�������"]=0;
  mp["����˯����������"]=0;
  mp["��Ϸ����ú�"]=1;
  return;
}
