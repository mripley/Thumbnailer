#ifndef THUMBNAILERDIALOG_H
#define THUMBNAILERDIALOG_H

#include <QDialog>
#include <QFileDialog>
#include <QGraphicsGridLayout>
#include <QGraphicsScene>
#include <QGraphicsWidget>
#include <QImage>
#include <QGraphicsPixmapItem>
#include <QGraphicsProxyWidget>

namespace Ui {
    class ThumbnailerDialog;
}

class ThumbnailerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ThumbnailerDialog(QWidget *parent = 0);
    ~ThumbnailerDialog();

public slots:
    void browseButtonClicked();
    void runButtonClicked();

private:
    Ui::ThumbnailerDialog *ui;

    void batchScale(QString dir);
    QStringList filters;
    QGraphicsGridLayout* gridLayout;
    QGraphicsScene* scene;
    QGraphicsWidget* form;
};

#endif // THUMBNAILERDIALOG_H
