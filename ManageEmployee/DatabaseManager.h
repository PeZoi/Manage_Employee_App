#pragma once
#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>
#include <QString>
#include <QDebug>
#include <QMessageBox>

class DatabaseManager : public QObject
{
    Q_OBJECT

public:
    explicit DatabaseManager(QObject* parent = nullptr);
    ~DatabaseManager();

    bool connectToDatabase();
    void closeDatabase();
    bool executeCreate(const QString& queryStr);
    bool executeCreate(const QString& queryStr, const QMap<QString, QVariant>& params);
    QSqlQuery executeQuery(const QString& queryStr);
    bool checkExistAdmin();

private:
    
    QSqlDatabase db;
};
