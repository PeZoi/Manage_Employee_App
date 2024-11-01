#pragma once
#include <QLabel>
#include <QTimer>
#include <QVBoxLayout>

class ErrorLabel : public QLabel {
	Q_OBJECT
public:
	explicit ErrorLabel(const QString& message, QWidget* parent = nullptr)
		: QLabel(message, parent) {
		setStyleSheet("background-color: #a32a2a; color: white;");
	}

	void showTemporary( QVBoxLayout* layout, int durationMs = 3000) {
		if (!layout) return;
		layout->insertWidget(0, this);

		QTimer::singleShot(durationMs, this, [this]() {
			this->hide();
			this->deleteLater();
			});
	}
};
