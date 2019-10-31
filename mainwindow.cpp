#include "mainwindow.h"
#include "ui_mainwindow.h"

/*
 * All comments are available in the header file.
 * Authors : Cemal Aytekin - Berke Esmer
 */

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    ui->lcdNumber->setDigitCount(9); //set the size of the int
    setWindowTitle(tr("Calculator[DEC]"));

    connect(ui->addButton, SIGNAL(clicked()), this, SLOT(addClick()));
    connect(ui->subButton, SIGNAL(clicked()), this, SLOT(subClick()));
    connect(ui->mulButton, SIGNAL(clicked()), this, SLOT(mulClick()));
    connect(ui->divButton, SIGNAL(clicked()), this, SLOT(divClick()));
    connect(ui->hexButton, SIGNAL(clicked()), this, SLOT(hexClick()));
    connect(ui->decButton, SIGNAL(clicked()), this, SLOT(decClick()));
    connect(ui->equalButton, SIGNAL(clicked()), this, SLOT(equalClick()));
    connect(ui->clearButton, SIGNAL(clicked()), this, SLOT(clearClick()));
    connect(ui->b0, SIGNAL(clicked()), this, SLOT(b0Click()));
    connect(ui->b1, SIGNAL(clicked()), this, SLOT(b1Click()));
    connect(ui->b2, SIGNAL(clicked()), this, SLOT(b2Click()));
    connect(ui->b3, SIGNAL(clicked()), this, SLOT(b3Click()));
    connect(ui->b4, SIGNAL(clicked()), this, SLOT(b4Click()));
    connect(ui->b5, SIGNAL(clicked()), this, SLOT(b5Click()));
    connect(ui->b6, SIGNAL(clicked()), this, SLOT(b6Click()));
    connect(ui->b7, SIGNAL(clicked()), this, SLOT(b7Click()));
    connect(ui->b8, SIGNAL(clicked()), this, SLOT(b8Click()));
    connect(ui->b9, SIGNAL(clicked()), this, SLOT(b9Click()));
    connect(ui->bA, SIGNAL(clicked()), this, SLOT(bAClick()));
    connect(ui->bB, SIGNAL(clicked()), this, SLOT(bBClick()));
    connect(ui->bC, SIGNAL(clicked()), this, SLOT(bCClick()));
    connect(ui->bD, SIGNAL(clicked()), this, SLOT(bDClick()));
    connect(ui->bE, SIGNAL(clicked()), this, SLOT(bEClick()));
    connect(ui->bF, SIGNAL(clicked()), this, SLOT(bFClick()));
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::midOperation(){
    if(isAdd){
        secondNumber = ui->lcdNumber->intValue();
        firstNumber +=secondNumber;
        ui->lcdNumber->display(firstNumber);
		
        isAdd=false;
    }

    else if(isMul){
        secondNumber = ui->lcdNumber->intValue();
        firstNumber *=secondNumber;
        ui->lcdNumber->display(firstNumber);

        isMul=false;
    }

    else if(isDiv){
        secondNumber = ui->lcdNumber->intValue();
        firstNumber /=secondNumber;
        ui->lcdNumber->display(firstNumber);

        isDiv=false;
    }

    else if(isSub){
        secondNumber = ui->lcdNumber->intValue();
        firstNumber -=secondNumber;
        ui->lcdNumber->display(firstNumber);

        isSub=false;
    }

    else{
        firstNumber = ui->lcdNumber->intValue();
    }
}

void MainWindow::addClick(){
   midOperation();

   isAdd=true;
   isOperationClickedBefore=true;
}

void MainWindow::subClick(){
    midOperation();

    isSub=true;
    isOperationClickedBefore=true;
}

void MainWindow::mulClick(){
    midOperation();

    isMul=true;
    isOperationClickedBefore=true;
}

void MainWindow::divClick(){
    midOperation();

    isDiv=true;
    isOperationClickedBefore=true;
}

void MainWindow::hexClick(){
    setWindowTitle(tr("Calculator[HEX]"));
    ui->lcdNumber->setHexMode();

    isDec = false;
}

void MainWindow::decClick(){
    setWindowTitle(tr("Calculator[DEC]"));
    ui->lcdNumber->setDecMode();

    isDec = true;
}

void MainWindow::equalClick(){
    midOperation();

    isOperationClickedBefore=true;
}

void MainWindow::clearClick(){
    firstNumber = 0;
    secondNumber = 0;
    ui->lcdNumber->display(0);

    isAdd = false;
    isMul = false;
    isDiv = false;
    isSub = false;
    isOperationClickedBefore = true;
}

void MainWindow::b0Click(){
    if(isOperationClickedBefore){
        ui->lcdNumber->display(0);
        isOperationClickedBefore = false;

        return;
    }

    int multiplier = 0;

    if(isDec)
        multiplier = 10;
    else
        multiplier = 16;

    int a = ui->lcdNumber->intValue();
    ui->lcdNumber->display(a*multiplier);
}

void MainWindow::b1Click(){
    if(isOperationClickedBefore){
        ui->lcdNumber->display(1);
        isOperationClickedBefore = false;

        return;
    }

    int multiplier = 0;

    if(isDec)
        multiplier = 10;
    else
        multiplier = 16;

    int a = ui->lcdNumber->intValue();
    ui->lcdNumber->display(a*multiplier+1);
}

void MainWindow::b2Click(){
    if(isOperationClickedBefore){
        ui->lcdNumber->display(2);
        isOperationClickedBefore = false;
        return;

    }

    int multiplier = 0;

    if(isDec)
        multiplier = 10;
    else
        multiplier = 16;

    int a = ui->lcdNumber->intValue();
    ui->lcdNumber->display(a*multiplier+2);
}

void MainWindow::b3Click(){
    if(isOperationClickedBefore){
        ui->lcdNumber->display(3);
        isOperationClickedBefore = false;

        return;
    }

    int multiplier = 0;

    if(isDec)
        multiplier = 10;
    else
        multiplier = 16;

    int a = ui->lcdNumber->intValue();
    ui->lcdNumber->display(a*multiplier+3);
}

void MainWindow::b4Click(){
    if(isOperationClickedBefore){
        ui->lcdNumber->display(4);
        isOperationClickedBefore = false;

        return;
    }

    int multiplier = 0;

    if(isDec)
        multiplier = 10;
    else
        multiplier = 16;

    int a = ui->lcdNumber->intValue();
    ui->lcdNumber->display(a*multiplier+4);
}

void MainWindow::b5Click(){
    if(isOperationClickedBefore){
        ui->lcdNumber->display(5);
        isOperationClickedBefore = false;

        return;
    }
    int multiplier = 0;

    if(isDec)
        multiplier = 10;
    else
        multiplier = 16;

    int a = ui->lcdNumber->intValue();
    ui->lcdNumber->display(a*multiplier+5);
}

void MainWindow::b6Click(){
    if(isOperationClickedBefore){
        ui->lcdNumber->display(6);
        isOperationClickedBefore = false;

        return;
    }

    int multiplier = 0;

    if(isDec)
        multiplier = 10;
    else
        multiplier = 16;

    int a = ui->lcdNumber->intValue();
    ui->lcdNumber->display(a*multiplier+6);
}

void MainWindow::b7Click(){
    if(isOperationClickedBefore){
        ui->lcdNumber->display(7);
        isOperationClickedBefore = false;

        return;
    }

    int multiplier = 0;

    if(isDec)
        multiplier = 10;
    else
        multiplier = 16;

    int a = ui->lcdNumber->intValue();
    ui->lcdNumber->display(a*multiplier+7);
}

void MainWindow::b8Click(){
    if(isOperationClickedBefore){
        ui->lcdNumber->display(8);
        isOperationClickedBefore = false;

        return;
    }

    int multiplier = 0;

    if(isDec)
        multiplier = 10;
    else
        multiplier = 16;

    int a = ui->lcdNumber->intValue();
    ui->lcdNumber->display(a*multiplier+8);
}

void MainWindow::b9Click(){
    if(isOperationClickedBefore){
        ui->lcdNumber->display(9);
        isOperationClickedBefore = false;

        return;
    }

    int multiplier = 0;

    if(isDec)
        multiplier = 10;
    else
        multiplier = 16;

    int a = ui->lcdNumber->intValue();
    ui->lcdNumber->display(a*multiplier+9);
}

void MainWindow::bAClick(){
    if(isOperationClickedBefore){
        ui->lcdNumber->display(10);
        isOperationClickedBefore = false;

        return;
    }

    int multiplier = 0;

    if(isDec)
        multiplier = 10;
    else
        multiplier = 16;

    int a = ui->lcdNumber->intValue();
    ui->lcdNumber->display(a*multiplier+10);
}

void MainWindow::bBClick(){
    if(isOperationClickedBefore){
        ui->lcdNumber->display(11);
        isOperationClickedBefore = false;

        return;
    }

    int multiplier = 0;

    if(isDec)
        multiplier = 10;
    else
        multiplier = 16;

    int a = ui->lcdNumber->intValue();
    ui->lcdNumber->display(a*multiplier+11);
}

void MainWindow::bCClick(){
    if(isOperationClickedBefore){
        ui->lcdNumber->display(12);
        isOperationClickedBefore = false;

        return;
    }

    int multiplier = 0;

    if(isDec)
        multiplier = 10;
    else
        multiplier = 16;

    int a = ui->lcdNumber->intValue();
    ui->lcdNumber->display(a*multiplier+12);
}

void MainWindow::bDClick(){
    if(isOperationClickedBefore){
        ui->lcdNumber->display(13);
        isOperationClickedBefore = false;

        return;
    }

    int multiplier = 0;

    if(isDec)
        multiplier = 10;
    else
        multiplier = 16;

    int a = ui->lcdNumber->intValue();
    ui->lcdNumber->display(a*multiplier+13);
}

void MainWindow::bEClick(){
    if(isOperationClickedBefore){
        ui->lcdNumber->display(14);
        isOperationClickedBefore = false;

        return;
    }

    int multiplier = 0;

    if(isDec)
        multiplier = 10;
    else
        multiplier = 16;

    int a = ui->lcdNumber->intValue();
    ui->lcdNumber->display(a*multiplier+14);
}

void MainWindow::bFClick(){
    if(isOperationClickedBefore){
        ui->lcdNumber->display(15);
        isOperationClickedBefore = false;

        return;
    }

    int multiplier = 0;

    if(isDec)
        multiplier = 10;
    else
        multiplier = 16;

    int a = ui->lcdNumber->intValue();
    ui->lcdNumber->display(a*multiplier+15);
}
