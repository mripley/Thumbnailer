#ifndef THUMBNAILERDIALOG_H
#define THUMBNAILERDIALOG_H

#include <QDialog>

namespace Ui {
    class ThumbnailerDialog;
}

class ThumbnailerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ThumbnailerDialog(QWidget *parent = 0);
    ~ThumbnailerDialog();

private:
    Ui::ThumbnailerDialog *ui;
};

#endif // THUMBNAILERDIALOG_H
