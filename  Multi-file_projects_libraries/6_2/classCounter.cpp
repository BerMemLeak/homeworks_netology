#include "classCounter.h"

Counter::Counter(int count ){
	this->count = count;
};
void Counter::plusCount(){
	this->count +=1;
};
void Counter::minusCount(){
	this->count -=1;
}
int Counter::nowCount(){
	return this->count;
}

