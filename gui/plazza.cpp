//
// EPITECH PROJECT, 2018
//
// File description:
//
//

#include <QtWidgets>
#include <iostream>
#include "include/plazzaGui.hpp"

Window::Window(QWidget *parent)
	: QWidget(parent),
		_fileCmd(""),
		_cmd((Information)-1)
{
    createFilesTable();
//     textComboBox = new QLineEdit();
    QGridLayout *mainLayout = new QGridLayout;
    _textFile = new QLabel(tr("Choose your file:"));
    _buttonFile = new QPushButton("File ...");

    _textCmd = new QLabel(tr("Choose your command:"));
    _buttonCmd1 = new QPushButton("PHONE");
    _buttonCmd2 = new QPushButton("EMAIL");
    _buttonCmd3 = new QPushButton("IP");

    _buttonBuild = new QPushButton("Build");
    //     _scrollBarCmd = new QScrollArea;
    connect(_buttonFile, &QAbstractButton::clicked, this, &Window::_setFile);
    connect(_buttonCmd1, &QAbstractButton::clicked, this, &Window::_setCmd1);
    connect(_buttonCmd2, &QAbstractButton::clicked, this, &Window::_setCmd2);
    connect(_buttonCmd3, &QAbstractButton::clicked, this, &Window::_setCmd3);
    connect(_buttonBuild, &QAbstractButton::clicked, this, &Window::_setBuild);

    // _scrollBarCmd->setBackgroundRole(QPalette::Dark);
    // _scrollBarCmd->setWidget(_textLabel);
    mainLayout->addWidget(_textFile, 1, 0);
    mainLayout->addWidget(_textCmd, 3, 0);
    //     mainLayout->addWidget(textComboBox, 1, 1, 1, 1);
    mainLayout->addWidget(_buttonFile, 1, 1, 2, 1);
    mainLayout->addWidget(_buttonCmd1, 3, 1, 2, 1);
    mainLayout->addWidget(_buttonCmd2, 3, 2, 2, 1);
    mainLayout->addWidget(_buttonCmd3, 3, 3, 2, 1);
    mainLayout->addWidget(_buttonBuild, 6, 1, 4, 1);
    mainLayout->addWidget(filesTable, 11, 0, 1, 4);
    setLayout(mainLayout);

    setWindowTitle(tr("Plazza"));
    resize(1200, 700);
}

void Window::showResult(const QString &)
{
    // for (int i = 0; i < commands.size(); ++i) {                // Boucle à modifier
        

        //QTableWidgetItem *phone = new QTableWidgetItem(PARSING RESULT);
        // phone->setFlags(phone->flags() ^ Qt::ItemIsEditable);
        //QTableWidgetItem *mail = new QTableWidgetItem(PARSING RESULT);
        // mail->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);
        // mail->setFlags(mail->flags() ^ Qt::ItemIsEditable);
        // QTableWidgetItem *ip = new QTableWidgetItem(PARSING RESULT);
        // ip->setFlags(ip->flags() ^ Qt::ItemIsEditable);

        // int row = filesTable->rowCount();                /**
        // filesTable->insertRow(row);
        // filesTable->setItem(row, 0, phone);                     ne pas modifier, affichage des result
        // filesTable->setItem(row, 1, mail);
        // filesTable->setItem(row, 2, ip);                            **/
    // }
}

void Window::createFilesTable()
{
	filesTable = new QTableWidget(0, 4);
	filesTable->setSelectionBehavior(QAbstractItemView::SelectRows);

	QStringList labels;
	labels << tr("phone") << tr("mail") << tr("ip") << tr("log");
	filesTable->setHorizontalHeaderLabels(labels);
	filesTable->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);
	filesTable->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
	filesTable->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Stretch);
	filesTable->horizontalHeader()->setSectionResizeMode(3, QHeaderView::Stretch);
	// filesTable->verticalHeader()->hide();
	// filesTable->setShowGrid(false);
}

void Window::_setFile()
{
	filesTable->setRowCount(0);

	// QString tmp = textComboBox->text(); // cmd sera la commande à parser

	QString tmp2 = QFileDialog::getOpenFileName(this,
		tr("Choose your file"), "./testU", tr("Files (*.json *.csv *.xml *.sql *.html *)"));

	_fileCmd = tmp2.toUtf8().constData();
	std::cout << _fileCmd << std::endl;
	// parsing de cmd
	// read + parsing files
	//     showResult(cmd);
}

void Window::_setCmd1()
{
	_cmd = PHONE_NUMBER;
}

void Window::_setCmd2()
{
	_cmd = EMAIL_ADDRESS;
}

void Window::_setCmd3()
{
	_cmd = IP_ADDRESS;
}

void Window::_setBuild()
{
	if (_fileCmd == "" || _cmd == -1) {
		QMessageBox msgBox;
		msgBox.setText("make a commande pls choose a file then press on\
your commnad then press on build !");
		msgBox.exec();
	} else {
		std::cout << "build" << std::endl;
		start(_nbrThread,
			std::make_pair(_fileCmd, (int)_cmd));
		// QTableWidgetItem *pCell = new QTableWidgetItem;
		// filesTable->setItem(0, 0, pCell);
		// pCell->setText("lol");

		// QTableWidgetItem *phone = new QTableWidgetItem;
		// phone->setFlags(phone->flags() ^ Qt::ItemIsEditable);
		// phone->setText(QString("lol"));
		// QTableWidgetItem *mail = new QTableWidgetItem(PARSING RESULT);
		// mail->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);
		// mail->setFlags(mail->flags() ^ Qt::ItemIsEditable);
		// QTableWidgetItem *ip = new QTableWidgetItem(PARSING RESULT);
		// ip->setFlags(ip->flags() ^ Qt::ItemIsEditable);

		// int row = filesTable->rowCount();
		// std::cout << row << std::endl;                
		// filesTable->insertRow(row);
		// filesTable->setItem(12, 0, phone); //     ne pas modifier, affichage des result

		// filesTable->setItem(row, 1, mail);
		// filesTable->setItem(row, 2, ip);

		QTableWidgetItem *newItem = new QTableWidgetItem;
		newItem->setFlags(newItem->flags() ^ Qt::ItemIsEditable);
		newItem->setText("ummm");
		// // std::cout << filesTable->rowCount() << std::endl;
		// // filesTable->insertRow(0);
		filesTable->setItem(0, 1, newItem);

		// filesTable->setItem(0, 1, new QTableWidgetItem("Hello"));
	}
}

void Window::setNbrThreadMax(int nbrThreadMax)
{
	_nbrThread = nbrThreadMax;
}