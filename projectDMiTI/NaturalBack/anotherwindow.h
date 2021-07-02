#ifndef ANOTHERWINDOW_H
#define ANOTHERWINDOW_H

#pragma once
#include <QWidget>
#include "NaturalNumbera/NZER_N_B.h"
#include "NaturalNumbera/COM_NN_D.h"
#include "NaturalNumbera/ADD_1N_N.h"
#include "NaturalNumbera/ADD_NN_N.h"
#include "NaturalNumbera/SUB_NN_N.h"
#include "NaturalNumbera/MUL_ND_N.h"
#include "NaturalNumbera/MUL_Nk_N.h"
#include "NaturalNumbera/MUL_NN_N.h"
#include "NaturalNumbera/SUB_NDN_N.h"
#include "NaturalNumbera/DIV_NN_Dk.h"
#include "NaturalNumbera/DIV_NN_N.h"
#include "NaturalNumbera/MOD_NN_N.h"
#include "NaturalNumbera/GCF_NN_N.h"
#include "NaturalNumbera/LCM_NN_N.h"
#include "NaturalNumbera/generalNatNum.h"

namespace Ui {
class AnotherWindow;
}

class AnotherWindow : public QWidget
{
    Q_OBJECT

public:
    explicit AnotherWindow(QWidget *parent = nullptr);
    ~AnotherWindow();

signals:
    void firstWindow();

private slots:
    void on_backNaturalNum_clicked();
    void on_push_COM_NN_D_clicked();

    void on_push_NZER_N_B_clicked();

    void on_push_ADD_1N_N_clicked();

    void on_push_ADD_NN_N_clicked();

    void on_push_SUB_NN_N_clicked();

    void on_push_MUL_ND_N_clicked();

    void on_push_MUL_Nk_N_clicked();

    void on_push_MUL_NN_N_clicked();

    void on_push_SUB_NDN_N_clicked();

    void on_push_DIV_NN_Dk_clicked();

    void on_push_DIV_NN_N_clicked();

    void on_push_MOD_NN_N_clicked();

    void on_push_GCF_NN_N_clicked();

    void on_push_LCM_NN_N_clicked();

    void on_faqN_clicked();

private:
    Ui::AnotherWindow *ui;
};

#endif // ANOTHERWINDOW_H
