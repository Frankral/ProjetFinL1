#include "customDelegate.h"

CustomDelegate::CustomDelegate(QObject *parent, QString type, QString display, QString regex, QString errorMsg)
    :QStyledItemDelegate(parent)
{
    this->type = type;
    this->display = display;
    this->regex = regex;
    this->errorMsg = errorMsg;
}

QWidget* CustomDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    Q_UNUSED(option);
    Q_UNUSED(index);

    if(type == "unedit"){
        return Q_NULLPTR;
    }

    if(regex != ""){
        return new CustomLineEdit(parent, regex, errorMsg);
    }
    return new QLineEdit(parent);
}

QString CustomDelegate::displayText(const QVariant& value, const QLocale& locale) const{
    Q_UNUSED(locale);
    if(display == "phoneNumber"){
        return Format::phoneNumber(value.toString());
    }
    return value.toString();
}
