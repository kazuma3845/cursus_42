#pragma once

# include <iostream>

template <typename T> void swap(T &a, T &b)
{
	T c;
	c = a;
	a = b;
	b = c;
}

template <typename T> T &min(T &a, T &b)
{
	if (a > b)
		return b;
	return a;
}

template <typename T> T &max(T &a, T &b)
{
	if (a < b)
		return b;
	return a;
}
