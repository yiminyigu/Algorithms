#include <iostream>
#include <vector>
using namespace std;
//when problem like count inversion, the base arr in BIT becomes the count of value in original array(converted), considering the duplicate, some may more than 1 some may be 0, but the total sum is n
//for update, we cannot use newVal because we do not have stat vector to know the current(old) value
class BIT{
private:
    vector<int> partialSum;
public:
    BIT(vector<int>& arr):partialSum(arr.size()+1,0){
        for(int i=0;i<arr.size();i++){
            update(i,arr[i]);
        }
    }
    
    void update(int originIdx, int diff){
        int psn=partialSum.size();
        int bitIdx=originIdx+1;
        while(bitIdx<psn){
            partialSum[bitIdx]+=diff;
            bitIdx+=(bitIdx&(~bitIdx+1));
            
        }
        
    }
    
    int getSum(int originLastIdx){
        int bitIdx=originLastIdx+1;
        int sum=0;
        while(bitIdx>0){
            sum+=partialSum[bitIdx];
            
            bitIdx-=(bitIdx&(~bitIdx+1));
        }
        return sum;
    }
    

};

int getInvCount(vector<int>& arr){
    int n=arr.size();
    if(n<2){
        return 0;
    }
    vector<int> forConvert(arr);

    sort(forConvert.begin(),forConvert.end());
    for(int i=0;i<n;i++){
        arr[i]=lower_bound(forConvert.begin(), forConvert.end(), arr[i])-forConvert.begin();//0 based
    }
    
    vector<int> dummy(n,0);
    BIT bit(dummy);
    int rlt=0;
    for(int i=n-1;i>=0;i--){
        if(arr[i]>0){//because of 0-based
            rlt+=bit.getSum(arr[i]-1);
        }
        bit.update(arr[i], 1);
    }
    return rlt;
    
    
}


int main()
{
    vector<int> freq{8, 4, 2, 1};
    
    cout << "Number of inversions are : " << getInvCount(freq)<<endl;
  
  
    return 0;
}

