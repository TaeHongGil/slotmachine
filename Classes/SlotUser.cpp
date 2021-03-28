#include "SlotUser.h";

SlotUser::SlotUser() {
		this->coin = 10;
		this->betting = 1;
}

SlotUser::SlotUser(int c) {
	this->coin = c;
	this->betting = 1;
}
SlotUser::~SlotUser() {}


int SlotUser::getCoin() {return this->coin;}

void SlotUser::setCoin(int c) {this->coin = c;}

int SlotUser::getBet() {return this->betting;}

void SlotUser::setBet(int c) {this->betting = c;}
