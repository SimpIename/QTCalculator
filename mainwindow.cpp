#include "mainwindow.h"
#include <cmath>


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    setMinimumSize(370, 380);
    setMaximumSize(370, 380);
    simpleCalc = new QRadioButton(tr("Калькулятор"));
    simpleCalc->setChecked(1);
    engineeringCalc = new QRadioButton(tr("Инженерный калькулятор"));
    connect(simpleCalc, SIGNAL(toggled(bool)), SLOT(Change()));
    CreateDefaultCalc();
    CreateSimpleCalc();
    CreateEngineeringCalc();
    mainWidget = new QWidget(this);
    SimpleMode();
}


void MainWindow::CreateSimpleCalc(){
    QPushButton* point =      new QPushButton(tr("."), this);
    QPushButton* reverse =    new QPushButton(tr("1/x"), this);
    QPushButton* equal =      new QPushButton(tr("="), this);
    QPushButton* minus =      new QPushButton(tr("-"), this);
    QPushButton* squareRoot = new QPushButton(tr("Sqrt"), this);
    QPushButton* division =   new QPushButton(tr("/"), this);
    QPushButton* times =      new QPushButton(tr("*"), this);
    QPushButton* plus =       new QPushButton(tr("+"), this);
    connect(point,      SIGNAL(clicked()), SLOT(pointClicked()));
    connect(reverse,    SIGNAL(clicked()), SLOT(unaryClicked()));
    connect(equal,      SIGNAL(clicked()), SLOT(equalClicked()));
    connect(minus,      SIGNAL(clicked()), SLOT(additiveClicked()));
    connect(plus,       SIGNAL(clicked()), SLOT(additiveClicked()));
    connect(squareRoot, SIGNAL(clicked()), SLOT(unaryClicked()));
    connect(division,   SIGNAL(clicked()), SLOT(multiplicativeClicked()));
    connect(times,      SIGNAL(clicked()), SLOT(multiplicativeClicked()));
    const QSize BUTTON_SIZE = QSize(70, 70);
    point->     setFixedSize(BUTTON_SIZE);
    division->  setFixedSize(BUTTON_SIZE);
    times->     setFixedSize(BUTTON_SIZE);
    minus->     setFixedSize(BUTTON_SIZE);
    plus->      setFixedSize(BUTTON_SIZE);
    squareRoot->setFixedSize(BUTTON_SIZE);
    reverse->   setFixedSize(BUTTON_SIZE);
    equal->     setFixedSize(70,150);
    for (int i = 0; i < 10; ++i) {
        digitButtons[i] = new QPushButton(QString::number(i), this);
        connect(digitButtons[i],  SIGNAL(clicked()), SLOT(digitClicked()));
    }
    digitButtons[0]->setFixedSize(140,70);
    simpleCalcDisplay = new QGridLayout(this);
    simpleCalcDisplay->setSpacing(0);
    simpleCalcDisplay->setContentsMargins(0, 0, 0, 0);
    simpleCalcDisplay->addWidget(digitButtons[0],  6, 0, 1, 2);
    simpleCalcDisplay->addWidget(point,      6, 2);
    simpleCalcDisplay->addWidget(minus,      6, 3);
    simpleCalcDisplay->addWidget(division,   4, 3);
    simpleCalcDisplay->addWidget(times,      3, 3);
    simpleCalcDisplay->addWidget(reverse,    4, 4);
    simpleCalcDisplay->addWidget(plus,       5, 3);
    simpleCalcDisplay->addWidget(squareRoot, 3, 4);
    simpleCalcDisplay->addWidget(equal,      5, 4, 2, 1,Qt::AlignTop);
    for (int i = 1; i < 10; ++i){
        digitButtons[i]->setFixedSize(BUTTON_SIZE);
    }
    for (int i = 1; i < 10; ++i) {
        int row = ((9 - i) / 3) + 3;
        int column = ((i - 1) % 3);
        simpleCalcDisplay->addWidget(digitButtons[i], row, column);

    }
    simpleCalcWidget = new QWidget(this);
    simpleCalcWidget->setLayout(simpleCalcDisplay);
}


void MainWindow::CreateEngineeringCalc(){
    QPushButton *to2Button =     new QPushButton(tr("x\u00B2"), this);
    QPushButton *to3Button =     new QPushButton(QString::fromUtf8("x\u00B3"), this);
    QPushButton *logButton =     new QPushButton(tr("log"), this);
    QPushButton *kubsqrtButton = new QPushButton(QString::fromUtf8("\u00B3\u221A"), this);
    QPushButton *tanhButton =    new QPushButton(tr("tanh"), this);
    QPushButton *sinButton =     new QPushButton(tr("sin"), this);
    QPushButton *sinhButton =    new QPushButton(tr("sinh"), this);
    QPushButton *coshAllButton = new QPushButton(tr("cosh"), this);
    QPushButton *cosButton =     new QPushButton(tr("cos"), this);
    QPushButton *factButton =    new QPushButton(tr("n!"), this);
    QPushButton *expButton =     new QPushButton(QString::fromUtf8("e\u207F"), this);
    QPushButton *lnButton =      new QPushButton(tr("ln"), this);
    QPushButton *tanButton =     new QPushButton(tr("tan"), this);
    QPushButton *piButton =      new QPushButton(QString::fromUtf8("\u03C0"), this);
    QPushButton *toyButton =     new QPushButton(QString::fromUtf8("x\u207F"), this);
    QPushButton *ysqrtButton =   new QPushButton(QString::fromUtf8("\u207F\u221A"), this);
    connect(to2Button,     SIGNAL(clicked()), SLOT(unaryClicked()));
    connect(to3Button,     SIGNAL(clicked()), SLOT(unaryClicked()));
    connect(logButton,     SIGNAL(clicked()), SLOT(unaryClicked()));
    connect(kubsqrtButton, SIGNAL(clicked()), SLOT(unaryClicked()));
    connect(tanhButton,    SIGNAL(clicked()), SLOT(unaryClicked()));
    connect(sinButton,     SIGNAL(clicked()), SLOT(unaryClicked()));
    connect(sinhButton,    SIGNAL(clicked()), SLOT(unaryClicked()));
    connect(coshAllButton, SIGNAL(clicked()), SLOT(unaryClicked()));
    connect(cosButton,     SIGNAL(clicked()), SLOT(unaryClicked()));
    connect(factButton,    SIGNAL(clicked()), SLOT(unaryClicked()));
    connect(expButton,     SIGNAL(clicked()), SLOT(unaryClicked()));
    connect(lnButton,      SIGNAL(clicked()), SLOT(unaryClicked()));
    connect(tanButton,     SIGNAL(clicked()), SLOT(unaryClicked()));
    connect(piButton,      SIGNAL(clicked()), SLOT(digitClicked()));
    connect(toyButton,     SIGNAL(clicked()), SLOT(multiplicativeClicked()));
    connect(ysqrtButton,   SIGNAL(clicked()), SLOT(multiplicativeClicked()));
    splitter=new QSplitter(this);
    splitter->setOrientation(Qt::Orientation(1));
    QList<int> sizes={200,200,200,200};
    splitter->setSizes(sizes);
    const QSize BUTTON_SIZE = QSize(70, 70);
    sinhButton->   setFixedSize(BUTTON_SIZE);
    coshAllButton->setFixedSize(BUTTON_SIZE);
    tanhButton->   setFixedSize(BUTTON_SIZE);
    sinButton->    setFixedSize(BUTTON_SIZE);
    cosButton->    setFixedSize(BUTTON_SIZE);
    tanButton->    setFixedSize(BUTTON_SIZE);
    piButton->     setFixedSize(BUTTON_SIZE);
    factButton->   setFixedSize(BUTTON_SIZE);
    expButton->    setFixedSize(BUTTON_SIZE);
    lnButton->     setFixedSize(BUTTON_SIZE);
    logButton->    setFixedSize(BUTTON_SIZE);
    kubsqrtButton->setFixedSize(BUTTON_SIZE);
    to2Button->    setFixedSize(BUTTON_SIZE);
    to3Button->    setFixedSize(BUTTON_SIZE);
    toyButton->    setFixedSize(BUTTON_SIZE);
    ysqrtButton->  setFixedSize(BUTTON_SIZE);
    engineeringCalcDisplay = new QGridLayout(this);
    engineeringCalcDisplay->setSpacing(0);
    engineeringCalcDisplay->setContentsMargins(0, 0, 0, 0);
    engineeringCalcDisplay->addWidget(to2Button,     1, 0, 1, 1);
    engineeringCalcDisplay->addWidget(to3Button,     2, 0, 1, 1);
    engineeringCalcDisplay->addWidget(toyButton,     3, 0, 1, 1);
    engineeringCalcDisplay->addWidget(ysqrtButton,   4, 0, 1, 1);
    engineeringCalcDisplay->addWidget(sinhButton,    1, 1, 1, 1);
    engineeringCalcDisplay->addWidget(coshAllButton, 2, 1, 1, 1);
    engineeringCalcDisplay->addWidget(tanhButton,    3, 1, 1, 1);
    engineeringCalcDisplay->addWidget(kubsqrtButton, 4, 1, 1, 1);
    engineeringCalcDisplay->addWidget(sinButton,     1, 2, 1, 1);
    engineeringCalcDisplay->addWidget(cosButton,     2, 2, 1, 1);
    engineeringCalcDisplay->addWidget(tanButton,     3, 2, 1, 1);
    engineeringCalcDisplay->addWidget(piButton,      4, 2, 1, 1);
    engineeringCalcDisplay->addWidget(expButton,     1, 3, 1, 1);
    engineeringCalcDisplay->addWidget(lnButton,      2, 3, 1, 1);
    engineeringCalcDisplay->addWidget(logButton,     3, 3, 1, 1);
    engineeringCalcDisplay->addWidget(factButton,    4, 3, 1, 1);
    engineeringCalcDisplay->addWidget(splitter,      1, 3, 1, 1);
    engineeringCalcWidget = new QWidget(this);
    engineeringCalcWidget->setLayout(engineeringCalcDisplay);
}


void MainWindow::Change() {
    mainWidget->setParent(this);
    simpleCalcWidget->setParent(this);
    engineeringCalcWidget->setParent(this);
    if (!simpleCalc->isChecked()) {
        delete mainLayout;
        setWindowTitle(tr("Для инженеров"));
        setMinimumSize(640, 380);
        setMaximumSize(640, 380);
        EngMode();
    }
    else {
        delete mainLayout;
        setWindowTitle(tr("Обычный"));
        setMinimumSize(370, 380);
        setMaximumSize(370, 380);
        SimpleMode();
    }
}


void MainWindow::CreateDefaultCalc() {
    waitingForArg = 1;
    outline = new QLineEdit("0");
    outline->setReadOnly(true);
    outline->setAlignment(Qt::AlignRight);
    QFont font = outline->font();
    font.setPointSize(font.pointSize() + 8);
    outline->setFont(font);
    clearAllButton = new QPushButton(tr("C"), this);
    clearAllButton->setFixedSize(200,40);
    connect(clearAllButton, SIGNAL(clicked()), SLOT(clearAll()));
    defaultCalcDisplay = new QGridLayout(this);
    defaultCalcDisplay->setSpacing(0);
    defaultCalcDisplay->setContentsMargins(0, 0, 0, 0);
    defaultCalcDisplay->addWidget(outline,  0, 0, 2, 5);
    defaultCalcDisplay->addWidget(clearAllButton, 2, 4, 2, 1);
    defaultCalcDisplay->addWidget(simpleCalc, 2, 0, 1, 4);
    defaultCalcDisplay->addWidget(engineeringCalc, 3, 0, 1, 4);
    defaultCalcWidget = new QWidget(this);
    defaultCalcWidget->setLayout(defaultCalcDisplay);
}


void MainWindow::SimpleMode() {
    mainLayout = new QGridLayout;
    mainLayout->setSpacing(0);
    engineeringCalcWidget->hide();
    mainWidget->setLayout(mainLayout);
    setCentralWidget(mainWidget);
    centralWidget()->layout()->setContentsMargins(0, 0, 0, 0);
    mainLayout->addWidget(defaultCalcWidget, 0, 0, 1, 5);
    mainLayout->addWidget(simpleCalcWidget,  1, 0, 4, 5);
    clearAllButton->setFixedSize(200,40);
}

void MainWindow::EngMode() {
    mainLayout = new QGridLayout;
    mainLayout->setSpacing(0);
    mainLayout->addWidget(defaultCalcWidget, 0, 0, 1, 8);
    mainLayout->addWidget(engineeringCalcWidget,   1, 0, 4, 4);
    mainLayout->addWidget(simpleCalcWidget,  1, 4, 4, 4);
    mainWidget->setLayout(mainLayout);
    setCentralWidget(mainWidget);
    centralWidget()->layout()->setContentsMargins(0, 0, 0, 0);
    engineeringCalcWidget->show();
    clearAllButton->setFixedSize(405,40);
}


double fact (double n)
{
     if (n == 0) {
         return 1;
     }
     return n*fact(n-1);
}


void MainWindow::unaryClicked()
 {
     double arg = outline->text().toDouble();
     double result = 0.0;
     QPushButton *clickedButton = qobject_cast<QPushButton *>(sender());
     if(clickedButton==nullptr){
         return;
     }
     QString Oper = clickedButton->text();
     if (Oper == tr("1/x")) {
         if (arg == 0.0) {
             abortOperation();
             return;
         }
         result = 1.0 / arg;
     }
     else if (Oper == tr("log")) {
         if (arg < 0.0 | arg == 1) {
             abortOperation();
             return;
         }
         result = log10(arg);
     }
     else if (Oper == tr("\u00B3\u221A")) {
         result = pow(arg, 1.0 / 3.0);
     }
     else if (Oper == tr("x\u00B2")) {
         result = arg*arg;
     }
     else if (Oper == tr("x\u00B3")) {
        result = arg*arg*arg;
     }
     else if (Oper == tr("Sqrt")) {
         if (arg < 0.0) {
             abortOperation();
             return;
         }
         result = sqrt(arg);
     }
     else if (Oper == tr("n!")) {
        if (arg < 0.0 | arg != round(arg)) {
            abortOperation();
            return;
        }
        result = fact(arg);
     }
     else if (Oper == tr("sin")) {
        result = sin(arg);
     }
     else if (Oper == tr("cos")) {
        result = cos(arg);
     }
     else if (Oper == tr("tan")) {
        result = tan(arg);
     }
     else if (Oper == tr("e\u207F")) {
        result = exp(arg);
     }
     else if (Oper == tr("ln")) {
        if (arg < 0.0 | arg == 1) {
            abortOperation();
            return;
        }
        result = log(arg);
     }
     else if (Oper == tr("sinh")) {
         result = sinh(arg);
     }
     else if (Oper == tr("cosh")) {
         result = cosh(arg);
     }
     else if (Oper == tr("tanh")) {
         result = tanh(arg);
     }

     outline->setText(QString::number(result));
     waitingForArg = 1;
}


void MainWindow::additiveClicked()
 {
     QPushButton *clickedButton = qobject_cast<QPushButton *>(sender());
     if(clickedButton==nullptr){
         return;
     }
     double arg = outline->text().toDouble();
     QString Oper = clickedButton->text();
     bool calc=1;
     if (!pendingAddop.isEmpty()) {
         if (pendingAddop == tr("-")) {
             sum -= arg;
         } else if (pendingAddop == tr("+")) {
             sum += arg;
         } else if (pendingAddop == tr("/")) {
             if (arg == 0.0)
                 abortOperation();
             factor /= arg;
         } else if (pendingAddop == tr("*")) {

             factor *= arg;
         } else if (pendingAddop == tr("x\u207F")) {
             factor = pow(factor, arg);
         } else if (pendingAddop == tr("\u207F\u221A")) {
             factor = pow(factor, 1.0/(arg));
         }
             if(calc==0){
             abortOperation();
             }

         outline->setText(QString::number(sum));
     }
     if (!pendingMLO.isEmpty()) {
         if (pendingMLO == tr("-")) {
             sum -= arg;
         } else if (pendingMLO == tr("+")) {
             sum += arg;
         } else if (pendingMLO == tr("/")) {
             if (arg == 0.0)
                 abortOperation();
             factor /= arg;
         } else if (pendingMLO == tr("*")) {

             factor *= arg;
         } else if (pendingMLO == tr("x\u207F")) {
             factor = pow(factor, arg);
         } else if (pendingMLO == tr("\u207F\u221A")) {
             factor = pow(factor, 1.0/(arg));
         }
             if(calc==0){
             abortOperation();
             }

         outline->setText(QString::number(factor));
         arg = factor;
         factor = 0.0;
         pendingMLO.clear();
     }else {
        sum = arg;
        }

     pendingAddop = Oper;
     waitingForArg = 1;
}


void MainWindow::multiplicativeClicked()
{
    QPushButton *clickedButton = qobject_cast<QPushButton *>(sender());
    if(clickedButton==nullptr){
        return;
    }
    QString clickedOperator = clickedButton->text();
    double arg = outline->text().toDouble();
    double calc=1;
    if (!pendingMLO.isEmpty()) {
        if (pendingMLO == tr("-")) {
            sum -= arg;
        } else if (pendingMLO == tr("+")) {
            sum += arg;
        } else if (pendingMLO == tr("/")) {
            if (arg == 0.0)
                abortOperation();
            factor /= arg;
        } else if (pendingMLO == tr("*")) {

            factor *= arg;
        } else if (pendingMLO == tr("x\u207F")) {
            factor = pow(factor, arg);
        } else if (pendingMLO == tr("\u207F\u221A")) {
            factor = pow(factor, 1.0/(arg));
        }
            if(calc==0){
            abortOperation();
            }

        outline->setText(QString::number(factor));
    } else {
        factor = arg;
    }

    pendingMLO = clickedOperator;
    waitingForArg = 1;
}


void MainWindow::equalClicked()
{
    double arg = outline->text().toDouble();
    bool calc=1;

    if (!pendingMLO.isEmpty()) {
        if (pendingMLO == tr("-")) {
            sum -= arg;
        } else if (pendingMLO == tr("+")) {
            sum += arg;
        } else if (pendingMLO == tr("/")) {
            if (arg == 0.0)
                abortOperation();
            factor /= arg;
        } else if (pendingMLO == tr("*")) {

            factor *= arg;
        } else if (pendingMLO == tr("x\u207F")) {
            factor = pow(factor, arg);
        } else if (pendingMLO == tr("\u207F\u221A")) {
            factor = pow(factor, 1.0/(arg));
        }
            if(calc==0){
            abortOperation();
            }
        arg = factor;
        factor = 0.0;
        pendingMLO.clear();
    }
    if (!pendingAddop.isEmpty()) {
        if (pendingAddop == tr("-")) {
            sum -= arg;
        } else if (pendingAddop == tr("+")) {
            sum += arg;
        } else if (pendingAddop == tr("/")) {
            if (arg == 0.0)
                abortOperation();
            factor /= arg;
        } else if (pendingAddop == tr("*")) {

            factor *= arg;
        } else if (pendingAddop == tr("x\u207F")) {
            factor = pow(factor, arg);
        } else if (pendingAddop == tr("\u207F\u221A")) {
            factor = pow(factor, 1.0/(arg));
        }
            if(calc==0){
            abortOperation();
            }

        pendingAddop.clear();
     }else {
        sum = arg;
    }

    outline->setText(QString::number(sum));
    sum = 0.0;
    waitingForArg = 1;
}


void MainWindow::pointClicked()
 {
     if (waitingForArg)
         outline->setText("0");
     if (!outline->text().contains("."))
         outline->setText(outline->text() + tr("."));
     waitingForArg = 0;
 }


void MainWindow::abortOperation()
 {
     clearAll();
     outline->setText(tr("ERROR"));
 }


void MainWindow::addToMemory()
{
    equalClicked();
    memory += outline->text().toDouble();
}


void MainWindow::clearMemory()
{
    memory = 0.0;
}


void MainWindow::readMemory()
{
    outline->setText(QString::number(memory));
    waitingForArg = 1;
}


void MainWindow::setMemory()
{
    equalClicked();
    memory = outline->text().toDouble();
}


void MainWindow::clearAll()
{
    sum = 0.0;
    factor = 0.0;
    pendingAddop.clear();
    pendingMLO.clear();
    outline->setText("0");
    waitingForArg = 1;
}


void MainWindow::digitClicked()
 {
     QPushButton *clickedButton = qobject_cast<QPushButton *>(sender());
     if(clickedButton==nullptr){
         return;
     }
     int digitValue = clickedButton->text().toInt();
     QString clickedOperator = clickedButton->text();
     if (clickedOperator == "\u03C0") {
              double pi = 3.1415926535897932384626433832795;
              outline->clear();
              waitingForArg = 0;
              outline->setText( QString::number(pi));
     }

     if (outline->text() == "0" && digitValue == 0.0)
         return;

          if (waitingForArg) {
              outline->clear();
              waitingForArg = 0;
          }
          outline->setText(outline->text() + QString::number(digitValue));
 }
