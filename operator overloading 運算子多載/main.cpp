#include<iostream>
#include "Time.cpp"
#include "DateTime.cpp"
using namespace std;

int main() {
	//	----------------------- Task 1 ---------------------------

	Time t1;
	Time t2 = Time();

	//	Q2 Getters and Setters
	t1.setSecond(59);
	t1.setMinute(59);
	t1.setHour(23);

	if (t1.getSecond() == 59 && t1.getMinute() == 59 && t1.getHour() == 23) {
		cout << "Task 1: Q2 Passed at t1(23,59,59)" << endl;
	}
	else {
		cout << "Task 1: Q2 Failed at t1(23,59,59)!" << endl;
	}

	//	Q3 Add function
	t1.add(2, "second"); // should return 0h0m1s

	if (t1.getSecond() == 1 && t1.getMinute() == 0 && t1.getHour() == 0) {
		cout << "Task 1: Q3 Passed at t1.add(2, 'second')!" << endl;
	}
	else {
		cout << "Task 1: Q3 Failed at t1.add(2, 'second')!" << endl;
	}

	t1.add(3, "minute");

	t1.add(2, "hour");

	if (t1.getSecond() == 1 && t1.getMinute() == 3 && t1.getHour() == 2) {
		cout << "Task 1: Q3 Passed at t1.add(2, 'hour')!" << endl;
	}
	else {
		cout << "Task 1: Q3 Failed at t1.add(2, 'hour')!" << endl;
	}

	t1.add(-3, "hour");
	t1.add(-4, "second");


	//	Q4 Duration function
	Time t3(23, 2, 50);

	if (t1.duration(t3) == 7) {
		cout << "Task 1: Q4 Passed!" << endl;
	}
	else {
		cout << "Task 1: Q4 Failed at t1.duration(t3)!" << endl;
	}


	//	Q5 Compare 2 Time
	Time t4 = Time();

	if (t4 == t2) {
		cout << "Task 1: Q5 compared t4 == t2 Passed!" << endl;
	}
	else {
		cout << "Task 1: Q5 compared t4 == t2 Failed!" << endl;
	}


	//	Q6  ++ -- operators
	++t1;
	t1 += 1;
	t1++;

	t2--;
	t2 -= 5;
	--t2;

	if (t2.getSecond() == 53 && t2.getMinute() == 59 && t1.getHour() == 23) {
		cout << "Task 1: Q6 -- t2 Passed!" << endl;
	}
	else {
		cout << "Task 1: Q6 -- t2 Failed!" << endl;
	}

	//	Q7 Gap between 2 Times
	t1.add(56, "minute");

	int b = t2 - t1;

	if (b == 53) {
		cout << "Task 1: Q7 Passed!" << endl;
	}
	else {
		cout << "Task 1: Q7 Failed!" << endl;
	}


	//	----------------------- Task 2 ---------------------------
	
	//	Q2 Getters and Setters
	DateTime d1;
	DateTime d2(2, 2, 2023);
	DateTime d3(5, 10, 2023, t2);
	DateTime d5;
	d5.setDate(20);
	d5.setMonth(2);
	d5.setYear(2024);
	d5.setHour(1);
	d5.setMinute(1);
	d5.setSecond(1);

	if (d2.getDate() == 2 && d2.getMonth() == 2 && d2.getYear() == 2023 && d2.getHour() == 0 && d2.getMinute() == 0 && d2.getSecond() == 0) {
		cout << "Task 2: Q2 case d2(2,2,2023) Passed!" << endl;
	}
	else {
		cout << "Task 2: Q2 case d2(2,2,2023) Failed!" << endl;
	}

	if (d5.getDate() == 20 && d5.getMonth() == 2 && d5.getYear() == 2024 && d5.getHour() == 1 && d5.getMinute() == 1 && d5.getSecond() == 1) {
		cout << "Task 2: Q2 case 20/2/2024 1h1m1s Passed!" << endl;
	}
	else {
		cout << "Task 2: Q2 case 20/2/2024 1h1m1s Failed!" << endl;
	}
	
	//	Q3 add function
	d1.add(120, "year"); 				// should be 1/1/2020 0h0m0s
	d2.add(2, "month");


	if (d1.getDate() == 1 && d1.getMonth() == 1 && d1.getYear() == 2020 && d1.getHour() == 0 && d1.getMinute() == 0 && d1.getSecond() == 0) {
		cout << "Task 2: Q3 case d1() Passed!" << endl;
	}
	else {
		cout << "Task 2: Q3 case d1() Failed!" << endl;
	}

	if (d2.getDate() == 2 && d2.getMonth() == 4 && d2.getYear() == 2023 && d2.getHour() == 0 && d2.getMinute() == 0 && d2.getSecond() == 0) {
		cout << "Task 2: Q3 case d2(2,4,2023) Passed!" << endl;
	}
	else {
		cout << "Task 2: Q3 case d2(2,4,2023) Failed!" << endl;
	}

	
	//	Q4 dayOfMonth function

	DateTime d6(10, 2, 2023);
	DateTime d7(30, 12, 2023);

	if (d6.dateOfMonth() == 28) {
		cout << "Task 2: Q4 case d6(10, 2, 2023) Passed!" << endl;
	}
	else {
		cout << "Task 2: Q4 case d6(10, 2, 2023) Failed!" << endl;
	}

	if (d7.dateOfMonth() == 31) {
		cout << "Task 2: Q4 case d7(30, 12, 2023) Passed!" << endl;
	}
	else {
		cout << "Task 2: Q4 case d7(30, 12, 2023) Failed!" << endl;
	}

	//	Q5 dateOfYear function
	DateTime d9(2, 2, 2023);
	DateTime d10(31, 12, 2023);

	if (d9.dateOfYear() == 33) {
		cout << "Task 2: Q5 case d9(2, 2, 2023) Passed!" << endl;
	}
	else {
		cout << "Task 2: Q5 case d9(2, 2, 2023) Failed!" << endl;
	}

	if (d10.dateOfYear() == 365) {
		cout << "Task 2: Q5 case d10(31, 12, 2023) Passed!" << endl;
	}
	else {
		cout << "Task 2: Q5 case d10(31, 12, 2023) Failed!" << endl;
	}

	//	Q6 dateOfWeek
	DateTime d13(2, 5, 2023);
	DateTime d14(1, 1, 2023);
	
	if (d13.dateOfWeek() == "Tuesday") {
		cout << "Task 2: Q6 case d13(2, 5, 2023) Passed!" << endl;
	}
	else {
		cout << "Task 2: Q6 case d13(2, 5, 2023) Failed!" << endl;
	}
	if (d14.dateOfWeek() == "Sunday") {
		cout << "Task 2: Q6 case d14(1, 1, 2023) Passed!" << endl;
	}
	else {
		cout << "Task 2: Q6 case d14(1, 1, 2023) Failed!" << endl;
	}

	//	Q7 WeekOfYear

	if (d14.weekOfYear() == 1) {
		cout << "Task 2: Q7 case d14(1, 1, 2023) Passed!" << endl;
	}
	else {
		cout << "Task 2: Q7 case d14(1, 1, 2023) Failed!" << endl;
	}

	//	Q8 quaterOfYear
	DateTime d18(1, 7, 2023);
	if (d14.quaterOfYear() == 1 && d10.quaterOfYear() == 4) {
		cout << "Task 2: Q8 case d14(1, 1, 2023), d10(31,12,2023) Passed!" << endl;
	}
	else {
		cout << "Task 2: Q8 case d14(1, 1, 2023), d10(31,12,2023) Failed!" << endl;
	}

	//	Q9 relational operator overloading
	DateTime d19(1, 2, 2023);
	DateTime d20(1, 3, 2023);

	if (d19 > d20 == false) {
		cout << "Task 2: Q9 case d19(1, 2, 2023) > d20(1,3,2023) is false Passed!" << endl;
	}
	else {
		cout << "Task 2: Q9 case d19(1, 2, 2023) > d20(1,3,2023) is false Failed!" << endl;
	}

	if (d19 < d20) {
		cout << "Task 2: Q9 case d19(1, 2, 2023) < d20(1,3,2023) is true Passed!" << endl;
	}
	else {
		cout << "Task 2: Q9 case d19(1, 2, 2023) < d20(1,3,2023) is true Passed!" << endl;
	}

	if (d19 != d20) {
		cout << "Task 2: Q9 case d19(1, 2, 2023) != d20(1,3,2023) is true Passed!" << endl;
	}
	else {
		cout << "Task 2: Q9 case d19(1, 2, 2023) != d20(1,3,2023) is true Failed!" << endl;
	}

	//	Q10 ++ -- overloading
	DateTime d21(28, 2, 2023);
	d21++;
	++d21;
	d21--;
	--d21;

	if (d21.getDate() == 28 && d21.getMonth() == 2 && d21.getYear() == 2023) {
		cout << "Task 2: Q10 case d2(28,2,2023) Passed!" << endl;
	}
	else {
		cout << "Task 2: Q10 case d2(28,2,2023) Failed!" << endl;
	}

	//	Q11 duration
	DateTime d22(31, 3, 2023);
	DateTime d23(29, 3, 2023, 12, 0, 0);

	if (d20.duration(d22) == 30 && d22.duration(d23) == 1.5) {
		cout << "Task 2: Q11 Passed!" << endl;
	}
	else {
		cout << "Task 2: Q11 Failed!" << endl;
	}


	//	Q12 - operator
	DateTime d24(1, 1, 2023);
	DateTime d25(3, 1, 2023);

	DateTime d26(1, 2, 2023, 12, 0, 0);
	DateTime d27(5, 2, 2023);

	if (d24 - d25 == -2 && d26 - d27 == -3.5) {
		cout << "Task 2: Q12 Passed!" << endl;
	}
	else {
		cout << "Task 2: Q12 Failed!" << endl;
	}
	
	return 0;
}
