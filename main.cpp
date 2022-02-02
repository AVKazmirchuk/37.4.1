#include <QApplication>
#include <QValidator>
#include "calculatorMainWindow.h"
#include "./ui_calculator.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    CalculatorMainWindow window(nullptr);
    Ui::MainWindow calculator;
    calculator.setupUi(&window);

    window.result = calculator.result;

    window.operand_1  = calculator.operand_1;
    Validator* validator1 = new Validator(window.operand_1);
    calculator.operand_1->setValidator(validator1);
    window.operand_2 = calculator.operand_2;
    Validator* validator2 = new Validator(window.operand_2);
    calculator.operand_2->setValidator(validator2);

    window.plus = calculator.plus;
    window.minus = calculator.minus;
    window.multiply = calculator.multiply;
    window.divide = calculator.divide;

    window.resize(200, 100);
    window.show();

    return QApplication::exec();
}
