#include "DialogFormLoginAdmin.h"
#include "ErrorLabel.h"
#include <QLinearGradient>
#include <QPalette>
#include <QShortcut>

DialogFormLoginAdmin::DialogFormLoginAdmin(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	QLinearGradient gradient(0, 0, 0, this->height());
	gradient.setColorAt(0.0, Qt::white);
	gradient.setColorAt(1.0, QColor("#87A8D2"));

	QPalette palette;
	palette.setBrush(QPalette::Window, gradient);
	this->setPalette(palette);
	this->setAutoFillBackground(true);

	ui.password->setEchoMode(QLineEdit::Password);

	QShortcut* shortcut = new QShortcut(QKeySequence(Qt::Key_Return), this);
	connect(shortcut, &QShortcut::activated, ui.login_2, &QPushButton::click);
	connect(ui.login_2, SIGNAL(clicked()), this, SLOT(handleLoginAdmin()));
	connect(ui.cancelButton, &QPushButton::clicked, this, [this]() {this->accept(); });
}

DialogFormLoginAdmin::~DialogFormLoginAdmin()
{}

void DialogFormLoginAdmin::handleLoginAdmin() {
	QString pass = ui.password->text();

	if (pass.trimmed().isEmpty()) {
		ErrorLabel* error = new ErrorLabel("  Please enter complete information.  ");
		error->showTemporary(ui.verticalLayout, 3000);
		this->adjustSize();
		return;
	}

	if (pass.trimmed().length() < 4) {
		ErrorLabel* error = new ErrorLabel("  Password must be at least 4 characters long.  ");
		error->showTemporary(ui.verticalLayout, 3000);
		this->adjustSize();
		return;
	}

	emit loginSuccessful(pass, this);
}

Ui::DialogFormLoginAdminClass DialogFormLoginAdmin::getUi() {
	return ui;
}