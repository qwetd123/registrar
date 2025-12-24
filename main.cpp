import graphics;
import std;
using std::print;

int main()
{
    Point p(1.0, 1.0);
    print( "Point p(1.0, 1.0);\n");

    print( "-----------------\n\n");
    print( "Shape s(p);\n");
    Shape s(p); // s是一个Shape对象，尽管语义上并不成立
    print( "\ns.move(Point(2.0, 2.0));\n");
    s.move(Point(2.0, 2.0)); // OK，调用Shape自身操作，静态绑定到自身的方法
    //    s.hideOp(); //错误！不从允许调用私有操作
    //    s.resize();//错误！resize()没有在Shape接口中声明
    //    s.noMethod();//错误！该操作调用不能进行静态绑定，编译器会报"未定义的引用"错误

    print( "-----------------\n\n");
    print( "Circle c(p, 10.0);\n");
    Circle c(p, 10.0); // c是一个Circle对象，内嵌了一个Shape对象
    print( "\nc.move(Point(3.0, 3.0)); \n");
    c.move(Point(3.0, 3.0)); // OK，调用继承的父类操作，静态绑定到继承的父类方法
    print( "\nc.resize(); \n");
    c.resize(2); // OK，调用子类的自身操作，静态绑定到自身的方法

    print( "-------------------------------\n\n");
    print( "Shape *ps = &c;\n");

    Shape *ps = &c;
    print( "\nps->move(p); \n");
    ps->move(p); // OK，通过指针调用Shape自身的操作，静态绑定到自身的方法
    //    ps->resize();     //错误！Shape的接口没有操作resize()

    print( "-----------------\n\n");
    print( "Circle *pc = &c;\n");
    Circle *pc = &c;
    print( "\npc->move(Point(5.0, 5.0)); \n");
    pc->move(Point(5.0, 5.0)); // OK，通过指针调用继承的父类Shape的操作，静态绑定到继承的父类方法
    print( "\npc->resize(); \n");
    pc->resize(2); // OK,通过指针调用子类Circle的自身操作，静态绑定到自身的方法

    return 0;
}

// void demo()
// {
//     Shape *ps = nullptr;              //ps的静态类型为Shape*
//     Circle *pc = new Circle();        //pc的静态类型为Circle*, 动态类型为Circle*
//     Rectangle* pr = new Rectangle();  //pr的静态类型为Rectangle*, 动态类型为Rectangle*
//     ps = pc;  //ps的动态类型现在是Circle*  赋值之后，ps就有了is a语义，即：一个Circle也是一个Shape，仍可作为Shape类型使用
//     ps = pr;  //pr的动态类型现在是Rectangle*  赋值之后，ps就有了is a语义，即：一个Rectangle也是一个Shape，仍可作为Shape类型使用

//     Circle c(p, 1);  //p是表达一个圆心点的对象，半径为1
//     Shape &rs（c);   //rs的静态类型是Shape&, 动态类型为Circle&
//                      //注意：C++引用类型的多态变量会永久绑定有名对象，不能重新指向其他对象，
//                      //     所以指针类型的多态变量会用得更多一些

// }


// void sp()
// {
//     // unique_ptr<Shape> ps(&c); // Error:智能指针只能管理堆对象，不能接收局部变量的地址
//     unique_ptr<Shape> ps;        //ps的静态类型为unique_ptr<Shape>, 其指针成员为nullptr

//     //pc的静态类型和动态类型都是unique_ptr<Circle>
//     unique_ptr<Circle> pc = make_unique<Circle>();
//     //pc的静态类型和动态类型都是unique_ptr<Rectangle>
//     unique_ptr<Rectangle> pr = make_unique<Rectangle>();

//     ps = std::move(pc);  //ps现在的动态类型是unique_ptr<Circle>

//     ps = std::move(pr);  //ps原来指向的Circle在擦除时被销毁，然后在移动复制得到pr的地址，
//                          //ps现在的动态类型是unique_ptr<Rectangle>
// }
