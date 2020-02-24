//Subset split（Akuna shanghai） 

//Split an array (element is positive) to two subset A B, such that sum of A> sum of B and number of A is minimum. 

//O(n) 

 

#include <iostream> 

#include <vector> 

using namespace std; 

int myPartition(vector<int>& arr, int s, int e, long leftSum, long rightSum){ 

    if(s==e){ 

        return s; 

    } 

    int pivot=arr[e]; 

    int lastSmallOrEqualIdx=s-1; 

    long localLeftSum=0; 

    long localRightSum=0; 

    for(int cur=s;cur<e;cur++){ 

        if(arr[cur]<=pivot){ 

            localLeftSum+=arr[cur]; 

            swap(arr[cur],arr[++lastSmallOrEqualIdx]); 

        }else{ 

            localRightSum+=arr[cur]; 

        } 

    } 

    swap(arr[e],arr[++lastSmallOrEqualIdx]); 

    //localLeftSum+=pivot; 

    if(leftSum+localLeftSum+pivot>=rightSum+localRightSum && leftSum+localLeftSum<rightSum+localRightSum+pivot){ 

        return lastSmallOrEqualIdx; 

    }else if(leftSum+localLeftSum+pivot>=rightSum+localRightSum && leftSum+localLeftSum>=rightSum+localRightSum+pivot){ 

        return myPartition(arr,s,lastSmallOrEqualIdx-1,leftSum,rightSum+localRightSum+pivot); 

    }else{//leftSum+localLeftSum+pivot<rightSum+localRightSum && leftSum+localLeftSum<rightSum+localRightSum+pivot 

        return myPartition(arr,lastSmallOrEqualIdx+1,e,leftSum+localLeftSum+pivot,rightSum); 

    } 

     

     

} 

 
 

vector<int> subsetA(vector<int> arr) { 

    int n=arr.size(); 

    if(n==1){ 

        return vector<int>(1,arr[0]); 

    } 

     

    int firstAIdx=myPartition(arr,0,n-1,0,0); 

    return vector<int>(arr.begin()+firstAIdx,arr.end()); 

} 

 
 

 
 

int main(){ 

    vector<int> v{5,3,2,4,1,2}; 

    auto rlt=subsetA(v); 

    int i=1; 

} 

  
