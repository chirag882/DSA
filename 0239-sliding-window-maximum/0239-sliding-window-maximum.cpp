class SegmentTree{
    int n;
    vector<int> tree;
    vector<int> v;
    public:
        void init(int nn,vector<int> &arr){
            n = nn;
            v = arr;
            tree.resize(4*n+5);
        }
        void build(int idx,int l,int r){
            if(l == r){
                tree[idx] = v[l];
                return;
            }
            int mid = (l+r)/2;
            build(idx<<1,l,mid);
            build(idx<<1|1,mid+1,r);
            tree[idx] = max(tree[idx<<1],tree[idx<<1|1]);
        }
        int query(int idx,int l,int r,int ql,int qr){
            if(ql > r || l > qr){
                return -1e9;
            }
            if(ql <= l && r <= qr){
                return tree[idx];
            }
            int mid = (l+r)/2;
            int left = query(idx<<1,l,mid,ql,qr);
            int right = query(idx<<1|1,mid+1,r,ql,qr);
            return max(left,right);
        }
        void print(){
            cout<<tree[1]<<"\n";
        }
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        SegmentTree seg;
        seg.init(n,nums);
        seg.build(1,0,n-1);
        // seg.print();
        vector<int> ans;
        for(int i=k;i<=n;i++){
            int res = seg.query(1,0,n-1,i-k,i-1);
            ans.push_back(res);
        }
        return ans;
    }
};