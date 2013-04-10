#include "MainWindow.h"



MainWindow::MainWindow()  {
    //We need a scene and a view to do graphics in QT
    
    
    window = new QWidget;
    QLineEdit *lineEdit1 = new QLineEdit(this);
    QLineEdit *lineEdit2 = new QLineEdit(this);
    QLineEdit *lineEdit3 = new QLineEdit(this);
    QLabel *sizeLabel = new QLabel("Size",this);
    QLabel *turnLabel = new QLabel("Amount of Randomization",this);
    QLabel *seedLabel = new QLabel("Seed",this);
    QPushButton *startButton = new QPushButton("&Start",this);
    QPushButton *quitButton = new QPushButton("&Quit", this);
    QRadioButton *OutofPlaceButton = new QRadioButton("OutofPlace Heuristic", this);
    QRadioButton *ManhattanButton = new QRadioButton("Manhattan Heuristic", this);
    
    QFormLayout *formLayout = new QFormLayout;
    QHBoxLayout *HBoxLayout = new QHBoxLayout;
    QHBoxLayout *HBoxLayout2 = new QHBoxLayout;
    QVBoxLayout *VBoxLayout = new QVBoxLayout;
    HBoxLayout->addWidget(startButton);
    HBoxLayout->addWidget(quitButton);
    HBoxLayout2->addWidget(OutofPlaceButton);
    HBoxLayout2->addWidget(ManhattanButton);
    VBoxLayout->addLayout(HBoxLayout);
    VBoxLayout->addLayout(formLayout);
    VBoxLayout->addLayout(HBoxLayout2);
    formLayout->addRow(sizeLabel, lineEdit1);
    formLayout->addRow(turnLabel, lineEdit2);
    formLayout->addRow(seedLabel, lineEdit3);
    window->setLayout(VBoxLayout);
    connect(quitButton, SIGNAL(clicked()), this, SLOT(quit()));
    
       
}

void MainWindow::show() {

    //This is how we get our view displayed.
    window->show();
    
}

void MainWindow::quit() {

    exit(1);
}

MainWindow::~MainWindow()
{
    delete scene;
    delete view;
    delete window;
}

