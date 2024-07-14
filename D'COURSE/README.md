# D'COURSE Project

**D'COURSE** is a C-based program designed to facilitate private tutoring for students. The program features three main roles:

- **Admin**: The provider and manager of the tutoring services.
- **Teacher**: The facilitator who teaches the students.
- **Student**: The customer who uses the tutoring services.

## Program Features

#### Admin Features
- **Admin Login**: Access admin features with a username and password.
- **View Student Data**: Display registered student data.
- **Add Education Levels**: Add education levels.
- **Add Learning Packages**: Add learning packages based on education levels (teacher + subject).
- **Add Learning Schedules**: Add learning schedules for students.
- **Calculate Earnings**: Calculate earnings for admin and teachers (40% admin, 60% teacher).
- **View Admin Earnings**: Display admin earnings.
- **Log Out**: Log out from the admin account.

#### Student Features
- **Student Login**: Access student account (maximum of 3 login attempts).
- **View HELPDESK**: Application usage guide.
- **View Learning Packages**: Display learning packages sorted by education levels.
- **Select Learning Package**: Choose a learning package.
- **Pay for Learning Package**: Pay for the chosen learning package.
- **Select Learning Schedule**: Choose a learning schedule.
- **Make Payment**: Complete the payment process.
- **View Feedback**: Check the reviews and feedback given by teachers.
- **Log Out**: Log out from the student account.

#### Teacher Features
- **Teacher Login**: Access teacher account.
- **View Student List**: Display students enrolled in the schedule.
- **Provide Feedback**: Give feedback to students.
- **View Salary**: Display teacher's earnings.
- **Log Out**: Log out from the teacher account.

## How to Use the Program

1. **Compile the Program**
   ```
   gcc -o dcourse dcourse.c
   ```

2. **Run the Program**
   ```
   ./dcourse
   ```

3. **Navigate the Menu**
   - Follow on-screen instructions to choose between admin, teacher, and student menus.

4. **Login and Registration**
   - Admin, teacher, and student must log in to access features. New students must register first.

## Directory Structure

```
D'COURSE/
└── dcourse.c        
README.md      
```

Enjoy using D'COURSE!
