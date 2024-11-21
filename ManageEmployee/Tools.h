#pragma once

#include <QWidget>
#include "ui_Tools.h"

class Tools : public QWidget
{
	Q_OBJECT

public:
	Tools(QWidget *parent = nullptr);
	~Tools();

	Ui::ToolsClass* getUi();

private:
	Ui::ToolsClass *ui;
};
