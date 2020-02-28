//how to proof evaluation of prefix/postfix is equal to the responding infix(induction)
#include <iostream>
#include<string>
#include<stack>
using namespace std;

bool isOp(char c){
    switch (c) {
        case '+':
        case '-':
        case '*':
        case '/':
            return true;
            
        default:
            return false;
    }
}

string preToPost(string s){
    //assume it iis valid
    int n=s.size();
    if(n<=1){
        return s;
    }
    int count=0;
    stack<pair<char,int>> oprs;
    stack<string> opds;
    for(int i=0;i<n;i++){
        if(isOp(s[i])){
            oprs.push({s[i],0});
        }else{
            opds.push(string(1,s[i]));
            oprs.top().second++;
            while(oprs.size()&&oprs.top().second==2){
                auto secondOpd=opds.top();
                opds.pop();
                opds.top().append(secondOpd).push_back(oprs.top().first);
                oprs.pop();
                //virtual adding of in-place opds for top oprs
                if(oprs.size()){
                    oprs.top().second++;
                }
            }
        }
    }
    return opds.top();
}
int main() {
  string pre_exp = "*-A/BC-/AKL";
  cout << "Postfix : " << preToPost(pre_exp);
  return 0;
} 

