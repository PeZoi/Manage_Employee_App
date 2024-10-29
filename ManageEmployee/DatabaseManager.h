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

    static bool connectToDatabase();
    static void closeDatabase();
    static bool executeCreate(const QString& queryStr);
    static bool executeCreate(const QString& queryStr, const QMap<QString, QVariant>& params);
    static QSqlQuery executeQuery(const QString& queryStr);
    static QSqlQuery executeQuery2(const QString& queryStr, const QMap<QString, QVariant>& params);
    static bool checkExistAdmin();

private:
    static QSqlDatabase db;
};
