import graphics;
import std;

using std::print;

int main()
{
    Point p(1.0, 1.0);

    Shape *ps = new Circle(p, 1.0);
    print("Point p(1.0, 1.0);\n");
    print("Shape *ps = new Circle(p, 1.0);\n");
    ps->display();     // 多态调用Shape的接口操作display()

    delete ps;
    print("-------------------------------\n");

    ps = new Rectangle(p, 1.0, 1.0);
    print("ps = new Rectangle(p, 1.0, 1.0);\n");
    ps->display();     // 多态调用Shape的接口操作display()

    delete ps;
    print("-------------------------------\n");



    //这是高扬添加的行，测试推送到别人的github仓库
    //这是高扬gy_branch分支添加的行

    return 0;
}
