#ifndef MYSTATUSWIDGET_H
#define MYSTATUSWIDGET_H

#include <QWidget>

namespace Ui {
class mystatusWidget;
}

class mystatusWidget : public QWidget
{
    Q_OBJECT

public:
    explicit mystatusWidget(QWidget *parent = nullptr);
    ~mystatusWidget();

private:
    Ui::mystatusWidget *ui;
    bool isplay;

public slots:
    void sendPlay();
    void sendStop();

signals:
    void Play();
    void Stop();
};

#endif // MYSTATUSWIDGET_H
