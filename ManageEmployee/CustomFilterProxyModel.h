#pragma once
#include <QSortFilterProxyModel>
#include <QModelIndex>
class CustomFilterProxyModel : public QSortFilterProxyModel {
	Q_OBJECT
public:
	CustomFilterProxyModel(QObject* parent = nullptr) : QSortFilterProxyModel(parent) {}

protected:
	// Ghi đè filterAcceptsRow để kiểm tra cả tên department và tên employee
	bool filterAcceptsRow(int source_row, const QModelIndex& source_parent) const override {
		// Lấy dữ liệu tên department
		QModelIndex departmentIndex = sourceModel()->index(source_row, 0, source_parent);
		QString departmentName = sourceModel()->data(departmentIndex).toString();

		// Duyệt qua các hàng con (employee) của department
		int rowCount = sourceModel()->rowCount(departmentIndex);
		for (int i = 0; i < rowCount; ++i) {
			QModelIndex employeeIndex = sourceModel()->index(i, 0, departmentIndex);
			QString employeeName = sourceModel()->data(employeeIndex).toString();

			// Kiểm tra xem có chứa filter text không
			if (employeeName.contains(filterRegExp()) || departmentName.contains(filterRegExp())) {
				return true;
			}
		}
		// Kiểm tra nếu department chứa filter text
		return departmentName.contains(filterRegExp());
	}
};


