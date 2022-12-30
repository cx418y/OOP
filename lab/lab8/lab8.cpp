#include <iostream>
#include <math.h>
using namespace std;



#define PI acos(-1)



class Shape			//抽象类 
{
public:
	virtual float area() const //计算面积 
	{
		return 0.0;
	}
	virtual float volume() const//计算体积 
	{
		return 0.0;
	}
	virtual void ShapeName() const = 0;//纯虚函数 ——形状名 
};

//声明点类
class Point : public Shape
{
public:
	Point(float = 0, float = 0);
	void setPoint(float, float);
	float getX()const;//获取x坐标
	float getY()const;//获取y坐标
	virtual void ShapeName()const
	{
		cout << "Point:";
		//cout << *this;
	}
	friend ostream& operator<< (ostream&, const Point&);
protected://重载操作符<<，使得能够用cout<<来输出成员变量
	float x, y;//点的坐标x,y
};

//Point类方法定义
Point::Point(float x, float y) {
	this->x = x;
	this->y = y;
}

void Point::setPoint(float x, float y) {
	this->x = x;
	this->y = y;
}

float Point::getX() const {
	return this->x;
}
float Point::getY() const {
	return this->y;
}

ostream& operator<< (ostream& output, const Point& p) {
	output << "X:" << p.getX() << ", Y: " << p.getY() << endl;
	return output;
}


//声明圈类
class Circle :public Point
{
public:
	Circle(float x = 0, float y = 0, float r = 0);
	void setRadius(float);
	float GetRadius()const;
	virtual float area() const;
	virtual void ShapeName()const
	{
		cout << "Circle:";
		//cout << *this;
	}
	friend ostream& operator<< (ostream&, const Circle&);
protected:
	float radius;//圈的半径
};

//圈类方法定义
Circle::Circle(float x, float y, float r) :Point(x, y) {
	this->radius = r;
}
void Circle::setRadius(float r) {
	this->radius = r;
}

float Circle::GetRadius() const { return this->radius; }

float Circle::area() const { return PI * radius * radius; }

ostream& operator<< (ostream& output, const Circle& circle) {
	output << "X:" << circle.getX() << ", Y: " << circle.getY() << ", radius:" << circle.GetRadius() << endl;

	return output;
}



//声明圆柱类 
class Cylinder :public Circle
{
public:
	Cylinder(float x = 0, float y = 0, float r = 0, float h = 0);
	void setHeight(float h);
	virtual float area()const;
	virtual float volume()const;
	virtual void ShapeName()const
	{
		cout << "Cylinder:";
		//cout << *this;
	}
	friend ostream& operator<< (ostream&, const Cylinder&);
protected:
	float height; //圆柱的高度
};

//圆柱方法定义
Cylinder::Cylinder(float x, float y, float r, float h) :Circle(x, y, r) {
	this->height = h;
}

void Cylinder::setHeight(float h) {
	this->height = h;
}

float Cylinder::area() const {
	return 2 * PI * radius * radius + 2 * PI * radius * height;
}

float Cylinder::volume() const {
	return PI * radius * radius * height;
}

ostream& operator<< (ostream& output, const Cylinder& cylinder) {
	output << "X:" << cylinder.getX() << ", Y: " << cylinder.getY() << ", radius:" << cylinder.GetRadius() <<", area:"<< cylinder.area()<<", volume:"<< cylinder.volume() << endl;

	return output;
}


int main()
{
	Point point(1.1, 2.2);
	Circle circle(3.3, 4.4, 5.5);
	Cylinder cylinder(6.6, 7.7, 8.8, 9.9);
	//补全调用部分，静态关联，直接调用各个ShapeName，输出各个成员变量（最好直接用cout）
	point.ShapeName();
	cout << point;
	circle.ShapeName();
	cout << circle;
	cylinder.ShapeName();
	cout << cylinder;

	Shape* pt;
	//补全调用部分，使用基类指针进行动态关联
	pt =  &point;
	pt->ShapeName();
	cout << endl;

	pt = &circle;
	pt->ShapeName();
	cout << endl;

	pt = &cylinder;
	pt->ShapeName();
	cout << endl;

	return 0;
}
