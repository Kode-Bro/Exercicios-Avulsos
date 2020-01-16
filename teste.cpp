#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define pb push_back
int n, v[60005], x;
int merge_sort(vector<int> &v){
    int inv=0;
    if(v.size()==1){
        return 0;
    }
    vector<int> v1, v2;
    for(int i=0; i<v.size()/2; i++){
        v1.pb(v[i]);
    }
    for(int i=v.size()/2; i<v.size(); i++){
        v2.pb(v[i]);
    }

    inv+=merge_sort(v1);
    inv+=merge_sort(v2);

    v1.pb(INF);
    v2.pb(INF);

    int ini1=0, ini2=0;

    for(int i=0; i<v.size(); i++){
        if(v1[ini1]<=v2[ini2]){
            v[i]=v1[ini1];
            ini1++;
        }else{
            v[i]=v2[ini2];
            ini2++;
            inv+=v1.size()+ini1-1;
        }
    }
    return inv;
}
int main()
{
    cin >> n;
    vector<int> v;
    for(int i=0; i<n; i++){
        cin >> x;
        v.pb(x);
    }
    cout << merge_sort(v) << endl;
    return 0;
}
