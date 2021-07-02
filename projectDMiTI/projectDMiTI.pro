QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    IntegerNumbers/ABS_Z_N.cpp \
    Polinoms/ADD_PP_P.cpp \
    NaturalNumbera/ADD_1N_N.cpp \
    NaturalNumbera/ADD_NN_N.cpp \
    IntegerNumbers/ADD_ZZ_Z.cpp \
    RatioNumbers\ADD_QQ_Q.cpp \
    NaturalNumbera/COM_NN_D.cpp \
    Polinoms/DEG_P_N.cpp \
    NaturalNumbera/DIV_NN_Dk.cpp \
    NaturalNumbera/DIV_NN_N.cpp \
    Polinoms/DIV_PP_P.cpp \
    IntegerNumbers/DIV_ZZ_Z.cpp \
    RatioNumbers\DIV_QQ_Q.cpp \
    Polinoms/DER_P_P.cpp \
    Polinoms/FAC_P_Q.cpp \
    NaturalNumbera/GCF_NN_N.cpp \
    Polinoms/GCF_PP_P.cpp \
    Polinoms/LED_P_Q.cpp \
    Polinoms/MOD_PP_P.cpp \
    Polinoms/MUL_PP_P.cpp \
    Polinoms/MUL_PQ_P.cpp \
    Polinoms/MUL_Pxk_P.cpp \
    Polinoms/NMR_P_P.cpp \
    Polinoms/SUB_PP_P.cpp \
    NaturalNumbera/generalNatNum.cpp \
    Polinoms/generalPolinoms.cpp \
    RatioNumbers\generalRatioNumber.cpp \
    IntegerNumbers/generalZNum.cpp \
    RatioNumbers\INT_Q_B.cpp \
    NaturalNumbera/LCM_NN_N.cpp \
    NaturalNumbera/MOD_NN_N.cpp \
    IntegerNumbers/MOD_ZZ_Z.cpp \
    NaturalNumbera/MUL_ND_N.cpp \
    NaturalNumbera/MUL_Nk_N.cpp \
    NaturalNumbera/MUL_NN_N.cpp \
    IntegerNumbers/MUL_ZM_Z.cpp \
    IntegerNumbers/MUL_ZZ_Z.cpp \
    RatioNumbers\MUL_QQ_Q.cpp \
    NaturalNumbera/NZER_N_B.cpp \
    IntegerNumbers/POZ_Z_D.cpp \
    RatioNumbers\RED_Q_Q.cpp \
    NaturalNumbera/SUB_NDN_N.cpp \
    NaturalNumbera/SUB_NN_N.cpp \
    IntegerNumbers/SUB_ZZ_Z.cpp \
    RatioNumbers\SUB_QQ_Q.cpp \
    IntegerNumbers/TRANS_N_Z.cpp \
    IntegerNumbers/TRANS_Z_N.cpp \
    RatioNumbers\TRANS_Z_Q.cpp \
    RatioNumbers\TRANS_Q_Z.cpp \
    NaturalBack//anotherwindow.cpp \
    CreatorsBack/creators.cpp \
    IntegerBack/intnumber.cpp \
    main.cpp \
    MainBack/mainwindow.cpp \
    PolinomBack//numberpolinoms.cpp \
    RatioBack//numberq.cpp

HEADERS += \
    Polinoms/DER_P_P.h \
    Polinoms/GCF_PP_P.h \
    Polinoms/MOD_PP_P.h \
    Polinoms/NMR_P_P.h \
    Polinoms/RED_Q_Q.h \
    IntegerNumbers/ABS_Z_N.h \
    Polinoms/ADD_PP_P.h \
    NaturalNumbera/ADD_1N_N.h \
    NaturalNumbera/ADD_NN_N.h \
    IntegerNumbers/ADD_ZZ_Z.h \
    RatioNumbers\ADD_QQ_Q.h \
    NaturalNumbera/COM_NN_D.h \
    Polinoms/DEG_P_N.h \
    NaturalNumbera/DIV_NN_Dk.h \
    NaturalNumbera/DIV_NN_N.h \
    Polinoms/DIV_PP_P.h \
    IntegerNumbers/DIV_ZZ_Z.h \
    RatioNumbers\DIV_QQ_Q.h \
    Polinoms/FAC_P_Q.h \
    NaturalNumbera/GCF_NN_N.h \
    Polinoms/LED_P_Q.h \
    Polinoms/MUL_PP_P.h \
    Polinoms/MUL_PQ_P.h \
    Polinoms/MUL_Pxk_P.h \
    Polinoms/SUB_PP_P.h \
    NaturalNumbera/generalNatNum.h \
    Polinoms/generalPolinoms.h \
    RatioNumbers\generalRatioNumber.h \
    IntegerNumbers/generalZNum.h \
    RatioNumbers\INT_Q_B.h \
    NaturalNumbera/LCM_NN_N.h \
    NaturalNumbera/MOD_NN_N.h \
    IntegerNumbers/MOD_ZZ_Z.h \
    NaturalNumbera/MUL_ND_N.h \
    NaturalNumbera/MUL_Nk_N.h \
    NaturalNumbera/MUL_NN_N.h \
    IntegerNumbers/MUL_ZM_Z.h \
    IntegerNumbers/MUL_ZZ_Z.h \
    RatioNumbers\MUL_QQ_Q.h \
    NaturalNumbera/NZER_N_B.h \
    IntegerNumbers/POZ_Z_D.h \
    NaturalNumbera/SUB_NDN_N.h \
    NaturalNumbera/SUB_NN_N.h \
    IntegerNumbers/SUB_ZZ_Z.h \
    RatioNumbers\SUB_QQ_Q.h \
    IntegerNumbers/TRANS_N_Z.h \
    IntegerNumbers/TRANS_Z_N.h \
    RatioNumbers\TRANS_Z_Q.h \
    RatioNumbers\TRANS_Q_Z.h \
    NaturalBack/anotherwindow.h \
    CreatorsBack/creators.h \
    IntegerBack/intnumber.h \
    MainBack/mainwindow.h \
    PolinomBack/numberpolinoms.h \
    RatioBack/numberq.h

FORMS += \
    NaturalBack/anotherwindow.ui \
    CreatorsBack/creators.ui \
    IntegerBack/intnumber.ui \
    MainBack/mainwindow.ui \
    PolinomBack/numberpolinoms.ui \
    RatioBack/numberq.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
