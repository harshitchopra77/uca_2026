#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;

    cin >> n >> k;

    vector<int> population(n);

    for (int i = 0; i < n; i++) {
        cin >> population[i];
    }

    priority_queue<tuple<double, int, int>> pq;

    for (int i = 0; i < n; i++) {
        pq.push({(double)population[i], 1, i});
    }

    int remaining = k - n;

    while (remaining--) {
        auto[load,num,idx]=pq.top();
        pq.pop();
        num++;
        load=(double)population[idx]/num;
        pq.push({load,idx,num});
    }

    auto [answer, num, idx] = pq.top();

    cout << answer << endl;

    return 0;
}