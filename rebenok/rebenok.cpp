#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct Line {
	int WhereTo;
	int Color;
};

ifstream in("input.in");
ofstream out("output.out");
int N, L, K, Q;
int M;
int circles[101];
int pos[101][101];
queue<pair<int, int> > positions;
vector<vector<Line>> lines;

int main() {
	ios_base::sync_with_stdio(false);
	in.tie(0);
	in >> N >> L >> K >> Q;
	L--;
	K--;
	Q--;
	int xx, a, b, c;
	for (int i = 0; i < N; i++) {
		in >> xx;
		circles[i] = xx;
	}
	in >> M;
	lines.resize(N + 1);
	for (int i = 0; i < N; i++) {
		Line l;
		l.Color = 0;
		l.WhereTo = -1;
		lines[i].push_back(l);
	}
	for (int i = 0; i < M; i++) {
		in >> a >> b >> c;
		Line l;
		l.WhereTo = b - 1;
		l.Color = c;
		lines[a - 1].insert(lines[a - 1].begin(), l);
	}
	Line p;
	int x, y, curx = 0, cury = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < i; j++) {
			pos[i][j] = 100000;
		}
	}
	y = min(L, K);
	x = max(L, K);
	pos[x][y] = 0;
	positions.push({ x, y });
	int j;
	while(!positions.empty()) {
		x = positions.front().first;
		y = positions.front().second;
		positions.pop();
		j = 0;
		p = lines[x][j];
		while (p.WhereTo != -1)
		{
			curx = max(y, p.WhereTo);
			cury = min(y, p.WhereTo);
			if (curx > cury)
				if (p.Color == circles[y] && pos[x][y] + 1 < pos[curx][cury])
				{
					if (pos[curx][cury] > 10000) {
						positions.push({curx, cury});
					}
					pos[curx][cury] = pos[x][y] + 1;
					if (p.WhereTo == Q) break;
				}
			p = lines[x][j++];
		}
		j = 0;
		if (p.WhereTo == Q) break;
		p = lines[y][j];
		while (p.WhereTo != -1) {
			curx = max(x, p.WhereTo);
			cury = min(x, p.WhereTo);
			if (curx > cury)
				if (p.Color == circles[x] && pos[x][y] + 1 < pos[curx][cury])
				{
					if (pos[curx][cury] > 10000) {
						positions.push({curx, cury});
					}
					pos[curx][cury] = pos[x][y] + 1;
					if (p.WhereTo == Q) break;
				}
			p = lines[y][j++];
		}
		if (p.WhereTo == Q) break;	
	}
	if (pos[curx][cury] == 100000) {
		out << "No";
	}
	else {
		out << "Yes" << endl;
		out << pos[curx][cury];
	}
	return 0;
}