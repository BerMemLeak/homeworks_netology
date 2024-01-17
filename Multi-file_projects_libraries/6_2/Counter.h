#pragma once

class Counter{
private:
	int count = 1;
public:
	Counter(int count = 1);
	void plusCount();
	void minusCount();
	int nowCount();
};
