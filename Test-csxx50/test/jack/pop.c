bool pop(int *n)
{
    if(s.size > 0) // check if stack is not empty
    {
        s.size--; // decrement the size of the stack
        *n = s.numbers[s.size]; // remove the top element from the stack
        return true; // pop successful
        }
        else
        {
            return false; // pop failed, stack is empty
            }
}
