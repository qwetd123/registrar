// Module partition graphics:shape - define class Point and Shape
// File: shape.cppm   Version: 0.1.0   License: AGPLv3
// Created: Wei Gong   open-src@qq.com   2025-12-21 11:40:58
// Description:
//     Shape is the base class for all graphics classes
//     Every Shape object has a Point object representing its center

export module graphics:shape;

import std;
using std::print;

export class Point
{
public:
    Point(double x = 0.0, double y = 0.0);
    std::string toString();
private:
    double m_x;
    double m_y;
};

export class Shape
{
public:
    Shape(Point o);            //构造函数声明，通常不会被继承
    Shape(double x, double y); //重载的构造函数
    void move(Point p);        //普通函数声明，可被继承
    void noMethodOperate();    //普通函数声明，但没有方法，可调用，链接失败
    Point origin() const;      //若作为边界对象，可以按需保留(不需要也应去掉);若是实体对象，则应该去掉。
private:
    void hideOperate();         //隐藏的操作，不是接口的一部分，调用时不可见
    Point m_origin;            //属性描述，可被继承
};

Point::Point(double x, double y)
    : m_x (x), m_y (y)
{}

std::string Point::toString()
{
    return std::format("({}, {})", m_x, m_y);
}

Shape::Shape(Point p):m_origin(p){}
Shape::Shape(double x, double y)
    :m_origin(x,y)
{}

void Shape::move(Point p)//泛化的方法，被子类继承
{
    print("    moving to a new Point:{} "
          "using Shape::move().\n", p.toString());
    m_origin = p;
}

Point Shape::origin() const
{ //若Shape作为实体类，不需要该getter方法
    return m_origin;
}

void Shape::hideOperate()
{
    print("invoking hideOp()\n");
}
