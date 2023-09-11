#include <iostream>
#include <vector>
using namespace std;
class SGT {
public:
    vector<int>segmentTree,arr;
    int n;
    SGT(vector<int>&nums){
        n = nums.size();
        arr = nums;
        segmentTree.resize(4*n);
        build(0,0,n-1);
    }
    void build(int ind,int low,int hi){
        if(low==hi){
            segmentTree[ind] = arr[low];
            return;
        }
        int mid = (low+hi)/2;
        build(2*ind+1,low,mid);
        build(2*ind+2,mid+1,hi);
        segmentTree[ind] = segmentTree[2*ind+1] + segmentTree[2*ind+2];
    }
    int query(int low,int hi,int left,int right,int ind){
        if(low>=left && hi<=right){
            return segmentTree[ind];
        }
        if(left>hi || right<low) return 0;
        int mid = (low+hi)/2;
        int leftSum = findSum(low,mid,left,right,2*ind+1);
        int rightSum = findSum(mid+1,hi,left,right,2*ind+2);
        return leftSum + rightSum;
    }
    void updateSegTree(int low,int hi,int change,int ind,int index){
        if(low>=index && hi<=index){
            segmentTree[ind] += change;
            return;
        }
        if(index>hi || index<low) return ;
        int mid = (low+hi)/2;
        updateSegTree(low,mid,change,2*ind+1,index);
        updateSegTree(mid+1,hi,change,2*ind+2,index);
        segmentTree[ind] = segmentTree[2*ind+1] + segmentTree[2*ind+2];
    }
};
