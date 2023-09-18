#ifndef CUSTOMLINEEDIT_H
#define CUSTOMLINEEDIT_H

#include <QObject>
#include <QWidget>
#include <QDebug>
#include <QLineEdit>
#include <QRegularExpression>
#include <QRegularExpressionValidator>
#include <QToolTip>


class CustomLineEdit: public QLineEdit
{
    Q_OBJECT
public:
    CustomLineEdit(QWidget* parent=nullptr, QString regex=QString(), QString errorMsg=QString());

private slots:
    void showErrors();
    void hideErrors();

private:
    QString errorMsg;
};

#endif // CUSTOMLINEEDIT_H
