#ifndef SIKPLAYER_H
#define SIKPLAYER_H

#include <QMainWindow>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QTableWidget>
#include <QMediaPlaylist>

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
    QMediaPlaylist* playlist;
    void updateList(QStringList& playlist);
};
#endif // SIKPLAYER_H
