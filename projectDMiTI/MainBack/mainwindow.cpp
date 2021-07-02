#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    sWindow = new AnotherWindow();
    connect(sWindow, &AnotherWindow::firstWindow, this, &MainWindow::show);

    intWindow = new IntNumber();
    connect(intWindow, &IntNumber::firstWindowI, this, &MainWindow::show);

    windowQ = new NumberQ();
    connect(windowQ, &NumberQ::firstWindowQ, this, &MainWindow::show);

    pWindow = new NumberPolinoms();
    connect(pWindow, &NumberPolinoms::firstWindowP, this, &MainWindow::show);

    cWindow = new Creators();
    connect(cWindow, &Creators::firstWindowC, this, &MainWindow::show);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_naturalNum_clicked()
{
    sWindow->setFixedSize(813,401);
    sWindow->setWindowTitle("Натуральные числа");
    sWindow->show();
    this->close();
}

void MainWindow::on_intNum_clicked()
{
    intWindow->setFixedSize(813,401);
    intWindow->setWindowTitle("Целые числа");
    intWindow->show();
    this->close();
}

void MainWindow::on_ratioNum_clicked()
{
    windowQ->setFixedSize(813,401);
    windowQ->setWindowTitle("Рациональные числа");
    windowQ->show();
    this->close();
}

void MainWindow::on_polinoms_clicked()
{
    pWindow->setFixedSize(813,401);
    pWindow->setWindowTitle("Полиномы");
    pWindow->show();
    this->close();
}

void MainWindow::on_creaters_clicked()
{
    cWindow->setFixedSize(813,401);
    cWindow->setWindowTitle("Создатели");
    cWindow->show();
    this->close();
}
