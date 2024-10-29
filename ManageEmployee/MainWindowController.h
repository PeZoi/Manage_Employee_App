#pragma once
#include <QObject>
#include "MainWindow.h"
class MainWindowController : public QObject {
    Q_OBJECT

public:
    MainWindowController(MainWindow* view, QObject* parent = nullptr);

private:
    MainWindow view;
};

