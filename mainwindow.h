#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QToolButton>
#include <QLineEdit>
#include <QMainWindow>
#include <QRadioButton>
#include <QGridLayout>
#include <QDialog>
#include<QPushButton>
#include<QFont>
#include<QSplitter>



class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);


    bool PDigits();
    void SetDigits(bool);

private:



    QGridLayout* defaultCalcDisplay;
    QGridLayout* simpleCalcDisplay;
    QGridLayout* engineeringCalcDisplay;
    QGridLayout* mainLayout;
    QWidget* defaultCalcWidget;
    QWidget* simpleCalcWidget;
    QWidget* engineeringCalcWidget;
    QWidget* mainWidget;
    QPushButton *addButton(const QString &text, const char *member);
    QPushButton *digitButtons[10];
    QPushButton* clearAllButton;
    void abortOperation();
    double memory=0;
    double sum=0;
    double factor=0;
    QString pendingAddop;
    QString pendingMLO;
    bool waitingForArg;
    bool digits_only = true;
    QLineEdit *outline;
    QRadioButton *simpleCalc;
    QRadioButton *engineeringCalc;
    QFont* font;
    QSplitter *splitter;
    void SimpleMode();
    void EngMode();
    void CreateDefaultCalc();
    void CreateSimpleCalc();
    void CreateEngineeringCalc();

public slots:
    void Change();
    void clearAll();
    void clearMemory();
    void readMemory();
    void setMemory();
    void addToMemory();
    void digitClicked();
    void equalClicked();
    void pointClicked();
    void additiveClicked();
    void unaryClicked();
    void multiplicativeClicked();


};
#endif // MAINWINDOW_H

