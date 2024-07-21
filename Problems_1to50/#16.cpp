#include <iostream>
#include <cmath>
using namespace std;

float Area(float a, float d) {
	return(a * (sqrt(pow(d,2) - pow(a,2))));
}
int main() {
	float A, D;
	cin >> A >> D;
	cout << Area(A, D) << endl;
}