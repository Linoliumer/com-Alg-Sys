#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <NaturalBack/anotherwindow.h>
#include <IntegerBack/intnumber.h>
#include <RatioBack/numberq.h>
#include <PolinomBack/numberpolinoms.h>
#include <CreatorsBack/creators.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_naturalNum_clicked();
    void on_intNum_clicked();
    void on_ratioNum_clicked();
    void on_polinoms_clicked();
    void on_creaters_clicked();

private:
    Ui::MainWindow *ui;
    AnotherWindow *sWindow;
    IntNumber *intWindow;
    NumberQ *windowQ;
    NumberPolinoms *pWindow;
    Creators *cWindow;

};
#endif // MAINWINDOW_H
