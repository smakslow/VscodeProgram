
int a[];
//单调递增序列a中查找>=x的数中最小的一个
int lowerSearch(int l,int r,int x){
    int mid = l + (r - l) / 2;
    if(a[mid] >= x){
        l = mid;
    }else{
        r = mid - 1;
    }
    return a[l];
}

//单调递增数列中查找<=x的数中最大的一个

int upperSearch(int l,int r,int x){
    int mid = l + (r - l) / 2;
    if(a[mid] <= x){
        l = mid;
    }else{
        r  = mid - 1;
    }
    return a[l];
}

int main(){

    return 0;
}