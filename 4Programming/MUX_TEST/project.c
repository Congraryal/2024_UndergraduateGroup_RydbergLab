#include <reg52.h>

sbit Z1 = P0^0;
sbit Z2 = P0^1;
sbit Z3 = P0^2;
sbit Z4 = P0^3;
sbit Z5 = P0^4;
sbit Z6 = P0^5;
sbit Z7 = P0^6;
sbit Z8 = P0^7;
sbit Z9 = P1^0;
sbit Z10 = P1^1;
sbit Z11 = P1^2;
sbit Z12 = P1^3;
sbit Z13 = P1^4;
sbit Z14 = P1^5;
sbit Z15 = P1^6;
sbit Z16 = P1^7;

sbit AZ = P2^0;
sbit BZ = P2^1;
sbit CZ = P2^2;
sbit DZ = P2^3;

sbit EN = P2^4;

sbit DM = P3^7;

void delayms(unsigned int ms)
{
	unsigned char j;
	while(ms--)
	{
		for(j=0;j<120;j++);
	}
}



void init()
{
	Z1 = 1;
	Z2 = 0;
	Z3 = 1;
	Z4 = 0;
	Z5 = 1;
	Z6 = 0;
	Z7 = 1;
	Z8 = 0;
	Z9 = 1;
	Z10 = 0;
	Z11 = 1;
	Z12 = 0;
	Z13 = 1;
	Z14 = 0;
	Z15 = 1;
	Z16 = 0;
}

void init_low()
{
	Z1 = 0;
	Z2 = 0;
	Z3 = 0;
	Z4 = 0;
	Z5 = 0;
	Z6 = 0;
	Z7 = 0;
	Z8 = 0;
	Z9 = 0;
	Z10 = 0;
	Z11 = 0;
  Z12 = 0;
	Z13 = 0;
	Z14 = 0;
	Z15 = 0;
	Z16 = 0;
}

void init_high()
{
	Z1 = 1;
	Z2 = 1;
	Z3 = 1;
	Z4 = 1;
	Z5 = 1;
	Z6 = 1;
	Z7 = 1;
	Z8 = 1;
	Z9 = 1;
	Z10 = 1;
	Z11 = 1;
	Z12 = 1;
	Z13 = 1;
	Z14 = 1;
	Z15 = 1;
	Z16 = 1;
}

void ENswitch()
{
	if (EN == 1)
	{
		EN = 0;
	}	
	else EN = 1;
}

void chan_select(int m)
{
	int n1, n2, n3;
	DZ = m/8;
	n1 = m - 8;
	CZ = n1/4;
	n2 = n1 - 4;
	BZ = n2/2;
	n3 = n2 - 2;
	AZ = n3/1;
}

int num = 0;


void main()
{
	init_low();
	delayms(1000);
	
	EN = 0;

	init();
	
	while(1)
	{
		DM = 1;
		chan_select(num);
		num ++;
		DM = 0;
		if (num == 15)
		{
		init_low();
		delayms(1000);
		init();
		num = 0;
		}
		
	}
}