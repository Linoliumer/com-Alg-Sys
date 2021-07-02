#ifndef INTNUMBER_H
#define INTNUMBER_H
#pragma once
#include <QWidget>
#include "IntegerNumbers/ABS_Z_N.h"
#include "IntegerNumbers/POZ_Z_D.h"
#include "IntegerNumbers/MUL_ZM_Z.h"
#include "IntegerNumbers/TRANS_N_Z.h"
#include "IntegerNumbers/TRANS_Z_N.h"
#include "IntegerNumbers/ADD_ZZ_Z.h"
#include "NaturalNumbera/COM_NN_D.h"
#include "IntegerNumbers/SUB_ZZ_Z.h"
#include "IntegerNumbers/MUL_ZZ_Z.h"
#include "IntegerNumbers/DIV_ZZ_Z.h"
#include "IntegerNumbers/MOD_ZZ_Z.h"
#include "IntegerNumbers/generalZNum.h"
namespace Ui {
class IntNumber;
}

class IntNumber : public QWidget
{
    Q_OBJECT

public:
    explicit IntNumber(QWidget *parent = nullptr);
    ~IntNumber();

signals:
    void firstWindowI();

private slots:
    void on_backIntNum_clicked();

    void on_push_ABS_Z_N_clicked();

    void on_push_POZ_Z_D_clicked();

    void on_push_MUL_ZM_Z_clicked();

    void on_push_TRANS_N_Z_clicked();

    void on_push_TRANS_Z_N_clicked();

    void on_push_ADD_ZZ_Z_clicked();

    void on_push_SUB_ZZ_Z_clicked();

    void on_push_MUL_ZZ_Z_clicked();

    void on_push_DIV_ZZ_Z_clicked();

    void on_push_MOD_ZZ_Z_clicked();

    void on_faqI_clicked();

private:
    Ui::IntNumber *ui;
};

#endif // INTNUMBER_H
