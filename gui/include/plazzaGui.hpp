//
// EPITECH PROJECT, 2018
//
// File description:
//
//

#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include <QDir>
#include <QLineEdit>
#include <QScrollArea>
#include <utility>
#include <QMessageBox>
#include "include/Plazza.hpp"

class QComboBox;
class QLabel;
class QPushButton;
class QTableWidget;
class QTableWidgetItem;

class Window : public QWidget
{
	Q_OBJECT

public:
	Window(QWidget *parent = 0);
	void setNbrThreadMax(int);

private slots:
    	void _setFile();
	void _setCmd1();
	void _setCmd2();
	void _setCmd3();
	void _setBuild();

private:
	void showResult(const QString &commands);
	QComboBox *createComboBox(const QString &text = QString());
	void createFilesTable();

	//     QLineEdit *textComboBox;

	QLabel *_textFile;
	QLabel *_textCmd;
	QPushButton *_buttonFile;
	QPushButton *_buttonCmd1;
	QPushButton *_buttonCmd2;
	QPushButton *_buttonCmd3;
	QPushButton *_buttonBuild;
	QTableWidget *filesTable;
	std::string _fileCmd;
	Information _cmd;
	int _nbrThread;
};

void start(const int &nbrThreadMax, std::pair<std::string, int>);

#endif