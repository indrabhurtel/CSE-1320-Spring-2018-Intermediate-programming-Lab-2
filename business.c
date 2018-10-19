#include <stdio.h>

float print_out(float* salary, int*	num_of_emps)
{
	int num_Mgrs = *num_of_emps / 2;
	int num_Dirs = num_Mgrs / 5;
	if ((num_Mgrs % 5) != 0)
	{
		num_Dirs = num_Dirs + 1;
	}

	float dir_Salary = (*salary) * 5;
	printf("\n\n**Employee info:**");
	printf("\nTotal workers: %d Monthly salary: $%.2f", *num_of_emps, *salary);
	printf("\nTotal managers: %d Monthly salary: $%.2f", num_Mgrs, dir_Salary / 2);
	printf("\nTotal directors: %d Monthly salary: $%.2f", num_Dirs, dir_Salary);

	float total_Spent = (*salary) * (*num_of_emps) + (num_Mgrs * (dir_Salary / 2)) + num_Dirs * dir_Salary;
	printf("\nTotal spent: $%.2f", total_Spent);
	return total_Spent;
}

int	rebudget(float*	d, float *budget)
{
	float diffA = *budget - *d;
	int choiceR = 0;
	char *message;
	if (*budget > *d)
	{
		printf("\n--This goes UNDER your budget by $%.2f", *budget - *d);
	}
	else if (*budget < *d)
	{
		printf("\n--This goes OVER your budget by $%.2f", *d - *budget);
	}
	else
	{
		printf("\n--This goes SAME AS your budget.");
	}
	printf("\n\n------\nWould you like to rebudget? 1 for yes 2 for no.\n");
	scanf("%d", &choiceR);
	if (choiceR != 1)
	{
		choiceR = 0;
		printf("Bye!");
	}
	return choiceR;
}

int	main()
{
	int	i = 1;
	float	budget, total, salary;
	float	*money_ptr = &salary;
	float	*total_ptr = &total;
	int	employees;
	printf("Enter monthly budget: $");
	scanf("%f", &budget);
	while (i)
	{
		printf("Enter monthly worker salary: $");
		scanf("%f", &salary);
		printf("Enter total workers: ");
		scanf("%d", &employees);
		total = print_out(money_ptr, &employees);
		i = rebudget(total_ptr, &budget);
	}
}
