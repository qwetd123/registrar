export module graphics:rectangle;

import :shape;  //子类分区需要导入基类分区
import std;
using std::print;

class Rectangle : public Shape
{
public:
    Rectangle(Point origin, double width, double length);

    void resize(double ratio);  //相似操作

private:
    double m_width;   //特有属性
    double m_length;   //特有属性
};

Rectangle::Rectangle(Point origin, double width, double length)
    :Shape(origin),m_width(width), m_length(length)
{}

void Rectangle::resize(double ratio) //相似操作的特定方法
{
    print("    width = {}, length = {} before resize, ", m_width, m_length);
    m_width *= ratio;
    m_length *= ratio;
    print("width = {}, length = {} after resize\n", m_width, m_length);
}
