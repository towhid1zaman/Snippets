//https://leetcode.com/problems/range-sum-query-mutable/

class NumArray {
public:

    struct FenwickTree{
    int N;
    vector<int> tree;
 
    void build(int n){
        N = n;
        tree.assign(n + 1, 0);
    }

    void update(int idx, int val){
        while (idx <= N)
        {
            tree[idx] += val;
            idx += idx & -idx;
        }
    }

    void updateMax(int idx, int val){
        while (idx <= N)
        {
            tree[idx] = max(tree[idx], val);
            idx += idx & -idx;
        }
    }
     //mainly Query
    int pref(int idx){
        int ans = 0;
        while (idx > 0){
            ans += tree[idx];
            idx -= idx & -idx;
        }
        return ans;
    }
     //range sum
    int rsum(int l, int r){
        return pref(r+1) - pref(l);
    }

    int prefMax(int idx){
        int ans = -2e9;
        while (idx > 0){
            ans = max(ans, tree[idx]);
            idx -= idx & -idx;
        }
        return ans;
    }

    int search(int val){
        int curSum=0,pos=0;
        for(int i = log2(N)+1;i>=0;i--){
            if(pos + (1<<i) < N && curSum + tree[ pos+(1<<i) ] < val){
                curSum += tree[pos+(1<<i)];
                pos += (1<<i);
            }
        }
        return pos+1;
    }
};
    
    FenwickTree BIT;
    vector<int>nums;
    NumArray(vector<int>& nums) {
        this->nums = nums;
        int n = (int)nums.size();
        BIT.build(n);
        for(int i = 1; i<=n; i++){
            BIT.update(i, nums[i-1]);
        }
    }
    
    void update(int index, int val) {
        int diff = val - nums[index]; // get diff amount of `val` compared to current value
        BIT.update(index + 1, diff); // add this `diff` amount at index `index+1` of BIT, plus 1 because in BIT it's 1-based indexing
        nums[index] = val; // update latest value of `nums[index]`
    }
    
    int sumRange(int left, int right) {
        return BIT.rsum(left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
