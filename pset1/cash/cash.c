#include <cs50.h>
#include <stdio.h>

int main(void)
{
int change;
do
{
 change = get_float("Change owed: ");

}
while(change < 0);
}