#include "EmployeeRepository.h"


EmployeeRepository::EmployeeRepository() {
}

bool EmployeeRepository::add(EmployeeModel employee) {
	DatabaseManager::connectToDatabase();
	QString query = "INSERT INTO employee ("
		"id, first_name, last_name, password, department, "
		"date_of_birth, start_date_of_work, status, is_enabled, "
		"avatar, role, email, phone_number, address, is_allow_password, "
		"iri_right, iri_left) "
		"VALUES (:id, :first_name, :last_name, :password, :department, "
		":date_of_birth, :start_date_of_work, :status, :is_enabled, "
		":avatar, :role, :email, :phone_number, :address, :is_allow_password, "
		":iri_right, :iri_left);";

	QMap<QString, QVariant> params;
	params[":id"] = employee.getId();
	params[":first_name"] = employee.getFirstName();
	params[":last_name"] = employee.getLastName();
	params[":password"] = employee.getPassword();
	params[":department"] = employee.getDepartment().getName();
	params[":date_of_birth"] = employee.getDateOfBirth().toString("dd/MM/yyyy");
	params[":start_date_of_work"] = employee.getStartDateOfWork().toString("dd/MM/yyyy");
	params[":role"] = employee.getRole();
	params[":email"] = employee.getEmail().trimmed().isEmpty() ? QVariant() : employee.getEmail();
	params[":phone_number"] = employee.getPhoneNumber();
	params[":address"] = employee.getAddress();
	params[":is_enabled"] = employee.getIsEnabled();
	params[":is_allow_password"] = employee.getIsAllowPassword();
	params[":status"] = "Về";
	params[":avatar"] = employee.getAvatar().isEmpty() ? QVariant() : employee.getAvatar();
	params[":iri_right"] = employee.getIriRight();
	params[":iri_left"] = employee.getIriLeft();

	return DatabaseManager::executeCreate(query, params);
}

bool EmployeeRepository::update(EmployeeModel employee) {
	DatabaseManager::connectToDatabase();
	QString query = "UPDATE employee SET "
		"first_name = :first_name, "
		"last_name = :last_name, "
		"password = :password, "
		"department = :department, "
		"date_of_birth = :date_of_birth, "
		"start_date_of_work = :start_date_of_work, "
		"is_enabled = :is_enabled, "
		"email = :email, "
		"phone_number = :phone_number, "
		"address = :address, "
		"is_allow_password = :is_allow_password "
		"WHERE id = :id;";

	QMap<QString, QVariant> params;
	params[":id"] = employee.getId();
	params[":first_name"] = employee.getFirstName();
	params[":last_name"] = employee.getLastName();
	params[":password"] = employee.getPassword();
	params[":department"] = employee.getDepartment().getName();
	params[":date_of_birth"] = employee.getDateOfBirth().toString("dd/MM/yyyy");
	params[":start_date_of_work"] = employee.getStartDateOfWork().toString("dd/MM/yyyy");
	params[":email"] = employee.getEmail().trimmed().isEmpty() ? QVariant() : employee.getEmail();
	params[":phone_number"] = employee.getPhoneNumber();
	params[":address"] = employee.getAddress();
	params[":is_enabled"] = employee.getIsEnabled();
	params[":is_allow_password"] = employee.getIsAllowPassword();
	params[":avatar"] = employee.getAvatar().isEmpty() ? QVariant() : employee.getAvatar();

	return DatabaseManager::executeCreate(query, params);
}

bool EmployeeRepository::_delete(QString id) {
	DatabaseManager::connectToDatabase();
	QString query = "DELETE FROM employee WHERE id = :id";
	QMap<QString, QVariant> params;
	params[":id"] = id;

	return DatabaseManager::executeCreate(query, params);
}

QList<EmployeeModel> EmployeeRepository::getAll() {
	DatabaseManager::connectToDatabase();
	QString query = "SELECT * FROM employee WHERE role = 'STAFF'";
	QSqlQuery result = DatabaseManager::executeQuery(query);

	if (!result.isActive()) {
		qDebug() << "Query failed:" << result.lastError().text();
		return QList<EmployeeModel>();
	}
	QList<EmployeeModel> list;

	while (result.next()) {
		EmployeeModel employee = EmployeeModel();
		employee.setId(result.value("id").toString());
		employee.setFirstName(result.value("first_name").toString());
		employee.setLastName(result.value("last_name").toString());
		employee.setPassword(result.value("password").toString());

		DepartmentModel department;
		department.setName(result.value("department").toString());
		employee.setDepartment(department);

		employee.setDateOfBirth(QDate::fromString(result.value("date_of_birth").toString(), "dd/MM/yyyy"));
		employee.setStartDateOfWork(QDate::fromString(result.value("start_date_of_work").toString(), "dd/MM/yyyy"));

		employee.setStatus(result.value("status").toString());
		employee.setIsEnabled(result.value("is_enabled").toBool());
		employee.setAvatar(result.value("avatar").toString());
		employee.setRole(result.value("role").toString());
		employee.setEmail(result.value("email").toString());
		employee.setPhoneNumber(result.value("phone_number").toString());
		employee.setAddress(result.value("address").toString());
		employee.setIsAllowPassword(result.value("is_allow_password").toBool());
		employee.setIriRight(result.value("iri_right").toString());
		employee.setIriLeft(result.value("iri_left").toString());

		list.append(employee);
	}
	return list;

}

EmployeeModel EmployeeRepository::getById(QString id) {
	DatabaseManager::connectToDatabase();
	QString query = "SELECT * FROM employee WHERE id = :id";
	QMap<QString, QVariant> params;
	params[":id"] = id;
	QSqlQuery result = DatabaseManager::executeQuery2(query, params);

	if (!result.isActive()) {
		qDebug() << "Query failed:" << result.lastError().text();
		return EmployeeModel();
	}

	EmployeeModel employee = EmployeeModel();

	if (result.next()) {
		employee.setId(result.value("id").toString());
		employee.setFirstName(result.value("first_name").toString());
		employee.setLastName(result.value("last_name").toString());
		employee.setPassword(result.value("password").toString());

		DepartmentModel department;
		department.setName(result.value("department").toString());
		employee.setDepartment(department);

		employee.setDateOfBirth(QDate::fromString(result.value("date_of_birth").toString(), "dd/MM/yyyy"));
		employee.setStartDateOfWork(QDate::fromString(result.value("start_date_of_work").toString(), "dd/MM/yyyy"));

		employee.setStatus(result.value("status").toString());
		employee.setIsEnabled(result.value("is_enabled").toBool());
		employee.setAvatar(result.value("avatar").toString());
		employee.setRole(result.value("role").toString());
		employee.setEmail(result.value("email").toString());
		employee.setPhoneNumber(result.value("phone_number").toString());
		employee.setAddress(result.value("address").toString());
		employee.setIsAllowPassword(result.value("is_allow_password").toBool());
		employee.setIriRight(result.value("iri_right").toString());
		employee.setIriLeft(result.value("iri_left").toString());
		return employee;
	}
	else {
		return EmployeeModel();
	}

}

bool EmployeeRepository::toggleEnabled(QString id, bool checked) {
	DatabaseManager::connectToDatabase();
	QString query = "UPDATE employee SET is_enabled = :is_enabled WHERE id = :id;";

	QMap<QString, QVariant> params;
	params[":is_enabled"] = checked;
	params[":id"] = id;

	return DatabaseManager::executeCreate(query, params);
}

bool EmployeeRepository::changeAvatar(QString path, QString id) {
	QString query = "UPDATE employee SET avatar = :avatar WHERE id = :id";
	QMap<QString, QVariant> params;
	params[":id"] = id;
	params[":avatar"] = path;

	return DatabaseManager::executeCreate(query, params);
}

bool EmployeeRepository::signInAdmin(QString pass) {
	QString query = "SELECT COUNT(*) FROM employee WHERE role = 'ADMIN' AND password = :pass";
	QMap<QString, QVariant> params;
	params[":pass"] = pass;

	// Thực thi câu truy vấn
	QSqlQuery result = DatabaseManager::executeQuery2(query, params);

	if (!result.isActive()) {
		qDebug() << "Query failed:" << result.lastError().text();
		return false;
	}

	// Kiểm tra nếu có ít nhất một bản ghi khớp (COUNT(*) >= 1)
	if (result.next()) {
		int count = result.value(0).toInt();
		return count > 0;
	}

	return false;
}

QList<EmployeeModel> EmployeeRepository::getByDepartment(QString department) {
	QString query = "SELECT id, first_name, last_name, is_enabled FROM employee WHERE department = :department and role = 'STAFF'";
	QMap<QString, QVariant> params;
	params[":department"] = department;

	QSqlQuery result = DatabaseManager::executeQuery2(query, params);

	if (!result.isActive()) {
		qDebug() << "Query failed:" << result.lastError().text();
		return QList<EmployeeModel>();
	}
	QList<EmployeeModel> list;

	while (result.next()) {
		EmployeeModel employee = EmployeeModel();
		employee.setId(result.value("id").toString());
		employee.setFirstName(result.value("first_name").toString());
		employee.setLastName(result.value("last_name").toString());
		employee.setIsEnabled(result.value("is_enabled").toBool());

		list.append(employee);
	}
	return list;
}