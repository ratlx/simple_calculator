//
// Created by 小火锅 on 24-8-20.
//

#include "evaluateExpression.h"

evaluateExpression::evaluateExpression(std::string& str):iss(str+'#'),expression(str) {}

bool evaluateExpression::isOpt(char ch) {
    switch (ch)
    {
        case '+':
            return true;
        case '-':
            return true;
        case '*':
            return true;
        case '/':
            return true;
        case '(':
            return true;
        case ')':
            return true;
        case '#':
            return true;
        default:
            return false;
    }
}

char evaluateExpression::precede(char t1, char t2) {
    char f;
    switch (t1)
    {
        case '+':
            if (t2 == '*' || t2 == '/' || t2 == '(')
                f = '<';
            else
                f = '>';
        break;
        case '-':
            if (t2 == '*' || t2 == '/' || t2 == '(')
                f = '<';
            else
                f = '>';
        break;
        case '*':
            if (t2 == '(')
                f = '<';
            else
                f = '>';
        break;
        case '/':
            if (t2 == '(')
                f = '<';
            else
                f = '>';
        break;
        case '(':
            if (t2 == ')')
                f = '=';
            else if (t2 == '#')
                f = ' ';
            else
                f = '<';
        break;
        case ')':
            if (t2 == '(')
                f = ' ';
            else
                f = '>';
        break;
        case '#':
            if (t2 == '#')
                f = '=';
            if (t2 == ')')
                f = ' ';
            else
                f = '<';
        break;
    }
    return f;
}

double evaluateExpression::operate(double num1, char opt, double num2) {
    switch (opt){
        case '+':
            return num1 + num2;
        case '-':
            return num2 - num1;
        case '*':
            return num2 * num1;
        case '/':
            return num2 / num1;
    }
}

double evaluateExpression::calculate() {
    std::stack<char> sch;
    std::stack<double> sdouble;
    char ch, opt;
    double tmp, num1, num2, res;
    bool prnm = false, minus=false;
    double isft=0;
    sch.push('#');
    iss>>ch;
    int pos=0;
    while (ch!='#'||sch.top()!='#') {
        if (isdigit(ch)) {
            if (prnm) {
                tmp = sdouble.top();
                sdouble.pop();
                if(minus) {
                    if(isft) {
                        tmp=tmp-(ch-'0')/isft;
                        isft*=10;
                    }
                    else
                        tmp=tmp*10-(ch-'0');
                }
                else {
                    if(isft) {
                        tmp=tmp+(ch-'0')/isft;
                        isft*=10;
                    }
                    else
                        tmp=tmp*10+(ch-'0');
                }
                sdouble.push(tmp);
                iss>>ch;
                pos++;
            }
            else {
                prnm = true;
                tmp=ch-'0';
                if(minus) tmp=-tmp;
                sdouble.push(tmp);
                iss>>ch;
                pos++;
            }
        }
        else if(ch=='.') {
            isft=10;
            iss>>ch;
            pos++;
        }
        else if (ch=='%') {
            prnm=isft=minus=false;
            tmp=sdouble.top();
            sdouble.pop();
            tmp=operate(100,'/',tmp);
            sdouble.push(tmp);
            iss>>ch;
            pos++;
        }
        else if (isOpt(ch)) {
            prnm=isft=minus=false;
            if(ch=='-') {
                if(pos==0 || (isOpt(expression[pos-1]) && expression[pos-1]!=')')) {
                    minus=true;
                    iss>>ch;
                    pos++;
                    continue;
                }
            }
            switch (precede(sch.top(), ch)) {
                case'>':{
                    num1=sdouble.top();
                    sdouble.pop();
                    num2 = sdouble.top();
                    sdouble.pop();
                    opt = sch.top();
                    sch.pop();
                    res = operate(num1, opt, num2);
                    sdouble.push(res);
                    break;
                }
                case'<':
                    sch.push(ch);
                    iss>>ch;
                    pos++;
                    break;
                case'=':
                    sch.pop();
                    iss>>ch;
                    pos++;
                    break;
            }
        }
    }
    return sdouble.top();
}


