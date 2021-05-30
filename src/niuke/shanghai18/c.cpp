#include<stdio.h>
int binaryFind(int a[],int low,int high,int target){
    int mid=(low+high)/2;
    if(a[mid]>=target && a[mid-1]<target){
        return mid;
    }else if(a[mid]>target){
        high=mid-1;
        return binaryFind(a,low,high,target);
    }else{
        low=mid+1;
        return binaryFind(a,low,high,target);
    }
    if(low>high)
        return -1;
}
void computePreSum(int a[],int length,int sum[]){
    for(int i=0;i<length;i++){
        for(int j=0;j<=i;j++){
            sum[i]=a[j]+sum[i];
        }
    }

}
int needNum(int x,int sum[],int n,int t){
    //返回将中位数增加到x，所需要的糖果数
    int r=(t-n/2+1)*x-(sum[t]-sum[n/2-1]) ;
    return r;
}
int main(){
    int a[7]={1,2,3,4,6,7,8};
    //int result=binaryFind(a,0,5,5);
    int n=7;
    int sum[5]={0};
    int m=3;//糖果的总数
    int result;
    computePreSum(a,7,sum);//计算数组a的前缀和，存储在sum数组中
    int midNum=a[n/2];
    int x=midNum;
    result=binaryFind(a,0,6,x);
    while(needNum(x,sum,n,result)<=m){
        x++;
        result=binaryFind(a,0,6,x);
    }
    printf("%d",x-1);
}