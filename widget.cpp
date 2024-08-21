#include "widget.h"
#include "./ui_widget.h"
#include "evaluateExpression.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
    , expression()
{
    ui->setupUi(this);
    this->setWindowTitle("计算器");
}

Widget::~Widget()
{
    delete ui;
}

bool Widget::isOpt(int i) {
    if(expression.size()<i || i <= 0)
        return false;
    int index=expression.size()-i;
    if(expression[index]=='+' || expression[index]=='-'
        || expression[index]=='*' || expression[index]=='/')
        return true;
    else return false;
}

void Widget::on_floatButton_clicked()
{
    int pos=1,len=expression.size();
    for(;pos<=len;pos++) {
        if(isOpt(pos)) break;
        if(expression[len-pos]=='.')
            return;
    }
    if(pos==1) expression+="0.";
    else expression+='.';
    ui->mainLineEdit->setText(expression);
}


void Widget::on_zerozeroButton_clicked()
{
    bool isFloat=false;
    int pos=1,len=expression.size();
    for(;pos<=len;pos++) {
        if(isOpt(pos)) break;
        if(expression[len-pos]=='.')
            {isFloat=true;break;}
    }
    if(isFloat) expression+="00";
    else {
        int index=len-pos+1;
        if(pos!=1 && expression[index]!='0') expression+="00";
        else if(pos==1) expression+='0';
    }
    ui->mainLineEdit->setText(expression);
}


void Widget::on_zeroButton_clicked()
{
    bool isFloat=false;
    int pos=1,len=expression.size();
    for(;pos<=len;pos++) {
        if(isOpt(pos)) break;
        if(expression[len-pos]=='.')
        {isFloat=true;break;}
    }
    if(isFloat) expression+='0';
    else {
        int index=len-pos+1;
        if(pos!=1 && expression[index]=='0') return;
        else expression+='0';
    }
    ui->mainLineEdit->setText(expression);
}


void Widget::on_equalButton_clicked()
{
    if(check()) {
        auto str=expression.toStdString();
        evaluateExpression solve(str);
        auto res=solve.calculate();
        expression=QString::number(res);
        ui->mainLineEdit->setText(expression);
    }
    else {
        expression.clear();
        ui->mainLineEdit->setText("表达式错误");
    }
}


void Widget::on_addButton_clicked()
{
    if(expression.isEmpty() || expression[expression.size()-1]=='+')
        return;
    if(isOpt(1)) {
        if(isOpt(2)) expression.chop(2);
        else expression.chop(1);
    }
    expression+='+';
    ui->mainLineEdit->setText(expression);
}


void Widget::on_threeButton_clicked()
{
    expression+='3';
    ui->mainLineEdit->setText(expression);
}


void Widget::on_twoButton_clicked()
{
    expression+='2';
    ui->mainLineEdit->setText(expression);
}


void Widget::on_oneButton_clicked()
{
    expression+='1';
    ui->mainLineEdit->setText(expression);
}


void Widget::on_subButton_clicked()
{
    if(!expression.isEmpty() && expression[expression.size()-1]=='+') expression.chop(1);
    if(expression.isEmpty() || expression[expression.size()-1]!='-')
        expression+='-';
    ui->mainLineEdit->setText(expression);
}


void Widget::on_sixButton_clicked()
{
    expression+='6';
    ui->mainLineEdit->setText(expression);
}


void Widget::on_fiveButton_clicked()
{
    expression+='5';
    ui->mainLineEdit->setText(expression);
}


void Widget::on_fourButton_clicked()
{
    expression+='4';
    ui->mainLineEdit->setText(expression);
}


void Widget::on_mulButton_clicked()
{
    if(expression.isEmpty() || expression[expression.size()-1]=='*')
        return;
    if(isOpt(1)) {
        if(isOpt(2)) expression.chop(2);
        else expression.chop(1);
    }
    expression+='*';
    ui->mainLineEdit->setText(expression);
}


void Widget::on_nineButton_clicked()
{
    expression+='9';
    ui->mainLineEdit->setText(expression);
}


void Widget::on_eightButton_clicked()
{
    expression+='8';
    ui->mainLineEdit->setText(expression);
}


void Widget::on_sevenButton_clicked()
{
    expression+='7';
    ui->mainLineEdit->setText(expression);
}


void Widget::on_divButton_clicked()
{
    if(expression.isEmpty() || expression[expression.size()-1]=='/')
        return;
    if(isOpt(1)) {
        if(isOpt(2)) expression.chop(2);
        else expression.chop(1);
    }
    expression+='/';
    ui->mainLineEdit->setText(expression);
}


void Widget::on_delButton_clicked()
{
    expression.chop(1);
    ui->mainLineEdit->setText(expression);
}


void Widget::on_perButton_clicked()
{
    expression+='%';
    ui->mainLineEdit->setText(expression);
}


void Widget::on_clearButton_clicked()
{
    expression.clear();
    ui->mainLineEdit->setText(expression);
}

bool Widget::check() {
    int cur=0,len=expression.size();
    for(;cur<len;cur++) {
        if(expression[cur]=='%') {
            if(cur==0 || isOpt(len-cur+1))
                return false;
        }
        if(expression[cur]=='-') {
            if(cur==len-1 || (isOpt(len-cur-1) && expression[cur+1]!='('))
                return false;
        }
    }
    return true;
}