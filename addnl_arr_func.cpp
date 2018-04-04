#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

void print_array(int a[], int length_a){

    cout<<"[";
    for(int i=0;i<length_a;i++){
        cout<<a[i]<<", ";
    }
    cout<<"]\n\n";
}

int main(){

    int a[] = {1, 2, 3, 5, 6, -4};
    int c[6];

    all_of(a, a + 6, [](int x) { return x>0; })?
        cout<<"All are positive numbers.":
        cout<<"Not all are positive numbers.";

    cout<<endl<<endl;

    any_of(a, a + 6, [](int x) { return x<0; })?
        cout<<"There exists a negative element":
        cout<<"No negative element";

    cout<<endl<<endl;

    none_of(a, a + 6, [](int x) { return x<0; })?
        cout<<"All are positive elements":
        cout<<"There are some negative elements";

    cout<<endl<<endl;

    copy_n(a, 6, c);

    print_array(c, 6);

    iota(a, a+6, 20);

    print_array(a, 6);
   
}