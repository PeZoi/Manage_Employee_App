#include "DialogFormException.h"
#include "ExceptionModel.h"
#include "ErrorLabel.h"
#include <QPushButton>
#include <QTime>

DialogFormException::DialogFormException(QWidget *parent)
	: QDialog(parent)
	, ui(new Ui::DialogFormExceptionClass())
{
	ui->setupUi(this);

	ui->paid_hours->setDisplayFormat("HH:mm");
	ui->paid_hours->setTime(QTime(0, 0));

	ui->paid_coefficient->setValue(1);
	ui->paid_coefficient->setSingleStep(0.1);
	ui->paid_coefficient->setMaximum(3.0);
	ui->paid_coefficient->setMinimum(0.0);

	ui->work_coefficient->setSingleStep(0.1);
	ui->work_coefficient->setMaximum(10.0);
	ui->work_coefficient->setMinimum(0.0);

	QLinearGradient gradient(0, 0, 0, this->height());
	gradient.setColorAt(0.0, Qt::white);
	gradient.setColorAt(1.0, QColor("#87A8D2"));

	QPalette palette;
	palette.setBrush(QPalette::Window, gradient);
	this->setPalette(palette);
	this->setAutoFillBackground(true);

	connect(ui->submit, SIGNAL(clicked()), this, SLOT(handleSubmit()));
	connect(ui->cancelButton, &QPushButton::clicked, this, &DialogFormException::onClickCancel);
}

DialogFormException::~DialogFormException()
{
	delete ui;
}

void DialogFormException::onClickCancel() {
	this->deleteLater();
}


void DialogFormException::handleSubmit() {
	QString name = ui->exception_name->text();
	QString paidHours = ui->paid_hours->time().toString("HH:mm");
	float paidCoefficient = ui->paid_coefficient->value();
	float workCoefficient = ui->work_coefficient->value();
	bool isCalculate = ui->is_calculate->isChecked();

	if (name.isEmpty()) {
		ErrorLabel* error = new ErrorLabel("  Please fill in the name field");
		error->showTemporary(ui->verticalLayout, 3000);
		return;
	}

	ExceptionModel exception = ExceptionModel(0, name, paidHours, paidCoefficient, workCoefficient, isCalculate);

	emit submit(exception, isEditMode_exception, this);
}

void DialogFormException::setMode(bool _isEditMode) {
	isEditMode_exception = _isEditMode;
}

void DialogFormException::setValue(ExceptionModel exception) {
	QTime paidHours = QTime::fromString(exception.getPaidHours(), "HH:mm");
	ui->exception_name->setText(exception.getName());
	ui->paid_hours->setTime(paidHours);
	ui->paid_coefficient->setValue(exception.getPaidCoefficient());
	ui->work_coefficient->setValue(exception.getWorkCoefficient());
	ui->is_calculate->setChecked(exception.getIsCaculate());
}

Ui::DialogFormExceptionClass* DialogFormException::getUi() {
	return ui;
}
