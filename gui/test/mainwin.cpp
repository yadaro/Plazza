#include "mainwin.hpp"

MainWin::MainWin() : QWidget()
{
    setFixedSize(600, 400);

    phone_button = new QPushButton("Phone Number", this);
    browse_button = new QPushButton("Select a file", this);
    pbar = new QProgressBar(this);
    laygrid = new QGridLayout;
    QString directory;


    browse_button->setFont(QFont("Comic Sans MS", 20));
    QObject::connect(browse_button, SIGNAL(clicked()), this, SLOT(browse()));

    phone_button->setFont(QFont("Comic Sans MS", 20));
    phone_button->setIcon(QIcon("phone.png"));
    // phone_button->setGeometry(300,100,250,40);

    laygrid->addWidget(pbar, 2, 0);

    laygrid->addWidget(browse_button, 0, 0);

    laygrid->addWidget(phone_button, 1, 2);
    // pbar->setGeometry(50,300, 500,50);                      // SetGeometry(x, y, width, height);
    pbar->setValue(0);
    this->setLayout(laygrid);
}

void MainWin::browse()
{
    QFileDialog::getExistingDirectory(this, "Find Files", QDir::currentPath());
}