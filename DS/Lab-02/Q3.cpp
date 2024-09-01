#include<iostream>
using namespace std;

bool commonFriend(bool arr[][5],int p1, int p2){
    
    for(int i=0; i<5; i++) if(arr[p1][i] && arr[p2][i]) return true;
    return false;
}

int main(){
    
    bool commonFriends[5][5] = {
        {false,true,false,true,true},
        {true,false,true,false,true},
        {false,true,false,false,false},
        {true,false,false,false,true},
        {true,true,false,true,false},
    };
    
    int p1, p2;
    cout<<"Enter the first person (0-4): "; cin>>p1;
    cout<<"Enter the second person (0-4): "; cin>>p2;

    if(commonFriend(commonFriends,p1,p2)) cout<<"Thay have common friends";
    else cout<<"They have no common friends";
    
}
