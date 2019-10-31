#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QPushButton>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private slots:
    void addClick(); 				// this function call the midoperation function and set isAdd to true.
    void subClick();				// this function call the midoperation function and set isSub to true.
    void mulClick();				// this function call the midoperation function and set isMul to true.
    void divClick();				// this function call the midoperation function and set isDiv to true.
    void hexClick();				// this function channge the lcdNumber mode to hexadecimal mode. 
    void decClick();				// this function channge the lcdNumber mode to decimal mode.
    void equalClick();				// this function call the midoperation function.
    void clearClick();				// this function clear the memory and set all operation boolean to false.
    void b0Click();					// this function updates the lcdNumber display by multiplying the current value by 10 then adding 0
    void b1Click();					// this function updates the lcdNumber display by multiplying the current value by 10 then adding 1
    void b2Click();					// this function updates the lcdNumber display by multiplying the current value by 10 then adding 2
    void b3Click();					// this function updates the lcdNumber display by multiplying the current value by 10 then adding 3
    void b4Click();					// this function updates the lcdNumber display by multiplying the current value by 10 then adding 4
    void b5Click();					// this function updates the lcdNumber display by multiplying the current value by 10 then adding 5
    void b6Click();					// this function updates the lcdNumber display by multiplying the current value by 10 then adding 6
    void b7Click();					// this function updates the lcdNumber display by multiplying the current value by 10 then adding 7
    void b8Click();					// this function updates the lcdNumber display by multiplying the current value by 10 then adding 8
    void b9Click();					// this function updates the lcdNumber display by multiplying the current value by 10 then adding 9
    void bAClick();					// this function updates the lcdNumber display by multiplying the current value by 10 then adding 10
    void bBClick();					// this function updates the lcdNumber display by multiplying the current value by 10 then adding 11
    void bCClick();					// this function updates the lcdNumber display by multiplying the current value by 10 then adding 12
    void bDClick();					// this function updates the lcdNumber display by multiplying the current value by 10 then adding 13
    void bEClick();					// this function updates the lcdNumber display by multiplying the current value by 10 then adding 14
    void bFClick();					// this function updates the lcdNumber display by multiplying the current value by 10 then adding 15

public:
    void midOperation();			//this function checks the operation boolean. According to operation which has the value of TRUE				
									//set the secondNumber from lcdNumber, make the operation and assign its result to firstNumber			
									// and update the lcdNumber display.
									
    bool isOperationClickedBefore = false;		//it is true when first operation clicked.
    bool isAdd = false;
    bool isMul = false;
    bool isDiv = false;
    bool isSub = false;
    bool isDec = true;

    int firstNumber = 0;
    int secondNumber = 0;
};

#endif // MAINWINDOW_H
