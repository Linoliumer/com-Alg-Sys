#include "anotherwindow.h"
#include "ui_anotherwindow.h"
#include <QMessageBox>
#include <iostream>
#include <QDesktopServices>
#include <QUrl>


NaturalNumber inputNat(bool &ok, QString &str){
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


AnotherWindow::AnotherWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AnotherWindow)
{
    ui->setupUi(this);
}

AnotherWindow::~AnotherWindow()
{
    delete ui;
}

QString printNN(NaturalNumber& number1, QString str){
    int i;
    QString a;
    for(i=number1.olderCoef-1; i>=0;--i){
        str.append(a.setNum(number1.arrayNum[i]));
    }
    return str;
}

void AnotherWindow::on_backNaturalNum_clicked()
{
    this->close();      // Закрываем окно
    emit firstWindow();
}

void AnotherWindow::on_push_COM_NN_D_clicked()
{
    bool ok, ok2;
    int flagCom;
    NaturalNumber number1, number2;
    QString firstNumberC = ui->lineEditFirstNatural->text();
    QString seconfNumberC = ui->lineEditSecondNatural->text();
    number1 = inputNat(ok, firstNumberC);
    number2 = inputNat(ok2, seconfNumberC);
    if(ok&&ok2){
        flagCom = COM_NN_D(number1, number2);
        ui->answerNatural->setText(QString::number(flagCom));

    }else{
        QMessageBox::warning(this, "Ошибка!" , "При вводе исходных данных проихошла ошибка!");
    }

}

void AnotherWindow::on_push_NZER_N_B_clicked()
{
    bool ok;
    NaturalNumber number1;
    QString firstNumberC = ui->lineEditFirstNatural->text();
    number1 = inputNat(ok, firstNumberC);
    if(ok){
        ok = NZER_N_B(number1);
        ui->answerNatural->setText(QString::number(ok));

    }else{
        QMessageBox::warning(this, "Ошибка!" , "При вводе исходных данных проихошла ошибка!");
    }
}

void AnotherWindow::on_push_ADD_1N_N_clicked()
{
    QString resultU = "";
    bool ok;
    NaturalNumber number1, result;
    QString firstNumberC = ui->lineEditFirstNatural->text();
    number1 = inputNat(ok,firstNumberC);
    if(ok){
        result = ADD_1N_N(number1);
        resultU = printNN(result, resultU);
        ui->answerNatural->setText(resultU);
    }else{
        QMessageBox::warning(this, "Ошибка!" , "При вводе исходных данных проихошла ошибка!");
    }
}

void AnotherWindow::on_push_ADD_NN_N_clicked()
{
    QString resultU = "";
    bool ok, ok2;
    NaturalNumber number1, number2, result;
    QString firstNumberC = ui->lineEditFirstNatural->text();
    QString seconfNumberC = ui->lineEditSecondNatural->text();
    number1 = inputNat(ok,firstNumberC);
    number2 = inputNat(ok2,seconfNumberC);
    if(ok&&ok2){
        result = ADD_NN_N(number1,number2);
        resultU = printNN(result, resultU);
        ui->answerNatural->setText(resultU);
    }else{
        QMessageBox::warning(this, "Ошибка!" , "При вводе исходных данных проихошла ошибка!");
    }
}

void AnotherWindow::on_push_SUB_NN_N_clicked()
{
    bool ok,ok2;
    QString resultU = "";
    NaturalNumber number1, number2, result;
    QString firstNumberC = ui->lineEditFirstNatural->text();
    QString seconfNumberC = ui->lineEditSecondNatural->text();
    number1 = inputNat(ok,firstNumberC);
    number2 = inputNat(ok2,seconfNumberC);
    if(ok&&ok2){
        result = SUB_NN_N(number1,number2);
        resultU = printNN(result, resultU);
        ui->answerNatural->setText(resultU);
    }else{
        QMessageBox::warning(this, "Ошибка!" , "При вводе исходных данных проихошла ошибка!");
    }
}

void AnotherWindow::on_push_MUL_ND_N_clicked()
{
    QString resultU = "";
    bool ok, ok2;
    int numberal;
    NaturalNumber number1, result;
    QString firstNumberC = ui->lineEditFirstNatural->text();
    QString numberlC = ui->lineEditNumeral->text();
    number1 = inputNat(ok,firstNumberC);
    numberal = numberlC.toInt(&ok2, 10);
    if((numberal>=10) || (numberal<0)){
        ok2 = 0;
    }
    if(ok&&ok2){
        result = MUL_ND_N(number1,numberal);
        resultU = printNN(result, resultU);
        ui->answerNatural->setText(resultU);
    }else{
        QMessageBox::warning(this, "Ошибка!" , "При вводе исходных данных проихошла ошибка!");
    }
}

void AnotherWindow::on_push_MUL_Nk_N_clicked()
{
    QString resultU = "";
    bool ok, ok2;
    int numberal;
    NaturalNumber number1, result;
    QString firstNumberC = ui->lineEditFirstNatural->text();
    QString numberlC = ui->lineEditNumeral->text();
    number1 = inputNat(ok,firstNumberC);
    numberal = numberlC.toInt(&ok2, 10);
    if(ok&&ok2){
        result = MUL_Nk_N(number1,numberal);
        resultU = printNN(result, resultU);
        ui->answerNatural->setText(resultU);
    }else{
        QMessageBox::warning(this, "Ошибка!" , "При вводе исходных данных проихошла ошибка!");
    }
}

void AnotherWindow::on_push_MUL_NN_N_clicked()
{
    QString resultU = "";
    bool ok, ok2;
    NaturalNumber number1, number2, result;
    QString firstNumberC = ui->lineEditFirstNatural->text();
    QString seconfNumberC = ui->lineEditSecondNatural->text();
    number1 = inputNat(ok,firstNumberC);
    number2 = inputNat(ok2,seconfNumberC);
    if(ok&&ok2){
        result = MUL_NN_N(number1, number2);
        resultU = printNN(result, resultU);
        ui->answerNatural->setText(resultU);
    }else{
        QMessageBox::warning(this, "Ошибка!" , "При вводе исходных данных проихошла ошибка!");
    }
}

void AnotherWindow::on_push_SUB_NDN_N_clicked()
{
    bool ok, ok2, ok3;
    QString resultU = "";
    int numberal;
    NaturalNumber number1, number2, result;
    QString firstNumberC = ui->lineEditFirstNatural->text();
    QString seconfNumberC = ui->lineEditSecondNatural->text();
    QString numberlC = ui->lineEditNumeral->text();
    number1 = inputNat(ok,firstNumberC);
    number2 = inputNat(ok2,seconfNumberC);
    numberal = numberlC.toInt(&ok3, 10);
    if((numberal>=10) || (numberal<0)){
        ok3 = 0;
    }
    if(ok&&ok2&&ok3){
        result = SUB_NDN_N(number1, number2, numberal);
        if(result.olderCoef == -1){
            QMessageBox::warning(this, "Ошибка!" , "Полученный ответ не будет являться натуральным числом!");
        }else{
            resultU = printNN(result, resultU);
            ui->answerNatural->setText(resultU);
        }

    }else{
        QMessageBox::warning(this, "Ошибка!" , "При вводе исходных данных проихошла ошибка!");
    }
}

void AnotherWindow::on_push_DIV_NN_Dk_clicked()
{
    bool ok, ok2;
    QString resultU = "";
    NaturalNumber number1, number2, result;
    QString firstNumberC = ui->lineEditFirstNatural->text();
    QString seconfNumberC = ui->lineEditSecondNatural->text();
    number1 = inputNat(ok,firstNumberC);
    number2 = inputNat(ok2,seconfNumberC);
    if((number2.olderCoef==1) && (number2.arrayNum[0] == 0)){
        ok2 = 0;
    }
    if(ok&&ok2){
        result = DIV_NN_Dk(number1, number2);
        resultU = printNN(result, resultU);
        ui->answerNatural->setText(resultU);
    }else{
        QMessageBox::warning(this, "Ошибка!" , "При вводе исходных данных проихошла ошибка!");
    }
}

void AnotherWindow::on_push_DIV_NN_N_clicked()
{
    bool ok, ok2;
    QString resultU = "";
    NaturalNumber number1, number2, result;
    QString firstNumberC = ui->lineEditFirstNatural->text();
    QString seconfNumberC = ui->lineEditSecondNatural->text();
    number1 = inputNat(ok,firstNumberC);
    number2 = inputNat(ok2,seconfNumberC);
    if((number2.olderCoef==1) && (number2.arrayNum[0] == 0)){
        ok2 = 0;
    }
    if(ok&&ok2){
        result = DIV_NN_N(number1, number2);
        resultU = printNN(result, resultU);
        ui->answerNatural->setText(resultU);
    }else{
        QMessageBox::warning(this, "Ошибка!" , "При вводе исходных данных проихошла ошибка!");
    }
}

void AnotherWindow::on_push_MOD_NN_N_clicked()
{
    bool ok, ok2;
    QString resultU = "";
    NaturalNumber number1, number2, result;
    QString firstNumberC = ui->lineEditFirstNatural->text();
    QString seconfNumberC = ui->lineEditSecondNatural->text();
    number1 = inputNat(ok,firstNumberC);
    number2 = inputNat(ok2,seconfNumberC);
    if((number2.olderCoef==1) && (number2.arrayNum[0] == 0)){
        ok2 = 0;
    }
    if(ok&&ok2){
        result = MOD_NN_N(number1, number2);
        resultU = printNN(result, resultU);
        ui->answerNatural->setText(resultU);
    }else{
        QMessageBox::warning(this, "Ошибка!" , "При вводе исходных данных проихошла ошибка!");
    }
}

void AnotherWindow::on_push_GCF_NN_N_clicked()
{
    bool ok, ok2;
    QString resultU = "";
    NaturalNumber number1, number2, result;
    QString firstNumberC = ui->lineEditFirstNatural->text();
    QString seconfNumberC = ui->lineEditSecondNatural->text();
    number1 = inputNat(ok,firstNumberC);
    number2 = inputNat(ok2,seconfNumberC);
    if(ok&&ok2){
        result = GCF_NN_N(number1, number2);
        resultU = printNN(result, resultU);
        ui->answerNatural->setText(resultU);
    }else{
        QMessageBox::warning(this, "Ошибка!" , "При вводе исходных данных проихошла ошибка!");
    }
}

void AnotherWindow::on_push_LCM_NN_N_clicked()
{
    QString resultU = "";
    bool ok, ok2;
    NaturalNumber number1, number2, result;
    QString firstNumberC = ui->lineEditFirstNatural->text();
    QString seconfNumberC = ui->lineEditSecondNatural->text();
    number1 = inputNat(ok,firstNumberC);
    number2 = inputNat(ok2,seconfNumberC);
    if(ok&&ok2){
        result = LCM_NN_N(number1, number2);
        resultU = printNN(result, resultU);
        ui->answerNatural->setText(resultU);
    }else{
        QMessageBox::warning(this, "Ошибка!" , "При вводе исходных данных проихошла ошибка!");
    }
}

void AnotherWindow::on_faqN_clicked()
{
    QMessageBox::information(this, "Информация." , "Читайте readME!");
}
