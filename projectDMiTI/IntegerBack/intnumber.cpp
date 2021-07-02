#include "intnumber.h"
#include "ui_intnumber.h"
#include <QMessageBox>
#include <iostream>
#include "NaturalNumbera/generalNatNum.h"


NaturalNumber inputNatZ(bool &ok, QString &str){
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

numberZ inputZ(bool &ok, QString &str){
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

IntNumber::IntNumber(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::IntNumber)
{
    ui->setupUi(this);
}

IntNumber::~IntNumber()
{
    delete ui;
}

QString printZ(numberZ& number1, QString str){
    int i;
    QString a;
    if(number1.sign==1) str.append("-");
    for(i=number1.olderCoef-1; i>=0;--i){
        str.append(a.setNum(number1.arrayNum[i]));
    }
    return str;
}

QString printN(NaturalNumber& number1, QString str){
    int i;
    QString a;
    for(i=number1.olderCoef-1; i>=0;--i){
        str.append(a.setNum(number1.arrayNum[i]));
    }
    return str;
}

void IntNumber::on_backIntNum_clicked()
{
    this->close();      // Закрываем окно
    emit firstWindowI();
}

void IntNumber::on_push_ABS_Z_N_clicked()
{
    bool ok;
    QString resultI = "";
    NaturalNumber result;
    numberZ number1;
    QString firstNumberC = ui->firstInt->text();
    number1 = inputZ(ok, firstNumberC);
    if(ok){
        result = ABS_Z_N(number1);
        resultI = printN(result,resultI);
        ui->answerInt->setText(resultI);
    }else{
         QMessageBox::warning(this, "Ошибка!" , "При вводе исходных данных проихошла ошибка!");
    }
}

void IntNumber::on_push_POZ_Z_D_clicked()
{
    bool ok;
    numberZ number1;
    long long int resultI;
    QString firstNumberC = ui->firstInt->text();
    number1 = inputZ(ok, firstNumberC);
    if(ok){
        resultI = POZ_Z_D(number1);
        ui->answerInt->setText(QString::number(resultI));
    }else{
         QMessageBox::warning(this, "Ошибка!" , "При вводе исходных данных проихошла ошибка!");
    }
}

void IntNumber::on_push_MUL_ZM_Z_clicked()
{
    bool ok;
    QString resultI = "";
    numberZ result;
    numberZ number1;
    QString firstNumberC = ui->firstInt->text();
    number1 = inputZ(ok, firstNumberC);
    if(ok){
        result = MUL_ZM_Z(number1);
        resultI = printZ(result,resultI);
        ui->answerInt->setText(resultI);
    }else{
         QMessageBox::warning(this, "Ошибка!" , "При вводе исходных данных проихошла ошибка!");
    }
}

void IntNumber::on_push_TRANS_N_Z_clicked()
{
    QString resultI = "";
    bool ok;
    numberZ result;
    NaturalNumber number1;
    QString firstNumberC = ui->firstInt->text();
    number1 = inputNatZ(ok,firstNumberC);
    if(ok){
        result = TRANS_N_Z(number1);
        resultI = printZ(result,resultI);
        ui->answerInt->setText(resultI);
    }else{
         QMessageBox::warning(this, "Ошибка!" , "При вводе исходных данных проихошла ошибка!");
    }
}

void IntNumber::on_push_TRANS_Z_N_clicked()
{
    QString resultI = "";
    bool ok;
    NaturalNumber result;
    numberZ number1;
    QString firstNumberC = ui->firstInt->text();
     number1 = inputZ(ok, firstNumberC);
    if(ok){
        result = TRANS_Z_N(number1);
        resultI = printN(result,resultI);
        ui->answerInt->setText(resultI);
    }else{
         QMessageBox::warning(this, "Ошибка!" , "При вводе исходных данных проихошла ошибка!");
    }
}

void IntNumber::on_push_ADD_ZZ_Z_clicked()
{
    QString resultI = "";
    bool ok, ok2;
    numberZ number1Z, number2Z, result;
    QString firstNumberC = ui->firstInt->text();
    QString seconfNumberC = ui->secondInt->text();
    number1Z = inputZ(ok, firstNumberC);
    number2Z = inputZ(ok2, seconfNumberC);
    if(ok&&ok2){
        result = ADD_ZZ_Z(number1Z, number2Z);
        resultI = printZ(result,resultI);
        ui->answerInt->setText(resultI);
    }else{
         QMessageBox::warning(this, "Ошибка!" , "При вводе исходных данных проихошла ошибка!");
    }

}



void IntNumber::on_push_SUB_ZZ_Z_clicked()
{
    QString resultI = "";
    bool ok, ok2;
    numberZ number1Z, number2Z, result;
    NaturalNumber resultN;
    QString firstNumberC = ui->firstInt->text();
    QString seconfNumberC = ui->secondInt->text();
    number1Z = inputZ(ok, firstNumberC);
    number2Z = inputZ(ok2, seconfNumberC);
    if(ok&&ok2){
        result = SUB_ZZ_Z(number1Z,number2Z);
        resultI = printZ(result,resultI);
        ui->answerInt->setText(resultI);
    }else{
        QMessageBox::warning(this, "Ошибка!" , "При вводе исходных данных проихошла ошибка!");
    }
}

void IntNumber::on_push_MUL_ZZ_Z_clicked()
{
    QString resultI = "";
    bool ok, ok2;
    numberZ number1Z, number2Z, result;
    NaturalNumber resultN;
    QString firstNumberC = ui->firstInt->text();
    QString seconfNumberC = ui->secondInt->text();
    number1Z = inputZ(ok, firstNumberC);
    number2Z = inputZ(ok2, seconfNumberC);
    if(ok&&ok2){
        result = MUL_ZZ_Z(number1Z,number2Z);
        resultI = printZ(result,resultI);
        ui->answerInt->setText(resultI);
    }else{
         QMessageBox::warning(this, "Ошибка!" , "При вводе исходных данных проихошла ошибка!");
    }
}

void IntNumber::on_push_DIV_ZZ_Z_clicked()
{
    bool ok, ok2;
    numberZ number1Z, number2Z, result;
    QString resultI = "";
    QString firstNumberC = ui->firstInt->text();
    QString seconfNumberC = ui->secondInt->text();
    number1Z = inputZ(ok, firstNumberC);
    number2Z = inputZ(ok2, seconfNumberC);
    if(seconfNumberC[0] == "0") ok2 = 0;
    if(ok&&ok2){
        result = DIV_ZZ_Z(number1Z,number2Z);
        if(result.olderCoef == -1)  QMessageBox::warning(this, "Ошибка!" , "Деление на ноль невозможно!");
        else{
            resultI = printZ(result,resultI);
            ui->answerInt->setText(resultI);
        }
    }else{
         QMessageBox::warning(this, "Ошибка!" , "При вводе исходных данных проихошла ошибка!");
    }
}

void IntNumber::on_push_MOD_ZZ_Z_clicked()
{
    bool ok, ok2;
    QString resultI = "";
    numberZ number1Z, number2Z, result;
    QString firstNumberC = ui->firstInt->text();
    QString seconfNumberC = ui->secondInt->text();
    number1Z = inputZ(ok, firstNumberC);
    number2Z = inputZ(ok2, seconfNumberC);
    if(seconfNumberC[0] == "0") ok2 = 0;
    if(ok&&ok2){
        result = MOD_ZZ_Z(number1Z,number2Z);
        if(result.olderCoef == -1) QMessageBox::warning(this, "Ошибка!" , "Деление на ноль невозможно!");
        else{
            resultI = printZ(result,resultI);
            ui->answerInt->setText(resultI);
        }
    }else{
        QMessageBox::warning(this, "Ошибка!" , "При вводе исходных данных проихошла ошибка!");
    }
}

void IntNumber::on_faqI_clicked()
{
    QMessageBox::information(this, "Информация." , "Читайте readME!");
}
