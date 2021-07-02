#include "numberpolinoms.h"
#include "ui_numberpolinoms.h"
#include <QInputDialog>
#include <QDir>
#include <QMessageBox>
#include <iostream>
#include <QRegExp>

NaturalNumber inputNatPP(bool &ok,const QString &str){
    NaturalNumber result;
    int sizeStr, i, temp;
    bool ok2;
    QString temps = "";
    ok = 1;
    sizeStr = str.size();
    result.olderCoef = 0;
    for(i=0;i<sizeStr;i++){
        temps = "";
        temps.append(str[i]);
        temp = temps.toInt(&ok2, 10);
        if(ok2){
            result.arrayNum.insert(result.arrayNum.begin(),temp);
            ++result.olderCoef;
        }else{
            ok = 0;
            i = sizeStr;
        }
    }

    return result;
}

numberZ inputZPP(bool &ok,const QString &str){
    numberZ result;
    int sizeStr, i, temp;
    bool ok2;
    QString temps = "";
    ok = 1;
    sizeStr = str.size();
    result.olderCoef = 0;
    if(str[0]=="-"){
        result.sign = 1;
        i = 1;
    }else{
        result.sign = 0;
        i = 0;
    }
    for(;i<sizeStr;i++){
        temps = "";
        temps.append(str[i]);
        temp = temps.toInt(&ok2, 10);
        if(ok2){
            result.arrayNum.insert(result.arrayNum.begin(),temp);
            ++result.olderCoef;
        }else{
            ok = 0;
            i = sizeStr;
        }
    }

    return result;
}

NumberPolinoms::NumberPolinoms(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NumberPolinoms)
{
    ui->setupUi(this);
}

NumberPolinoms::~NumberPolinoms()
{
    delete ui;
}

polinom polinom1, polinom2;
bool setPolinom1 = 0;
bool setPolinom2 = 0;

polinom NumberPolinoms::enterPolinom(){
    bool ok, ok1;
    long long int power;
    numberR temp;
    polinom result;
    ok = 1;
    ok1 = 1;

    QString text = QInputDialog::getText(this,
                                 QString::fromUtf8("Окно ввода полинома"),
                                 QString::fromUtf8("Введите степень:"),
                                 QLineEdit::Normal,
                                 QDir::home().dirName(), &ok);
    if (!(ok && !text.isEmpty())) ok1 = 0;
    power = text.toLongLong(&ok, 10);
    if(ok){
        if(power<0) ok1 = 0;
        else result.olderCoef = power;
    }else{
        ok1 = 0;
    }
    do{
        if(ok1){
            QString text = QInputDialog::getText(this,
                                         QString::fromUtf8("Окно ввода полинома"),
                                         QString::fromUtf8("Введите числитель коэффициента неизвестного :"),
                                         QLineEdit::Normal,
                                         QDir::home().dirName(), &ok);
            if (ok && !text.isEmpty()){
                    temp.whole = inputZPP(ok, text);
                    if(ok){
                        QString text = QInputDialog::getText(this,
                                                     QString::fromUtf8("Окно ввода полинома"),
                                                     QString::fromUtf8("Введите знаменатель коэффициента неизвестного :"),
                                                     QLineEdit::Normal,
                                                     QDir::home().dirName(), &ok);
                        if (ok && !text.isEmpty()){
                            temp.natural = inputNatPP(ok, text);
                            if(ok){
                                --power;
                                result.arrayNum.insert(result.arrayNum.begin() , temp);
                            }else{
                                ok1 = 0;
                                QMessageBox::warning(this, "Ошибка!" , "При вводе исходных данных проихошла ошибка!");
                            }
                        }else{
                            ok1 = 0;
                            QMessageBox::warning(this, "Ошибка!" , "При вводе исходных данных проихошла ошибка!");
                        }
                    }else{
                        ok1 = 0;
                        QMessageBox::warning(this, "Ошибка!" , "При вводе исходных данных проихошла ошибка!");
                    }
            }else{
                ok1 = 0;
                QMessageBox::warning(this, "Ошибка!" , "При вводе исходных данных проихошла ошибка!");
            }
        }else{
            QMessageBox::warning(this, "Ошибка!" , "При вводе исходных данных проихошла ошибка!");
        }
    }while((ok1)&&(power >= 0));

    if(!ok1){
        result.olderCoef = -1;
    }
    correct(result);
    return result;
}


QString printP(polinom answer){
    QString resultALL = "";
    QString result = "(%1/%2)x^%3\n";
    QString whole, natural, power, a;
    int i,j;
    if(answer.olderCoef == 0){
        whole.setNum(XarrayZtoX(answer.arrayNum[0].whole));
        natural.setNum(XArrayToX(answer.arrayNum[0].natural));
        power.setNum(0);
        return resultALL.append(result.arg(whole).arg(natural).arg(power));
    }
    for(i=0;i<answer.olderCoef+1;++i){

        whole = "";
        natural = "";
        power = "";
        if(answer.arrayNum[i].whole.sign == 1) whole.append("-");
        for(j=answer.arrayNum[i].whole.olderCoef-1;j>=0;--j){
            whole.append(a.setNum(answer.arrayNum[i].whole.arrayNum[j]));
        }
        for(j=answer.arrayNum[i].natural.olderCoef-1;j>=0;--j){
            natural.append(a.setNum(answer.arrayNum[i].natural.arrayNum[j]));
        }
        power.setNum(i);
        resultALL.append(result.arg(whole).arg(natural).arg(power));
    }
    return resultALL;
}

QString printZP(numberR number1){
    int i;
    QString str="";
    QString a;
    if(number1.whole.sign == 1) str.append("-");
    for(i=number1.whole.olderCoef-1; i>=0;--i){
        str.append(a.setNum(number1.whole.arrayNum[i]));
    }
    str.append("/");
    for(i=number1.natural.olderCoef-1; i>=0;--i){
        str.append(a.setNum(number1.natural.arrayNum[i]));
    }
    return str;
}

void NumberPolinoms::on_backPolinoms_clicked()
{
    this->close();      // Закрываем окно
    emit firstWindowP();
}



void NumberPolinoms::on_firstPolinom_clicked()
{
    polinom1 = enterPolinom();
    if(polinom1.olderCoef != -1){
        setPolinom1 = 1;
        QMessageBox::information(this, "Успешно!" , "Первый полином задан!");
    }else setPolinom1 = 0;
}

void NumberPolinoms::on_secondPolinom_clicked()
{
    polinom2 = enterPolinom();
    if(polinom2.olderCoef != -1){
        setPolinom2 = 1;
        QMessageBox::information(this, "Успешно!" , "Второй полином задан!");
    }else setPolinom2 = 0;
}

void NumberPolinoms::on_push_ADD_PP_P_clicked()
{
    QString resultC;
    polinom result;
    if(setPolinom1&&setPolinom2){
        result = ADD_PP_P(polinom1, polinom2);
        resultC = printP(result);
        ui->answerText->setText(resultC);
    }else{
        QMessageBox::warning(this, "Ошибка!" , "Полином не был задан!");
    }
}

void NumberPolinoms::on_push_SUB_PP_P_clicked()
{
    QString resultC;
    polinom result;
    if(setPolinom1&&setPolinom2){
        result = SUB_PP_P(polinom1, polinom2);
        resultC = printP(result);
        ui->answerText->setText(resultC);
    }else{
        QMessageBox::warning(this, "Ошибка!" , "Полином не был задан!");
    }
}

void NumberPolinoms::on_push_MUL_PQ_P_clicked()
{
    QString resultC;
    numberR number1R;
    bool ok, ok2;
    long long int numberRI;
    unsigned long long numberRN;
    polinom result;
    if(setPolinom1){
        QString numberator = ui->polinomsRatioN->text();
        QString denominator = ui->polinomsRatioD->text();
        numberRI = numberator.toLongLong(&ok, 10);
        numberRN = denominator.toULongLong(&ok2, 10);
        if(ok&&ok2){
            number1R = XtoRArrayX(numberRI,numberRN);
            result = MUL_PQ_P(polinom1, number1R);
            resultC = printP(result);
            ui->answerText->setText(resultC);
        }else{
            QMessageBox::warning(this, "Ошибка!" , "При вводе исходных данных проихошла ошибка!");
        }
    }else{
        QMessageBox::warning(this, "Ошибка!" , "Полином не был задан!");
    }
}

void NumberPolinoms::on_push_MUL_Pxk_P_clicked()
{
    QString resultC;
    polinom result;
    bool ok;
    long long int xk;
    if(setPolinom1){
        QString xkS = ui->lineEditK->text();
        xk = xkS.toLongLong(&ok, 10);
        if(ok){
            result = MUL_Pxk_P(polinom1, xk);
            resultC = printP(result);
            ui->answerText->setText(resultC);
        }else{
             QMessageBox::warning(this, "Ошибка!" , "При вводе исходных данных проихошла ошибка!");
        }
    }else{
        QMessageBox::warning(this, "Ошибка!" , "Полином не был задан!");
    }
}

void NumberPolinoms::on_push_LED_P_Q_clicked()
{
    QString resultC;
    numberR result;
    if(setPolinom1){
        result = LED_P_Q(polinom1);
        resultC = printZP(result);
        ui->answerText->setText(resultC);
    }else{
        QMessageBox::warning(this, "Ошибка!" , "Полином не был задан!");
    }
}

void NumberPolinoms::on_faqP_clicked()
{
    QMessageBox::information(this, "Информация." , "Читайте readME!");
}

void NumberPolinoms::on_push_DEG_P_N_clicked()
{
    long long int result;
    if(setPolinom1){
        result = DEG_P_N(polinom1);
        ui->answerText->setText(QString::number(result));
    }else{
        QMessageBox::warning(this, "Ошибка!" , "Полином не был задан!");
    }
}

void NumberPolinoms::on_push_FAC_P_Q_clicked()
{
    QString resultC;
    numberR result;
    if(setPolinom1){
        result = FAC_P_Q(polinom1);
        resultC = printZP(result);
        ui->answerText->setText(resultC);
    }else{
        QMessageBox::warning(this, "Ошибка!" , "Полином не был задан!");
    }
}

void NumberPolinoms::on_push_MUL_PP_P_clicked()
{
    QString resultC;
    polinom result;
    if(setPolinom1&&setPolinom2){
        result = MUL_PP_P(polinom1, polinom2);
        resultC = printP(result);
        ui->answerText->setText(resultC);
    }else{
        QMessageBox::warning(this, "Ошибка!" , "Полином не был задан!");
    }
}

void NumberPolinoms::on_push_DIV_PP_P_clicked()
{
    QString resultC;
    polinom result;
    if(setPolinom1&&setPolinom2){
        result = DIV_PP_P(polinom1, polinom2);
        resultC = printP(result);
        ui->answerText->setText(resultC);
    }else{
        QMessageBox::warning(this, "Ошибка!" , "Полином не был задан!");
    }
}

void NumberPolinoms::on_push_MOD_PP_P_clicked()
{
    QString resultC;
    polinom result;
    if(setPolinom1&&setPolinom2){
        result = MOD_PP_P(polinom1, polinom2);
        resultC = printP(result);
        ui->answerText->setText(resultC);
    }else{
        QMessageBox::warning(this, "Ошибка!" , "Полином не был задан!");
    }
}

void NumberPolinoms::on_push_GCF_PP_P_clicked()
{
    QString resultC;
    polinom result;
    if(setPolinom1&&setPolinom2){
        result = GCF_PP_P(polinom1, polinom2);
        resultC = printP(result);
        ui->answerText->setText(resultC);
    }else{
        QMessageBox::warning(this, "Ошибка!" , "Полином не был задан!");
    }
}

void NumberPolinoms::on_push_DER_P_P_clicked()
{
    QString resultC;
    polinom result;
    if(setPolinom1){
        result = DER_P_P(polinom1);
        resultC = printP(result);
        ui->answerText->setText(resultC);
    }else{
        QMessageBox::warning(this, "Ошибка!" , "Полином не был задан!");
    }
}

void NumberPolinoms::on_push_NMR_P_P_clicked()
{
    QString resultC;
    numberR result;
    if(setPolinom1){
        result = LED_P_Q(polinom1);
        resultC = printZP(result);
        ui->answerText->setText(resultC);
    }else{
        QMessageBox::warning(this, "Ошибка!" , "Полином не был задан!");
    }
}
