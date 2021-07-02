#ifndef NUMBERPOLINOMS_H
#define NUMBERPOLINOMS_H

#include <QWidget>
#include "Polinoms/ADD_PP_P.h"
#include "Polinoms/generalPolinoms.h"
#include "Polinoms/MUL_PQ_P.h"
#include "Polinoms/MUL_Pxk_P.h"
#include "Polinoms/LED_P_Q.h"
#include "Polinoms/DEG_P_N.h"
#include "Polinoms/FAC_P_Q.h"
#include "Polinoms/MUL_PP_P.h"
#include "Polinoms/DEG_P_N.h"
#include "Polinoms/FAC_P_Q.h"
#include "Polinoms/MUL_PP_P.h"
#include "Polinoms/SUB_PP_P.h"
#include "Polinoms/DIV_PP_P.h"
#include "Polinoms/MOD_PP_P.h"
#include "Polinoms/GCF_PP_P.h"
#include "Polinoms/DER_P_P.h"
#include "Polinoms/NMR_P_P.h"

namespace Ui {
class NumberPolinoms;
}

class NumberPolinoms : public QWidget
{
    Q_OBJECT

signals:
    void firstWindowP();

public:
    explicit NumberPolinoms(QWidget *parent = nullptr);
    ~NumberPolinoms();

private slots:
    polinom enterPolinom();
    void on_backPolinoms_clicked();

    void on_firstPolinom_clicked();

    void on_secondPolinom_clicked();

    void on_push_ADD_PP_P_clicked();

    void on_push_SUB_PP_P_clicked();

    void on_push_MUL_PQ_P_clicked();

    void on_push_MUL_Pxk_P_clicked();

    void on_push_LED_P_Q_clicked();


    void on_faqP_clicked();

    void on_push_DEG_P_N_clicked();

    void on_push_FAC_P_Q_clicked();

    void on_push_MUL_PP_P_clicked();

    void on_push_DIV_PP_P_clicked();

    void on_push_MOD_PP_P_clicked();

    void on_push_GCF_PP_P_clicked();

    void on_push_DER_P_P_clicked();

    void on_push_NMR_P_P_clicked();

private:
    Ui::NumberPolinoms *ui;
};

#endif // NUMBERPOLINOMS_H
