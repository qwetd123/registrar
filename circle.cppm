export module graphics:circle;

import :shape;  //子类分区需要导入基类分区
import std;
using std::print;

export class Circle : public Shape
{
public:
    Circle(class Point origin = Point(),
           double r = 0.0);      //构造函数
    void resize(double ratio);   //相似操作
    double diameter();           //特有操作
private:
    double m_radius;             //特有属性
};

Circle::Circle(Point origin, double r):
    Shape(origin), m_radius(r)
{}

void Circle::resize(double ratio)//相似操作的特定方法
{
    print("    radius = {} "
          "before resize, ", m_radius);
    m_radius *= ratio;
    print("radius = {} after resize.\n", m_radius);
}

double Circle::diameter()        //特定操作的特定方法
{
    return 2 * m_radius;
}
