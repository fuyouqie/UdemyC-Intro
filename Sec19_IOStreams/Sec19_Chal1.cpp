#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

struct Customer
{
	string name;
	string email;
};

struct Item_Purchased
{
	string name;
	double price;
	size_t amount;
};

struct Order
{
	size_t order_id;
	Customer customer;
	vector<Item_Purchased> items_purchased;
};

struct Sale
{
	string sale;
	vector<Order> orders;
};

int main()
{
	Sale sale
	{
		"Sale1",

		{
			{
				625,

				{"CusA","CustA@store.com"},

				{
					{"Item1",546.76,2},
					{"Item2",1146.26,1}
				}
			},

			{
				124,

				{"CusB","CustB@store.com"},

				{
					{"Item3",26.786,5},
					{"Item4",134.2676,3},
					{"Item5",875.2,2}
				}
			}
		}
	};

	const size_t general_size{15};
	const size_t email{general_size + 5};
	const size_t indent{65};
	cout << setprecision(2) << fixed;

	cout << "Sale Name: " << sale.sale << endl;
	cout << left;
	cout << setw(general_size) << "Order_Index";
	cout << setw(general_size) << "Order_ID";
	cout << setw(general_size) << "Cust_Name";
	cout << setw(email) << "Cust_Email";
	cout << setw(general_size) << "Item_Index";
	cout << setw(general_size) << "Item_Name";
	cout << setw(general_size) << "Item_Price";
	cout << setw(general_size) << "Item_Amount";
	cout << endl;

	for (size_t i{0}; i < sale.orders.size(); i++)
	{
		cout << setw(general_size) << i + 1;
		cout << setw(general_size) << sale.orders.at(i).order_id;
		cout << setw(general_size) << sale.orders.at(i).customer.name;
		cout << setw(email) << sale.orders.at(i).customer.email;

		for (size_t j{0}; j < sale.orders.at(i).items_purchased.size(); j++)
		{
			if (j > 0)
				cout << setw(indent) << "";
			cout << setw(general_size) << j + 1;
			cout << setw(general_size) << sale.orders.at(i).items_purchased.at(j).name;
			cout << right << setw(general_size) << sale.orders.at(i).items_purchased.at(j).price;
			cout << setw(general_size) << sale.orders.at(i).items_purchased.at(j).amount << left;
			cout << endl;
		}
	}

	return 0;
}