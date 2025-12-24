export module graphics:rectangle;

import :shape;  //子类分区需要导入基类分区
import std;
using std::print;

export class Rectangle : public Shape
{
public:
    Rectangle(Point origin = Point(),
              double width = 0.0,
              double length = 0.0);
    virtual ~Rectangle() override;

    //抽象操作的覆盖声明，简称覆盖操作
    virtual void resize(double ratio) override;

    //共似接口操作的覆盖声明，简称覆盖操作
    virtual void display() override;

private:
    double m_width;    //特有属性
    double m_length;   //特有属性
};

Rectangle::Rectangle(Point origin, double width, double length)
    :Shape(origin),m_width(width), m_length(length)
{}

Rectangle::~Rectangle(){
    print("cleaning in ~Rectangle()...\n");
}



// 抽象操作的Circle覆盖方法
void Rectangle::resize(double ratio)
{
    print("    ***resizing a rectangle: width = {}, length = {}"
          " before resize, ",
          m_width, m_length);
    m_width *= ratio;
    m_length *= ratio;
    print("width = {}, length = {}"
          " after resize\n",
          m_width, m_length);
}

//覆盖方法表达了子类特定的，有公共子行为的行为细节
void Rectangle::display()
{
    print("    ***display a Rectangle: ");
    Shape::display(); // 调用公共子行为的基类方法
    print(", width = {}, length = {} "
          "using Rectangle::display() method.\n",
          m_width, m_length);
}
