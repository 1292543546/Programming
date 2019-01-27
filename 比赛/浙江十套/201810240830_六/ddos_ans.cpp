#include<bits/stdc++.h>

using namespace std;

const int INF = 2333333;//ÿ��ЦһЦ��ʮ����23333333333
const int MAXN = 200 + 10;
const int maxWay = 4;//���ķ����������ֱ��һ�¾ͺá���
const int dx[] = {-1, 0, 0, 1};
const int dy[] = {0, -1, 1, 0};

struct Point {
    int x, y;
    int lastWay;
};

queue < Point > q;
Point start, end;//�����յ�
char maze[MAXN][MAXN];//maze���Թ���
int N, step[MAXN][MAXN];

bool check(int x, int y) {
    if ((x < 0) || (x >= N) || (y < 0) || (y >= N) || (maze[x][y] == 'x')) {
        return false;
    }//Խ��||����㲻���� return false��
    return true;
}

void Init() {
    cin >> N;
    getchar();
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> maze[i][j];
            //cin�Զ����Կյ��ַ�
            if (maze[i][j] == 'A') {
            //�ҵ������յ�
                start.x = i; start.y = j;
            }
            if (maze[i][j] == 'B') {
                end.x = i; end.y = j;
            }
            step[i][j] = INF;
    //����㵽��[i][j]��ת���������ΪINF�����޴�
        }
    }
    step[start.x][start.y] = 0;//��㵽���ת0���䡣
}

void Work() {
    q.push(start);
    while (!q.empty()) {
        Point u = q.front();
        q.pop();
        if ((u.x == end.x) && (u.y == end.y)) break;//������굽���յ����꣬���ݹ��ѡ��ȵ��ıض����š�ԭ�򣬿���������������
        Point V;
        for (int i = 0; i < maxWay; ++i) {//�ĸ�����
            V.x = u.x + dx[i]; V.y = u.y + dy[i];
            while (check(V.x, V.y) == true) {

/*
ѧ��˵��һ��Ĺ���������ɢ�����ģ����������Ļ����������˳���û�취��֤����ת������ٵ�ת�������ģ�������һ��while��һ�ΰ��������ߵĵ�ȫ����չ����
*/
            if (step[V.x][V.y]>step[u.x][u.y] + 1) {
                    step[V.x][V.y]=step[u.x][u.y] + 1;
                    //���µ���˵��ת���������
                    q.push(V);
                }
                V.x += dx[i]; V.y += dy[i];//˳�Ŵ˷�������ߣ�������һ�μ�����С�
            }
        }
    }
}

void Print() {
    (step[end.x][end.y] == INF) ? cout << -1 : cout << step[end.x][end.y] - 1;//ѧ��˵����step�����������ͨ�����ֱ���߹�ȥ�ĵ㣬��������ˡ�ת1���䡱����Ϊ������Ĺ����У�whileѭ����һ����չ�㶼��չ�ˣ������Դ������һ�£���Ϊ�˷��㣬ֱ��-1��
}

void debug2()
{
    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++)
            cout<<step[i][j]<<" ";
        cout<<endl;
    }
}

int main() {
    Init();
    Work();
    Print();
//    debug2();
    return 0;
}
