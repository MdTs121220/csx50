bool push(int n)
{
    if(t.numbers == NULL) // check if stack is empty
    {
        t.numbers = (int*) malloc(sizeof(int)); // allocate memory for one element
        if(t.numbers == NULL) // check if memory allocation failed
        {
            return false; // push failed, memory allocation failed
        }
    }
    else if(t.size >= SIZE_MAX / sizeof(int) || t.size >= INT_MAX) // check if stack is full
    {
        return false; // push failed, stack is full
    }
    else
    {
        int temp = (int) realloc(t.numbers, (t.size + 1) * sizeof(int)); // allocate more memory for the stack
        if(temp == NULL) // check if memory allocation failed
        {
            return false; // push failed, memory allocation failed
            }
            else
            {
                t.numbers = temp; // update the stack pointer to the new memory location
                }
                }
}
