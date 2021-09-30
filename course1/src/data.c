#include "data.h"

uint8_t numberDigits(int32_t decimalNumber, uint32_t base){
	uint8_t answer = 0;
	do{
		++answer;
		decimalNumber = decimalNumber/base;
	} while(decimalNumber != 0);
	return answer;
}

void toAscii(uint8_t *convertedNumber, uint8_t length, int32_t number, int32_t base){
	float decimals;
	uint8_t digit;
	uint8_t position = length - 2; // because the ascii characters are obtained from last to first
	if(number == 0)
		*convertedNumber = '0';
	else{
		while(number/base != 0){
			decimals = (float)number/base - number/base; 
			digit = base*decimals + 0.5;
			// to convert to ascii characters the obtained numbers are summed an integer
			// according to how far away they are from their ascii representation in the
			// ascii table
			if(base == 16 && digit > 9)
				*(convertedNumber + position) = digit + 55;
			else
				*(convertedNumber + position) = digit + 48;
			number = number/base;
			--position;
		}
		decimals = ((float)number/base) - number/base;
		digit = base*decimals;
		if(base == 16 && digit > 9)
			*(convertedNumber + position) = digit + 55;
		else
			*(convertedNumber + position) = digit + 48;
	}
}

uint8_t my_itoa(int32_t data, uint8_t *ptr, uint32_t base){
	uint8_t length = 1; // at least one to count for the null terminator '\n'
	int8_t isNegative = 0;
	if(data < 0){
		++length; // to count for the minus sign
		isNegative = 1;
		data *= -1;
	} 
	length += numberDigits(data, base);
	if(isNegative == 1)
		*ptr = '-';
	*(ptr + length - 1) = '\n';
	toAscii(ptr, length, data, base);
	return length;
}

int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base){
	int32_t answer = 0;
	int8_t isNegative = 0;
	int8_t position = 0;
	--digits; // this line gets rid of the digit count of the null terminator 
	// the power to which the base is going to be raised, 
	// starting from the most significant digit 
	uint8_t power = digits - 1; 
	if(*ptr == '-'){
		isNegative = 1;
		--power; // one less because the sign does not count for the power raising
		position = 1; // one position is shifted in order to bypass the minus sign
	}
	for(; position < digits; ++position){
		int32_t powerOfBase = 1;
		if(power == 0){
			if(base == 16 && *(ptr + position) > 57)
				answer += (*(ptr + position) - 55);
			else
				answer += (*(ptr + position) - 48);
		}
		else{
			// this method is used to calculate the power as no libraries can be used
			for(uint8_t aux = power; aux > 0; --aux)
				powerOfBase *= base;
			if(base == 16 && *(ptr + position) > 57)
				answer += (*(ptr + position) - 55)*powerOfBase;
			else
				answer += (*(ptr + position) - 48)*powerOfBase;
			--power;
		}
	}
	if(isNegative == 1)
		return -1*answer;
	else
		return answer;
}