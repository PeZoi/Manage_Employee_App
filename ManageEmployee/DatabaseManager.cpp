#include "DatabaseManager.h"
#include <QFile>

DatabaseManager::DatabaseManager(QObject* parent)
    : QObject(parent)
{
}

DatabaseManager::~DatabaseManager()
{
    closeDatabase();
}

bool DatabaseManager::connectToDatabase()
{
    QString dbName = "manage_employee_sqlite.db";
    QFile dbFile(dbName);

    // Kiểm tra nếu tệp cơ sở dữ liệu đã tồn tại
    bool databaseExists = dbFile.exists();

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(dbName);

    if (!db.open()) {
        qDebug() << "Failed to open database:" << db.lastError().text();
        return false;
    }

    if (!databaseExists) {
        QString createTableDepartmentQuery = "CREATE TABLE department (name TEXT PRIMARY KEY, description TEXT);";
        QString createTableEmployeeQuery = "CREATE TABLE employee (id TEXT PRIMARY KEY, first_name TEXT, last_name TEXT, password TEXT, department TEXT,date_of_birth TEXT,start_date_of_work TEXT, status TEXT, is_enabled BOOLEAN NOT NULL DEFAULT 1,avatar TEXT,role TEXT,email TEXT UNIQUE,phone_number TEXT,address TEXT, is_allow_password BOOLEAN NOT NULL DEFAULT 0, iri_right TEXT, iri_left TEXT,FOREIGN KEY(department) REFERENCES department(name)); ";
        executeCreate(createTableDepartmentQuery);
        executeCreate(createTableEmployeeQuery);
    }

    qDebug() << "Connected to database successfully.";
    return true;
}

void DatabaseManager::closeDatabase()
{
    if (db.isOpen()) {
        db.close();
        qDebug() << "Database closed.";
    }
}

bool DatabaseManager::executeCreate(const QString& queryStr, const QMap<QString, QVariant>& params) {
    QSqlQuery query(db);
    query.prepare(queryStr);

    for (auto it = params.constBegin(); it != params.constEnd(); ++it) {
        query.bindValue(it.key(), it.value());
    }

    if (!query.exec()) {
        qDebug() << "Failed to execute query:" << query.lastError().text();
        return false;
    }
    qDebug() << "Query executed successfully.";
    return true;
}


bool DatabaseManager::executeCreate(const QString& queryStr)
{
    QSqlQuery query(db);

    if (!query.exec(queryStr)) {
        qDebug() << "Failed to execute query:" << query.lastError().text();
        return false;
    }
    qDebug() << "Query executed successfully.";
    return true;
}

QSqlQuery DatabaseManager::executeQuery(const QString& queryStr) {
    QSqlQuery query(db);
    if (!query.exec(queryStr)) {
        qDebug() << "Query execution failed:" << query.lastError().text();
        return QSqlQuery(); 
    }
    return query;
}

bool DatabaseManager::checkExistAdmin() {
    QString queryString = "SELECT COUNT(*) FROM employee WHERE role = 'ADMIN';";
    QSqlQuery query = executeQuery(queryString);

    if (query.next()) {
        return query.value(0).toInt() > 0; // Nếu có ít nhất một tài khoản ADMIN
    }

    return false; // Nếu không có tài khoản ADMIN hoặc truy vấn thất bại
}

