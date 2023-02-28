#pragma once
#include <iostream>

class IParcer{

public:
	//������ �����
	virtual void IReaderFile(const std::string& file_name) = 0;
	//����� ����� �� ������� (� ����� ������ ����)
	virtual void IfindKey(const std::string& find_key) = 0;
	//���������� �� ������
	virtual void IfindSection(const std::string& find_section) = 0;
	//���� � �����
	virtual bool keyInFile(const std::string& find_key) = 0;
	//���������� �� �������� � �����
	virtual bool valueInFile(const std::string& find_value) = 0;
	//�������� ����� � ������
	virtual void keyValueInSection(const std::string& section_name, const std::string& key_name) = 0;
	//������ �������� �����
	virtual void keyValueReplacement(const std::string& section_name, const std::string& key_name, const std::string& value_newName) = 0;
	//������ ������� � ���� writeToFile
	virtual const void writeToFile(const std::string& file_name) = 0;
	

	//����� ������� � �������
	virtual void showParcer() = 0;


	virtual ~IParcer() {}
};

