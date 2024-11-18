SET FOREIGN_KEY_CHECKS = 0;

-- Tạo bảng `department`
CREATE TABLE department (
    name VARCHAR(255) PRIMARY KEY,
    description TEXT
);

-- Thêm dữ liệu vào bảng `department`
INSERT INTO department (name, description) VALUES ('Others', '');
INSERT INTO department (name, description) VALUES ('Dev', 'Dev');

-- Tạo bảng `employee`
CREATE TABLE employee (
    id VARCHAR(255) PRIMARY KEY,
    first_name VARCHAR(255),
    last_name VARCHAR(255),
    password VARCHAR(255),
    department VARCHAR(255),
    date_of_birth DATE,
    start_date_of_work DATE,
    status VARCHAR(255),
    is_enabled BOOLEAN NOT NULL DEFAULT 1,
    avatar TEXT,
    role VARCHAR(255),
    email VARCHAR(255) UNIQUE,
    phone_number VARCHAR(255),
    address TEXT,
    is_allow_password BOOLEAN NOT NULL DEFAULT 0,
    iri_right TEXT,
    iri_left TEXT,
    FOREIGN KEY (department) REFERENCES department(name)
);

-- Thêm dữ liệu vào bảng `employee`
INSERT INTO employee (id, first_name, last_name, password, department, date_of_birth, start_date_of_work, status, is_enabled, avatar, role, email, phone_number, address, is_allow_password, iri_right, iri_left) 
VALUES ('admin', NULL, NULL, '123456', NULL, NULL, NULL, 'Về', 1, NULL, 'ADMIN', 'admin@gmail.com', NULL, NULL, 0, NULL, NULL);

INSERT INTO employee (id, first_name, last_name, password, department, date_of_birth, start_date_of_work, status, is_enabled, avatar, role, email, phone_number, address, is_allow_password, iri_right, iri_left) 
VALUES ('1', 'Đông', 'Phạm', '123456', 'Others', '2024-11-06', '2024-11-06', 'OUT', 1, NULL, 'STAFF', NULL, '', '', 1, '', '');

-- Tạo bảng `attendance_event`
CREATE TABLE attendance_event (
    id INT AUTO_INCREMENT PRIMARY KEY,
    type_event VARCHAR(255),
    date_event DATE,
    time_event TIME,
    exception INT,
    session INT,
    employee_id VARCHAR(255),
    FOREIGN KEY (employee_id) REFERENCES employee(id)
);

-- Thêm dữ liệu vào `sqlite_sequence` (chỉ mang tính tham khảo, MySQL không dùng bảng này)
-- Vì MySQL không có sqlite_sequence, chúng ta không cần phần này.

-- Đặt lại khóa ngoại
SET FOREIGN_KEY_CHECKS = 1;
