#include <iostream>

using namespace std;

int fact(int n)
{
    if(n < 2){
        return 1;
    } else {
        return n * fact(n-1);
    }
}

int perm(int *arr, int ln)
{
    if(ln < 2){
        return 1;
    }
    else {
        int k=0,t=0;
        int a1[100], a2[100];

        for(int i=1;i<ln;i++){
            if(arr[0] > arr[i]){
                a1[k++] = arr[i];
            } else {
                a2[t++] = arr[i];
            }
        }
        return (fact(ln-1)/(fact(k)*fact(t))) * perm(a1, k) * perm(a2, t);
    }
}


int main()
{
    int n, m;
    cin >> n;
    m = n;

    int a[n];

    while(m--){
        cin >> a[n-m-1];
    }
    int ln = sizeof(a)/sizeof(a[0]);

    cout << perm(a, ln) << endl;
}
