    #include<iostream>  
    using namespace std;  
      
    //Ԥ�ȶ����ֵ�ڵ�ĸ���Ϊ1000�������ݿ���̨����ĸ���num�Ӷ�ȷ����ֵ�ڵ�ĸ���  
    const int N=1000;  
      
    //arrX[N],arrY[N]�ֱ��ŵ��ǲ�ֵ�ڵ�(Xi,Yi)�е�Xi,Yi,����nΪ��ֵ�ڵ�ĸ���,������xΪ�����Ĳ�ֵ�ڵ��Xֵ  
    //��������ֵΪ�������Ĳ�ֵ�ڵ�X��Ӧ��Yֵ  
    //ע�����������漰�ı���������ѭ������Ϊint�⣬������Ϊfloat  
    float Lagrange(float arrX[],float arrY[],int n,float x)  
    {  
        float yResult=0.0;  
          
        //LValue[N]��ŵ���ÿ�����Ĳ�ֵ��������ͨ��  
        float LValue[N];  
      
        //ѭ������k,m  
        int k,m;  
        //��ֵ�������е������۳�temp1,temp2  
        float temp1,temp2;  
      
        for(k=0;k<n;k++)  
        {  
            temp1=1.0;  
            temp2=1.0;  
            for(m=0;m<n;m++)  
            {  
                if(m==k)  
                {  
                    continue;  
                }  
                temp1 *= (x-arrX[m]);     
                temp2 *= (arrX[k]-arrX[m]);  
            }  
      
            LValue[k]=temp1/temp2;  
      
        }  
      
        for(int i=0;i<n;i++)  
        {  
            yResult += arrY[i]*LValue[i];  
        }  
          
        return yResult;  
    }  
      
    int main()  
    {  
        float arrX[N],arrY[N];  
        int num;  
             cout<<"�����ֵ�ڵ�ĸ���(С��"<<N<<"��): ";  
        cin>>num;  
      
        cout<<"\n--������������Щ��ֵ�ڵ�(������X �������Ӧ��Y)--\n";  
        for(int i=0;i<num;i++)  
        {  
            cout<<"��"<<i+1<<"���ڵ��Xֵ: ";  
            cin>>arrX[i];  
            cout<<"��"<<i+1<<"���ڵ��Yֵ: ";  
            cin>>arrY[i];  
        }  
      
      
        float X;  
        cout<<"\n--����������Ĳ�ֵ�ڵ��Xֵ--\n";  
        cin>>X;  
      
             float Res = Lagrange(arrX,arrY,num,X);  
        cout<<"\n--��ֵ���Ϊ: "<<Res<<endl;  
      
        return 0;  
    }