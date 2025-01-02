#include "DialogConfirm.h"

DialogConfirm::DialogConfirm(QString content, QWidget *parent)
	: QDialog(parent)
	, ui(new Ui::DialogConfirmClass())
{
	ui->setupUi(this);

	this->setWindowTitle(tr("Form Confirm"));

	QLinearGradient gradient(0, 0, 0, this->height());
	gradient.setColorAt(0.0, Qt::white);
	gradient.setColorAt(1.0, QColor("#87A8D2"));

	QPalette palette;
	palette.setBrush(QPalette::Window, gradient);
	this->setPalette(palette);
	this->setAutoFillBackground(true);

	ui->content->setText(content);

	connect(ui->btn_yes, &QPushButton::clicked, this, [this]() {accept(); });
	connect(ui->btn_no, &QPushButton::clicked, this, [this]() {reject(); });
}

DialogConfirm::~DialogConfirm()
{
	delete ui;
}
