#include <iostream>
#include <fstream>



class Adress{
private:
	std::string townName;
	std::string streetName;
	int houseNum;
	int apartmentNum;
	
public:
	Adress(std::string townName = "0", std::string streetName = "0", int houseNum = 0, int apartmentNum = 0){}
	
	//сеттеры 
	void setTownName(std::string townName){
		this->townName = townName;
	}
	void setStreetName(std::string streetName){
		this->streetName = streetName;
	}
	void sethouseNum(int houseNum){
		this->houseNum = houseNum;
	}

	void setApartmentNum(int apartmentNum){
		this->apartmentNum = apartmentNum;
	}
	// гетеры 
	std::string getTownName(){
		return this->townName; 
	}
	std::string getStreetName(){
		return this->streetName; 
	}
	int getHouseNum(){
		return this->houseNum;
	}
	int getApartmentNum(){
		return this->apartmentNum;
	}
};

int main(int argc, char *argv[]) {
	std::ifstream in;
	in.open("in.txt");
	int size = 0;
	if (in.is_open()) {
		in >> size;
	}else{
		std::cout << "Не удалось открыть файл";
		return -1;
	}
	Adress* allAdresses  = new Adress[size];
	for(int i = 0; i < size; i++){
		std::string town;
		in >> town;
		allAdresses[i].setTownName(town);
		std::string street;
		in >> street;
		allAdresses[i].setStreetName(street);
		int house;
		in >> house;
		allAdresses[i].sethouseNum(house);
		int apartment;
		in >> apartment;
		allAdresses[i].setApartmentNum(apartment);
	}
	std::ofstream out ;
	out.open("out.txt"); 
	if (!out.is_open()) {
		std::cout << "Не удалось создать/открыть файл для записи\n";
		return -2;
	}
	out<< size << "\n";
	for(int i = size - 1; i >= 0; i--){
		out << allAdresses[i].getTownName()<<", " ;
		out << allAdresses[i].getStreetName()<<", " ;
		out << allAdresses[i].getHouseNum()<<", " ;
		out << allAdresses[i].getApartmentNum()<<"\n" ;
	}
	out.close();
	in.close();
	delete[] allAdresses;
	return 0;
}

