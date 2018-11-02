int getUmbrellas(int n, vector<int> p) {
    if (p.empty() || n <= 0) return -1;
    sort(p.begin(), p.end());
    return backtracking(n, p, 0);
}

int backtracking(int n, vector<int>& p) {
    for (int i=p.size()-1; i>=0; i--) {
        int remain = n - p[i];
        if (remain == 0) return 1;
        if (remain < 0) return -1;
        int temp = backtracking(remain, p);
        if (temp > 0) return temp + 1;
    }
    return -1;
}
