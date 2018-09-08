/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evalexpr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfisher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 14:04:46 by dfisher           #+#    #+#             */
/*   Updated: 2018/09/08 16:09:55 by dfisher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

/* check for max/min int)
 *
 */
void	ft_putnbr(int n)
{
	if (n < 0)
	{
		ft_putchar('-');
		if (n == -2147483648)
		{
			ft_putchar('2');
			n = -147483648;
		}
		ft_putnbr(-n);
	}
	else if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
		ft_putchar(n + '0');
}

int eval_expr(char *str)
{
	int		*numbers;
	char	*tmp;
	char	*ops;
	//int		*start_signs;
	//int		*end_signs;
	int		i;
	int		j;
	int		k;
	int		sign;
	//int		o;

	numbers = (int *)malloc(sizeof(int) * 100); //strlen?
	tmp = (char *)malloc(sizeof(char) * 100);
	ops = (char *)malloc(sizeof(char) * 100); // strlen?
	i = 0;
	j = 0;
	/* remove space
	 */
	while (str[i] != '\0')
	{
		while (str[i] == ' ')
			i++;
		tmp[j] = str[i];
		j++;
		i++;
	}
	tmp[j] = str[i];
	printf("%s\n", tmp);
	i = 0;
	j = 0;
	k = 0;
	sign = 1;
	if (tmp[i] == '-')
	{
		i++;
		while (tmp[i] >= '0' && tmp[i] <= '9')
		{
			numbers[j] = numbers[j] * 10 + ((int)tmp[i] - '0');
			i++;
			k++;
		}
		numbers[j] = -numbers[j];
		j++;
		k++;
	}
	while (tmp[i] != '\0')
	{
		if (tmp[i] == '+' || tmp[i] == '-' || tmp[i] == '/' || tmp[i] == '8' || tmp[i] == '%' || tmp[i] == ')')
		{
			k++;
		}
		while (tmp[i] == '(' && tmp[i + 1] == '-')
		{
			//printf("number [%d]\n", j);
			j--;
			k++;
			printf("tmp[%d] == %c\n", k, tmp[k]);
			i += 2;
			while (tmp[k] >= '0' && tmp[k] <= '9')
			{
				numbers[j] = numbers[j] * 10 + ((int)tmp[k] - '0');
				i++;
				k++;
			}
			numbers[j] = -numbers[j];
			j++;
			k++;
		}
		while (tmp[k] >= '0' && tmp[k] <= '9')
		{
			numbers[j] = numbers[j] * 10 + (int)tmp[k] - '0';
			k++;
		}
		if (tmp[i] == '+' || tmp[i] == '-' || tmp[i] == '/' || tmp[i] == '8' || tmp[i] == '%' || tmp[i] == '(' || tmp[i] == ')')
		{
			j++;
			k++;
		}
		i++;
	}
	printf("%d\n", numbers[0]);
	printf("%d\n", numbers[1]);
	printf("%d\n", numbers[2]);
	printf("%d\n", numbers[3]);
	printf("%d\n", numbers[4]);
	i = 0;
	j = 0;
	k = 0;
	if (tmp[i] == '-')
	{
		i++;
		k++;
	}
	while (tmp[i] != '\0')
	{
		if (tmp[i] >= '0' && tmp[i] <= '9')
		{
			k++;
		}
		while (tmp[k] == '+' || tmp[k] == '-' || tmp[k] == '/' || tmp[k] == '8' || tmp[k] == '%' || tmp[k] == '(' || tmp[k] == ')')
		{
			ops[j] = tmp[k];
			k++;
		}
		if (tmp[i] >= '0' && tmp[i] <= '9')
		{
			j++;
			k++;
		}
		i++;
	}
	printf("%c\n", ops[0]);
	printf("%c\n", ops[1]);
	/*k = 0;
	j = 0;
	o = 0;
	while (str[i] != '\0')
		{
			if (str[k] == ' ')
			{
				j--;
				k++;
			}
			printf("We are in main cycle (i) %d before subcycle (k) %d, j = %d\n", i, k, j);
			while (str[k] >= '0' && str[k] <= '9')
			{
				numbers[j] *= 10;
				printf("We are in subcycle (k) %d of main cycle (i) %d numbers[%d] = %d, (int)str[k] - '0' = %d \n", k, i, j, numbers[j], (int)str[k] - '0');
				numbers[j] += (int)str[k] - '0';
				printf("We are in subcycle (k) %d of main cycle (i) %d numbers[%d] changed to %d, str[k] = %c \n", k, i, j ,numbers[j], str[k]);
				k++;
			}
			while (str[k] == '+')
			{
				ops[o] = str[k];
				printf("ops[%d] = %c\n", o, str[k]);
				k++;
			}
			j++;
			o++;
			i++;
			printf("We are in main cycle %d after subcycle %d, j = %d\n", i, k, j);
		}
	 */
	return (1);
}

int		main(int ac, char **av)
{
	if (ac > 1)
	{
		ft_putnbr(eval_expr(av[1]));
		ft_putchar('\n');
	}	
	return (0);
}
