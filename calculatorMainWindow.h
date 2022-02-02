//
// Created by Alexander on 01.02.2022.
//

#ifndef UNTITLED_CALCULATORMAINWINDOW_H
#define UNTITLED_CALCULATORMAINWINDOW_H

#include <QMainWIndow>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QValidator>
#include <QRegularExpression>

class Validator : public QValidator
{
public:
    Validator(QObject* parent) : QValidator(parent) {}

    State validate(QString& str, int& pos) const override
    {
        QRegularExpression rxp =
                QRegularExpression("^[-+]?[0-9]*\\.?[0-9]*([eE][-+]?[0-9]*)?$");

        if (!rxp.match(str).hasMatch()) {
            return QValidator::Invalid;
        }

        return QValidator::Acceptable;
    }
};

class CalculatorMainWindow : public QMainWindow
{
    Q_OBJECT

private:
    double operand1{};
    double operand2{};

public:
    CalculatorMainWindow(QWidget* parent = nullptr) : QMainWindow(parent) {}

    QLineEdit *operand_1{};
    QLineEdit *operand_2{};
    QLineEdit *result{};

    QPushButton* plus{};
    QPushButton* minus{};
    QPushButton* multiply{};
    QPushButton* divide{};

public slots:
    void slotResult()
    {
        operand1 = operand_1->text().toDouble();
        operand2 = operand_2->text().toDouble();

        QPushButton* pb = static_cast<QPushButton*>(sender());

        if (pb == plus) result->setText(QString::number(operand1 + operand2));
        if (pb == minus) result->setText(QString::number(operand1 - operand2));
        if (pb == multiply) result->setText(QString::number(operand1 * operand2));
        if (pb == divide) {
            if (!operand2) {
                result->setText("ERROR");
                return;
            }

            result->setText(QString::number(operand1 / operand2));
        }
    }
};

#endif //UNTITLED_CALCULATORMAINWINDOW_H
