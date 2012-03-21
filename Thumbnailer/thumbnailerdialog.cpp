#include "thumbnailerdialog.h"
#include "ui_thumbnailerdialog.h"

ThumbnailerDialog::ThumbnailerDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ThumbnailerDialog)
{
    ui->setupUi(this);
    filters.append("*.png");
    filters.append("*.jpg");
    filters.append("*.bmp");

    gridLayout = new QGraphicsGridLayout();
    scene = new QGraphicsScene();
    form = new QGraphicsWidget;
    ui->Canvas->setScene(scene);
    connect(ui->BrowseButton, SIGNAL(clicked()), this, SLOT(browseButtonClicked()));
    connect(ui->RunButton, SIGNAL(clicked()), this, SLOT(runButtonClicked()));

    form->setLayout(gridLayout);
    scene->addItem(form);
}

ThumbnailerDialog::~ThumbnailerDialog()
{
    delete ui;
}

void ThumbnailerDialog::browseButtonClicked(){
    QString directoryPath = QFileDialog::getExistingDirectory(this, "Select Directory", ".");
    ui->BrowseEdit->setText(directoryPath);
    qDebug(directoryPath.toAscii());
}

void ThumbnailerDialog::runButtonClicked(){
    qDebug("Run Button Clicked!");
    QString directoryPath = ui->BrowseEdit->text();
    batchScale(directoryPath);

}

void ThumbnailerDialog::batchScale(QString dir){
    QSize newSize(ui->XSizeSpinBox->value(), ui->YSizeSpinBox->value());
    QDir directory(dir);
    QStringList fileList = directory.entryList(filters, QDir::Files);
    QString finalDirectory = QString("%1x%2").arg(newSize.width()).arg(newSize.height());
    // make sure we were able to create the director
    if(!directory.mkdir(finalDirectory)){
        return;
    }
    QDir finalDir(dir);
    finalDir.cd(finalDirectory);

    qDebug(directory.absolutePath().toAscii());
    for(int i=0; i< fileList.size(); i++){
        QImage img(directory.absoluteFilePath(fileList.at(i)));
        img.scaled(newSize);
        //img.save(QString("%1").arg());
    }
}
