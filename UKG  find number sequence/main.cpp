vector<int> findNumberSequence(string& direction) {
    int n = direction.length();
    vector<int> res(n);

    int left = 0, right = n-1;

    for (int i = 0; i < n; i++) {
        if (direction[i] == 'L') {
            res[right--] = i+1;
        } else {
            res[left++] = i+1;
        }
    }

    return res;
}