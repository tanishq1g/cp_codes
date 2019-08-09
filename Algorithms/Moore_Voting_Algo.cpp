// METHOD 3 (Using Moore’s Voting Algorithm)
// This is a two step process.

// NOTE : This Method only works when we are given that majority element do exist in the array , otherwise this method won’t work , as in the problem definition we said that majority element may or may not exist but for applying this approach you can assume that majority element do exist in the given input array

// The first step gives the element that may be majority element in the array. If there is a majority element in an array, then this step will definitely return majority element, otherwise it will return candidate for majority element.
// Check if the element obtained from above step is majority element.This step is necessary as we are not always sure that element return by first step is majority element.
int findCandidate(int a[], int size)
{
    int maj_index = 0, count = 1;
    for (int i = 1; i < size; i++)
    {
        if (a[maj_index] == a[i])
            count++;
        else
            count--;
        if (count == 0)
        {
            maj_index = i;
            count = 1;
        }
    }
    return a[maj_index];
}

/* Function to check if the candidate
   occurs more than n/2 times */
bool isMajority(int a[], int size, int cand)
{
    int count = 0;
    for (int i = 0; i < size; i++)

    if (a[i] == cand)
    count++;

    if (count > size/2)
    return 1;

    else
    return 0;
}

/* Function to print Majority Element */
void printMajority(int a[], int size)
{
   /* Find the candidate for Majority*/
   int cand = findCandidate(a, size);

   /* Print the candidate if it is Majority*/
   if (isMajority(a, size, cand))
   cout << " " << cand << " ";

   else
   cout << "No Majority Element";
}


/* Driver function to test above functions */
int main()
{
    int a[] = {1, 3, 3, 1, 2};
    int size = (sizeof(a))/sizeof(a[0]);

    // Function calling
    printMajority(a, size);

    return 0;
}