#include <iostream>
using namespace std;

struct Student
{
	struct Student* BestFriend;
};

Student a = { NULL };

int main()
{
	a.BestFriend;
	

	return;
}