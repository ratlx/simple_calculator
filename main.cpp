#include "widget.h"

#include <QApplication>
#include <QLocale>
#include <iostream>
#include "evaluateExpression.h"

void test() {
    std::string str("(1.54*-8.11)-6");
    evaluateExpression s(str);
    std::cout<<s.calculate();
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //test();
    Widget w;
    w.show();
    return a.exec();
}
