// #include <unistd.h>
// #include <sys/time.h>
// #include <stdio.h>

// unsigned long long	get_time(void)
// {
// 	struct timeval	t;

// 	gettimeofday(&t, NULL);
// 	return (t.tv_sec * (unsigned long long) 1000 + t.tv_usec / 1000);
// }

// int main(void)
// {
// 	unsigned long long start;
// 	unsigned long long end;
// 	unsigned long long current_time;

// 	start = get_time();
// 	usleep(200 * 1000);
// 	end = get_time();
// 	printf("1 : %llu\n", end - start);

// 	start = get_time();
// 	while(1)
// 	{
// 		current_time = get_time();
// 		if (current_time - start >= 200)
// 			break;
// 	}
// 	end = get_time();
// 	printf("2 : %llu\n", end - start);
// 	return 0;
// }
