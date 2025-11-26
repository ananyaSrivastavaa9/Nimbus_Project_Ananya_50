Traffic Violation & Penalty Management System
Project by Ananya

Repository Name: Nimbus_Project_Ananya_50

Project Objective

The objective of this project is to develop a Traffic Violation & Penalty Management System that helps track violations, calculate fines, manage repeat offenses, and generate reports for traffic authorities.

Features Implemented
✔ 1. Add Violation Record

Enter license number

Enter offense description

Enter base fine

Marks the record as unpaid and first-time violation

✔ 2. Apply Repeat-Offender Penalties

Automatically increases fine if the same vehicle violates rules multiple times.

✔ 3. Mark Payment as Paid

Updates the selected vehicle’s payment status.

✔ 4. Summary Report

Displays:

License number

Violation

Fine

Payment status

Total revenue collected

✔ 5. Data Saving

Stores all records permanently in traffic_data.txt

Development Steps
1. Understanding Requirements

The problem requires:

Structures

File handling

Dynamic memory

Menu-driven system

2. Designing Functions
Function	Purpose
insertRecord()	Add new violation
updatePenalties()	Increase fine for repeat offenders
setPaymentStatus()	Mark fine as paid
showSummary()	Display all violations & revenue
saveToDisk()	Write data to text file
Files Included
File Name	Description
traffic.c	Main program source code
traffic_data.txt	Auto-generated data file
README.md	This project documentation
Output Screenshots

(Upload these to your repo)

Menu screenshot

Add violation screenshot

Paid update screenshot

Summary screenshot

traffic_data.txt screenshot

How to Run
On Nimbus or VS Code
gcc traffic.c -o traffic
./traffic

Submission Details

Platform: Nimbus

Repository: Nimbus_Project_Ananya_50

Deadline: 30 Nov 2025, 11:59 PM

✔ Declaration

This project is created by me and follows academic honesty.
