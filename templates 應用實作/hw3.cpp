#include <iostream>
#include <string>
#include<cmath>
#include<vector>
#include <fstream>
#include <sstream>
#include "fraction.cpp"
using namespace std;

template <typename T>
inline T const& Max(T & a, T & b) {
	if (a > b) {
		return a;
	}
	else {
		return b;
	}
}
template <typename T>
inline T const& Min(T & a, T & b) {
	if (a < b) {
		return a;
	}
	else {
		return b;
	}
}
template <typename T>//Find	the	smallest negative element in an	array of type T	
inline T  smallest(T * a, int size) {
	T min = a[0];
	for (int i = 1; i < size; i++) {
		if (a[i] < min) {
			min = a[i];
		}
	}
	return min;
}
template <typename T>//Find	the	largest positive element in an	array of type T
inline T  largest(T * a, int size) {
	T max = a[0];
	for (int i = 1; i < size; i++) {
		if (a[i] > max) {
			max = a[i];
		}
	}
	return max;
}
template <typename T>//Sort	ascending array	of type	T
inline T * ascending(T * a, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = i; j < size; j++) {
			if (a[i] > a[j]) {
				T temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
	return a;
}
template <typename T>//Sort	the	array of numbers in descending order of absolute value
inline T * descending(T * a, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = i; j < size; j++) {
			if (abs(a[i]) < abs(a[j])) {
				T temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
	return a;
}
template <typename T>//Sort	even numbers ascending and odd numbers descending
inline T* evenodd(T* a, int size) {
	vector <T> temp;
	for (int i = 0; i < size; i++) {
		temp.push_back(a[i]);
	}
	int count = 0;
	for (int i = 0; i < size; i++) {
		if (a[i] % 2 == 0) {
			temp[count] = a[i];
			count++;
		}
	}
	for (int i = 0; i < count; i++) {
		for (int j = i; j < count; j++) {
			if (temp[i] > temp[j]) {
				T p = temp[i];
				temp[i] = temp[j];
				temp[j] = p;
			}
		}
	}
	int c = count;
	for (int i = 0; i < size; i++) {
		if (a[i] % 2 != 0) {
			temp[count] = a[i];
			count++;
		}
	}
	for (int i = c; i < count; i++) {
		for (int j = i; j < count; j++) {
			if (temp[i] < temp[j]) {
				T p = temp[i];
				temp[i] = temp[j];
				temp[j] = p;
			}
		}
	}
	for (int i = 0; i < size; i++) {
		a[i] = temp[i];
	}
	return a;
}

template <typename T>//Sort	negative numbers descending, positive numbers ascending, and negative numbers come before positive numbers
 T * n_descend_p_ascend(T * a, int size) {
	vector <T> temp;
	for (int i = 0; i < size; i++) {
		temp.push_back(a[i]);
	}
	int count = 0;
	for (int i = 0; i < size; i++) {
		if (a[i] < 0) {
			temp[count] = a[i];
			count++;
		}
	}
	for (int i = 0; i < count; i++) {
		for (int j = i; j < count; j++) {
			if (temp[i] < temp[j]) {
				T p = temp[i];
				temp[i] = temp[j];
				temp[j] = p;
			}
		}
	}
	int c = count;
	for (int i = 0; i < size; i++) {
		if (a[i] >= 0) {
			temp[count] = a[i];
			count++;
		}
	}
	for (int i = c; i < count; i++) {
		for (int j = i; j < count; j++) {
			if (temp[i] > temp[j]) {
				T p = temp[i];
				temp[i] = temp[j];
				temp[j] = p;
			}
		}
	}
	for (int i = 0; i < size; i++) {
		a[i] = temp[i];
	}
	return a;
}

 class Customer {
	 public:
		 string name;
		 int numberOfGoods;
		 int unitPrice;
		 int type;
		 int yearsOfLoyalty;
		 Customer() {}
		 double calculatePayment(){
			 double payment = 0;
			 double promotionPercentage;
			 switch (type) {
			 case 1:
				 payment = numberOfGoods * unitPrice * 1.1; 
				 break;
			 case 2:
				 promotionPercentage = min(yearsOfLoyalty * 0.05, 0.5); 
				 payment = (numberOfGoods * unitPrice) * (1.0 - promotionPercentage) * 1.1; 
				 break;
			 case 3:
				 payment = (numberOfGoods * unitPrice) * 0.5 * 1.1; 
				 break;
			 }
			 return payment;
		 }
		 
 };
 class Room {
 public:
	 string name;
	 int numberOfNights;
	 int extraFee;
	 int serviceFee;
	 int type;
	 double calculateRevenue() {
		 double revenue = 0;
		 switch (type) {
		 case 1:
			 revenue = (numberOfNights * 7500 + serviceFee) * 1.15 + extraFee;
			 break;
		 case 2:
			 revenue = (numberOfNights * 5000 + serviceFee) * 1.05; 
			 break;
		 case 3:
			 revenue = numberOfNights * 3000;
			 break;
		 }
		 return revenue;
	 }
 };
int main() {
	int i = 39;
	int j = 20;
	cout << "max(i, j): " << Max(i, j) << endl;
	double f1 = 13.5;
	double f2 = 20.7;
	cout << "max(f1, f2): " << Max(f1, f2) << endl;
	string s1 = "Hello";
	string s2 = "World";
	cout << "max(s1, s2): " << Max(s1, s2) << endl;

	Fraction f3(1, 2);
	Fraction f4(2, 3);
	cout << "max(f3, f4): " << Max(f3, f4) << endl;
	cout << "min(f3, f4): " << Min(f3, f4) << endl;

	int two_c[8] = { 1,2,3,4,5,6,7,8 };
	evenodd(two_c, 8);
	for (int i = 0; i < 8; i++) {
		cout << two_c[i] << " ";
	}
	cout << endl;

	int test[9] = { 1, 2,-1, -2, -3,3, 4, -4, -5 };
	cout << "smallest: " << smallest(test, 9) << endl;

	cout << "largest: " << largest(test, 9) << endl;

	n_descend_p_ascend(test, 9);
	for (int i = 0; i < 9; i++) {
		cout << test[i] << " ";
	}
	cout << endl;

	string data; 
	ifstream input("customer.imp.txt");
	if (!input) {
		cout << "Error opening file." << endl;
		return 0;
	}
	int x, y, z;
	input >> x >> y >> z;

	vector<Customer> customers;
	for (int i = 0; i < x + y + z; i++) {
		Customer customer;

		string name;
		input >> name;
		customer.name = name;

		int numberOfGoods;
		input >> numberOfGoods;
		customer.numberOfGoods = numberOfGoods;

		double unitPrice;
		input >> unitPrice;
		customer.unitPrice = unitPrice;

		if (i < x) {
			customer.type = 1;
		}
		else if (i < x + y) {
			customer.type = 2;
			int yearsOfLoyalty;
			input >> yearsOfLoyalty;
			customer.yearsOfLoyalty = yearsOfLoyalty;
		}
		else {
			customer.type = 3;
		}

		customers.push_back(customer);
	}
	input.close();

	double total = 0;
	ofstream output("payment.out.txt");
	for (int i = 0; i < x + y + z; i++) {
		double payment = customers[i].calculatePayment();
		output << customers[i].name << "\n";
		output << payment << "\n";
		total += payment;
	}
	output << total << "\n";

	//算last month
	ifstream input_last("Last_month.txt");
	if (!input_last) {
		cout << "Error opening file." << endl;
		return 0;
	}
	int d, p, b;
	input_last >> d >> p >> b;
	vector<Room> last_month;
	for (int i = 0; i < d + p + b; i++) {
		Room room;

		string name;
		input_last >> name;
		room.name = name;

		if (i < d) {
			room.type = 1;
			int serviceFee;
			input_last >> serviceFee;
			room.serviceFee = serviceFee;
			double extraFee;
			input_last >> extraFee;
			room.extraFee = extraFee;
		}
		else if (i < d + p) {
			room.type = 2;
			int serviceFee;
			input_last >> serviceFee;
			room.serviceFee = serviceFee;
		}
		else {
			room.type = 3;
		}

		int numberOfNights;
		input_last >> numberOfNights;
		room.numberOfNights = numberOfNights;

		last_month.push_back(room);
	}
	input_last.close();

	for (int i = 0; i < d+p+b; i++) {
		double revenue = last_month[i].calculateRevenue();
		cout << last_month[i].name << "\n";
		cout << revenue << "\n";
	}

	//算current month
	ifstream input_current("Current_month.txt");
	if (!input_current) {
		cout << "Error opening file." << endl;
		return 0;
	}
	input_current >> d >> p >> b;
	vector<Room> current_month;
	for (int i = 0; i < d + p + b; i++) {
		Room room;

		string name;
		input_current >> name;
		room.name = name;

		if (i < d) {
			room.type = 1;
			int serviceFee;
			input_current >> serviceFee;
			room.serviceFee = serviceFee;
			double extraFee;
			input_current >> extraFee;
			room.extraFee = extraFee;
		}
		else if (i < d + p) {
			room.type = 2;
			int serviceFee;
			input_current >> serviceFee;
			room.serviceFee = serviceFee;
		}
		else {
			room.type = 3;
		}

		int numberOfNights;
		input_current >> numberOfNights;
		room.numberOfNights = numberOfNights;

		current_month.push_back(room);
	}
	input_current.close();

	vector<string>excellent_room;
	for (int i = 0; i < d + p + b; i++) {
		if (current_month[i].calculateRevenue() > last_month[i].calculateRevenue() * 1.25) {
			excellent_room.push_back(current_month[i].name);
		}
	}

	ofstream output_revenue("revenue.out.txt");
	for (int i = 0; i < d + p + b; i++) {
		double revenue = current_month[i].calculateRevenue();
		output_revenue << current_month[i].name << "\n";
		output_revenue << revenue << "\n";
	}
	output_revenue << "============================\n";
	output_revenue << "Excellent Rooms:\n";
	for (int i = 0; i < excellent_room.size(); i++) {
		output_revenue << excellent_room[i] << "\n";
	}
}