#include <iostream>

using namespace std;

int whichHeap(int a[], int n)
{
    int ans = 0;
    if((a[1] < a[2]) && (a[1] < a[3])){
        for(int i=2;i<=n/2;i++){
            if(((a[i] < a[2*i]) && (a[i] < a[2*i+1])) || 2*i+1 > n){
                ans = 1;
            } else {
                ans = 0;
                break;
            }
        }
    }
    if((a[1] > a[2]) && (a[1] > a[3])){
        for(int i=2;i<=n/2;i++){
            if(((a[i] > a[2*i]) && (a[i] > a[2*i+1])) || 2*i+1 > n){
                ans = 2;
            } else {
                ans = 0;
                break;
            }
        }
    }
    return ans;
}


int main()
{
    int n, ans;

    cin >> n;

    int a[n+1];

    for(int i=1;i<=n;i++){
        cin >> a[i];
    }

    ans = whichHeap(a, n);

    if(ans == 0){
        cout << "NONE";
    } else if(ans == 1){
        cout << "MINHEAP";
    } else {
        cout << "MAXHEAP";
    }
    cout << endl;
    return 0;
}
