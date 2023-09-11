#include <bits/stdc++.h>

using namespace std;

const double EPS = 1e-9;

struct vec {
	double x, y;
	vec() {x = 0; y = 0;}
	vec(double _x, double _y) : x(_x), y(_y) {}
	bool operator == (vec other) const  {
		if (abs(x - other.x) < EPS && abs(y - other.y) < EPS) return true;
		else return false;
	}
	vec scale(double k) {
		return vec(x * k, y * k);
	}
	double norm() {
		return x * x + y * y;
	}
};

struct point() {
	double x, y;
	point() {x = 0; y = 0}
	point(double _x, double _y) : x(_x), y(_y) {}
	bool operator == (point other) const  {
		if (abs(x - other.x) < EPS && abs(y - other.y) < EPS) return true;
		else return false;
	}
	point move(vec a) {
		return point(x + a.x, y + a.y); //translate ()
	}
};

double dist(point a, point b) {
	return hypot(a.x - b.x, a.y - b.y);
}

vec toVec(point a, point b) {
	return vec(b.x - a.x, b.y - a.y);
}

struct line {
	double a, b, c;
};

void points_to_line(point a, point b, line &c) {
	if (abs(a.x - b.x) < EPS) {
		c.a = 1, c.b = 0, c.c = -a.x;
	} else {
		c.b = 1.0;
		c.a = 1.0 * (a.y - b.y) / (b.x - a.x);
		c.c = -c.a * a.x - a.y;
	}
}

bool areParrallel(line l1, line l2) {
	return (abs(l1.a - l2.a) < EPS && abs(l1.b - l2.b) < EPS);
}

bool areSame(line l1, line l2) {
	return (areParrallel(l1, l2) && abs(l1.c - l2.c) < EPS);
}

bool areIntersect(line l1, line l2, point &p) {
	if (areParrallel(l1, l2)) return false;
	p.x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);
	if (abs(l1.b) > EPS) p.y = -(l1.a * p.x + l1.c);
	else 				 p.y = -(l2.a * p.x + l2.c);
	return true;
}

double dot_product(vec a, vec b) {
	return (a.x * b.x + a.y * b.y);
}

double distToLine(point p, point a, point b, point &res) {
	vec ap = toVec(a, p), ab = toVec(a, b);
	double u = dot_product(ap, ab) / ab.norm();
	res = a.move(ab.scale(u));
	return dist(p, res);
}

double distToSeg(point p, point a, point b, point &res) {
	vec ap = toVec(a, p), ab = toVec(a, b);
	double u = dot_product(ap, ab) / ab.norm();
	if (u < EPS) {
		res = a;
		return dist(p, a);
	}
	if (u > 1.0) {
		res = b;
		return dist(p, b);
	}
	res = a.move(ab.scale(u));
	return dist(res, p);
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("Geometry.inp", "r", stdin);
	freopen("Geometry.out", "w", stdout);

	return 0;
}
