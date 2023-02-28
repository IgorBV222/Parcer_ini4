#pragma once
#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <iostream>
#include <chrono>
#include "IParcer.h"



class Parcer_ini : public IParcer{

public:
	//������ �����
	void IReaderFile(const std::string& file_name) override;

	//����� ����� �� ������� (� ����� ������ ����)
	void IfindKey(const std::string& find_key) override;

	//���������� �� ������
	void IfindSection(const std::string& find_section) override;

	//���� � �����
	bool keyInFile(const std::string& find_key) override;

	//���������� �� �������� � �����
	bool valueInFile(const std::string& find_value) override;
	
	//�������� ����� � ������
	void keyValueInSection(const std::string& section_name, const std::string& key_name) override;

	//������ �������� �����
	void keyValueReplacement(const std::string& section_name, const std::string& key_name, const std::string& value_newName) override;

	//������ ������� � ����
	const void writeToFile(const std::string& file_name) override;

	//����� ������� � �������
	void showParcer() override;

private:
	
	std::map <std::string, std::map < std::string, std::string>> _section;	
	
};

