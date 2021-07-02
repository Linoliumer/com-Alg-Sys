#include "creators.h"
#include "ui_creators.h"

Creators::Creators(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Creators)
{
    ui->setupUi(this);
}

Creators::~Creators()
{
    delete ui;
}

void Creators::on_backCreators_clicked()
{
    this->close();      // Закрываем окно
    emit firstWindowC();
}
