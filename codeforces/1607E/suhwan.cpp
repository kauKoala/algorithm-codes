#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		string s; cin >> s;

		int min_y = 0, max_y = 0, min_x = 0, max_x = 0;
		int y = 0, x = 0;
		int ans_y = 1, ans_x = 1;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == 'L') x--;
			else if (s[i] == 'R') x++;
			else if (s[i] == 'U') y--;
			else y++;
			
			min_y = min(min_y, y);
			max_y = max(max_y, y);
			min_x = min(min_x, x);
			max_x = max(max_x, x);

			if (max_x - min_x >= m || max_y - min_y >= n) break;
			ans_y = -min_y + 1;
			ans_x = -min_x + 1;
		}

		

		cout << ans_y << " " << ans_x << "\n";
	}


	return 0;
}