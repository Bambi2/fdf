#include <fdf.h>



int main(int argc, char **argv)
{
	if (argc == 2)
	{
		if (fdf(argv[1]))
			return (0);
	}
	else
		ft_putstr_fd("Wrong number of arguments\n", 2);
	return (1);
}