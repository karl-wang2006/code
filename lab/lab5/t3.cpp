#include<iostream>
#include<string>
#include<iomanip>
#include<vector>
#include <sstream>
using namespace std;

class Vec3
{
	double x;
	double y;
	double z;
public:
	Vec3(double x1, double y1, double z1)
	{
		x = x1;
		y = y1;
		z = z1;
	}
	Vec3 cross(const Vec3& other) const
	{
		Vec3 c(0.,0.,0.);
		c.x = y * (other.z) - (other.y) * z;
		c.y = (other.x) * z - x * (other.z);
		c.z = x * (other.y) - (other.x) * y;
		return c;
	}
	void print()
	{
		cout << "(" << x <<","<< y <<","<< z << ")";
	}
};
int main()
{
	double x1, x2, y1, y2, z1, z2;
	cin >> x1 >> y1 >> z1;
	cin >> x2 >> y2 >> z2;
	Vec3 m(x1, y1, z1);
	Vec3 n(x2, y2, z2);
	Vec3 k=m.cross(n);
	k.print();
	return 0;
}