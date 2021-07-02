#include "numberq.h"
#include "ui_numberq.h"
#include <QMessageBox>
#include <QTextStream>
NumberQ::NumberQ(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NumberQ)
{
    ui->setupUi(this);
}

NumberQ::~NumberQ()
{
    delete ui;
}

NaturalNumber inputNatP(bool &ok, QString &str){
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

numberZ inputZP(bool &ok, QString &str){
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

QString printNQ(NaturalNumber& number1, QString str){
    int i;
    QString a;
    for(i=number1.olderCoef-1; i>=0;--i){
        str.append(a.setNum(number1.arrayNum[i]));
    }
    return str;
}

QString printZQ(numberZ& number1, QString str){
    int i;
    QString a;
    if(number1.sign==1) str.append('-');
    for(i=number1.olderCoef-1; i>=0;--i){
        str.append(a.setNum(number1.arrayNum[i]));
    }
    return str;
}

void NumberQ::on_backNumberQ_clicked()
{
    this->close();      // Закрываем окно
    emit firstWindowQ();
}

void NumberQ::on_push_RED_Q_Q_clicked()
{
    bool ok, ok2;
    numberR number1R, result;
    QString resultSI = "";
    QString resultSN = "";
    QString numberator = ui->numberatorRatio->text();
    QString denominator = ui->denominatorRatio->text();
    number1R.whole = inputZP(ok, numberator);
    number1R.natural = inputNatP(ok2, denominator);
    if(denominator[0] == "0") ok2 = 0;
    if(ok&&ok2){
        result = RED_Q_Q(number1R);
        resultSI = printZQ(result.whole, resultSI);
        resultSN = printNQ(result.natural, resultSN);
        ui->answerWhole->setText(resultSI);
        ui->answerNatural->setText(resultSN);
    }else{
        QMessageBox::warning(this, "Ошибка!" , "При вводе исходных данных проихошла ошибка!");
    }
}

void NumberQ::on_push_INT_Q_B_clicked()
{
    bool ok, ok2, result;
    QString numberator = ui->numberatorRatio->text();
    QString denominator = ui->denominatorRatio->text();
    numberR number1R;
    number1R.whole = inputZP(ok, numberator);
    number1R.natural = inputNatP(ok2, denominator);
    if(denominator[0] == "0") ok2 = 0;
    if(ok&&ok2){
        result = INT_Q_B(number1R);
        ui->answerWhole->setText(QString::number(result));
        ui->answerNatural->setText(QString::number(1));
    }else{
        QMessageBox::warning(this, "Ошибка!" , "При вводе исходных данных проихошла ошибка!");
    }
}

void NumberQ::on_push_TRANS_Z_Q_clicked()
{
    bool ok;
    QString resultZ, resultN;
    QString numberator = ui->numberatorRatio->text();
    numberR result;
    numberZ number1Z;
    number1Z = inputZP(ok, numberator);
    if(ok){
        result = TRANS_Z_Q(number1Z);
        resultZ = printZQ(result.whole,resultZ);
        resultN = printNQ(result.natural,resultN);
        ui->answerWhole->setText(resultZ);
        ui->answerNatural->setText(resultN);
    }else{
        QMessageBox::warning(this, "Ошибка!" , "При вводе исходных данных проихошла ошибка!");
    }
}

void NumberQ::on_push_TRANS_Q_Z_clicked()
{
    bool ok, ok2;
    QString resultZ;
    QString numberator = ui->numberatorRatio->text();
    QString denominator = ui->denominatorRatio->text();
    numberR number1R;
    numberZ result;
    number1R.whole = inputZP(ok, numberator);
    number1R.natural = inputNatP(ok2, denominator);
    if(denominator[0] == "0") ok2 = 0;
    if(ok&&ok2){
        result = TRANS_Q_Z(number1R);
        resultZ = printZQ(result,resultZ);
        ui->answerWhole->setText(resultZ);
        ui->answerNatural->setText("");
    }else{
        QMessageBox::warning(this, "Ошибка!" , "При вводе исходных данных проихошла ошибка!");
    }
}

void NumberQ::on_push_ADD_QQ_Q_clicked()
{
    bool ok, ok2, ok3, ok4;
    QString resultZ, resultN;
    QString numberator = ui->numberatorRatio->text();
    QString denominator = ui->denominatorRatio->text();
    QString numberator2 = ui->numberatorRatio2->text();
    QString denominator2 = ui->denominatorRatio2->text();
    numberR number1R, number2R , result;
    number1R.whole = inputZP(ok, numberator);
    number1R.natural = inputNatP(ok2, denominator);
    number2R.whole = inputZP(ok3, numberator2);
    number2R.natural = inputNatP(ok4, denominator2);
    if((denominator[0] == "0") || (denominator2[0] == "0")) ok2 = 0;
    if(ok&&ok2&&ok3&&ok4){
        result = ADD_QQ_Q(number1R, number2R);
        resultZ = printZQ(result.whole,resultZ);
        resultN = printNQ(result.natural,resultN);
        ui->answerWhole->setText(resultZ);
        ui->answerNatural->setText(resultN);
    }else{
        QMessageBox::warning(this, "Ошибка!" , "При вводе исходных данных проихошла ошибка!");
    }
}



void NumberQ::on_push_SUB_QQ_Q_clicked()
{
    bool ok, ok2, ok3, ok4;
    QString resultZ, resultN;
    QString numberator = ui->numberatorRatio->text();
    QString denominator = ui->denominatorRatio->text();
    QString numberator2 = ui->numberatorRatio2->text();
    QString denominator2 = ui->denominatorRatio2->text();
    numberR number1R, number2R , result;
    number1R.whole = inputZP(ok, numberator);
    number1R.natural = inputNatP(ok2, denominator);
    number2R.whole = inputZP(ok3, numberator2);
    number2R.natural = inputNatP(ok4, denominator2);
    if((denominator[0] == "0") || (denominator2[0] == "0")) ok2 = 0;
    if(ok&&ok2&&ok3&&ok4){
        result = SUB_QQ_Q(number1R, number2R);
        resultZ = printZQ(result.whole,resultZ);
        resultN = printNQ(result.natural,resultN);
        ui->answerWhole->setText(resultZ);
        ui->answerNatural->setText(resultN);
    }else{
        QMessageBox::warning(this, "Ошибка!" , "При вводе исходных данных проихошла ошибка!");
    }
}

void NumberQ::on_push_MUL_QQ_Q_clicked()
{
    bool ok, ok2, ok3, ok4;
    QString resultZ, resultN;
    QString numberator = ui->numberatorRatio->text();
    QString denominator = ui->denominatorRatio->text();
    QString numberator2 = ui->numberatorRatio2->text();
    QString denominator2 = ui->denominatorRatio2->text();
    numberR number1R, number2R , result;
    number1R.whole = inputZP(ok, numberator);
    number1R.natural = inputNatP(ok2, denominator);
    number2R.whole = inputZP(ok3, numberator2);
    number2R.natural = inputNatP(ok4, denominator2);
    if((denominator[0] == "0") || (denominator2[0] == "0")) ok2 = 0;
    if(ok&&ok2&&ok3&&ok4){
        result = MUL_QQ_Q(number1R, number2R);
        resultZ = printZQ(result.whole,resultZ);
        resultN = printNQ(result.natural,resultN);
        ui->answerWhole->setText(resultZ);
        ui->answerNatural->setText(resultN);
    }else{
        QMessageBox::warning(this, "Ошибка!" , "При вводе исходных данных проихошла ошибка!");
    }
}

void NumberQ::on_push_DIV_QQ_Q_clicked()
{
    bool ok, ok2, ok3, ok4;
    QString resultZ, resultN;
    QString numberator = ui->numberatorRatio->text();
    QString denominator = ui->denominatorRatio->text();
    QString numberator2 = ui->numberatorRatio2->text();
    QString denominator2 = ui->denominatorRatio2->text();
    numberR number1R, number2R , result;
    number1R.whole = inputZP(ok, numberator);
    number1R.natural = inputNatP(ok2, denominator);
    number2R.whole = inputZP(ok3, numberator2);
    number2R.natural = inputNatP(ok4, denominator2);
    if((denominator[0] == "0") || (denominator2[0] == "0")) ok2 = 0;
    if(ok&&ok2&&ok3&&ok4){
        if(numberator2[0] == "0") QMessageBox::warning(this, "Ошибка!" , "Деление на ноль невозможно!");
        else{
            result = DIV_QQ_Q(number1R, number2R);
            resultZ = printZQ(result.whole,resultZ);
            resultN = printNQ(result.natural,resultN);
            ui->answerWhole->setText(resultZ);
            ui->answerNatural->setText(resultN);
        }
    }else{
        QMessageBox::warning(this, "Ошибка!" , "При вводе исходных данных проихошла ошибка!");
    }
}

void NumberQ::on_faqR_clicked()
{
    QMessageBox::information(this, "Информация." , "Читайте readME!");
}
