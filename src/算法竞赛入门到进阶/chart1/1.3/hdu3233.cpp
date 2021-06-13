#include<iostream>
#include <iomanip>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cout << setprecision(2) << 3.1415 << endl;
    printf("%.2f",3.1415);
    int T , n, cnt = 1, B;
    while(cin >> T >> n>> B){
        if (T == 0 || n == 0 || B == 0) break;
        double s , p , sum = 0;
        while(T--){
            cin >> s >> p;
            sum += s * (100 - p) * 0.01;
        }
        cout << "Case "<< cnt++ << ": " << fixed << setprecision(2) << sum / (B * 1.0) << endl << endl;
        //浮点值可以四舍五入到若干位有效数或精度，这是出现在小数点前后的总位数。
        //可以通过使用 setprecision 操作符来控制显示浮点数值的有效数的数量。
    }
    return 0;
}