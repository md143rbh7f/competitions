#include <stdio.h>

int n, c, sum, i;
char buf[20];

void output( int x )
{
	i = 0;
	while(x>=1000) x -= 1000, buf[i++] = 'M';
	if(x>=900) x -= 900, buf[i] = 'C', buf[i+1] = 'M', i += 2;
	if(x>=500) x -= 500, buf[i++] = 'D';
	if(x>=400) x -= 400, buf[i] = 'C', buf[i+1] = 'D', i += 2;
	while(x>=100) x -= 100, buf[i++] = 'C';
	if(x>=90) x -= 90, buf[i] = 'X', buf[i+1] = 'C', i += 2;
	if(x>=50) x -= 50, buf[i++] = 'L';
	if(x>=40) x -= 40, buf[i] = 'X', buf[i+1] = 'L', i += 2;
	while(x>=10) x -= 10, buf[i++] = 'X';
	if(x>=9) x -= 9, buf[i] = 'I', buf[i+1] = 'X', i += 2;
	if(x>=5) x -= 5, buf[i++] = 'V';
	if(x>=4) x -= 4, buf[i] = 'I', buf[i+1] = 'V', i += 2;
	while(x>=1) x -= 1, buf[i++] = 'I';
	buf[i] = 0;
	printf("%s",buf);
}

int main()
{
	while(1)
	{
		scanf("%d",&n);
		if(!n) break;
		c++;
		sum = 0;
		while(n--)
		{
			scanf("%s",buf);
			i = 0;
			while(buf[i]=='M') sum += 1000, i++;
			if(buf[i]=='C'&&buf[i+1]=='M') sum += 900, i += 2;
			if(buf[i]=='D') sum += 500, i++;
			if(buf[i]=='C'&&buf[i+1]=='D') sum += 400, i += 2;
			while(buf[i]=='C') sum += 100, i++;
			if(buf[i]=='X'&&buf[i+1]=='C') sum += 90, i += 2;
			if(buf[i]=='L') sum += 50, i++;
			if(buf[i]=='X'&&buf[i+1]=='L') sum += 40, i += 2;
			while(buf[i]=='X') sum += 10, i++;
			if(buf[i]=='I'&&buf[i+1]=='X') sum += 9, i += 2;
			if(buf[i]=='V') sum += 5, i++;
			if(buf[i]=='I'&&buf[i+1]=='V') sum += 4, i += 2;
			while(buf[i]=='I') sum ++, i++;
		}
		printf("Case ");
		output(c);
		printf(": ");
		output(sum);
		printf("\n");
	}
	return 0;
}
