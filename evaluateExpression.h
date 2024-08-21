//
// Created by 小火锅 on 24-8-20.
//

#ifndef CALCULATE_H
#define CALCULATE_H

#include <sstream>
#include <cctype>
#include <stack>

class evaluateExpression {
private:
    std::istringstream iss;
    std::string expression;
public:
    explicit evaluateExpression(std::string&);
    bool isOpt(char);
    char precede(char,char);
    double operate(double,char,double);
    double calculate();
};



#endif //CALCULATE_H
