#include "faqint.h"
#include "ui_faqint.h"

FaqInt::FaqInt(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FaqInt)
{
    ui->setupUi(this);
}

FaqInt::~FaqInt()
{
    delete ui;
}
