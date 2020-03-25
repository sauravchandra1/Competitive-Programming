class SegmentTree {
	vector<int> tree;
public:
	SegmentTree(int n) : tree(4 * n, 0) {}
	void build (vector<int> arr, int l, int r, int pos) {
		if (l > r) {
			return;
		}
		if (l == r) {
			tree[pos] = arr[l];
		}
		else {
			int mid = l + (r - l) / 2;
			build(arr, l, mid, 2 * pos + 1);
			build(arr, mid + 1, r, 2 * pos + 2);
			tree[pos] = max(tree[2 * pos + 1], tree[2 * pos + 2]);
		}
	}
	void update (int newVal, int L, int R, int l, int r, int pos) {
		if (L < l || R > r)
			return;
		if (l == r) {
			tree[pos] = newVal;
			return;
		}
		int mid = l + (r - l) / 2;
		update(newVal, L, R, l, mid, 2 * pos + 1);
		update(newVal, L, R, mid + 1, r, 2 * pos + 2);
		tree[pos] = max(tree[2 * pos + 1], tree[2 * pos + 2]);
	}
	int query (int L, int R, int l, int r, int pos) {
		if (l > R || r < L)
			return INT_MIN;
		else if (l >= L && r <= R)
			return tree[pos];
		else {
			int mid = l + (r - l) / 2;
			int leftAns = query(L, R, l, mid, 2 * pos + 1);
			int rightAns = query(L, R, mid + 1, r, 2 * pos + 2);
			int ans = max(leftAns, rightAns);
			return ans;
		}
	}
};
