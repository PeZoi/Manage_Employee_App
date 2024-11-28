CREATE TABLE IF NOT EXISTS department (
    name VARCHAR(255) PRIMARY KEY,
    description TEXT
);

INSERT IGNORE INTO department (name, description)
VALUES ('Others', '');

CREATE TABLE IF NOT EXISTS employee (
    id VARCHAR(255) PRIMARY KEY,
    first_name VARCHAR(255),
    last_name VARCHAR(255),
    password VARCHAR(255),
    department VARCHAR(255),
    date_of_birth VARCHAR(255),
    start_date_of_work VARCHAR(255),
    status VARCHAR(255),
    is_enabled BOOLEAN NOT NULL DEFAULT 1,
    avatar TEXT,
    role VARCHAR(255),
    email VARCHAR(255),
    phone_number VARCHAR(255),
    address TEXT,
    is_allow_password BOOLEAN NOT NULL DEFAULT 0,
    iri_right TEXT,
    iri_left TEXT,
    FOREIGN KEY (department) REFERENCES department(name)
);

CREATE TABLE IF NOT EXISTS attendance_event (
    id INT AUTO_INCREMENT PRIMARY KEY,
    type_event VARCHAR(255),
    date_event VARCHAR(255),
    time_event VARCHAR(255),
    exception INT,
    session INT,
    employee_id VARCHAR(255),
    FOREIGN KEY (employee_id) REFERENCES employee(id)
);
