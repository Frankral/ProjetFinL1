#ifndef CUSTOMDELEGATE_H
#define CUSTOMDELEGATE_H

#include "format.h"
#include "widget/customLineEdit.h"

#include <QObject>
#include <QStyledItemDelegate>
#include <QWidget>
#include <QStyleOptionViewItem>
#include <QModelIndex>
#include <QLineEdit>


class CustomDelegate: public QStyledItemDelegate
{
public:
    explicit CustomDelegate(QObject *parent = nullptr, QString type=QString(), QString display=QString(), QString regex=QString(), QString errorMsg=QString());
    QWidget* createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index)const override;
    QString displayText(const QVariant& value, const QLocale& locale) const override;

private:
    QString type;
    QString display;
    QString regex;
    QString errorMsg;
};

#endif // CUSTOMDELEGATE_H
