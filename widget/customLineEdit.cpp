#include "customLineEdit.h"

CustomLineEdit::CustomLineEdit(QWidget* parent, QString regex, QString errorMsg)
    :QLineEdit(parent)
{

    QRegularExpressionValidator* validator = new QRegularExpressionValidator(QRegularExpression(regex));

    this->setValidator(validator);

    this->errorMsg = errorMsg;

    connect(this, &QLineEdit::inputRejected, this, CustomLineEdit::showErrors);
    connect(this, &QLineEdit::textChanged, this, CustomLineEdit::hideErrors);
}

void CustomLineEdit::showErrors(){
    QPoint pos = this->mapToGlobal(QPoint(0, 15));
    QToolTip::showText(pos, errorMsg);
}

void CustomLineEdit::hideErrors(){
    QToolTip::hideText();
}

void CustomLineEdit::setupUI(QString regex, QString errorMsg){
    QRegularExpressionValidator* validator = new QRegularExpressionValidator(QRegularExpression(regex));

    this->setValidator(validator);

    this->errorMsg = errorMsg;

    connect(this, &QLineEdit::inputRejected, this, CustomLineEdit::showErrors);
    connect(this, &QLineEdit::textChanged, this, CustomLineEdit::hideErrors);

}
