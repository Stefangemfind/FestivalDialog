#ifndef FESTIVALDIALOG_H
#define FESTIVALDIALOG_H

#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QRadioButton>
#include <QGroupBox>
#include <QLineEdit>
#include <QLabel>
#include <QVBoxLayout>
#include <QObject>
#include <QMessageBox>
#include <QApplication>
#include <QString>

#include <alsa/asoundlib.h>
#include <ncurses.h>
#include "/opt/festival-2.1/festival/src/include/festival.h"

class FestivalDialog : public QWidget
{
    Q_OBJECT

public slots:
    void speak();
    void quit();

public:
    FestivalDialog(QWidget *parent = 0);
    QString getRadioChoice();

private:
    QPushButton *exitButton;
    QPushButton *speakButton;

    QRadioButton *voice1;
    QRadioButton *voice2;
    QRadioButton *voice3;
    QRadioButton *voice4;
    QRadioButton *voice5;

    QGroupBox *group;

    QLineEdit *sentence;

};

#endif // FESTIVALDIALOG_H
