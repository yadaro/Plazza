#ifndef MAINWIN
# define MAINWIN

#include <QApplication>
#include <QWidget>
#include <QtWidgets>
#include <QPushButton>
#include <QHBoxLayout>
#include <QGridLayout>

class MainWin: public QWidget
{
        Q_OBJECT
    public:
            MainWin();
            

 public slots:
        void browse();

    private:
            QPushButton         *phone_button;
            //QPushButton         *ip_button;
            //QPushButton         *mail_button;

            QPushButton         *browse_button;

            QProgressBar        *pbar;
            //QHBoxLayout *layout = new QHBoxLayout;
            QGridLayout *laygrid;
};

#endif /* !MAINWIN */