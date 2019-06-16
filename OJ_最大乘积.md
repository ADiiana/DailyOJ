~~~C


#include<iostream>
#include<algorithm>
using namespace std;
 
const int maxn = 1e6;
long long arr[maxn];
 
int main(){
    int n;
    long long maxi[3], mini[3], ans;
    cin>>n;
    for(int i = 0; i < n; i++) scanf("%lld", &arr[i]);
    for(int i = 0; i < 3; i++){
        for(int j = i + 1; j < n; j++) if(arr[j] > arr[i]) swap(arr[j], arr[i]);
        maxi[i] = arr[i];
    }
    for(int i = 0; i < 3; i++){
        for(int j = i + 1; j < n; j++) if(arr[j] < arr[i]) swap(arr[j], arr[i]);
        mini[i] = arr[i];
    }
    ans = max(maxi[0]*maxi[1]*maxi[2],
              max(maxi[0]*mini[0]*mini[1], mini[0]*mini[1]*mini[2]));
    printf("%lld\n", ans);
}
~~~

