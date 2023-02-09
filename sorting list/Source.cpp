#include<iostream>
#include<iomanip>
#include <string>
using namespace std;
class PersonData
{
protected:
	string name;
	string address;
	string contact;
	char gender;

public:
	PersonData()
	{
		name = "";
		address = "";
		contact = "";
		gender = ' ';
	}
	PersonData(string _name, string _address, string _contact, char _gender)
	{
		name = _name;
		address = _address;
		contact = _contact;
		gender = _gender;
	}
	string getName()
	{
		return name;
	}
	string getAdress()
	{
		return address;
	}
	string getContact()
	{
		return contact;
	}
	char getGender()
	{
		return gender;
	}
	void setName(string newName)
	{
		name = newName;
	}
	void setAdress(string newAddress)
	{
		address = newAddress;
	}
	void setContact(string newContact)
	{
		contact = newContact;
	}
	void setGender(char newGender)
	{
		gender = newGender;
	}

	~PersonData()
	{
		delete this;
	}
};
class Customer :public PersonData
{
private:
	string customerID;
	string review;

public:
	Customer()
	{
		name = "";
		address = "";
		contact = "";
		gender = ' ';
		customerID = "";
		review = "";
	}

	Customer(string name, string address, string contact, char gender, string customerID, string review)
		: PersonData(name, address, contact, gender)
	{
		this->customerID = customerID;
		this->review = review;
	}

	void cPrint()
	{
		cout << "Name: " << this->name << endl;
		cout << "Address: " << this->address << endl;
		cout << "Contact: " << this->contact << endl;
		cout << "Gender: " << this->gender << endl;
		cout << "CustomerID: " << customerID << endl;
		cout << "Review: " << review << endl << endl;
	}

	string getCustomerID()
	{
		return customerID;
	}

	string getReview()
	{
		return review;
	}

	void setCustomerID(string id)
	{
		this->customerID = id;
	}

	void setReview(string review)
	{
		this->review = review;
	}
};
class Employee :public PersonData
{
private:
	string employeeID;
	float yearSalary;

public:
	Employee()
	{
		name = "";
		address = "";
		contact = "";
		gender = '\0';
		employeeID = "";
		yearSalary = 0;
	}

	Employee(string name, string address, string contact, char gender, string employeeID, float yearSalary)
		: PersonData(name, address, contact, gender)
	{
		this->employeeID = employeeID;
		this->yearSalary = yearSalary;
	}

	void ePrint()
	{
		cout << "Name: " << this->getName() << endl;
		cout << "Address: " << this->getAdress() << endl;
		cout << "Contact: " << this->getContact() << endl;
		cout << "Gender: " << this->getGender() << endl;
		cout << "Employee ID: " << employeeID << endl;
		cout << fixed<< setprecision(2)<<"Year Salary: " << yearSalary << endl << endl;

	}

	string getEmployeeID()
	{
		return employeeID;
	}

	float getYearSalary()
	{
		return yearSalary;
	}

	void setEmployeeID(string id)
	{
		this->employeeID = id;
	}

	void setYearSalary(float salary)
	{
		this->yearSalary = salary;
	}
};

int main()
{
	Employee employee1(
		"Alice White",
		"123 University Ave, Troy AL 36081",
		"awhite@gmail.com",
		'F',
		"e12345",
		100000.0);
	Customer customer1(
		"John Talor",
		"318 Jane Rd, Troy AL 36081",
		"334-356-788",
		'M',
		"c345678",
		"good");
	customer1.cPrint();
	employee1.ePrint();

	float newSalary;
	cout << "Enter new salary of employee: ";
	cin >> newSalary;

	employee1.setYearSalary(newSalary);
	employee1.ePrint();

	return 0;
}