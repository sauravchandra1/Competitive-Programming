
class SegmentTree {
	vector < int > tree;
public:
	SegmentTree(int n): tree(n, 0) {}
	void build(vector < int > arr, int l, int r, int id) {
		if (l > r)
			return;
		if (l == r)
			tree[id] = arr[l];
		else {
			int mid = l + (r - l) / 2;
			build(arr, l, mid, id * 2 + 1);
			build(arr, mid + 1, r, id * 2 + 2);
			tree[id] = max(tree[id * 2 + 1], tree[id * 2 + 2]);
		}
	}
	void pointUpdate(int newVal, int p, int l, int r, int id) {
		if (p < l || p > r)
			return;
		if (l == r) {
			tree[id] = newVal;
			return;
		}
		int mid = l + (r - l) / 2;
		if (p <= mid)
			pointUpdate(newVal, p, l, mid, id * 2 + 1);
		else 
			pointUpdate(newVal, p, mid + 1, r, id * 2 + 2);
		tree[id] = max(tree[id * 2 + 1], tree[id * 2 + 2]);
	}
	int query(int L, int R, int l, int r, int id) {
		if (l > R || r < L)
			return INT_MIN;
		else if (l >= L && r <= R)
			return tree[id];
		else {
			int mid = l + (r - l) / 2;
			int leftAns = query(L, R, l, mid, id * 2 + 1);
			int rightAns = query(L, R, mid + 1, r, id * 2 + 2);
			int ans = max(leftAns, rightAns);
			return ans;
		}
	}
};
