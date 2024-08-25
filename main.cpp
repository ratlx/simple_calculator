#include "widget.h"
#include <QApplication>
#include <QLocale>
#include <iostream>
#include "evaluateExpression.h"

void test() {
    std::string str("9.85+0.000000000001");
    evaluateExpression s(str);
    std::cout.precision(13);
    std::cout<<s.calculate();
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    test();
    Widget w;
    w.show();
    return a.exec();
}
