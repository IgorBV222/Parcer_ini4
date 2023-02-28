#include "Parcer_ini.h"

//������ �����
/*
void Parcer_ini::IReaderFile(const std::string& file_name) {
std::ifstream path;
path.open(file_name);
std::string currenLine;

if (path.is_open()) {
	while (getline(path, currenLine)) {
		if (currenLine[0] == '[') { //������� ��� ������
			_sectionTitle = currenLine.substr(1, currenLine.find(']') - 1);
			_section[_sectionTitle];
		}
		else {
			if (currenLine.size() != 0 && currenLine[0] != ';' && currenLine[0] != '#' && currenLine[0] != '[') {
				for (int i = 0; i < currenLine.size(); i++) {
					if (currenLine[i] == '=') {
						_key = currenLine.substr(0, currenLine.find('='));

					}
				}
			}
		}
	
	
	
	
	
	
	
		_section[_sectionTitle][_key] = _value;
	}
}
else
	throw "Error open file";
	path.close();
}*/


void Parcer_ini::IReaderFile(const std::string& file_name) {

	std::ifstream path;
	path.open(file_name);
	std::string currenLine;
	std::string sectionTitle, key, value;
	
	if (path.is_open()) {
		while (getline(path, currenLine)) {			
			if (currenLine[0] == '[') {
				sectionTitle = currenLine.substr(1, currenLine.find(']') - 1);
				//_section[_sectionTitle];
			}
			else {
				if (currenLine.size() !=0 && currenLine[0] != ';' && currenLine[0] != '#' && currenLine[0] != '[' && currenLine[0] != ' ') {
					for (int i = 0; i < currenLine.size(); i++) {
						if (currenLine[i] == '=') {
							key = currenLine.substr(0, currenLine.find('='));
							//value = currenLine.substr(currenLine.find('=') + 1, currenLine.find(';'));
							
							if (currenLine[i] != ';' && currenLine[i] != '#') {
								for (int i = currenLine.find('=')+1; i < currenLine.find(';'); i++)
									//value = currenLine.substr(currenLine.find('=') + 1) + currenLine[i];
									value = currenLine[i];
							}
						}
						/*
						for (int i = currenLine.find('='); i < currenLine.size(); i++) {
							if (currenLine[i] == ';') {
								_value = currenLine.substr(currenLine.find('=') +1, currenLine.find(';'));
							}
							if (currenLine[i] == '#') {
								_value = currenLine.substr(currenLine.find('=') +1, currenLine.find('#'));
							}
							else 
							    _value = currenLine.substr(currenLine.find('=') +1) + currenLine[i];
						}
						*/
						//while (currenLine[i] != ';' || currenLine[i] != '#') {
						//	_value = currenLine.substr(currenLine.find('=') + 1) + currenLine[i];
						//	_value = _value.substr(_value.find(' ') - 1);							
						//}
							//parameterValues[key] = value;
							//parameterValues[currenLine.substr(0, currenLine.find('=') - 1)] = currenLine.substr(currenLine.find('=') + 1);
							//_section[sectionTitle] = parameterValues;
							//_section[_sectionTitle][_key] = _value;						
					}
				}
				if(key!="")
					_section[sectionTitle][key] = value;
			}			
		}		
	}
	else
		throw "Error open file";

	path.close();
}


//����� ����� �� ������� (� ����� ������ ����)
void Parcer_ini::IfindKey(const std::string& find_key){
	for (const auto& section : _section) {
		for (const auto& element : section.second) {
			if (element.first == find_key)
				std::cout << "The key: " << element.first << " in section " << section.first << std::endl;	
			//else //(element.first != find_key)
				//std::cout << "The key: " << find_key << " is not in the sections!" << section.first << std::endl;
		}
	}
	std::cout << "The key: " << find_key << " is not in the sections!" << std::endl;
}

//���������� �� ������
void Parcer_ini::IfindSection(const std::string& find_section) {
	for (const auto& section : _section) {
		if (section.first == find_section) 
			std::cout << "Section exists!" << std::endl;
		//else
			//std::cout << "There is no such section...." << std::endl;
	}
	std::cout << "There is no such section...." << std::endl;
}






//���� � �����
bool Parcer_ini::keyInFile(const std::string& find_key){
	for (const auto& section : _section) {
		for (const auto& element : section.second) {
			if (element.first == find_key)
				return true;
			break;// ��������� ��������� ��, � ������� ��� ����������
		}
	}
	return false;
}

//���������� �� �������� � �����
bool Parcer_ini::valueInFile(const std::string& find_value){
	for (const auto& section : _section) {
		for (const auto& element : section.second) {
			//if (element.second == find_value)
			if(element.second.find(find_value)) // ��� �������, ��� ��� ����� � ���� �������� ���� ������������
				return true;
		}
	}
	return false;
}

//�������� ����� � ������
void Parcer_ini::keyValueInSection(const std::string& section_name, const std::string& key_name) {
	for (const auto& section : _section) {
		if (section.first == section_name) {
			for (const auto& element : section.second) {
				if (element.first == key_name)
					std::cout << "Key value in section: " << element.second << std::endl;
				//else //(element.first != key_name) 
					//std::cout << "No key in section!" << std::endl;				
			}
		}
		//else
			//std::cout << "No section in file!" << std::endl;
	}
}

//������ �������� �����
/*
void Parcer_ini::keyValueReplacement(const std::string& section_name, const std::string& key_name, const std::string& value_newName) {
	for (const auto& section : _section) {
		if (section.first == section_name) {
			for (const auto& element : section.second) {
				if (element.first == key_name) {
					element.second == value_newName;
					std::cout << "Key: " << element.first << " value changed to: " << element.second << std::endl;
				}
			}
		}
		else {
			if (section.first != section_name) {
				section.first == section_name;
				for (const auto& element : section.second) {
					element.first == key_name;
					element.second == value_newName;
					std::cout << "New section created: " << section.first << "\nNew key created: " << element.first << "\nNew value created:" << element.second << std::endl;
				}
			}
			else {
				if (section.first == section_name) {
					for (const auto& element : section.second) {
						if (element.first != key_name) {
							element.first == key_name;
							element.second == value_newName;
							std::cout << "New key created: " << element.first << "\nNew value created:" << element.second << std::endl;
						}
					}
				}
			}
		}		
	}
}
*/

//������ �������� ����� 2
void Parcer_ini::keyValueReplacement(const std::string& section_name, const std::string& key_name, const std::string& value_newName) {
	std::string sectionTitle, key, value;
	for (const auto& section : _section) {
		if (section.first == section_name) {
			for (const auto& element : section.second) {
				if (element.first == key_name) {
					value = value_newName;
					_section[sectionTitle][key] = value;
					std::cout << "Key: " << element.first << " value changed to: " << element.second << std::endl;
				}
			}
		}
		else {
			if (section.first != section_name) {
				sectionTitle = section_name;
				for (const auto& element : section.second) {
					key = key_name;
					value = value_newName;
					_section[sectionTitle][key] = value;
					std::cout << "New section created: " << section.first << "\nNew key created: " << element.first << "\nNew value created:" << element.second << std::endl;
				}
			}
			else {
				if (section.first == section_name) {
					for (const auto& element : section.second) {
						if (element.first != key_name) {
							key = key_name;
							value = value_newName;
							_section[sectionTitle][key] = value;
							std::cout << "New key created: " << element.first << "\nNew value created:" << element.second << std::endl;
						}
					}
				}
			}
		}
	}
}

//������ ������� � ����. ���������� ������ � ������������ ����, �� ����� ��������� �� ����������
const void Parcer_ini::writeToFile(const std::string& file_name){	
	std::ofstream out;	
	out.open(file_name);
	if (out.is_open()) {
		
		for (const auto& section : _section) {
			//parser += ('[' + section.first + ']' + '\n');
			out << ('[' + section.first + ']' + '\n');
			for (const auto& element : section.second) {
				//parser += (element.first + '=' + element.second + '\n');
				out << (element.first + '=' + element.second + '\n');
			}
		}
		//out << parser << "\n";
		

		std::cout << "\nThe parser is written to the specified file!\n";
		
	}
	else
		std::cout << "Error opening file! File does not exist.\n";

	
	out.close(); 
	system("pause");
	system("cls");
}





//����� ������� � �������
void Parcer_ini::showParcer(){
	for (const auto& section : _section) {
		std::cout << "[" << section.first << "]" << std::endl;
			for (const auto& element : section.second) {
					std::cout << element.first << "=" << element.second << std::endl;
			}
	}
}

