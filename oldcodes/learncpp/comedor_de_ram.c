#include <stdlib.h>

int main()
{
	for (long long int i = 0; i < 1000000; i++)
    {
        malloc(52428800000);
		_sleep(1000);
	}
	_sleep(5000);
	return 0;
}