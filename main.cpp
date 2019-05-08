#include <iostream>
#include<fstream>
#include<time.h>
#include<stdlib.h>
#define MAXNUM 1000

using namespace std;

int select(int a[],int len,int k);
int bubble_sort(int a[],int len,int k);

int main()
{
    srand((unsigned int)time (NULL));
    ofstream op("E:\\DAA\\test2.txt");
    for(int i=0;i<MAXNUM;i++){
        op<<rand()%500<<"\n";
    }
    op.close();
    int len;
    int k;
    cout<<"**********求数组第K小元素问题**********"<<endl<<endl;
    cout<<"请输入数组的长度：";
    cin>>len;
    cout<<"请输入K的值：";
    cin>>k;
    int a[len];
    ifstream fp("E:\\DAA\\test2.txt");
    for(int i=0;i<len;i++){
        fp>>a[i];
    }
    fp.close();

    int result;
    result=select(a,len,k);
    cout<<"该数组第"<<k<<"小元素为："<<result<<endl;
    if(len<=30){
        cout<<"数组元素为："<<endl;
        for(int i=0;i<len;i++){
            cout<<a[i]<<"  ";
        }
    }
}


int select(int a[],int len,int k){
    int sub_len=len/5;
    int result;
    if(len<5){
        result=bubble_sort(a,len,k);
        return result;
    }
    int b[5];
    int median[sub_len];
    for(int i=0;i<sub_len;i++){
        for(int j=0;j<5;j++){
            b[j]=a[i*5+j];
        }
        median[i]=bubble_sort(b,5,3);
    }
    int x;
    int s1[len],s2[len];
    int s1_num=0,s2_num=0;
    x=select(median,sub_len,sub_len/2+1);  //这里加1为了避免sub_len=1时sub_len/2=0,出bug
    for(int i=0;i<len;i++){
        if(a[i]<=x){
            s1[s1_num]=a[i];
            s1_num++;
        }
        else{
            s2[s2_num]=a[i];
            s2_num++;
        }
    }
    if(k==s1_num+1)
        result=x;
    else if(k<=s1_num)
        result=select(s1,s1_num,k);
    else
        result=select(s2,s2_num,k-s1_num);
    return result;
}

int bubble_sort(int a[],int len,int k){
    int t;
    for(int i=0;i<len-1;i++){
        for(int j=0;j<len-i-1;j++){
            if(a[j]>a[j+1]){
                t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
        }
    }
    return a[k-1];
}

