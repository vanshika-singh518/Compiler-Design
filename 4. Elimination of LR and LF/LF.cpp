#include <bits/stdc++.h>
using namespace std;

int main(){
    vector <string> ans;
    int n;
    cin >> n;
    while(n--){
    string str,mn="",tmp="",cm="";
    cin >> str;
    int n = str.size();
    vector <string> tmprules,t1,t2;
    for(int i=0;i<=n;i++){
        if(i == n){
            tmprules.push_back(tmp);
            bool tu = false;
            for(int j=0;j<tmprules.size()-1;j++){
                string tmp1 = tmprules[j];
                for(int k=j+1;k<tmprules.size();k++){
                    string tmp2 = tmprules[k];
                    // cout << tmp1 << " " << tmp2 << endl;
                    if(tmp1[0] == tmp2[0]){
                        cm = tmp1;
                        tu = true;
                        break;
                    }
                }
            }
            if(tu){
                for(auto &it:tmprules){
                    if(it[0] == cm[0])
                        t1.push_back(it.substr(1));
                    else
                        t2.push_back(it);
                }
                string anstmp = "";
                anstmp += mn;
                anstmp += "->";
                anstmp += cm[0];
                anstmp += str[0];
                anstmp += "'";
                for(int m=0;m<t2.size();m++){
                    anstmp += "|";
                    anstmp += t2[m];
                }
                ans.push_back(anstmp);
                anstmp = "";
                anstmp += str[0];
                anstmp += "'";
                anstmp += "->";
                for(int m=0;m<t1.size();m++){
                    anstmp += t1[m]; 
                    if(m < t1.size()-1){
                        anstmp += "|";
                    }
                }
                ans.push_back(anstmp);
            }
            else{
                ans.push_back(str);
            }
        }
        else if(str[i] == ' '){
            continue;
        }
        else if(str[i] == '-' && str[i+1] == '>'){
            mn = tmp;
            i++;
        }
        else if(str[i] == '|'){
            tmprules.push_back(tmp);
        }
        else{
            tmp += str[i];
            continue;
        }
        tmp = "";
    }
    }
    cout << endl;
    for(auto &it:ans)
        cout << it << endl;
    return 0;
}

// 3
// S->Aa|Ab|Ac|z
// S->Aa|Ab
// S->a
