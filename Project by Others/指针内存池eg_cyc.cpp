// luogu-judger-enable-o2
// luogu-judger-enable-o2
#include <cstdio>
#include <vector>
using std::vector;

namespace Scapegoat_Tree {
    const int maxn = 100000 + 10;
    const double alpha = 0.75;    //��ת���� 
    struct Node {
        Node* ch[2];              //�����ӽڵ� 
        int key,siz,cover;        //key��ֵ��siz���Ըýڵ�Ϊ�������Ĵ��ڵĽڵ�����cover�����нڵ����� 
        bool exist;               //exist��־�ýڵ��Ƿ�ɾ�� 
        void pushup() {           //���º��� 
            this->siz=ch[0]->siz+ch[1]->siz+(int)exist;
            this->cover=ch[0]->cover+ch[1]->cover+1; 
        }
        int isbad() {             //�ж��Ƿ�Ҫ�ع� 
            return (ch[0]->cover>this->cover*alpha+5)||(ch[1]->cover>this->cover*alpha+5);
        }
    };
    struct STree {
        protected:
            Node mempol[maxn];           //�ڴ�� 
            Node *tail,*null,*root;      //tailΪָ���ڴ��Ԫ�ص�ָ�� 
            Node *bc[maxn];              //�ڴ���ճأ�ջ�� 
            int bc_top;                  //�ڴ���ճأ�ջ����ָ�� 
            
            Node* newnode(int key) {
                Node* p=bc_top?bc[--bc_top]:tail++;
                p->ch[0]=p->ch[1]=null;
                p->cover=p->siz=p->exist=1;
                p->key=key;
                return p;
            }
            
            void travel(Node* p,vector<Node*>& x) {    //��һ����ת�������У�������vector�� 
                if(p==null) return;                    //����ǿ������˳� 
                travel(p->ch[0],x);                    //�ݹ���������� 
                if(p->exist) x.push_back(p);           //����ýڵ��������������� 
                else bc[bc_top++]=p;                   //�����ڴ棬�����õĽڵ��ӵ��ڴ���ճأ�ջ���� 
                travel(p->ch[1],x);                    //�ݹ���������� 
            }
            
            Node* divide(vector<Node*>& x,int l,int r) {    //���ؽ��õ��� 
                if(l>=r) return null;                       //����Ϊ�ղ��ý��� 
                int mid=(l+r)>>1;
                Node* p=x[mid];                             //mid��֤ƽ�� 
                p->ch[0]=divide(x,l,mid);                   //�ݹ���� 
                p->ch[1]=divide(x,mid+1,r);                 //�ݹ���� 
                p->pushup();                                //ά���ڵ���Ϣ 
                return p; 
            }
            
            void rebuild(Node*& p) {
                static vector<Node*> v;
                v.clear();
                travel(p,v);                //�ı� 
                p=divide(v,0,v.size());     //���� 
            }
            
            Node** insert(Node*& p,int val) {                     //����ָ�������ڵ������һ�ò�ƽ���������ָ�� 
                if(p==null) {
                    p=newnode(val);
                    return &null;
                } else {
                    p->siz++,p->cover++;                          //ά���ڵ��� 
                    Node** res=insert(p->ch[val>=p->key],val);
                    if(p->isbad()) res=&p;
                    return res;
                }
            }
            
            void erase(Node*& p,int k) {
                p->siz--;                               //ά��siz 
                int offset=p->ch[0]->siz+p->exist;      //�����������Ĵ��ڵĽڵ����� 
                if(p->exist&&k==offset) {               //�жϵ�ǰ�ڵ�Ȩֵ�Ƿ��kС 
                    p->exist=false;                     //ɾ���ڵ� 
                } else {
                    if(k<=offset) erase(p->ch[0],k);    //���kС�ڵ���offset���ݹ���������� 
                    else erase(p->ch[1],k-offset);      //��֮�ݹ���������� 
                }
            }
            
            void iod(Node* p) {
                if(p!=null) {
                    iod(p->ch[0]);
                    printf("%d ",p->key);
                    iod(p->ch[1]);
                }
            }
        public:
            void init() {
                tail=mempol;                         //tailָ���ڴ�صĵ�һ��Ԫ�� 
                null=tail++;                         //Ϊnullָ������ڴ� 
                null->ch[0]=null->ch[1]=null;        //null����������Ҳ��null 
                null->cover=null->siz=null->key=0;   //null�����б�Ƕ���0 
                root=null;                           //��ʼ�����ڵ� 
                bc_top=0;                            //���ջ 
            }
            
            STree() {
                init();
            }
            
            void insert(int val) {
                Node** res=insert(root,val);
                if(*res!=null) rebuild(*res);
            }
            
            int rank(int val) {
                Node* now=root;
                int ans=1;
                while(now!=null) {
                    if(now->key>=val) now=now->ch[0];
                    else {
                        ans+=now->ch[0]->siz+now->exist;
                        now=now->ch[1]; 
                    }
                }
                return ans;
            }
            
            int kth(int val) {
                Node* now=root;
                while(now!=null) {
                    if(now->ch[0]->siz+1==val&&now->exist) return now->key;
                    else if(now->ch[0]->siz>=val) now=now->ch[0];
                    else val-=now->ch[0]->siz+now->exist,now=now->ch[1];
                }
            }
            
            void erase(int k) {              //ɾ��ֵΪk��Ԫ�� 
                erase(root,rank(k));
                if(root->siz<root->cover*alpha) rebuild(root);
            }
            
            void erase_kth(int k) {          //ɾ����kС 
                erase(root,k);
                if(root->siz<root->cover*alpha) rebuild(root);
            }
            
            void iod() {                     //�����õ�������� 
                Node* p=root;
                iod(p);
            }
    };
}


template <class T> inline void read(T &x) {
    x = 0; int ch, f = 0;
    for (ch = getchar(); ch < '0' || ch > '9'; ch = getchar()) if (ch == '-') f = 1;
    for (; ch >= '0' && ch <= '9'; ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
    if (f) x = -x;
}

using namespace Scapegoat_Tree;
STree st; 
int main() {
    int n, opt, que;
    read(n);
    while(n--) {
        read(opt), read(que);
        if(opt==1) st.insert(que);
        if(opt==2) st.erase(que);
        if(opt==3) printf("%d\n",st.rank(que));
        if(opt==4) printf("%d\n",st.kth(que));
        if(opt==5) printf("%d\n",st.kth(st.rank(que)-1));
        if(opt==6) printf("%d\n",st.kth(st.rank(que+1)));
        if(opt==7) st.iod();
    }
    return 0;
}
