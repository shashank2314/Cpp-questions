class SegmentTree {
private:
    vector<int> segTree;
    int n;

public:
    SegmentTree(int size) {
        n = size;
        segTree.resize(4 * n, 0);
        build(0, 0, n - 1);
    }

    void build(int node, int left, int right) {
        if (left == right) {
            segTree[node] = 1;
            return;
        }
        int mid = (left + right) / 2;
        build(2 * node + 1, left, mid);
        build(2 * node + 2, mid + 1, right);
        segTree[node] = segTree[2 * node + 1] + segTree[2 * node + 2];
    }

    int query(int node, int left, int right, int k) {
        if (left == right) return left;
        int mid = (left + right) / 2;
        int leftCount = segTree[2 * node + 1];
        if (k <= leftCount) {
            return query(2 * node + 1, left, mid, k);
        } else {
            return query(2 * node + 2, mid + 1, right, k - leftCount);
        }
    }

    void update(int node, int left, int right, int idx) {
        if (left == right) {
            segTree[node] = 0;
            return;
        }
        int mid = (left + right) / 2;
        if (idx <= mid) {
            update(2 * node + 1, left, mid, idx);
        } else {
            update(2 * node + 2, mid + 1, right, idx);
        }
        segTree[node] = segTree[2 * node + 1] + segTree[2 * node + 2];
    }
};

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int n = people.size();
        sort(people.begin(), people.end(), [](const auto& a, const auto& b) {
            if (a[0] != b[0]) return a[0] < b[0];
            return a[1] > b[1];
        });

        vector<vector<int>> ans(n);
        SegmentTree st(n);

        for (auto& person : people) {
            int pos = st.query(0, 0, n - 1, person[1] + 1);
            ans[pos] = person;
            st.update(0, 0, n - 1, pos);
        }

        return ans;
    }
};