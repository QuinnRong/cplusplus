long long lt_cnt = 0;
long long ge_cnt = 0;

long long absdiff_se(long long x, long long y)
{
	long long result;
	if (x < y)
	{
		lt_cnt++;
		result = y - x;
	}
	else
	{
		ge_cnt++;
		result = x - y;
	}
	return result;
}

long long gotodiff_se(long long x, long long y)
{
	long long result;
	if (x >= y)
		goto x_ge_y;
	lt_cnt++;
	result = y - x;
	return result;
x_ge_y:
	ge_cnt++;
	result = x - y;
	return result;
}