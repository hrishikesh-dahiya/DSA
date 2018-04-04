#include <iostream>

using namespace std;

int main() {
    int n, size, count = 0;
    char type, junk;
    int a[101];

    for(int i=1;i<101;i++){
        a[i] = 0;
    }

    cin >> n;

    while(n--){
        cin >> size;
        cin >> junk;
        cin >> type;
        cout << size << endl;
        cout << type << endl;
        if(type == 'L'){
            a[size] += 2;
        }
        if(type == 'R'){
            a[size] -= 1;
        }
    }

    for(int i=0;i<101;i++){
        if(a[i] == 1){
            count ++;
        }
    }

    cout << count;
    return 0;
}
