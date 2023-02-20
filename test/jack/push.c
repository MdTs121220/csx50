bool push(int n)
{
    if(s.size < CAPACITY) // check if stack is not full
    {
        s.numbers[s.size] = n; // add element to the top of the stack
        s.size++; // increment the size of the stack
        return true; // push successful
        }
        else
        {
            return false; // push failed, stack is full
            }
}
