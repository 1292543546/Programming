#include<iostream>
#include<map>
#include<algorithm>
#include<windows.h>
#include<time.h>
#include<conio.h>
#include<cmath>
#include<cctype>
#include<io.h>
#include<stdlib.h>
#include<fstream>
#include<shellapi.h>
#include<cstdio>
#include<winuser.h>
#include<cstring>
#define RED(); SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_INTENSITY);
#define YELLOW(); SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY);
#define GREEN(); SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN|FOREGROUND_INTENSITY);
#define CYAN(); SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
#define BLUE(); SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE|FOREGROUND_INTENSITY);
#define PURPLE(); SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
#define WHITE(); SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_GREEN);
#define HUANYUAN(); SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_GREEN);
#define GRAY(); SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY);
#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0)
using namespace std;
map<string,string>date; 
map<string,int>PROPMAX;
char ch;
long long a,b,gamesend;
bool bj,bj2;
int cour;
string st,Verification;
char mapmap[10001][10001],showmap[10001][10001];
DWORD t1,t2;
long long frequency,Maxfrequency;
HWND hwnd=GetForegroundWindow();
struct account{
    string ID;
    string PassWord;
}Account;
string propname[110]={"��","�Ѳ�","ֽ","�������","��ľ","ľ��","ս��֮��","����֮��","����֮��","����ͼ","��ֲ֮��","ľͷ","Сʯ��","�ܲ�","����","��������","�������","��ʯ","Ƥ��","��ʯ","�ɲ�","С��֦","ľ̿","��","����","��","ľ��","ʯ��","����","ʯ��","����","ʯѼ���","��Ѽ���","�ݼ�","��","ľ��","ҩ��","ҩ","��","����","��","Զ�Ż���","Զ�Ŵ�","��","����","��������","���ߴ���","����","ʯש","����Ԫ��","��ħ��","��ħ֮��","��ħ��","����ʯ","������","��������","�챦ʯ","�ȱ�ʯ","�Ʊ�ʯ","�ϱ�ʯ","�̱�ʯ","�ڱ�ʯ","�ױ�ʯ","������","���ڻ���","ʥ�໤��","���˻���","���˻���","���令��","��ħ��","�ӶỤ��","��������","ֲ�ﻤ��","ȼ�մ���","С���","������","����","����","����","����","����","����","��Ģ��","��Ģ��","��Ģ��","�����ɱ�","�������","����","�������","������","��������","���Ⱥ���","ʲ��ʥ��","����ɳ��","������","����嵰","�Ϲϱ���","��֭����","����","���⴮","����ǧ����","��֭С���","����","�𼦴��","�߲��ӻ�","ʯ��","����","����Կ��","����Կ��","����Կ��"};
string id;
string password;
int dosum;
string dosomething[1001];
int propsum;
string now;
int prop[2][33];
int HP;
int MAXHP;
int Exocet;
int power;
int MAXpower;
int Day;
int percentage;
int hungry;
int MAXhungry; 
bool Course; 
bool rate(int Successrate,int allrate)
{
    srand(time(0));
    srand(rand()+time(0));
    int a=rand()%allrate+1;
    if(a<=Successrate) return true; else return false;
}
int findpropnumber(long long propnamenumber)
{
    long long lj;
    int i=1;
    for(;i<=32;i++)  if(prop[0][i]==propnamenumber) lj+=prop[1][i];
    return prop[1][i];;
}
bool findprop(long long propnamenumber)
{
    for(int i=1;i<=32;i++)  if(prop[0][i]==propnamenumber) return true;
    return false;
}
void pt(int propID,long long number)
{
    for(int i=1;i<=32;i++)
        if(prop[0][i]==propID)
        {
            if(prop[0][i]>=number) {prop[0][i]-=number;return;}
            if(prop[0][i]<number) {number-=prop[0][i];prop[0][i]=0;}
        }
    return;
}
string potout(int propID,long long number)
void HPdown(long long waittime)
{
    system("color 4F");
    Sleep(500);
    system("color");
}
void potin(int propID,long long number,long long )
{
    for(int i=1;i<=32;i++)
        if(prop[0][i]==propID)
            if(prop[1][i]+number>PROPMAX[propname[propID]]) {propID-=PROPMAX[propname[propID]]-prop[1][i];prop[1][i]=PROPMAX[propname[propID]];} else {prop[1][i]+=number;return;}
    for(int i=1;i<=32;i++)
        if(prop[0][i]==0) {prop[0][i]=propID;prop[1][i]=number;}
    return;
}
void Synthesis()
{

    return;
}
void test()
{
    for(int i=1;i<=32;i++)
        if(prop[1][i]<=0) {prop[0][i]=0;prop[1][i]=0;prop[2][i]=0;}
    return;
}
char ckzt(HWND hwnd)
{
    if(!IsIconic(hwnd)&&!IsZoomed(hwnd)) return '?'; else
        if(IsZoomed(hwnd)) return 'b'; else
            return 's';
}
void wait(int a)
{
    DWORD t1,t2;
    t1=GetTickCount();
    while(GetTickCount()-t1<a);
    return;
}
void say(string st,int speed)
{
    int l=st.length();
    for(int i=0;i<l;i++)cout<<st[i],Sleep(speed);
}
void Sigh()
{
    HUANYUAN();
    system("cls");
    while(!(bj==1&&ch=='\r'))
    {
        CYAN();
        cout<<"�ʺ�:";
        cout<<Account.ID;
        cout<<endl;
        PURPLE();
        cout<<"����:";
        for(int i=1;i<=Account.PassWord.size();i++)  cout<<'*';
        ch=getch();
        if(bj==0) 
        {
            if(ch=='\b'&&Account.ID!="") {Account.ID[Account.ID.size()-1]='\0';st=Account.ID;Account.ID="";for(int i=0;i<st.size()-1;i++) Account.ID+=st[i];} else
                if(ch=='\r') {bj=1;ch='\000';} else
                    if(ch=='\340') {ch=getch();} else
                        if(ch!='\r'&&ch!='\033') Account.ID+=ch;
        }
        if(bj==1) 
        {
            if(ch=='\b'&&Account.PassWord!="") {Account.PassWord[Account.PassWord.size()-1]='\0';st=Account.PassWord;Account.PassWord="";for(int i=0;i<st.size()-1;i++) Account.PassWord+=st[i];} else 
                if(ch=='\340') {ch=getch();if(ch=='H') bj=0;} else 
                    if(ch=='\340') {ch=getch();} else
                        if(ch!='\r'&&ch!='\033') Account.PassWord+=ch;
            if(bj2==0) {Account.PassWord="";bj2=1;}
        }
        system("cls");
        HUANYUAN();
    }
    string st2=Account.ID+".txt";
    if((_access(st2.c_str(),0))==-1) 
    {
        RED();
        cout<<st2<<endl;
        cout<<"���ʺ�ʧ��!ԭ���޴��˺š�";
        wait(1000);
        HUANYUAN();
        system("cls");
        ch='\0';
        Account.ID="";
        Account.PassWord="";
        Sigh();
        return; 
    }
    FILE* d=fopen(st2.c_str(),"rt+");
    char ch2;
    while(ch2!='\n')
    {
        fscanf(d,"%c",&ch2);
        if(ch2!='\n') password+=ch2;
    }
    if(password!=Account.PassWord)
    {
        RED();
        cout<<"���˺�ʧ��!ԭ���������";
        wait(1000);
        HUANYUAN();
        system("cls");
        ch='\0';
        Account.PassWord="";
        Sigh();
        return; 
    }
    id=Account.ID;
    fscanf(d,"%d",&propsum);
    for(int i=1;i<=32;i++) fscanf(d,"%d%d%d",&prop[0][i],&prop[1][i],&prop[2][i]);
    fscanf(d,"%d%d%d%d%d%d%d%d&d%d",&HP,&MAXHP,&Exocet,&power,&MAXpower,&Day,&hungry,&MAXhungry,&cour,&gamesend);
    if(cour==0) Course=0; else Course=1;
    return;
}
void Establish()
{
    HUANYUAN();
    system("cls");
    while(!(bj==1&&ch=='\r'))
    {
        CYAN();
        cout<<"�ʺ�:";
        cout<<Account.ID;
        cout<<endl;
        PURPLE();
        cout<<"����:";
        for(int i=1;i<=Account.PassWord.size();i++)  cout<<'*';
        ch=getch();
        if(bj==0) 
        {
            if(ch=='\b'&&Account.ID!="") {st=Account.ID;Account.ID="";for(int i=0;i<st.size()-1;i++) Account.ID+=st[i];} else
                if(ch=='\r') {bj=1;ch='\000';} else
                    if(ch=='\340') {ch=getch();} else
                        if(ch!='\r'&&ch!='\033') Account.ID+=ch;
        }
        if(bj==1) 
        {
            if(ch=='\b'&&Account.PassWord!="") {st=Account.PassWord;Account.PassWord="";for(int i=0;i<st.size()-1;i++) Account.PassWord+=st[i];} else 
                if(ch=='\340') {ch=getch();if(ch=='H') bj=0;} else 
                    if(ch=='\340') {ch=getch();} else
                        if(ch!='\r'&&ch!='\033') Account.PassWord+=ch;
            if(bj2==0) {Account.PassWord="";bj2=1;}
        }
        system("cls");
        HUANYUAN();
    }
    ch='\0';
    while(ch!='\r')
    {
        YELLOW();
        cout<<"������������:";
        for(int i=1;i<=Verification.size();i++)
            cout<<'*';
        ch=getch();
        if(ch=='\b'&&Verification!="") {st=Verification;Verification="";for(int i=0;i<st.size()-1;i++) Verification+=st[i];} else
                if(ch=='\340') {ch=getch();} else
                    if(ch!='\r'&&ch!='\033') Verification+=ch;
        system("cls");
    }
    HUANYUAN();
    if(Verification!=Account.PassWord)
    {
        Account.PassWord="";
        Verification="";
        bj2=0;
        bj=1;
        ch='\0';
        RED();
        cout<<"��";
        YELLOW();
        cout<<"��";
        GREEN();
        cout<<"��";
        CYAN();
        cout<<"��";
        BLUE();
        cout<<"��";
        PURPLE();
        cout<<"ͬ";
        HUANYUAN();
        cout<<"!";
        wait(1000);
        Establish();
        return;
    }
    string st3=Account.ID+".txt";
    if((_access(st3.c_str(),0))!=-1) 
    {
        RED();
        cout<<"�ļ�����ʧ��!ԭ�����д��ļ���";
        HUANYUAN();
        wait(1000);
        Account.PassWord="";
        Account.ID="";
        Verification="";
        bj2=0;
        bj=0;
        Establish();
        return;
    } 
    string st2="echo "+Account.PassWord+" >> "+st3;
    system(st2.c_str());
    FILE* a=fopen(st3.c_str(),"rt+");
    fprintf(a,"%s\n",Account.PassWord.c_str());
    fprintf(a,"0\n");
    for(int i=1;i<=32;i++) fprintf(a,"0 0 0\n");
    fprintf(a,"10\n50\n10\n20\n50\n1\n50\n100\n0\n%lld",send);
    GREEN();
    cout<<"��ͼ����(������17��):";
    long long send;
    cin>>send;
    cout<<"�ļ������ɹ�!";
    system("cls");
    fprintf(a,"%lld",send);
    fclose(a);
    HUANYUAN();
    system("cls");
    Account.PassWord="";
    ch=getch();
    ch='\0';
    return;
}
void GO()
{
    power-=5;
    return;
}
void stop(long long alltime)
{
    for(int k=1;k<=10;k++)
    {
        long long j;
        cout<<"|��������������������|\n"
        cout<<"|";
        for(int i=1;i<=j;i++) cout<<"��";
        for(int i=j+1;i<=10;i++) cout<<"��";
        cout<<"|\n";
        cout<<"|��������������������|";
        wait(alltime/10);
    }
    return;
}
void SLEEP()
{
    system("cls");
    say("����,��Ԯ����Ȼû����,ϣ������������������\n",100);
    say("�������ˣ�\n",250);
    for(int i=1;i<=dosum;i++)
    {
        cout<<dosum<<".";
        wait(100);
        say(dosomething[i],100);
        cout<<"\n";
        wait(100);
        dosomething[i]="";
    }
    wait(900);
    system("cls");
    say("����������������������������������������������������������������\n��������������������������������������������������������������\n������������������������������������������������������������\n����������������������������������������������������������\n��������������������������������������������������������\n����������������������������������������������������������������������������\n",5);
    wait(400);
    system("cls");
    power=MAXpower;
    now="";
    dosum=0;
    hungry-=20;
    return;
}
void PROP()
{
    long long hang,lie;
    for(int i=1;i<=4;i++)
    {
        for(int j=1;j<=8;j++)
        {
            if(hang==i&&lie==j) YELLOW();
                HUANYUAN();
        }
    }
}
int main()
{
    PROPMAX["ԭ����"]=40;
    PROPMAX["ħ��ԭ����"]=20;
    PROPMAX["ʳ��"]=40;
    PROPMAX["��Ʒ"]=20;
    PROPMAX["��Ʒ"]=1;
    PROPMAX["��ֲ"]=40;
    PROPMAX["����"]=1;
    PROPMAX["����"]=1;
    PROPMAX["��"]=1;
    PROPMAX["��"]=1;
    PROPMAX["��������"]=10;
    PROPMAX["��"]=1;
    PROPMAX["����"]=5;
    PROPMAX["����"]=20;
    PROPMAX["Ԫ��"]=10;

    date["ľͷ"]="ԭ����";
    date["Сʯ��"]="ԭ����";
    date["��ʯ"]="ԭ����";
    date["Ƥ��"]="ԭ����";
    date["�������"]="ԭ����";
    date["��ʯ"]="ԭ����";
    date["�ɲ�"]="ԭ����";
    date["С��֦"]="ԭ����";
    date["ľ̿"]="ԭ����";
    date["��"]="ԭ����";
    date["����"]="ԭ����";
    date["�Ѳ�"]="ԭ����";
    date["ҩ��"]="ԭ����";
    date["��"]="ԭ����";
    date["��"]="ԭ����";
    date["��ľ"]="ԭ����";

    date["�챦ʯ"]="ħ��ԭ����";
    date["�ȱ�ʯ"]="ħ��ԭ����";
    date["�Ʊ�ʯ"]="ħ��ԭ����";
    date["�̱�ʯ"]="ħ��ԭ����";
    date["�౦ʯ"]="ħ��ԭ����";
    date["����ʯ"]="ħ��ԭ����";
    date["�ϱ�ʯ"]="ħ��ԭ����";
    date["�ڱ�ʯ"]="ħ��ԭ����";
    date["�ױ�ʯ"]="ħ��ԭ����";

    date["��������"]="��Ʒ";
    date["���˻���"]="��Ʒ";
    date["���˻���"]="��Ʒ";
    date["ֲ�ﻤ��"]="��Ʒ";
    date["�ഺ����"]="��Ʒ";
    date["���令��"]="��Ʒ";
    date["�ӶỤ��"]="��Ʒ";
    date["ʥ�໤��"]="��Ʒ";
    date["���ڻ���"]="��Ʒ";

    date["�ܲ�"]="ʳ��";
    date["����"]="ʳ��";
    date["��������"]="ʳ��";
    date["�������"]="ʳ��";
    date["��"]="ʳ��";
    date["������"]="ʳ��";
    date["��������"]="ʳ��";
    date["С���"]="ʳ��";
    date["ʯ��"]="ʳ��";
    date["����"]="ʳ��";
    date["������"]="ʳ��";
    date["��Ģ��"]="ʳ��";
    date["����"]="ʳ��";
    date["����"]="ʳ��";
    date["������"]="ʳ��";
    date["��Ģ��"]="ʳ��";
    date["��Ģ��"]="ʳ��";
    date["����"]="ʳ��";
    date["�������"]="ʳ��";

    date["�߲��ӻ�"]="��Ʒ";
    date["�𼦴��"]="��Ʒ";
    date["��֭С���"]="��Ʒ";
    date["����ǧ����"]="��Ʒ";
    date["���⴮"]="��Ʒ";
    date["����"]="��Ʒ";
    date["��֭����"]="��Ʒ";
    date["�Ϲϱ���"]="��Ʒ";
    date["����嵰"]="��Ʒ";
    date["����ɳ��"]="��Ʒ";
    date["ʲ��ʥ��"]="��Ʒ";
    date["���Ⱥ���"]="��Ʒ";
    date["��������"]="��Ʒ";
    date["����"]="��Ʒ";
    date["����"]="��Ʒ";
    date["����"]="��Ʒ";
    date["�����ɱ�"]="��Ʒ";
    date["�������"]="��Ʒ";

    date["ľ��"]="����";
    date["ʯ��"]="����";
    date["����"]="����";
    date["Զ�Ŵ�"]="����";
    date["������"]="����";
    date["��ħ��"]="����";
    date["��ħ��"]="����";

    date["���ߴ���"]="��������";
    date["���洵��"]="��������";
    date["��������"]="��������";

    date["�ݼ�"]="����";
    date["ľ��"]="����";
    date["����"]="����";
    date["Զ�Ż���"]="����";
    date["Ƥ��"]="����";

    date["ʯ��"]="��";
    date["����"]="��";

    date["ʯѼ���"]="��";
    date["��Ѽ���"]="��";

    date["����Կ��"]="����";
    date["����Կ��"]="����";
    date["����Կ��"]="����";

    date["����"]="��ֲ";

    date["�Ƽ�Ԫ��"]="Ԫ��"; 

    date["ʯש"]="����";
    date["����"]="����";
    date["ľ��"]="����";
    date["ֽ"]="����";

    date["ս��֮��"]="��";
    date["����֮��"]="��";
    date["����֮��"]="��";
    date["����ͼ"]="��";
    date["��ֲ֮��"]="��";
    system("cd.>begin");
    system("start music.exe");
    cout<<"���س����У����Ժ�";
    for(int i=1;i<=5;i++)
    {
        wait(1000);
        cout<<'.';
    }
    system("cls");
    cout<<"����bgm�У����Ժ�";
    for(int i=1;i<=5;i++)
    {
        wait(1000);
        cout<<'.';
    }
    system("cls");
    POINT p;
    while(1)
    { 
        if(ckzt(hwnd)!='b') ShowWindow(hwnd,SW_MAXIMIZE);
        GetCursorPos(&p);
        if(p.x>=1&&p.x<=46&&p.y>=28&&p.y<=43) {YELLOW();if(KEY_DOWN(MOUSE_MOVED)) {Establish();Sigh();break;}}
        cout<<"���û�";
        HUANYUAN();
        cout<<"��";
        if(p.x>=62&&p.x<=117&&p.y>=28&&p.y<=43) {GREEN();if(KEY_DOWN(MOUSE_MOVED)) {Sigh();break;}} 
        cout<<"���û�";
        HUANYUAN();
        system("cls");
    }
    if(Course==0) 
    {
        CYAN();
        say("���죬�����˿��ĵ�һ��\n",100);
        say("�����ڷɻ��ϣ����ص����Լ��ļң�������޶��ž�\n",100);
        say("ͻȻ,һ�����������\n",100);
        say("�㱻������һ��籩֮��\n",100);
        wait(100);
        system("cls");
        say(".....",300);
        wait(100);
        system("cls");
        HUANYUAN();
        cout<<"�㣺��"
        YELLOW();
        say("��...���ģ���...����������",100);
        HUANYUAN();
        cout<<"��";
        wait(100);
        CYAN();
        system("cls"); 
        say("���Ĵ�����\n",100);
        say("��ΧһƬ����������һƬ��½��\n",100);
        wait(100);
        HUANYUAN();
        system("cls");
        cout<<"�㣺��"
        YELLOW();
        say("�ðɣ�ֻ���������ȥ����\n",100);
        HUANYUAN();
        cout<<"��";
        wait(100);
        cout<<"                  �����������ڡ������󡤴���"; 
        wait(1000);
        system("cls");
        Course=1;
    }
    bj=1;
    while(1)
    {
        if(bj==1) 
        {
            Maxfrequency=0;
            frequency=0;
            srand(rand()+rand()+gamesend*gamesend+gamesend+time(0));
            bj=0;
            percentage=rand()%2000+1;
            if(percentage<=50) now="ʯͷ"; else
                if(percentage<=100) now="��ľ"; else
                    if(percentage<=125) now="����"; else
                        if(percentage<=175) now="�ܲ�"; else
                            if(percentage<=225) now="����"; else
                                if(percentage<=275) now="����"; else
                                    if(percentage<=300) Battle(); else
                                        if(percentage<=400) now="С��֦"; else
                                            if(percentage<=500) now="�ɲ�"; else
                                                if(percentage<=525) now="С��ʯ"; else
                                                    if(percentage<=550) now="Сʯ��"; else
                                                        if(percentage<=560) now="��Ĺ"; else
                                                            if(percentage<=600) now="����"; else
                                                                if(percentage<=725) now="ҩ��"; else
                                                                    if(percentage<=775) now="��"; else
                                                                        if(percentage<=800) now="�����"; else
                                                                            if(percentage<=825) now="��ħ��"; else
                                                                                if(percentage<=835) now="����(��ͨ��)"; else
                                                                                    if(percentage<=840) now="����(������)"; else
                                                                                        if(percentage<=845) now="����(������)"; else
                                                                                            if(percentage==846) now="����(������)"; else
                                                                                                if(percentage==847) now="���滨"; else
                                                                                                    if(percentage==846) now="������"; else
                                                                                                        if(percentage==847) now="��������"; else
                                                                                                            if(percentage<=900) now="����"; else
                                                                                                                if(percentage<=910) now="������"; else
                                                                                                                    if(percentage<=920) now="��Ģ��"; else
                                                                                                                        if(percentage<=930) now="��Ģ��"; else
                                                                                                                            if(percentage<=940) now="��Ģ��"; else
                                                                                                                                if(percentage<=941) now="�Ǻ�"; else
                                                                                                                                    if(percentage<=942) now="����"; else
                                                                                                                                        if(percentage<=943) now="����Ƭ"; else
                                                                                                                                            if(percentage<=944) now="����ʯ"; else
                                                                                                                                                if(percentage<=945) now="������������"; else
                                                                                                                                                    cout<<"NULL";
            if(now=="ʯͷ")   {Maxfrequency=7;frequency=Maxfrequency;}
            if(now=="��ľ")   {Maxfrequency=15;frequency=Maxfrequency;}
            if(now=="������������")   {Maxfrequency=15;frequency=Maxfrequency;}
        }   
        GetCursorPos(&p);
        cout<<"��"<<Day<<"��\n";
        cout<<"��ǰ��:";
        if(Maxfrequency>0) cout<<now<<'('<<(int)((frequency*1.0)/Maxfrequency*100)<<"%)\n"; else cout<<now<<endl;
        cout<<endl;
        cout<<"��ѡ��:\n";
        if(p.y>=47&&p.y<=62&&p.x>=1&&p.x<=31) 
        {
            if(power>=5) 
            {
                YELLOW();
                if(KEY_DOWN(MOUSE_MOVED)) 
                {
                    GO();
                    bj=1;
                }
            } else 
            GRAY();
        }
        cout<<"ǰ��";
        HUANYUAN();
        if(p.y>=47&&p.y<=62&&p.x>=32&&p.x<=62) {GREEN();if(KEY_DOWN(MOUSE_MOVED)) {SLEEP();}}
        cout<<"  ��Ϣ";
        HUANYUAN();
        if(p.y>=47&&p.y<=62&&p.x>=63&&p.x<=93) {BLUE();if(KEY_DOWN(MOUSE_MOVED)) {PROP();}}
        cout<<"  ����";
        HUANYUAN();
        if(p.y>=47&&p.y<=62&&p.x>=94&&p.x<=124) 
        {
            if(power>=5) 
            {
                PURPLE();
                if(KEY_DOWN(MOUSE_MOVED)) 
                {
                    Exploitation();
                }
            } else
            GRAY();
        }
        cout<<"  ����";
        HUANYUAN();
        if(p.y>=47&&p.y<=62&&p.x>=125&&p.x<=155) {CYAN();if(KEY_DOWN(MOUSE_MOVED)) {Information();}}
        cout<<"  ��Ϣ";
        HUANYUAN();
        if(p.y>=47&&p.y<=62&&p.x>=156&&p.x<=186) {RED();if(KEY_DOWN(MOUSE_MOVED)) {SET();}}
        cout<<"  ����\n";
        HUANYUAN();
        cout<<"          ��ľ���:"<<power<<'\\'<<MAXpower;
        system("cls");
    }
    return 0;
}
