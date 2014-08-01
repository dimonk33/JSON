#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

#include "cjsonpacker.h"

namespace Ui {
    class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget (QWidget *parent = 0);
            ~Widget ();

private:
    Ui::Widget*     ui;
    CJsonPacker* converter;

private slots:
    void    test    (void);

};

#endif // WIDGET_H
