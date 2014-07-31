#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

#include <cjsonparser.h>

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
    CJsonParser*    parser;

private slots:
    void    test    (void);

};

#endif // WIDGET_H
