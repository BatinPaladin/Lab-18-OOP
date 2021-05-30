#pragma once
#include <string>
#include <iostream>
using namespace std;
class Error {
public:
	virtual void what() { };
};
class IndexError : public Error {
protected:
	string type_error;
public:
	IndexError() { 
		type_error = "\n������ �������!"; 
	}
	void what() { 
		cout << type_error; 
	}
};
class IndexError1 : public IndexError {
protected:
	string error_message;
public:
	IndexError1() { 
		IndexError();
		error_message = "\n��������� ������� ��������� � �������� � ������������� ��������\n"; 
	}
	void what() { 
		cout << type_error << error_message;
	}
};
class IndexError2 : public IndexError {
protected:
	string error_message;
public:
	IndexError2() { 
		IndexError(); 
		error_message = "\n��������� ������� ��������� � ��������, ������ �������� ������ ������������� �������\n";
	}
	void what() { 
		cout << type_error << error_message;
	}
};
class IndexShiftError1 : public IndexError {
protected:
	string error_message;
public:
	IndexShiftError1() { 
		IndexError(); 
		error_message = "\n��������� ������� ������ ������� �� �������� ������� ����� ���������\n";
	}
	void what() { 
		cout << type_error << error_message;
	}
};
class IndexShiftError2 : public IndexError {
protected:
	string error_message;
public:
	IndexShiftError2() {
		IndexError();
		error_message = "\n��������� ������� ������ ������� �� ������������� ��������\n";
	}
	void what() {
		cout << type_error << error_message;
	}
};
class SizeError : public Error {
protected:
	string type_error;
public:
	SizeError() { 
		type_error = "\n������ �������!"; 
	}
	void what() { 
		cout << type_error; 
	}
};
class SizeError1 : public SizeError {
protected:
	string error_message;
public:
	SizeError1() {
		SizeError();
		error_message  = "\n��������� ������� �������� ���������, ���-�� ��������� �������� ������ ������������� ���-�� ���������\n";
	}
	void what() {
		cout << type_error << error_message;
	}
};
class SizeError2 : public SizeError {
protected:
	string error_message;
public:
	SizeError2() {
		SizeError();
		error_message = "\n��������� ������� �������� ��������� � ������������� ���-��� ���������\n";
	}
	void what() {
		cout << type_error << error_message;
	}
};
class EmptySizeError : public SizeError {
protected:
	string error_message;
public:
	EmptySizeError() {
		SizeError();
		error_message = "\n��������� ������� ��������� � ������� ���������\n";
	}
	void what() {
		cout << type_error << error_message;
	}
};