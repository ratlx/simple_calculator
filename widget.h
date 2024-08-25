#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QString>
#include <cctype>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_floatButton_clicked();

    void on_zerozeroButton_clicked();

    void on_zeroButton_clicked();

    void on_equalButton_clicked();

    void on_addButton_clicked();

    void on_threeButton_clicked();

    void on_twoButton_clicked();

    void on_oneButton_clicked();

    void on_subButton_clicked();

    void on_sixButton_clicked();

    void on_fiveButton_clicked();

    void on_fourButton_clicked();

    void on_mulButton_clicked();

    void on_nineButton_clicked();

    void on_eightButton_clicked();

    void on_sevenButton_clicked();

    void on_divButton_clicked();

    void on_delButton_clicked();

    void on_perButton_clicked();

    void on_clearButton_clicked();

private:
    Ui::Widget *ui;
    QString expression;
    bool isOpt(int);
    bool check();
};
#endif // WIDGET_H
