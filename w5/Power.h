
/*---------------------------------------------------------
Name:        Samarth Sunilkumar Patel
Student ID:  150061208
Seneca Email:sspatel65@myseneca.ca
Section:     NBB
Date:	     20 June,2022
------------------------------------------------------------*/


#ifndef SDDS_POWER_H
#define SDDS_POWER_H


namespace sdds {
	const int MAX_NAME_LENGTH = 50;

	class Power{
		char m_name[MAX_NAME_LENGTH + 1];
		int m_rarity;

	public:
		Power();
		Power(const char* name, int rarity);
		void setEmpty();
		void createPower(const char* name, int rarity);

		const char* checkName() const;
		int checkRarity() const;
		bool isEmpty() const;
	};
	void displayDetails(Power* powers, int size);
}
#endif