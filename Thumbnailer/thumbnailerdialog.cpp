#include "thumbnailerdialog.h"
#include "ui_thumbnailerdialog.h"

ThumbnailerDialog::ThumbnailerDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ThumbnailerDialog)
{
    ui->setupUi(this);
}

ThumbnailerDialog::~ThumbnailerDialog()
{
    delete ui;
}
