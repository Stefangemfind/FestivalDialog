#include "festivaldialog.h"

FestivalDialog::FestivalDialog(QWidget *parent)
    : QWidget(parent)
{

    //Initialize festival
    //int heap_size = 210000;
    int heap_size = 5000000;
    int load_init_files = 1;
    festival_initialize(load_init_files,heap_size);

    //Text field
    QLabel *sentenceLabel = new QLabel(tr("Text to speak"));
    sentence = new QLineEdit;

    //Buttons
    speakButton = new QPushButton(tr("&Speak"));
    exitButton = new QPushButton(tr("&Exit"));

    //Signals and slots
    QObject::connect(speakButton, SIGNAL(clicked()), this, SLOT(speak()));
    QObject::connect(exitButton, SIGNAL(clicked()), this, SLOT(quit()));

    //Radio buttons
    voice1 = new QRadioButton(tr("cmu_us_awb_cg"));
    voice2 = new QRadioButton(tr("cmu_us_rms_cg"));
    voice3 = new QRadioButton(tr("cmu_us_slt_arctic_hts"));
    voice4 = new QRadioButton(tr("kal_diphone"));
    voice5 = new QRadioButton(tr("rab_diphone"));
    voice1->setChecked(true);

    //Vertical grid
    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addWidget(voice1);
    vbox->addWidget(voice2);
    vbox->addWidget(voice3);
    vbox->addWidget(voice4);
    vbox->addWidget(voice5);
    vbox->addStretch(1);

    //Radio button group
    group = new QGroupBox(tr("Choose a voice"));
    group->setLayout(vbox);

    //Set grid and layout
    QGridLayout *layout = new QGridLayout;
    layout->addWidget(group, 0, 0);
    layout->addWidget(sentenceLabel, 1, 0);
    layout->addWidget(sentence, 2, 0);
    layout->addWidget(speakButton, 3, 0);
    layout->addWidget(exitButton, 4, 0);

    setLayout(layout);

    setWindowTitle("FestivalDialog");

}



void FestivalDialog::speak(){

    if(sentence->text() == ""){
        QMessageBox::information(this, tr("Error"), tr("Please enter a sentence"));
        return;
    }else{
        const EST_String choice = getRadioChoice().toUtf8().constData();
        const EST_String sentenceString = sentence->text().toUtf8().constData();

        festival_eval_command(choice);
        festival_say_text(sentenceString);
        festival_wait_for_spooler();
    }

}

void FestivalDialog::quit(){

    QMessageBox messageBox;
    messageBox.setWindowTitle(tr("FestivalDialog"));
    messageBox.setText(tr("Do you really want to quit?"));
    messageBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    messageBox.setDefaultButton(QMessageBox::No);
    if(messageBox.exec() == QMessageBox::Yes){
        qApp->quit();
    }

}

QString FestivalDialog::getRadioChoice(){

    QString choice;

    if(voice1->isChecked()){
        choice = "(voice_cmu_us_awb_cg)";
    }
    if(voice2->isChecked()){
        choice = "(voice_cmu_us_rms_cg)";
    }
    if(voice3->isChecked()){
        choice = "(voice_cmu_us_slt_arctic_hts)";
    }
    if(voice4->isChecked()){
        choice = "(voice_kal_diphone)";
    }
    if(voice5->isChecked()){
        choice = "(voice_rab_diphone)";
    }

    return choice;

}
