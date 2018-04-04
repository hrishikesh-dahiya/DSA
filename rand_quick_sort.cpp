#include <iostream>

using namespace std;

int count = 0;

int partition(int a[], int p, int r)
{
    int x = a[r];
    int i = p - 1;
    for(int j=p;j<r;j++){
        if(a[j] <= x){
            i++;
            swap(a[i], a[j]);
            cout << "swapping a[" << i << "] with a[" << j << "]" << endl;
            count ++;
        }
    }
    swap(a[i+1], a[r]);
    cout << "swapping a[" << i+1 << "] with a[" << r << "]" << endl;
    count++;
    return i+1;
}

int rand_pratition(int a[], int p, int r)
{
    int i = rand() % (r - p) + p;
    swap(a[r], a[i]);
    return partition(a, p, r);
}

void quick_sort(int a[], int p, int r)
{
    if(p < r){
        int q = rand_pratition(a, p, r);
        quick_sort(a, p, q-1);
        quick_sort(a, q+1, r);
    }
}

int main()
{
    int n;

    cin >> n;

    int a[n+1];

    for(int i=1;i<=n;i++){
        cin >> a[i];
    }

    for(int i=1;i<=n;i++){
        cout << a[i] << " ";
    }
    cout << endl;

    quick_sort(a, 1, n);

    for(int i=1;i<=n;i++){
        cout << a[i] << " ";
    }
    cout << endl;

    cout << "Count = " << count << endl;
}
