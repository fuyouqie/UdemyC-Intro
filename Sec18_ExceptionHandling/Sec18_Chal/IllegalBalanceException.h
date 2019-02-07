#pragma once

class IllegalBalanceException : public std::exception
{
public:
	IllegalBalanceException() noexcept = default;
	~IllegalBalanceException() = default;
	virtual const char* what() const noexcept
	{
		return "Illegal Balance";
	}
};
