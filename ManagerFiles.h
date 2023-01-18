#pragma once
#include <iostream>
#include <map>
#include <vector>
template <typename T>
class M_Files {
public:
	M_Files(){
	}
	void Add_file(int id,const T file) {
		const auto& [it, isinsert] = _data.insert({ id, file});
		if (!isinsert)
			std::cout << "Введенный id уже занят\n";
		else {
			std::cout << "Файл успешно добавлен\n";			
		}
	}
	void Set_file(int id, const T file) {
		_it = _data.find(id);
		_save_using_id(id);
		if (_it != _data.end()){
			_data[id] = file;
		std::cout << "Файл успешно изменен\n";
		}
		else
			std::cout << "Файла с таким id несуществует\n";
	}
	void Deleted_file(int id) {
		_save_using_id(id);
		if(!_data.erase(id))
			std::cout<<"Файла с таким id несуществует\n";
		std::cout << "Файл удален\n";
	}
	const T Get_file(int id) {
		_it = _data.find(id);
		_save_using_id(id);
		if (_it!=_data.end())
			return _it->second;
	}
	int mostPopularKeyToFind() {
		std::map<int, int> keyAmount;
		for (size_t i = 0; i < _vecId.size(); i++) {
			const auto& [it, isInserted] = keyAmount.insert({ _vecId[i],1 });
			if (!isInserted) {
				auto value = it->second;
				value++;
				keyAmount[_vecId[i]] = value;
			}
		}
		std::pair<int, int> key_beggestValue = { 0,0 };
		for (std::map<int, int>::const_iterator it = keyAmount.begin(); it != keyAmount.end(); it++) {
			if (key_beggestValue.second < it->second)
				key_beggestValue = std::make_pair(it->first, it->second);
		}
		return key_beggestValue.first;

	}
private:
	void _save_using_id(int id) {
		_vecId.push_back(id);
	}
	std::map<int, T> _data;
	std::map<int, T>::iterator _it;
	std::vector<int> _vecId;
};