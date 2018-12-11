#include <iostream>
#define N 9
using namespace std;

char ch[] = "0123456789";
int func(int n) {
    int i,j;
    char temp;
    if(n==0) {
        for(j=N-1;j>=0;j--)
            cout<<ch[j];
        cout<<endl;
        return 0;
    }
    for(i=0;i<n;i++){
        temp = ch[i];
        for(j=i+1;j<n;j++)
            ch[j-1] = ch[j];
        ch[n-1] = temp;
        //shift
        func(n-1);
        for(j=n-1;j>i;j--)
            ch[j] = ch[j-1];
        ch[i] = temp;
        //and shift back agian
    }
    return 1;
}

int main(void)
{
    func(N);
    return 0;
}