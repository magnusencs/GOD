#include <iostream>
using namepsace std;

int main() {
    int n;
    cin>>n;
    
    if ( n % 2 == 0 ) {
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=i;j++) {
                cout<<"*";
            }
            cout<<endl;
        }
    } else {
        for(int i=1;i<=n;i++) {
            for(int j=n;j>=i;j--) {
                cout<<"*";
            }
            cout<<endl;
        }
    }
    
    return 0;
}