//#include <iostream>
#include <bits/stdc++.h>
#include<ctype.h>
using namespace std;


stack <char> s1;
stack <char> s2;
stack <char> s3;
int n;

void showstacks(stack <char> ss1, stack <char> ss2, stack <char> ss3){
    while (!ss1.empty())
    {
        cout <<ss1.top()<<"\t"<<ss2.top()<<"\t"<<ss3.top();
        ss1.pop();
        ss2.pop();
        ss3.pop();
        cout<<"\n";
    }
}


void normalize(){
    //stack 1
    int i;
    for(i = s1.size(); i<n;i++){
        s1.push(' ');
    }
    //stack 2
    for(i = s2.size(); i<n;i++){
        s2.push(' ');
    }
    //stack 3
    for(i = s3.size(); i<n;i++){
        s3.push(' ');
    }
}

void un_normalize(){
    //stack 1
    while(s1.top()==' '){
        s1.pop();
        if(s1.size()==0)
            break;
    }
    //stack 2
    while(s2.top()==' '){
        s2.pop();
        if(s2.size()==0)
            break;
    }
    //stack 3
    while(s3.top()==' '){
        s3.pop();
        if(s3.size()==0)
            break;
    }

}


void shows(){
    normalize();
    cout<<"Rod 1\tRod 2\tRod 3\n";
    showstacks(s1, s2, s3);

    un_normalize();


}



void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod)
{
    char temp;
    if (n == 1)
    {

        switch (from_rod){
            case '1': if(to_rod == '2'){
                        temp = s1.top();
                        s1.pop();
                        s2.push(temp);
                    }
                    if(to_rod == '3'){
                        temp = s1.top();
                        s1.pop();
                        s3.push(temp);
                    }
                    break;
            case '2': if(to_rod == '1'){
                        temp = s2.top();
                        s2.pop();
                        s1.push(temp);
                    }
                    if(to_rod == '3'){
                        temp = s2.top();
                        s2.pop();
                        s3.push(temp);
                    }
                    break;
            case '3': if(to_rod == '1'){
                        temp = s3.top();
                        s3.pop();
                        s1.push(temp);
                    }
                    if(to_rod == '2'){
                        temp = s3.top();
                        s3.pop();
                        s2.push(temp);
                    }
                    break;
        }
        shows();
        return;
    }


    towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);

    switch (from_rod){
        case '1': if(to_rod == '2'){
                    temp = s1.top();
                    s1.pop();
                    s2.push(temp);
                }
                if(to_rod == '3'){
                    temp = s1.top();
                    s1.pop();
                    s3.push(temp);
                }
                break;
        case '2': if(to_rod == '1'){
                    temp = s2.top();
                    s2.pop();
                    s1.push(temp);
                }
                if(to_rod == '3'){
                    temp = s2.top();
                    s2.pop();
                    s3.push(temp);
                }
                break;
        case '3': if(to_rod == '1'){
                    temp = s3.top();
                    s3.pop();
                    s1.push(temp);
                }
                if(to_rod == '2'){
                    temp = s3.top();
                    s3.pop();
                    s2.push(temp);
                }
                break;
    }
    shows();
    towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
}

int main()
{

    cout<<"enter number of disks: ";
    cin>>n;
    char a = '1';
    for(int i = 1; i<=n; i++){
        s1.push(a++);

    }
    shows();
    //cout<<"qwer";
    towerOfHanoi(n, '1', '3', '2');
    return 0;
}
