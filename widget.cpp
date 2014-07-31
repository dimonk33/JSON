#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent): QWidget(parent),
                                 ui(new Ui::Widget)
{
    ui->setupUi(this);

    connect(ui->btnTest, SIGNAL(clicked()), SLOT(test()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::test(void)
{
    unsigned short buf_size = ui->editBufSize->text().toInt();
    if (!buf_size)
    {
        ui->textEdit->appendPlainText("Неверный размер буфера - " + ui->editBufSize->text() + " байт");
        return;
    }
    ui->textEdit->clear();
    ui->textEdit->appendPlainText("Установлен размер буфера - " + ui->editBufSize->text() + " байт\r\n");
    char*   json = new char[buf_size];
    memset(json, 0, buf_size);

    TTEST_STRUCT_1  test_data_1;
    test_data_1.p1 = 1024;
    test_data_1.p2 = 0xAAAAAA;

    TTEST_STRUCT_2  test_data_2;
    test_data_2.p1 = 1;
    QByteArray test_str_2 = QString("test2").toLocal8Bit();
    test_data_2.p2 = (char*)test_str_2.constData();
    test_data_2.p3 = 0x555555;
    test_data_2.p4 = 0xAAAAAA;

    TTEST_STRUCT_3  test_data_3;
    QByteArray test_str_3_1 = QString("test3_p1").toLocal8Bit();
    test_data_3.p1 = (char*)test_str_3_1.constData();
    QByteArray test_str_3_2 = QString("test3_p2").toLocal8Bit();
    test_data_3.p2 = (char*)test_str_3_2.constData();

    TTEST_STRUCT_4  test_data_4;
    test_data_4.p1 = 0xAA;
    test_data_4.p2 = 0x12345678;

    TTEST_STRUCT_5  test_data_5;
    test_data_5.p1 = 1;
    for (int i = 0; i < 5; i++)
        test_data_5.p2.push_back(test_data_1);

    parser = new CJsonParser();
    json[0] = '[';
    parser->setBuf(&json[1], buf_size - 3);

    unsigned char i = 0;
    unsigned char send_buf = 0;
    unsigned char cnt_pack = 0;
// Pack struct to json
    while (i < 5)
    {
        unsigned short  len = 0;
        switch(i++)
        {
            case 0:
                len = parser->packStruct1(&test_data_1);
            break;
            case 1:
                len = parser->packStruct2(&test_data_2);
            break;
            case 2:
                len = parser->packStruct3(&test_data_3);
            break;
            case 3:
                len = parser->packStruct4(&test_data_4);
            break;
            case 4:
                len = parser->packStruct5(&test_data_5);
            break;
        }
        if (!len)
        {
        // Back to previous struct
            i--;
        // Check if json struct exceed buf size
            if (send_buf++)
                break;
        // Send buf
            ui->textEdit->appendPlainText(QString("%1 пакет:\r\n%2\r\n").arg(++cnt_pack)
                                                                        .arg(json));
        // Init buf and parser
            memset(json, 0, buf_size);
            parser->setBuf(json, buf_size - 2);
        }
        else
        {
        // Reset sending flag
            send_buf = 0;
        // Add json struct divider
            sprintf(json, "%s,", json);
        }
    }
// Add ending symbol
    if (strlen(json) && !send_buf)
        json[strlen(json) - 1] = '\0';
    sprintf(json, "%s]", json);
    ui->textEdit->appendPlainText(QString("%1 пакет:\r\n%2\r\n").arg(++cnt_pack)
                                                                .arg(json));
// Check send error
    if ((i < 5) &&  send_buf)
        ui->textEdit->appendPlainText("Недостаточный размер буфера - " + ui->editBufSize->text() + " байт");

    delete parser;
    delete [] json;
}
