#ifndef SIKPLAYER_H
#define SIKPLAYER_H

#include <QMainWindow>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QTableWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class SikPlayer; }
QT_END_NAMESPACE

class SikPlayer : public QMainWindow
{
    Q_OBJECT

public:
    SikPlayer(QWidget *parent = nullptr);
    ~SikPlayer();

protected:
    void enterEvent(QEvent*);

private:
    Ui::SikPlayer *ui;
    QStringList filelist;
    QVideoWidget* videoWidget;
    QTableWidget* fileBrowser;
    QMediaPlayer* player;
};
#endif // SIKPLAYER_H
