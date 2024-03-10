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

sbit S0 = P2^3;
sbit S1 = P2^2;
sbit S2 = P2^1;
sbit S3 = P2^0;

sbit EN = P2^4;

sbit DM = P3^7;
sbit DMM =P3^6;


void delayms(unsigned int ms)
{
	unsigned char j;
	while(ms--)
	{
		for(j=0;j<120;j++);
	}
}

void commd()
{
	S0 = 0;
}

void commdover()
{
	S0 = 1;
}

void main()
{
	Z1 = 1;
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
	Z15 = 1;
	Z16 = 0;
	
	EN = 0;
	
	while(1)
	{
	  commd();
		delayms(200);
		commdover();
		delayms(200);
	}

}