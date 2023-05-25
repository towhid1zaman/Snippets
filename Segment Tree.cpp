//checked on https://lightoj.com/problem/horrible-queries


#include<bits/stdc++.h>
using namespace std;
#define MAXN 100005
#define int long long //check long long

int nums[MAXN];
int tree[4*MAXN];
int lazy[4*MAXN];

// 0 indexed segment tree
int left(int node) { return 2 * node + 1; }
int right(int node) { return 2 * node + 2; }
int half(int left, int right) { return left + (right - left) / 2; }

// call reset for every test cases
void reset() {
	memset(nums, 0, sizeof nums);
	memset(tree, 0, sizeof tree);
	memset(lazy, 0, sizeof lazy);
}

void build(int node, int b, int e) {
	if (b > e)return;
	if (b == e) {
		tree[node] = nums[b];
		return;
	}
	int mid = half(b, e);
	build(left(node), b, mid);
	build(right(node), mid + 1, e);
	tree[node] = tree[left(node)] + tree[right(node)];
}

void updatePoint(int node, int b, int e, int pos, int newVal) {
	if (b == e) {
		tree[node] = newVal;
		return;
	}
	int mid = half(b, e);
	if (pos <= mid)updatePoint(left(node), b, mid, pos, newVal);
	else updatePoint(right(node), mid + 1, e, pos, newVal);
	tree[node] = tree[left(node)] + tree[right(node)];
}

void propagate(int node, int b, int e) { // clear previous calculations
	if (lazy[node] > 0) {
		tree[node] += (e - b + 1) * lazy[node];

		if (b != e) {
			lazy[left(node)] += lazy[node];
			lazy[right(node)] += lazy[node];
		}
		lazy[node] = 0;
	}
}

void updateRange(int node, int b, int e, int l, int r, int newVal) {
	propagate(node, b, e);
	if (e < l || b > r || b > e)return;
	if (l <= b && e <= r) {
		lazy[node] += newVal;
		propagate(node, b, e);
		return;
	}
	int mid = half(b, e);
	updateRange(left(node), b, mid, l, r, newVal);
	updateRange(right(node), mid + 1, e, l, r, newVal);
	tree[node] = tree[left(node)] + tree[right(node)];
}

int queryRange(int node, int b, int e, int l, int r) { // for point query, just sent l and r value same
	propagate(node, b, e); // for range update query

	if (e < l || b > r || b > e)return 0;
	if (l <= b && e <= r) {
		return tree[node];
	}
	int mid = half(b, e);
	int leftValue = queryRange(left(node), b, mid, l, r);
	int rightValue = queryRange(right(node), mid + 1, e, l, r);
	return leftValue + rightValue;
}


void solve() {
	reset();

	int n, q; cin >> n >> q;
	n -= 1;
	while (q--) {
		int command; cin >> command;
		if (command == 0) { // update range
			int l, r, newVal; cin >> l >> r >> newVal;
			updateRange(0, 0, n, l, r, newVal);
		}
		else if (command == 1) { // range query
			int l, r; cin >> l >> r;
			int ans = queryRange(0, 0, n, l, r);
			cout << ans << endl;
		}
	}
}
main() {
	int T; cin >> T;
	for (int t = 1; t <= T; t++) {
		cout << "Case "<<t<<": " << endl;;
		solve();
	}
}
